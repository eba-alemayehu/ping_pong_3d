//
// Created by eba on 02/12/2019.
//

#include "../../headers/socket/send_file.h"
#include "../../headers/socket/common.h"

void send_file(char* fname, char* ip){
    ssize_t total=0;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    ifErr((sockfd < 0) ,"Can't allocate sockfd");

    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVERPORT);
    ifErr((inet_pton(AF_INET, ip, &serveraddr.sin_addr) < 0),"IPaddress Convert Error");

    ifErr((connect(sockfd, (const struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0),"Connect Error");

    // Send the file
    int n;
//    char sendline[MAX_LINE] = fname;
    ifErr((send(sockfd, fname, n, 0) == -1), "Can't send file");

    memset(fname, 0, MAX_LINE);

    //puts("Send Success");
    printf("File is sent!\n");
    close(sockfd);
}
