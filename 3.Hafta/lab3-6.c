//What does the following recursive code do?
#include<stdio.h>

void my_recursive_function(int n){
	if( n==0 )
		return;
	printf("%d", n);
	my_recursive_function(n-1);
}
void main(){
	my_recursive_function(7);
	//Printing n to 1.
}
