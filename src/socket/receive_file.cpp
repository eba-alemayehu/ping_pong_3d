//
// Created by eba on 02/12/2019.
//

#include "../../headers/socket/receive_file.h"
#include "../../headers/socket/common.h"

void receive_file(int port){
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
    ifErr((listen(sockfd, LINSTENPORT) == -1) ,"Couldn't listen to the port!");

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

        memset(buff, 0, MAX_LINE);

        printf("data recived \n");
    }
//    printf("Recived %s (%s) from %s \n", filename, formatedSize(total), inet_ntop(AF_INET, &clientaddr.sin_addr, addr, INET_ADDRSTRLEN));
//    printf("*********************************************************\n\n");

    close(connfd);
}