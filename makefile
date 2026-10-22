CC = g++
CFLAGS = -std=c++11 -Wall
DEPS = starter.h

# Default rule builds the final executable (let's call it bowling, or change it to match your assignment)
all: bowling

# Link the object files into the final executable
bowling: starter.o main.o
	$(CC) $(CFLAGS) starter.o main.o -o bowling

# Compile starter.cpp into starter.o
starter.o: starter.cpp $(DEPS)
	$(CC) $(CFLAGS) -c starter.cpp

# Compile main.cpp into main.o
main.o: main.cpp $(DEPS)
	$(CC) $(CFLAGS) -c main.cpp

# Clean up build artifacts
clean:
	rm -f *.o bowling a.out