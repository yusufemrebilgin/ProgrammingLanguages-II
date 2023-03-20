// S = 1-X^2/2! + X^4/4! - ...
#include<stdio.h>
#include<math.h>
double sumOfTheSeries(int,double);
int factorial(int);
int main(){

    int a, b;
    printf("S = 1-X^2/2! + X^4/4! - ...\n\n");
    printf("Enter X value: ");
    scanf("%d", &a);
    printf("Enter number of terms: ");
    scanf("%d", &b);

    printf("Sum: %.3lf", sumOfTheSeries(b,a));

    return 0;
}
double sumOfTheSeries(int n, double x){
    
    if( n==1 )
        return 1;
    else if( n%2==1 )
        return +pow(x,(n-1)*2)/(double)factorial((n-1)*2) + sumOfTheSeries(n-1,x);
    else if( n%2==0 )
        return -pow(x,(n-1)*2)/(double)factorial((n-1)*2) + sumOfTheSeries(n-1,x);
}
int factorial(int a){
    return (a<=1) ? 1 : a*factorial(a-1);
}