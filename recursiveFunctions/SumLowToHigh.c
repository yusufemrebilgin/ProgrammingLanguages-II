#include<stdio.h>
int sum(int,int);
int main(){

    int a, b, result;
    printf("LOW:  "); scanf("%d", &a);
    printf("HIGH: "); scanf("%d", &b);

    result = (a<b) ? sum(a,b) : sum(b,a);
    printf("Sum: %d", result);

    return 0;
}
int sum(int low, int high){
    return (low==high) ? high : low+sum(low+1,high);
}