#include<stdio.h>
int findFrequency(int,int);
int main(){
    
    int a, number;
    printf("Please enter number: ");
    scanf("%d", &number);
    printf("Find the frequency of ");
    scanf("%d", &a);
    
    printf("%d", findFrequency(number,a));

    return 0;
}
int findFrequency(int n, int digit){
    if( n==0 )
        return 0;
    else
        if( n%10==digit )
            return 1 + findFrequency(n/10,digit);
        else
            return findFrequency(n/10,digit);
}