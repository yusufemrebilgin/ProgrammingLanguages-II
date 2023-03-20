#include<stdio.h>
#define M 6
#define N 12
int path[M][N] ={0};
void findPath(int,int,int[][N]);
void printPath(void);
int main(){
	
	int i, j;
	int maze[M][N] = {		{1,0,1,1,1,0,0,1,0,1,1,0},
							{1,0,1,1,1,1,1,0,1,0,0,0},
							{1,1,1,1,1,1,1,0,1,0,1,0},
							{0,1,0,1,0,1,0,1,1,1,1,1},
							{0,1,0,1,1,1,1,1,0,0,0,1},
							{1,1,1,0,1,1,1,1,1,1,1,1}		};
	
	printf("MxN (%dx%d):\n\n",M,N);	
	for(i=0 ; i<M ; i++){
		for(j=0 ; j<N ; j++)
			printf("%d ", maze[i][j]);
		printf("\n");
	}
	findPath(0,0,maze);	
	printPath();
	
	return 0;
}

void findPath(int i, int j, int arr[][N]){
	
	static int minCost, maxCost=M*N;
	arr[i][j]=2;
	minCost++;
	
	(arr[i+1][j]==1 && arr[i+1][j]!=2) ? findPath(i+1,j,arr) : 0 ;
	(arr[i][j+1]==1 && arr[i][j+1]!=2) ? findPath(i,j+1,arr) : 0 ;
	(arr[i-1][j]==1 && arr[i-1][j]!=2) ? findPath(i-1,j,arr) : 0 ;
	(arr[i][j-1]==1 && arr[i][j-1]!=2) ? findPath(i,j-1,arr) : 0 ;
	
	if( minCost<maxCost && (i==M-1 && j==N-1) ){
		maxCost=minCost;
		for(i=0;i<M;i++)
			for(j=0;j<N;j++)
				path[i][j]=arr[i][j];
		minCost=0;
	}
	minCost--;
	arr[i][j]=1;
}
void printPath(){
	
	int i, j;
	printf("\n\nSHORTEST PATH:\n\n");
	for(i=0 ; i<M ; i++){
		for(j=0 ; j<N ; j++)
			(path[i][j]==2) ? printf("%c ",254):printf("%d ",path[i][j]);
		printf("\n");	
	}
}