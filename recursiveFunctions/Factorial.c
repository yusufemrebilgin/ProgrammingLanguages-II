#include<stdio.h>
int factorial(int);
int main(){

    int number;
    printf("Please enter a number: ");
    scanf("%d", &number);

    printf("%d!(Factorial): %d", number, factorial(number));

    return 0;
}
int factorial(int n){
    return (n>0) ? n*factorial(n-1) : 1; 
}