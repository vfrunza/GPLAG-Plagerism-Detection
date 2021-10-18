#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int izbaci_cifre (int *niz, int vel, int *red, int vel1)
{

	int i=0, j, k=0, s=0, l, niz1[100]= {0}, znak=0;
	/* Provjeravamo da li su cifre u trazenom opsegu */
	for(i=0; i<vel1; i++)
		if(red[i]<0 || red[i]>9)
			return 0;

	for(i=0; i<vel1; i++) {
		for(j=i+1; j<vel1; j++)
			if(red[i]==red[j])
				return 0;
	}

	for(s=0; s<vel; s++) {
		/* Korisitimo promjenljivu znak koju postavljamo na 1 ako je clan niza negativan, a ostaje nula ako je clan niza pozitivan */
		znak=0;
		if(niz[s]<0)
			znak=1;

		i=0;
		do {
			niz1[i]=(abs(niz[s]))%10;
			i++;
			niz[s]=niz[s]/10;
		} while(niz[s]!=0);

		for(k=0; k<i; k++) {
			for(l=0; l<vel1; l++) {
				if(niz1[k]==red[l]) {
					for(j=k; j<i-1; j++)
						niz1[j]=niz1[j+1];
					i--;
					k--;
					break;
				}
			}
		}

		niz[s]=0;

		for(j=0; j<i; j++)
			niz[s]+=round(niz1[j]*pow(10, j));
		/* Ako je clan niza negativan, znak ce biti jedan pa ga zbog toga mnozimo sa (-1) */
		if(znak==1)
			niz[s]=niz[s]*(-1);
	}
	return 1;
}

int main()
{
	return 0;
}