#include<stdio.h>
float findAvg(float[],int);
int main(){

    int i, n;
    float result, array[100];
    printf("Enter size for array: ");
    scanf("%d", &n);

    for(i=0 ; i<n ; i++){
        printf("Student %d: ", i+1);
        scanf("%f", &array[i]);
    }
    result = findAvg(array,n);
    printf("Average: %.2f", result);

    return 0;
}
float findAvg(float arr[], int size){
    static int i;
    static float sum;
    
    if( i==size )
        return sum/size;
    else{
        sum += arr[i++];
        return findAvg(arr,size);
    }
}