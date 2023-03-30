//Write a program in C to store n elements in an array and print the elements using pointer.
#include<stdio.h>
#include<stdlib.h>
int main(){

    int i, n, *arr;
    printf("Enter array size: ");
    scanf("%d", &n);
    
    arr = (int *)malloc(sizeof(int)*n);
    printf("Input %d number of elements in the array:\n", n);

    for(i=0 ; i<n ; i++){
        printf("[%d]: ", i);
        scanf("%d", (arr+i));
    }
    
    printf("The elements you entered are:\n");
    for(i=0 ; i<n ; i++)
        printf("[%d]: %d\n", i, *(arr+i));

    return 0;
}