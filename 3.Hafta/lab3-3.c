//What is the output of the following C Program?
#include<stdio.h>

int fun(int n){
	if( n==4 )
		return n;
	else
		return 2*fun(n+1);
}
int main(){
	
	printf("%d", fun(2));
	//16
	
	return 0;
}
