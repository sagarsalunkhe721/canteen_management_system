#include <iostream>
#include <stdlib.h>

using namespace std;

int fab(int n){
	if( n == 0 || n == 1)
		return 1;
	return fab(n - 1) + fab(n - 2);
}


int main(int argc,char ** args){
	/*
	int a = 1;
	int b = 1;
	int n = 0;
	while( n < atoi(args[1])){
		if( n == 0 || n == 1){
			cout<<1<<endl;
		}else{
			int c =  a + b;
			cout<<c<<endl;
			a = b;
			b = c;
		}
		n++;
	}*/

	for(int  i = 0; i < atoi(args[1]); i++)
		cout<<fab(i)<<endl;
return 0;
}

