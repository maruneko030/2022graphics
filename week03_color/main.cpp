///第一步 全部刪除
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1,1,0);///黃色
    glutSolidTeapot( 0.3 );///0.3實心茶壺
    glutSwapBuffers();///交換兩倍的buffer
}

int main(int argc,char**argv)
{///進階的main函式
    glutInit( &argc,argv );///初始化先
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍+3D
    glutCreateWindow("week03的視窗");///建立視窗

    glutDisplayFunc( display );///今天畫畫的函式

    glutMainLoop();///主要的迴圈
    return 0;
}
