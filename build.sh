#!/bin/bash
set -e

echo "🚀 Setting up Brick Breaker build environment..."

# Check if we're running in Docker
if [ -f /.dockerenv ] || grep -q docker /proc/1/cgroup 2>/dev/null; then
    echo "🐋 Detected Docker environment"
    # In Docker, we should already have all dependencies installed
    if [ ! -f "/usr/include/GL/glut.h" ] && [ ! -f "/usr/include/freeglut.h" ]; then
        echo "❌ Error: GLUT headers not found in Docker container"
        echo "   Please ensure your Dockerfile includes:"
        echo "   RUN apt-get update && apt-get install -y freeglut3-dev libgl1-mesa-dev libglu1-mesa-dev"
        exit 1
    fi
else
    echo "💻 Detected host environment"
    # On host, use make to install dependencies
    if ! make setup; then
        echo "❌ Failed to install dependencies"
        exit 1
    fi
fi

# Build the project
echo "🔨 Building Brick Breaker..."
if make -j$(nproc); then
    echo "✅ Build successful! Run the game with: ./blockblaster"
    echo "   Controls: Mouse to move paddle, 's' to start/stop, 'q' to quit"
else
    echo "❌ Build failed. Please check the error messages above."
    exit 1
fi
