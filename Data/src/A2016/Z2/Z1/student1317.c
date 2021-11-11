#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
	long int number=0, new_number=0;
	int zad_cif=0, pred_cif=0, nova_cifra=0, broj_cif=0;
	
	printf("Unesite broj: ");
	scanf("%ld", &number);
	
	if(number >= -9 && number <=9) printf("0");
	else
	{
		number = abs(number);
	do {
	zad_cif = number % 10;   /* Razdvajanje zadnjih cifara */
	number = number / 10;
	
	if(broj_cif >= 1) 
	{
		nova_cifra = abs(zad_cif - pred_cif); /* Oduzimanje cifara */
		new_number = new_number + nova_cifra * pow(10, broj_cif-1); /* Sastavljanje novog broja */
	}
	pred_cif = zad_cif; /* Zamjena predzadnje i zadnje cifre, predzadnja postaje zadnja */
	broj_cif++;
	
	} while(number != 0);
	
	printf("%ld", new_number);
	}
	return 0;
}
