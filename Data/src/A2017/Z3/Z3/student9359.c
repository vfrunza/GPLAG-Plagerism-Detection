#include <stdio.h>
#include <stdlib.h>



int stepen(int x, int n) {
	
	int i, rez = 1;
	
	for(i = 0; i < n; i++) {
		
		rez *= x;
		
	}
	
	return rez;
	
}

int izbacivanjeCifara(int broj, int cifra)
{
	
	int noviBroj = 0;
	int cifraProvjera;
	int i = 0;
	
	broj = abs(broj);
	
	while(broj > 0) {
		
		cifraProvjera = broj % 10;
		
		if(cifraProvjera != cifra){
			
			noviBroj += cifraProvjera * stepen(10, i);
			i++;
		}
		
		broj /= 10;
	}
	
	return noviBroj;
	
}

int izbaci_cifre(int nizBrojevi[], int vel1, int nizCifre[], int vel2){
	
	int i,j, negativan;
	int nizQA[9] = {0};
	
	for(i = 0; i < vel2; i++) {
		
		if(nizCifre[i] < 0 || nizCifre[i] > 9) return 0;
		
		nizQA[nizCifre[i]]++;
		
	}
	
	for(i = 0; i < 9; i++) {
		
		if(nizQA[i] > 1) return 0;
	}
	
	
	for( i = 0; i < vel1; i++ ) {
		
		if(nizBrojevi[i] < 0) negativan = 1;
        else negativan = 0;
		
		for(j = 0; j < vel2; j++) {
			
			nizBrojevi[i] = izbacivanjeCifara(nizBrojevi[i], nizCifre[j]);
			if(negativan) nizBrojevi[i] *= -1;
		}
	}
	
	return 1;
	
}

int main() {
	
	int brojevi[] = {12345, -12345};
	int cifre[] = {3,5}, rez;

	rez = izbaci_cifre(brojevi, 2, cifre, 2);
	printf("%d\n%d %d",rez, brojevi[0], brojevi[1]);
	
	
	

	
	return 0;
}
