#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int broj,cifra1,cifra2,k=0,broj2=0,broj3=0;
	printf ("Unesite broj: ");
	scanf ("%d",&broj);
	broj=abs(broj);
	if (broj<10) printf ("");
	do{
		cifra1=broj%10;
		broj/=10;
		if (broj!=0){
		cifra2=broj%10;
		broj2=abs(cifra1-cifra2);
		broj3=broj3+broj2*pow(10,k);
		k++;
		} 
		}while (broj!=0);
	printf ("%d",broj3);
	
	return 0;
}
