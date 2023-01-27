GCC=g++
CFLAGS=-Wall
LIBS=
TARGET=a
OBJECTS=230108188-1.cpp

$(TARGET): $(OBJECTS)
	$(GCC) -o $@ $(CFLAGS) $^ $(LIBS)

clean:
	rm $(TARGET)
