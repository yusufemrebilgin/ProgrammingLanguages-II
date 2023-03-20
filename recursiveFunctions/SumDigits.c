#include<stdio.h>
int sumDigits(int);
int main(){

    int number, result;
    printf("Please enter a positive number: ");
    scanf("%d", &number);

    result = sumDigits(number);
    printf("Sum: %d", result);

    return 0;
}
int sumDigits(int n){
    return (n!=0) ? (n%10+sumDigits(n/10)) : n;
}