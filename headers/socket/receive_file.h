//
// Created by eba on 02/12/2019.
//

#ifndef FINAL_RECEIVE_FILE_H
#define FINAL_RECEIVE_FILE_H

#define MAX_LINE 4096
#define LINSTENPORT 7788
#define SERVERPORT 8877
#define BUFFSIZE 4096

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "common.h"

void receive_file();

#endif //FINAL_RECEIVE_FILE_H
