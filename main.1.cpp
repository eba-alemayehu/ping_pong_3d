#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define WIN_TITLE "3D PING PONG"
#define REFRESH_RATE 30;

using namespace std;

struct Plane{
    GLfloat elivation = 1.0;
    GLfloat width = 4.0;
    GLfloat length = 6.0;
} plane;

struct Ball {
    GLfloat elivation = 1.0001;
    GLfloat width = 0.2;
    pair<GLfloat, GLfloat> *loc = new pair<GLfloat ,GLfloat>();
} ball;
GLfloat angle = 45.0;
GLfloat far = -10.0;
pair<GLfloat, GLfloat> *speed = new pair<GLfloat , GLfloat>(0.05, 0.05);

void init();
void onResize(GLsizei w, GLsizei h);
void display(void);
void onKey(unsigned char k, int x,int y);
void refresh(int);

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_DEPTH);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(50, 50);

    glutDisplayFunc(display);
    glutReshapeFunc(onResize);
    glutKeyboardFunc(onKey);
    unsigned int frame_time = 1000/REFRESH_RATE;
    glutTimerFunc(frame_time, refresh, 0);
    init();
    glutCreateWindow(WIN_TITLE);
    glutMainLoop();
    return 0;
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glTranslatef(0.0, 0.0,far);
    glRotatef(angle, 1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glColor3f(0.1f, 6.0f, 0.2f);     // Blue
        glVertex3f( plane.width/2.0, plane.elivation,  plane.length/2.0);
        glVertex3f(-1*(plane.width/2.0) , plane.elivation,  plane.length/2.0);
        glVertex3f(-1*(plane.width/2.0), plane.elivation, -1*plane.length/2.0);
        glVertex3f( plane.width/2.0, plane.elivation, -1*plane.length/2.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);     // Red
        glVertex3f(ball.loc->first , ball.elivation,  ball.loc->second);
        glVertex3f(ball.loc->first, ball.elivation, ball.loc->second - ball.width);
        glVertex3f(ball.loc->first + ball.width, ball.elivation, ball.loc->second - ball.width);
        glVertex3f( ball.loc->first + ball.width, ball.elivation,  ball.loc->second);

    glEnd();
    glutSwapBuffers();
}
void init(){
    glClearColor(0.0,0.0,0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void onResize(GLsizei w, GLsizei h){
    glViewport(0, 0, w, h);

    GLfloat r = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, r, 2.0, 20.0);
}

void onKey(unsigned char k, int x,int y){
    switch(k){
        case 'a':
            angle += 3;
            break;
        case 'b':
            far -=1;
            break;
        case 'c':
            ball.loc->first += 0.1;
            break;
    }

    cout << angle << " " << far << " " << ball.loc->first <<endl;
    glutPostRedisplay();
}

void refresh(int x){
    if(ball.loc->first + ball.width >= plane.width/2.0 || ball.loc->first <= -1* plane.width/2.0){
        speed->first *= -1;
    }

    if(ball.loc->second >= plane.length/2.0 || ball.loc->second - ball.width  < -1* plane.length/2.0){
        speed->second *= -1;
        cout << ball.loc->first << " <====> " << ball.loc->second << endl;
    }
    ball.loc->first += speed->first;
    ball.loc->second += speed->second;
    int frame_time = 1000/REFRESH_RATE;
    cout << ball.loc->first << " , " << ball.loc->second << endl;

    glutTimerFunc(frame_time, refresh, 0);
    glutPostRedisplay();
}