//
// Created by eba on 07/01/2020.
//

#include "../headers/Ball.h"
#include <cmath>

#define PI 3.142857142857143

using namespace std;

void Ball::render() {
    glColor3f(1.0, 0.16666666666,0.48823529411);
    glPolygonMode(GL_FRONT_AND_BACK , GL_FILL);
    glBegin(GL_POLYGON);
        glVertex3f(this->xc, this->yc, this->zc);
        GLfloat x, z;
        pair<GLfloat, GLfloat> points[362];
        GLfloat deg2rad = PI/180;
        for(int teta = 0; teta <= 361; teta++){
            points[teta].first = xc + r * cos((double)(teta * deg2rad));
            points[teta].second = zc + r * sin((double)(teta * deg2rad));
        }
    for (int j = 0; j < 361; j++) glVertex3f(points[j].first, yc, points[j].second);
//    for (int j = 0; j < 180; j++) glVertex3f(-1 * points[j].first, yc, -1 * points[j].second);
//    for (int j = 0; j < 45; j++) glVertex3f(-1*points[j].second, yc, points[j].first);
//    for (int j = 0; j < 45; j++) glVertex3f(-1*points[j].first, yc, points[j].second);
//    for (int j = 0; j < 45; j++) glVertex3f(-1*points[j].first, yc, -1*points[j].second);
//    for (int j = 0; j < 45; j++) glVertex3f(points[j].second* -1, yc, -1 * points[j].first);
//    for (int j = 0; j < 45; j++) glVertex3f(points[j].second, yc, -1 * points[j].first);
//    for (int j = 0; j < 45; j++) glVertex3f(points[j].first, yc, -1 * points[j].second);


    glEnd();
}

Ball::Ball(GLfloat r, GLfloat xc, GLfloat yc, GLfloat zc, GLfloat player_width, GLfloat thickness) {
    this->r = r;
    this->xc = xc;
    this->yc = yc;
    this->zc = zc;
    this->state = pair<bool, bool>(true, true);
    this->speed = pair<GLfloat ,GLfloat >(-0.03f, 0.03f);
    this->player_width = player_width;
    this->thickness = thickness;

    this->reset_r = r;
    this->reset_xc = xc;
    this->reset_yc = yc;
    this->reset_zc = zc;
}

void Ball::update(GLfloat w, GLfloat l,GLfloat player1_x, GLfloat player2_x,  void (* callback)(int)) {
    if(this->xc+this->r >= w/2 || this->xc - this->r <= -1 * w / 2){
        this->state.first = !this->state.first;
    }
    if(this->zc+this->r >= l/2 - this->thickness || this->zc - this->r <= -1 * l/2 + this->thickness){
        bool over = (this->zc+this->r >= l/2 || this->zc - this->r <= -1 * l/2);
        if(!(this->xc >= player1_x - this->player_width/2 && this->xc <= player1_x + this->player_width/2) && this->state.second) {
            if(over) {
                this->zc = 0;
                this->xc = 0;
                callback(1);
                this->state.second = !this->state.second;
            }

        }else if(!(this->xc >= player2_x - this->player_width/2 && this->xc <= player2_x + this->player_width/2) && !this->state.second) {
            if(over) {
                this->zc = 0;
                this->xc = 0;
                callback(2);
                this->state.second = !this->state.second;
            }

        }else
            this->state.second = !this->state.second;
    }

    if(this->state.first) this->xc  += speed.first;
    else this->xc -= speed.first;

    if(this->state.second) this->zc  += speed.second;
    else this->zc -= speed.second;
    glutPostRedisplay();
}

void Ball::reset() {
    this->state = pair<bool, bool>(true, true);
    this->speed = pair<GLfloat ,GLfloat >(-0.025f, 0.025f);

    this->r = this->reset_r;
    this->xc = this->reset_xc;
    this->yc = this->reset_yc;
    this->zc = this->reset_zc;
}



