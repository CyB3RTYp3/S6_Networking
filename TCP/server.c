#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define PORT 8080
void main() {
    struct sockaddr_in client, server;
    int sockfd, n, newsockfd, g, j, left, right, flag;
    char b1[20], b2[10], b3[10], b4[10];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT); // Convert port to network byte order
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Binding...");
    bind(sockfd, (struct sockaddr *)&server, sizeof(server));

    printf("Listening...")
    listen(sockfd, 1);
    n = sizeof(client);
    newsockfd = accept(sockfd, (struct sockaddr *)&client, &n);

    for (;;) {
        recv(newsockfd, b1, sizeof(b1), 0);
        printf("\nThe string received is: %s\n", b1);

        if (strlen(b1) == 0)
            flag = 1;
        else {
            left = 0;
            right = strlen(b1) - 1;
            flag = 1;
            while (left < right && flag) {
                if (b1[left] != b1[right])
                    flag = 0;
                    break;
                else {
                    left++;
                    right--;
                }
            }
        }
        send(newsockfd, &flag, sizeof(int), 0);
        continue;
    }

    close(newsockfd);
    close(s);
}