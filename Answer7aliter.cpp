#include <GL/glut.h>

float ver_angle = 90, rotangle=-90;
float theta=90.001;
int click=0;

float rate=0.05;
void display(void) {
    double base,height;
    int slicesCols,ringsRows;
    base = 0.7;
    height = 1;
    slicesCols = 30;
    ringsRows = 50;

    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0.4f,0.4f,0.4f,1.0f);



    glEnable(GL_DEPTH_TEST);

    glColor3f(1.0f,.7f,0.0f);

    glLoadIdentity();

    gluLookAt(5.0f, 3.0f, 3.0f,
              4.0f, 1.5f, 0.0f,
              0.0f, 1.0f, 0.0f);
    glTranslatef(0.0, 0, -12);

    glLineWidth(3.0f);
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_LINES);
    
        glVertex3f(0.0f,0.0f, -3.0f);
        glVertex3f(0.0f, 0.0f, 7.0f);

        glVertex3f(0.0f,0.0f, -3.0f);
        glVertex3f(2.5f, -4.0f, -3.0f);
        
        glVertex3f(0.0f,0.0f, 7.0f);
        glVertex3f(2.5f, -4.0f, 7.0f);

        glVertex3f(0.0f,0.0f, -3.0f);
        glVertex3f(-2.5f, -4.0f, -3.0f);
        
        glVertex3f(0.0f,0.0f, 7.0f);
        glVertex3f(-2.5f, -4.0f, 7.0f);


    glEnd();

    glRotatef(rotangle, 0.0, 0.0, 1.0);

    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_LINES);

    glVertex3f(0.0f, -2.5f, 2.0f);
    glVertex3f(0.0f, 0.0f, 2.0f);

    glVertex3f(0.0f, -2.5f, -2.0f);
    glVertex3f(0.0f, 0.0f, -2.0f);



    glVertex3f(-1.0f, -3.5f, 2.0f);
    glVertex3f(0.0f, -2.5f, 2.0f);

    glVertex3f(-1.0f, -3.5f, -2.0f);
    glVertex3f(0.0f, -2.5f, -2.0f);
    
    glVertex3f(1.0f, -3.5f, -2.0f);
    glVertex3f(0.0f, -2.5f, -2.0f);
    
    glVertex3f(1.0f, -3.5f, 2.0f);
    glVertex3f(0.0f, -2.5f, 2.0f);

    glEnd();

    glColor3f( 1, 0, 0 );
    glBegin(GL_POLYGON);
    
    glVertex3f(-1.0,-3.5,2);
    glVertex3f( 1.0,-3.5 ,2);
    glVertex3f( 1.0, -3.5 ,-2);
    glVertex3f(-1.0,-3.5 ,-2);
    
    glEnd();


    glutSwapBuffers();
}

void reshape(int x, int y)
{
    glViewport(0, 0, (GLsizei)x,(GLsizei)y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, x/(double)y, 2, 20.0);
    glMatrixMode(GL_MODELVIEW);
}
void idle(void)
{
    if(click){
        
        theta-=0.005;
        rotangle+=rate;
        if(rotangle>=theta)
            rate=-rate;

        if(rotangle<=-theta)
            rate=-rate;

        if(theta<=2)
            rate=0;
    }
    display();
}
void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
}
void mouse(int btn, int state, int x, int y) {  
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) {  
        click=1;
    }
}
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(1000, 750);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("SWING");

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

