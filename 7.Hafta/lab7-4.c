//Write the C program using dynamic memory, which counts the words in a given text.
#include<stdio.h>
#include<stdlib.h>
int main(){

    int i=0, wordCounter = 0;
    char ch, *text = NULL;
    size_t textSize = 0;

    text = malloc(sizeof(char) * (textSize+1));
    if (!text) {
        printf("Memory cannot allocated!");
        exit(EXIT_FAILURE);
    }

    printf("Please enter text: ");
    while( (ch=getchar()) != '\n' ){
        

        text = realloc(text , sizeof(char) * ((++textSize) + 1));
        if (!text) {
            printf("Memory cannot reallocated!");
            exit(EXIT_FAILURE);
        }
        text[textSize-1] = ch;
    }
    text[textSize] = '\0';

    for(i=0 ; text[i] != '\0' ; i++){
        if( (text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122) )
            if( (text[i+1] >= 32 && text[i+1] <= 64) || text[i+1]==0 )
                wordCounter++;
    }
    
    printf("Number of word(s): %d", wordCounter);

    free(text);

    return 0;
}