#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){

	int i, c=1, zar, puan1=0, puan2=0;
	srand( time(NULL) );
	
	for(i=0 ; i<2 ; i++){
		zar = rand()%6+1;
		printf("%d.Zar: %d\n", c++, zar);
		puan1 += zar;
	}
	putchar('\n');
		
	if( puan1==7 || puan1==11 )
		printf("\n\nKAZANDINIZ!");
	else if( puan1==2 || puan1==3 || puan1==12 )
		printf("\n\nKAYBETTINIZ!");
	else{
		
		while(1){
			
			for(i=0, puan2=0 ; i<2 ; i++){
				zar = rand()%6+1;
				printf("%d.Zar: %d\n", c++, zar);
				puan2 += zar;
			}
				
			if( puan2==puan1 ){
				printf("\n\nKAZANDINIZ!");
				break;
			}
			else if( puan2==7 ){
				printf("\n\nKAYBETTINIZ!");
				break;	
			}
		}
		
	}
	
	return 0;
}
