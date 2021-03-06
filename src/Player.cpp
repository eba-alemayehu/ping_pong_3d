//
// Created by eba on 07/01/2020.
//

#include "../headers/Player.h"

Player::Player(pair<GLfloat, GLfloat> loc, GLfloat width, GLfloat tickness, GLfloat elevation, GLfloat table_width) {
    this->loc = loc;
    this->width = width;
    this->tickness = tickness;
    this->elevation = elevation;
    this->table_width = table_width;
}

void Player::render(GLfloat* color) {
    GLfloat height = 0.1;
    glBegin(GL_QUADS);
        glColor3fv(color); //blue
        glVertex3f( this->width/2 + loc.first, elevation + height, this->tickness/2 + loc.second);
        glVertex3f( loc.first - this->width/2 , elevation + height, this->tickness/2 + loc.second);
        glVertex3f( loc.first - this->width/2, elevation + height, loc.second - this->tickness/2 );
        glVertex3f( this->width/2 + loc.first, elevation + height, loc.second - this->tickness/2 );
    glEnd();

    glBegin(GL_QUAD_STRIP);
    color[0] -= 0.1;
    color[1] -= 0.1;
    color[2] -= 0.1;
    glColor3fv(color); //blue
    glVertex3f( this->width/2 + loc.first, elevation + height, this->tickness/2 + loc.second);
    glVertex3f( this->width/2 + loc.first, elevation, this->tickness/2 + loc.second);

    glVertex3f( loc.first - this->width/2 , elevation + height, this->tickness/2 + loc.second);
    glVertex3f( loc.first - this->width/2 , elevation , this->tickness/2 + loc.second);

    glVertex3f( loc.first - this->width/2, elevation + height, loc.second - this->tickness/2 );
    glVertex3f( loc.first - this->width/2, elevation, loc.second - this->tickness/2 );

    glVertex3f( this->width/2 + loc.first, elevation + height, loc.second - this->tickness/2 );
    glVertex3f( this->width/2 + loc.first, elevation, loc.second - this->tickness/2 );
    glColor3f(1.0, 0.0, 0.0);

    glEnd();
}

void Player::update(bool right, bool left) {
    if(right && this->loc.first+this->width/2 <= this->table_width/2) this->loc.first += speed;
    else if(left && this->loc.first-this->width/2 > -1*this->table_width/2) this->loc.first -= speed;
    glutPostRedisplay();
}
