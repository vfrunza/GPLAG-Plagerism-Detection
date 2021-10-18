#include <stdio.h>
#include <math.h>

//Funkcija provjerava da li neki broj postoji u nekom od nizova
int pomocna_sadrzi (int broj, int niz[], int vel)
{
	int i=0;
	for (i=0; i<vel; i++) {
		if (niz[i]==broj) return 1;
	}
	return 0;
}

int dva_od_tri (int niz1[], int br1, int niz2[], int br2, int niz3[],  int br3)
{
	int i, j, n=0, count=0, kon=0;
	int np_niz[9999]= {};
	// Prvo prolazimo kroz cijela 3 niza i u novi niz postavljamo sve clanove bez ponavljanja
	for (i=0; i<br1; i++) {
		if ((pomocna_sadrzi(niz1[i],np_niz,n))==0) {
			np_niz[n]= niz1[i];
			n++;
		}
	}

	for (i=0; i<br2; i++) {
		if ((pomocna_sadrzi(niz2[i],np_niz,n))==0) {
			np_niz[n]= niz2[i];
			n++;
		}
	}

	for (i=0; i<br3; i++) {
		if ((pomocna_sadrzi(niz3[i],np_niz,n))==0) {
			np_niz[n]= niz3[i];
			n++;
		}
	}

	//Prolazimo kroz četvrti niz i provjeravamo koliko se puta nalazi u data 3 niza 
	for (j=0; j<=n; j++) {
		if (pomocna_sadrzi(np_niz[j], niz1, br1)) count++;  //Kada pronađe iste elemente, povećavamo counter
		if (pomocna_sadrzi(np_niz[j], niz2, br2)) count++;
		if (pomocna_sadrzi(np_niz[j], niz3, br3)) count++;
		if (count==2) kon++; //Povećavamo broj elemenata koji se ponavljaju, ako vrijedi navedeni uslov
		count=0;
	}

	return kon;
}


int main()
{
	int niz1[10000], niz2[10000], niz3[10000];
	int br1=0, br2=0, br3=0, i, j;
	
	//Unos elemenata
	for (i=0;; i++) {
		scanf("%d", niz1[i]);
		if(niz1[i]=='\n') break;
		br1++;
	}

	for (j=0;; j++) {
		scanf("%d", niz2[j]);
		if(niz2[j]=='\n') break;
		br2++;
	}

	for (j=0;; j++) {
		scanf("%d", niz3[j]);
		if(niz3[j]=='\n') break;
		br3++;
	}

	//Poziv funkcije
	printf ("%d", dva_od_tri(niz1, br1, niz2, br2, niz3, br3));

	return 0;
}
