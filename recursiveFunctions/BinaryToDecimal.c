#include<stdio.h>
#include<math.h>
int binaryToDecimal(int);
int main(){

    int number, result;
    printf("Please enter binary number: ");
    scanf("%d", &number);

    result = binaryToDecimal(number);
    printf("Decimal: %d", result);
    
    return 0;
}
int binaryToDecimal(int n){
    static int i;
    if( n==0 )
        return 0;
    else
        if( n%10==1 )
            return pow(2,i++) + binaryToDecimal(n/10);
        else{
            i++;
            binaryToDecimal(n/10);
        }
}