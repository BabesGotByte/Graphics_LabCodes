#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float w, h, tip = 0, turn = 0;
void specialKeys();
// Global Variables
double rotate_y=0.0; 
double rotate_x=0.0;

double s_x=1.0;
double s_y=1.0;
double s_z=1.0;

float ORG[3] = {0,0,0};

float XP[3] = {1,0,0}, XN[3] = {-1,0,0},
YP[3] = {0,1,0}, YN[3] = {0,-1,0},
ZP[3] = {0,0,1}, ZN[3] = {0,0,-1};

void reshape (int nw, int nh)
{
w = nw;
h = nh;
}

void Turn (int key, int x, int y)
{
switch (key) {
case GLUT_KEY_RIGHT: turn += 5; break;
case GLUT_KEY_LEFT : turn -= 5; break;
case GLUT_KEY_UP : tip -= 5; break;
case GLUT_KEY_DOWN : tip += 5; break;
}
}


void Draw_Axes (void)
{
glPushMatrix ();

glTranslatef (-2.4, -1.5, -5);
glRotatef    (tip , 1,0,0);
glRotatef    (turn, 0,1,0);
    glScalef     (0.25, 0.25, 0.25);

glLineWidth (2.0);

glBegin (GL_LINES);
       glColor3f (1,0,0);   // X axis is red.
       glVertex3fv (ORG);
       glVertex3fv (XP ); 
       glColor3f (0,1,0);   // Y axis is green.
       glVertex3fv (ORG);
       glVertex3fv (YP );
       glColor3f (0,0,1);   // z axis is blue.
       glVertex3fv (ORG);
       glVertex3fv (ZP ); 
    glEnd();

glPopMatrix ();
}

void Draw_Teapot (void)
{
glPushMatrix ();

glColor3f (1.0, 0.5, 0.1);
    glutSolidTeapot (1.0);

glLineWidth (2.0);
glColor3f (0.0, 0.2, 0.9);
    glutWireTeapot (1.01);

glPopMatrix ();

}



void display (void)
{
glViewport (0, 0, w, h);
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


glRotatef( rotate_x, 1.0, 0.0, 0.0 );
glRotatef( rotate_y, 0.0, 1.0, 0.0 );
glScalef( s_x, s_y, s_z );

Draw_Teapot ();
Draw_Axes ();

glutSwapBuffers ();

}

void main(int argc, char *argv[])
{
	glutInit(&argc,argv);
glutInitWindowSize (600, 400);
glutInitWindowPosition (400, 300);
glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
glutCreateWindow ("Corner Axes");
glutDisplayFunc (display);
glutIdleFunc (display);
glutReshapeFunc (reshape);
glutSpecialFunc (Turn);

glClearColor (0.1, 0.2, 0.1, 1.0);
glEnable     (GL_DEPTH_TEST);
glMatrixMode (GL_PROJECTION);
gluPerspective (40.0, 1.5, 1.0, 10.0);
glMatrixMode   (GL_MODELVIEW);

glutMainLoop ();

}
