#include<stdio.h>
int checkStrongNumber(int);
int factorial(int);
int main(){

    int number;
    printf("Check Whether a Number is Strong or Not\n\n");
    printf("Enter number: ");
    scanf("%d", &number);

    printf( (checkStrongNumber(number)==number) ? "TRUE" : "FALSE");

    return 0;
}
int checkStrongNumber(int a){
    return (a!=0) ? factorial(a%10)+checkStrongNumber(a/10) : 0 ;
}
int factorial(int n){
    return (n>0) ? n*factorial(n-1) : 1;
}