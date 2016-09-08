CC=clang++
CFLAGS=-c -Wall -Werror -O3
SOURCES= asp_main.cpp person.cpp vertex.cpp graph.cpp edge.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=asp

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o
	-rm -f ./asp