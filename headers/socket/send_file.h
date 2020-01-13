//
// Created by eba on 02/12/2019.
//

#ifndef FINAL_SEND_FILE_H
#define FINAL_SEND_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "common.h"

#define MAX_LINE 4096
#define SERVERPORT 8877
#define BUFFSIZE 4096

void send_file(char* fname, char* ip);

#endif //FINAL_SEND_FILE_H
