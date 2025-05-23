#!/usr/bin/env bash
set -e

# Install dependencies for building the project
apt-get update
DEBIAN_FRONTEND=noninteractive apt-get install -y \
    build-essential \
    freeglut3-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev

