#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();///push�ƥ��x�}
        glTranslated(0.3,0.2,0);///�k�W��
        glColor3f(1,0,0);///red
        glutSolidTeapot(0.3);
    glPopMatrix();///pop�٭�x�}
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(& argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("HW2 bonus");

    glutDisplayFunc(display);
    glutMainLoop();
}
