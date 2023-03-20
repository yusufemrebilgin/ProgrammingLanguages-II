#include<stdio.h>
int SIZE;
int findMax(int[],int);
int main(){

    int i, array[100];
    printf("Please enter array size: ");
    scanf("%d", &SIZE);
    
    for(i=0 ; i<SIZE ; i++){
        printf("%d) ", i+1);
        scanf("%d", &array[i]);
    }

    printf("Max Number: %d", findMax(array,SIZE));

    return 0;
}
int findMax(int arr[], int n){

    static int max=-9999;
    if( n-1==0 )
        return max;
    else{
        if( arr[n]>max )
            max = arr[n];
        return findMax(arr,--n);
    }
}