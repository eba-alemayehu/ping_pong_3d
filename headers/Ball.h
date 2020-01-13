//
// Created by eba on 07/01/2020.
//

#ifndef LAB32_BALL_H
#define LAB32_BALL_H

#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>

using namespace std;
class Ball {
private:
    GLfloat r;
    GLfloat xc;
    GLfloat yc;
    GLfloat zc;
    GLfloat player_width;
    GLfloat thickness;
    pair<bool, bool> state;
    pair<GLfloat, GLfloat> speed;

    GLfloat reset_r;
    GLfloat reset_xc;
    GLfloat reset_yc;
    GLfloat reset_zc;

public:
    Ball(GLfloat r, GLfloat xc, GLfloat yc, GLfloat zc, GLfloat player_width, GLfloat thickness);
    void render();
    void update(GLfloat w, GLfloat l, GLfloat player1_x, GLfloat player2_x, void (* callback)(int));
    void reset();
};


#endif //LAB32_BALL_H
