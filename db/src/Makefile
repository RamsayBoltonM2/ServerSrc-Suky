CC = g++

DB_VERSION = $(shell cat ../../__REVISION__)

INCDIR =
LIBDIR =
BINDIR = ..
OBJDIR = OBJDIR_DB
INSTALL_DIR = /usr/game
$(shell if [ ! -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi)

CFLAGS = -m32 -g -Wall -w -O2 -pipe -fexceptions  -Wno-long-long -pthread -D_THREAD_SAFE -D__USER__=\"$(USER)\" -D__HOSTNAME__=\"$(HOSTNAME)\" -D__PWD__=\"$(PWD)\" -D__DB_VERSION__=\"$(DB_VERSION)\"
INCDIR += -I../../libmysql/bsd_connector/output/include -I../../../Extern/include
LIBDIR += -L../../libthecore/lib -L../../libsql -L../../libpoly -L../../libgame/lib -L../../libmysql/bsd_connector/output/lib -L../../../Extern/lib
LIBS = -lthecore -lmysqlclient -lsql -lpoly -lgame -lm -lz -lcryptopp

SRCS =	Config.cpp NetBase.cpp Peer.cpp PeerBase.cpp Main.cpp Lock.cpp DBManager.cpp \
		Cache.cpp LoginData.cpp ClientManager.cpp ClientManagerPlayer.cpp ClientManagerLogin.cpp \
		ClientManagerBoot.cpp ClientManagerParty.cpp ClientManagerGuild.cpp GuildManager.cpp ClientManagerOfflineShop.cpp HB.cpp \
		PrivManager.cpp MoneyLog.cpp ItemAwardManager.cpp ClientManagerEventFlag.cpp Marriage.cpp \
		Monarch.cpp BlockCountry.cpp ItemIDRangeManager.cpp ClientManagerHorseName.cpp version.cpp \
		ProtoReader.cpp CsvReader.cpp 

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

TARGET  = $(BINDIR)/db_r$(DB_VERSION)
TARGET_STRIPPED = $(BINDIR)/db_r$(DB_VERSION)_stripped

default: $(TARGET) $(TARGET_STRIPPED)

$(TARGET): $(OBJS)
	@echo linking $(TARGET)....
	@$(CC) $(CFLAGS) $(LIBDIR) $(OBJS) $(LIBS) -o $(TARGET)
	
$(TARGET_STRIPPED): $(OBJS)
	@echo linking $(TARGET_STRIPPED)....
	@$(CC) $(CFLAGS) $(LIBDIR) $(OBJS) $(LIBS) -o $(TARGET_STRIPPED)
	@strip $(TARGET_STRIPPED)

$(OBJDIR)/%.o: %.cpp
	@echo compile $<
	@$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -f OBJDIR_DB/*
	@rm -f $(TARGET)
	@rm -f $(TARGET_STRIPPED)
	
install:
	rm -rf $(INSTALL_DIR)/share/db
	cp $(TARGET) $(INSTALL_DIR)/share/db
	
install_stripped:
	rm -rf $(INSTALL_DIR)/share/db
	cp $(TARGET_STRIPPED) $(INSTALL_DIR)/share/db
	
dep:
	@touch Depend
	makedepend -fDepend $(INCDIR) -I/usr/include/c++/3.3 -I/usr/include/c++/4.2 -p$(OBJDIR)/ $(SRCS) 2> /dev/null

sinclude Depend
