#include<stdio.h>
int checkPerfectNumber(int);
int main(){

    int number;
    printf("Check Whether a Number is Perfect or Not\n\n");
    printf("Enter number: ");
    scanf("%d", &number);

    printf( (checkPerfectNumber(number)==number) ? "TRUE" : "FALSE" );

    return 0;
}
int checkPerfectNumber(int n){

    static int i=1;
    if(i==n)
        return 0;
    else if( n%i==0 )
        return (i++) + checkPerfectNumber(n);
    else{
        i++;
        return checkPerfectNumber(n);
    }
}