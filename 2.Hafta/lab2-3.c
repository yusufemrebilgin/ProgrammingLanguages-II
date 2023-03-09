//Write a recursion function to sum digits of the number given in the main function.
#include<stdio.h>
int sumDigits(int);
int main(){
	
	int number, result;
	printf("Please enter a number: "); scanf("%d", &number);
	
	result = sumDigits(number);
	printf("Result: %d", result);
	
	return 0;
}
int sumDigits(int n){
	
	if(n==0)
		return n;
	else 
		return n%10 + sumDigits(n/10);
}
