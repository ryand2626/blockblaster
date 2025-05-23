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
ifeq ($(UNAME_S),Linux)
SETUP_CMD = sudo apt-get update && \
DEBIAN_FRONTEND=noninteractive sudo apt-get install -y \
build-essential freeglut3-dev libgl1-mesa-dev libglu1-mesa-dev
else ifeq ($(UNAME_S),Darwin)
SETUP_CMD = xcode-select --install && brew install glfw glew freeglut
else
SETUP_CMD = echo "Unsupported OS $(UNAME_S)"
endif

setup:
	$(SETUP_CMD)

.PHONY: all clean run setup
