#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <sys/stat.h>

#define PORT 8091
#define BUFFER_SIZE 1024

int connected = 1;

void handle_pwd(int client_socket) {
    char cwd[BUFFER_SIZE];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        send(client_socket, cwd, strlen(cwd), 0);
    } else {
        perror("Error getting current directory");
        send(client_socket, "Error retrieving directory", 26, 0);
    }
}

void handle_list(int client_socket) {
    DIR *dir;
    struct dirent *entry;
    char buffer[BUFFER_SIZE] = {0};

    dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        send(client_socket, "Error listing directory", 24, 0);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only list regular files
            strcat(buffer, entry->d_name);
            strcat(buffer, "\n");
        }
    }
    closedir(dir);

    if (strlen(buffer) == 0) {
        strcpy(buffer, "No files found.\n");
    }
    send(client_socket, buffer, strlen(buffer), 0);
}

void handle_retr(int client_socket) {
    char filename[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    FILE *file;

    // Ask for filename
    send(client_socket, "Enter filename: ", 16, 0);
    recv(client_socket, filename, BUFFER_SIZE, 0);
    filename[strcspn(filename, "\n")] = 0; // Remove newline

    file = fopen(filename, "r");
    if (file == NULL) {
        send(client_socket, "Error: File not found", 21, 0);
        return;
    }

    // Send file contents
    printf("S: Sending file\n");
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        send(client_socket, buffer, strlen(buffer), 0);
    }
    fclose(file);

    // Indicate end of file
    send(client_socket, "EOF", 3, 0);
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        recv(client_socket, buffer, BUFFER_SIZE, 0);
		printf("C: %s",buffer);
		
        if (strcmp(buffer, "PWD\n") == 0) {
        	printf("S: Sending PWD\n");
            handle_pwd(client_socket);
        } else if (strcmp(buffer, "LIST\n") == 0) {
        	printf("S: Sending list of files in directory\n");
            handle_list(client_socket);
        } else if (strcmp(buffer, "RETR\n") == 0) {
        	printf("S: Asking for file name\n");
            handle_retr(client_socket);
        } else if (strcmp(buffer, "exit\n") == 0) {
            printf("Client disconnected.\n");
            connected = 0;
            break;
        } else {
            send(client_socket, "Invalid command\n", 16, 0);
        }
    }
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

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

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding to port");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept connections
    addr_size = sizeof(client_addr);
    while ((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size))) {
        if (client_socket == -1) {
            perror("Error accepting connection");
            continue;
        }
        printf("Client connected!\n");
        handle_client(client_socket);
        if (connected == 0)
        {
        	break;
        }
    }

    close(server_socket);
    return 0;
}

