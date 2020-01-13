//
// Created by eba on 07/01/2020.
//

#include <cstring>
#include "../headers/Table.h"

void Table::render() {
    glBegin(GL_QUADS);
        glColor3f(0.1f, 6.0f, 0.2f);     // Blue
        glVertex3f( this->width/2.0, this->elivation,  this->length/2.0);
        glVertex3f(-1*(this->width/2.0) , this->elivation,  this->length/2.0);
        glVertex3f(-1*(this->width/2.0), this->elivation, -1*this->length/2.0);
        glVertex3f( this->width/2.0, this->elivation, -1*this->length/2.0);
    glEnd();

    glRasterPos3f(this->width/2.0+0.3, this->elivation, this->length/2.5);

    if(this->score_player1 == 0) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
    else{
        GLint score = this->score_player1;
        string score_txt = "";
        while (score != 0) {
            score_txt += '0' + (score % 10);
            score = score / 10;
        }
        for(int i = strlen(score_txt.c_str()); i >= 0;  i--)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score_txt[i]);
    }

    glRasterPos3f(this->width/2.0+0.3, this->elivation, -1*this->length/2.5);
    if(this->score_player2 == 0) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
    else {
        GLint score = this->score_player2;
        string score_txt = "";
        while (score != 0) {
            score_txt += '0' + (score % 10);
            score = score / 10;
        }
        for(int i = strlen(score_txt.c_str()); i >= 0; i--)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score_txt[i]);
    }

    glRasterPos3f(this->width/2.0+0.3, this->elivation, 0);
    string time_str = "";
    while (time != 0) {
        time_str += '0' + (time % 10);
        time = time / 10;
    }
    for(int i = strlen(time_str.c_str()); i >= 0; i--)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, time_str[i]);

}

Table::Table(GLfloat width, GLfloat length, GLfloat elivation) {
    this->width = width;
    this->length = length;
    this->elivation = elivation;

    this->score_player1 = 0;
    this->score_player2 = 0;
    this->time = 0;
}

void Table::reset() {
    this->score_player1 = 0;
    this->score_player2 = 0;
    this->time = 0;
}
