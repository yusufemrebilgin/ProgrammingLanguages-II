#include<stdio.h>
int primeNumberControl(int);
int main(){

    int number;
    printf("Please enter a number: ");
    scanf("%d", &number);

    printf( (primeNumberControl(number)==1) ? "TRUE" : "FALSE" );

    return 0;
}
int primeNumberControl(int n){
    static int i=2;
    if( i==n )
        return 1;
    else if( n%i==0 || n==1 )
        return 0;
    else{
        ++i;
        primeNumberControl(n);
    }
}