#include<stdio.h>
int strLength(char[]);
int main(){

    char str[100];
    printf("Enter string: ");
    gets(str);

    printf("Length: %d", strLength(str));

    return 0;
}
int strLength(char s[]){
    static int i;
    if( s[i]!=0 ){
        i++;
        strLength(s);
    }
    else 
        return i;
}