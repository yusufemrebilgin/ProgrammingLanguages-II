#include<stdio.h>
void printEvenOrOdd(int,int,int);
int main(){

    int a, b, n;
    printf("Enter first number: "); scanf("%d", &a);
    printf("Enter last number:  "); scanf("%d", &b);
    printf("Select (0) for even, select (1) for odd numbers: ");
    scanf("%d", &n);

    printEvenOrOdd(a,b,n);

    return 0;
}
void printEvenOrOdd(int firstNumber, int lastNumber, int n){
    if( n==0 ){
        if( firstNumber%2==0 && firstNumber<=lastNumber )
            printf("%d\n", firstNumber);
        printEvenOrOdd(++firstNumber,lastNumber,n);
    }
    if( n==1 )
        if( firstNumber%2==1 && firstNumber<=lastNumber )
            printf("%d\n", firstNumber);
        printEvenOrOdd(++firstNumber,lastNumber,n);
}