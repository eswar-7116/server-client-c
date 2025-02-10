#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8000

int main()
{
    // Create server socket
    int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock_fd < 0)
    {
        perror("Error creating server socket\n");
        return -1;
    }

    // Create socket address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    int addr_len = sizeof(addr);

    // Bind socket to the address
    int isBound = bind(server_sock_fd, (struct sockaddr *)&addr, addr_len);
    if (isBound < 0)
    {
        perror("Error binding server socket\n");
        return -1;
    }

    // Listen for connections
    int isListening = listen(server_sock_fd, 2);
    if (isListening < 0)
    {
        perror("Error listening server socket\n");
        return -1;
    }
    printf("Listening on port 8000\n");

    while (1)
    {
        // Accept new connections, if any
        int new_sock_conn = accept(server_sock_fd, (struct sockaddr *)&addr, &addr_len);
        if (new_sock_conn < 0)
        {
            perror("Error accepting connection\n");
            return -1;
        }

        // Send msg to the freshly connected client
        const char *msg = "Hello from server";
        ssize_t bytes_sent = send(new_sock_conn, msg, strlen(msg), 0);
        if (bytes_sent < 0)
        {
            perror("Error messaging client\n");
            return -1;
        }
        printf("%ld bytes sent to client\n", bytes_sent);

        // Close connected socket
        close(new_sock_conn);
    }

    // Close server socket
    close(server_sock_fd);
    return 0;
}