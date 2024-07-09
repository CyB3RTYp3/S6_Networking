#include<stdio.h>
#include<unistd.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<strings.h>
#include <time.h>

#define PORT 8080

int main(){

    struct sockaddr_in serveraddr,clientaddr;
    int serversocket,m;
    socklen_t len;
    time_t currTime;

    serversocket = socket(AF_INET,SOCK_DGRAM,0);
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    serveraddr.sin_addr.s_addr=INADDR_ANY;

    bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));

    printf("Listening...\n");
    len=sizeof(clientaddr);

    recvfrom(serversocket,&m,sizeof(m),0,(struct sockaddr*)&clientaddr,&len);
    currTime=time(NULL);
    sendto(serversocket,&currTime,sizeof(currTime),0,(struct sockaddr*)&clientaddr,len);

    close(serversocket);

}