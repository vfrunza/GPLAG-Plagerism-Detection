#include <stdio.h>
#include <math.h>

int main() {
	int broj,razlika = 0,nova_cifra = 0,prva_cifra = 0,druga_cifra = 0,desetice;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if(broj < 0)
	{
		broj = fabs(broj);
	}
	desetice = 1;
	while(broj!=0 && broj >= 10)
	{
		prva_cifra = broj % 10;
		druga_cifra = (broj / 10) % 10;
		razlika = fabs(prva_cifra - druga_cifra);
		nova_cifra += razlika * desetice;;
		desetice = desetice * 10;
		broj = broj / 10;
	}
	printf("%d",nova_cifra);
	
	return 0;
}
