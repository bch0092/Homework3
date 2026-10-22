CC = g++
CFLAGS = -std=c++11 -Wall

# List all your header files
DEPS = address.h credit_card.h person.h product.h store.h transaction.h

# List all your implementation source files (including main.cpp)
SRCS = main.cpp address.cpp credit_card.cpp person.cpp product.cpp store.cpp transaction.cpp

# Automatically generate object file names from source file names
OBJS = $(SRCS:.cpp=.o)

# Name of your final executable
TARGET = store_program

# Default target
all: $(TARGET)

# Link all object files together into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Generic rule to compile any .cpp file into a .o file
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts and output files
clean:
	rm -f $(OBJS) $(TARGET) a.out *.txt.bak