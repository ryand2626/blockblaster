# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++11 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lglfw -lGLEW -framework OpenGL -framework GLUT

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

# Install dependencies (macOS)
setup:
	xcode-select --install
	brew install glfw glew freeglut

.PHONY: all clean run setup
