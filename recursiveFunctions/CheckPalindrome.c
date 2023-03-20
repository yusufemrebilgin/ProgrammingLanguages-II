#include<stdio.h>
int controlPalindrome(int,int);
int main(){

    int number;
    printf("Check Whether a Number is Palindrome or Not\n\n");
    printf("Please enter number: ");
    scanf("%d", &number);

    printf( (controlPalindrome(number,number)==1) ? "TRUE" : "FALSE" );

    return 0;
}
int controlPalindrome(int n, int control){
    static int sum;
    if( n==0 )
        return ( sum==control ) ? 1 : 0;
    else{
        sum = (n%10) + sum*10;
        controlPalindrome(n/10,control);
    }
}