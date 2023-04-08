#include<stdio.h>
#include<stdlib.h>
int main(){

    int i, j, n, temp, *ptr;

    printf("Enter array size: ");
    scanf("%d", &n);
    ptr = (int*)malloc(sizeof(int)*n);

    for(i=0 ; i<n ; i++){
        printf("%d) ", i+1);
        scanf("%d", ptr+i);
    }
    
    for(i=0 ; i<n ; i++)
        if( ptr[i]%2!=0 )
            for(j=i+1 ; j<n ; j++)
                if( ptr[j]%2==0 ){
                    temp = ptr[i];
                    ptr[i] = ptr[j];
                    ptr[j] = temp;          
                }

    for(i=0 ; i<n ; i++)
        printf("%d ", *(ptr+i));
        
    free(ptr);

    return 0;
}