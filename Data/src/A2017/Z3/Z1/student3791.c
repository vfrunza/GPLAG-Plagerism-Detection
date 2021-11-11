#include <stdio.h>

/* Funkcija koja broji koliko se clanova javlja u dva niza, a ne u trećem: */
int za_svaki (int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3) {
	int i, j, k, brojac=0;
	for (i=0; i<vel1; i++) {
		for (j=0; j<vel2; j++) {
			if (niz1[i]==niz2[j]) {
				brojac++;
				for (k=0; k<vel3; k++) {
					if (niz1[i]==niz3[k]) brojac--;
				}
			}
		}
	}
	return brojac;
}

/* Funkcija koja izbacuje duple clanove iz datih nizova: */
int izbaci_duple (int niz[], int vel) {
	int i, j;
	for (i=0; i<vel; i++) {
		for (j=i+1; j<vel; j++) {
			if (niz[i]==niz[j]) {
				niz[j]=niz[vel-1];
				j--;
				vel--;
			}
		}
	}
	return vel;
}

int dva_od_tri (int nizA[], int velA, int nizB[], int velB, int nizC[], int velC) {
	int brojac=0;
	
	velA=izbaci_duple(nizA, velA);
	velB=izbaci_duple(nizB, velB);
	velC=izbaci_duple(nizC, velC);
	
	/* Funkciju za_svaki pozivamo za sve kombinacije data tri niza: */
	brojac=za_svaki(nizA, velA, nizB, velB, nizC, velC);
	brojac+=za_svaki(nizA, velA, nizC, velC, nizB, velB);
	brojac+=za_svaki(nizB, velB, nizC, velC, nizA, velA);
	
	return brojac;
}
int main() {
	printf("Zadaća 3, Zadatak 1");
}
