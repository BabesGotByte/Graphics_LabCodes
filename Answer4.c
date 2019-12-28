#include <GL/glut.h>
#include <math.h>
//#include<iostream.h>
#include <stdlib.h>
#include<stdio.h>

float a, b, c, d,e,f;
int xf, yf,xf1,yf1; 
void delay(unsigned int mseconds) 
{ 
    clock_t goal = mseconds + clock(); 
    while (goal > clock()) 
        ; 
} 
void setpixel(GLint xCoordinate, GLint yCoordinate) {
  glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 1.0f); 
  glVertex2i(xCoordinate, yCoordinate);
  glEnd();
  glFlush();
}

void DDA(int X1, int Y1, int X2, int Y2) {
  int I;
  float Length;
  float X, Y, Xinc, Yinc;
  Length = abs(X2 - X1);
  if (abs(Y2 - Y1) > Length)
    Length = abs(Y2 - Y1);
  Xinc = (X2 - X1) / (Length);
  Yinc = (Y2 - Y1) / (Length);
  X = X1;
  Y = Y1;
  for (I = 0; I < Length; I++) {
    setpixel((X + 0.5), (Y + 0.5));
    X = X + Xinc;
    Y = Y + Yinc;
  }
}

void drawmyline() { 

float thetaSpeed=0.05;

    float theta = 0.050,theta2 = 0.05; 
    while (1) { 
        glClear(GL_COLOR_BUFFER_BIT); 
        
  
        // update theta anticlockwise rotation 
        theta = theta + thetaSpeed; 
	theta2 = theta2+0.2 + thetaSpeed; 
	
  
        // check overflow 
        if (theta >= (2.0 * 3.14159)) 
            theta = theta - (2.0 * 3.14159); 
  	if (theta2 >= (2.0 * 3.14159)) 
            theta2 = theta2 - (2.0 * 3.14159);
        // actual calculations.. 
        xf = c + (int)((float)(a - c) * cos(theta)) 
             - ((float)(b - d) * sin(theta)); 
        yf = d + (int)((float)(a - c) * sin(theta)) 
             + ((float)(b - d) * cos(theta)); 
	xf1 = e + (int)((float)(a - e) * cos(theta)) 
             - ((float)(b - f) * sin(theta2)); 
        yf1 = f + (int)((float)(a - e) * sin(theta)) 
             + ((float)(b - f) * cos(theta2));
	xf1 = xf1 + (int)((float)(xf - xf1) * cos(theta2)) 
             - ((float)(yf - yf1) * sin(theta2)); 
        yf1 = yf1 + (int)((float)(xf - xf1) * sin(theta2)) 
             + ((float)(yf - yf1) * cos(theta2)); 
	
	
  	//printf("%d %d %d %d",c,d,e,f);
        DDA(a, b, xf, yf);
	DDA(xf, yf, xf1, yf1);
        glFlush(); 
        // creating a delay 
        // so that the point can be noticed 
        delay(1); 
    
 }

    

}
void init(void) {

  glClearColor(1.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

int main(int argc, char **argv) {
  //printf("DDA\nEnter co-ordinates to draw line(Co-ordinates in between(0 - " "300))\n");
  printf("X1 = ");
  scanf("%f",&a);
  printf("Y1 = ");
  scanf("%f",&b);
  printf("X2 = ");
  scanf("%f",&c);
  printf("Y2 = ");
  scanf("%f",&d);
  printf("X3 = ");
  scanf("%f",&e);
  printf("Y3 = ");
  scanf("%f",&f);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(200, 200);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Digital Differential Analyzer Algorithm");
  init();
  glutDisplayFunc(drawmyline);
  glutMainLoop();
  return 0;
}

