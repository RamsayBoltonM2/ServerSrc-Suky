CXX	= g++

BIN     = ./libsql.a

IFLAGS = -I../libmysql/bsd_connector/output/include

CFLAGS  = $(IFLAGS) -m32 -Wall -w -O2 -pipe -D_THREAD_SAFE -fno-exceptions 

LIBS =

OBJFILES = AsyncSQL.o Semaphore.o Tellwait.o Statement.o

default:
	$(MAKE) $(BIN)

$(BIN): $(OBJFILES)
	ar cru $(BIN) $(OBJFILES) $(LIBS)
	ranlib $(BIN)
	chmod 700 $(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

dep:
	touch Depend
	$(CXX) $(CFLAGS) -MM *.cpp > Depend

$(OBJFILES):
	$(CXX) $(CFLAGS) -c $<

sinclude Depend
