#include <stdlib.h>
#include <GL/glut.h>
#include "imageloader.h"

float _angle = 0.0;
GLuint _textureBrick, _textureDoor, _textureGrass, _textureRoof, _textureWindow1, _textureSky,_texturequadbridge,_texturebridgehead;

GLuint _texturelowerbridge,_textureWindow2, _textureWindow3,_textureblackboundary,_texturelowerstreetboundary;
GLuint _texturecloud2;



static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);

    // Sky
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureSky);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,-.2,-10);

        glBegin(GL_QUADS);
            glTexCoord3f(0.0,1.0,0.1);  glVertex3f(-10,10,0);
            glTexCoord3f(1.0,1.0,0.1);  glVertex3f(10,10,0);
            glTexCoord3f(1.0,0.0,0.1);  glVertex3f(10,-1,0);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-10,-1,0);
        glEnd();





    glPopMatrix();

    // water
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureGrass);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,-1,-6);
        //glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);
            glTexCoord3f(0.0,10.0,1);  glVertex3f(-50,-1.5,50);
            glTexCoord3f(0.0,0.0,-1);  glVertex3f(-50,-1.5,-50);
            glTexCoord3f(10.0,0.0,-1);  glVertex3f(50,-1.5,-50);
            glTexCoord3f(10.0,10.0,1);  glVertex3f(50,-1.5,50);
        glEnd();




    glPopMatrix();

    // Front side
    glPushMatrix();

        glTranslatef(0,-1,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);



        /*wall front sculpture street*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front 1 left
            glTexCoord2f(0.0,0.0);glVertex3f(-2,1.2,1);
            glTexCoord2f(0.0,1.0);glVertex3f(2.7,1.2,1);
            glTexCoord2f(-2.0,1.0);glVertex3f(2.7,1.2,.5);
            glTexCoord2f(-2,0.0);glVertex3f(-2,1.2,.5);
        glEnd();
        /*wall front sculpture street*/






        glBindTexture(GL_TEXTURE_2D, _texturequadbridge);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front 1 left
            glTexCoord2f(0.0,0.0);glVertex3f(-2,1.2,1);
            glTexCoord2f(0.0,1.0);glVertex3f(-2,2,1);
            glTexCoord2f(-4.0,1.0);glVertex3f(0,2,1);
            glTexCoord2f(-4,0.0);glVertex3f(0,1.2,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _texturequadbridge);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front 2 left
            glTexCoord2f(0.0,0.0);glVertex3f(-2,1.2,.5);
            glTexCoord2f(0.0,1.0);glVertex3f(-2,2,.5);
            glTexCoord2f(-4.0,1.0);glVertex3f(2.7,2,.5);
            glTexCoord2f(-4,0.0);glVertex3f(2.7,1.2,.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _texturebridgehead);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // head
            glTexCoord2f(0.0,0.0);glVertex3f(0,1.2,1);
            glTexCoord2f(0.0,1.0);glVertex3f(0,2.4,1);
            glTexCoord2f(-1,1.0);glVertex3f(.7,2.4,1);
            glTexCoord2f(-1,0.0);glVertex3f(.7,1.2,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _texturequadbridge);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front 2 right
            glTexCoord2f(0.0,0.0);glVertex3f(.7,1.2,1);
            glTexCoord2f(0.0,1.0);glVertex3f(.7,2,1);
            glTexCoord2f(-4.0,1.0);glVertex3f(2.7,2,1);
            glTexCoord2f(-4,0.0);glVertex3f(2.7,1.2,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _texturelowerbridge);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(-8.2,-.7,.5);
            glTexCoord2f(0.0,1.0);glVertex3f(-8.2,-.5,.5);
            glTexCoord2f(-10.0,1.0);glVertex3f(8.2,-.5,.5);
            glTexCoord2f(-10,0.0);glVertex3f(8.2,-.7,.5);
        glEnd();

        /*lower street er nicher design front*/
        glBindTexture(GL_TEXTURE_2D, _texturelowerstreetboundary);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(-1.8,-1,.3);
            glTexCoord2f(0.0,1.0);glVertex3f(-1.8,-1.05,.3);
            glTexCoord2f(-10.0,1.0);glVertex3f(.4,-.75,.3);
            glTexCoord2f(-10,0.0);glVertex3f(.4,-.7,.3);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(.4,-.75,.3);
            glTexCoord2f(0.0,1.0);glVertex3f(.4,-.7,.3);
            glTexCoord2f(-10.0,1.0);glVertex3f(2.7,-1,.3);
            glTexCoord2f(-10,0.0);glVertex3f(2.7,-1.05,.3);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
             glTexCoord2f(0.0,0.0);glVertex3f(-1.7,-1,.3);
            glTexCoord2f(0.0,1.0);glVertex3f(-1.7,-1.05,.3);
            glTexCoord2f(-10.0,1.0);glVertex3f(-1.4,-.75,.3);
            glTexCoord2f(-10,0.0);glVertex3f(-1.4,-.7,.3);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
             glTexCoord2f(0.0,0.0);glVertex3f(-.97,-.9,.3);
            glTexCoord2f(0.0,1.0);glVertex3f(-.97,-.95,.3);
            glTexCoord2f(-10.0,1.0);glVertex3f(-1.4,-.75,.3);
            glTexCoord2f(-10,0.0);glVertex3f(-1.4,-.7,.3);
        glEnd();
         glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(-10.0,1.0);glVertex3f(-1,-.87,.3);
            glTexCoord2f(-10,0.0);glVertex3f(-1,-.93,.3);
            glTexCoord2f(0.0,0.0);glVertex3f(-.5,-.75,.3);
            glTexCoord2f(0.0,1.0);glVertex3f(-.5,-.7,.3);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(-.5,-.75,.3);
            glTexCoord2f(0.0,1.0);glVertex3f(-.5,-.7,.3);
            glTexCoord2f(-10.0,1.0);glVertex3f(-.1,-.78,.3);
            glTexCoord2f(-10,0.0);glVertex3f(-.1,-.81,.3);

        glEnd();





        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(1.4,-.75,.3);
            glTexCoord2f(0.0,1.0);glVertex3f(1.4,-.7,.3);
            glTexCoord2f(-10.0,1.0);glVertex3f(1,-.78,.3);
            glTexCoord2f(-10,0.0);glVertex3f(1,-.81,.3);
        glEnd();
         glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(1.4,-.75,.3);
            glTexCoord2f(0.0,1.0);glVertex3f(1.4,-.7,.3);
            glTexCoord2f(-10.0,1.0);glVertex3f(1.9,-.9,.3);
            glTexCoord2f(-10,0.0);glVertex3f(1.9,-.96,.3);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(2.2,-.75,.3);
            glTexCoord2f(0.0,1.0);glVertex3f(2.2,-.7,.3);
            glTexCoord2f(-10.0,1.0);glVertex3f(1.9,-.9,.3);
            glTexCoord2f(-10,0.0);glVertex3f(1.9,-.96,.3);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(2.2,-.75,.3);
            glTexCoord2f(0.0,1.0);glVertex3f(2.2,-.7,.3);
            glTexCoord2f(-10.0,1.0);glVertex3f(2.8,-1.55,.3);
            glTexCoord2f(-10,0.0);glVertex3f(2.8,-1.6,.3);
        glEnd();

         /*lower street er nicher design front*/







        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front lower street
            glTexCoord2f(0.0,0.0);glVertex3f(-8.2,-.7,.5);
            glTexCoord2f(0.0,1.0);glVertex3f(-8.2,-.7,-1);
            glTexCoord2f(-10.0,1.0);glVertex3f(8.2,-.7,-1);
            glTexCoord2f(-10,0.0);glVertex3f(8.2,-.7,.5);
        glEnd();



        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front left cube
            glTexCoord2f(0.0,0.0);glVertex3f(-1.7,-1.4,1.4);
            glTexCoord2f(0.0,2.0);glVertex3f(-1.7,-.5,1.4);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.6,-.5,1.4);
            glTexCoord2f(-2,0.0);glVertex3f(-3.6,-1.4,1.4);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front right cube
            glTexCoord2f(0.0,0.0);glVertex3f(2.4,-1.4,1.4);
            glTexCoord2f(0.0,2.0);glVertex3f(2.4,-.5,1.4);
            glTexCoord2f(-2.0,2.0);glVertex3f(4.3,-.5,1.4);
            glTexCoord2f(-2,0.0);glVertex3f(4.3,-1.4,1.4);
        glEnd();





        /*middle big dome left*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  // Wall front tower cube left
            glTexCoord2f(0.0,0.0);glVertex3f(-3,2,.5);
             glTexCoord2f(-2,0.0);glVertex3f(-2.2,2,.5);
             glTexCoord2f(-2.0,2.0);glVertex3f(-2.6,3.5,-.3);



        glEnd();

        glBegin(GL_TRIANGLES);  // Wall front tower cube left
            glTexCoord2f(-2,0.0);glVertex3f(-2.2,2,.5);
            glTexCoord2f(0.0,0.0);glVertex3f(-2.2,2,-1);
             glTexCoord2f(-2.0,2.0);glVertex3f(-2.6,3.5,-.3);



        glEnd();


        glBegin(GL_TRIANGLES);  // Wall front tower cube left
           glTexCoord2f(0.0,0.0);glVertex3f(-3,2,.5);
             glTexCoord2f(-2,0.0);glVertex3f(-3,2,-1);
             glTexCoord2f(-2.0,2.0);glVertex3f(-2.6,3.5,-.3);



        glEnd();


         glBegin(GL_TRIANGLES);  // Wall front tower cube left
           glTexCoord2f(-2,0.0);glVertex3f(-3,2,-1);
           glTexCoord2f(0.0,0.0);glVertex3f(-2,2,-1);
            glTexCoord2f(-2.0,2.0);glVertex3f(-2.6,3.5,-.3);



        glEnd();

        /*middle big dome left*/




        /*middle big dome right*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  // Wall front tower cube left
            glTexCoord2f(0.0,0.0);glVertex3f(3.7,2,.5);
             glTexCoord2f(-2,0.0);glVertex3f(2.9,2,.5);
             glTexCoord2f(-2.0,2.0);glVertex3f(3.2,3.5,-.3);



        glEnd();

        glBegin(GL_TRIANGLES);  // Wall front tower cube left
            glTexCoord2f(0.0,0.0);glVertex3f(3.7,2,.5);
             glTexCoord2f(-2,0.0);glVertex3f(3.7,2,-1);
             glTexCoord2f(-2.0,2.0);glVertex3f(3.2,3.5,-.3);



        glEnd();


        glBegin(GL_TRIANGLES);  // Wall front tower cube left
           glTexCoord2f(0.0,0.0);glVertex3f(2.9,2,.5);
             glTexCoord2f(-2,0.0);glVertex3f(2.9,2,-1);
             glTexCoord2f(-2.0,2.0);glVertex3f(3.2,3.5,-.3);



        glEnd();


         glBegin(GL_TRIANGLES);  // Wall front tower cube left
           glTexCoord2f(-2,0.0);glVertex3f(2.9,2,-1);
           glTexCoord2f(0.0,0.0);glVertex3f(3.7,2,-1);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.2,3.5,-.3);



        glEnd();

        /*middle big dome right*/



        /*Wall front tower cube left boundary for window*/

        glBindTexture(GL_TEXTURE_2D, _textureblackboundary);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord2f(0.0,0.0);glVertex3f(-2,0.32,1.01);
            glTexCoord2f(0.0,2.0);glVertex3f(-2,.34,1.01);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.2,.34,1.01);
            glTexCoord2f(-2,0.0);glVertex3f(-3.2,.32,1.01);
        glEnd();
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord2f(0.0,0.0);glVertex3f(-2,0.48,1.01);
            glTexCoord2f(0.0,2.0);glVertex3f(-2,.5,1.01);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.2,.5,1.01);
            glTexCoord2f(-2,0.0);glVertex3f(-3.2,.48,1.01);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureblackboundary);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord2f(0.0,0.0);glVertex3f(-2,1.16,1.01);
            glTexCoord2f(0.0,2.0);glVertex3f(-2,1.18,1.01);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.2,1.18,1.01);
            glTexCoord2f(-2,0.0);glVertex3f(-3.2,1.16,1.01);
        glEnd();
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord2f(0.0,0.0);glVertex3f(-2,1.32,1.01);
            glTexCoord2f(0.0,2.0);glVertex3f(-2,1.34,1.01);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.2,1.34,1.01);
            glTexCoord2f(-2,0.0);glVertex3f(-3.2,1.32,1.01);
        glEnd();



        glBindTexture(GL_TEXTURE_2D, _textureblackboundary);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord2f(0.0,0.0);glVertex3f(-2,1.95,1.01);
            glTexCoord2f(0.0,2.0);glVertex3f(-2,1.97,1.01);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.2,1.97,1.01);
            glTexCoord2f(-2,0.0);glVertex3f(-3.2,1.95,1.01);
        glEnd();

        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord2f(0.0,0.0);glVertex3f(-2,2.13,1.01);
            glTexCoord2f(0.0,2.0);glVertex3f(-2,2.15,1.01);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.2,2.15,1.01);
            glTexCoord2f(-2,0.0);glVertex3f(-3.2,2.13,1.01);
        glEnd();

        /*Wall front tower cube left boundary for window*/

        /*window all for left*/
        glBindTexture(GL_TEXTURE_2D, _textureWindow1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(-2.35,1.4,1.01);
            glTexCoord3f(0.0,1,0);glVertex3f(-2.35,1.9,1.01);
            glTexCoord3f(1,1,-2);glVertex3f(-3,1.9,1.01);
            glTexCoord3f(1,0.0,-2);glVertex3f(-3,1.4,1.01);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureWindow3);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(-2.35,.6,1.01);
            glTexCoord3f(0.0,1,0);glVertex3f(-2.35,1.1,1.01);
            glTexCoord3f(1,1,-2);glVertex3f(-3,1.1,1.01);
            glTexCoord3f(1,0.0,-2);glVertex3f(-3,.6,1.01);
        glEnd();

        /*janalar side er wall*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(-2,.1,1.02);
            glTexCoord3f(0.0,.5,0);glVertex3f(-2,.3,1.02);
            glTexCoord3f(.5,.5,-2);glVertex3f(-2.68,.3,1.02);
            glTexCoord3f(.5,0.0,-2);glVertex3f(-2.64,.1,1.02);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(-2.72,.1,1.02);
            glTexCoord3f(0.0,.5,0);glVertex3f(-2.68,.3,1.02);
            glTexCoord3f(.5,.5,-2);glVertex3f(-3,.3,1.02);
            glTexCoord3f(.5,0.0,-2);glVertex3f(-3,.1,1.02);
        glEnd();
        /*janalar side er wall*/
        glBindTexture(GL_TEXTURE_2D, _textureWindow2);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(-2.35,-.2,1.01);
            glTexCoord3f(0.0,1,0);glVertex3f(-2.35,.3,1.01);
            glTexCoord3f(.98,1,-2);glVertex3f(-3,.3,1.01);
            glTexCoord3f(.98,0.0,-2);glVertex3f(-3,-.2,1.01);
        glEnd();

        /*window all for left*/







        /*Wall front tower cube right boundary for window*/

        glBindTexture(GL_TEXTURE_2D, _textureblackboundary);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord2f(0.0,0.0);glVertex3f(3.6,0.32,1.01);
            glTexCoord2f(0.0,2.0);glVertex3f(3.6,.34,1.01);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.05,.34,1.01);
            glTexCoord2f(-2,0.0);glVertex3f(3.05,.32,1.01);
        glEnd();
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord2f(0.0,0.0);glVertex3f(3.6,0.48,1.01);
            glTexCoord2f(0.0,2.0);glVertex3f(3.6,.5,1.01);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.05,.5,1.01);
            glTexCoord2f(-2,0.0);glVertex3f(3.05,.48,1.01);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureblackboundary);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord2f(0.0,0.0);glVertex3f(3.6,1.16,1.01);
            glTexCoord2f(0.0,2.0);glVertex3f(3.6,1.18,1.01);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.05,1.18,1.01);
            glTexCoord2f(-2,0.0);glVertex3f(3.05,1.16,1.01);
        glEnd();
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord2f(0.0,0.0);glVertex3f(3.6,1.32,1.01);
            glTexCoord2f(0.0,2.0);glVertex3f(3.6,1.34,1.01);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.05,1.34,1.01);
            glTexCoord2f(-2,0.0);glVertex3f(3.05,1.32,1.01);
        glEnd();



        glBindTexture(GL_TEXTURE_2D, _textureblackboundary);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord2f(0.0,0.0);glVertex3f(3.6,1.95,1.01);
            glTexCoord2f(0.0,2.0);glVertex3f(3.6,1.97,1.01);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.05,1.97,1.01);
            glTexCoord2f(-2,0.0);glVertex3f(3.05,1.95,1.01);
        glEnd();

        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord2f(0.0,0.0);glVertex3f(3.6,2.13,1.01);
            glTexCoord2f(0.0,2.0);glVertex3f(3.6,2.15,1.01);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.05,2.15,1.01);
            glTexCoord2f(-2,0.0);glVertex3f(3.05,2.13,1.01);
        glEnd();

        /*Wall front tower cube right boundary for window*/






        /*window all for right*/
        glBindTexture(GL_TEXTURE_2D, _textureWindow1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(3.05,1.4,1.01);
            glTexCoord3f(0.0,1,0);glVertex3f(3.05,1.9,1.01);
            glTexCoord3f(1,1,-2);glVertex3f(3.6,1.9,1.01);
            glTexCoord3f(1,0.0,-2);glVertex3f(3.6,1.4,1.01);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureWindow3);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
         glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(3.05,.6,1.01);
            glTexCoord3f(0.0,1,0);glVertex3f(3.05,1.1,1.01);
            glTexCoord3f(1,1,-2);glVertex3f(3.6,1.1,1.01);
            glTexCoord3f(1,0.0,-2);glVertex3f(3.6,.6,1.01);
        glEnd();

        /*janalar side er wall*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
         glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(3.05,.1,1.02);
            glTexCoord3f(0.0,1,0);glVertex3f(3.05,.3,1.02);
            glTexCoord3f(2.7,1,-2);glVertex3f(3.3,.3,1.02);
            glTexCoord3f(2.7,0.0,-2);glVertex3f(3.26,.1,1.02);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
         glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(3.35,.1,1.02);
            glTexCoord3f(0.0,1,0);glVertex3f(3.31,.3,1.02);
            glTexCoord3f(2.7,1,-2);glVertex3f(3.6,.3,1.02);
            glTexCoord3f(2.7,0.0,-2);glVertex3f(3.6,.1,1.02);
        glEnd();

        /*janalar side er wall*/
        glBindTexture(GL_TEXTURE_2D, _textureWindow2);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
         glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(3.05,-.2,1.01);
            glTexCoord3f(0.0,1,0);glVertex3f(3.05,.3,1.01);
            glTexCoord3f(1,1,-2);glVertex3f(3.6,.3,1.01);
            glTexCoord3f(1,0.0,-2);glVertex3f(3.6,-.2,1.01);
        glEnd();

        /*window all for right*/













        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left
            glTexCoord2f(0.0,0.0);glVertex3f(-2,-.5,1);
            glTexCoord2f(0.0,2.0);glVertex3f(-2,1.2,1);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.2,1.2,1);
            glTexCoord2f(-2,0.0);glVertex3f(-3.2,-.5,1);
        glEnd();









         glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube right
            glTexCoord2f(0.0,0.0);glVertex3f(2.7,-.5,1);
            glTexCoord2f(0.0,2.0);glVertex3f(2.7,1.2,1);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.9,1.2,1);
            glTexCoord2f(-2,0.0);glVertex3f(3.9,-.5,1);
        glEnd();


        /*cylinder front left-right*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  //cylinder front left-right middle
            /*glTexCoord2f(0.0,0.0);glVertex3f(-2.05,1.2,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(-2.05,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(-2.2,2.3,1.1);
            glTexCoord2f(-2,0.0);glVertex3f(-2.2,1.2,1.1);
            */
            glTexCoord2f(0.0,0.0);glVertex3f(-2.05,-.5,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(-2.05,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(-2.2,2.3,1.1);
            glTexCoord2f(-2,0.0);glVertex3f(-2.2,-.5,1.1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front left-right right
            glTexCoord2f(0.0,0.0);glVertex3f(-2.05,-.5,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(-2.05,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(-2,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(-2,-.5,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front left-right left
            glTexCoord2f(0.0,0.0);glVertex3f(-2.2,-.5,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(-2.2,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(-2.35,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(-2.35,-.5,1);
        glEnd();

        /*cylinder front left-right*/



        /*cylinder front left-right cone*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front middle
            glTexCoord2f(0.0,2.0);glVertex3f(-2.2,2.3,1.1);
            glTexCoord2f(0.0,0.0);glVertex3f(-2.05,2.3,1.1);
            glTexCoord2f(-1.0,2.0);glVertex3f(-2.13,2.9,1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front left
            glTexCoord2f(0.0,2.0);glVertex3f(-2.2,2.3,1.1);
            glTexCoord2f(0.0,0.0);glVertex3f(-2.35,2.3,1);
            glTexCoord2f(-1.0,2.0);glVertex3f(-2.11,2.9,1.05);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right
            glTexCoord2f(0.0,2.0);glVertex3f(-2.05,2.3,1.1);
            glTexCoord2f(0.0,0.0);glVertex3f(-2,2.3,1);
            glTexCoord2f(-1.0,2.0);glVertex3f(-2.11,2.9,1.05);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right 2
            glTexCoord2f(0.0,2.0);glVertex3f(-2.05,2.3,1);
            glTexCoord2f(0.0,0.0);glVertex3f(-2.1,2.3,.9);
            glTexCoord2f(-1.0,2.0);glVertex3f(-2.1105,2.9,1.05);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right 2
            glTexCoord2f(0.0,2.0);glVertex3f(-2.35,2.3,1);
            glTexCoord2f(0.0,0.0);glVertex3f(-2.1,2.3,.9);
            glTexCoord2f(-1.0,2.0);glVertex3f(-2.1105,2.9,1.05);
        glEnd();

         /*cylinder front left-right cone*/




/*cylinder front right-left*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  //cylinder front left-right middle
            glTexCoord2f(0.0,0.0);glVertex3f(2.85,-.5,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(2.85,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(2.9,2.3,1.1);
            glTexCoord2f(-2,0.0);glVertex3f(2.9,-.5,1.1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front left-right right
            glTexCoord2f(0.0,0.0);glVertex3f(2.85,-.5,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(2.85,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(2.7,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(2.7,-.5,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front left-right left
            glTexCoord2f(0.0,0.0);glVertex3f(2.9,-.5,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(2.9,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.05,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(3.05,-.5,1);
        glEnd();

        /*cylinder front right-left*/







        /*cylinder front right-left cone*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front middle
            glTexCoord2f(0.0,2.0);glVertex3f(2.85,2.3,1.1);
            glTexCoord2f(0.0,0.0);glVertex3f(2.9,2.3,1.1);
            glTexCoord2f(-1.0,2.0);glVertex3f(2.87,2.9,1.05);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front left
            glTexCoord2f(0.0,2.0);glVertex3f(2.85,2.3,1.1);
            glTexCoord2f(0.0,0.0);glVertex3f(2.7,2.3,1);
            glTexCoord2f(-1.0,2.0);glVertex3f(2.87,2.9,1.05);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right
            glTexCoord2f(0.0,2.0);glVertex3f(2.9,2.3,1.1);
            glTexCoord2f(0.0,0.0);glVertex3f(3.05,2.3,1);
            glTexCoord2f(-1.0,2.0);glVertex3f(2.87,2.9,1.05);
        glEnd();
         /*cylinder front right-left cone*/



        //front boundary after cylinder left
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front left-left left
            glTexCoord2f(0.0,0.0);glVertex3f(-2.35,1.2,1);
            glTexCoord2f(0.0,2.0);glVertex3f(-2.35,2.3,1);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.05,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(-3.05,1.2,1);

        glEnd();



         //front boundary after cylinder right
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front left-left left
            glTexCoord2f(0.0,0.0);glVertex3f(3.05,1.2,1);
            glTexCoord2f(0.0,2.0);glVertex3f(3.05,2.3,1);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.6,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(3.6,1.2,1);

        glEnd();





         /*cylinder front left-left*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  //cylinder front left-left middle
            glTexCoord2f(0.0,0.0);glVertex3f(-3.05,-.5,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(-3.05,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.20,2.3,1.1);
            glTexCoord2f(-2,0.0);glVertex3f(-3.20,-.5,1.1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front left-left right
            glTexCoord2f(0.0,0.0);glVertex3f(-3.05,-.5,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(-3.05,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(-3,-.5,1);

        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front left-left left
            glTexCoord2f(0.0,0.0);glVertex3f(-3.2,-.5,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(-3.2,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.35,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(-3.35,-.5,1);

        glEnd();

        //tower wall middle
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front left-left left
            glTexCoord2f(0.0,0.0);glVertex3f(-3.35,-.5,.8);
            glTexCoord2f(0.0,2.0);glVertex3f(-3.35,2.3,.8);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.35,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(-3.35,-.5,1);

        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front left-left left
            glTexCoord2f(0.0,0.0);glVertex3f(-3.35,-.5,.8);
            glTexCoord2f(0.0,2.0);glVertex3f(-3.35,2.3,.8);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.20,2.3,.7);
            glTexCoord2f(-2,0.0);glVertex3f(-3.20,-.5,.7);

        glEnd();
        //side cylinder shesh
        /*cylinder front left-left*/




        /*cylinder front left-left cone*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front middle
            glTexCoord2f(0.0,2.0);glVertex3f(-3,2.3,1);
            glTexCoord2f(0.0,0.0);glVertex3f(-3.05,2.3,1.1);
            glTexCoord2f(-1.0,2.0);glVertex3f(-3.1,2.9,1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front left
            glTexCoord2f(0.0,2.0);glVertex3f(-3.05,2.3,1.1);
            glTexCoord2f(0.0,0.0);glVertex3f(-3.2,2.3,1.1);
            glTexCoord2f(-1.0,2.0);glVertex3f(-3.1,2.9,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right
            glTexCoord2f(0.0,2.0);glVertex3f(-3.2,2.3,1.1);
            glTexCoord2f(0.0,0.0);glVertex3f(-3.35,2.3,1);
            glTexCoord2f(-1.0,2.0);glVertex3f(-3.1,2.9,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right 2
            glTexCoord2f(0.0,2.0);glVertex3f(-3.35,2.3,1);
            glTexCoord2f(0.0,0.0);glVertex3f(-3.35,2.3,.8);
            glTexCoord2f(-1.0,2.0);glVertex3f(-3.1,2.9,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right 2
            glTexCoord2f(0.0,2.0);glVertex3f(-3.35,2.3,.8);
            glTexCoord2f(0.0,0.0);glVertex3f(-3.2,2.3,.7);
            glTexCoord2f(-1.0,2.0);glVertex3f(-3.1,2.9,1);
        glEnd();

         /*cylinder front left-left cone*/



        /*cylinder front right-right*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  //cylinder front right-right middle
            glTexCoord2f(0.0,0.0);glVertex3f(3.75,-.5,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(3.75,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.9,2.3,1.1);
            glTexCoord2f(-2,0.0);glVertex3f(3.9,-.5,1.1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front right-right left
            glTexCoord2f(0.0,0.0);glVertex3f(3.75,-.5,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(3.75,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.6,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(3.6,-.5,1);

        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front right-right right
            glTexCoord2f(0.0,0.0);glVertex3f(3.9,-.5,1.1);
            glTexCoord2f(0.0,2.0);glVertex3f(3.9,2.3,1.1);
            glTexCoord2f(-2.0,2.0);glVertex3f(4.05,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(4.05,-.5,1);

        glEnd();

        //tower wall middle
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front right-right left
            glTexCoord2f(0.0,0.0);glVertex3f(4.05,-.5,.8);
            glTexCoord2f(0.0,2.0);glVertex3f(4.05,2.3,.8);
            glTexCoord2f(-2.0,2.0);glVertex3f(4.05,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(4.05,-.5,1);

        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front right-right left
            glTexCoord2f(0.0,0.0);glVertex3f(4.05,-.5,.8);
            glTexCoord2f(0.0,2.0);glVertex3f(4.05,2.3,.8);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.9,2.3,.7);
            glTexCoord2f(-2,0.0);glVertex3f(3.9,-.5,.7);

        glEnd();
        //side cylinder shesh
        /*cylinder front right-right*/



        /*cylinder front right-right cone*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front middle
            glTexCoord2f(0.0,2.0);glVertex3f(3.75,2.3,1.1);
            glTexCoord2f(0.0,0.0);glVertex3f(3.9,2.3,1.1);
            glTexCoord2f(-1.0,2.0);glVertex3f(3.83,2.9,1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front left
            glTexCoord2f(0.0,2.0);glVertex3f(3.75,2.3,1.1);
            glTexCoord2f(0.0,0.0);glVertex3f(3.6,2.3,1);
            glTexCoord2f(-1.0,2.0);glVertex3f(3.83,2.9,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right
            glTexCoord2f(0.0,2.0);glVertex3f(3.9,2.3,1.1);
            glTexCoord2f(0.0,0.0);glVertex3f(4.05,2.3,1);
            glTexCoord2f(-1.0,2.0);glVertex3f(3.83,2.9,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right 2
            glTexCoord2f(0.0,2.0);glVertex3f(4.05,2.3,1);
            glTexCoord2f(0.0,0.0);glVertex3f(4.05,2.3,.8);
            glTexCoord2f(-1.0,2.0);glVertex3f(3.83,2.9,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right 2
            glTexCoord2f(0.0,2.0);glVertex3f(4.05,2.3,.8);
            glTexCoord2f(0.0,0.0);glVertex3f(3.9,2.3,.7);
            glTexCoord2f(-1.0,2.0);glVertex3f(3.83,2.9,1);
        glEnd();

         /*cylinder front right-right cone*/






    glPopMatrix();
















    // Back side
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, _texturequadbridge);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,-1,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);







        glBegin(GL_QUADS);  // Wall back 1
           glTexCoord2f(0.0,0.0);glVertex3f(-2,1.2,-1);
            glTexCoord2f(0.0,1);glVertex3f(-2,2,-1);
            glTexCoord2f(-6,1);glVertex3f(2.7,2,-1);
            glTexCoord2f(-6,0.0);glVertex3f(2.7,1.2,-1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _texturequadbridge);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall back 2
           glTexCoord2f(0.0,0.0);glVertex3f(-2,1.2,-1.5);
            glTexCoord2f(0.0,1);glVertex3f(-2,2,-1.5);
            glTexCoord2f(-6,1);glVertex3f(2.7,2,-1.5);
            glTexCoord2f(-6,0.0);glVertex3f(2.7,1.2,-1.5);
        glEnd();


         /*wall back sculpture street*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front 1 left
            glTexCoord2f(0.0,0.0);glVertex3f(-2,1.2,-1.5);
            glTexCoord2f(0.0,1.0);glVertex3f(2.7,1.2,-1.5);
            glTexCoord2f(-2.0,1.0);glVertex3f(2.7,1.2,-1);
            glTexCoord2f(-2,0.0);glVertex3f(-2,1.2,-1);
        glEnd();
        /*wall back sculpture street*/



        glBindTexture(GL_TEXTURE_2D, _texturelowerbridge);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall back 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(-8.2,-.7,-1);
            glTexCoord2f(0.0,1.0);glVertex3f(-8.2,-.5,-1);
            glTexCoord2f(-10.0,1.0);glVertex3f(8.2,-.5,-1);
            glTexCoord2f(-10,0.0);glVertex3f(8.2,-.7,-1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall back left cube
           glTexCoord2f(0.0,0.0);glVertex3f(-1.7,-1.4,-1.5);
            glTexCoord2f(0.0,2.0);glVertex3f(-1.7,-.5,-1.5);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.6,-.5,-1.5);
            glTexCoord2f(-2,0.0);glVertex3f(-3.6,-1.4,-1.5);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall back left cube
           glTexCoord2f(0.0,0.0);glVertex3f(2.4,-1.4,-1.5);
            glTexCoord2f(0.0,2.0);glVertex3f(2.4,-.5,-1.5);
            glTexCoord2f(-2.0,2.0);glVertex3f(4.3,-.5,-1.5);
            glTexCoord2f(-2,0.0);glVertex3f(4.3,-1.4,-1.5);
        glEnd();



        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall back tower cube left
           glTexCoord2f(0.0,0.0);glVertex3f(-2,-.5,-1.5);
            glTexCoord2f(0.0,2.0);glVertex3f(-2,1.2,-1.5);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.2,1.2,-1.5);
            glTexCoord2f(-2,0.0);glVertex3f(-3.2,-.5,-1.5);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall back tower cube right
           glTexCoord2f(0.0,0.0);glVertex3f(2.7,-.5,-1.5);
            glTexCoord2f(0.0,2.0);glVertex3f(2.7,1.2,-1.5);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.9,1.2,-1.5);
            glTexCoord2f(-2,0.0);glVertex3f(3.9,-.5,-1.5);
        glEnd();





         /*cylinder back left-left*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  //cylinder back left-left 1
            glTexCoord2f(0.0,0.0);glVertex3f(-3.20,-.5,-1.2);
            glTexCoord2f(0.0,2.0);glVertex3f(-3.20,2.3,-1.2);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.35,2.3,-1.3);
            glTexCoord2f(-2,0.0);glVertex3f(-3.35,-.5,-1.3);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder back left-left 2
            glTexCoord2f(0.0,0.0);glVertex3f(-3.35,-.5,-1.3);
            glTexCoord2f(0.0,2.0);glVertex3f(-3.35,2.3,-1.3);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.35,2.3,-1.5);
            glTexCoord2f(-2,0.0);glVertex3f(-3.35,-.5,-1.5);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder back left-left 3
            glTexCoord2f(0.0,0.0);glVertex3f(-3.35,-.5,-1.5);
            glTexCoord2f(0.0,2.0);glVertex3f(-3.35,2.3,-1.5);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.20,2.3,-1.6);
            glTexCoord2f(-2,0.0);glVertex3f(-3.20,-.5,-1.6);

        glEnd();

        //tower wall middle
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder back left-left 4
            glTexCoord2f(0.0,0.0);glVertex3f(-3.20,-.5,-1.6);
            glTexCoord2f(0.0,2.0);glVertex3f(-3.20,2.3,-1.6);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.05,2.3,-1.6);
            glTexCoord2f(-2,0.0);glVertex3f(-3.05,-.5,-1.6);

        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder back left-left 5
            glTexCoord2f(0.0,0.0);glVertex3f(-3.05,-.5,-1.6);
            glTexCoord2f(0.0,2.0);glVertex3f(-3.05,2.3,-1.6);
            glTexCoord2f(-2.0,2.0);glVertex3f(-2.9,2.3,-1.5);
            glTexCoord2f(-2,0.0);glVertex3f(-2.9,-.5,-1.5);

        glEnd();
        //side cylinder shesh
        /*cylinder back left-left*/

        /*cylinder back left-left cone*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front middle
            glTexCoord2f(0.0,2.0);glVertex3f(-3.2,2.3,-1.2);
            glTexCoord2f(0.0,0.0);glVertex3f(-3.35,2.3,-1.3);
            glTexCoord2f(-1.0,2.0);glVertex3f(-3.1,2.9,-1.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front left
            glTexCoord2f(0.0,2.0);glVertex3f(-3.35,2.3,-1.3);
            glTexCoord2f(0.0,0.0);glVertex3f(-3.35,2.3,-1.5);
            glTexCoord2f(-1.0,2.0);glVertex3f(-3.1,2.9,-1.5);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right
            glTexCoord2f(0.0,2.0);glVertex3f(-3.35,2.3,-1.5);
            glTexCoord2f(0.0,0.0);glVertex3f(-3.20,2.3,-1.6);
            glTexCoord2f(-1.0,2.0);glVertex3f(-3.1,2.9,-1.5);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right 2
            glTexCoord2f(0.0,2.0);glVertex3f(-3.20,2.3,-1.6);
            glTexCoord2f(0.0,0.0);glVertex3f(-3.05,2.3,-1.6);
            glTexCoord2f(-1.0,2.0);glVertex3f(-3.1,2.9,-1.5);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right 2
            glTexCoord2f(0.0,2.0);glVertex3f(-3.05,2.3,-1.6);
            glTexCoord2f(0.0,0.0);glVertex3f(-2.9,2.3,-1.5);
            glTexCoord2f(-1.0,2.0);glVertex3f(-3.1,2.9,-1.5);
        glEnd();

         /*cylinder back left-left cone*/






          /*cylinder back right-right*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  //cylinder back left-left 1
            glTexCoord2f(0.0,0.0);glVertex3f(3.9,-.5,-1.6);
            glTexCoord2f(0.0,2.0);glVertex3f(3.9,2.3,-1.6);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.75,2.3,-1.6);
            glTexCoord2f(-2,0.0);glVertex3f(3.75,-.5,-1.6);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder back left-left 2
            glTexCoord2f(0.0,0.0);glVertex3f(3.75,-.5,-1.6);
            glTexCoord2f(0.0,2.0);glVertex3f(3.75,2.3,-1.6);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.6,2.3,-1.5);
            glTexCoord2f(-2,0.0);glVertex3f(3.6,-.5,-1.5);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder back left-left 3
            glTexCoord2f(0.0,0.0);glVertex3f(3.9,-.5,-1.6);
            glTexCoord2f(0.0,2.0);glVertex3f(3.9,2.3,-1.6);
            glTexCoord2f(-2.0,2.0);glVertex3f(4.05,2.3,-1.5);
            glTexCoord2f(-2,0.0);glVertex3f(4.05,-.5,-1.5);

        glEnd();

        //tower wall middle
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder back left-left 4
            glTexCoord2f(0.0,0.0);glVertex3f(4.05,-.5,-1.5);
            glTexCoord2f(0.0,2.0);glVertex3f(4.05,2.3,-1.5);
            glTexCoord2f(-2.0,2.0);glVertex3f(4.05,2.3,-1.4);
            glTexCoord2f(-2,0.0);glVertex3f(4.05,-.5,-1.4);

        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder back left-left 5
            glTexCoord2f(0.0,0.0);glVertex3f(4.05,-.5,-1.4);
            glTexCoord2f(0.0,2.0);glVertex3f(4.05,2.3,-1.4);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.9,2.3,-1.3);
            glTexCoord2f(-2,0.0);glVertex3f(3.9,-.5,-1.3);

        glEnd();
        //side cylinder shesh
        /*cylinder back right-right*/




/*cylinder back right-right cone*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front middle
            glTexCoord2f(0.0,2.0);glVertex3f(3.9,2.3,-1.6);
            glTexCoord2f(0.0,0.0);glVertex3f(3.75,2.3,-1.6);
            glTexCoord2f(-1.0,2.0);glVertex3f(3.83,2.9,-1.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front left
            glTexCoord2f(0.0,2.0);glVertex3f(3.75,2.3,-1.6);
            glTexCoord2f(0.0,0.0);glVertex3f(3.6,2.3,-1.5);
            glTexCoord2f(-1.0,2.0);glVertex3f(3.83,2.9,-1.5);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right
            glTexCoord2f(0.0,2.0);glVertex3f(3.9,2.3,-1.6);
            glTexCoord2f(0.0,0.0);glVertex3f(4.05,2.3,-1.5);
            glTexCoord2f(-1.0,2.0);glVertex3f(3.83,2.9,-1.5);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right 2
            glTexCoord2f(0.0,2.0);glVertex3f(4.05,2.3,-1.5);
            glTexCoord2f(0.0,0.0);glVertex3f(4.05,2.3,-1.4);
            glTexCoord2f(-1.0,2.0);glVertex3f(3.83,2.9,-1.5);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right 2
            glTexCoord2f(0.0,2.0);glVertex3f(4.05,2.3,-1.4);
            glTexCoord2f(0.0,0.0);glVertex3f(3.9,2.3,-1.3);
            glTexCoord2f(-1.0,2.0);glVertex3f(3.83,2.9,-1.5);
        glEnd();

         /*cylinder back right-right cone*/



        //back boundary after cylinder left
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);
            glTexCoord2f(0.0,0.0);glVertex3f(-2.9,-.5,-1.5);
            glTexCoord2f(0.0,2.0);glVertex3f(-2.9,2.3,-1.5);
            glTexCoord2f(-2.0,2.0);glVertex3f(-2.3,2.3,-1.5);
            glTexCoord2f(-2,0.0);glVertex3f(-2.3,-.5,-1.5);

        glEnd();


        //back boundary after cylinder right
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);
            glTexCoord2f(0.0,0.0);glVertex3f(3.05,-.5,-1.5);
            glTexCoord2f(0.0,2.0);glVertex3f(3.05,2.3,-1.5);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.6,2.3,-1.5);
            glTexCoord2f(-2,0.0);glVertex3f(3.6,-.5,-1.5);

        glEnd();


 /*cylinder back left-right*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  //cylinder back left-right-left
            glTexCoord2f(0.0,0.0);glVertex3f(-2.3,-.5,-1.5);
            glTexCoord2f(0.0,2.0);glVertex3f(-2.3,2.3,-1.5);
            glTexCoord2f(-2.0,2.0);glVertex3f(-2.2,2.3,-1.6);
            glTexCoord2f(-2,0.0);glVertex3f(-2.2,-.5,-1.6);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder back left-right-middle
            glTexCoord2f(0.0,0.0);glVertex3f(-2.2,-.5,-1.6);
            glTexCoord2f(0.0,2.0);glVertex3f(-2.2,2.3,-1.6);
            glTexCoord2f(-2.0,2.0);glVertex3f(-2.05,2.3,-1.6);
            glTexCoord2f(-2,0.0);glVertex3f(-2.05,-.5,-1.6);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder back left-right-right
            glTexCoord2f(0.0,0.0);glVertex3f(-2.05,-.5,-1.6);
            glTexCoord2f(0.0,2.0);glVertex3f(-2.05,2.3,-1.6);
            glTexCoord2f(-2.0,2.0);glVertex3f(-1.95,2.3,-1.5);
            glTexCoord2f(-2,0.0);glVertex3f(-1.95,-.5,-1.5);
        glEnd();

        /*cylinder back left-right*/

         /*cylinder back left-right cone*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front middle
            glTexCoord2f(0.0,2.0);glVertex3f(-2.3,2.3,-1.5);
            glTexCoord2f(0.0,0.0);glVertex3f(-2.2,2.3,-1.6);
            glTexCoord2f(-1.0,2.0);glVertex3f(-2.13,2.9,-1.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front left
            glTexCoord2f(0.0,2.0);glVertex3f(-2.2,2.3,-1.6);
            glTexCoord2f(0.0,0.0);glVertex3f(-2.05,2.3,-1.6);
            glTexCoord2f(-1.0,2.0);glVertex3f(-2.13,2.9,-1.5);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right
            glTexCoord2f(0.0,2.0);glVertex3f(-2.05,2.3,-1.6);
            glTexCoord2f(0.0,0.0);glVertex3f(-1.95,2.3,-1.5);
            glTexCoord2f(-1.0,2.0);glVertex3f(-2.13,2.9,-1.5);
        glEnd();



         /*cylinder back left-right cone*/




        /*cylinder back right-left*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  //cylinder back left-right-left
            glTexCoord2f(0.0,0.0);glVertex3f(2.8,-.5,-1.6);
            glTexCoord2f(0.0,2.0);glVertex3f(2.8,2.3,-1.6);
            glTexCoord2f(-2.0,2.0);glVertex3f(2.9,2.3,-1.6);
            glTexCoord2f(-2,0.0);glVertex3f(2.9,-.5,-1.6);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder back left-right-middle
            glTexCoord2f(0.0,0.0);glVertex3f(2.7,-.5,-1.5);
            glTexCoord2f(0.0,2.0);glVertex3f(2.7,2.3,-1.5);
            glTexCoord2f(-2.0,2.0);glVertex3f(2.8,2.3,-1.6);
            glTexCoord2f(-2,0.0);glVertex3f(2.8,-.5,-1.6);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder back left-right-right
            glTexCoord2f(0.0,0.0);glVertex3f(2.9,-.5,-1.6);
            glTexCoord2f(0.0,2.0);glVertex3f(2.9,2.3,-1.6);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.05,2.3,-1.5);
            glTexCoord2f(-2,0.0);glVertex3f(3.05,-.5,-1.5);
        glEnd();

        /*cylinder back right-left*/


          /*cylinder back right-left cone*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front middle
            glTexCoord2f(0.0,2.0);glVertex3f(2.8,2.3,-1.6);
            glTexCoord2f(0.0,0.0);glVertex3f(2.9,2.3,-1.6);
            glTexCoord2f(-1.0,2.0);glVertex3f(2.85,2.9,-1.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  //cone front left
            glTexCoord2f(0.0,2.0);glVertex3f(2.8,2.3,-1.6);
            glTexCoord2f(0.0,0.0);glVertex3f(2.7,2.3,-1.5);
            glTexCoord2f(-1.0,2.0);glVertex3f(2.85,2.9,-1.5);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_TRIANGLES);  ////cone front right
            glTexCoord2f(0.0,2.0);glVertex3f(2.9,2.3,-1.6);
            glTexCoord2f(0.0,0.0);glVertex3f(3.05,2.3,-1.5);
            glTexCoord2f(-1.0,2.0);glVertex3f(2.85,2.9,-1.5);
        glEnd();



         /*cylinder back right-left cone*/





        /*window all for left*/
        glBindTexture(GL_TEXTURE_2D, _textureWindow1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(-2.35,1.4,-1.51);
            glTexCoord3f(0.0,1,0);glVertex3f(-2.35,1.9,-1.51);
            glTexCoord3f(1,1,-2);glVertex3f(-3,1.9,-1.51);
            glTexCoord3f(1,0.0,-2);glVertex3f(-3,1.4,-1.51);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureWindow3);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(-2.35,.6,-1.51);
            glTexCoord3f(0.0,1,0);glVertex3f(-2.35,1.1,-1.51);
            glTexCoord3f(1,1,-2);glVertex3f(-3,1.1,-1.51);
            glTexCoord3f(1,0.0,-2);glVertex3f(-3,.6,-1.51);
        glEnd();

        /*janalar side er wall*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(-2,.1,-1.52);
            glTexCoord3f(0.0,.5,0);glVertex3f(-2,.3,-1.52);
            glTexCoord3f(.5,.5,-2);glVertex3f(-2.68,.3,-1.52);
            glTexCoord3f(.5,0.0,-2);glVertex3f(-2.64,.1,-1.52);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(-2.72,.1,-1.52);
            glTexCoord3f(0.0,.5,0);glVertex3f(-2.68,.3,-1.52);
            glTexCoord3f(.5,.5,-2);glVertex3f(-3,.3,-1.52);
            glTexCoord3f(.5,0.0,-2);glVertex3f(-3,.1,-1.52);
        glEnd();
        /*janalar side er wall*/
        glBindTexture(GL_TEXTURE_2D, _textureWindow2);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(-2.35,-.2,-1.51);
            glTexCoord3f(0.0,1,0);glVertex3f(-2.35,.3,-1.51);
            glTexCoord3f(.98,1,-2);glVertex3f(-3,.3,-1.51);
            glTexCoord3f(.98,0.0,-2);glVertex3f(-3,-.2,-1.51);
        glEnd();

        /*window all for left*/





        /*window all for right*/
        glBindTexture(GL_TEXTURE_2D, _textureWindow1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(3.05,1.4,-1.51);
            glTexCoord3f(0.0,1,0);glVertex3f(3.05,1.9,-1.51);
            glTexCoord3f(1,1,-2);glVertex3f(3.6,1.9,-1.51);
            glTexCoord3f(1,0.0,-2);glVertex3f(3.6,1.4,-1.51);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureWindow3);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
         glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(3.05,.6,-1.51);
            glTexCoord3f(0.0,1,0);glVertex3f(3.05,1.1,-1.51);
            glTexCoord3f(1,1,-2);glVertex3f(3.6,1.1,-1.51);
            glTexCoord3f(1,0.0,-2);glVertex3f(3.6,.6,-1.51);
        glEnd();

        /*janalar side er wall*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
         glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(3.05,.1,-1.52);
            glTexCoord3f(0.0,1,0);glVertex3f(3.05,.3,-1.52);
            glTexCoord3f(2.7,1,-2);glVertex3f(3.3,.3,-1.52);
            glTexCoord3f(2.7,0.0,-2);glVertex3f(3.26,.1,-1.52);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
         glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(3.35,.1,-1.52);
            glTexCoord3f(0.0,1,0);glVertex3f(3.31,.3,-1.52);
            glTexCoord3f(2.7,1,-2);glVertex3f(3.6,.3,-1.52);
            glTexCoord3f(2.7,0.0,-2);glVertex3f(3.6,.1,-1.52);
        glEnd();

        /*janalar side er wall*/
        glBindTexture(GL_TEXTURE_2D, _textureWindow2);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
         glBegin(GL_QUADS);  // Wall front tower cube left boundary for window
            glTexCoord3f(0.0,0.0,0);glVertex3f(3.05,-.2,-1.51);
            glTexCoord3f(0.0,1,0);glVertex3f(3.05,.3,-1.51);
            glTexCoord3f(1,1,-2);glVertex3f(3.6,.3,-1.51);
            glTexCoord3f(1,0.0,-2);glVertex3f(3.6,-.2,-1.51);
        glEnd();

        /*window all for right*/


          /*lower street er nicher design back*/

        glBindTexture(GL_TEXTURE_2D, _texturelowerstreetboundary);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(-1.8,-1,-.8);
            glTexCoord2f(0.0,1.0);glVertex3f(-1.8,-1.05,-.8);
            glTexCoord2f(-10.0,1.0);glVertex3f(.4,-.75,-.8);
            glTexCoord2f(-10,0.0);glVertex3f(.4,-.7,-.8);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(.4,-.75,-.8);
            glTexCoord2f(0.0,1.0);glVertex3f(.4,-.7,-.8);
            glTexCoord2f(-10.0,1.0);glVertex3f(2.7,-1,-.8);
            glTexCoord2f(-10,0.0);glVertex3f(2.7,-1.05,-.8);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
             glTexCoord2f(0.0,0.0);glVertex3f(-1.7,-1,-.8);
            glTexCoord2f(0.0,1.0);glVertex3f(-1.7,-1.05,-.8);
            glTexCoord2f(-10.0,1.0);glVertex3f(-1.4,-.75,-.8);
            glTexCoord2f(-10,0.0);glVertex3f(-1.4,-.7,-.8);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
             glTexCoord2f(0.0,0.0);glVertex3f(-.97,-.9,-.8);
            glTexCoord2f(0.0,1.0);glVertex3f(-.97,-.95,-.8);
            glTexCoord2f(-10.0,1.0);glVertex3f(-1.4,-.75,-.8);
            glTexCoord2f(-10,0.0);glVertex3f(-1.4,-.7,-.8);
        glEnd();
         glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(-10.0,1.0);glVertex3f(-1,-.87,-.8);
            glTexCoord2f(-10,0.0);glVertex3f(-1,-.93,-.8);
            glTexCoord2f(0.0,0.0);glVertex3f(-.5,-.75,-.8);
            glTexCoord2f(0.0,1.0);glVertex3f(-.5,-.7,-.8);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(-.5,-.75,-.8);
            glTexCoord2f(0.0,1.0);glVertex3f(-.5,-.7,-.8);
            glTexCoord2f(-10.0,1.0);glVertex3f(-.1,-.78,-.8);
            glTexCoord2f(-10,0.0);glVertex3f(-.1,-.81,-.8);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(1.4,-.75,-.8);
            glTexCoord2f(0.0,1.0);glVertex3f(1.4,-.7,-.8);
            glTexCoord2f(-10.0,1.0);glVertex3f(1,-.78,-.8);
            glTexCoord2f(-10,0.0);glVertex3f(1,-.81,-.8);
        glEnd();
         glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(1.4,-.75,-.8);
            glTexCoord2f(0.0,1.0);glVertex3f(1.4,-.7,-.8);
            glTexCoord2f(-10.0,1.0);glVertex3f(1.9,-.9,-.8);
            glTexCoord2f(-10,0.0);glVertex3f(1.9,-.96,-.8);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(2.2,-.75,-.8);
            glTexCoord2f(0.0,1.0);glVertex3f(2.2,-.7,-.8);
            glTexCoord2f(-10.0,1.0);glVertex3f(1.9,-.9,-.8);
            glTexCoord2f(-10,0.0);glVertex3f(1.9,-.96,-.8);
        glEnd();
        glBegin(GL_QUADS);  // Wall front 1 lower
            glTexCoord2f(0.0,0.0);glVertex3f(2.2,-.75,-.8);
            glTexCoord2f(0.0,1.0);glVertex3f(2.2,-.7,-.8);
            glTexCoord2f(-10.0,1.0);glVertex3f(2.8,-1.55,-.8);
            glTexCoord2f(-10,0.0);glVertex3f(2.8,-1.6,-.8);
        glEnd();
         /*lower street er nicher design back*/





    glPopMatrix();













    // Right side
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,-1,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        /*wall cube inner left*/
        glBegin(GL_QUADS);  // Wall cube right inner
            glTexCoord3f(0.0,2.0,1); glVertex3f(2.4,-.7,1.4);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(2.4,-.7,-1.5);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(2.4,-1.4,-1.5);
            glTexCoord3f(0.0,0.0,1); glVertex3f(2.4,-1.4,1.4);
        glEnd();



        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall cube inner left front
            glTexCoord3f(0.0,2.0,1);    glVertex3f(2.4,-.5,1.4);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(2.4,-.5,.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(2.4,-1.4,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(2.4,-1.4,1.4);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall cube inner left back
            glTexCoord3f(0.0,2.0,1);    glVertex3f(2.4,-.5,-1.5);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(2.4,-.5,-1);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(2.4,-1.4,-1);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(2.4,-1.4,-1.5);
        glEnd();
        /*wall cube inner left*/

        /*wall cube outer right*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall cube right outer
            glTexCoord3f(0.0,2.0,1); glVertex3f(4.3,-.7,1.4);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(4.3,-.7,-1.5);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(4.3,-1.4,-1.5);
            glTexCoord3f(0.0,0.0,1); glVertex3f(4.3,-1.4,1.4);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall cube right outer
            glTexCoord3f(0.0,2.0,1); glVertex3f(4.3,-.5,1.4);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(4.3,-.5,.5);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(4.3,-1.4,.5);
            glTexCoord3f(0.0,0.0,1); glVertex3f(4.3,-1.4,1.4);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall cube right outer
            glTexCoord3f(0.0,2.0,1); glVertex3f(4.3,-.5,-1.5);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(4.3,-.5,-1);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(4.3,-1.4,-1);
            glTexCoord3f(0.0,0.0,1); glVertex3f(4.3,-1.4,-1.5);
        glEnd();
        /*wall cube outer right*/


        /*floow of cube right*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // floor of cube right
            glTexCoord3f(0.0,2.0,1);    glVertex3f(2.4,-.5,1.4);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(4.3,-.5,1.4);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(4.3,-.5,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(2.4,-.5,.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // floor of cube right
            glTexCoord3f(0.0,2.0,1);    glVertex3f(2.4,-.5,-1.5);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(4.3,-.5,-1.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(4.3,-.5,-1);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(2.4,-.5,-1);
        glEnd();


        /*floow of cube right*/



        /*wall tower cube inner right*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall tower cube inner
            glTexCoord3f(0.0,2.0,1); glVertex3f(2.7,1.2,1);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(2.7,1.2,-1.5);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(2.7,.2,-1.5);
            glTexCoord3f(0.0,0.0,1); glVertex3f(2.7,.2,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall tower cube inner left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(2.7,1.2,1);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(2.7,1.2,.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(2.7,-.5,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(2.7,-.5,1);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall tower cube inner left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(2.7,1.2,-1);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(2.7,1.2,-1.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(2.7,-.5,-1.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(2.7,-.5,-1);
        glEnd();

        /*wall tower cube inner right*/


        /*wall tower cube outer left*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall tower cube outer
            glTexCoord3f(0.0,2.0,1); glVertex3f(3.9,1.2,1);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(3.9,1.2,-1.5);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(3.9,.2,-1.5);
            glTexCoord3f(0.0,0.0,1); glVertex3f(3.9,.2,1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall tower cube outer
            glTexCoord3f(0.0,2.0,1); glVertex3f(3.9,1.2,1);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(3.9,1.2,.5);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(3.9,-.5,.5);
            glTexCoord3f(0.0,0.0,1); glVertex3f(3.9,-.5,1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall tower cube outer
            glTexCoord3f(0.0,2.0,1); glVertex3f(3.9,1.2,-1);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(3.9,1.2,-1.5);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(3.9,-.5,-1.5);
            glTexCoord3f(0.0,0.0,1); glVertex3f(3.9,-.5,-1);
        glEnd();
        /*wall tower cube outer right*/


         /*right side boundary after cylinder left */
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front left-left left
            glTexCoord2f(0.0,0.0);glVertex3f(-3.20,1.2,.7);
            glTexCoord2f(0.0,2.0);glVertex3f(-3.20,2.3,.7);
            glTexCoord2f(-2.0,2.0);glVertex3f(-3.20,2.3,-1.2);
            glTexCoord2f(-2,0.0);glVertex3f(-3.20,1.2,-1.2);

        glEnd();
        /*right side boundary after cylinder left */
         /*right side boundary after cylinder right */
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  //cylinder front left-left left
            glTexCoord2f(0.0,0.0);glVertex3f(3.9,1.2,.7);
            glTexCoord2f(0.0,2.0);glVertex3f(3.9,2.3,.7);
            glTexCoord2f(-2.0,2.0);glVertex3f(3.9,2.3,-1.2);
            glTexCoord2f(-2,0.0);glVertex3f(3.9,1.2,-1.2);

        glEnd();
        /*right side boundary after cylinder right */


        /*fence design right*/
        glBindTexture(GL_TEXTURE_2D, _texturelowerstreetboundary);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  // Wall tower cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(3.9,1.2,-.3);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(3.9,1.22,-.3);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(6,-.72,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(6,-.64,.5);
        glEnd();
        glBegin(GL_POLYGON);  // Wall tower cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(3.9,1.2,-.3);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(3.9,1.22,-.3);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(5.7,-.72,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(5.7,-.64,.5);
        glEnd();


        glBegin(GL_POLYGON);  // Wall tower cube outer left
             glTexCoord3f(0.0,2.0,1);    glVertex3f(3.9,1.2,-.3);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(3.9,1.22,-.3);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(6,-.72,-1);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(6,-.64,-1);
        glEnd();
        glBegin(GL_POLYGON);  // Wall tower cube outer left
           glTexCoord3f(0.0,2.0,1);    glVertex3f(3.9,1.2,-.3);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(3.9,1.22,-.3);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(5.7,-.72,-1);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(5.7,-.64,-1);
        glEnd();

        glBegin(GL_POLYGON);  // Wall tower cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(4.2,.65,-.1);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(4.2,-.66,.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(4.22,-.66,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(4.22,.65,-.1);
        glEnd();
        glBegin(GL_POLYGON);  // Wall tower cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(4.2,.65,-.5);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(4.2,-.66,-1);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(4.22,-.66,-1);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(4.22,.65,-.5);
        glEnd();

        /*fence design right*/

        /*
        glBegin(GL_TRIANGLES);  // Wall Upper
            glTexCoord3f(0.0,1.0,0); glVertex3f(2,0.5,0);
            glTexCoord3f(1.0,0.0,1); glVertex3f(2,0,1);
            glTexCoord3f(-1.0,0.0,-1); glVertex3f(2,0,-1);
        glEnd();
        */
    glPopMatrix();


















    // Left side
    glPushMatrix();


        /*wall cube inner left*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,-1,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall cube inner left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-1.7,-.7,1.4);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-1.7,-.7,-1.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-1.7,-1.4,-1.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-1.7,-1.4,1.4);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall cube inner left front
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-1.7,-.5,1.4);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-1.7,-.5,.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-1.7,-1.4,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-1.7,-1.4,1.4);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall cube inner left back
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-1.7,-.5,-1.5);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-1.7,-.5,-1);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-1.7,-1.4,-1);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-1.7,-1.4,-1.5);
        glEnd();
        /*wall cube inner left*/


        /*wall cube outer left*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.6,-.7,1.4);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.6,-.7,-1.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-3.6,-1.4,-1.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-3.6,-1.4,1.4);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall cube outer left front
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.6,-.5,1.4);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.6,-.5,.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-3.6,-1.4,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-3.6,-1.4,1.4);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall cube outer left back
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.6,-.5,-1.5);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.6,-.5,-1);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-3.6,-1.4,-1);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-3.6,-1.4,-1.5);
        glEnd();

        /*wall cube outer left*/





        /*floor of cube left*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // floor of cube left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.6,-.5,1.4);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-1.7,-.5,1.4);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-1.7,-.5,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-3.6,-.5,.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // floor of cube left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.6,-.5,-1.5);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-1.7,-.5,-1.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-1.7,-.5,-1);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-3.6,-.5,-1);
        glEnd();
        /*floor of cube left*/


        /*wall tower cube inner left*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall tower cube inner left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-2,1.2,1);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-2,1.2,.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-2,-.5,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-2,-.5,1);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall tower cube inner left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-2,1.2,-1);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-2,1.2,-1.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-2,-.5,-1.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-2,-.5,-1);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Wall tower cube inner left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-2,1.2,1);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-2,1.2,-1.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-2,.2,-1.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-2,.2,1);
        glEnd();
        /*wall tower cube inner left*/




        /*wall tower cube outer left*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  // Wall tower cube outer left
            /*
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.2,1.2,1);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.2,1.2,-1.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-3.2,-.5,-1.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-3.2,-.5,1);
            */
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.2,1.2,1);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.2,1.2,.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-3.2,-.5,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-3.2,-.5,1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  // Wall tower cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.2,1.2,-1);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.2,1.2,-1.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-3.2,-.5,-1.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-3.2,-.5,-1);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  // Wall tower cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.2,1.2,1);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.2,1.2,-1.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-3.2,.2,-1.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-3.2,.2,1);
        glEnd();
        /*wall tower cube outer left*/






        /*fence design left*/
        glBindTexture(GL_TEXTURE_2D, _texturelowerstreetboundary);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);  // Wall tower cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.2,1.2,-.3);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.2,1.22,-.3);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-5.3,-.72,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-5.3,-.64,.5);
        glEnd();
        glBegin(GL_POLYGON);  // Wall tower cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.2,1.2,-.3);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.2,1.22,-.3);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-5,-.72,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-5,-.64,.5);
        glEnd();


        glBegin(GL_POLYGON);  // Wall tower cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.2,1.2,-.3);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.2,1.22,-.3);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-5.3,-.72,-1);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-5.3,-.64,-1);
        glEnd();
        glBegin(GL_POLYGON);  // Wall tower cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.2,1.2,-.3);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.2,1.22,-.3);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-5,-.72,-1);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-5,-.64,-1);
        glEnd();

        glBegin(GL_POLYGON);  // Wall tower cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.8,.65,-.1);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.8,-.66,.5);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-3.82,-.66,.5);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-3.82,.65,-.1);
        glEnd();
        glBegin(GL_POLYGON);  // Wall tower cube outer left
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-3.8,.65,-.5);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-3.8,-.66,-1);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-3.82,-.66,-1);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-3.82,.65,-.5);
        glEnd();


        /*fence design left*/













         /*left side inner boundary after cylinder left*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);
            glTexCoord2f(0.0,0.0);glVertex3f(-2.05,1.2,-1.5);
            glTexCoord2f(0.0,2.0);glVertex3f(-2.05,2.3,-1.5);
            glTexCoord2f(-2.0,2.0);glVertex3f(-2.05,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(-2.05,1.2,1);

        glEnd();
        /*left side inner boundary after cylinder left*/

         /*left side inner boundary after cylinder right*/
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_POLYGON);
            glTexCoord2f(0.0,0.0);glVertex3f(2.7,1.2,-1.5);
            glTexCoord2f(0.0,2.0);glVertex3f(2.7,2.3,-1.5);
            glTexCoord2f(-2.0,2.0);glVertex3f(2.7,2.3,1);
            glTexCoord2f(-2,0.0);glVertex3f(2.7,1.2,1);

        glEnd();
        /*left side inner boundary after cylinder right*/










        /*
        glBegin(GL_TRIANGLES);  // Wall Upper
            glTexCoord3f(0.0,1.0,0);    glVertex3f(-2,0.5,0);
            glTexCoord3f(1.0,0.0,1);    glVertex3f(-2,0,1);
            glTexCoord3f(-1.0,0.0,-1);    glVertex3f(-2,0,-1);
        glEnd();
        */
    glPopMatrix();

    glutSwapBuffers();
}

void mySpecialFunc(int key, int x, int y){
	switch (key) {
    case GLUT_KEY_RIGHT:
        _angle += 1;
        if (_angle > 360) _angle = 0.0;
		break;

		case GLUT_KEY_UP:
        _angle += 1;
        if (_angle > 360) _angle = 0.0;
		break;
    case GLUT_KEY_LEFT:
        _angle -= 1;
        if (_angle > 360) _angle = 0.0;
	    break;
	}
	glutPostRedisplay();
}

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	Image* image = loadBMP("F:\\bricks.bmp");
	_textureBrick = loadTexture(image);
	image = loadBMP("F:\\door.bmp");
	_textureDoor = loadTexture(image);
	image = loadBMP("F:\\quadbridge.bmp");
	_texturequadbridge = loadTexture(image);
	image = loadBMP("F:\\head2.bmp");
	_texturebridgehead = loadTexture(image);
	image = loadBMP("F:\\grass.bmp");
	_textureGrass = loadTexture(image);
	image = loadBMP("F:\\roof.bmp");
	_textureRoof = loadTexture(image);
	image = loadBMP("F:\\window1.bmp");
	_textureWindow1 = loadTexture(image);
	image = loadBMP("F:\\window2.bmp");
	_textureWindow2 = loadTexture(image);
	image = loadBMP("F:\\window3.bmp");
	_textureWindow3 = loadTexture(image);
	image = loadBMP("F:\\sky.bmp");
	_textureSky = loadTexture(image);
	image = loadBMP("F:\\lowerbridge.bmp");
	_texturelowerbridge = loadTexture(image);
	image = loadBMP("F:\\blackboundary.bmp");
	_textureblackboundary = loadTexture(image);
	image = loadBMP("F:\\lowerstreetboundary.bmp");
	_texturelowerstreetboundary = loadTexture(image);
	image = loadBMP("F:\\cloud2.bmp");
	_texturecloud2 = loadTexture(image);


	delete image;
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(1440,900);
	glutCreateWindow("Z-London Tower Bridge");
	glEnable(GL_DEPTH_TEST);

	glutReshapeFunc(resize);
	glutSpecialFunc(mySpecialFunc);
	glutDisplayFunc(renderScene);
	Initialize();

	glutMainLoop();

	return 0;
}
