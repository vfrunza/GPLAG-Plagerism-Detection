#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int broj=0,cifra1=1,cifra2=1,suma=0,brojac=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	broj=abs(broj);
	if(broj<10){printf("0"); return 0;}
	else{
		do{
			
		cifra1=broj%10;
		broj=(int)broj/10;
		cifra2=broj%10;
	if(broj!=0){	suma+=(abs(cifra1-cifra2))*(pow(10,brojac));}
		brojac++;}while(broj!=0);
		
		
		
	}
	printf("%d ",suma);
	
	return 0;
}
