//
// Created by eba on 07/01/2020.
//

#ifndef LAB32_TABLE_H
#define LAB32_TABLE_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>
using namespace std;

class Table {
private:
    GLfloat width;
    GLfloat length;
    GLfloat elivation;

    GLfloat color[3] = {0.1, 0.6, 0.2};

    GLint score_player1;
    GLint score_player2;

    GLint time = 0;
public:
    Table(GLfloat width, GLfloat length, GLfloat elivation);
    void render();
    GLfloat getWidth() { return this->width; }
    GLfloat getLength() { return this->length; }
    GLfloat getElivation() { return this->elivation; }

    void setScore_player1(GLint score_player1) { this->score_player1 = score_player1; }
    void setScore_player2(GLint score_player2) { this->score_player2 = score_player2;  }
    void setTime(GLint time) { this->time = time; }
    void reset();
    vector<GLfloat*> rect_prizem(GLfloat x, GLfloat y, GLfloat Z, GLfloat w, GLfloat l, GLfloat h);
};


#endif //LAB32_TABLE_H
