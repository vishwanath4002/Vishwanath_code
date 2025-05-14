#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

#define PORT 8091
#define BUFFER_SIZE 1024

void main()
{
  int client_socket;
  char buffer[BUFFER_SIZE], stored_message[BUFFER_SIZE];
  struct sockaddr_in server_addr;
  
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1)
  {
    perror("Error creating socket.\n");
    exit(EXIT_FAILURE);
  }
  
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_addr.sin_port = htons(PORT);
  
  if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
  {
    perror("Error connecting socket.\n");
    exit(EXIT_FAILURE);
  }
  
  while (1)
  {
    int ack = 0; 
    memset(buffer, 0, BUFFER_SIZE);
    printf("Enter message to send to server\nClient : ");
    fgets(buffer, BUFFER_SIZE, stdin);
    strcpy(stored_message, buffer);
    
    if (strcmp(buffer, "exit\n") == 0)
    {
      break;
    }
    
    while (ack == 0)
    {
      send(client_socket, stored_message, strlen(stored_message), 0);
      memset(buffer, 0, BUFFER_SIZE);
      recv(client_socket, buffer, BUFFER_SIZE, 0);
      
      if (strcmp(buffer, "ACK") == 0)
      {
        ack = 1;
        printf("\nMessage acknowledged by server.\n");
        break;
      }
    }
    
    while (ack == 1)
    {
      recv(client_socket, buffer, BUFFER_SIZE, 0);
      if (rand()%2 == 0)
      {
        printf("Message sent by Server : %s\n", buffer);
        printf("Client : ACK\n");
        strcpy(buffer, "ACK");
        send(client_socket, buffer, strlen(buffer), 0);
        ack = 0;
        break;
      }
      else
      {
        printf("Client : NACK\n");
        strcpy(buffer, "NACK");
        send(client_socket, buffer, strlen(buffer), 0);
      }
    }
  }
}
