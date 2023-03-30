//Write a program in C to compute the sum of all elements in an array using pointers
#include<stdio.h>
#include<stdlib.h>
int main(){

    int i, n, sum=0, *array;
    printf("Enter array size: ");
    scanf("%d", &n);

    array = (int *)malloc(sizeof(int)*n);

    for(i=0 ; i<n ; i++){
        printf("%d) ", i+1);
        scanf("%d", (array+i));
        sum += *(array+i);
    }
    printf("The sum of array is: %d", sum);

    return 0;
}
