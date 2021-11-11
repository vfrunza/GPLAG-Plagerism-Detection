#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
	int n;
	printf("Unesite broj: ");
	scanf("%d", &n);
	int pomocna = n;
	int rezultat=0;
	int broj_cifararez = 0;
	if(pomocna<0) pomocna=-pomocna;
	if(pomocna<10) { printf("0"); return 0; }
	while(pomocna>0)
	{
		int prva_cifra=pomocna%10;
		pomocna/=10;
		int druga_cifra;
		 druga_cifra = pomocna%10;
		rezultat += abs(prva_cifra-druga_cifra) * pow(10, broj_cifararez);
		broj_cifararez++;
	}
	rezultat= rezultat % (int)pow(10,broj_cifararez-1);
	printf("%d", rezultat);
	return 0;
}
