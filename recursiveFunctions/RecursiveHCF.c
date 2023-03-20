#include<stdio.h>
int hcf(int,int);
int main(){

    int n1, n2;
    printf("Please enter first number:    "); scanf("%d", &n1);
    printf("Please enter second number:   "); scanf("%d", &n2);

    printf("HCF: %d", hcf(n1,n2));

    return 0;
}
int hcf(int x, int y){
    return (y==0) ? x : hcf(y,x%y);
}