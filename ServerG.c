#include "sharedModule.h"


int main(int argc,char **argv){

	char writeBuffer[2048];
	char readBuf[2048];
	char Cmd[100];
	int toServerG[2];
	int toServerC[2];
	int new_socket;
	int writeError;
	int readErr;
	int valread;
	char sends[50];

	sscanf(argv[0],"%d",&toServerG[0]);
	sscanf(argv[1],"%d",&toServerC[1]);
	sscanf(argv[2],"%d",&new_socket);

  clearBuffer(writeBuffer);
	printf("Child ID: %d\n toServerG :%d\n toServerC :%d\n\n\n", getpid(),toServerG[0], toServerC[1]);
  sprintf(writeBuffer,"ServerG initialized\n\n");
  writeError = write(toServerC[1],writeBuffer,99);

	srand(time(NULL));


	sprintf(sends, "ServerG Initialized");
	send(new_socket , sends , strlen(sends) , 0 );

	valread = read( new_socket , sends, 2048);
	
	//valread = read( new_socket , sends, 2048);
	//CHOOSE ROCK, PAPER OR SCISSORS

//for loop????
	//run random val function
	//val = rand() % 3 + 1;

	//send
	//sprintf(sends,"");
	//send(new_socket , sends , strlen(sends) , 0 );
	//read
	//who_won = function(user_Val, server_Val);
	//run random val function
	//send
	//read
	//run random val function
	//send
	//read
	//run random val function
	//send
	//read


	send(new_socket , sends , strlen(sends) , 0 );

  errcheck(writeError);

  }
