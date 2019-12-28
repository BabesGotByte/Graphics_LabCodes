// C program for DDA line generation
#include <stdio.h>
#include <GL/glut.h>

void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // used to set up the view volume,
    //GL_MODELVIEW can be used to set up viewing
    //transformation
    glMatrixMode(GL_PROJECTION);
    // gluOrtho2D specifies the coordinates to
    //be used with the viewport which defaults to the
    //window size.
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

int abs(int n)
{
    return ((n > 0) ? n : (n * (-1)));
}

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void DDA(int X0, int Y0, int X1, int Y1)
{
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        // putpixel(X, Y, RED);
        draw_pixel(X, Y);
        X += Xinc;
        Y += Yinc;
        // delay(100);
    }
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // glColor3f(1.0, 0.0, 0.0);
    DDA(375, 200, 750, 650);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // glutInitWindowSize(1920, 1280);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}
