#include<stdio.h>
#include<stdlib.h>
int main(){

    int n, m, i, *ptr;
    printf("Enter array size: ");
    scanf("%d", &n);

    ptr = (int*)malloc(sizeof(int)*n);

    for(i=0 ; i<n ; i++){
        printf("%d) ", i+1);
        scanf("%d", ptr+i);
    }

    printf("Enter new array size: ");
    scanf("%d", &m);
    ptr = realloc(ptr, sizeof(int)*m);

    for( n ; n<m ; n++){
        printf("%d) ", n+1);
        scanf("%d", ptr+n);
    }
    printf("\nArray:\n");
    for(i=0 ; i<m ; i++)
        printf("Number %d: %d\n", i+1, *(ptr+i));

    free(ptr);

    return 0;
}