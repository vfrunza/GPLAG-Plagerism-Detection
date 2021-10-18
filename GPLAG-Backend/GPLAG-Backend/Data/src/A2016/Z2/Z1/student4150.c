#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int broj,brojac=0,kopija,broj1,broj2,razlika=0,i, konacno=0;
	printf("Unesite broj: ");
	scanf("%d", &broj);

	if(broj<0) broj*=-1;
		kopija=broj;
	while(broj!=0) {
		broj/=10;
		brojac++;
	}	
	if(broj<10 && broj>0) {
		printf("0");
		return 0;
	}	
		
		for(i=0; i<brojac-1; i++) {
		broj1=kopija%10;
		kopija/=10;
		broj2=kopija%10;
		razlika+=abs(broj1-broj2);
		razlika*=10;
	}
	razlika/=10;

	for(i=0;i<brojac-1;i++) {
		konacno+=razlika%10;
		konacno*=10;
		razlika/=10;
	}
konacno/=10;
printf("%d",konacno);
		
return 0;
}