// S = 1/2 + 1/4 + ... + 1/n
#include<stdio.h>
double sumOfTheSeries(double);
int main(){

    int number;
    double result;
    printf("S = 1/2 + 1/4 + ... + 1/n\n\n");
    printf("Enter a number that is a multiple of two: ");
    scanf("%d", &number);

    printf("Sum: %.4lf", sumOfTheSeries(number));

    return 0;
}
double sumOfTheSeries(double n){
    if( n==2 )
        return 0.5;
    else
        return 1/n + sumOfTheSeries(n-2);
}