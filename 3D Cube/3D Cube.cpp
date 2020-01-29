#include <iostream>
#include<Windows.h> 
#include<gl/glew.h>
#include<gl/GL.h>    
#include<gl/GLU.h>    
#include<gl/glut.h> 

// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
static double rotate_y = 0;
static double rotate_x = 0;

// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void drawScene() {

	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Rotate when user changes rotate_x and rotate_y
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	
	//--------------------------------------------------
	//Cube code
	//--------------------------------------------------
	//RED - FRONT
	glBegin(GL_POLYGON);

	glColor3f(0.835, 0.125, 0.176);
	glVertex3f(0.35, -0.35, -0.35);      // P1 is red
	glVertex3f(0.35, 0.35, -0.35);      // P2 is red
	glVertex3f(-0.35, 0.35, -0.35);      // P3 is red
	glVertex3f(-0.35, -0.35, -0.35);      // P4 is red

	glEnd();

	// YELLOW - BACK
	glBegin(GL_POLYGON);
	glColor3f(0.949, 0.886, 0.192);
	glVertex3f(0.35, -0.35, 0.35);
	glVertex3f(0.35, 0.35, 0.35);
	glVertex3f(-0.35, 0.35, 0.35);
	glVertex3f(-0.35, -0.35, 0.35);
	glEnd();

	// VIOLET - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(0.674, 0.407, 0.694);
	glVertex3f(-0.35, -0.35, -0.35);
	glVertex3f(-0.35, 0.35, -0.35);
	glVertex3f(-0.35, 0.35, 0.35);
	glVertex3f(-0.35, -0.35, 0.35);
	glEnd();

	// GREEN - LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.35, -0.35, -0.35);
	glVertex3f(0.35, 0.35, -0.35);
	glVertex3f(0.35, 0.35, 0.35);
	glVertex3f(0.35, -0.35, 0.35);
	glEnd();

	// ORANGE - TOP
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-0.35, 0.35, -0.35);
	glVertex3f(-0.35, 0.35, 0.35);
	glVertex3f(0.35, 0.35, 0.35);
	glVertex3f(0.35, 0.35, -0.35);
	glEnd();

	// BROWN - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(-0.35, -0.35, -0.35);
	glVertex3f(-0.35, -0.35, 0.35);
	glVertex3f(0.35, -0.35, 0.35);
	glVertex3f(0.35, -0.35, -0.35);
	glEnd();
	
	glFlush();
	glutSwapBuffers();
}

void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}


void print(void)
{
	system("CLS");
	std::cout << "Right side value: " << rotate_x << std::endl;
	std::cout << "Left side cubes: " << rotate_y << std::endl;

}

void NormalKeyHandler(unsigned char key, int x, int y)
{
	//  d - increase rotation by 5 degree

	if (key == 'd')
	{
		rotate_y += 5;
		glutPostRedisplay();
	}

	//  a - decrease rotation by 5 degree
	else if (key == 'a')
	{
		rotate_y -= 5;
		glutPostRedisplay();
	}
	else if (key == 'w')
	{
		if (rotate_x < 90)
		{
			rotate_x += 5;
			glutPostRedisplay();
		}
		
	}
	else if (key == 's')
	{
		if (rotate_x > -90)
		{
			rotate_x -= 5;
			glutPostRedisplay();
		}
		
	}
	//print();
	// and so on...
}

// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]) {
	glClear(GL_COLOR_BUFFER_BIT);

	//  Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	//  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(750, 750);/*set the initial window size*/
	glutInitWindowPosition(420, 30);/*set the initial window position*/

	// Create window
	glutCreateWindow("3D Cube");

	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	// Callback functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(NormalKeyHandler);// for  normal keys call

	//Background Color
	setup();


	//  Pass control to GLUT for events
	glutMainLoop();

	//  Return to OS
	return 0;

}