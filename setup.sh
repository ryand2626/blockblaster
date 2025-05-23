#!/usr/bin/env bash
set -e

# Install dependencies for building the project
sudo apt-get update
DEBIAN_FRONTEND=noninteractive sudo apt-get install -y \
    build-essential \
    freeglut3-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev

# Additional dependencies can be added here

echo "Dependencies installed"
