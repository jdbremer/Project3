#include "sharedModule.h"




//Functions
string winner(int user, int comp){
	if(user == comp) return "It's a tie";
	else if(user == 1 && comp == 2) return "Player Wins";
	else if(user == 1 && comp == 3) return "Computer Wins";
	else if(user == 2 && comp == 3) return "Player Wins";
	else if(user == 2 && comp == 1) return "Computer Wins";
	else if(user == 3 && comp == 2) return "Computer Wins";
	else if(user == 3 && comp == 1) return "Player Wins";
}

string convertNumber(int value){
	if(value == 1) return "Rock";
	else if(value == 2) return "Scissors";
	else if(value == 3) return "Paper";
}





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
	
//CHOOSE ROCK, PAPER OR SCISSORS
	
	vector<int> randomValue;
	randomValue = randomChoice();
	
	int server_Val, user_Val, playerWins = 0, computerWins = 0;
	string who_won;
	
	while(computerWins != randomValue[0] && playerWins != randomValue[0])
	{
		server_Val = rand() % 3 + 1;
		sprintf(sends, convertNumber(server_Val));
		send(new_socket, sends, strlen(sends), 0);
		user_Val = read(new_socket, sends, 2048);
		who_won = winner(user_Val, server_Val);
		if(who_won == "Player Wins") playerWins++;
		else if(who_won == "Computer Wins") computerWins++;
		sprintf(sends, who_won);
		send(new_socket, sends, strlen(sends), 0);
	}
	
	if(computerWins == randomValue[0]){
		sprintf(sends, "The computer wins the game");
		send(new_socket, sends, strlen(sends), 0);
	}
	else if(playerWins == randomValue[0]){
		sprintf(sends, "The player wins the game");
		send(new_socket, sends, strlen(sends), 0);
	}
	

	send(new_socket , sends , strlen(sends) , 0 );

	errcheck(writeError);

  }
