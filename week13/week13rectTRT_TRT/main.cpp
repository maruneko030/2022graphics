#include<gl/glut.h>
float angle[20],oldX=0;///�]�w����
int angleID=0;
void keyboard( unsigned char key,int x,int y){
    if( key =='0') angleID=0;
    if( key =='1') angleID=1;
    if( key =='2') angleID=2;
    if( key =='3') angleID=3;
}

void mouse(int button,int state,int x,int y){
    oldX = x;
}
void motion(int x,int y){
    angle[angleID] += (x-oldX);
    oldX = x;
    glutPostRedisplay();///���e�ù�
}
void Display(void) ///�k��
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�㦳3D�`��
glColor3f(1,1,1);///�զ�
glRectf(0.3, 0.5, -0.3, -0.2); ///ø��@�ӯx��(�զ�)


glPushMatrix();///�k
    glTranslatef(0.3,0.5,0);///���b0.5���a�� 3.
    glRotatef(angle[0],0,0,1);///����2.
    glTranslatef(-0.3,-0.4,0);///����1.
    glColor3f(1,0,0);///����
glRectf(0.3, 0.5, 0.8, 0.3); ///ø��ĤG�ӭӯx��///�i��-1~1
glPushMatrix();
    glTranslatef(0.8,0.4,0);
    glRotatef(angle[1],0,0,1);
    glTranslatef(-0.8,-0.4,0);
    glColor3f(0,1,0);///���
    glRectf(0.8,0.5,1.1,0.3);
glPopMatrix();
glPopMatrix();


glPushMatrix();///��
    glTranslatef(-0.3,0.5,0);///���b0.5���a�� 3.
    glRotatef(angle[2],0,0,1);///����2.
    glTranslatef(0.3,-0.4,0);///����1.
    glColor3f(1,0,0);///����
glRectf(-0.3, 0.5, -0.8, 0.3); ///ø��ĤG�ӭӯx��///�i��-1~1
glPushMatrix();
    glTranslatef(-0.8,0.4,0);
    glRotatef(angle[3],0,0,1);
    glTranslatef(0.8,-0.4,0);
    glColor3f(0,1,0);///���
    glRectf(-0.8,0.5,-1.1,0.3);
glPopMatrix();
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
glutKeyboardFunc(keyboard);
glutDisplayFunc(Display); ///�]�m��e���f����ܦ^�ը��(�����٬O�����A�έI��)

glutMainLoop(); ///����
return 0;
}
