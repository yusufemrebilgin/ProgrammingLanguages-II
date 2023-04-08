#include<stdio.h>
#include<stdlib.h>
int main(){

    int i, j, n, maxAbs=0, *ptr;
    int index1, index2;

    printf("Enter array size: ");
    scanf("%d", &n);

    ptr = (int *)malloc(sizeof(int) * n);

    for(i=0 ; i<n ; i++){
        printf("[%d]: ", i);
        scanf("%d", ptr+i);
    }
    for(i=0 ; i<n ; i++)
        for(j=0 ; j<n ; j++)
            if( abs(ptr[i]-ptr[j])>maxAbs ){
                maxAbs = abs(ptr[i]-ptr[j]);
                index1 = i;
                index2 = j;
            }

    printf("Max absolute value difference |[%d] - [%d]|:  %d", index1, index2, maxAbs);
    free(ptr);

    return 0;
}