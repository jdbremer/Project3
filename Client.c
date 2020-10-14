// Client side C/C++ program to demonstrate Socket programming
#include "sharedModule.h"
#define PORT 8080

int main(int argc, char const *argv[])
{

	vector<int> random;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
	char randomVal[15];
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

	random = randomChoice();
	sprintf(randomVal, "Client: %d, %d", random[0], random[1]);
    send(sock , randomVal , strlen(randomVal) , 0 );
    printf("Client message sent\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );

    valread = read( sock , buffer, 1024); //waiting for serverG connection
    printf("%s\n",buffer );

    return 0;
}
