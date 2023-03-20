// S= 1 + 11 + 111 + ... + n
int sumOfTheSeries(int);
#include<stdio.h>
int main(){

    int i, term, sum=0;
    printf("S = 1 + 11 + 111 + ... + n\n\n");
    printf("Enter number of terms: ");
    scanf("%d", &term);

    for(i=1 ; i<=term ; i++)
        sum += sumOfTheSeries(i);

    printf("Sum: %d", sum);

    return 0;
}
int sumOfTheSeries(int n){
    return (n==1) ? 1 : 1+(sumOfTheSeries(n-1))*10;
}