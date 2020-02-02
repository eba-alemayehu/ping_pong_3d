//
// Created by eba on 07/01/2020.
//

#include <GL/glut.h>
#include <cstring>
#include "../headers/Window.h"

Window::Window(int argv, char **argc, char *title) {
    glutInit(&argv, argc);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    this->title = title;
}

void Window::setSize(GLint w, GLint h) {
    this->width = w;
    this->height = h;
}

void Window::setPosition(GLint x, GLint y) {
    this->pos_x = x;
    this->pos_y = y;
}
void Window::createWindow() {
    glutInitWindowSize(this->width, this->height);
    glutInitWindowPosition(this->pos_x, this->pos_y);
    glutCreateWindow(title);
}

void Window::show() {
    this->init();
    glutMainLoop();
}

void Window::init() {
    glClearColor(0.0,0.0,0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void Window::onResize(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);

    GLfloat r = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, r, 2.0, 20.0);
}

void Window::onResize(void (*callback)(GLsizei , GLsizei)) {
    glutReshapeFunc(callback);
}

void Window::onKey(void (*callback)(unsigned char, int, int)) {
    glutKeyboardFunc(callback);
    glutPostRedisplay();
}

void Window::onDisplay(void (*callback)(void)) {
    glutDisplayFunc(callback);
}

void Window::onClick(void (*callback)(int, int, int, int)) {
    glutMouseFunc(callback);
    glutPostRedisplay();
}

void Window::displayInit() {
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glTranslatef(0.0, 0.0,this->_zoom);
    glRotatef(this->angle, 1.0, 0.0, 0.0);
}

void Window::onUpdate(void (*callback)(int)) {
    glutTimerFunc(1000/ FPS, callback, FPS);
}

void Window::render() {
    glColor3f(1.0, 0.2, 1.0);
    glRasterPos3f(-0.5f, 1.8f, 0);
    for(int i = 0; i < strlen(this->main_message.c_str()); i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, this->main_message[i]);
}

void Window::rotate(bool forward) {
    this->angle += (forward)? 0.5: -0.5;
    glutPostRedisplay();
}

void Window::zoom(bool zoon_in) {
    this->_zoom += (zoon_in)? 0.5: -0.5;
    glutPostRedisplay();
}
