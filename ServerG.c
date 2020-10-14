#include "sharedModule.h"


int main(int argc,char **argv){

	char writeBuffer[2048];
	char readBuf[2048];
	char Cmd[100];
	int toServerG[2];
	int toServerC[2];
	int writeError;
	int readErr;

	sscanf(argv[0],"%d",&toServerG[0]);
	sscanf(argv[1],"%d",&toServerC[1]);
  clearBuffer(writeBuffer);
	printf("Child ID: %d\n toServerG :%d\n toServerC :%d\n", getpid(),toServerG[0], toServerC[1]);
  sprintf(writeBuffer,"ServerG initialized\n");
  printf("test\n");
  writeError = write(toServerC[1],writeBuffer,99);
  printf("test1\n");
  errcheck(writeError);
  }
