#include<stdio.h>
#include<math.h>
void fun(float,float,float*);
double factorial(int n);
int main(){

    float x, n, result;
    printf("cos(X) = 1 - X^2/2! + X^4/4! + ... + X^N/N!\n\n");
    printf("Enter X value: ");
    scanf("%f", &x);
    printf("Enter N value: ");
    scanf("%f", &n);

    fun(x,n,&result);

    printf("Result: %.4f", result);

    return 0;
}
void fun(float x, float n, float *result){
    for(int i=1 ; i<=n ; i++){
        if(i==1)
            *result += 1;
        if(i==2)
            *result -= pow(x,(i-1)*2)/factorial((i-1)*2);
        if(i>2)
            *result += pow(x,(i-1)*2)/factorial((i-1)*2);
    }
}
double factorial(int n){
    return (n>0) ? n*factorial(n-1) : 1 ;
}