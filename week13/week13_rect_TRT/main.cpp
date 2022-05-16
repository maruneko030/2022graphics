#include<gl/glut.h>
float angle=45,oldX=0;///設定角度
void mouse(int button,int state,int x,int y){
    oldX = x;
}
void motion(int x,int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay();///重畫螢幕
}
void Display(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///具有3D深度
glColor3f(1,1,1);///白色
glRectf(0.5, 0.5, -0.5, -0.5); ///繪制一個矩形(白色)
glPushMatrix();///備份矩陣
    glTranslated(0.5,0.5,0);///掛在0.5的地方 3.
    glRotatef(angle,0,0,1);///旋轉2.
    glTranslatef(-0.5,-0.4,0);///移動1.
    glColor3f(1,0,0);///紅色
glRectf(0.5, 0.5, 1.0, 0.3); ///繪制第二個個矩形///可用-1~1
glPopMatrix();
glutSwapBuffers();///(只能存在一個)共4種buffers
}

int main(int argc, char* argv[])
{
glutInit(&argc,argv);
///glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 無3D功能
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///有3D功能
glutInitWindowSize(600,600); ///視窗大小
glutCreateWindow("week13 rect TRT"); ///專案
glutMouseFunc(mouse);
glutMotionFunc(motion);
glutDisplayFunc(Display); ///設置當前窗口的顯示回調函數(但我還是不懂，用背的)

glutMainLoop(); ///結束
return 0;
}
