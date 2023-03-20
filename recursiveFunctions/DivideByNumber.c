#include<stdio.h>
void divideByNumber(int,int,int);
int main(){

    int a, b, c;
    printf("Enter first number:  ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Divide with ");
    scanf("%d", &c);

    divideByNumber(a,b,c);

    return 0;
}
void divideByNumber(int low, int high, int n){
    if( low<=high )
        if( low%n==0 )
            printf("%d\n", low);
    divideByNumber(++low,high,n);
}
