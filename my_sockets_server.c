#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Refer to socket.txt 

int main () 
{
    char buf[100] = "hello, World!";
    int server_socket;
    // create a server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    // Port to connect to
    server_address.sin_port = htons(9001);
    // actual address of the peer
    server_address.sin_addr.s_addr = INADDR_ANY; // connects to local host


    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Server bind failed\n");
    }

    listen(server_socket, 5);

    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);
    send(client_socket, buf, 13, 0);
    close(server_socket);

    return (0);
}