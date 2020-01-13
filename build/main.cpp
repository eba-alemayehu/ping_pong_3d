//
// Created by eba on 12/01/2020.
//

#include <iostream>
#include "headers/Socket.h"

using namespace std;
void listen(char* x){
    cout << x << endl;
}
int main(){
    Socket* socket = new Socket("localhost", 5566);
    cout << "Recive..." <<endl;
    socket->listen(listen);
}