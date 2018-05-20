#include "stdafx.h"
#include "../../libgame/include/grid.h"
#include "constants.h"
#include "utils.h"
#include "config.h"
#include "shop.h"
#include "desc.h"
#include "desc_manager.h"
#include "char.h"
#include "char_manager.h"
#include "item.h"
#include "item_manager.h"
#include "buffer_manager.h"
#include "packet.h"
#include "log.h"
#include "db.h"
#include "questmanager.h"
#include "monarch.h"
#include "mob_manager.h"
#include "locale_service.h"

/* ------------------------------------------------------------------------------------ */
CShop::CShop()
	: m_dwVnum(0), m_dwNPCVnum(0), m_pkPC(NULL), m_sPriceType(0), m_szShopName(""), m_bSize(0)
{
	m_pGrid = M2_NEW CGrid(8, 8);
}

CShop::~CShop()
{
	TPacketGCShop pack;

	pack.header		= HEADER_GC_SHOP;
	pack.subheader	= SHOP_SUBHEADER_GC_END;
	pack.size		= sizeof(TPacketGCShop);

	Broadcast(&pack, sizeof(pack));

	GuestMapType::iterator it;

	it = m_map_guest.begin();

	while (it != m_map_guest.end())
	{
		LPCHARACTER ch = it->first;
		ch->SetShop(NULL);
		++it;
	}

	M2_DELETE(m_pGrid);
}

void CShop::SetPCShop(LPCHARACTER ch)
{
	m_pkPC = ch;
}

bool CShop::Create(DWORD dwVnum, DWORD dwNPCVnum, TShopItemTable * pTable, short price_type, std::string shopname, DWORD dwSize)
{
	m_bSize = dwSize;
	BYTE bGridTable[6][2] = {
		{ 5, 8 },{ 5, 10 },{ 6, 10 },{ 7, 10, },{ 8, 10 },{ 9, 10 }
	};
	BYTE* bSelectedGrid = bGridTable[dwSize];
	m_pGrid->Clear();
	M2_DELETE(m_pGrid);
	m_pGrid = M2_NEW CGrid(bSelectedGrid[0], bSelectedGrid[1]);
	m_pGrid->Clear();
	
	sys_log(0, "SHOP #%d (Shopkeeper %d)", dwVnum, dwNPCVnum);

	m_dwVnum = dwVnum;
	m_dwNPCVnum = dwNPCVnum;
	m_sPriceType = price_type;
	m_szShopName = shopname;

	short bItemCount;

	for (bItemCount = 0; bItemCount < SHOP_HOST_ITEM_MAX_NUM; ++bItemCount)
		if (0 == (pTable + bItemCount)->vnum)
			break;

	SetShopItems(pTable, bItemCount);
	return true;
}

void CShop::SetShopItems(TShopItemTable * pTable, short bItemCount)
{
	if (bItemCount > SHOP_HOST_ITEM_MAX_NUM)
		return;
	
	m_pGrid->Clear();	BYTE bGridTable[6][2] = {
		{ 5, 8 },{ 5, 10 },{ 6, 10 },{ 7, 10, },{ 8, 10 },{ 9, 10 }
	};

	if (!m_pkPC)
	{
		BYTE* bSelectedGrid = bGridTable[m_bSize];
		if (bItemCount > bSelectedGrid[0] * bSelectedGrid[1]) {
			sys_err("maximum item count from allocated grid count. item count: %d grid count: %d", bItemCount, bSelectedGrid[0] * bSelectedGrid[1]);
			return;
		}

		m_pGrid->Clear();
		M2_DELETE(m_pGrid);
		m_pGrid = M2_NEW CGrid(bSelectedGrid[0], bSelectedGrid[1]);
		m_pGrid->Clear();
	}
	else {
		if (bItemCount > 40)
			return;
	}

	m_itemVector.resize(SHOP_HOST_ITEM_MAX_NUM);
	memset(&m_itemVector[0], 0, sizeof(SHOP_ITEM) * m_itemVector.size());

	for (int i = 0; i < bItemCount; ++i)
	{
		LPITEM pkItem = NULL;
		const TItemTable * item_table;

		if (m_pkPC)
		{
			pkItem = m_pkPC->GetItem(pTable->pos);

			if (!pkItem)
			{
				sys_err("cannot find item on pos (%d, %d) (name: %s)", pTable->pos.window_type, pTable->pos.cell, m_pkPC->GetName());
				continue;
			}

			item_table = pkItem->GetProto();
		}
		else
		{
			if (!pTable->vnum)
				continue;

			item_table = ITEM_MANAGER::instance().GetTable(pTable->vnum);
		}

		if (!item_table)
		{
			sys_err("Shop: no item table by item vnum #%d", pTable->vnum);
			continue;
		}

		int iPos;

		if (IsPCShop())
		{
			sys_log(0, "MyShop: use position %d", pTable->display_pos);
			iPos = pTable->display_pos;
		}
		else
			iPos = m_pGrid->FindBlank(1, item_table->bSize);

		if (iPos < 0)
		{
			sys_err("not enough shop window");
			continue;
		}

		if (!m_pGrid->IsEmpty(iPos, 1, item_table->bSize))
		{
			if (IsPCShop())
			{
				sys_err("not empty position for pc shop %s[%d]", m_pkPC->GetName(), m_pkPC->GetPlayerID());
			}
			else
			{
				sys_err("not empty position for npc shop");
			}
			continue;
		}

		m_pGrid->Put(iPos, 1, item_table->bSize);

		SHOP_ITEM & item = m_itemVector[iPos];

		item.pkItem = pkItem;
		item.itemid = 0;

		if (item.pkItem)
		{
			item.vnum = pkItem->GetVnum();
			item.count = pkItem->GetCount(); // PC 샵의 경우 아이템 개수는 진짜 아이템의 개수여야 한다.
			item.price = pTable->price; // 가격도 사용자가 정한대로..
			item.itemid	= pkItem->GetID();
		}
		else
		{
			item.vnum = pTable->vnum;
			item.count = pTable->count;
			item.price = pTable->price;
			for (int i=0; i < ITEM_SOCKET_MAX_NUM; ++i)
				item.alSockets[i] = pTable->alSockets[i];
			for (int i=0; i < ITEM_ATTRIBUTE_MAX_NUM; ++i)
			{
				item.aAttr[i].bType = pTable->aAttr[i].bType;
				item.aAttr[i].sValue = pTable->aAttr[i].sValue;
			}
		}

		char name[36];
		snprintf(name, sizeof(name), "%-20s(#%-5d) (x %d)", item_table->szName, (int) item.vnum, item.count);

		sys_log(0, "SHOP_ITEM: %-36s PRICE %-5d", name, item.price);
		++pTable;
	}
}

void CShop::SetPrivateShopItems(TPrivateShopItemTable * pTable, short bItemCount)
{
	if (bItemCount > SHOP_HOST_ITEM_MAX_NUM)
		return;

	m_pGrid->Clear();

	m_itemVector.resize(SHOP_HOST_ITEM_MAX_NUM);
	memset(&m_itemVector[0], 0, sizeof(SHOP_ITEM) * m_itemVector.size());

	for (int i = 0; i < bItemCount; ++i)
	{
		LPITEM pkItem = NULL;
		const TItemTable * item_table;

		if (m_pkPC)
		{
			pkItem = m_pkPC->GetItem(pTable->pos);

			if (!pkItem)
			{
				sys_err("cannot find item on pos (%d, %d) (name: %s)", pTable->pos.window_type, pTable->pos.cell, m_pkPC->GetName());
				continue;
			}

			item_table = pkItem->GetProto();
		}
		else
		{
			if (!pTable->vnum)
				continue;

			item_table = ITEM_MANAGER::instance().GetTable(pTable->vnum);
		}

		if (!item_table)
		{
			sys_err("Shop: no item table by item vnum #%d", pTable->vnum);
			continue;
		}

		int iPos;

		if (IsPCShop())
		{
			sys_log(0, "MyShop: use position %d", pTable->display_pos);
			iPos = pTable->display_pos;
		}
		else
			iPos = m_pGrid->FindBlank(1, item_table->bSize);

		if (iPos < 0)
		{
			sys_err("not enough shop window");
			continue;
		}

		if (!m_pGrid->IsEmpty(iPos, 1, item_table->bSize))
		{
			if (IsPCShop())
			{
				sys_err("not empty position for pc shop %s[%d]", m_pkPC->GetName(), m_pkPC->GetPlayerID());
			}
			else
			{
				sys_err("not empty position for npc shop");
			}
			continue;
		}

		m_pGrid->Put(iPos, 1, item_table->bSize);

		SHOP_ITEM & item = m_itemVector[iPos];

		item.pkItem = pkItem;
		item.itemid = 0;

		if (item.pkItem)
		{
			item.vnum = pkItem->GetVnum();
			item.count = pkItem->GetCount(); // PC 샵의 경우 아이템 개수는 진짜 아이템의 개수여야 한다.
			item.price = pTable->price; // 가격도 사용자가 정한대로..
			item.itemid	= pkItem->GetID();
		}
		else
		{
			item.vnum = pTable->vnum;
			item.count = pTable->count;
			item.price = pTable->price;
		}

		char name[36];
		snprintf(name, sizeof(name), "%-20s(#%-5d) (x %d)", item_table->szName, (int) item.vnum, item.count);

		sys_log(0, "SHOP_ITEM: %-36s PRICE %-5d", name, item.price);
		++pTable;
	}
}

long long CShop::Buy(LPCHARACTER ch, BYTE pos)
{
	if (pos >= m_itemVector.size())
	{
		sys_log(0, "Shop::Buy : invalid position %d : %s", pos, ch->GetName());
		return SHOP_SUBHEADER_GC_INVALID_POS;
	}

	sys_log(0, "Shop::Buy : name %s pos %d", ch->GetName(), pos);

	GuestMapType::iterator it = m_map_guest.find(ch);

	if (it == m_map_guest.end())
		return SHOP_SUBHEADER_GC_END;

	SHOP_ITEM& r_item = m_itemVector[pos];

	if (r_item.price < 0)
	{
		LogManager::instance().HackLog("SHOP_BUY_GOLD_OVERFLOW", ch);
		return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
	}

	LPITEM pkSelectedItem = ITEM_MANAGER::instance().Find(r_item.itemid);

	if (IsPCShop())
	{
		if (!pkSelectedItem)
		{
			sys_log(0, "Shop::Buy : Critical: This user seems to be a hacker : invalid pcshop item : BuyerPID:%d SellerPID:%d",
					ch->GetPlayerID(),
					m_pkPC->GetPlayerID());

			return SHOP_SUBHEADER_GC_SOLD_OUT;
		}

		if ((pkSelectedItem->GetOwner() != m_pkPC))
		{
			sys_log(0, "Shop::Buy : Critical: This user seems to be a hacker : invalid pcshop item : BuyerPID:%d SellerPID:%d",
					ch->GetPlayerID(),
					m_pkPC->GetPlayerID());

			return SHOP_SUBHEADER_GC_SOLD_OUT;
		}
	}

	long long dwPrice = r_item.price;

	if (it->second)	// if other empire, price is triple
		dwPrice *= 1;

	if (m_pkPC)
	{
		if (ch->GetGold() < (long long) dwPrice)
		{
			sys_log(1, "Shop::Buy : Not enough money : %s has %lld, price %lld", ch->GetName(), ch->GetGold(), dwPrice);
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
		}
	}
	else
	{
		if (m_sPriceType == 0)
		{
			if (ch->GetGold() < (int) dwPrice)
			{
				sys_log(1, "Shop::Buy : Not enough money : %s has %lld, price %lld", ch->GetName(), ch->GetGold(), dwPrice);
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
			}			
		}
		else if (m_sPriceType == 1)
		{
			if (ch->GetDragonCoin() < (unsigned int) dwPrice)
			{
				sys_log(1, "Shop::Buy : Not enough dc : %s has %d, price %d", ch->GetName(), ch->GetDragonCoin(), dwPrice);
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_DRAGON_COIN;
			}
		}
		else if (m_sPriceType == 2)
		{
			if (ch->GetDragonMark() < (unsigned int) dwPrice)
			{
				sys_log(1, "Shop::Buy : Not enough dm : %s has %d, price %d", ch->GetName(), ch->GetDragonMark(), dwPrice);
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_DRAGON_MARK;
			}
		}
		else if (m_sPriceType == 3)
		{
			if (ch->GetAlignment() < (int) dwPrice*10)
			{
				sys_log(1, "Shop::Buy : Not enough alignment : %s has %d, price %d", ch->GetName(), ch->GetAlignment(), dwPrice*10);
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_ALIGNMENT;
			}
		}		
	}

	LPITEM item;

	if (m_pkPC) // 피씨가 운영하는 샵은 피씨가 실제 아이템을 가지고있어야 한다.
		item = r_item.pkItem;
	else
		item = ITEM_MANAGER::instance().CreateItem(r_item.vnum, r_item.count);

	if (!item)
		return SHOP_SUBHEADER_GC_SOLD_OUT;

	int iEmptyPos;
	iEmptyPos = ch->GetEmptyInventory(item->GetSize());

	if (iEmptyPos < 0)
	{
		if (m_pkPC)
		{
			sys_log(1, "Shop::Buy at PC Shop : Inventory full : %s size %d", ch->GetName(), item->GetSize());
			return SHOP_SUBHEADER_GC_INVENTORY_FULL;
		}
		else
		{
			sys_log(1, "Shop::Buy : Inventory full : %s size %d", ch->GetName(), item->GetSize());
			M2_DESTROY_ITEM(item);
			return SHOP_SUBHEADER_GC_INVENTORY_FULL;
		}
	}

	quest::CQuestManager::instance().Buy(ch->GetPlayerID());
	if (m_pkPC)
	{
		if (dwPrice > 0)
			ch->PointChange(POINT_GOLD, -dwPrice, false);
	}
	else
	{
		if (m_sPriceType == 0)
		{
			ch->PointChange(POINT_GOLD, -dwPrice, false);
		}
		else if (m_sPriceType == 1)
		{
			ch->SetDragonCoin(ch->GetDragonCoin()-dwPrice);
			if (item->GetVnum() != 80014 || item->GetVnum() != 80015 || item->GetVnum() != 80016 || item->GetVnum() != 80017)
				ch->SetDragonMark(ch->GetDragonMark()+dwPrice);
		}
		else if (m_sPriceType == 2)
		{
			ch->SetDragonMark(ch->GetDragonMark()-dwPrice);
		}
		else if (m_sPriceType == 3)
		{
			ch->UpdateAlignment(-dwPrice*10);
		}
	}

	//세금 계산
	DWORD dwTax = 0;
	int iVal = 0;

	iVal = quest::CQuestManager::instance().GetEventFlag("personal_shop");

	if (0 < iVal)
	{
		if (iVal > 100)
			iVal = 100;

		dwTax = dwPrice * iVal / 100;
		dwPrice = dwPrice - dwTax;
	}
	else
	{
		iVal = 0;
		dwTax = 0;
	}

	// 상점에서 살떄 세금 5%
	if (!m_pkPC) 
	{
		CMonarch::instance().SendtoDBAddMoney(dwTax, ch->GetEmpire(), ch);
	}

	// 군주 시스템 : 세금 징수
	if (m_pkPC)
	{
		m_pkPC->SyncQuickslot(QUICKSLOT_TYPE_ITEM, item->GetCell(), 1000);

		char buf[512];

		if (item->GetVnum() >= 80003 && item->GetVnum() <= 80007)
		{
			snprintf(buf, sizeof(buf), "%s FROM: %u TO: %u PRICE: %lld", item->GetName(), ch->GetPlayerID(), m_pkPC->GetPlayerID(), dwPrice);
			LogManager::instance().GoldBarLog(ch->GetPlayerID(), item->GetID(), SHOP_BUY, buf);
			LogManager::instance().GoldBarLog(m_pkPC->GetPlayerID(), item->GetID(), SHOP_SELL, buf);
		}
			
		item->RemoveFromCharacter();
		item->AddToCharacter(ch, TItemPos(INVENTORY, iEmptyPos));
		ITEM_MANAGER::instance().FlushDelayedSave(item);
			

		snprintf(buf, sizeof(buf), "%s %u(%s) %lld %u", item->GetName(), m_pkPC->GetPlayerID(), m_pkPC->GetName(), dwPrice, item->GetCount());
		LogManager::instance().ItemLog(ch, item, "SHOP_BUY", buf);

		snprintf(buf, sizeof(buf), "%s %u(%s) %lld %u", item->GetName(), ch->GetPlayerID(), ch->GetName(), dwPrice, item->GetCount());
		LogManager::instance().ItemLog(m_pkPC, item, "SHOP_SELL", buf);

		r_item.pkItem = NULL;
		BroadcastUpdateItem(pos);

		m_pkPC->PointChange(POINT_GOLD, dwPrice, false);

		if (iVal > 0)
			m_pkPC->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("판매금액의 %d %% 가 세금으로 나가게됩니다"), iVal);

		CMonarch::instance().SendtoDBAddMoney(dwTax, m_pkPC->GetEmpire(), m_pkPC);
	}
	else
	{
		item->AddToCharacter(ch, TItemPos(INVENTORY, iEmptyPos));
		if (r_item.alSockets[0] > 0)
		{
			const TItemTable * table;
			table = ITEM_MANAGER::instance().GetTable(item->GetVnum());
			
			for (int i=0 ; i < ITEM_LIMIT_MAX_NUM ; i++)
			{
				if (LIMIT_REAL_TIME == table->aLimits->bType)
					item->SetSocket(0, time(0) + r_item.alSockets[0]);
				else
					item->SetSocket(0, r_item.alSockets[0]);
			}
		}
		if (r_item.alSockets[1] > 0)
			item->SetSocket(1, r_item.alSockets[1]);
		if (r_item.alSockets[2] > 0)
			item->SetSocket(2, r_item.alSockets[2]);
		if (r_item.alSockets[3] > 0)
			item->SetSocket(3, r_item.alSockets[3]);
		if (r_item.alSockets[4] > 0)
			item->SetSocket(4, r_item.alSockets[4]);
		if (r_item.alSockets[5] > 0)
			item->SetSocket(5, r_item.alSockets[5]);
		if (r_item.aAttr[0].bType > 0 && r_item.aAttr[0].sValue > 0)
			item->SetForceAttribute(0, r_item.aAttr[0].bType, r_item.aAttr[0].sValue);
		if (r_item.aAttr[1].bType > 0 && r_item.aAttr[1].sValue > 0)
			item->SetForceAttribute(1, r_item.aAttr[1].bType, r_item.aAttr[1].sValue);
		if (r_item.aAttr[2].bType > 0 && r_item.aAttr[2].sValue > 0)
			item->SetForceAttribute(2, r_item.aAttr[2].bType, r_item.aAttr[2].sValue);
		if (r_item.aAttr[3].bType > 0 && r_item.aAttr[3].sValue > 0)
			item->SetForceAttribute(3, r_item.aAttr[3].bType, r_item.aAttr[3].sValue);
		if (r_item.aAttr[4].bType > 0 && r_item.aAttr[4].sValue > 0)
			item->SetForceAttribute(4, r_item.aAttr[4].bType, r_item.aAttr[4].sValue);
		if (r_item.aAttr[5].bType > 0 && r_item.aAttr[5].sValue > 0)
			item->SetForceAttribute(5, r_item.aAttr[5].bType, r_item.aAttr[5].sValue);
		if (r_item.aAttr[6].bType > 0 && r_item.aAttr[6].sValue > 0)
			item->SetForceAttribute(6, r_item.aAttr[6].bType, r_item.aAttr[6].sValue);
		ITEM_MANAGER::instance().FlushDelayedSave(item);
		LogManager::instance().ItemLog(ch, item, "BUY", item->GetName());

		if (item->GetVnum() >= 80003 && item->GetVnum() <= 80007)
		{
			LogManager::instance().GoldBarLog(ch->GetPlayerID(), item->GetID(), PERSONAL_SHOP_BUY, "");
		}

		DBManager::instance().SendMoneyLog(MONEY_LOG_SHOP, item->GetVnum(), -dwPrice);
	}

	if (item)
		sys_log(0, "SHOP: BUY: name %s %s(x %d):%u price %lld", ch->GetName(), item->GetName(), item->GetCount(), item->GetID(), dwPrice);

    ch->Save();

    return (SHOP_SUBHEADER_GC_OK);
}

bool CShop::AddGuest(LPCHARACTER ch, DWORD owner_vid, bool bOtherEmpire)
{
	if (!ch)
		return false;

	if (ch->GetExchange())
		return false;

	if (ch->GetShop())
		return false;

	ch->SetShop(this);

	m_map_guest.insert(GuestMapType::value_type(ch, bOtherEmpire));

	TPacketGCShop pack;

	pack.header		= HEADER_GC_SHOP;
	pack.subheader	= SHOP_SUBHEADER_GC_START;

	TPacketGCShopStart pack2;

	memset(&pack2, 0, sizeof(pack2));
	pack2.owner_vid = owner_vid;
	
	if (IsPCShop())
	{
		strlcpy(pack2.shop_name, m_pkPC->GetName(), SHOP_TAB_NAME_MAX);
		pack2.price_type = 0;
		pack2.grid_type = 0;
	}
	else
	{
		pack2.price_type = m_sPriceType;
		strlcpy(pack2.shop_name, m_szShopName.c_str(), SHOP_TAB_NAME_MAX);
		pack2.grid_type = m_bSize;
	}

	for (DWORD i = 0; i < m_itemVector.size() && i < SHOP_HOST_ITEM_MAX_NUM; ++i)
	{
		const SHOP_ITEM & item = m_itemVector[i];

		if (m_pkPC && !item.pkItem)
			continue;

		pack2.items[i].vnum = item.vnum;

		if (bOtherEmpire) // no empire price penalty for pc shop
			pack2.items[i].price = item.price * 1;
		else
			pack2.items[i].price = item.price;

		pack2.items[i].count = item.count;
		
		if (item.pkItem)
		{
			thecore_memcpy(pack2.items[i].alSockets, item.pkItem->GetSockets(), sizeof(pack2.items[i].alSockets));
			thecore_memcpy(pack2.items[i].aAttr, item.pkItem->GetAttributes(), sizeof(pack2.items[i].aAttr));
		}
		else if (!m_pkPC && !IsPCShop())
		{
			thecore_memcpy(pack2.items[i].alSockets, item.alSockets, sizeof(pack2.items[i].alSockets));
			thecore_memcpy(pack2.items[i].aAttr, item.aAttr, sizeof(pack2.items[i].aAttr));
			pack2.items[i].iLimitValue = item.alSockets[0];
		}
	}

	pack.size = sizeof(pack) + sizeof(pack2);

	ch->GetDesc()->BufferedPacket(&pack, sizeof(TPacketGCShop));
	ch->GetDesc()->Packet(&pack2, sizeof(TPacketGCShopStart));
	return true;
}

void CShop::RemoveGuest(LPCHARACTER ch)
{
	if (ch->GetShop() != this)
		return;

	m_map_guest.erase(ch);
	ch->SetShop(NULL);

	TPacketGCShop pack;

	pack.header		= HEADER_GC_SHOP;
	pack.subheader	= SHOP_SUBHEADER_GC_END;
	pack.size		= sizeof(TPacketGCShop);

	ch->GetDesc()->Packet(&pack, sizeof(pack));
}

void CShop::RemoveAllGuests()
{
	if (m_map_guest.empty())
		return;
	for (GuestMapType::iterator it = m_map_guest.begin(); it != m_map_guest.end(); it++)
	{
		LPCHARACTER ch = it->first;
		if (ch)
		{
			if (ch->GetDesc() && ch->GetShop() == this)
			{
				ch->SetShop(NULL);

				TPacketGCShop pack;

				pack.header = HEADER_GC_SHOP;
				pack.subheader = SHOP_SUBHEADER_GC_END;
				pack.size = sizeof(TPacketGCShop);

				ch->GetDesc()->Packet(&pack, sizeof(pack));
			}
		}
	}
	m_map_guest.clear();
}

void CShop::Broadcast(const void * data, int bytes)
{
	sys_log(1, "Shop::Broadcast %p %d", data, bytes);

	GuestMapType::iterator it;

	it = m_map_guest.begin();

	while (it != m_map_guest.end())
	{
		LPCHARACTER ch = it->first;

		if (ch->GetDesc())
			ch->GetDesc()->Packet(data, bytes);

		++it;
	}
}

void CShop::BroadcastUpdateItem(BYTE pos)
{
	TPacketGCShop pack;
	TPacketGCShopUpdateItem pack2;

	TEMP_BUFFER	buf;

	pack.header		= HEADER_GC_SHOP;
	pack.subheader	= SHOP_SUBHEADER_GC_UPDATE_ITEM;
	pack.size		= sizeof(pack) + sizeof(pack2);

	pack2.pos		= pos;

	if (m_pkPC && !m_itemVector[pos].pkItem)
		pack2.item.vnum = 0;
	else
	{
		pack2.item.vnum	= m_itemVector[pos].vnum;
		if (m_itemVector[pos].pkItem)
		{
			thecore_memcpy(pack2.item.alSockets, m_itemVector[pos].pkItem->GetSockets(), sizeof(pack2.item.alSockets));
			thecore_memcpy(pack2.item.aAttr, m_itemVector[pos].pkItem->GetAttributes(), sizeof(pack2.item.aAttr));
		}
		else
		{
			thecore_memcpy(pack2.item.alSockets, m_itemVector[pos].alSockets, sizeof(pack2.item.alSockets));
			thecore_memcpy(pack2.item.aAttr, m_itemVector[pos].aAttr, sizeof(pack2.item.aAttr));
			pack2.item.iLimitValue = m_itemVector[pos].alSockets[0];
		}
	}

	pack2.item.price	= m_itemVector[pos].price;
	pack2.item.count	= m_itemVector[pos].count;

	buf.write(&pack, sizeof(pack));
	buf.write(&pack2, sizeof(pack2));

	Broadcast(buf.read_peek(), buf.size());
}

int CShop::GetNumberByVnum(DWORD dwVnum)
{
	int itemNumber = 0;

	for (DWORD i = 0; i < m_itemVector.size() && i < SHOP_HOST_ITEM_MAX_NUM; ++i)
	{
		const SHOP_ITEM & item = m_itemVector[i];

		if (item.vnum == dwVnum)
		{
			itemNumber += item.count;
		}
	}

	return itemNumber;
}

bool CShop::IsSellingItem(DWORD itemID)
{
	bool isSelling = false;

	for (DWORD i = 0; i < m_itemVector.size() && i < SHOP_HOST_ITEM_MAX_NUM; ++i)
	{
		if (static_cast<unsigned long>(m_itemVector[i].itemid) == itemID)
		{
			isSelling = true;
			break;
		}
	}

	return isSelling;

}
