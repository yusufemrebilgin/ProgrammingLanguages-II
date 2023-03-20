#include<stdio.h>
void printFloydsTriangle(int);
int main(){

    int row;
    printf("Please enter row number: "); 
    scanf("%d", &row);

    printFloydsTriangle(row);

    return 0;
}
void printFloydsTriangle(int i){

    if( i>=1 ){
        printFloydsTriangle(i-1);
        if( i==1 )
          printf("1");
        else if( i%2==0 )
            for(int j=1; j<=i ; j++)
                printf( (j%2==0) ? "1" : "0" );
        else if( i%2==1 )
            for(int j=1; j<=i ; j++)
                printf( (j%2==0) ? "0" : "1" );
        printf("\n");
    }
}