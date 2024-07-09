#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<strings.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8080
int main(){

    int serversocket;
    struct sockaddr_in serveradr,clientaddr;
    char msg[20];
    socklen_t len;

    serversocket = socket(AF_INET,SOCK_DGRAM,0);
    serveradr.sin_family=AF_INET;
    serveradr.sin_port=htons(PORT);
    serveradr.sin_addr.s_addr=INADDR_ANY;

    bind(serversocket,(struct sockaddr*)&serveradr,sizeof(serveradr));

    printf("LIstening");
    len=sizeof(clientaddr);

    recvfrom(serversocket,msg,sizeof(msg),0,(struct sockaddr*)&clientaddr,&len);
    printf("%s",msg);
    sendto(serversocket,"kitti tayoli",sizeof("kitti tayoli"),0,(struct sockaddr*)&clientaddr,len);
    

    close(serversocket);

}