//Using the two positive numbers given in the main function, find the largest common divisor of these numbers using a recursive function.
#include<stdio.h>
int hcf(int,int);
int main(){
	
	int number1, number2;
	printf("Enter first number:   "); scanf("%d", &number1);
	printf("Enter second number:  "); scanf("%d", &number2);
	
	printf("HCF: %d", hcf(number1,number2));
	
	return 0;
}

int hcf(int n1, int n2){
	
	if( n2==0 )
		return n1;
	return hcf( n2,n1%n2 );
}
