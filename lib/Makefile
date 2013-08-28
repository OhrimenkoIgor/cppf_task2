
TARGET =	libmodulelib.a

IDIR =./inc
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -O0 -g -gdwarf-2 -Wall -fPIC -fmessage-length=0 -pthread

ODIR=./obj
SDIR=./src
LDIR =./lib

LIBS=

_DEPS = IModule.h Module.h Mutex.h Command.h MessageQueue.h InetSockets.h    ModuleExceptions.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = IModule.o Module.o Mutex.o Command.o MessageQueue.o InetSockets.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all:	$(ODIR) $(TARGET)

$(TARGET): $(OBJ) 
	ar cvrs $@ $^ 
	
#g++ -shared -o $@ $^ $(CFLAGS) $(LIBS)
	
$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR):
	@mkdir -p $@ 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
