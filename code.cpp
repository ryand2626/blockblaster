#include <stdlib.h>    
#include <GL/glut.h>
#include<stdio.h>
#include<string.h>
#include <math.h>
//#include<iostream>
//using namespace std;


int score = 0;
int brick_color = 0, ball_color = 2, level = 2,
    paddle_color = 2, text_color = 3, size = 1;
GLfloat twoModel[]={GL_TRUE};
int game_level[] = {40,30,20};
float rate = game_level[level];

GLfloat brick_color_array[][3] = {{1,0,0},{0,0,1},{0,1,0},{1,1,1}};
GLfloat paddle_color_array[][3] = {{1,0,0},{0,0,1},{0,1,0},{0,1,1}};
GLfloat text_color_array[][4] = {
    {1,0,0,1},   // red
    {0,0,1,1},   // blue
    {0,1,0,1},   // green
    {1,1,0,1},   // yellow
    {0.5,0.5,0.5,1} // grey
};
GLfloat paddle_size[] = {2,4,6};
//The grid parameters for the bricks
int rows = 4;
int columns = 10;

// Structure to store the coordinates of each brick
struct brick_coords{
	
	GLfloat x;
	GLfloat y;
};

//Array to store the bricks
brick_coords brick_array[50][50];
GLfloat px,bx = 0,by = -12.94 ,speed = 0,dirx=0,diry=0,start = 0;



// Function to draw the paddle
void draw_paddle()
{
	glDisable(GL_LIGHTING);
	glColor3fv(paddle_color_array[paddle_color]);
	glBegin(GL_POLYGON);
	glVertex3f(-paddle_size[size]+px,0-15,0);
	glVertex3f(paddle_size[size]+px,0-15,0);
	glVertex3f(paddle_size[size]+px,1-15,0);
	glVertex3f(-paddle_size[size]+px,1-15,0);
	glEnd();
	glEnable(GL_LIGHTING);
}


//Function to draw a single brick
void brick(GLfloat x,GLfloat y, GLfloat z)
{	

	glDisable(GL_LIGHTING);
	glColor3fv(brick_color_array[brick_color]);
	glBegin(GL_QUADS);
	glVertex3f(x,y,z);
	glVertex3f(x+3,y,z);
	glVertex3f(x+3,y+1,z);
	glVertex3f(x,y+1,z);       
	glEnd();
	glEnable(GL_LIGHTING);
}


// Function to draw the grid of bricks
void draw_bricks()
{
	
	int i,j;
	if(start == 0)
	{
		for(i = 1;i<=rows;i++)
		{
			for(j = 1;j<=columns;j++)
			{   
				
				brick_array[i][j].x = (GLfloat)(j*4*0.84);
				brick_array[i][j].y = (GLfloat)(i*2*0.6) ;
			}
		}
	}
	
	
	glPushMatrix();
	glTranslatef(-19.5,5,0);

	for(i = 1;i<=rows;i+=1)
	{
		for(j = 1;j<=columns;j+=1)
		{
			
			if(brick_array[i][j].x==0 || brick_array[i][j].y ==0)
			{
				continue;
			}
			brick(brick_array[i][j].x,brick_array[i][j].y,0);
		}
	}
	glPopMatrix();
	
}

//Function to draw the spherical ball
void draw_ball()
{
//	glDisable(GL_LIGHTING);

	GLfloat ambient1[] = {1,1,1};
	GLfloat diffuse1[] = {0.4,0.4,0.4};
	GLfloat specular1[] = {1,1,1};
	
	GLfloat position[] = {0,0,-50,1};
	GLfloat ambient2[] = {0,0,0};
	GLfloat diffuse2[] = {1,1,1};
	GLfloat specular2[] = {0,1,1};
	
	float materialColours[][3]={{1,0,0},{0,0,1},{0,1,1}};
	GLfloat matAmbient1[] = {1,1,1};
	GLfloat matDiffuse1[] = {1,1,1};
	GLfloat matSpecular1[] = {1,1,1};
	GLfloat shininess[] = {1000};
	
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular1);
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambient1);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse1);
	
	glLightfv(GL_LIGHT1,GL_POSITION,position);
	glLightfv(GL_LIGHT1,GL_SPECULAR,specular2);
	glLightfv(GL_LIGHT1,GL_AMBIENT,ambient2);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse2);
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,materialColours[ball_color]);
	
	
	
	glPushMatrix();
	glTranslatef(bx,by,0);
	glScalef(1.0, 1.0, 0.5);
	//glScalef(size[i], size[], size[]);
	glutSolidSphere(1.0, 52, 52);
	   
	glPopMatrix();
	
}


//mouse function
void mousemotion(int x,int y)
{
  
  if(start == 1)
  {
    px=(x-glutGet(GLUT_WINDOW_WIDTH)/2)/20;
    if(px>15)
	  {
		  px=15;
	  }
	  if(px<-15)
	  {
		  px=-15;
	  }
    }
    
    else glutSetCursor(GLUT_CURSOR_INHERIT);
}

//handle brick color
void change_brick_color(int action)
{
	
	brick_color=action-1;
}

//handle ball color
void change_ball_color(int action)
{
	
	ball_color=action-1;
}

//handle level
void change_difficulty(int action)
{
	
	level=action-1;
}

//handle menu
void handle_menu(int action)
{
	
}

//handle paddle color
void change_paddle_color(int action)
{
	paddle_color = action -1;
}

//handle paddle color
void change_text_color(int action)
{
	text_color = action -1;
}

//handle paddle size
void change_paddle_size(int action)
{
	size = action -1;
}

//add menu
void addMenu()
{
	
	
	int submenu1 = glutCreateMenu(change_brick_color);
	glutAddMenuEntry("Red",1);
	glutAddMenuEntry("Blue",2);
	glutAddMenuEntry("Green",3);
	glutAddMenuEntry("White",4);

	int submenu2 = glutCreateMenu(change_ball_color);
	glutAddMenuEntry("Red",1);
	glutAddMenuEntry("Blue",2);
	glutAddMenuEntry("Cyan",3);


	
	int submenu4 = glutCreateMenu(change_paddle_color);
	glutAddMenuEntry("Red",1);
	glutAddMenuEntry("Blue",2);
	glutAddMenuEntry("Green",3);
	glutAddMenuEntry("Cyan",4);


	
	int submenu3 = glutCreateMenu(change_difficulty);
	glutAddMenuEntry("Easy",1);
	glutAddMenuEntry("Medium",2);
	glutAddMenuEntry("Hard",3);
	
	int submenu5 = glutCreateMenu(change_text_color);
	glutAddMenuEntry("Red",1);
	glutAddMenuEntry("Blue",2);
	glutAddMenuEntry("Green",3);
	glutAddMenuEntry("Yellow",4);

	
	int submenu6 = glutCreateMenu(change_paddle_size);
	glutAddMenuEntry("Small",1);
	glutAddMenuEntry("Medium",2);
	glutAddMenuEntry("Large",3);
	
	glutCreateMenu(handle_menu);
	glutAddSubMenu("Bricks Color",submenu1);
	glutAddSubMenu("Ball Color",submenu2);
	glutAddSubMenu("Paddle Color",submenu4);
	glutAddSubMenu("Text Color",submenu5);
	glutAddSubMenu("Difficulty",submenu3);
	glutAddSubMenu("Paddle Size",submenu6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
}



//Function to print the score on the screen
void text( int sc)
{
	glDisable(GL_LIGHTING);
	char text[40];
	char difficulty[10];
	if(level == 0)
	{
		sprintf(difficulty,"Easy");
	}
	
	if(level == 1)
	{
		sprintf(difficulty,"Medium");
	}
	
	if(level == 2)
	{
		sprintf(difficulty,"Hard");
	}
	if(sc <40)
	sprintf(text,"Difficulty: %s    Your Score: %d",difficulty, sc);
	else
	{
	  sprintf(text,"You have won !!");
	  start = 0;
	  by = -12.94;
	  bx = 0;
	  dirx = 0;
	  diry = 0;
	  px = 0;	

	}
        // Render the text as a 2D overlay
        glColor4fv(text_color_array[text_color]);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(-20,20,-20,20);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glRasterPos2f(-19.f, 18.f);
        for(int i = 0; text[i] != '\0'; i++)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glEnable(GL_LIGHTING);
}

// Display basic instructions at the bottom of the screen
void draw_instructions()
{
        glDisable(GL_LIGHTING);
        const char *msg = "Press 's' to start, 'a'/'d' to move, 'q' to quit";
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(-20,20,-20,20);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glColor4fv(text_color_array[text_color]);
        glRasterPos2f(-19.f, -19.f);
        for(const char *p = msg; *p; ++p)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p);
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glEnable(GL_LIGHTING);
}

// Draw a simple predictive line showing the ball's next bounce point
void draw_predictive_line()
{
        if(!start)
                return;

        float dx = dirx / rate;
        float dy = diry / rate;
        float x = bx;
        float y = by;

        // advance until hitting a wall or the ceiling
        for(int i = 0; i < 200; ++i)
        {
                x += dx;
                y += dy;
                if(x < -16 || x > 16)
                {
                        dx *= -1;
                        break;
                }
                if(y > 14)
                {
                        dy *= -1;
                        break;
                }
        }

        glDisable(GL_LIGHTING);
        glColor4fv(text_color_array[4]);
        glBegin(GL_LINES);
        glVertex3f(bx, by, 0);
        glVertex3f(x, y, 0);
        glEnd();
        glEnable(GL_LIGHTING);
}

//The main display function
void display (void) {
        // Dark grey background for a cleaner look
        glClearColor (0.1f,0.1f,0.1f,1.0f);
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        gluLookAt(0,0,0,0,0,-25,0,1,0);
        glTranslatef(0,0,-25);
        draw_paddle();
        draw_bricks();
        draw_ball();
        draw_predictive_line();
        text(score);
        draw_instructions();
        glutSwapBuffers();
}



//function to turn on lights
void lightsOn()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}

void reshape (int w, int h) {
	glViewport (0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 1000.0);
	glMatrixMode (GL_MODELVIEW);
}


//function to take in keyboard entries
void keyboard (unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'd': px+=3; break;
		case 'a': px-=3; break;
		case 'q': exit(0); break;
		case 's':
		if(!start)
		{
			dirx = diry= 1;
			rate = game_level[level];
			start = 1;
			score = 0;
			glutSetCursor(GLUT_CURSOR_NONE);
			
		}
		break;
	}
	if(px>15)
	{
		px=15;
	}
	if(px<-15)
	{
		px=-15;
	}
	if(start== 0)
	{
		px=0;
	}
	glutPostRedisplay();
}


//Function to handle the case when the ball strikes the bricks
void hit()
{
	int i,j;
	for(i = 1;i<=rows;i++)
		for(j=1;j<=columns;j++)
		{
			if((bx>=brick_array[i][j].x-19.5-0.1 )&&( bx<=brick_array[i][j].x + 3-19.5+ 0.1))
			{
				if(by >=brick_array[i][j].y+5-0.1 && by <=brick_array[i][j].y+5 +1.2 +0.1)
				{
					brick_array[i][j].x = 0;
					brick_array[i][j].y = 0;
					diry= diry*-1;
				
					score++;
				}
				//cout<<bx<<" "<<by<<"\t"<<brick_array[i][j].x<<" "<<brick_array[i][j].y;
			}
//			else if(by >=brick_array[i][j].y+5 -0.1 && by <=brick_array[i][j].y+5 +1.2+0.1)
//			{
//				if((bx>=brick_array[i][j].x-19.5 -0.1)&&( bx<=brick_array[i][j].x + 3-19.5 + 0.1 ))
//				{
//					brick_array[i][j].x = 0;
//					brick_array[i][j].y = 0;
//					dirx= dirx*-1;
//					score++;				
//				}
//				//cout<<bx<<" "<<by<<"\t"<<brick_array[i][j].x<<" "<<brick_array[i][j].y;
//			}
		}
}


//The idle function. Handles the motion of the ball along with rebounding from various surfaces
void idle()
{
	hit();
	if(bx<-16 || bx>16 && start == 1)
	{
		dirx = dirx*-1;
	}
	if(by<-15 || by>14 && start == 1)
	{
		diry = diry*-1;
	}
	bx+=dirx/(rate);
	by+=diry/(rate);
	rate-=0.001; // Rate at which the speed of ball increases
	
	float x = paddle_size[size];
	//Make changes here for the different position of ball after rebounded by paddle
	if( by<=-12.8 && bx<(px+x*2/3) && bx>(px+x/3)&& start == 1 )
	{
		dirx = 1;
		diry = 1;
	}
	else if(by <=-12.8 && bx<(px-x/3) && bx>(px-x*2/3) && start == 1 )
	{
		dirx = -1;
		diry = 1;
	}
	else if( by<=-12.8 && bx<(px+x/3) &&bx>(px-x/3) && start == 1)
	{
		dirx = dirx;
		diry = 1;
	}
	else if(by <=-12.8 && bx<(px-(x*2/3)) && bx>(px-(x+0.3)) && start == 1 )
	{
		dirx = -1.5;
		diry = 0.8;
	}
	else if(by<=-12.8 && bx<(px+(x+0.3)) && bx>(px+x/3)&& start == 1 )
	{
		dirx = 1.5;
		diry = 0.8;
	}
	else if(by<-13)
	{
		start = 0;
		by = -12.8;
		bx = 0;
		dirx = 0;
		diry = 0;
		px = 0;	
	}
	glutPostRedisplay();
}


int main (int argc,char **argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize (900, 900);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Brick Breaker");
	glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	glEnable(GL_DEPTH_TEST);
	glutIdleFunc (idle);
	glutPassiveMotionFunc(mousemotion);
	glutKeyboardFunc(keyboard);
	lightsOn();
	addMenu();
	glutMainLoop ();
	return 0;
}
