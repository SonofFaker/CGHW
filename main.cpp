//
//  main.cpp
//  OPENGL
//
//  Created by Lee, Hyejin (UMSL-Student) on 10/26/17.
//  Copyright © 2017 Lee, Hyejin (UMSL-Student). All rights reserved.
//  벽 넣기

#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

double x, y, z;           // current teapot position (initialized in main)

void wall(double thickness){
    //draw thin wall with top = xz-plane, corner at origin
    glPushMatrix();
    glTranslated(0.5, 0.5 * thickness, 0.5);
    glScaled(1.0, thickness, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();
}

void display () {
    
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);
    
    /* draw scene */
    glPushMatrix();
    glTranslatef(x,y,z);
    glutSolidTeapot(.5);
    glPopMatrix();
    
    /* flush drawing routines to the window */
    glFlush();
    
    /* display the offscreen buffer */
    glutSwapBuffers();
}

void animate () {
    
    /* update state variables */
    //x += .01;
    //y += .001;
    //z -= .001;
    glRotatef(1, 0, 1, 0);
    /* refresh screen */
    glutPostRedisplay();
}

void reshape ( int width, int height ) {
    
    /* define the viewport transformation */
    glViewport(0,0,width,height);
    
}


int main ( int argc, char * argv[] ) {
    
    /* initialize GLUT, using any commandline parameters passed to the
     program */
    glutInit(&argc,argv);
    
    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    /* create and set up a window */
    glutCreateWindow("flying teapot");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(animate);
    
    /* depth-buffering */
    glEnable(GL_DEPTH_TEST);
    
    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0,1.0,-1.0,1.0,.5,3.0);
    
    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.0,1.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
    
    /* initialize state variables (teapot position) */
    x = 0;
    y = 0;
    z = 0;
    
    /* tell GLUT to wait for events */
    glutMainLoop();
}
