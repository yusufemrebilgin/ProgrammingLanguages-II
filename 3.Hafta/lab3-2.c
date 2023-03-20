/*
Write a recursive function that takes the address of the array and the number of elements as a parameter 
and returns the number of odd numbers in the array. (Do not use global variable)
*/
#include<stdio.h>
int oddCounter(int[],int);
int main(){
	
	int array[] = {1,3,7,9,11};
	int n = sizeof(array)/sizeof(array[0]);	
	
	printf("%d", oddCounter(array,n));
	
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

