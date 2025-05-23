# Detect OS
UNAME_S := $(shell uname -s)

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lglut -lGL -lGLU -lm

# macOS specific settings
ifeq ($(UNAME_S),Darwin)
    CXX = clang++
    CXXFLAGS += -I/opt/homebrew/include
    LDFLAGS = -L/opt/homebrew/lib -lglfw -lGLEW -framework OpenGL -framework GLUT -lobjc
endif

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

# Install dependencies
setup:
	ifeq ($(UNAME_S),Linux)
		sudo apt-get update && \
		DEBIAN_FRONTEND=noninteractive sudo apt-get install -y build-essential freeglut3-dev libgl1-mesa-dev libglu1-mesa-dev
	else ifeq ($(UNAME_S),Darwin)
		xcode-select --install
		brew install glfw glew freeglut
	endif

.PHONY: all clean run setup
