#ifndef __INC_TABLES_H__
#define __INC_TABLES_H__

#include "length.h"

typedef	DWORD IDENT;

/**
 * @version 05/06/10	Bang2ni - Myshop Pricelist 관련 패킷 HEADER_XX_MYSHOP_PRICELIST_XXX 추가
 */
enum
{
	HEADER_GD_LOGIN								= 1,
	HEADER_GD_LOGOUT							= 2,
	HEADER_GD_PLAYER_LOAD						= 3,
	HEADER_GD_PLAYER_SAVE						= 4,
	HEADER_GD_PLAYER_CREATE						= 5,
	HEADER_GD_PLAYER_DELETE						= 6,
	HEADER_GD_LOGIN_KEY							= 7,
	HEADER_GD_BOOT								= 8,
	HEADER_GD_PLAYER_COUNT						= 9,
	HEADER_GD_QUEST_SAVE						= 10,
	HEADER_GD_SAFEBOX_LOAD						= 11,
	HEADER_GD_SAFEBOX_SAVE						= 12,
	HEADER_GD_SAFEBOX_CHANGE_SIZE				= 13,
	HEADER_GD_EMPIRE_SELECT						= 14,
	HEADER_GD_SAFEBOX_CHANGE_PASSWORD			= 15,
	HEADER_GD_SAFEBOX_CHANGE_PASSWORD_SECOND	= 16,
	HEADER_GD_DIRECT_ENTER						= 17,
	HEADER_GD_GUILD_SKILL_UPDATE				= 18,
	HEADER_GD_GUILD_EXP_UPDATE					= 19,
	HEADER_GD_GUILD_ADD_MEMBER					= 20,
	HEADER_GD_GUILD_REMOVE_MEMBER				= 21,
	HEADER_GD_GUILD_CHANGE_GRADE				= 22,
	HEADER_GD_GUILD_CHANGE_MEMBER_DATA			= 23,
	HEADER_GD_GUILD_DISBAND						= 24,
	HEADER_GD_GUILD_WAR							= 25,
	HEADER_GD_GUILD_WAR_SCORE					= 26,
	HEADER_GD_GUILD_CREATE						= 27,
	HEADER_GD_ITEM_SAVE							= 28,
	HEADER_GD_ITEM_DESTROY						= 29,
	HEADER_GD_ADD_AFFECT						= 30,
	HEADER_GD_REMOVE_AFFECT						= 31,
	HEADER_GD_HIGHSCORE_REGISTER				= 32,
	HEADER_GD_ITEM_FLUSH						= 33,
	HEADER_GD_PARTY_CREATE						= 34,
	HEADER_GD_PARTY_DELETE						= 35,
	HEADER_GD_PARTY_ADD							= 36,
	HEADER_GD_PARTY_REMOVE						= 37,
	HEADER_GD_PARTY_STATE_CHANGE				= 38,
	HEADER_GD_PARTY_HEAL_USE					= 39,
	HEADER_GD_FLUSH_CACHE						= 40,
	HEADER_GD_RELOAD_PROTO						= 41,
	HEADER_GD_CHANGE_NAME						= 42,
	HEADER_GD_SMS								= 43,
	HEADER_GD_GUILD_CHANGE_LADDER_POINT			= 44,
	HEADER_GD_GUILD_USE_SKILL					= 45,
	HEADER_GD_REQUEST_EMPIRE_PRIV				= 46,
	HEADER_GD_REQUEST_GUILD_PRIV				= 47,
	HEADER_GD_MONEY_LOG							= 48,
	HEADER_GD_GUILD_DEPOSIT_MONEY				= 49,
	HEADER_GD_GUILD_WITHDRAW_MONEY				= 50,
	HEADER_GD_GUILD_WITHDRAW_MONEY_GIVE_REPLY	= 51,
	HEADER_GD_REQUEST_CHARACTER_PRIV			= 52,
	HEADER_GD_SET_EVENT_FLAG					= 53,
	HEADER_GD_PARTY_SET_MEMBER_LEVEL			= 54,
	HEADER_GD_GUILD_WAR_BET						= 55,
	HEADER_GD_CREATE_OBJECT						= 56,
	HEADER_GD_DELETE_OBJECT						= 57,
	HEADER_GD_UPDATE_LAND						= 58,
	HEADER_GD_MARRIAGE_ADD						= 59,
	HEADER_GD_MARRIAGE_UPDATE					= 60,
	HEADER_GD_MARRIAGE_REMOVE					= 61,
	HEADER_GD_WEDDING_REQUEST					= 62,
	HEADER_GD_WEDDING_READY						= 63,
	HEADER_GD_WEDDING_END						= 64,
	HEADER_GD_AUTH_LOGIN						= 65,
	HEADER_GD_LOGIN_BY_KEY						= 66,
	HEADER_GD_VCARD								= 68,
	HEADER_GD_MALL_LOAD							= 70,
	HEADER_GD_MYSHOP_PRICELIST_UPDATE			= 71,
	HEADER_GD_MYSHOP_PRICELIST_REQ				= 72,
	HEADER_GD_BLOCK_CHAT						= 73,
	HEADER_GD_HAMMER_OF_TOR						= 77,
	HEADER_GD_RELOAD_ADMIN						= 78,
	HEADER_GD_BREAK_MARRIAGE					= 79,
	HEADER_GD_ELECT_MONARCH						= 80,
	HEADER_GD_CANDIDACY							= 81,
	HEADER_GD_ADD_MONARCH_MONEY					= 82,
	HEADER_GD_TAKE_MONARCH_MONEY				= 83,
	HEADER_GD_COME_TO_VOTE						= 84,
	HEADER_GD_RMCANDIDACY						= 85,
	HEADER_GD_SETMONARCH						= 86,
	HEADER_GD_RMMONARCH							= 87,
	HEADER_GD_DEC_MONARCH_MONEY 				= 88,
	HEADER_GD_CHANGE_MONARCH_LORD 				= 89,
	HEADER_GD_BLOCK_COUNTRY_IP					= 90,
	HEADER_GD_BLOCK_EXCEPTION					= 91,
	HEADER_GD_REQ_CHANGE_GUILD_MASTER			= 92,
	HEADER_GD_REQ_SPARE_ITEM_ID_RANGE			= 93,
	HEADER_GD_UPDATE_HORSE_NAME					= 94,
	HEADER_GD_REQ_HORSE_NAME					= 95,
	HEADER_GD_DC								= 96,
	HEADER_GD_VALID_LOGOUT						= 97,
	HEADER_GD_REQUEST_CHARGE_CASH				= 98,
	HEADER_GD_DELETE_AWARDID					= 99,
	HEADER_GD_UPDATE_CHANNELSTATUS				= 100,
	HEADER_GD_REQUEST_CHANNELSTATUS				= 101,

	HEADER_GD_SETUP			= 0xff,

	///////////////////////////////////////////////
	HEADER_DG_NOTICE							= 1,
	HEADER_DG_LOGIN_SUCCESS						= 2,
	HEADER_DG_LOGIN_NOT_EXIST					= 3,
	HEADER_DG_LOGIN_WRONG_PASSWD				= 4,
	HEADER_DG_LOGIN_ALREADY						= 5,
	HEADER_DG_PLAYER_LOAD_SUCCESS				= 6,
	HEADER_DG_PLAYER_LOAD_FAILED				= 7,
	HEADER_DG_PLAYER_CREATE_SUCCESS				= 8,
	HEADER_DG_PLAYER_CREATE_ALREADY				= 9,
	HEADER_DG_PLAYER_CREATE_FAILED				= 10,
	HEADER_DG_PLAYER_DELETE_SUCCESS				= 11,
	HEADER_DG_PLAYER_DELETE_FAILED				= 12,
	HEADER_DG_ITEM_LOAD							= 13,
	HEADER_DG_BOOT								= 14,
	HEADER_DG_QUEST_LOAD						= 15,
	HEADER_DG_SAFEBOX_LOAD						= 16,
	HEADER_DG_SAFEBOX_CHANGE_SIZE				= 17,
	HEADER_DG_SAFEBOX_WRONG_PASSWORD			= 18,
	HEADER_DG_SAFEBOX_CHANGE_PASSWORD_ANSWER	= 19,
	HEADER_DG_EMPIRE_SELECT						= 20,
	HEADER_DG_AFFECT_LOAD						= 21,
	HEADER_DG_MALL_LOAD							= 22,
	HEADER_DG_DIRECT_ENTER						= 23,
	HEADER_DG_GUILD_SKILL_UPDATE				= 24,
	HEADER_DG_GUILD_SKILL_RECHARGE				= 25,
	HEADER_DG_GUILD_EXP_UPDATE					= 26,
	HEADER_DG_PARTY_CREATE						= 27,
	HEADER_DG_PARTY_DELETE						= 28,
	HEADER_DG_PARTY_ADD							= 29,
	HEADER_DG_PARTY_REMOVE						= 30,
	HEADER_DG_PARTY_STATE_CHANGE				= 31,
	HEADER_DG_PARTY_HEAL_USE					= 32,
	HEADER_DG_PARTY_SET_MEMBER_LEVEL			= 33,
	HEADER_DG_TIME								= 34,
	HEADER_DG_ITEM_ID_RANGE						= 35,
	HEADER_DG_GUILD_ADD_MEMBER					= 36,
	HEADER_DG_GUILD_REMOVE_MEMBER				= 37,
	HEADER_DG_GUILD_CHANGE_GRADE				= 38,
	HEADER_DG_GUILD_CHANGE_MEMBER_DATA			= 39,
	HEADER_DG_GUILD_DISBAND						= 40,
	HEADER_DG_GUILD_WAR							= 41,
	HEADER_DG_GUILD_WAR_SCORE					= 42,
	HEADER_DG_GUILD_TIME_UPDATE					= 43,
	HEADER_DG_GUILD_LOAD						= 44,
	HEADER_DG_GUILD_LADDER						= 45,
	HEADER_DG_GUILD_SKILL_USABLE_CHANGE			= 46,
	HEADER_DG_GUILD_MONEY_CHANGE				= 47,
	HEADER_DG_GUILD_WITHDRAW_MONEY_GIVE			= 48,
	HEADER_DG_SET_EVENT_FLAG					= 49,
	HEADER_DG_GUILD_WAR_RESERVE_ADD				= 50,
	HEADER_DG_GUILD_WAR_RESERVE_DEL				= 51,
	HEADER_DG_GUILD_WAR_BET						= 52,
	HEADER_DG_RELOAD_PROTO						= 53,
	HEADER_DG_CHANGE_NAME						= 54,
	HEADER_DG_AUTH_LOGIN						= 55,
	HEADER_DG_CHANGE_EMPIRE_PRIV				= 56,
	HEADER_DG_CHANGE_GUILD_PRIV					= 57,
	HEADER_DG_MONEY_LOG							= 58,
	HEADER_DG_CHANGE_CHARACTER_PRIV				= 59,
	HEADER_DG_VCARD								= 63,
	HEADER_DG_CREATE_OBJECT						= 65,
	HEADER_DG_DELETE_OBJECT						= 66,
	HEADER_DG_UPDATE_LAND						= 67,
	HEADER_DG_MARRIAGE_ADD						= 68,
	HEADER_DG_MARRIAGE_UPDATE					= 69,
	HEADER_DG_MARRIAGE_REMOVE					= 70,
	HEADER_DG_WEDDING_REQUEST					= 71,
	HEADER_DG_WEDDING_READY						= 72,
	HEADER_DG_WEDDING_START						= 73,
	HEADER_DG_WEDDING_END						= 74,
	HEADER_DG_MYSHOP_PRICELIST_RES				= 75,
	HEADER_DG_RELOAD_ADMIN 						= 76,
	HEADER_DG_BREAK_MARRIAGE 					= 77,
	HEADER_DG_ELECT_MONARCH						= 78,
	HEADER_DG_CANDIDACY							= 79,
	HEADER_DG_ADD_MONARCH_MONEY					= 80,
	HEADER_DG_TAKE_MONARCH_MONEY				= 81,
	HEADER_DG_COME_TO_VOTE						= 82,
	HEADER_DG_RMCANDIDACY						= 83,
	HEADER_DG_SETMONARCH						= 84,
	HEADER_DG_RMMONARCH							= 85,
	HEADER_DG_DEC_MONARCH_MONEY 				= 86,
	HEADER_DG_CHANGE_MONARCH_LORD_ACK 			= 87,
	HEADER_DG_UPDATE_MONARCH_INFO				= 88,
	HEADER_DG_BLOCK_COUNTRY_IP					= 89,
	HEADER_DG_BLOCK_EXCEPTION					= 90,
	HEADER_DG_ACK_CHANGE_GUILD_MASTER 			= 91,
	HEADER_DG_ACK_SPARE_ITEM_ID_RANGE 			= 92,
	HEADER_DG_UPDATE_HORSE_NAME 				= 93,
	HEADER_DG_ACK_HORSE_NAME					= 94,
	HEADER_DG_NEED_LOGIN_LOG					= 95,
	HEADER_DG_RESULT_CHARGE_CASH				= 96,
	HEADER_DG_ITEMAWARD_INFORMER				= 97,
	HEADER_DG_RESPOND_CHANNELSTATUS				= 98,

	HEADER_DG_MAP_LOCATIONS		= 0xfe,
	HEADER_DG_P2P			= 0xff,
};

/* ----------------------------------------------
 * table
 * ----------------------------------------------
 */

/* game Server -> DB Server */
#pragma pack(1)
enum ERequestChargeType
{
	ERequestCharge_Cash = 0,
	ERequestCharge_Mileage,
};

typedef struct SRequestChargeCash
{
	DWORD		dwAID;		// id(primary key) - Account Table
	DWORD		dwAmount;
	ERequestChargeType	eChargeType;

} TRequestChargeCash;

typedef struct SSimplePlayer
{
	DWORD		dwID;
	char		szName[CHARACTER_NAME_MAX_LEN + 1];
	BYTE		byJob;
	int			byLevel;
	DWORD		dwPlayMinutes;
	BYTE		byST, byHT, byDX, byIQ;
	WORD		wMainPart;
	BYTE		bChangeName;
	WORD		wHairPart;
	BYTE		bDummy[4];
	long		x, y;
	long		lAddr;
	WORD		wPort;
	BYTE		skill_group;
} TSimplePlayer;

typedef struct SAccountTable
{
	DWORD		id;
	char		login[LOGIN_MAX_LEN + 1];
	char		passwd[PASSWD_MAX_LEN + 1];
	char		social_id[SOCIAL_ID_MAX_LEN + 1];
	char		status[ACCOUNT_STATUS_MAX_LEN + 1];
	BYTE		bEmpire;
	TSimplePlayer	players[PLAYER_PER_ACCOUNT];
} TAccountTable;

typedef struct SPacketDGCreateSuccess
{
	BYTE		bAccountCharacterIndex;
	TSimplePlayer	player;
} TPacketDGCreateSuccess;

typedef struct TPlayerItemAttribute
{
	BYTE	bType;
	short	sValue;
} TPlayerItemAttribute;

typedef struct SPlayerItem
{
	DWORD	id;
	BYTE	window;
	WORD	pos;
	DWORD	count;

	DWORD	vnum;
	long	alSockets[ITEM_SOCKET_MAX_NUM];	// 소켓번호

	TPlayerItemAttribute    aAttr[ITEM_ATTRIBUTE_MAX_NUM];

	DWORD	owner;
} TPlayerItem;

typedef struct SQuickslot
{
	BYTE	type;
	UINT    pos;
} TQuickslot;

typedef struct SPlayerSkill
{
	BYTE	bMasterType;
	BYTE	bLevel;
	time_t	tNextRead;
} TPlayerSkill;

struct	THorseInfo
{
	BYTE	bLevel;
	BYTE	bRiding;
	short	sStamina;
	short	sHealth;
	DWORD	dwHorseHealthDropTime;
};

typedef struct SPlayerTable
{
	DWORD	id;

	char	name[CHARACTER_NAME_MAX_LEN + 1];
	char	ip[IP_ADDRESS_LENGTH + 1];

	WORD	job;
	BYTE	voice;

	int		level;
	BYTE	level_step;
	short	st, ht, dx, iq;

	long long	exp;
	long long	gold;

	BYTE	dir;
	INT		x, y, z;
	INT		lMapIndex;

	long	lExitX, lExitY;
	long	lExitMapIndex;

	long long      hp;
	long long      sp;

	short	sRandomHP;
	short	sRandomSP;

	int         playtime;

	short	stat_point;
	short	skill_point;
	short	sub_skill_point;
	short	horse_skill_point;

	TPlayerSkill skills[SKILL_MAX_NUM];

	TQuickslot  quickslot[QUICKSLOT_MAX_NUM];

	BYTE	part_base;
	WORD	parts[PART_MAX_NUM];

	short	stamina;

	BYTE	skill_group;
	long	lAlignment;
	char	szMobile[MOBILE_MAX_LEN + 1];

	short	stat_reset_count;

	THorseInfo	horse;

	DWORD	logoff_interval;
} TPlayerTable;

typedef struct SMobSkillLevel
{
	DWORD	dwVnum;
	BYTE	bLevel;
} TMobSkillLevel;

typedef struct SEntityTable
{
	DWORD dwVnum;
} TEntityTable;

typedef struct SMobTable : public SEntityTable
{
	char	szName[CHARACTER_NAME_MAX_LEN + 1];
	char	szLocaleName[CHARACTER_NAME_MAX_LEN + 1];

	BYTE	bType;			// Monster, NPC
	BYTE	bRank;			// PAWN, KNIGHT, KING
	BYTE	bBattleType;		// MELEE, etc..
	int		bLevel;			// Level
	BYTE	bSize;

	DWORD	dwGoldMin;
	DWORD	dwGoldMax;
	long long	dwExp;
	DWORD	dwMaxHP;
	BYTE	bRegenCycle;
	BYTE	bRegenPercent;
	WORD	wDef;

	DWORD	dwAIFlag;
	DWORD	dwRaceFlag;
	DWORD	dwImmuneFlag;

	BYTE	bStr, bDex, bCon, bInt;
	DWORD	dwDamageRange[2];

	short	sAttackSpeed;
	short	sMovingSpeed;
	BYTE	bAggresiveHPPct;
	WORD	wAggressiveSight;
	WORD	wAttackRange;

	char	cEnchants[MOB_ENCHANTS_MAX_NUM];
	char	cResists[MOB_RESISTS_MAX_NUM];

	DWORD	dwResurrectionVnum;
	DWORD	dwDropItemVnum;

	BYTE	bMountCapacity;
	BYTE	bOnClickType;

	BYTE	bEmpire;
	char	szFolder[64 + 1];

	float	fDamMultiply;

	DWORD	dwSummonVnum;
	DWORD	dwDrainSP;
	DWORD	dwMobColor;
	DWORD	dwPolymorphItemVnum;

	TMobSkillLevel Skills[MOB_SKILL_MAX_NUM];

	BYTE	bBerserkPoint;
	BYTE	bStoneSkinPoint;
	BYTE	bGodSpeedPoint;
	BYTE	bDeathBlowPoint;
	BYTE	bRevivePoint;
} TMobTable;

typedef struct SSkillTable
{
	DWORD	dwVnum;
	char	szName[32 + 1];
	BYTE	bType;
	BYTE	bMaxLevel;
	DWORD	dwSplashRange;

	char	szPointOn[64];
	char	szPointPoly[100 + 1];
	char	szSPCostPoly[100 + 1];
	char	szDurationPoly[100 + 1];
	char	szDurationSPCostPoly[100 + 1];
	char	szCooldownPoly[100 + 1];
	char	szMasterBonusPoly[100 + 1];
	//char	szAttackGradePoly[100 + 1];
	char	szGrandMasterAddSPCostPoly[100 + 1];
	DWORD	dwFlag;
	DWORD	dwAffectFlag;

	// Data for secondary skill
	char 	szPointOn2[64];
	char 	szPointPoly2[100 + 1];
	char 	szDurationPoly2[100 + 1];
	DWORD 	dwAffectFlag2;

	// Data for grand master point
	char 	szPointOn3[64];
	char 	szPointPoly3[100 + 1];
	char 	szDurationPoly3[100 + 1];

	BYTE	bLevelStep;
	BYTE	bLevelLimit;
	DWORD	preSkillVnum;
	BYTE	preSkillLevel;

	long	lMaxHit; 
	char	szSplashAroundDamageAdjustPoly[100 + 1];

	BYTE	bSkillAttrType;

	DWORD	dwTargetRange;
} TSkillTable;

typedef struct SShopItemTable
{
	DWORD		vnum;
	short		count;

    TItemPos	pos;			// PC 상점에만 이용
	long long	price;	// PC, shop_table_ex.txt 상점에만 이용
	long		alSockets[ITEM_SOCKET_MAX_NUM];
	TPlayerItemAttribute    aAttr[ITEM_ATTRIBUTE_MAX_NUM];
	BYTE		display_pos; // PC, shop_table_ex.txt 상점에만 이용, 보일 위치.
} TShopItemTable;

typedef struct SPrivateShopItemTable
{
	DWORD		vnum;
	short		count;

    TItemPos	pos;			// PC 상점에만 이용
	long long	price;	// PC, shop_table_ex.txt 상점에만 이용
	BYTE		display_pos; // PC, shop_table_ex.txt 상점에만 이용, 보일 위치.
} TPrivateShopItemTable;

typedef struct SShopTable
{
	DWORD		dwVnum;
	DWORD		dwNPCVnum;

	short		byItemCount;
	TShopItemTable	items[SHOP_HOST_ITEM_MAX_NUM];
	short		price_type;
	char		szShopName[SHOP_TAB_NAME_MAX];
	BYTE		bSize;
} TShopTable;

#define QUEST_NAME_MAX_LEN	32
#define QUEST_STATE_MAX_LEN	64

typedef struct SQuestTable
{
	DWORD		dwPID;
	char		szName[QUEST_NAME_MAX_LEN + 1];
	char		szState[QUEST_STATE_MAX_LEN + 1];
	long		lValue;
} TQuestTable;

typedef struct SItemLimit
{
	BYTE	bType;
	long	lValue;
} TItemLimit;

typedef struct SItemApply
{
	BYTE	bType;
	long	lValue;
} TItemApply;

typedef struct SItemTable : public SEntityTable
{
	DWORD		dwVnumRange;
	char        szName[ITEM_NAME_MAX_LEN + 1];
	char	szLocaleName[ITEM_NAME_MAX_LEN + 1];
	BYTE	bType;
	BYTE	bSubType;

	BYTE        bWeight;
	BYTE	bSize;

	DWORD	dwAntiFlags;
	DWORD	dwFlags;
	DWORD	dwWearFlags;
	DWORD	dwImmuneFlag;

	long long	dwGold;
	long long	dwShopBuyPrice;

	TItemLimit	aLimits[ITEM_LIMIT_MAX_NUM];
	TItemApply	aApplies[ITEM_APPLY_MAX_NUM];
	long        alValues[ITEM_VALUES_MAX_NUM];
	long	alSockets[ITEM_SOCKET_MAX_NUM];
	DWORD	dwRefinedVnum;
	WORD	wRefineSet;
	BYTE	bAlterToMagicItemPct;
	BYTE	bSpecular;
	BYTE	bGainSocketPct;

	short int	sAddonType; // 기본 속성

	// 아래 limit flag들은 realtime에 체크 할 일이 많고, 아이템 VNUM당 고정된 값인데,
	// 현재 구조대로 매번 아이템마다 필요한 경우에 LIMIT_MAX_NUM까지 루프돌면서 체크하는 부하가 커서 미리 저장 해 둠.
	char		cLimitRealTimeFirstUseIndex;		// 아이템 limit 필드값 중에서 LIMIT_REAL_TIME_FIRST_USE 플래그의 위치 (없으면 -1)
	char		cLimitTimerBasedOnWearIndex;		// 아이템 limit 필드값 중에서 LIMIT_TIMER_BASED_ON_WEAR 플래그의 위치 (없으면 -1) 

} TItemTable;

struct TItemAttrTable
{
	TItemAttrTable() :
		dwApplyIndex(0),
		dwProb(0)
	{
		szApply[0] = 0;
		memset(&lValues, 0, sizeof(lValues));
		memset(&bMaxLevelBySet, 0, sizeof(bMaxLevelBySet));
	}

	char    szApply[APPLY_NAME_MAX_LEN + 1];
	DWORD   dwApplyIndex;
	DWORD   dwProb;
	long    lValues[5];
	BYTE    bMaxLevelBySet[ATTRIBUTE_SET_MAX_NUM];
};

typedef struct SConnectTable
{
	char	login[LOGIN_MAX_LEN + 1];
	IDENT	ident;
} TConnectTable;

typedef struct SLoginPacket
{
	char	login[LOGIN_MAX_LEN + 1];
	char	passwd[PASSWD_MAX_LEN + 1];
} TLoginPacket;

typedef struct SPlayerLoadPacket
{
	DWORD	account_id;
	DWORD	player_id;
	BYTE	account_index;	/* account 에서의 위치 */
} TPlayerLoadPacket;

typedef struct SPlayerCreatePacket
{
	char		login[LOGIN_MAX_LEN + 1];
	char		passwd[PASSWD_MAX_LEN + 1];
	DWORD		account_id;
	BYTE		account_index;
	TPlayerTable	player_table;
} TPlayerCreatePacket;

typedef struct SPlayerDeletePacket
{
	char	login[LOGIN_MAX_LEN + 1];
	DWORD	player_id;
	BYTE	account_index;
	//char	name[CHARACTER_NAME_MAX_LEN + 1];
	char	private_code[8];
} TPlayerDeletePacket;

typedef struct SLogoutPacket
{
	char	login[LOGIN_MAX_LEN + 1];
	char	passwd[PASSWD_MAX_LEN + 1];
} TLogoutPacket;

typedef struct SPlayerCountPacket
{
	DWORD	dwCount;
} TPlayerCountPacket;

#define SAFEBOX_MAX_NUM			135
#define SAFEBOX_PASSWORD_MAX_LEN	6

typedef struct SSafeboxTable
{
	DWORD	dwID;
	BYTE	bSize;
	DWORD	dwGold;
	WORD	wItemCount;
} TSafeboxTable;

typedef struct SSafeboxChangeSizePacket
{
	DWORD	dwID;
	BYTE	bSize;
} TSafeboxChangeSizePacket;

typedef struct SSafeboxLoadPacket
{
	DWORD	dwID;
	char	szLogin[LOGIN_MAX_LEN + 1];
	char	szPassword[SAFEBOX_PASSWORD_MAX_LEN + 1];
} TSafeboxLoadPacket;

typedef struct SSafeboxChangePasswordPacket
{
	DWORD	dwID;
	char	szOldPassword[SAFEBOX_PASSWORD_MAX_LEN + 1];
	char	szNewPassword[SAFEBOX_PASSWORD_MAX_LEN + 1];
} TSafeboxChangePasswordPacket;

typedef struct SSafeboxChangePasswordPacketAnswer
{
	BYTE	flag;
} TSafeboxChangePasswordPacketAnswer;

typedef struct SEmpireSelectPacket
{
	DWORD	dwAccountID;
	BYTE	bEmpire;
} TEmpireSelectPacket;

typedef struct SPacketGDSetup
{
	char	szPublicIP[16];	// Public IP which listen to users
	BYTE	bChannel;	// 채널
	WORD	wListenPort;	// 클라이언트가 접속하는 포트 번호
	WORD	wP2PPort;	// 서버끼리 연결 시키는 P2P 포트 번호
	long	alMaps[MAP_ALLOW_LIMIT];
	DWORD	dwLoginCount;
	BYTE	bAuthServer;
} TPacketGDSetup;

typedef struct SPacketDGMapLocations
{
	BYTE	bCount;
} TPacketDGMapLocations;

typedef struct SMapLocation
{
	long	alMaps[MAP_ALLOW_LIMIT];
	char	szHost[MAX_HOST_LENGTH + 1];
	WORD	wPort;
} TMapLocation;

typedef struct SPacketDGP2P
{
	char	szHost[MAX_HOST_LENGTH + 1];
	WORD	wPort;
	BYTE	bChannel;
} TPacketDGP2P;

typedef struct SPacketGDDirectEnter
{
	char	login[LOGIN_MAX_LEN + 1];
	char	passwd[PASSWD_MAX_LEN + 1];
	BYTE	index;
} TPacketGDDirectEnter;

typedef struct SPacketDGDirectEnter
{
	TAccountTable accountTable;
	TPlayerTable playerTable;
} TPacketDGDirectEnter;

typedef struct SPacketGuildSkillUpdate
{
	DWORD guild_id;
	int amount;
	BYTE skill_levels[12];
	BYTE skill_point;
	BYTE save;
} TPacketGuildSkillUpdate;

typedef struct SPacketGuildExpUpdate
{
	DWORD guild_id;
	int amount;
} TPacketGuildExpUpdate;

typedef struct SPacketGuildChangeMemberData
{
	DWORD guild_id;
	DWORD pid;
	DWORD offer;
	int level;
	BYTE grade;
} TPacketGuildChangeMemberData;


typedef struct SPacketDGLoginAlready
{
	char	szLogin[LOGIN_MAX_LEN + 1];
} TPacketDGLoginAlready;

typedef struct TPacketAffectElement
{
	DWORD	dwType;
	BYTE	bApplyOn;
	long	lApplyValue;
	DWORD	dwFlag;
	long	lDuration;
	long	lSPCost;
} TPacketAffectElement;

typedef struct SPacketGDAddAffect
{
	DWORD			dwPID;
	TPacketAffectElement	elem;
} TPacketGDAddAffect;

typedef struct SPacketGDRemoveAffect
{
	DWORD	dwPID;
	DWORD	dwType;
	BYTE	bApplyOn;
} TPacketGDRemoveAffect;

typedef struct SPacketGDHighscore
{
	DWORD	dwPID;
	long	lValue;
	char	cDir;
	char	szBoard[21];
} TPacketGDHighscore;

typedef struct SPacketPartyCreate
{
	DWORD	dwLeaderPID;
} TPacketPartyCreate;

typedef struct SPacketPartyDelete
{
	DWORD	dwLeaderPID;
} TPacketPartyDelete;

typedef struct SPacketPartyAdd
{
	DWORD	dwLeaderPID;
	DWORD	dwPID;
	BYTE	bState;
} TPacketPartyAdd;

typedef struct SPacketPartyRemove
{
	DWORD	dwLeaderPID;
	DWORD	dwPID;
} TPacketPartyRemove;

typedef struct SPacketPartyStateChange
{
	DWORD	dwLeaderPID;
	DWORD	dwPID;
	BYTE	bRole;
	BYTE	bFlag;
} TPacketPartyStateChange;

typedef struct SPacketPartySetMemberLevel
{
	DWORD	dwLeaderPID;
	DWORD	dwPID;
	int		bLevel;
} TPacketPartySetMemberLevel;

typedef struct SPacketGDBoot
{
    DWORD	dwItemIDRange[2];
	char	szIP[16];
} TPacketGDBoot;

typedef struct SPacketGuild
{
	DWORD	dwGuild;
	DWORD	dwInfo;
} TPacketGuild;

typedef struct SPacketGDGuildAddMember
{
	DWORD	dwPID;
	DWORD	dwGuild;
	BYTE	bGrade;
} TPacketGDGuildAddMember;

typedef struct SPacketDGGuildMember
{
	DWORD	dwPID;
	DWORD	dwGuild;
	BYTE	bGrade;
	BYTE	isGeneral;
	BYTE	bJob;
	int		bLevel;
	DWORD	dwOffer;
	char	szName[CHARACTER_NAME_MAX_LEN + 1];
} TPacketDGGuildMember;

typedef struct SPacketGuildWar
{
	BYTE	bType;
	BYTE	bWar;
	DWORD	dwGuildFrom;
	DWORD	dwGuildTo;
	long	lWarPrice;
	long	lInitialScore;
} TPacketGuildWar;

// Game -> DB : 상대적 변화값
// DB -> Game : 토탈된 최종값
typedef struct SPacketGuildWarScore
{
	DWORD dwGuildGainPoint;
	DWORD dwGuildOpponent;
	long lScore;
	long lBetScore;
} TPacketGuildWarScore;

typedef struct SRefineMaterial
{
	DWORD vnum;
	int count;
} TRefineMaterial;

typedef struct SRefineTable
{
	//DWORD src_vnum;
	//DWORD result_vnum;
	DWORD id;
	short material_count;
	int cost; // 소요 비용
	int prob; // 확률
	TRefineMaterial materials[REFINE_MATERIAL_MAX_NUM];
} TRefineTable;

typedef struct SBanwordTable
{
	char szWord[BANWORD_MAX_LEN + 1];
} TBanwordTable;

typedef struct SPacketGDChangeName
{
	DWORD pid;
	char name[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGDChangeName;

typedef struct SPacketDGChangeName
{
	DWORD pid;
	char name[CHARACTER_NAME_MAX_LEN + 1];
} TPacketDGChangeName;

typedef struct SPacketGuildLadder
{
	DWORD dwGuild;
	long lLadderPoint;
	long lWin;
	long lDraw;
	long lLoss;
} TPacketGuildLadder;

typedef struct SPacketGuildLadderPoint
{
	DWORD dwGuild;
	long lChange;
} TPacketGuildLadderPoint;

typedef struct SPacketGDSMS
{
	char szFrom[CHARACTER_NAME_MAX_LEN + 1];
	char szTo[CHARACTER_NAME_MAX_LEN + 1];
	char szMobile[MOBILE_MAX_LEN + 1];
	char szMsg[SMS_MAX_LEN + 1];
} TPacketGDSMS;

typedef struct SPacketGuildUseSkill
{
	DWORD dwGuild;
	DWORD dwSkillVnum;
	DWORD dwCooltime;
} TPacketGuildUseSkill;

typedef struct SPacketGuildSkillUsableChange
{
	DWORD dwGuild;
	DWORD dwSkillVnum;
	BYTE bUsable;
} TPacketGuildSkillUsableChange;

typedef struct SPacketGDLoginKey
{
	DWORD dwAccountID;
	DWORD dwLoginKey;
} TPacketGDLoginKey;

typedef struct SPacketGDAuthLogin
{
	DWORD	dwID;
	DWORD	dwLoginKey;
	char	szLogin[LOGIN_MAX_LEN + 1];
	char	szSocialID[SOCIAL_ID_MAX_LEN + 1];
	DWORD	adwClientKey[4];
} TPacketGDAuthLogin;

typedef struct SPacketGDLoginByKey
{
	char	szLogin[LOGIN_MAX_LEN + 1];
	DWORD	dwLoginKey;
	DWORD	adwClientKey[4];
	char	szIP[MAX_HOST_LENGTH + 1];
} TPacketGDLoginByKey;

/**
 * @version 05/06/08	Bang2ni - 지속시간 추가
 */
typedef struct SPacketGiveGuildPriv
{
	BYTE type;
	int value;
	DWORD guild_id;
	time_t duration_sec;	///< 지속시간
} TPacketGiveGuildPriv;
typedef struct SPacketGiveEmpirePriv
{
	BYTE type;
	int value;
	BYTE empire;
	time_t duration_sec;
} TPacketGiveEmpirePriv;
typedef struct SPacketGiveCharacterPriv
{
	BYTE type;
	int value;
	DWORD pid;
} TPacketGiveCharacterPriv;
typedef struct SPacketRemoveGuildPriv
{
	BYTE type;
	DWORD guild_id;
} TPacketRemoveGuildPriv;
typedef struct SPacketRemoveEmpirePriv
{
	BYTE type;
	BYTE empire;
} TPacketRemoveEmpirePriv;

typedef struct SPacketDGChangeCharacterPriv
{
	BYTE type;
	int value;
	DWORD pid;
	BYTE bLog;
} TPacketDGChangeCharacterPriv;

/**
 * @version 05/06/08	Bang2ni - 지속시간 추가
 */
typedef struct SPacketDGChangeGuildPriv
{
	BYTE type;
	int value;
	DWORD guild_id;
	BYTE bLog;
	time_t end_time_sec;	///< 지속시간
} TPacketDGChangeGuildPriv;

typedef struct SPacketDGChangeEmpirePriv
{
	BYTE type;
	int value;
	BYTE empire;
	BYTE bLog;
	time_t end_time_sec;
} TPacketDGChangeEmpirePriv;

typedef struct SPacketMoneyLog
{
	BYTE type;
	DWORD vnum;
	long long gold;
} TPacketMoneyLog;

typedef struct SPacketGDGuildMoney
{
	DWORD dwGuild;
	INT iGold;
} TPacketGDGuildMoney;

typedef struct SPacketDGGuildMoneyChange
{
	DWORD dwGuild;
	INT iTotalGold;
} TPacketDGGuildMoneyChange;

typedef struct SPacketDGGuildMoneyWithdraw
{
	DWORD dwGuild;
	INT iChangeGold;
} TPacketDGGuildMoneyWithdraw;

typedef struct SPacketGDGuildMoneyWithdrawGiveReply
{
	DWORD dwGuild;
	INT iChangeGold;
	BYTE bGiveSuccess;
} TPacketGDGuildMoneyWithdrawGiveReply;

typedef struct SPacketSetEventFlag
{
	char	szFlagName[EVENT_FLAG_NAME_MAX_LEN + 1];
	long	lValue;
} TPacketSetEventFlag;

typedef struct SPacketLoginOnSetup
{
	DWORD   dwID;
	char    szLogin[LOGIN_MAX_LEN + 1];
	char    szSocialID[SOCIAL_ID_MAX_LEN + 1];
	char    szHost[MAX_HOST_LENGTH + 1];
	DWORD   dwLoginKey;
	DWORD   adwClientKey[4];
} TPacketLoginOnSetup;

typedef struct SPacketGDCreateObject
{
	DWORD	dwVnum;
	DWORD	dwLandID;
	INT		lMapIndex;
	INT	 	x, y;
	float	xRot;
	float	yRot;
	float	zRot;
} TPacketGDCreateObject;

typedef struct SPacketGDHammerOfTor
{
	DWORD 	key;
	DWORD	delay;
} TPacketGDHammerOfTor;

typedef struct SPacketGDVCard
{
	DWORD	dwID;
	char	szSellCharacter[CHARACTER_NAME_MAX_LEN + 1];
	char	szSellAccount[LOGIN_MAX_LEN + 1];
	char	szBuyCharacter[CHARACTER_NAME_MAX_LEN + 1];
	char	szBuyAccount[LOGIN_MAX_LEN + 1];
} TPacketGDVCard;

typedef struct SGuildReserve
{
	DWORD       dwID;
	DWORD       dwGuildFrom;
	DWORD       dwGuildTo;
	DWORD       dwTime;
	BYTE        bType;
	long        lWarPrice;
	long        lInitialScore;
	bool        bStarted;
	DWORD	dwBetFrom;
	DWORD	dwBetTo;
	long	lPowerFrom;
	long	lPowerTo;
	long	lHandicap;
} TGuildWarReserve;

typedef struct
{
	DWORD	dwWarID;
	char	szLogin[LOGIN_MAX_LEN + 1];
	DWORD	dwGold;
	DWORD	dwGuild;
} TPacketGDGuildWarBet;

// Marriage

typedef struct
{
	DWORD dwPID1;
	DWORD dwPID2;
	time_t tMarryTime;
	char szName1[CHARACTER_NAME_MAX_LEN + 1];
	char szName2[CHARACTER_NAME_MAX_LEN + 1];
} TPacketMarriageAdd;

typedef struct
{
	DWORD dwPID1;
	DWORD dwPID2;
	INT  iLovePoint;
	BYTE  byMarried;
} TPacketMarriageUpdate;

typedef struct
{
	DWORD dwPID1;
	DWORD dwPID2;
} TPacketMarriageRemove;

typedef struct
{
	DWORD dwPID1;
	DWORD dwPID2;
} TPacketWeddingRequest;

typedef struct
{
	DWORD dwPID1;
	DWORD dwPID2;
	DWORD dwMapIndex;
} TPacketWeddingReady;

typedef struct
{
	DWORD dwPID1;
	DWORD dwPID2;
} TPacketWeddingStart;

typedef struct
{
	DWORD dwPID1;
	DWORD dwPID2;
} TPacketWeddingEnd;

/// 개인상점 가격정보의 헤더. 가변 패킷으로 이 뒤에 byCount 만큼의 TItemPriceInfo 가 온다.
typedef struct SPacketMyshopPricelistHeader
{ 
	DWORD	dwOwnerID;	///< 가격정보를 가진 플레이어 ID 
	BYTE	byCount;	///< 가격정보 갯수
} TPacketMyshopPricelistHeader;

/// 개인상점의 단일 아이템에 대한 가격정보
typedef struct SItemPriceInfo
{
	DWORD	dwVnum;		///< 아이템 vnum
	long long	dwPrice;	///< 가격
} TItemPriceInfo;

/// 개인상점 아이템 가격정보 리스트 테이블
typedef struct SItemPriceListTable
{
	DWORD	dwOwnerID;	///< 가격정보를 가진 플레이어 ID
	BYTE	byCount;	///< 가격정보 리스트의 갯수

	TItemPriceInfo	aPriceInfo[SHOP_PRICELIST_MAX_NUM];	///< 가격정보 리스트
} TItemPriceListTable;

typedef struct
{
	char szName[CHARACTER_NAME_MAX_LEN + 1];
	long lDuration;
} TPacketBlockChat;

//ADMIN_MANAGER
typedef struct TAdminInfo
{
	int m_ID;				//고유ID
	char m_szAccount[32];	//계정
	char m_szName[32];		//캐릭터이름
	char m_szContactIP[16];	//접근아이피
	char m_szServerIP[16];  //서버아이피
	int m_Authority;		//권한
} tAdminInfo;
//END_ADMIN_MANAGER

//BOOT_LOCALIZATION
struct tLocale
{
	char szValue[32];
	char szKey[32];
};
//BOOT_LOCALIZATION

//RELOAD_ADMIN
typedef struct SPacketReloadAdmin
{
	char szIP[16];
} TPacketReloadAdmin;
//END_RELOAD_ADMIN

typedef struct TMonarchInfo
{
	DWORD pid[4];  // 군주의 PID
	int64_t money[4];  // 군주의 별개 돈	
	char name[4][32];  // 군주의 이름	
	char date[4][32];  // 군주 등록 날짜
} MonarchInfo;

typedef struct TMonarchElectionInfo
{
	DWORD pid;  // 투표 한사람 PID
	DWORD selectedpid; // 투표 당한 PID ( 군주 참가자 )
	char date[32]; // 투표 날짜
} MonarchElectionInfo;

// 군주 출마자
typedef struct tMonarchCandidacy
{
	DWORD pid;
	char name[32];
	char date[32];
} MonarchCandidacy;

typedef struct tChangeMonarchLord
{
	BYTE bEmpire;
	DWORD dwPID;
} TPacketChangeMonarchLord;

typedef struct tChangeMonarchLordACK
{
	BYTE bEmpire;
	DWORD dwPID;
	char szName[32];
	char szDate[32];
} TPacketChangeMonarchLordACK;

// Block Country Ip
typedef struct tBlockCountryIp
{
	DWORD	ip_from;
	DWORD	ip_to;
} TPacketBlockCountryIp;

enum EBlockExceptionCommand
{
	BLOCK_EXCEPTION_CMD_ADD = 1,
	BLOCK_EXCEPTION_CMD_DEL = 2,
};

// Block Exception Account
typedef struct tBlockException
{
	BYTE	cmd;	// 1 == add, 2 == delete
	char	login[LOGIN_MAX_LEN + 1];
}TPacketBlockException;

typedef struct tChangeGuildMaster
{
	DWORD dwGuildID;
	DWORD idFrom;
	DWORD idTo;
} TPacketChangeGuildMaster;

typedef struct tItemIDRange
{
	DWORD dwMin;
	DWORD dwMax;
	DWORD dwUsableItemIDMin;
} TItemIDRangeTable;

typedef struct tUpdateHorseName
{
	DWORD dwPlayerID;
	char szHorseName[CHARACTER_NAME_MAX_LEN + 1];
} TPacketUpdateHorseName;

typedef struct tDC
{
	char	login[LOGIN_MAX_LEN + 1];
} TPacketDC;

typedef struct tNeedLoginLogInfo
{
	DWORD dwPlayerID;
} TPacketNeedLoginLogInfo;

//독일 선물 알림 기능 테스트용 패킷 정보
typedef struct tItemAwardInformer
{
	char	login[LOGIN_MAX_LEN + 1];
	char	command[20];		//명령어
	unsigned int vnum;			//아이템
} TPacketItemAwardInfromer;
// 선물 알림 기능 삭제용 패킷 정보
typedef struct tDeleteAwardID
{
	DWORD dwID;
} TPacketDeleteAwardID;

typedef struct SChannelStatus
{
	short nPort;
	BYTE bStatus;
} TChannelStatus;

#pragma pack()
#endif
