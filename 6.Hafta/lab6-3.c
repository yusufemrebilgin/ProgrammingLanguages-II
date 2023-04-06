#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){

    char *ptr;
    
    ptr = (char*)malloc(sizeof(char)*15);
    strcpy(ptr,"Yusuf Emre");
    ptr = realloc(ptr,sizeof(char)*30);
    strcpy(ptr,"Yusuf Emre Bilgin");

    puts(ptr);

    free(ptr);

    return 0;
}