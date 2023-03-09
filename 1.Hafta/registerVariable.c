#include<stdio.h>
#include<time.h>
#define N 1000

int a=1;

int main(){
	
	clock_t start, end;
	double cpu_time_used;
	register double i;
	
	start = clock();
	for(i=0 ; i<N ; i=i+0.0001);
	end = clock();
	
	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
	
	printf("Running time is %f", cpu_time_used);
	
	//Running time is 0,163 second with register variable.
	//Running time is 0,419 second without register variable.
	
	
	return 0;
}
