#include<stdio.h>
int binaryFun(int);
int main(){

    int number, result;
    printf("Please enter decimal number: ");
    scanf("%d", &number);

    result = binaryFun(number);
    printf("Binary: %d", result);

    return 0;
}
int binaryFun(int n){
    return (n!=0) ? (n%2) + binaryFun(n/2)*10 : 0;
}