#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int broj, cifra1, cifra2;
	int novi_broj=0, eksponent;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj<0) { broj=abs(broj); }
	eksponent=0;
	while(broj>9) {
		cifra1=broj%10;
		broj=broj/10;
		cifra2=broj%10;
		novi_broj+=abs(cifra1-cifra2)*pow(10,eksponent);
		eksponent++;
	}
	
	printf("%d", novi_broj);
	return 0;
}
