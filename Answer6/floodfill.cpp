// Code by Prateek Mishra IIT2018199, IIIT Allahabad.
// In this code I have implemented formation of a pentagon using mouse clicks and then filling color in the pentagon using flood fill.
#include <GL/glut.h>
#include <cmath>

int wtemp = 700;
int htemp = 700;
int noofclicks = 0;

float fillColor[3] = {0.4, 0.0, 0.0};
float borderColor[3] = {0.0, 0.0, 0.0};
float defaultcolor[3] = {0.6, 0.8, 0.1};

void display()
{
	glClearColor(0.4, 0.0, 0.0, 0.1);
	glColor3f(1.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

typedef struct //this is a structure for 2d coordinates.
{
	float x;
	float y;
} Coordinates;
Coordinates p1, p2, p3, p4, p5; // the five points of the pentagon.

void putPixel(int x, int y, float f[3])
{
	glBegin(GL_POINTS);
	glColor3fv(f);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void getPixel(int x, int y, float pixels[3])
{
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels);
}

void boundaryFill(int x, int y, float fillColor[3], float borderColor[3]) //Checking if we have reached the boundary or the pixel has been filled.
{
	float interiorColor[3];
	getPixel(x, y, interiorColor);

	if ((interiorColor[0] != borderColor[0]) && (interiorColor[1] != borderColor[1]) && (interiorColor[2] != borderColor[2]) &&
	        (interiorColor[0] != fillColor[0]) && (interiorColor[1] != fillColor[1]) && (interiorColor[2] != fillColor[2]))
	{
		putPixel(x, y, fillColor);
		boundaryFill(x + 1, y, fillColor, borderColor);
		boundaryFill(x - 1, y, fillColor, borderColor);
		boundaryFill(x, y + 1, fillColor, borderColor);
		boundaryFill(x, y - 1, fillColor, borderColor);
	}
}

void floodFill(int x, int y, float defaultcolor[3], float fillColor[3])
{
	float interiorColor[3];
	getPixel(x, y, interiorColor);
	if (interiorColor[0] == defaultcolor[0] and interiorColor[1] == defaultcolor[1] and interiorColor[2] == defaultcolor[2]) //checking if the pixel is the default color pixel.
	{
		putPixel(x, y, fillColor);
		floodFill(x + 1, y, defaultcolor, fillColor);
		floodFill(x, y + 1, defaultcolor, fillColor);
		floodFill(x - 1, y, defaultcolor, fillColor);
		floodFill(x, y - 1, defaultcolor, fillColor);
	}
	return;
}

void drawpolygon(Coordinates pt1, Coordinates pt2, Coordinates pt3, Coordinates pt4, Coordinates pt5)
{
	glColor3fv(borderColor);
	glBegin(GL_LINES);
	glVertex2i(pt1.x, pt1.y);
	glVertex2i(pt2.x, pt2.y);

	glVertex2i(pt2.x, pt2.y);
	glVertex2i(pt3.x, pt3.y);

	glVertex2i(pt3.x, pt3.y);
	glVertex2i(pt4.x, pt4.y);

	glVertex2i(pt4.x, pt4.y);
	glVertex2i(pt5.x, pt5.y);

	glVertex2i(pt5.x, pt5.y);
	glVertex2i(pt1.x, pt1.y);
	glEnd();
	glFlush();
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			switch (noofclicks)
			{
			case 0:
				p1.x = x;
				p1.y = (htemp - y);
				noofclicks = 1;
				break;

			case 1:
				p2.x = x;
				p2.y = htemp - y;
				noofclicks = 2;
				break;
			case 2:
				p3.x = x;
				p3.y = htemp - y;
				noofclicks = 3;
				break;
			case 3:
				p4.x = x;
				p4.y = htemp - y;
				noofclicks = 4;
				break;
			case 4:
				p5.x = x;
				p5.y = htemp - y;
				noofclicks = 0;
				drawpolygon(p1, p2, p3, p4, p5);
				float xc = (p1.x + p2.x + p3.x + p4.x + p5.x) / 5; //We are beginning coloring from the centroid of the polygon.
				float yc = (p1.y + p2.y + p3.y + p4.y + p5.y) / 5;
				// boundaryFill(xc, yc, fillColor, borderColor);
				floodFill(xc, yc, fillColor, borderColor);
				break;
			}
		}
	}
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(wtemp, htemp);
	glutCreateWindow("Border Fill and then Flood fill");
	gluOrtho2D(0.0, (GLdouble)wtemp, 0.0, (GLdouble)htemp);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
/*How to use
First click anywhere on the screen for five times and then a pentagon will be formed. The pentagon would be first colored using flood fill algorithm.*/