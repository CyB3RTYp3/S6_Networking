#include <sys/types.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>

#define PORT 8080
int main(){

    int clientsocket,serversocket;
    struct sockaddr_in serveraddr,clientaddr;
    char b1[20];
    socklen_t len;

    serversocket=socket(AF_INET,SOCK_STREAM,0);
    bzero((char*)&serveraddr,sizeof(serveraddr));
    
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    serveraddr.sin_addr.s_addr=INADDR_ANY;

    bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    bzero((char*)&clientaddr,sizeof(clientaddr));
    len=sizeof(clientaddr);
    listen(serversocket,5);

    printf("Waiting----\n");
    clientsocket=accept(serversocket,(struct sockaddr*)&clientaddr,&len);

    recv(clientsocket,b1,sizeof(b1),0);
    printf("%s\n",b1);

    send(clientsocket,"kitti monne",sizeof("kitti monne"),0);

    close(clientsocket);
    close(serversocket);
}