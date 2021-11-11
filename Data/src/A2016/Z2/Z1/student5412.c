#include <stdio.h>
#include <math.h>

int main() 
{
	int n, cifra1, cifra2, suma;
	int koeficijent=1; //koeficijent za jedinice, desetice, stotice
	
	suma = 0;
	
	printf ("Unesite broj: ");
	scanf("%i", &n);
	
	cifra1 = n%10;
	n/=10;
	while (n!=0)
	{
		cifra2=n%10;
		suma=suma+fabs(cifra1-cifra2)*koeficijent;
		koeficijent*=10;
		cifra1=cifra2;
		n/=10;
	}
	printf ("%i",suma);
	
	return 0;
}
