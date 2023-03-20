#include<stdio.h>
void printArray(int[],int);
int main(){

    int array[] = {7,4,6,8,22,56,22};

    printArray(array, sizeof(array)/sizeof(array[0]));    

    return 0;
}
void printArray(int arr[], int size){
    ( size-1>0 ) ? printArray(arr,size-1) : 0 ;
    printf("%d\n", arr[size-1]);
}