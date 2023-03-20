#include<stdio.h>
void starPattern(int);
int main(){

    starPattern(10);

    return 0;
}
void starPattern(int row){

    ( row!=0 ) ? starPattern(row-1) : 0 ;
     for(int i=0 ; i<row ; i++)
        printf("*");
    printf("\n");
}