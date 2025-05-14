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
    char buffer[BUFFER_SIZE], ack[BUFFER_SIZE];
    int windowsize;
    int base = 0, count = 0, totalpackets, limit;
    int packnum = 0;
    

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

        //printf("Enter message to send to server (type 'exit' to quit): ");
        //fgets(buffer, BUFFER_SIZE, stdin);

        // Send message to server
        //send(client_socket, buffer, strlen(buffer), 0);

        //if (strcmp(buffer, "exit\n") == 0)
            //break;

        // Receive response from server
        //memset(buffer, 0, BUFFER_SIZE);
        //recv(client_socket, buffer, BUFFER_SIZE, 0);

        //printf("Received from server: %s\n", buffer);
	printf("\nEnter the sender's sliding window size : ");
    scanf("%d", &windowsize);
    printf("\nEnter total number of packets to be sent : ");
    scanf("%d", &totalpackets);
  
    
    base = 0;
    limit = (totalpackets < windowsize) ? totalpackets : windowsize;
    packnum = 0;
    for (int i = 0; i<limit; i++)
    {
      	memset(buffer, 0, BUFFER_SIZE);
       	//itoa(i, buffer, 10);
       	sprintf(buffer, "%d", i);
       	send(client_socket, buffer, strlen(buffer), 0);
       	printf("\nClient : sent packet %d, seqnum %d", packnum, i);
       	packnum++;
       	sleep(1);
    }
	printf("\n");
	
	while (count < totalpackets)
	{
		recv(client_socket, buffer, BUFFER_SIZE, 0);
       	printf("\n\nServer : sent ack for seqnum %s", buffer);
       	//itoa(base, ack, 10);
       	sprintf(ack, "%d", base);
       	if (strcmp(buffer, ack) == 0)
       	{
       		printf("\n\nACK received for seqnum %d", base);
       		base = (base + 1)%windowsize;
       		count++;
       	}
       	else
       	{
       		printf("\n\nAck not recieved for seqnum %d", base);
       		printf("\n\nRetransmitting packets from  %d", count);
       		limit = ((totalpackets-count) < windowsize) ? (totalpackets-count) : windowsize;
       		packnum = count;
       		for (int i = 0; i<limit; i++)
       		{
       			memset(buffer, 0, BUFFER_SIZE);
				//itoa(i, buffer, 10);
				sprintf(buffer, "%d", i);
				send(client_socket, buffer, strlen(buffer), 0);
				printf("\nClient : sent packet %d, seqnum %d", packnum, i);
				packnum++;
				sleep(1);
       		}
       		base = 0;
      	}
    }
        
    if (count == totalpackets)
    {
      	printf("\nAll packets sent and recieved succesfully.\n");
    }

    close(client_socket);
    return 0;
}


