#include<stdio.h>
#include<string.h>
void reverseString(char[]);
int main(){

    char str[50];

    gets(str);
    reverseString(str);
    puts(str);

    return 0;
}
void reverseString(char s[]){

    static int i;
    static char temp[50];
    if( i<=strlen(s)){
        temp[i] = s[strlen(s)-1-i];
        i++;
        reverseString(s);
    }
    else{
        temp[i] = '\0';
        strcpy(s,temp);
    }
}

