#include <GL/glut.h>
#include <stdio.h>
float angle[20], oldX=0;
int angleID=0;
FILE*fout=NULL, *fin=NULL;
void myWrite()
{
    if(fout==NULL) fout=fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
        fprintf(fout, "%.2f ", angle[i]);
    }
}
float NewAngle[20],OldAngle[20];
void myRead()
{
    if(fout!=NULL){fclose(fout); fout=NULL;}
    if(fin==NULL) fin=fopen("file.txt", "r");
    for(int i=0; i<20; i++){
            OldAngle[i] = NewAngle[i];
            fscanf(fin,"%f",&NewAngle[i]);
        ///fscanf(fin, "%f", &angle[i]);
    }
    glutPostRedisplay();
}
void myInterpolate(float alpha){
    for(int i=0;i<20;i++){
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
        printf("%.2f ",angle[i]);
    }
    printf("\n");
    glutPostRedisplay();
}
float alpha=0;
void timer(int t){
    float alpha = (t%100)/100.0;
    if(t%100==0) myRead();
    myInterpolate(alpha);
    glutTimerFunc(33,timer,t+1);
}
void keyboard(unsigned char key, int x, int y)
{
    if(key=='p'){///play
            myRead();
    glutTimerFunc(0,timer,0);
            ///myInterpolate(alpha);
            ///alpha = (alpha+0.0);
            ///if(alpha>1)alpha = alpha-1;
    }
    if(key=='r') myRead();///read
    if(key=='s') myWrite();///save
    if(key == '0') angleID=0;
    if(key == '1') angleID=1;
    if(key == '2') angleID=2;
    if(key == '3') angleID=3;
}
void mouse(int button, int state, int x, int y)
{
    oldX= x;
}
void motion(int x, int y)
{
    angle[angleID] += (x-oldX);
    ///myWrite();
    oldX= x;
    glutPostRedisplay();
}
#include<math.h>
void myCircle(float x,float y)
{
   glBegin(GL_POLYGON);
    for(float a=0; a<3.1415*2; a+=0.1){
        glVertex2f( x + 0.1*cos(a),y + 0.1*sin(a) );
    }
    glEnd();
}
void Display(void) ///右邊
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///具有3D深度
glColor3f(1,1,1);///白色
glRectf(0.3, 0.5, -0.3, -0.2); ///繪制一個矩形(白色)


glPushMatrix();///右
    glTranslatef(0.3,0.5,0);///掛在0.5的地方 3.
    glRotatef(angle[0],0,0,1);///旋轉2.
    glTranslatef(-0.3,-0.4,0);///移動1.
    glColor3f(1,0,0);///紅色
glRectf(0.3, 0.5, 0.8, 0.3); ///繪制第二個個矩形///可用-1~1
myCircle(0.3,0.4);///0.3-0.4

glPushMatrix();
    glTranslatef(0.8,0.4,0);
    glRotatef(angle[1],0,0,1);
    glTranslatef(-0.8,-0.4,0);
    glColor3f(0,1,0);///綠色
    glRectf(0.8,0.5,1.1,0.3);
    myCircle(0.8,0.4);///0.8-0.4
    myCircle(1.1,0.4);///1.1-0.4
glPopMatrix();
glPopMatrix();


glPushMatrix();///左
    glTranslatef(-0.3,0.5,0);///掛在0.5的地方 3.
    glRotatef(angle[2],0,0,1);///旋轉2.
    glTranslatef(0.3,-0.4,0);///移動1.
    glColor3f(1,0,0);///紅色
glRectf(-0.3, 0.5, -0.8, 0.3); ///繪制第二個個矩形///可用-1~1
myCircle(-0.3,0.4);
glPushMatrix();
    glTranslatef(-0.8,0.4,0);
    glRotatef(angle[3],0,0,1);
    glTranslatef(0.8,-0.4,0);
    glColor3f(0,1,0);///綠色
    glRectf(-0.8,0.5,-1.1,0.3);
    myCircle(-0.8,0.4);
    myCircle(-1.1,0.4);
glPopMatrix();
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
glutKeyboardFunc(keyboard);
glutDisplayFunc(Display); ///設置當前窗口的顯示回調函數(但我還是不懂，用背的)

glutMainLoop(); ///結束
return 0;
}
