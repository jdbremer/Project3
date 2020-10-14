#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <vector>
#include <arpa/inet.h>
#include <cerrno>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include "pthread.h"
#define BUFFER_SIZE 2048

using namespace std;


vector<int> randomChoice(){
	vector<int> vec;

	int defaults[2] = {1,1};
	int array1[2] = {2,3};
	int array2[2] = {3,5};
	int array3[2] = {4,7};
	int array4[2] = {5,9};
	int val = rand()%(4)+1;

	switch(val){
		case 1: vec.insert(vec.end(), begin(array1), end(array1)); break;
		case 2: vec.insert(vec.end(), begin(array2), end(array2)); break;
		case 3: vec.insert(vec.end(), begin(array3), end(array3)); break;
		case 4: vec.insert(vec.end(), begin(array4), end(array4)); break;
		default: vec.insert(vec.end(), begin(defaults), end(defaults)); break;
	}
	return vec;

}


void clearBuffer(char * input){};
void errcheck(int err){};
