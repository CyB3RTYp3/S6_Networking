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

    int serversocket,m;
    time_t currTime,rtt,start_time;
    struct sockaddr_in serveraddr;
    socklen_t len;

    serversocket =socket(AF_INET,SOCK_DGRAM,0);
    bzero((char*)&serveraddr,sizeof(serveraddr));
    
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    m=4;
    len=sizeof(serveraddr);
    start_time=time(NULL);
    sendto(serversocket,&m,sizeof(m),0,(struct sockaddr*)&serveraddr,len);
    recvfrom(serversocket,&currTime,sizeof(currTime),0,(struct sockaddr*)&serveraddr,&len);
    rtt=time(NULL)-start_time;
    currTime+=rtt/2;
    printf("Server time : %s",ctime(&currTime));
    close(serversocket);
}
