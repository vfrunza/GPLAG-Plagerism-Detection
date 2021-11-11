#include <stdio.h>
#include <math.h>

/*Funkcija provjerava da li broj postoji u nekom nizu*/
int pomocna(int broj, int niz[], int vel)
{
	int i=0;
	for(i=0; i<vel; i++) {
		if(niz[i]==broj) {
			return 1;
		}
	}
	return 0;
}
/* Provjerava sva tri niza i u novi niz postavlja sve clanove.Zatim provjerava koliko puta se svaki clan ponavlja u ova tri niza
i povecava x. */
int dva_od_tri (int nizPrvi[], int vel1, int nizDrugi[], int vel2, int nizTreci[], int vel3)
{
	int i, j, noviNiz[10000]= {}, broj=0, brojac=0, x=0;

	for(i=0; i<vel1; i++) {
		if((pomocna(nizPrvi[i], noviNiz, broj))==0) {
			noviNiz[broj]=nizPrvi[i];
			broj++;
		}
	}
	for(i=0; i<vel2; i++) {
		if((pomocna(nizDrugi[i], noviNiz, broj))==0) {
			noviNiz[broj]=nizDrugi[i];
			broj++;
		}
	}

	for(i=0; i<vel3; i++) {
		if((pomocna(nizTreci[i], noviNiz, broj))==0) {
			noviNiz[broj]=nizTreci[i];
			broj++;
		}
	}
	for(j=0; j<=broj; j++) {
		if(pomocna(noviNiz[j], nizPrvi, vel1)) {
			brojac++;
		}
		if(pomocna(noviNiz[j], nizDrugi, vel2)) {
			brojac++;
		}
		if(pomocna(noviNiz[j], nizTreci, vel3)) {
			brojac++;
		}
		if (brojac==2) {
			x++;
		}
		brojac=0;
	}
	return x;
}
int main()
{
	int nizPrvi[10000], nizDrugi[10000], nizTreci[10000], vel1=0, vel2=0, vel3=0, i, j;

	printf("Unesite prvi niz: ");
	for(i=0; i<vel1; i++) {
		scanf("%d", &nizPrvi[i]);
		vel1++;
	}

	printf("Unesite drugi niz: ");
	for(j=0; j<vel2; j++) {
		scanf("%d", &nizDrugi[j]);
		vel2++;
	}

	printf("Unesite treci niz: ");
	for(j=0; j<vel3; j++) {
		scanf("%d", &nizTreci[j]);
		vel3++;
	}

	printf("%d", dva_od_tri(nizPrvi, vel1, nizDrugi, vel2, nizTreci, vel3));
	return 0;
}
