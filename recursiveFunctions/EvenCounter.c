#include<stdio.h>
int evenCounter(int[],int);
int main(){
	
	int i, n, array[100];
    printf("Enter array size: ");
    scanf("%d", &n);

    for(i=0 ; i<n ; i++){
        printf("%d) ", i+1);
        scanf("%d", &array[i]);
    }
	printf("Even Number Count: %d", evenCounter(array,n));
	
	return 0;
}	
int evenCounter(int arr[], int size){
	
	if( size==0 )
		return 0;
	else{
		if( arr[size-1]%2==0 )
			return 1+evenCounter(arr,size-1);
		else
			return evenCounter(arr,size-1);
	}
}