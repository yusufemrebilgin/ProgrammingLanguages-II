//Write a program in C to calculate the length of the string using a pointer.
#include<stdio.h>
int main(){

    int i;
    char str[50], *p;

    printf("Input a string: ");
    gets(str);

    p = str;

    for(i=0 ; *(p+i)!='\0' ; i++);
    printf("The length of the string (%s) is: %d", str, i);

    return 0;
}