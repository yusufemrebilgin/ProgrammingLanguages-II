#include<stdio.h>
void letterPattern(int);
int main(){
    
    int n;
    printf("Enter row number: ");
    scanf("%d", &n);

    printf("\n\n");
    letterPattern(n);

    return 0;
}
void letterPattern(int row){
    int i, j, A=65;
    static int space=1;
    if( row>=1 ){
        space = space+1;
        letterPattern(row-1);

        for( i=1 ; i<=space ; i++)
            printf(" ");
        if( row==1 )
            printf("%c\n", 65);
        if( row>1 ){
            for( i=1 ; i<=row; i++ )
                printf("%c", A++);
            A = A-1;
            i = i-2;
            for( i ; i!=0 ; i-- )
                printf("%c", --A);
            printf("\n");
        }
        space--;     
    }
}
