/*
    Write a program that reads a string entered from the keyboard and find frequency of characters in this
    string using dynamic memory management.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int freq[256] = {0};
int main(){

    char ch, *text = NULL;
    
    size_t textSize = 0;
    text = malloc(sizeof(char) * (textSize+1));
    if( text==NULL ){
        printf("Memory cannot allocated!");
        exit(EXIT_FAILURE);
    }

    printf("Please enter text: ");
    while( (ch=getchar()) != '\n' ){
    
        text = realloc(text , sizeof(char) * ((++textSize) + 1 ));
        if ( text==NULL ){
            printf("Memory cannot reallocated!");
            exit(EXIT_FAILURE);
        }
        text[textSize-1] = ch;
    }
    text[textSize] = '\0';

    for(size_t i=0 ; i<textSize ; i++)
        freq[(text[i])]++;

    printf("Enter character to find frequency: ");
    scanf("%c", &ch);

    printf("Frequency of '%c' is %d.", ch, freq[ch]);

    free(text);

    return 0;
}