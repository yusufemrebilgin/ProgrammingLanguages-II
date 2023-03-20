#include<stdio.h>
void reverseArray(int[],int);
int main(){

    int n, array[100];
    printf("Enter array size: "); 
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++){
        printf("%d) ", i+1);
        scanf("%d", &array[i]);
    }
    
    reverseArray(array,n);
    for(int i=0; i<n;i++)
        printf("%d ",array[i]);
    
    return 0;
}
void reverseArray(int arr[], int size){
    static int i;
    if( i<size-1 ){
        arr[size-1] = arr[size-1] + arr[i];
        arr[i] = arr[size-1] - arr[i];
        arr[size-1] = arr[size-1] - arr[i];
        i++;
        reverseArray(arr,size-1);
    }
}