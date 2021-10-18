#include <stdio.h>
#include <math.h>

int main() {
	
	int unos; 
	int brojac = 0,broj1,broj2 ; 
	int suma =0 ;
	int x;
	printf("Unesite broj: ");
	scanf("%d",&unos);
		unos=fabs(unos);
		
		while(unos>10){
			broj1=unos%10; 
			unos=unos/10; 
			broj2=unos%10;
			
			x=fabs(broj1-broj2);
			suma=suma + x*pow(10,brojac);
			brojac++;
		}
		printf("%d",suma);
	
	return 0;
}
