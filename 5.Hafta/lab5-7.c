//Write a program in C to print a string in reverse using a pointer.
#include<stdio.h>
int main(){
    
    int i, len;
    char *p1, *p2, str1[50], str2[50];

    p1 = str1;
    p2 = str2;

    printf("Input a string: ");
    gets(str1);

    for(len=0 ; *(p1+len)!='\0' ; len++);

    for( i=0 ; len>=0 ; len--,i++)
        *(p2+i) = *(p1+len-1);

    *(p2+i) = '\0';

    printf("Reverse of the string is: %s", str2);

    return 0;
}