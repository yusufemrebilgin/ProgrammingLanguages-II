// S = 1 + 1/2 + 1/3 + ... + 1/n
#include<stdio.h>
double sumOfTheSeries(double);
int main(){

    int number;
    printf("S = 1 + 1/2 + 1/3 + ... + 1/n\n\n");
    printf("Enter n value: ");
    scanf("%d", &number);

    printf("Sum: %.3lf", sumOfTheSeries(number));

    return 0;
}
double sumOfTheSeries(double n){
    if( n==1 )
        return 1;
    else    
        return 1/n + sumOfTheSeries(n-1);
}