#include <GL/glut.h>

// Function Prototypes
void display();
void specialKeys();
// Global Variables
double rotate_y=0.0; 
double rotate_x=0.0;

double s_x=1.0;
double s_y=1.0;
double s_z=1.0;

void init2D(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0);
	// used to set up the view volume, GL_MODELVIEW can be used to set up viewing transformation
	glMatrixMode(GL_PROJECTION);
	// gluOrtho2D specifies the coordinates to be used with the viewport which defaults to the window size.
	gluOrtho2D(-300, 300, -300.0, 300);
	//gluOrtho2D(-600, 600, -600.0, 600);
}

void specialKeys( int key, int x, int y ) {

	//  Right arrow - increase rotation by 5 degree
	if (key == GLUT_KEY_RIGHT)
	  rotate_y += 5;
	  
	//  Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
	  rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
	  rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
	  rotate_x -= 5;
	else if (key == GLUT_KEY_PAGE_UP)
	 { s_x+=0.1;
	  s_y+=0.1;
	  s_z+=0.1;
	}
	else if (key == GLUT_KEY_PAGE_DOWN)
	{  s_x-=0.1;
	  s_y-=0.1;
	  s_z-=0.1;
	}
  
//  Request display update
glutPostRedisplay();

}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor4f(1.0, 0.0, 0.0,0);


	// Reset transformations
	glLoadIdentity();
	
	// Set the camera
	//gluLookAt(	0.0f, 0.0f, -10.0f, 0.0f, 0.0f,  0.0f, 0.0f, -1.0f,  0.0f);


	// Rotate when user changes rotate_x and rotate_y
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
	glRotatef( rotate_y, 0.0, 1.0, 0.0 );
	glScalef( s_x, s_y, s_z );



	//Multi-colored side - FRONT
	glBegin(GL_POLYGON);

	glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
	glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
	glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
	glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple

	glEnd();
	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0, 1.0 );
	glVertex3f(  0.5, -0.5, 0.5 );
	glVertex3f(  0.5,  0.5, 0.5 );
	glVertex3f( -0.5,  0.5, 0.5 );
	glVertex3f( -0.5, -0.5, 0.5 );
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(  1.0,  0.0,  1.0 );
	glVertex3f( 0.5, -0.5, -0.5 );
	glVertex3f( 0.5,  0.5, -0.5 );
	glVertex3f( 0.5,  0.5,  0.5 );
	glVertex3f( 0.5, -0.5,  0.5 );
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  1.0,  0.0 );
	glVertex3f( -0.5, -0.5,  0.5 );
	glVertex3f( -0.5,  0.5,  0.5 );
	glVertex3f( -0.5,  0.5, -0.5 );
	glVertex3f( -0.5, -0.5, -0.5 );
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  1.0 );
	glVertex3f(  0.5,  0.5,  0.5 );
	glVertex3f(  0.5,  0.5, -0.5 );
	glVertex3f( -0.5,  0.5, -0.5 );
	glVertex3f( -0.5,  0.5,  0.5 );
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  0.0,  0.0 );
	glVertex3f(  0.5, -0.5, -0.5 );
	glVertex3f(  0.5, -0.5,  0.5 );
	glVertex3f( -0.5, -0.5,  0.5 );
	glVertex3f( -0.5, -0.5, -0.5 );
	glEnd();

	glFlush();
	glutSwapBuffers();
}


void main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("line drawing in opengl");
	//init2D(1.0, 1.0, 0.0);  // uncomment to draw in pixels otherwise use normalizaed(0-1) value for vertex functions
	
	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);

	glutMainLoop();
}
