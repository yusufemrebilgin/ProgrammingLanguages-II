#include<stdio.h>
int countDigit(int);
int main(){

    int number, digit;
    printf("Please enter a positive number: ");
    scanf("%d", &number);

    digit = countDigit(number);
    printf("%d digit(s)", digit);

    return 0;
}
int countDigit(int n){
    return (n!=0) ? (1+countDigit(n/10)) : n;
}