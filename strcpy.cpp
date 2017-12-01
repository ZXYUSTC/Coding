#include<iostream>
#include<cstring>
using namespace std;
void foo(void){
char string[10],str[10];
for(int j=0;j<10;j++)
	str[j]='a';
strcpy(string,str);
cout<<string<<endl;
}
int main(){
foo();
}
