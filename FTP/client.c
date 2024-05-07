#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <arpa/inet.h>

#define PORT 5035
#define MAX 60
int main(int arg,char*argv[])
{
       int sockfd,n;
       struct sockaddr_in cli_addr;
       char send[MAX],recvline[MAX],s[MAX],name[MAX];

       sockfd=socket(AF_INET,SOCK_STREAM,0);
       cli_addr.sin_family=AF_INET;
       cli_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
       cli_addr.sin_port=htons(PORT);

       connect(sockfd,(struct sockaddr*)&cli_addr,sizeof(cli_addr));

       printf("\nEnter the source file name : \n");
       scanf("%s",send);
       write(sockfd,send,MAX);

       while((n=read(sockfd,recvline,MAX))!=0)
       {
          printf("%s",recvline);
       }

       close(sockfd);
       return 0;
}