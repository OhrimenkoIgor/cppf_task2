
TARGET =	client

IDIR =./inc
LIDIR=../lib/inc
CC=g++
CFLAGS=-I$(IDIR) -I$(LIDIR) -std=c++11 -O0 -g -gdwarf-2 -Wall -fmessage-length=0 -pthread

ODIR=./obj
SDIR=./src
LDIR =./lib

LIBS= -L../lib/ -lmodulelib

_DEPS = Connection.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = client.o Connection.o
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
