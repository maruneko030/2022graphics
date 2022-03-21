#include <stdio.h>
#include <GL/glut.h>
int N=0;///�k0
int x[1000], y[1000];///�̦h��1000�ӳ��I
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N;i++){
        glVertex2f((x[i]-150)/150.0,(y[i]-150)/150.0);
    }
    glEnd();
    glutSwapBuffers();
}
void mouse(int button, int state, int mouseX,int mouseY)
{
    if(state==GLUT_DOWN){
        N++;
        x[N-1]=mouseX;
        y[N-1]=mouseY;
        printf("�{�b���U�ƹ��A�o��s�y�� %d %d\n", x[N-1],y[N-1]);
    }
    display();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05_mouse");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
