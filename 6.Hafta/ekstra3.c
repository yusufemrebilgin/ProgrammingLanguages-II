#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){

    int i=0, len;
    char ch, temp, *ptr;

    ptr = (char*)malloc(sizeof(char));
    printf("Enter string: ");
    while(1){
        ch = getch();
        if(ch==13)
            break;
        putchar(ch);
        ptr = realloc(ptr,sizeof(char)*(i+2));
        *(ptr+i) = ch;
        i++;
    }
    *(ptr+i) = '\0';

    for(len=0 ; *(ptr+len) ; len++);
    
    for(i=0 ; i<len ; i++, len--){
        temp = *(ptr+i);
        *(ptr+i) = *(ptr+len-1);
        *(ptr+len-1) = temp;
    }

    printf("\nReverse of the string: %s", ptr);
    free(ptr);

    return 0;
}