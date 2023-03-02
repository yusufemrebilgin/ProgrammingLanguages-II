#include<stdio.h>
int kitleIndeks(float,float);

int main(){
	
	int durum;
	float boy, kilo;
	printf("Kilo degeri giriniz(kg):  ");
	scanf("%f", &boy);
	printf("Boy degeri giriniz(m):    ");
	scanf("%f", &kilo);

	durum = kitleIndeks(boy,kilo);
	
	if( durum==1 )
		printf("Zayif");
	if( durum==2 )
		printf("Normal");
	if( durum==3 )
		printf("Kilolu");
	if( durum==4 )
		printf("Obez");
	
	return 0;
}

int kitleIndeks(float k, float b){
	
	float vucutIndeks = k / (b*b);

	if( vucutIndeks<=18 )
		return 1;
	else if( vucutIndeks<=25 )
		return 2;
	else if( vucutIndeks<=30 )
		return 3;
	else if( vucutIndeks>30 )
		return 4;
}


