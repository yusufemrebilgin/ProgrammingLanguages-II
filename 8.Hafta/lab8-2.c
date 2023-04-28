/*
    Write C program to add two complex numbers by passing structure to a function. (In this example, you should take two complex
    numbers as structures and add them by creating a user-defined function.)
*/
#include <stdio.h>
typedef struct{
    float real;
    float imaginary;
} ComplexNumber;

void addComplexNumbers(ComplexNumber,ComplexNumber,ComplexNumber*);

int main(){

    ComplexNumber complexNum1, complexNum2, result;

    printf("Enter real part for first number: ");
    scanf("%f", &complexNum1.real);
    printf("Enter imaginary part for first number: ");
    scanf("%f", &complexNum1.imaginary);

    printf("Enter real part for second number: ");
    scanf("%f", &complexNum2.real);
    printf("Enter imaginary part for second number: ");
    scanf("%f", &complexNum2.imaginary);

    addComplexNumbers(complexNum1,complexNum2, &result);

    printf("Result: %.2f + %.2fi\n", result.real, result.imaginary);

    

    return 0;
}
void addComplexNumbers(ComplexNumber num1, ComplexNumber num2, ComplexNumber *result){
    result->real = num1.real + num2.real;
    result->imaginary = num1.imaginary + num2.imaginary;
}