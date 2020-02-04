#include <iostream>
#include <cmath>
#include "headers/Window.h"
#include "headers/Table.h"
#include "headers/Ball.h"
#include "headers/Player.h"

#define GAME_TIME 30
#define ENTER_KEY 13
#define ROTATE_UP 49
#define ROTATE_DOWN 113
#define ROTATE_X 120
#define ROTATE_Y 121
#define ROTATE_Z 122

const unsigned char PLAYER_1_RIGHT = 'l';
const unsigned char PLAYER_1_LEFT = 'j';
const unsigned char PLAYER_2_RIGHT = 'd';
const unsigned char PLAYER_2_LEFT = 'a';

using namespace std;
void addComponent(void);
void onResize(GLsizei w, GLsizei h);
void onUpdate(int fps);
void score(int player);
void onKey(unsigned char, int, int);
void onKeyUp(unsigned char, int, int);
void gameOver();
void onClick(int button, int state, int x, int y);

Window *win;
Table *table;
Ball *ball;
Player *player1;
Player *player2;

char* ip;
int port;

int player1_score = 0;
int player2_score = 0;

int frames = 0;
bool run = false;
string main_message = "";

bool z = false, y = false, x = false;

int main(int argc, char* argv[]){
    GLfloat player_thickness = 0.1;

    win = new Window(argc, argv, "Ping pong");
    table = new Table(4.0, 6.0, 1.0);
    ball = new Ball(0.2f , 0, 1.00001, 0, 0.5, player_thickness);


    player1 = new Player(pair<GLfloat ,GLfloat >(
                        0.0,
                        table->getLength()/2 - player_thickness/2),
                    0.5,
                        player_thickness,
                    1.00001,
                    table->getWidth());

    player2 = new Player(pair<GLfloat ,GLfloat >(0.0,-1 * table->getLength()/2 + player_thickness/2),
                         0.5,
                         player_thickness,
                         1.00001,
                         table->getWidth());

    win->setSize(600, 400);
    win->setPosition(100, 100);
    win->createWindow();
    win->onDisplay(addComponent);
    win->onResize(onResize);
    win->onUpdate(onUpdate);
    win->onKey(onKey);
    win->onKeyUp(onKeyUp);
    win->onClick(onClick);
    win->show();
}
void addComponent(void){
    win->displayInit();

    table->render();
    ball->render();
    player1->render(new GLfloat[3]{0.90980392156, 0.48235294117, 0.26274509803});
    player2->render(new GLfloat[3]{0.1, 0.32176470588, 0.86274509803});
    win->render();

    glutSwapBuffers();
}
void onResize(GLsizei w, GLsizei h){
    win->onResize(w, h);
}
void onUpdate(int fps){

    if(run){
        win->setMainMessage("");
        ball->update(table->getWidth(), table->getLength(), player1->getPlayerXloc(), player2->getPlayerXloc(), score);
        int elapsed_sec = floor(frames++ / (1000/ fps));
        table->setTime(elapsed_sec);
        if(elapsed_sec >= GAME_TIME){
            gameOver();
        }
    }

    glutTimerFunc(fps, onUpdate, fps);
}
void onClick(int button, int state, int x, int y)
{
    GLfloat axis[3] = {(GLfloat)::x,(GLfloat)::y,(GLfloat)::z};
    cout << (GLfloat)::x<<(GLfloat)::y<<(GLfloat)::z <<endl;
    switch(button){
        case 0: // left click
            win->zoom();
            break;
        case 2: // right click
            win->zoom(false);
            break;
        case 3: // wheel up
            if(::z){
                win->zoom();
            }else
                win->rotate(true, axis);
            break;
        case 4: // wheel down
            if(::z){
                win->zoom(false);
            }else
            win->rotate(false, axis);
            break;
    }
}
void onKey(unsigned char key, int x , int y){
    player1->update(key == PLAYER_1_RIGHT, key == PLAYER_1_LEFT);
    player2->update(key == PLAYER_2_RIGHT, key == PLAYER_2_LEFT);

    ::z = (ROTATE_Z == (int)key);
    ::y = (ROTATE_Y == (int)key);
    ::x = (ROTATE_X == (int)key);
    switch((int)key){
        case ENTER_KEY:
            run = !run;
            break;
        case ROTATE_UP:
            win->rotate();
            break;
        case ROTATE_DOWN:
            win->rotate(false);
            break;
    }
}
void onKeyUp(unsigned char key, int x , int y){
    ::z = false;
    ::y = false;
    ::x = false;
}
void score(int player){
    if(player == 1) {
        player2_score++;
        table->setScore_player2(player2_score);
    }else {
        player1_score++;
        table->setScore_player1(player1_score);
    }
    cout << player1_score << " , " << player2_score << endl;
    glutPostRedisplay();
}

void gameOver(){
    if(player1_score > player2_score){
        main_message = "Player 1 won!";
    }else if(player2_score > player1_score){
        main_message = "Player 2 won!";
    }else{
        main_message = "DRAW!";
    }
    run = false;
    frames = 0;
    player1_score = 0;
    player2_score = 0;
    ball->reset();
    table->reset();

    win->setMainMessage(main_message);
}