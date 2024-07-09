#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h> // Include for strcmp()

int main()
{
    struct sockaddr_in sever;
    int sockfd, flag;
    char buffer[20], response[2]; // Change response size to hold single character

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char*)&serveraddr,sizeof(serveraddr));
    sever.sin_family = AF_INET;
    sever.sin_port = htons(8080); // Use htons() to convert port to network byte order
    sever.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr *)&sever, sizeof(sever));

    do { // Loop until user inputs '0' (no)
        printf("\nEnter a string to check palindrome: ");
        scanf("%s", buffer);
        printf("\nClient: %s", buffer);
        send(sockfd, buffer, sizeof(buffer), 0);
        recv(sockfd, &flag, sizeof(int), 0);
        if (flag == 1) {
            printf("\nServer: the string is a palindrome.\n");
        } else {
            printf("\nServer: the string is not a palindrome.\n");
        }
        printf("Do you want to continue? (1 for yes, 0 for no): ");
        scanf("%s", response);
    } while (response[0] == '1'); // Loop until user inputs '0' (no)

    close(sockfd);
    return 0;
}
