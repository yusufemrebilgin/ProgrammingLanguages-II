#include<stdio.h>
#include<stdlib.h>
double factorial(int);
int main(){

    int i, j, k, row, space, *ptr;
    printf("Enter row number: ");
    scanf("%d", &row);

    ptr = (int*)malloc( sizeof(int)*( row*(row+1)/2 ) );
    
    for(i=0,k=0 ; i<row ; i++)
        for(j=0 ; j<=i ; j++){
            *(ptr+k) = factorial(i)/(factorial(j)*factorial(i-j));
            k++;
        }
    space = row;
    for(i=0, k=0 ; i<row ; i++){
        for(j=0 ; j<space ; j++)
            printf("   ");
        for(j=0 ; j<=i ; j++)
            printf("%6d", *(ptr+(k++)));
        printf("\n");
        space--;
    }

    free(ptr);

    return 0;
}
double factorial(int n){
    return (n>0) ? n*factorial(n-1) : 1;
}