#include <stdio.h>

int main() {
	
	int broj, cifra1, cifra2, nova_cifra;
	int rezultat = 0, tezina=1;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	if(broj < 0) broj = - broj;
	while(broj>0)
	{
		cifra1 = broj % 10;
		broj /= 10;
		cifra2 = broj % 10;
		
		if(broj==0 && cifra2==0) break; 
		
		nova_cifra = cifra1 - cifra2;
		if(nova_cifra < 0) nova_cifra = - nova_cifra;
		
		rezultat = rezultat + nova_cifra * tezina;
		tezina*=10;
		
	}
	
	printf("%d", rezultat);
	
	return 0;
}
