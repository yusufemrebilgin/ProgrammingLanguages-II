#include<stdio.h>
void printNaturalNumbers(int);
int main(){

    int number;
    printf("Print Natural Numbers (0,1,2,...,n)\n\n");
    printf("Enter last number(n): ");
    scanf("%d", &number);

    printNaturalNumbers(number);

    return 0;
}
void printNaturalNumbers(int n){
    if(n!=0)
        printNaturalNumbers(n-1);
    printf("%d ", n);
}