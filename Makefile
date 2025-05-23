# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lglut -lGL -lGLU -lm

# Target executable
TARGET = blockblaster

# Default target
all: $(TARGET)

# Link target
$(TARGET): code.o
	$(CXX) $^ -o $@ $(LDFLAGS)

# Compile source
code.o: code.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean build artifacts
clean:
	rm -f $(TARGET) code.o

# Run the program
run: $(TARGET)
	./$(TARGET)

# Install dependencies (Linux)
setup:
	sudo apt-get update && \
	DEBIAN_FRONTEND=noninteractive sudo apt-get install -y build-essential freeglut3-dev libgl1-mesa-dev libglu1-mesa-dev

.PHONY: all clean run setup
