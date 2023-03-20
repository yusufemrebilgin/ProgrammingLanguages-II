#include<stdio.h>
int lcf(int,int,int);
int main(){

    int a, b, result;
    printf("Please enter number 1:  "); scanf("%d", &a);
    printf("Please enter number 2:  "); scanf("%d", &b);

    result = ( a>b ) ? lcf(b,a,b) : lcf(a,a,b);

    printf("LCF: %d", result);

    return 0;
}
int lcf(int min, int x, int y){
    return ( min%x==0 && min%y==0 ) ? min : lcf(min+1,x,y);
}