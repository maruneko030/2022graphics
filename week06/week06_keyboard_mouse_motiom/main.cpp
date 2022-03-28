#include <GL/glut.h>
#include <stdio.h>
float x=250,y=250,z=0,scale=1.0,angle=0.0,oldX,oldY;
int now=1;///1����2����3�Y��
void display()
{
    glClearColor(0.5, 0.5, 0.5, 1);///�Ψ�Clear��m R�BG�BB�BA
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glPushMatrix();
     glTranslatef((x-250)/250.0,-(y-250)/250.0, z );///Maya: w
     glRotatef( angle, 0, 0, 1);///Maya: e
     glScalef( scale, scale,scale);///Maya: r
        glColor3f(1,1,0);///�ק��C��
        glutSolidTeapot(0.3);///�ק磌�~
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{
    //printf("�{�b���U:%c �y�Цb:%d %d\n", key, mouseX, mouseY);
    if(key=='w' || key=='W') now=1;///����
    if(key=='e' || key=='E') now=2;///����
    if(key=='r' || key=='R') now=3;///�Y��
}
void mouse( int button, int state, int mouseX, int mouseY )
{
    oldX = mouseX; oldY = mouseY;
}
void motion( int mouseX, int mouseY )
{
    if(now==1){///����
        x += (mouseX-oldX);
        y += (mouseY-oldY);
    }else if(now==2){///����
        angle += (mouseX-oldX);
    }else if(now==3){
    if( mouseX>oldX )scale = scale * 1.01;
    if( mouseX<oldX )scale = scale * 0.99;
    }
    oldX = mouseX; oldY = mouseY;
    display();
}
int main(int argc, char *argv[] )
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06_keyboard");

     glutDisplayFunc(display);
     glutKeyboardFunc(keyboard);
     glutMouseFunc(mouse);
     glutMotionFunc(motion);

     glutMainLoop();

}

