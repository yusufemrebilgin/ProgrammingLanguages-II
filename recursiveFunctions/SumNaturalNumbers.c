#include<stdio.h>
int sumAllNumbers(int);
int main(){

    int number, result;
    printf("0 + 1 + 2 + ... + n\n\n");
    printf("Enter last number(n): ");
    scanf("%d", &number);
    
    result = sumAllNumbers(number);
    printf("Result: %d", result);

    return 0;
}
int sumAllNumbers(int n){
    return (n==0) ? 0 : ( n + sumAllNumbers(n-1) );
}