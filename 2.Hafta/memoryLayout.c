#include<stdio.h>
#include<stdlib.h>
int global;	  // Unitialized variable stored in bss.

int main(){
	
	int *ptr_one;
	ptr_one = (int*)malloc(sizeof(int)); // Memory allocating in heap segment.
	int c; 								// Local variable stored in stack.
	static int i = 100; 			   // Initialized static variable stored in DS.
	static int k; 					  // Initialized static variable stored in bss.
	
	return 0;
}
