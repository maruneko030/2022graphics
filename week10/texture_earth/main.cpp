#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere=NULL;
int myTexture(char * filename)
{
    Ip1Image * img = cvLoadImage(filename);
    cvCvtColor(img,img,CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1,&id);
    glBindTexture(GL_TEXTURE_2D,id);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->width,img->height,0,GL_RGB,GL_UNSIGNED_BYTE,img->imagData);s
    return id;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(90,1,0,0);
        gluQuadricTexture(sphere,1);
        giuSphere(sphere,1,30,30);
    giPopMatrix();
        glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glutDisplayFunc(display);
    myTexture("earth.jpg");
    sphere = gluNewQuadric();
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
