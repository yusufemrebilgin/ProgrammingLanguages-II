#include<stdio.h>
int recursivePowFun(int,int);
int main(){

    int a, b;
    printf("Enter number:     ");
    scanf("%d", &a);
    printf("Enter power:      ");
    scanf("%d", &b);

    printf("Result: %d", recursivePowFun(a,b));

    return 0;
}
int recursivePowFun(int n, int a){
    return (a!=0) ? n*recursivePowFun(n,--a): 1;
}