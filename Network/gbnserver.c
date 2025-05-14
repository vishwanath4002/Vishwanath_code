#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8091
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];
    int received[20];
    int packs = 0;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(server_socket, 5);
    printf("Server listening on port %d...\n", PORT);

    // Accept a connection from a client
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
    if (client_socket == -1) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Receive message from client
        
        //recv(client_socket, buffer, BUFFER_SIZE, 0);

        //printf("Client: %s", buffer);

        // Send response to the client
        //printf("Server: ");
        //fgets(buffer, BUFFER_SIZE, stdin);
        //send(client_socket, buffer, strlen(buffer), 0);
        
        memset(buffer, 0, BUFFER_SIZE);
        while (1)
        {
        	sleep(0.5);
        	memset(buffer, BUFFER_SIZE, 0);
        	recv(client_socket, buffer, BUFFER_SIZE, 0);
        	
        	int ack_decision = rand() % 2; // Randomly choose 0 (NACK) or 1 (ACK)
            if (ack_decision == 1)
            {
            	printf("\nRecieved packet seqnum %s", buffer);
                printf("\nServer: Sending ACK.\n");
                send(client_socket, buffer , BUFFER_SIZE, 0);
                received[packs] = packs;
                packs++;
            }
            else
            {
                printf("Server: No ACK sent (simulating loss).\n");
            }
        }
    }
    printf("\nPackets received : ");
	for (int i = 0; i<packs; i++)
	{
		printf("\n%d", received[i]);
	}
	printf("\n");
	
    close(server_socket);
    close(client_socket);
    return 0;
}

