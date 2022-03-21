#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備分矩陣
        glRotatef(angle,0,0,1);///修改角度
        glColor3f(1,1,0);///修改顏色
        glutSolidTeapot(0.3);///修改物品
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void motion(int x,int y)
{///拖著物體動
    angle = x;
    display();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05_rotate");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
}
