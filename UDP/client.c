#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <netdb.h>
#include <unistd.h>
#define PORT 8080

int main(){

    struct sockaddr_in serveraddr;
    int serversocket;
    socklen_t len;
    char b1[20];

    serversocket = socket(AF_INET,SOCK_DGRAM,0);
    bzero((char*)&serveraddr,sizeof(serveraddr));

    len=sizeof(serveraddr);
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);

    sendto(serversocket,"hi rohan",sizeof("hi rohan"),0,(struct sockaddr*)&serveraddr,len);
    recvfrom(serversocket,b1,sizeof(b1),0,(struct sockaddr*)&serveraddr,&len);
    printf("%s",b1);

    close(serversocket);
}
