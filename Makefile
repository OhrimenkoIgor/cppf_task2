CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		cppf_task2.o

LIBS =

TARGET =	cppf_task2

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
