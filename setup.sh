#!/bin/bash
set -e

# Install OpenGL and GLUT development libraries
sudo apt-get update
sudo apt-get install -y build-essential freeglut3-dev

# Additional dependencies can be added here

echo "Dependencies installed"
