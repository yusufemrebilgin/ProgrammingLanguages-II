#include<stdio.h>
#include<stdlib.h>
int main(){

    int i, j, n, sum=0;

    printf("Enter N value for NxN matrix: ");
    scanf("%d", &n);

    int **ptr = (int**)malloc(sizeof(int*)*n);
    for(i=0 ; i<n ; i++)
        ptr[i] = (int*)malloc(sizeof(int)*n);

    for(i=0 ; i<n ; i++)
        for(j=0 ; j<n ; j++){
            printf("[%d][%d]: ", i,j);
            scanf("%d", &ptr[i][j]);
            if( (i%2==0 && j%2==0) || (i%2!=0 && j%2!=0) )
                sum += ptr[i][j];
        } 
                
    printf("\nMatrix:\n");
    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++)
            printf("%d ", ptr[i][j]);
        printf("\n");
    }
    printf("\nSum: %d", sum);

    for(i=0 ; i<n ; i++)
        free(ptr[i]);
        
    free(ptr);

    return 0;
}