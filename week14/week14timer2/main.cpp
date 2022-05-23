#include <GL/glut.h>
#include <mmsystem.h>
#include <stdio.h>
void timer(int t)
{
    printf("鬧鐘%d,起床了\n", t);
    PlaySound("do.wav", NULL, SND_ASYNC);
    printf("設定下一個鬧鐘\n");
    glutTimerFunc(1000, timer, t+1);
}
void display()
{

}
int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week14 timer");

    glutTimerFunc(3000, timer, 0);
    glutDisplayFunc(display);
    glutMainLoop();
}
