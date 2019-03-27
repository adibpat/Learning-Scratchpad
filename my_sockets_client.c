#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Refer to socket.txt 

int main () 
{
    int network_socket;
    // create a socket
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    // Port to connect to
    server_address.sin_port = htons(9001);
    // actual address of the peer
    server_address.sin_addr.s_addr = INADDR_ANY; // connects to local host

    if (connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0 ) {
        printf("Connection to server failed\n");
    }

    // buffer for storing received data
    char buf[100];
    recv(network_socket, buf, sizeof(buf), 0 /* FLAGS */);

    printf("Data received : %s\n", buf);
    close(network_socket);

    return (0);
}