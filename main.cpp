#include <iostream>
#include <cmath>
#include "headers/Window.h"
#include "headers/Table.h"
#include "headers/Ball.h"
#include "headers/Player.h"
#include "headers/Socket.h"

#define GAME_TIME 5
#define ENTER_KEY 13

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
void gameOver();

Window *win;
Table *table;
Ball *ball;
Player *player1;
Player *player2;
Socket *sock;

char* ip;
int port;

int player1_score = 0;
int player2_score = 0;

int frames = 0;
bool run = false;
string main_message = "";

int main(int argc, char* argv[]){
    GLfloat player_thickness = 0.1;

    win = new Window(argc, argv, "Ping pong");
    table = new Table(4.0, 6.0, 1.0);
    ball = new Ball(0.2f , 0, 1.00001, 0, 0.5, player_thickness);
    sock = new Socket(ip, port);
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
    win->show();
}
void addComponent(void){
    win->displayInit();

    table->render();
    ball->render();
    player1->render();
    player2->render();
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
void onKey(unsigned char key, int x , int y){
    player1->update(key == PLAYER_1_RIGHT, key == PLAYER_1_LEFT);
    player2->update(key == PLAYER_2_RIGHT, key == PLAYER_2_LEFT);
    if((int)key == ENTER_KEY)
        run = !run;
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
    run = false;
    frames = 0;
    player1_score = 0;
    player2_score = 0;
    ball->reset();
    table->reset();

    if(player1_score > player2_score){
        main_message = "Player 1 won!";
    }else if(player2_score > player1_score){
        main_message = "Player 2 won!";
    }else{
        main_message = "DRAW!";
    }
    win->setMainMessage(main_message);
}