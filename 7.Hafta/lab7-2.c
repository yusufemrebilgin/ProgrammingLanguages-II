/*
    Write a program that searches for the given string in the given sentece and if the word is found then prints the starting
    index of the places of this word to the screen.
*/
#include<stdio.h>
#include<string.h>

int main(){
    
    int i, j, len, index, isWordFound=0;
    char text[200], word[25];
    
    printf("Enter text: ");
    gets(text);
    printf("Enter word: ");
    scanf("%s", word);

    len = strlen(text);

    for(index=0 ; index<len ; index++)

        if( text[index]==word[0] )

            for(i=index, j=0 ; text[i]==word[j] && word[j]!='\0' ; i++, j++)
                if( word[j+1]=='\0' && ( (text[i+1]>=32 && text[i+1]<=64) || text[i+1]=='\0') ){
                    printf("Starting index:[%d]\n", index);
                    isWordFound = 1;
                }

    if( !isWordFound )
        printf("The word cannot be found.\n");                

    return 0;
}