//The program code that identifies whether two string entered from the keyboard are the same or not and which is longer as a word.
#include<stdio.h>
#include<string.h>

int main(){

    char str1[40], str2[40];

    printf("Enter first word:  ");
    scanf("%s", str1);
    printf("Enter second word: ");
    scanf("%s", str2);

    int temp = strcmp(str1,str2);

    if( !temp )
        printf("Words are same.");
    else    
        if( strlen(str1)>strlen(str2) )
            printf("(%s) is longer than (%s).", str1, str2);
        else
            printf("(%s) is longer than (%s).", str2, str1);


    return 0;
}