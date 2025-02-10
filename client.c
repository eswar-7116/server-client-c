#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define HOST "127.0.0.1"
#define PORT 8000
#define BUFF_SIZE 1024

int main()
{
    // Create client socket
    int client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sockfd < 0)
    {
        perror("Error creating client socket\n");
        return -1;
    }

    // Create address of server socket
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, HOST, &addr.sin_addr);
    int addr_len = sizeof(addr);

    // Connect to server socket
    int connection = connect(client_sockfd, (struct sockaddr *)&addr, addr_len);
    if (connection < 0)
    {
        perror("Error while connecting to server\n");
        return -1;
    }

    // Read msg as buff (char array)
    char buff[BUFF_SIZE];
    int n = read(client_sockfd, buff, BUFF_SIZE);
    if (n < 0)
    {
        perror("Error reading message\n");
        return -1;
    }
    buff[n] = '\0'; // Terminate char array with null character(\0) to make it a string
    printf("Server: %s\n", buff);

    // Close client socket
    close(client_sockfd);
    return 0;
}