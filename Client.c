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
    lastValinIP = rand() % 255 + 1;
    sprintf(ips, "127.0.0.%d", lastValinIP);
    cout << ips << "\n" << endl;;

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



	  //random = randomChoice();
    //printf("\n\nrandom %d, %d\n\n", random[0], random[1]);
		printf("1\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
		printf("2\n");

		printf("3\n");
    char *hello = "Client Initialized";
    send(sock , hello , strlen(hello) , 0 );
		printf("4\n");

		string server_choice;
		string Sclient_choice;
		char client_choice[50];
//printf("HEY\n");
		printf("5\n");
		valread = read( sock , buffer, 1024);
		printf("%s\n",buffer );
		printf("6\n");

		printf("7\n");
    send(sock , hello , strlen(hello) , 0 );
		printf("8\n");
		//printf("HEY11\n");
		while(true){
			memset(buffer, 0, sizeof(buffer));
			valread = read( sock , buffer, 1024);

			if((strcmp(buffer, "The computer wins the game") == 0)
			 || (strcmp(buffer, "The player wins the game") == 0)){
				 break;
			 }
			server_choice = buffer;
			cout << "Enter one of the following: \n 1 ~ Rock \n 2 ~ Paper \n 3 ~ Scissors\n:: ";
			cin >> Sclient_choice;
			//printf("10\n");

			memset(client_choice, 0, sizeof(client_choice));
			strcpy(client_choice, Sclient_choice.c_str());
			//client_choice
			//printf("9\n");
			send(sock , client_choice , strlen(client_choice) , 0 );
			valread = read( sock , buffer, 1024);
			printf("%s\n",buffer );
			hello = "Continue";
			send(sock , hello , strlen(hello) , 0 );


		}
		printf("HEY");
    printf("%s\n",buffer );

    return 0;
}
