# Graphics_LabCodes
[![Generic badge](https://img.shields.io/badge/GRAPHICS-LAB-BLUE.svg)](https://shields.io/)
[![Generic badge](https://img.shields.io/badge/VISUAL-COMPUTING-<BLUE>.svg)](https://shields.io/)
[![Generic badge](https://img.shields.io/badge/Language-C++-<BLUE>.svg)](https://shields.io/)

Graphics & Visual Computing Lab's Codes 

Command to compile the code
gcc test.c -lGL -lGLU -lglut

We have tried not use any library function other than one to draw a point.

#include <GL/glut.h>

## Techniques and Algorithms Covered:

We have covered the following algorithms:
* DDA (Line Generation)
* Bresenham
* Circle Generation Algorithms
* Draw shapes: Pentagon, Cone etc
* Coloring Algoriths (flood-fill, boundary-fill)
* Animations (Animated swing)
* Bezier Algorithm (Draw shapes like flowers, cylinder)
* Fractals (3-D fractal tree)


![](https://img.shields.io/badge/Graphics-Computing-orange.svg)
![](https://img.shields.io/badge/Language-C++-blue.svg)
![](https://img.shields.io/badge/Library-OpenGL-green.svg)


## Problem Statements

Some generic GVC codes are present in the Extra_Codes directory, apart from them, we have taken some specific problems and with the following problem statements:


1. Implement DDA Algorithm to draw a line.</br>
2. Implement Bresenham Algorithm to draw a line.</br>
3. WAP to draw an Arc between specified start and end angle.Write two separate implementation using Bresenham and midpoint circle algorithms.</br>
4. WAP to to draw two interconnected lines. Taking one end of the first line as pivot rotate both lines. Taking other end of the first line where second line is attached as pivot, rotate the second line. </br>
5. WAP a program to draw two cones(see attch. image) connected along their tips and rotating along the line passing through their tips. Hint: use glutWireCone function to daw the cone. use transformation  mechanism provided by opengl to make transformations.</br>
6. Write a program to draw a user defined pentagon and fill it using the following algorithms:</br>
   a) flood fill </br> 
   b)boundary fill</br>
   Input for the pentagon has to be acquired using mouse click events, i.e. write and register a call back for mouse click. In the call back record position(x,y) for every click and draw a pentagon after five clicks. There after flood fill it.</br>
7. Write a program to render an animated swing. On mouse click event, it should start to swing and gradually reduce it speed to zero(use timer). Try to make it  as realistic as possible.</br>
8. (a)Work in 2D.  Write a function to draw a curve(L,B) using bezier algorithm. 4 control points will be (0,0), (B+B/2,L/4), (B+B/2,3*L/4), (0,L). This would look like half petal of a flower.</br>
(b)Use transformation to create a full petal.</br>
(c)Use transformation to create a flower with six petals.</br>
(d)Use transformation to create a set of 10 random sized, random located flowers.</br>
9. Write a program to extrude following 3D shapes from basic 2D shapes: A Cylinder of height (Y axis) 5H from a circle of radius R. Calculate 48 points. At h=0H, 1H, 2H, 3H, 4H and 5H   for angle=0,45,90,135,180,225,270 and 315. Don't use inbuilt function to render the cylinder. Draw curved lines to connect the points. Implement Curved line function of your own using bezier curves.</br>
10. Write a program to implement a 3D fractal tree. Color of tree can be changed by pressing first letter of common colors(Red,Blue,Green,Yellow..). Use mouse movement to rotate tree along Y axis(on XZ plane). </br>

## Instructions to run:
We need to run the files using gcc/g++ using some extra parameters while passing to the gcc compiler.
Run the following commands for the respective files

gcc Answer1.c -lGL -lGLU -lglut </br>
./a.out</br>
gcc Answer3a.c -lGL -lGLU -lglut -lm</br>
./a.out</br>
gcc Answer5.c -lGL -lGLU -lglut</br>
./a.out</br>
g++ Answer10.cpp -lGL -lGLU -lglut</br>
./a.out</br>

### About OpenGL:
The OpenGL Utility Toolkit is a library of utilities for OpenGL programs, which primarily perform system-level I/O with the host operating system. Functions performed include window definition, window control, and monitoring of keyboard and mouse input.

Routines for drawing a number of geometric primitives (both in solid and wireframe mode) are also provided, including cubes, spheres and the Utah teapot. GLUT also has some limited support for creating pop-up menus


[![ForTheBadge built-with-love](http://ForTheBadge.com/images/badges/built-with-love.svg)](https://GitHub.com/Naereen/)
