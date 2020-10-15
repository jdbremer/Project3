// Client side C/C++ program to demonstrate Socket programming
#include "sharedModule.h"
#define PORT 8080

int main(int argc, char const *argv[])
{

	vector<int> random;

  //CREATES SOCKET
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
	  char randomVal[15];
    char ips[15];
    int lastValinIP = 0;
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);


    srand(time(NULL));
    lastValinIP = rand() % 10 + 1;
    sprintf(ips, "127.0.0.%d", lastValinIP);
    printf(ips);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ips, &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    //END OF SOCKET CREATION



	  random = randomChoice();
    printf("\n\nrandom %d, %d\n\n", random[0], random[1]);

    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );

    char *hello = "Client Initialized";
    send(sock , hello , strlen(hello) , 0 );

    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );

    return 0;
}
