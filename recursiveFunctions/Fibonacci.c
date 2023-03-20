#include<stdio.h>
int fibonacci(int);
int main(){

    int term;
    printf("Enter term number: ");
    scanf("%d", &term);
    printf("Fibonacci(%d): %d", term, fibonacci(term));

    return 0;
}
int fibonacci(int n){
    return (n==0 || n==1) ? 1 : fibonacci(n-1)+fibonacci(n-2);
}