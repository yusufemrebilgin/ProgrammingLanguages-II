#include<stdio.h>
void reverseStarPattern(int);
int main(){

    reverseStarPattern(10);

    return 0;
}
void reverseStarPattern(int row){

     for(int i=0 ; i<row ; i++)
        printf("*");
    printf("\n");
    ( row!=0 ) ? reverseStarPattern(row-1) : 0 ;
}