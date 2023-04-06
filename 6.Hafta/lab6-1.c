#include<stdio.h>
#include<stdlib.h>
int main(){

    int n, i, *ptr;
    printf("Enter array size: ");
    scanf("%d", &n);

    ptr = (int*)calloc(n,sizeof(int));

    if( ptr==NULL ){
        printf("Memory not allocated.\n");
        exit(0);
    }

    for(i=0 ; i<n ; i++){
        printf("%d) ", i+1);
        scanf("%d", ptr+i);
    }
    
    for(i=1 ; i<n ; i++)
        if( *ptr<*(ptr+i) )
            *ptr = *(ptr+i);

    printf("Max number: %d", *ptr);


    return 0;
}