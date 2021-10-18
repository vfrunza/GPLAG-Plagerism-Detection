#include <stdio.h>

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3)
{
	int i, j, brojac=1, rep=0, br_elemenata=0, elementi[100];
	/* Provjera postojanja elemenata iz 1. niza u 2. i 3. */
	for(i=0; i<vel1; i++) {
		brojac=1;
		for(j=0; j<vel2; j++) {
			if(niz1[i]==niz2[j]) {
				brojac++;
				break;
			}
		}
		for(j=0; j<vel3; j++) {
			if(niz1[i]==niz3[j]) {
				brojac++;
				break;
			}
		}
		/* Provjera uslova bez repeticije */
		if(brojac==2) {
			rep=0;
			for(j=0; j<br_elemenata; j++) {
				if(niz1[i]==elementi[j]) rep=1;
			}
			if(rep==0) {
				elementi[br_elemenata]=niz1[i]; /* upisivanje dosadasnjih elemenata sto se ponavljaju */
				br_elemenata++;
			}
		}
	}
	/* Trazenje elemenata 2. niza u 1. i 3. */
	for(i=0; i<vel2; i++) {
		brojac=1;
		for(j=0; j<vel1; j++) {
			if(niz2[i]==niz1[j]) {
				brojac++;
				break;
			}
		}
		for(j=0; j<vel3; j++) {
			if(niz2[i]==niz3[j]) {
				brojac++;
				break;
			}
		}
		if(brojac==2) {
			rep=0;
			for(j=0; j<br_elemenata; j++) {
				if(niz2[i]==elementi[j]) rep=1;
			}
			if(rep==0) {
				elementi[br_elemenata]=niz2[i];
				br_elemenata++;
			}
		}
	}
	return br_elemenata;
}

int main()
{
	return 0;
}
