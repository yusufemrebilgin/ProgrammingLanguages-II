#include<stdio.h>
void mTable(int);
int main(){

    mTable(10);

    return 0;
}
void mTable(int i){

    ( i!=1 ) ? mTable(i-1) : 0 ;
    for(int j=1 ; j<=10 ; j++)
        printf("%4d", i*j);
    printf("\n");
}