#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8091
#define BUFFER_SIZE 1024

void receive_file(int client_socket, char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        perror("Error creating file");
        return;
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        recv(client_socket, buffer, BUFFER_SIZE, 0);
        
        if (strcmp(buffer, "EOF") == 0) {
            break;
        }

        fputs(buffer, file);
    }

    fclose(file);
    printf("File '%s' received and saved successfully.\n", filename);

    // Display the file contents
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    printf("File contents:\n");
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Enter command (PWD, LIST, RETR, exit): ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send command to server
        send(client_socket, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        // Handle RETR separately to get filename
        if (strcmp(buffer, "RETR\n") == 0) {
            memset(buffer, 0, BUFFER_SIZE);
            recv(client_socket, buffer, BUFFER_SIZE, 0);
            printf("S: %s", buffer);

            // Get filename from user
            fgets(buffer, BUFFER_SIZE, stdin);
            send(client_socket, buffer, strlen(buffer), 0);

            // Receive and save the file
            buffer[strcspn(buffer, "\n")] = 0;
            receive_file(client_socket, buffer);
        } else {
            // Receive and display server response
            memset(buffer, 0, BUFFER_SIZE);
            recv(client_socket, buffer, BUFFER_SIZE, 0);
            printf("Server: %s\n", buffer);
        }
    }

    close(client_socket);
    return 0;
}

