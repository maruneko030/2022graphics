#include <GL/glut.h>

void display()

{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glPushMatrix();///�Ƥ��x�}
        glRotatef(180,0,0,1);///�ק﨤��
        glColor3f(1,1,0);///�ק��C��
        glutSolidTeapot(0.3);///�ק磌�~
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();

}

int main(int argc, char *argv[] )

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week05_rotate");

     glutDisplayFunc(display);

     glutMainLoop();

}