#include <GL/glut.h>
#include <stdio.h>
int mouseX=0, mouseY=0;
void display()
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1,1,0);///yellow
        glPushMatrix();
            glTranslated((mouseX-150)/150.0,-(mouseY-150)/150.0,0);
            glutSolidTeapot(0.3);///¯ù³ý
        glPopMatrix();
        glutSwapBuffers();
}
void mouse(int button, int state, int x,int y)
{
    //printf("%d %d %d %d\n",button, state, x, y);
    mouseX=x; mouseY=y;
    if(state==GLUT_DOWN)
        {
            printf("   glVertex2f()\n");
        }
}
int main(int argc, char**argv)
{
    glutInit( &argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 mouse");

    glutDisplayFunc(display);///displayÅã¥Ü
    glutMouseFunc(mouse);///mouse ·Æ¹«
    glutMainLoop();
}

