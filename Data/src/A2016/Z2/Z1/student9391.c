#include <stdio.h>
#include <math.h>
int main() {
	int broj, cifra, pomoc, cifra_druga, brojac=0, n=0, rezultat=0;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj<0) broj=-broj;
	if(broj<10) {
		printf("0");
	return 0;
	}
		pomoc=broj;
		while (pomoc!=0)
		{
			pomoc/=10;
			n++;
		}
	do {
		cifra=broj%10;
		broj=broj/10;
		rezultat+=fabs(broj%10-cifra)*pow(10,brojac);
		brojac++;
	} while(brojac<n-1);
	 printf("%d", rezultat);
	//printf("Zadaća 2, Zadatak 1");
	return 0;
}
