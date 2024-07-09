#include<arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>

#define PORT 8080

int main(){

    struct sockaddr_in serveraddr;
    int clientsocket;
    char b1[20];

    clientsocket=socket(AF_INET,SOCK_STREAM,0);
    bzero((char*)&serveraddr,sizeof(serveraddr));

    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    printf("Connected....\n");

    send(clientsocket,"hi Rohan",sizeof("hi Rohan"),0);
    recv(clientsocket,b1,sizeof(b1),0);
    printf("\n message is %s",b1);
    close(clientsocket);
}