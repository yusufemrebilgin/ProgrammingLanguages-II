#include<stdio.h>
int oddCounter(int[],int);
int main(){
	
	int i, n, array[100];
    printf("Enter array size: ");
    scanf("%d", &n);

    for(i=0 ; i<n ; i++){
        printf("%d) ", i+1);
        scanf("%d", &array[i]);
    }
	printf("Odd Number Count: %d", oddCounter(array,n));
	
	return 0;
}	
int oddCounter(int arr[], int size){
	
	if( size==0 )
		return 0;
	else{
		if( arr[size-1]%2==0 )
			return oddCounter(arr,size-1);
		else
			return 1+oddCounter(arr,size-1);
	}
}