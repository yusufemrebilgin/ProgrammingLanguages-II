//Write a recursion program that finds the largest element in the entered array.
#include<stdio.h>
int SIZE;
int findMax(int[]);
int main(){
	
	int i, array[100];
	printf("Enter array size: ");scanf("%d", &SIZE);
	for(i=0;i<SIZE;i++){
		printf("Please enter a number: ");
		scanf("%d", &array[i]);
	}
		
	printf("Max Number: %d", findMax(array));
	
	return 0;
}

int findMax(int arr[]){
	
	static int i=0, max=-9999;

	if( i==SIZE )
		return max;
	else{
		if( arr[i]>max )
			max = arr[i++];
		return findMax(arr);
	}
}
