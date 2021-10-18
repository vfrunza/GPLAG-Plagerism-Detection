#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int broj, brojPrvi, brojDrugi, faktor = 1, rez = 0;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	broj = abs(broj);
	
	while(broj >= 10) {
	
	brojDrugi = broj % 10;
	brojPrvi = (broj/10) % 10;
	
	rez += abs((brojDrugi - brojPrvi)) * faktor;
	broj = broj / 10;
	
	faktor *= 10;
	
	}
	
	printf("%d", rez);
	
}