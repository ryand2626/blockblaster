# Brick Breaker Game

A simple implementation of the classic Brick Breaker game using C++ and OpenGL.

## Prerequisites

### Option 1: Using Docker (Recommended)
- [Docker](https://www.docker.com/get-started) installed on your system

### Option 2: Native Build
#### macOS
- Xcode Command Line Tools (install with `xcode-select --install`)
- [Homebrew](https://brew.sh/) (package manager)

#### Linux
- Build essentials (g++, make)
- OpenGL and GLUT development libraries

## Building the Project

### Using Docker (Recommended)
```bash
git clone https://github.com/ryand2626/blockblaster.git
cd blockblaster
# Build and run in a container
docker build -t brick-breaker .
docker run -it --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix brick-breaker
```

### Native Build
1. Clone the repository:
   ```bash
   git clone https://github.com/ryand2626/blockblaster.git
   cd blockblaster
   ```

2. Run the build script (will install dependencies if needed):
   ```bash
   ./build.sh
   ```

   Or manually:
   ```bash
   # Install dependencies (requires sudo on Linux)
   make setup
   
   # Build the project
   make
   ```

## Running the Game

### After Native Build
```bash
./blockblaster
```

### Using Docker
```bash
docker run -it --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix brick-breaker
```

## Controls
- Move paddle: Mouse left/right
- Start/Stop game: 's' key
- Quit: 'q' key

## Troubleshooting

### X11/Docker Issues
If running in Docker, ensure:
1. X11 server is running on the host
2. X11 socket is accessible to Docker
3. Run with: `xhost +local:docker` before starting the container

### Missing Dependencies
If you see errors about missing headers or libraries:
- On Ubuntu/Debian: `sudo apt-get install freeglut3-dev libgl1-mesa-dev libglu1-mesa-dev`
- On Fedora: `sudo dnf install freeglut-devel mesa-libGL-devel mesa-libGLU-devel`
- On macOS: `brew install glfw glew freeglut`

## Project Structure
- `code.cpp`: Main game logic
- `Makefile`: Build configuration
- `setup_environment.sh`: Environment setup script (for development)
- `BUILD_CHECKLIST.md`: Development progress tracking

## Introduction :<br>
Brick Breaker is a classic arcade-style game in which the player controls a paddle that moves horizontally across the bottom of the screen to bounce a ball upward and break a wall of bricks located at the top of the screen. The game is built using the OpenGL graphics API, which enables the creation of 2D and 3D graphics in a cross-platform manner.<br><br>
The game level can be adjusted by changing the speed of the ball (via code) but user can change that using right click menu. The game also has a start/stop feature, which can be toggled using by pressing <b>“s”</b> button. Basic controls are <b>“a”</b> to move paddle left, <b>“d”</b> to move paddle right, <b>“q”</b> to quit the game.<br><br>
The game logic is implemented in the main loop, where the ball's position is updated based on its velocity, and collision detection is performed to determine if the ball has hit the paddle or a brick. If the ball hits a brick, the brick is removed, and the player's score is increased. If the ball hits the paddle, its velocity is adjusted based on the position of the paddle. If the ball hits the bottom of the screen, the game is over.<br>

## Basic Functions Used :<br>
1. `void draw_paddle();` - This function is responsible for drawing the paddle used in the game. The paddle is a rectangular object that the player controls to bounce the ball and prevent it from falling off the screen.<br>
2. `void brick(GLfloat x, GLfloat y, GLfloat z);` - This function is used to draw a single brick in the game. The brick is a rectangular object that the ball can break. The function takes in the x, y, and z coordinates of the brick to determine its position.<br>
3. `void draw_bricks();` - This function is responsible for drawing all the bricks in the game. It uses a loop to iterate through a 2D array that represents the bricks' positions and calls the brick() function to draw each brick.<br>
4. `void draw_ball();` - This function is used to draw the ball in the game. The ball is a circular object that bounces around the screen and breaks bricks.<br>
5. `void display();` - This function is the main display function that is called by OpenGL to draw the game scene. It calls the other functions to draw the paddle, bricks, and ball.<br>
6. `void init();` - This function is responsible for initializing the game. It sets up the window size, background color, and other OpenGL settings.<br>
7. `void mousemotion(int x, int y);` - This function is called when the player moves the mouse. It is used to update the paddle's position based on the mouse's position.<br>
8. `void keyboard(unsigned char key, int x, int y);` - This function is called when the player presses a key on the keyboard. It is used to handle key events such as quitting the game or resetting the ball.<br>
9. `void idle();` - This function is called when the game is idle, i.e., when there are no other events to handle. It is used to update the ball's position and check for collisions.<br>
10. `void reshape(GLsizei width, GLsizei height);` - This function is called when the window is resized. It is used to update the viewport and projection matrix to match the new window size.<br>
11. `void reset();` - This function is used to reset the game when the player loses a life or completes a level. It resets the ball and paddle positions and generates a new set of bricks to break.<br>


## Building

This project uses GLUT and OpenGL. On Debian-based systems, run the `setup` target to install dependencies:

```bash
make setup
```

Then build the game with:

```bash
make
```

Run `./blockblaster` to start the application.

