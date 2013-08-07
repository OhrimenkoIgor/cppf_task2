
TARGET =	server

IDIR =./inc
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -O0 -g -Wall -fmessage-length=0 -pthread

ODIR=./obj
SDIR=./src
LDIR =./lib

LIBS=

_DEPS = AppServer.h Server.h Module.h Command.h TestModule.h TestModuleCommands.h Connection.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main_server.o Server.o AppServer.o Module.o Command.o TestModuleCommands.o Connection.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all:	$(ODIR) $(TARGET)

$(TARGET): $(OBJ) 
	g++ -o $@ $^ $(CFLAGS) $(LIBS)
	
$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR):
	@mkdir -p $@ 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
