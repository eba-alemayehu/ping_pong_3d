//
// Created by eba on 12/01/2020.
//

#ifndef LAB32_SOCKET_H
#define LAB32_SOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_LINE 4096
#define LINSTENPORT 3344
#define SERVERPORT 4433

class Socket {
private:
    static void ifErr(int chk, char* msg);
    int port;
    char* ip;
public:
    Socket(char* ip, int port);
    void listen(void (* callback)(char*));
    void send(char* data);
};


#endif //LAB32_SOCKET_H
