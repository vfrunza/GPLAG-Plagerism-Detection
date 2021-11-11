#include <stdio.h>
#include <math.h>

int main() {
	int broj, cifra, a, b=0, brojac=-1, suma=0;
	
	printf("Unesite broj: ");
	scanf("%d", &broj);
	a=broj%10;
	
	do {
		cifra=fabs(broj%10);
		broj=fabs(broj/10);
		b= fabs(a-cifra);
		a=cifra;
		suma=suma+pow(10, brojac)*b;
		brojac++;
		} while(broj>0);
	printf("%d", suma);
	
	return 0;
}
