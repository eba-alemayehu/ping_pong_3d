//
// Created by eba on 12/01/2020.
//

#include "../headers/Socket.h"

void Socket::ifErr(int chk, char *msg) {
    if (chk)
    {
        perror(msg);
        exit(1);
    }
}

Socket::Socket(char *ip, int port) {
    this->ip = ip;
    this->port = port;
}

void Socket::listen(void (*callback)(char *)) {
    ssize_t total=0;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    ifErr((sockfd == -1), "Failed to get sockfd");


    struct sockaddr_in clientaddr, serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(port);

    ifErr((bind(sockfd, (const struct sockaddr *) &serveraddr, sizeof(serveraddr)) == -1),"Faild to bind");

    printf("Waiting to recive file on port %i ... \n", port);
    ifErr((::listen(sockfd, this->port ) == -1) ,"Couldn't listen to the port!");

    socklen_t addrlen = sizeof(clientaddr);
    int connfd = accept(sockfd, (struct sockaddr *) &clientaddr, &addrlen);
    ifErr((connfd == -1) ,"Failed to connect");

    close(sockfd);

    char addr[INET_ADDRSTRLEN];
    printf("\nReciving file...\n");
    // Write file
    ssize_t n;
    char buff[MAX_LINE] = {0};
    while ((n = recv(connfd, buff, MAX_LINE, 0)) > 0)
    {
        total+=n;
        ifErr((n == -1), "Couldn't recive the file");
        callback(buff);
    }
//    printf("Recived %s (%s) from %s \n", filename, formatedSize(total), inet_ntop(AF_INET, &clientaddr.sin_addr, addr, INET_ADDRSTRLEN));
//    printf("*********************************************************\n\n");

    close(connfd);
}

void Socket::send(char *data) {
    ssize_t total=0;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    ifErr((sockfd < 0) ,"Can't allocate sockfd");

    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(this->port);
    ifErr((inet_pton(AF_INET, this->ip, &serveraddr.sin_addr) < 0),"IPaddress Convert Error");

    ifErr((connect(sockfd, (const struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0),"Connect Error");

    // Send the file
    int n;
    ifErr((::send(sockfd, data, n, 0) == -1), "Can't send file");

    printf("File is sent!\n");
    close(sockfd);
}
