#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int dajbroj(int nizovski)
{
	// racunamo sumu cifara broja
	int tsuma=0;
	while(nizovski!=0) {
		int zadnji;
		zadnji=nizovski%10;
		tsuma+=zadnji;
		nizovski/=10;
	}
	tsuma=abs(tsuma); // vracamo pozitivnu vrijednost, ne moze biti negativna
	return tsuma;
}


void ubaci(int *niz, int vel)
{

	int *pok = niz;
	int *pomocni;
	while(pok!=niz+vel) {
		pomocni=niz+vel; // stavljamo pokazivac na kraj niza
		while(pomocni!=pok) {
			*pomocni=*(pomocni-1); // kopiramo niz redom za 1 element
			pomocni--;
		}
		*(pok+1)=dajbroj(*pok);
		vel++; // povecavamo velicinu niza da bi dobili ispravnu velicinu novog niza
		pok+=2; 
	}

}


int fibonachi(int broj)
{
	int i;
	int broj_a=1, broj_b=1, broj_c;
	if(broj==0) return 1;
	for(i=1; i<=broj; i++) { // algoritam za racunanje fibonacijevog broja
		if(i==1) {
			broj_c=1;
		} else {
			broj_c=broj_a+broj_b;
			broj_a=broj_b;
			broj_b=broj_c;
		}

		if(broj==broj_c) return broj; // ukoliko je naš broj jednak fibonacijevom, vracamo taj broj
	}

	return 0;
}


int izbaci(int *niz, int vel)
{
	int i, j;

	for(i=0; i<vel; i++) {
		if(*(niz+i) == fibonachi(*(niz+i)) ) { // provjeravamo redom da li su brojevi jedanki fibonacijevom i izbacujemo ukoliko je logicka jedinica

			for(j=i; j<vel-1; j++) {
				*(niz+j)=*(niz+j+1);
			}
			vel--;
			i--;

		}
	}
	return vel; // vracamo velicinu novog niza

}

int main()
{

	int vel;
	int i, niz[20];
	vel=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<vel; i++) {
		scanf("%d", niz+i);
	}


	ubaci(niz, vel);
	vel = izbaci(niz, 2*vel);

	printf("Modificirani niz glasi: ");
	for(i=0; i<vel; i++) {
		if(i==vel-1) printf("%d.", niz[i]);
		else printf("%d, ", niz[i]);
	}


	return 0;
}
