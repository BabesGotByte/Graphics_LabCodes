#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int xc, yc, r, angle;
float convert = 180.0 / PI;

void init2D(float r, float g, float b) {
	glClearColor(r, g, b, 0.0);
	// used to set up the view volume, GL_MODELVIEW can be used to set up viewing transformation
	glMatrixMode(GL_PROJECTION);
	// gluOrtho2D specifies the coordinates to be used with the viewport which defaults to the window size.
	gluOrtho2D(0.0, 600, 0.0, 600);
}

int abs(int x) {
    return ((x > 0) ? x : (-1 * x));
}

void drawCircle(int x, int y, int angle) {

    // 1st quad
    int X = xc+y, Y = yc+x;
    float num = Y - yc, dem = X - xc;
    float ang = atan(num / dem) * convert;
    if(ang > 45) ang = 45.0;
    if (ang <= angle) {
        glVertex2f(X, Y); // 0 - 45

    }
    X = xc+x, Y = yc+y;
    int ang1 = 90 - ang;
    if (ang1 <= angle) {
        glVertex2f(X, Y); // 45 - 90

    }

    // 2nd quad
    X = xc-x, Y = yc+y;
    int ang2 = 90 + ang;
    if (ang2 <= angle) {
        glVertex2f(X, Y); // 90 - 135
    }
    X = xc-y, Y = yc+x;
    int ang3 = 180 - ang;
    if (ang3 <= angle) {
        glVertex2f(X, Y); // 135 - 180
    }

    // 3rd quad
    X = xc-y, Y = yc-x;
    int ang4 = 180 + ang;
    if (ang4 <= angle) {
        glVertex2f(X, Y); // 180 - 225
    }
    X = xc-x, Y = yc-y;
    int ang5 = 270 - ang;
    if (ang5 < angle) {
        glVertex2f(X, Y); // 225 - 270
    }

    // 4th quad
    X = xc+x, Y = yc-y;
    int ang6 = 270 + ang;
    if (ang6 <= angle) {
        glVertex2f(X, Y); // 270 - 315
    }
    X = xc+y, Y = yc-x;
    int ang7 = 360 - ang;
    if (ang7 <= angle) {
        glVertex2f(X, Y); // 315 - 360
    }
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.7, 0.1);
    glVertex2f(xc, yc);
    glEnd();

	glColor3f(1.0, 0.7, 0.0);
	int x = 0, y = r;
    int d = 3 - 2 * r;
	glPointSize(3);
	glBegin(GL_POINTS);
    drawCircle(x, y, angle);
    
    while (y >= x) {
        x++;

        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
        drawCircle(x, y, angle);
    }
    
	glEnd();
	glFlush();
}


void main(int argc, char *argv[]) {
	glutInit(&argc,argv);
    printf("Enter xc, yc, r, angle:");
    scanf("%d %d %d %d", &xc, &yc, &r, &angle);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("DDA Algorithm");
	init2D(0.1, 0.2, 0.3);  // uncomment to draw in pixels otherwise use normalizaed(0-1) value for vertex functions
	glutDisplayFunc(display);
	glutMainLoop();
}