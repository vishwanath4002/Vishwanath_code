#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8091
#define BUFFER_SIZE 1024

int is_valid_email(const char* email) {
    // Check if email contains '@' and ends with ".com"
    if (strchr(email, '@') != NULL && strstr(email, ".com") != NULL) {
        return 1;
    }
    return 0;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];
    char recptemail[50];
    strcpy(recptemail, "server@gmail.com"); // Recipient email

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

    char email_data[BUFFER_SIZE]; // To store the message data
    int flag = 0;

    while (flag == 0) {
        // Receive message from client
        memset(buffer, 0, BUFFER_SIZE);
        recv(client_socket, buffer, BUFFER_SIZE, 0);
        printf("C: %s\n", buffer);

        // Handle HELO command
        if (strcmp(buffer, "HELO") == 0) {
            strcpy(buffer, "250");
            printf("S: %s\n", buffer);
            send(client_socket, buffer, strlen(buffer), 0);

            while (flag == 0) {
                memset(buffer, 0, BUFFER_SIZE);
                recv(client_socket, buffer, BUFFER_SIZE, 0);
				printf("C: %s\n", buffer);
				
                // Handle MAIL FROM command
                if (strncmp(buffer, "MAIL FROM:", 10) == 0) {
                    char* email = buffer + 11; // Email starts after "MAIL FROM: "

                    if (is_valid_email(email)) {
                        strcpy(buffer, "250");
                        printf("S: 250 OK\n");
                        send(client_socket, buffer, strlen(buffer), 0);
                    } else {
                        strcpy(buffer, "550 Invalid email address");
                        printf("S: %s\n", buffer);
                        send(client_socket, buffer, strlen(buffer), 0);
                        continue; // Skip further processing for invalid MAIL FROM
                    }
					while (flag == 0) {
		                // Handle RCPT TO command
		                memset(buffer, 0, BUFFER_SIZE);
		                recv(client_socket, buffer, BUFFER_SIZE, 0);
						printf("C:%s\n",buffer);
						
		                if (strncmp(buffer, "RCPT TO:", 8) == 0) {
		                    char* recipient_email = buffer + 9; // Email starts after "RCPT TO: "
		                    
		                    // Check if the recipient email matches the expected one
		                    if (strcmp(recipient_email, recptemail) == 10) {
		                        strcpy(buffer, "250");
		                        printf("S: 250 OK\n");
		                        send(client_socket, buffer, strlen(buffer), 0);
		                    } else {
		                        strcpy(buffer, "550 Recipient address rejected");
		                        printf("S: %s\n", buffer);
		                        send(client_socket, buffer, strlen(buffer), 0);
		                        continue; // Skip DATA and QUIT if recipient does not match
		                    }

		                    // Handle DATA command
		                    memset(buffer, 0, BUFFER_SIZE);
		                    recv(client_socket, buffer, BUFFER_SIZE, 0);

		                    if (strcmp(buffer, "DATA") == 0) {
		                        strcpy(buffer, "354");
		                        printf("S: 354 End message with .\n");
		                        send(client_socket, buffer, strlen(buffer), 0);

		                        // Receive email data (message body)
		                        memset(email_data, 0, BUFFER_SIZE); // Clear the email data buffer
		                        while (1) {
		                            memset(buffer, 0, BUFFER_SIZE);
		                            recv(client_socket, buffer, BUFFER_SIZE, 0);
		                            printf("C: %s", buffer);

		                            // Store email body part
		                            strcat(email_data, buffer);

		                            // End of message when client sends a single dot
		                            if (strcmp(buffer, ".\n") == 0) {
		                                strcpy(buffer, "250");
		                                printf("S: %s\n", buffer);
		                                send(client_socket, buffer, strlen(buffer), 0);
		                                break;
		                            }
		                        }

		                        // Handle QUIT command
		                        memset(buffer, 0, BUFFER_SIZE);
		                        recv(client_socket, buffer, BUFFER_SIZE, 0);
		                        if (strcmp(buffer, "QUIT") == 0) {
		                            strcpy(buffer, "221");
		                            printf("S: 221 Bye\n");
		                            send(client_socket, buffer, strlen(buffer), 0);
		                            flag = 1; // Exit loop and close connection
		                        }
		                    }
		                }
		            }
                }
            }
        }
    }

    // Print the received email data after client disconnects
    printf("\nReceived Email Data:\n%s\n", email_data);

    close(server_socket);
    close(client_socket);
    return 0;
}

