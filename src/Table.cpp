//
// Created by eba on 07/01/2020.
//

#include <cstring>
#include <vector>
#include "../headers/Table.h"

void Table::render() {
    // Tickness of the table
    glBegin(GL_QUAD_STRIP);
        GLfloat tickness = 0.12;

        glColor3f(0.8f, 0.8f, 0.8f);     // Blue
        glVertex3f(-1*(this->width/2.0), this->elivation, this->length/2.0);
        glVertex3f(-1*(this->width/2.0), this->elivation - tickness, this->length/2.0);
        glVertex3f( this->width/2.0 + 0.02, this->elivation, this->length/2.0);
        glVertex3f( this->width/2.0 + 0.02, this->elivation - tickness, this->length/2.0);

        glVertex3f( this->width/2.0 + 0.02, this->elivation , -1 * this->length/2.0);
        glVertex3f( this->width/2.0 + 0.02, this->elivation - tickness, -1 * this->length/2.0);

        glVertex3f( -1* this->width/2.0 + 0.02, this->elivation , -1 * this->length/2.0);
        glVertex3f( -1* this->width/2.0 + 0.02, this->elivation - tickness, -1 * this->length/2.0);

        glVertex3f(-1*(this->width/2.0), this->elivation, this->length/2.0);
        glVertex3f(-1*(this->width/2.0), this->elivation - tickness, this->length/2.0);
    glEnd();

    // Front face of the table
    glBegin(GL_QUADS);
        glColor3f(0.1f, 0.8f, 0.2f);     // Blue
        glVertex3f( this->width/2.0, this->elivation - 0.01,  this->length/2.0);
        glVertex3f(-1*(this->width/2.0) , this->elivation - 0.01,  this->length/2.0);
        glVertex3f(-1*(this->width/2.0), this->elivation - 0.01, -1*this->length/2.0);
        glVertex3f( this->width/2.0, this->elivation - 0.01, -1*this->length/2.0);
    glEnd();

    // border line of the table
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(5);
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);     // Blue
        glVertex3f( this->width/2.0, this->elivation,  this->length/2.0);
        glVertex3f(-1*(this->width/2.0) , this->elivation,  this->length/2.0);
        glVertex3f(-1*(this->width/2.0), this->elivation, -1*this->length/2.0);
        glVertex3f( this->width/2.0, this->elivation, -1*this->length/2.0);
    glEnd();

    // Center cross sesction line
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);     // Blue
        glVertex3f( 0.0, this->elivation,  this->length/2.0);
        glVertex3f(0.0 , this->elivation,  -1*this->length/2.0);
    glEnd();

    // Teble divider
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
        GLfloat net_height = 0.5f;
        GLfloat net_elevation = 0.1f;

        glColor3f(0.7f, 0.7f, 0.7f);     // Blue
        glVertex3f( this->width/2.0 + 0.1, this->elivation + net_height, 0.0f);
        glVertex3f( this->width/2.0 + 0.1, this->elivation + net_elevation,  0.0f);
        glVertex3f(-1*(this->width/2.0) - 0.1, this->elivation + net_elevation,  0.0f);
        glVertex3f(-1*(this->width/2.0) - 0.1, this->elivation + net_height, 0.0f);

    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1*(this->width/2.0) - 0.1, this->elivation + net_height, 0.0f);
        glVertex3f( this->width/2.0 + 0.1, this->elivation + net_height, 0.0f);
    glEnd();
    glLineWidth(5);
    // Table divider net
    glLineWidth(1);
    glBegin(GL_LINES);
        glColor3f(0.3f, 0.3f, 0.3f);
        GLfloat number_of_net = 60.0f;
        GLfloat net_width = this->width / number_of_net;
        GLfloat start = -1 * this->width / 2.0;
        for(GLint i = -1; i <= number_of_net+1; i++){
            GLfloat x = start + (net_width * (GLfloat)i);
            glVertex3f(x, this->elivation + net_elevation + 0.02, 0.0f);
            glVertex3f(x, this->elivation + net_height - 0.02, 0.0f);
        }
        number_of_net = 6.0f;
        net_width = ((this->elivation + net_height) - (this->elivation + net_elevation)) / number_of_net;
        start =(this->elivation + net_elevation);
        for(GLint i = 1; i < number_of_net; i++){
            GLfloat x = start + (net_width * (GLfloat)i);
            glVertex3f(this->width/2.0 + net_width , x, 0.0f);
            glVertex3f(-1*(this->width/2.0) - net_width, x, 0.0f);
        }
    glEnd();

        // Table back face
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
        glColor3f(0.1f, 0.5f, 0.2f);     // Blue
        glVertex3f( this->width/2.0, this->elivation - tickness,  this->length/2.0);
        glVertex3f(-1*(this->width/2.0) , this->elivation - tickness,  this->length/2.0);
        glVertex3f(-1*(this->width/2.0), this->elivation - tickness, -1*this->length/2.0);
        glVertex3f( this->width/2.0, this->elivation - tickness, -1*this->length/2.0);
    glEnd();
    // Legs
    glLineWidth(11);
    glBegin(GL_LINES);
        GLfloat leg_length = 2.0f, len_padding = 0.5f;
        glColor3f(0.9f, 0.9f, 0.9f);     // Blue
        // Leges
        glVertex3f( this->width/2.0- len_padding, this->elivation - tickness,  this->length/2.0 - len_padding);
        glVertex3f( this->width/2.0- len_padding, this->elivation - tickness - leg_length,  this->length/2.0 - len_padding);

        glVertex3f(-1*(this->width/2.0) + len_padding , this->elivation - tickness,  this->length/2.0 - len_padding);
        glVertex3f(-1*(this->width/2.0) + len_padding , this->elivation - tickness - leg_length,  this->length/2.0 - len_padding);

        glVertex3f(-1*(this->width/2.0) + len_padding, this->elivation - tickness, -1*this->length/2.0 + len_padding);
        glVertex3f(-1*(this->width/2.0) + len_padding, this->elivation - tickness - leg_length, -1*this->length/2.0 + len_padding);


        glVertex3f( this->width/2.0 - len_padding, this->elivation - tickness, -1*this->length/2.0 + len_padding);
        glVertex3f( this->width/2.0 - len_padding, this->elivation - tickness - leg_length, -1*this->length/2.0 + len_padding);
         // rectangle
        glVertex3f( this->width/2.0- len_padding, this->elivation - tickness ,  this->length/2.0 - len_padding);
        glVertex3f( this->width/2.0 - len_padding, this->elivation - tickness , -1*this->length/2.0 + len_padding);

        glVertex3f(-1*(this->width/2.0) + len_padding , this->elivation - tickness ,  this->length/2.0 - len_padding);
        glVertex3f(-1*(this->width/2.0) + len_padding, this->elivation - tickness , -1*this->length/2.0 + len_padding);

        glVertex3f(-1*(this->width/2.0) + len_padding, this->elivation - tickness , -1*this->length/2.0 + len_padding);
        glVertex3f( this->width/2.0 - len_padding, this->elivation - tickness , -1*this->length/2.0 + len_padding);


        glVertex3f( this->width/2.0- len_padding, this->elivation - tickness,  this->length/2.0 - len_padding);
        glVertex3f(-1*(this->width/2.0) + len_padding , this->elivation - tickness,  this->length/2.0 - len_padding);
        // Cross connector lines
       glVertex3f((-1*(this->width/2.0) + len_padding) * (1/2) , (this->elivation - tickness - leg_length) * (4 / 5),  this->length/2.0 - len_padding);
        glVertex3f((-1*(this->width/2.0) + len_padding) * (1/2), (this->elivation - tickness - leg_length) * (4 / 5), -1*this->length/2.0 + len_padding);

        glVertex3f(-1*(this->width/2.0) + len_padding, (this->elivation - tickness - leg_length) * (4 / 5), -1*this->length/2.0 + len_padding);
        glVertex3f( this->width/2.0 - len_padding, (this->elivation - tickness - leg_length) * (4 / 5), -1*this->length/2.0 + len_padding);

        glVertex3f( this->width/2.0- len_padding, (this->elivation - tickness - leg_length) * (4 / 5),  this->length/2.0 - len_padding);
        glVertex3f(-1*(this->width/2.0) + len_padding , (this->elivation - tickness - leg_length) * (4 / 5),  this->length/2.0 - len_padding);

        // center crosser
        glColor3f(0.4, 0.4, 0.4);
        glVertex3f(-1*(this->width/2.0)  - 0.25, this->elivation - tickness , 0.0);
        glVertex3f( this->width/2.0  + 0.25, this->elivation - tickness , 0.0);

        glVertex3f(-1*(this->width/2.0)  - 0.25, this->elivation  + tickness + net_height , 0.0);
        glVertex3f( -1*(this->width/2.0)  - 0.25, this->elivation - tickness , 0.0);

        glVertex3f(this->width/2.0 + 0.25, this->elivation  + tickness + net_height , 0.0);
        glVertex3f( this->width/2.0  + 0.25, this->elivation - tickness , 0.0);
        // net connector
        glEnd();
    glLineWidth(2);

    glBegin(GL_LINES);
            glColor3f(0.2, 0.2, 0.2);
            glVertex3f(-1*(this->width/2.0)  - 0.25, this->elivation  + tickness + net_height , 0.0);
            glVertex3f(-1*(this->width/2.0) - 0.1, this->elivation + net_height, 0.0f);

            glVertex3f( -1*(this->width/2.0)  - 0.25, this->elivation - tickness , 0.0);
            glVertex3f(-1*(this->width/2.0) - 0.1, this->elivation + net_elevation,  0.0f);

            glVertex3f(this->width/2.0 + 0.25, this->elivation  + tickness + net_height , 0.0);
            glVertex3f( this->width/2.0 + 0.1, this->elivation + net_height, 0.0f);

            glVertex3f( this->width/2.0  + 0.25, this->elivation - tickness , 0.0);
            glVertex3f( this->width/2.0 + 0.1, this->elivation + net_elevation,  0.0f);

    glEnd();
    glColor3fv(new GLfloat[3]{0.90980392156, 0.48235294117, 0.26274509803});
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
    glColor3fv(new GLfloat[3]{0.1, 0.32176470588, 0.86274509803});
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
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos3f(this->width/2.0+0.5, this->elivation + net_elevation, 0);
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


