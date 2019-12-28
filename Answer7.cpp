#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

int flag = 0;
int dir = 1;
int thres_angle = 30;
float speed = 1.0;

void changeSize(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;

    float ratio = w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(60.0f, ratio, 0.1f, 100.0f);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

float angle = 0.0f;

void renderScene(void)
{

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(0.0f, 15.0f, 30.0f,
              0.0f, 0.0f, 0.0f,
              0.0f, 1.0f, 0.0f);


    glRotatef(30, 0.0f, 1.0f, 0.0f);
    glLineWidth(5.0f);
    glColor3f(1.0, 0.7, 0.0);
    glBegin(GL_LINES);
        glVertex3f(-8.0f, 0.0f, 3.0f);
        glVertex3f(-8.0f, 10.0f, 0.0f);
        glVertex3f(-8.0f, 0.0f, -3.0f);
        glVertex3f(-8.0f, 10.0f, 0.0f);

        glVertex3f(8.0f, 0.0f, 3.0f);
        glVertex3f(8.0f, 10.0f, 0.0f);
        glVertex3f(8.0f, 0.0f, -3.0f);
        glVertex3f(8.0f, 10.0f, 0.0f);

        glVertex3f(-8.0f, 10.0f, 0.0f);
        glVertex3f(8.0f, 10.0f, 0.0f);
    glEnd();

    glColor3f(0.0, 0.7, .8);
    glTranslatef(0.0f, 10.0f, 0.0f);
    glRotatef(angle, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -10.0f, 0.0f);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glVertex3f(-1.3f, 10.0f, 0.0f);
        glVertex3f(-1.3f, 4.0f, 0.0f);
        glVertex3f(1.3f, 10.0f, 0.0f);
        glVertex3f(1.3f, 4.0f, 0.0f); 

        glVertex3f(-1.3f, 4.0f, 0.0f);
        glVertex3f(-1.3f, 2.0f, -0.8f);
        glVertex3f(-1.3f, 4.0f, 0.0f);
        glVertex3f(-1.3f, 2.0f, 0.8f);

        glVertex3f(1.3f, 4.0f, 0.0f);
        glVertex3f(1.3f, 2.0f, -0.8f);
        glVertex3f(1.3f, 4.0f, 0.0f);
        glVertex3f(1.3f, 2.0f, 0.8f);

        glColor3f(0.9, 0.9, 0.9);
        glVertex3f(-1.5f, 2.0f, -1.0f);
        glVertex3f(1.5f, 2.0f, -1.0f);
        glVertex3f(1.5f, 2.0f, 1.0f);
        glVertex3f(-1.5f, 2.0f, 1.0f);
        glVertex3f(-1.5f, 2.0f, 1.0f);
        glVertex3f(-1.5f, 2.0f, -1.0f);
        glVertex3f(1.5f, 2.0f, 1.0f);
        glVertex3f(1.5f, 2.0f, -1.0f);
    glEnd();
    
    if(flag == 1) {
        if (thres_angle == 0) flag = 0;
        if (angle >= thres_angle && dir == 1) { thres_angle--; dir = -1; speed *= 0.95;} 
        if(angle <= -thres_angle && dir == -1) { thres_angle--; dir = 1; speed *= 0.95;}
        angle = angle + ((float) dir * speed);
        printf("%f %f\n", angle, speed);
    }

    glutSwapBuffers();
}

void Timer(int value) {
    glutTimerFunc(1000, Timer, 0);
    glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y) {  
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) {  
        flag = 1;
    }  
}  

int main(int argc, char **argv)
{

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Swing Animation");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutMouseFunc(mouse); 
    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}