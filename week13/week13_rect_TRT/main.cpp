#include<gl/glut.h>
float angle=45,oldX=0;///�]�w����
void mouse(int button,int state,int x,int y){
    oldX = x;
}
void motion(int x,int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay();///���e�ù�
}
void Display(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�㦳3D�`��
glColor3f(1,1,1);///�զ�
glRectf(0.5, 0.5, -0.5, -0.5); ///ø��@�ӯx��(�զ�)
glPushMatrix();///�ƥ��x�}
    glTranslated(0.5,0.5,0);///���b0.5���a�� 3.
    glRotatef(angle,0,0,1);///����2.
    glTranslatef(-0.5,-0.4,0);///����1.
    glColor3f(1,0,0);///����
glRectf(0.5, 0.5, 1.0, 0.3); ///ø��ĤG�ӭӯx��///�i��-1~1
glPopMatrix();
glutSwapBuffers();///(�u��s�b�@��)�@4��buffers
}

int main(int argc, char* argv[])
{
glutInit(&argc,argv);
///glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); �L3D�\��
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///��3D�\��
glutInitWindowSize(600,600); ///�����j�p
glutCreateWindow("week13 rect TRT"); ///�M��
glutMouseFunc(mouse);
glutMotionFunc(motion);
glutDisplayFunc(Display); ///�]�m��e���f����ܦ^�ը��(�����٬O�����A�έI��)

glutMainLoop(); ///����
return 0;
}
