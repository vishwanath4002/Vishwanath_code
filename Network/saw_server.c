#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

#define PORT 8091
#define BUFFER_SIZE 1024

void main()
{
  int client_socket, server_socket;
  char buffer[BUFFER_SIZE], stored_message[BUFFER_SIZE];
  struct sockaddr_in client_addr, server_addr;
  socklen_t addrlen = sizeof(struct sockaddr_in);
  
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1)
  {
    perror("Error creating socket.\n");
    exit(EXIT_FAILURE);
  }
  
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);
  
  if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
  {
    perror("Error binding socket.\n");
    exit(EXIT_FAILURE);
  }
  
  printf("Listening for connections on port %d...\n", PORT);
  listen(server_socket, 5);
  
  client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addrlen);
  if (client_socket == -1)
  {
    perror("Error accepting connection.\n");
    exit(EXIT_FAILURE);
  }
  
while (1)
  {
    int ack = 0; 
    memset(buffer, 0, BUFFER_SIZE);
    
    while (ack == 0)
    {
      recv(client_socket, buffer, BUFFER_SIZE, 0);
      if (rand()%2 == 0)
      {
        printf("Message sent by Client : %s\n", buffer);
        printf("Server : ACK\n");
        strcpy(buffer, "ACK");
        send(client_socket, buffer, strlen(buffer), 0);
        ack = 1;
        break;
      }
      else
      {
        printf("Client : NACK\n");
        strcpy(buffer, "NACK");
        send(client_socket, buffer, strlen(buffer), 0);
      }
    }
    
    printf("Enter message to send to client:\nServer : ");
    fgets(buffer, BUFFER_SIZE, stdin);
    strcpy(stored_message, buffer);
    
    if (strcmp(buffer, "exit\n") == 0)
    {
      break;
    }
    
    while (ack == 1)
    {
      send(client_socket, stored_message, strlen(stored_message), 0);
      memset(buffer, 0, BUFFER_SIZE);
      recv(client_socket, buffer, BUFFER_SIZE, 0);
      
      if (strcmp(buffer, "ACK") == 0)
      {
        ack = 1;
        printf("\nMessage acknowledged by client.\n");
        break;
      }
    }
  }
}
