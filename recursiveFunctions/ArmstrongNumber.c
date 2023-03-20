#include<stdio.h>
#include<math.h>
int armstrongControl(int,int);
int countDigit(int);
int main(){
    
    int number;
    printf("Check Whether a Number is Armstrong or Not\n\n");
    printf("Enter number: ");
    scanf("%d", &number);

    printf( (armstrongControl(number,countDigit(number))==number) ? "TRUE" : "FALSE" );
    
    return 0;
}
int armstrongControl(int n, int digit){
    return (n!=0) ? pow(n%10,digit) + armstrongControl(n/10,digit) : 0 ;
}
int countDigit(int a){
    return (a!=0) ? 1 + countDigit(a/10):0;
}


