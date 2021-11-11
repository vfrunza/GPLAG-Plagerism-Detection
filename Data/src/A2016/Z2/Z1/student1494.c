#include <stdio.h>
#include <math.h>

int main() {
	int n, trazeni_br=0;
	int kopija_broja, brojac=0;
	int cifra, cifra1, razlika, i=0;
	int jednocifren;
	
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0) n=n*(-1);
	
	jednocifren=n/10;
	if(jednocifren==0)
	{
		trazeni_br=0;
	}
	else {
		kopija_broja = n;
	while(kopija_broja>0) {
		kopija_broja = kopija_broja/10;
		brojac++;
	}
	while(n>0)
	{
		cifra=n%10;
			cifra1=(n/10)%10;
				razlika=cifra-cifra1;
					if(razlika<0) razlika=razlika*(-1);
			trazeni_br=trazeni_br+razlika*pow(10, i);
			i++;
			n/=10;
	if(i==brojac-1) break;
	
	}
		}
		
		printf("%d", trazeni_br);
	
	return 0;
}