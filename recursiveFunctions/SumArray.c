#include<stdio.h>
int sumArray(int[],int);
int main(){

    int result, array[] = {5,6,7,1,2};

    result = sumArray(array,sizeof(array)/sizeof(array[0]));
    printf("Sum: %d", result);

    return 0;
}
int sumArray(int arr[], int size){
    return (size-1!=0) ? arr[size-1]+sumArray(arr,size-1) : arr[size-1] ;
}