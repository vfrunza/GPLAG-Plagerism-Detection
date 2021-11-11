#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int broj, cifra, prethodna_cifra, znamenka, rezultat=0, a=1;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	broj = abs(broj);
	
	while (broj>10) {
		cifra = broj%10;
		broj /= 10;
		prethodna_cifra = broj%10;
		
		znamenka = abs(cifra-prethodna_cifra);
		
		rezultat = rezultat + a*znamenka;
		
		a*=10;
	}
	
	printf("%d", rezultat);
	
	return 0;
}
