/*
***use valgrind --leak-check=full ./a.out to detect the memory of program.
***
*/


#include<iostream>
using namespace std;

void getMemory(char *p, int size){
	p=(char *)malloc(sizeof(char)*size);
}

int main(){
	char *str=NULL;
	getMemory(str,100);
	cout<<"Memory leak test"<<endl;
	return 0;
}