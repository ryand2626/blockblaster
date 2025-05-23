# ============================================================================
# Brick Breaker Makefile
# ============================================================================

# Detect OS and set platform-specific variables
UNAME_S := $(shell uname -s)

# Default installation paths for Linux
GL_INC_PATH ?= /usr/include
GL_LIB_PATH ?= /usr/lib

# Check if we're in a Docker container
DOCKER := $(shell grep -q docker /proc/1/cgroup 2>/dev/null && echo true || echo false)

# Default to Linux-style paths
GLUT_INC_PATH = $(GL_INC_PATH)/GL
GLUT_HEADER = $(GLUT_INC_PATH)/glut.h

# Check if we need to use macOS frameworks
ifeq ($(UNAME_S),Darwin)
    # On macOS, we use frameworks instead of libraries
    GL_FRAMEWORKS = -framework OpenGL -framework GLUT
    CXXFLAGS += -Wno-deprecated-declarations
    LDFLAGS = -L/opt/homebrew/lib -lglfw -lGLEW $(GL_FRAMEWORKS)
    # Check if we're using Homebrew's include path
    ifneq (,$(wildcard /opt/homebrew/include/GLUT/glut.h))
        GLUT_INC_PATH = /opt/homebrew/include/GLUT
        GLUT_HEADER = $(GLUT_INC_PATH)/glut.h
    endif
    # Check for MacPorts
    ifneq (,$(wildcard /opt/local/include/GLUT/glut.h))
        GLUT_INC_PATH = /opt/local/include/GLUT
        GLUT_HEADER = $(GLUT_INC_PATH)/glut.h
    endif
else
    # On Linux, we need to find the GLUT header
    ifeq (,$(wildcard $(GLUT_HEADER)))
        # Check common alternative locations
        ifneq (,$(wildcard /usr/include/GL/glut.h))
            GLUT_HEADER = /usr/include/GL/glut.h
        else ifneq (,$(wildcard /usr/local/include/GL/glut.h))
            GLUT_HEADER = /usr/local/include/GL/glut.h
        else ifneq (,$(wildcard /usr/include/freeglut.h))
            GLUT_HEADER = /usr/include/freeglut.h
        else ifneq (,$(wildcard /usr/include/GL/freeglut.h))
            GLUT_HEADER = /usr/include/GL/freeglut.h
        else
            $(error GLUT header not found. Please install freeglut development package)
        endif
    endif
    
    # Set the include path based on where we found the header
    GLUT_INC_PATH = $(dir $(GLUT_HEADER))
    
    # Add GLUT include path to compiler flags
    CXXFLAGS += -I$(dir $(GLUT_INC_PATH))
    
    # Set library flags for Linux
    LDFLAGS += -lglut -lGL -lGLU -lGLEW -lglfw
    
    # Check for GLFW
    ifeq (,$(wildcard /usr/include/GLFW/glfw3.h))
        ifeq (,$(wildcard /usr/local/include/GLFW/glfw3.h))
            $(warning GLFW3 header not found. Install libglfw3-dev package)
        endif
    endif
    
    # Check for GLEW
    ifeq (,$(wildcard /usr/include/GL/glew.h))
        ifeq (,$(wildcard /usr/local/include/GL/glew.h))
            $(warning GLEW header not found. Install libglew-dev package)
        endif
    endif
endif

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lm

# Check if we're in a Docker container and set paths accordingly
ifeq ($(DOCKER),true)
    # In Docker, we might need to use different paths
    ifeq (,$(wildcard /usr/include/GL/glut.h))
        ifneq (,$(wildcard /usr/include/freeglut.h))
            CXXFLAGS += -I/usr/include
        else
            $(warning Running in Docker but GLUT headers not found. Build might fail.)
            $(warning Consider adding 'RUN apt-get update && apt-get install -y freeglut3-dev' to your Dockerfile)
        endif
    endif
endif

# macOS specific settings
ifeq ($(UNAME_S),Darwin)
    CXX = clang++
    CXXFLAGS += -Wno-deprecated-declarations
    LDFLAGS = -L/opt/homebrew/lib -lglfw -lGLEW -framework OpenGL -framework GLUT -lobjc
    INSTALL_DIR = /usr/local/bin
else
    # Linux/Unix settings
    LDFLAGS += -lglfw -lGLEW
    INSTALL_DIR = /usr/local/games
endif

# Project settings
TARGET = blockblaster
SRC = code.cpp
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)


# Link target
$(TARGET): $(OBJ)
	@echo "Linking $(TARGET)..."
	@$(CXX) $^ -o $@ $(LDFLAGS)
	@echo "Build complete: $(TARGET)"

# Compile source
%.o: %.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts and temporary files
clean:
	@echo "Cleaning build artifacts..."
	@rm -f $(TARGET) $(OBJ) *.out *.dSYM

# Install the game
install: $(TARGET)
	@echo "Installing $(TARGET) to $(INSTALL_DIR)"
	@mkdir -p $(INSTALL_DIR)
	@cp $(TARGET) $(INSTALL_DIR)/
	@chmod 755 $(INSTALL_DIR)/$(TARGET)
	@echo "Installation complete. Run with: $(INSTALL_DIR)/$(TARGET)"

# Uninstall the game
uninstall:
	@echo "Removing $(INSTALL_DIR)/$(TARGET)"
	@rm -f $(INSTALL_DIR)/$(TARGET)

# Run the program
run: $(TARGET)
	@echo "Starting $(TARGET)..."
	@./$(TARGET)

# Install dependencies
setup:
	@echo "Checking and installing system dependencies..."
	@if [ "$(UNAME_S)" = "Linux" ]; then \
		echo "Installing Linux dependencies..."; \
		if command -v apt-get >/dev/null; then \
			apt-get update && \
			DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
			build-essential \
			freeglut3-dev \
			libgl1-mesa-dev \
			libglu1-mesa-dev \
			libglfw3-dev \
			libglew-dev \
			pkg-config \
			|| (echo "Failed to install dependencies. Try running with sudo." && exit 1); \
		else \
			echo "Package manager not supported. Please install the following packages manually:"; \
			echo "  - build-essential"; \
			echo "  - freeglut3-dev"; \
			echo "  - libgl1-mesa-dev"; \
			echo "  - libglu1-mesa-dev"; \
			echo "  - libglfw3-dev"; \
			echo "  - libglew-dev"; \
			exit 1; \
		fi; \
	elif [ "$(UNAME_S)" = "Darwin" ]; then \
		echo "Installing macOS dependencies..."; \
		if ! xcode-select -p >/dev/null 2>&1; then \
			echo "Installing Xcode Command Line Tools..."; \
			xcode-select --install || (echo "Failed to install Xcode Command Line Tools" && exit 1); \
		fi; \
		if ! command -v brew >/dev/null; then \
			echo "Installing Homebrew..."; \
			/bin/bash -c "$$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)" || \
			(echo "Failed to install Homebrew" && exit 1); \
			export PATH="/opt/homebrew/bin:$$PATH"; \
		fi; \
		echo "Installing required packages..."; \
		brew install glfw glew freeglut || (echo "Failed to install required packages" && exit 1); \
		brew link --overwrite freeglut || true; \
	else \
		echo "Unsupported OS: $(UNAME_S)"; \
		echo "Please install the following dependencies manually:"; \
		echo "  - OpenGL development libraries"; \
		echo "  - GLUT or freeglut"; \
		echo "  - GLFW"; \
		echo "  - GLEW"; \
		exit 1; \
	fi; \
	echo "Dependencies installed successfully!"

# Package the application for distribution
package: clean
	@echo "Creating distribution package..."
	@mkdir -p dist/$(TARGET)
	@cp $(TARGET) README.md BUILD.md LICENSE dist/$(TARGET)/
	@tar -czf $(TARGET).tar.gz -C dist .
	@rm -rf dist
	@echo "Package created: $(TARGET).tar.gz"

# Help target
help:
	@echo "Brick Breaker - Makefile Help"
	@echo "=============================="
	@echo "make              - Build the game"
	@echo "make clean        - Remove build artifacts"
	@echo "make run          - Build and run the game"
	@echo "make install      - Install to system"
	@echo "make uninstall    - Uninstall the game"
	@echo "make package      - Create distribution package"

# Set default target
.PHONY: all clean run install uninstall package help
