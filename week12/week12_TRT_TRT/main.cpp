#include <GL/glut.h>
#include <stdio.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glutSolidTeapot(0.3);///大茶壺
    glPushMatrix();
    glTranslated(0,0,0);
    glRotatef(angle,0,0,1);
    glTranslatef(0.2,0,0);
    glColor3f(1,0,0);
        glutSolidTeapot(0.2);///小茶壺
        glPopMatrix();
    glutSwapBuffers();
    angle+=0.02;///轉速

}

int main(int argc, char *argv[] )

{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12_TRT");

     glutIdleFunc(display);
     glutDisplayFunc(display);

     glutMainLoop();

}
