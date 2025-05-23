# Build Instructions for Brick Breaker

This document provides detailed instructions for building the Brick Breaker game on different platforms.

## Prerequisites

### macOS
1. Install Xcode Command Line Tools:
   ```bash
   xcode-select --install
   ```
2. Install Homebrew (if not already installed):
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```
3. Install required libraries:
   ```bash
   brew install cmake pkg-config glfw glew freeglut
   ```

### Ubuntu/Debian Linux
```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake pkg-config libglfw3-dev libglew-dev freeglut3-dev
```

### Fedora Linux
```bash
sudo dnf install -y gcc-c++ cmake pkgconf glfw-devel glew-devel freeglut-devel
```

## Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/ryand2626/blockblaster.git
   cd blockblaster
   ```

2. Build the project:
   ```bash
   make clean
   make
   ```

## Running the Game

```bash
./blockblaster
```

## Troubleshooting

### macOS Issues
- If you get GLUT-related errors, ensure you have the latest Xcode Command Line Tools
- For OpenGL deprecation warnings, you can safely ignore them or add `-Wno-deprecated-declarations` to CXXFLAGS in the Makefile

### Linux Issues
- If you get GLX errors, ensure your graphics drivers are properly installed
- For missing GL/glut.h, install the freeglut development package for your distribution

## Dependencies

- OpenGL (included with macOS/Windows, Mesa on Linux)
- GLFW 3.0+
- GLEW 2.0+
- FreeGLUT 3.0+
- CMake 3.10+ (for building from source)
