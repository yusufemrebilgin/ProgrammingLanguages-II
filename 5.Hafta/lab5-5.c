//Write a program in C to swap elements using call by reference.
#include<stdio.h>
#include<stdlib.h>
#define N 3
void swapElements(int *);
int main(){

    int i, array[N];

    for(i=0 ; i<N; i++){
        printf("Number %d: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("The elements before swapping:\n");
    for(i=0 ; i<N ; i++)
        printf("%d): %d\n", i+1, array[i]);
    
    swapElements(array);

    printf("The elements after swapping:\n");
    for(i=0 ; i<N ; i++)
        printf("%d): %d\n", i+1, array[i]);


    return 0;
}
void swapElements(int *arr){
    int i, temp;
    for(i=0 ; i<N/2 ; i++){
        temp = *(arr+i);
        *(arr+i) = *(arr+N-1-i);
        *(arr+N-1-i) = temp;
    }
}
