#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <vector>
#include <arpa/inet.h> 

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
		case 1: vec.insert(vec.end(), array1.begin(), array1.end()) break; 
		case 2: vec.insert(vec.end(), array2.begin(), array2.end()) break; 
		case 3: vec.insert(vec.end(), array3.begin(), array3.end()) break; 
		case 4: vec.insert(vec.end(), array4.begin(), array4.end()) break; 
		default: vec.insert(vec.end(), defaults.begin(), defaults.end()) break; 
	}
	return vec;
	
}