#include <stdio.h>
#include <math.h>

void zaokruzi1 (float *pok, int n1)
{
	float *vel=pok+n1;
	
	for (; pok<vel; pok++)
		*pok=round(*pok*10)/10;
}


int sumiraj (float *pok)
{
	int suma=0, x;

	x=*pok;
	while (x!=0) {
		suma+=fabs(x%10);
		x/=10;
	}
	/* sumiranje preostale decimalne cifre,
	potrebno je zaokruziti prvu decimalu zbog nepreciznosti */
	suma+=fabs(round((*pok-(int)*pok)*10));

	return suma;
}


void preslozi (float *pok, int n1, int k)
{
	float temp;
	float *vel = pok + n1, *j;
	int i;
	
	zaokruzi1(pok, n1);
	
	/* ako je vrijednost na pokazivacu manja od k prebacuje je na kraj niza a ostale pomjera za 1 mjesto lijevo i tako cuva redoslijed, ako nije ne dira je */
	for (i=0; i<n1; i++, pok++)
		if (sumiraj(pok)<k) {
			temp=*pok;
			for (j=pok; j<vel-1; j++)
				*j=*(j+1);
			*j=temp;
			pok--; /* ako je prebacilo clan na kraj provjerava onaj koji je dosao na njegovo mjesto */
		}
}


int main() {
	
	int i;
	float niz[5]={ 13.1, 15.749999, 15.75, 9.222, 78.1 };

	preslozi(niz, 5, 14);
	
	for (i=0; i<5; i++)
	printf ("%g ", niz[i]);

	return 0;
}