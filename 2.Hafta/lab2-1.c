//Calculate the sum of all numbers (including this number) up to a natural number given in the main function using a recursive function.
#include<stdio.h>
int sum(int);
int main(){
	
	int number;
	printf("Please enter a number: "); scanf("%d", &number);
	printf("Result: %d", sum(number));
	
	return 0;
}

int sum(int n){
	
	if(n!=0)
		return n+sum(n-1);
	else
		return n;
}
