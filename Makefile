
TARGET =	cppf_task2

IDIR =./inc
CC=g++
CFLAGS=-I$(IDIR) -std=c++0x -O0 -g -Wall -fmessage-length=0

ODIR=./obj
SDIR=./src
LDIR =./lib

LIBS=-lm

_DEPS = AppServer.h Module.h Command.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = cppf_task2.o AppServer.o Module.o Command.o
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
