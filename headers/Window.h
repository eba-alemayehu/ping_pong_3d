//
// Created by eba on 07/01/2020.
//

#ifndef LAB32_WINDOW_H
#define LAB32_WINDOW_H


#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

#define FPS 15

class Window {
private:
    void init();
    GLint width = 600;
    GLint height = 400;
    GLint pos_x = 50;
    GLint pos_y = 50;

    char* title = nullptr;
    GLfloat _zoom = -10.0;
    GLfloat angle = 45.0;

    string main_message;
public:
    Window(int argv, char* argc[], char* title);
    void setSize(GLint w, GLint h);
    void setPosition(GLint x,GLint y);
    void onResize(GLsizei w, GLsizei h);
    void onResize(void (* callback) (GLsizei, GLsizei));
    void onKey(void (* callback)(unsigned char, int, int));
    void onDisplay(void (* callback)(void));
    void onClick(void (* callback)(int, int, int, int));
    void onUpdate(void (* callback)(int));
    void rotate(bool forward = true);
    void zoom(bool zoon_in = true);
    void show();
    void createWindow();
    void displayInit();
    void render();
    void setMainMessage(string msg){ this->main_message = msg; glutPostRedisplay(); }
};


#endif //LAB32_WINDOW_H
