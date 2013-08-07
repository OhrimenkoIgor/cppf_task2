
TARGET =	testmodule

IDIR =./inc
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -O0 -g -Wall -fmessage-length=0 -pthread

ODIR=./obj
SDIR=./src
LDIR =./lib

LIBS=

_DEPS = Command.h Module.h TestModule.h TestModuleCommands.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main_testmodule.o Module.o Command.o TestModuleCommands.o TestModule.o
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
