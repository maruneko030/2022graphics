#include <GL/glut.h>
#include <stdio.h>
void timer(int t)
{
    printf("�x��%d,�_�ɤF\n", t);
    printf("�]�w�U�@�Ӿx��\n");
    glutTimerFunc(1000, timer, t+1);
    printf("�]�w�n�x��, �^�h�Φ^Ţı\n");
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
