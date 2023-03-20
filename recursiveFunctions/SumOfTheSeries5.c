// S = X - X^3 + X^5 + ...
#include<stdio.h>
#include<math.h>
double sumOfTheSeries(int,double);
int main(){

    int a, b;
    printf("S = X - X^3 + X^5 + ...\n\n");
    printf("Enter X value: ");
    scanf("%d", &a);
    printf("Enter number of terms: ");
    scanf("%d", &b);

    printf("Sum: %.3lf", sumOfTheSeries(b,a));

    return 0;
}
double sumOfTheSeries(int n, double x){
    if( n==1 )
        return x;
    else if( n==2 )
        return -pow(x,3) + sumOfTheSeries(n-1,x);
    else if( n>=3 )
        return +pow(x,n*2-1) + sumOfTheSeries(n-1,x);
}