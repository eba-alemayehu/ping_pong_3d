//
// Created by eba on 02/12/2019.
//
#include <stdio.h>
#include <stdlib.h>

#include "../../headers/socket/common.h"

void ifErr(int chk, char* msg){
    if (chk)
    {
        perror(msg);
        exit(1);
    }
}