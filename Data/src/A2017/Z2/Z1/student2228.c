#include <stdio.h>

int main() 
{

	int pocetni_broj, dobijeni_broj=0, K, pom, prva_cifra, druga_cifra;
	printf("Unesite broj: ");
	scanf("%d", &pocetni_broj);
	if(pocetni_broj<10 && pocetni_broj>-10)
	       dobijeni_broj=0;
	else
	{
		if(pocetni_broj<0)
		   pocetni_broj=-pocetni_broj;
		prva_cifra=pocetni_broj%10;
		pocetni_broj=pocetni_broj/10;
		K=1;
		while(pocetni_broj>0)
		{
			druga_cifra=pocetni_broj%10;
			pom=prva_cifra-druga_cifra;
			if(pom<0)
			   pom=-pom;
			dobijeni_broj+=K*pom;
			K*=10;
			prva_cifra=druga_cifra;
			pocetni_broj=pocetni_broj/10;
		}
	}
	
	printf("%d", dobijeni_broj );
	
	return 0;
}
