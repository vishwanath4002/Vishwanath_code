#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8091
#define BUFFER_SIZE 1024

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

    char email[25];	
    int flag = 0;
    
    // First loop to handle the conversation
    while (flag == 0) {
        // Send HELO
        printf("C: HELO\n");
        strcpy(buffer, "HELO");
        send(client_socket, buffer, strlen(buffer), 0);

        // Receive response from server
        memset(buffer, 0, BUFFER_SIZE);
        recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (strcmp("250", buffer) == 0) {
            printf("S: %s\n", buffer);
			
			do
            {
		        // Send MAIL FROM
		        memset(buffer, 0, BUFFER_SIZE);
		        strcpy(buffer, "MAIL FROM: ");
		        printf("C: MAIL FROM: ");
		        fgets(buffer + 11, BUFFER_SIZE - 11, stdin);  // Read the email after "MAIL FROM: "
		        send(client_socket, buffer, strlen(buffer), 0);

		        // Receive response from server
		        memset(buffer, 0, BUFFER_SIZE);
		        recv(client_socket, buffer, BUFFER_SIZE, 0);
		        if(strcmp(buffer, "250") == 0)
		        {
		        	break;
		        }
		    }while (strcmp(buffer, "550 Invalid email address") == 0);
		    
            if (strcmp("250", buffer) == 0) {
                printf("S: 250 OK\n");
				
				do
				{
		            // Send RCPT TO
		            memset(buffer, 0, BUFFER_SIZE);
		            strcpy(buffer, "RCPT TO: ");
		            printf("C: RCPT TO: ");
		            fgets(buffer + 9, BUFFER_SIZE - 9, stdin);
		            send(client_socket, buffer, strlen(buffer), 0);

		            // Receive response from server
		            memset(buffer, 0, BUFFER_SIZE);
		            recv(client_socket, buffer, BUFFER_SIZE, 0);
		            if(strcmp(buffer, "250") == 0)
				    {
				    	break;
				    }
		        }while(strcmp(buffer, "550 Recipient address rejected") == 0);
		        
                if (strcmp("250", buffer) == 0) {
                    printf("S: 250 OK\n");

                    // Send DATA command
                    memset(buffer, 0, BUFFER_SIZE);
                    strcpy(buffer, "DATA");
                    printf("C: DATA\n");
                    send(client_socket, buffer, BUFFER_SIZE, 0);

                    // Receive response from server
                    memset(buffer, 0, BUFFER_SIZE);
                    recv(client_socket, buffer, BUFFER_SIZE, 0);
                    if (strcmp("354", buffer) == 0) {
                        printf("S: 354 End message with .\n");

                        // Send email body
                        memset(buffer, 0, BUFFER_SIZE);
                        while (1) {
                            printf("C: ");
                            fgets(buffer, BUFFER_SIZE, stdin);
                            send(client_socket, buffer, strlen(buffer), 0);

                            // End message when client sends a single dot "."
                            if (strcmp(buffer, ".\n") == 0) {
                                break;
                            }
                        }

                        // Receive response from server after message sent
                        memset(buffer, 0, BUFFER_SIZE);
                        recv(client_socket, buffer, BUFFER_SIZE, 0);
                        if (strcmp(buffer, "250") == 0) {
                            printf("S: 250 Message accepted for delivery\n");

                            // Send QUIT command
                            memset(buffer, 0, BUFFER_SIZE);
                            strcpy(buffer, "QUIT");
                            printf("C: QUIT\n");
                            send(client_socket, buffer, BUFFER_SIZE, 0);

                            // Receive response from server
                            memset(buffer, 0, BUFFER_SIZE);
                            recv(client_socket, buffer, BUFFER_SIZE, 0);
                            if (strcmp(buffer, "221") == 0) {
                                printf("S: 221 Bye\n");
                                flag = 1; // Exit the loop
                            }
                        }
                    }
                }
            }
        }
    }

    close(client_socket);
    return 0;
}

