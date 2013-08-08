
TARGET =	server

IDIR =./inc
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -O0 -g -gdwarf-2 -Wall -fmessage-length=0 -pthread

ODIR=./obj
SDIR=./src
LDIR =./lib

LIBS=

_DEPS = AppServer.h Server.h Connection.h Module.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main_server.o Server.o AppServer.o Connection.o Module.o
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
