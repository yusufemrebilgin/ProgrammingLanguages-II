#include<stdio.h>
#include<string.h>
void removeChExceptAlphabet(char[]);
int main(){

    char str[40];
    printf("Enter string:  "); 
    
    gets(str);
    removeChExceptAlphabet(str);
    puts(str);

    return 0;
}
void removeChExceptAlphabet(char s[]){
    static int i, j;
    static char temp[50];
    if( s[i]!='\0'){
        if( (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') )
            temp[j++] = s[i];
        i++;
        removeChExceptAlphabet(s);
    }
    else{
        temp[j] = '\0';
        strcpy(s,temp);
    }
}
