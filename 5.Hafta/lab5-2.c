//Write a program in C to add two numbers using pointers.
#include<stdio.h>
int main(){

    int a, b, *p1, *p2;
    printf("Input the first number:   ");
    scanf("%d", &a);
    printf("Input the second number:  ");
    scanf("%d", &b);

    p1 = &a;
    p2 = &b;

    printf("The sum of entered number is: %d", *p1+*p2);

    return 0;
}