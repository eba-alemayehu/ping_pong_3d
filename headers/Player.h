//
// Created by eba on 07/01/2020.
//

#ifndef LAB32_PLAYER_H
#define LAB32_PLAYER_H

#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>

using namespace std;

class Player {
private:
    pair<GLfloat, GLfloat> loc;
    GLfloat width;
    GLfloat tickness;
    GLfloat elevation;
    GLfloat color[3];
    GLfloat speed = 0.2;
    GLfloat table_width;
public:
    Player(pair<GLfloat, GLfloat> loc,GLfloat width, GLfloat tickness, GLfloat elevation, GLfloat table_width);
    void render(GLfloat* color);
    void update(bool right, bool left);
    GLfloat getPlayerXloc() { return loc.first; }
};


#endif //LAB32_PLAYER_H
