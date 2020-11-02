#include <GL/glut.h>
#include<GL/glu.h>
#include <stdlib.h>

// 0.769, 0, 0.776
// 0.341, 0, 0.494
// 0.251, 0.318, 0.306

int flag = 1;
GLfloat angle = 0.0f;
GLfloat angle2 = 0.0f;
int moving, startx, starty;
float r = 0.47f;
float g = 0.0f;
float b = 0.74f;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-12.0, 12.0, -1.0, 20.0, -15.0, 15.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void makecylinder(float height,float Base)
{
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	glColor3f(r, g, b);
	glPushMatrix();
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	gluCylinder(qobj, Base, Base - (0.2 * Base), height, 20, 20);
	glPopMatrix();
}
void maketree(float height,float Base)
{

	glPushMatrix();
	float angle;
	makecylinder(height, Base);
	glTranslatef(0.0f, height,0.0f);
	height -= height * 0.2f;
	Base -= Base * 0.3f;

	if (height > 1)
	{
		angle = 22.5f;
		glPushMatrix();
		glRotatef(angle, -1.0f, 0.0f, 0.0f);
		maketree(height, Base);
		glPopMatrix();
		glPushMatrix();
		glRotatef(angle, 0.5f, 0.0f, 0.866f);
		maketree(height, Base);
		glPopMatrix();
		glPushMatrix();
		glRotatef(angle, 0.5f, 0.0f, -0.866f);
		maketree(height, Base);
		glPopMatrix();
	}
	glPopMatrix();
}
static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
    srand(GLUT_ELAPSED_TIME);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	glRotatef(angle, 0, 1, 0);
	glRotatef(angle2, 0, 1, 0);

    maketree(4.0f,0.1f);
    glutSwapBuffers();
  glFlush();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'r': 
				r = 1.0f;
				g = 0.0f;
				b = 0.0f;
				break;
        case 'g': 
				r = 0.0f;
				g = 1.0f;
				b = 0.0f;
				break;
        case 'b':
				r = 0.0f;
				g = 0.0f;
				b = 1.0f;
				break;
		case 'y':
				r = 1.0f;
				g = 1.0f;
				b = 0.0f;
				break;
		case 'p':
				r = 0.47f;
				g = 0.0f;
				b = 0.74f;
				break;
        case 'q':
            exit(0);
            break;


    }

    glutPostRedisplay();
}



void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		moving=1;
		startx=x;
		starty=y;
	}
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
	{
		moving=0;
	}
}
void motion(int x,int y)
{
	if(moving)
	{
		angle = angle + (x - startx);
		angle2 = angle2 + (y - starty);
		startx = x;
		starty = y;
		glutPostRedisplay();
	}
}


/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1280,960);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("3d fractal tree");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);

   glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glClearColor(1, 0.627, 0.412,1);


    glEnable(GL_DEPTH_TEST);


    glutMainLoop();

    return 0;
}