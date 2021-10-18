#include <stdio.h>
#include <math.h>
/*Provjerava da li je niz cifara ispravan.*/
int provjeriCifre (int niz[], int vel)
{
	int i, j;
	for(i=0; i< vel; i++) {
		if(niz[i]<0 || niz[i]>9) {
			return 0;
		}
		for(j=i+1; j<vel; j++) {
			if(niz[i]==niz[j]) {
				return 0;
			}
		}
	}
	return 1;
}
/*Pomocna funkcija koja izbacuje cifre*/
int izbaci_cifre1(int broj, int cifra)
{
	int n=0, brojac=0;
	while(broj!=0) {
		if(fabs(broj%10)!=cifra) {
			n+=broj%10 * pow(10, brojac);
			brojac++;
		}
		broj/=10;
	}
	return n;
}
int izbaci_cifre (int nizPrvi[], int vel1, int nizDrugi[], int vel2)
{
	/*Provjerava da li je niz ispravan, ako nije vraca 0*/
	int i, j;
	if(!(provjeriCifre(nizDrugi, vel2)!=0)) {
		return 0;
	}
	for(i=0; i<vel1; i++) {
		for(j=0; j<vel2; j++) {
			nizPrvi[i]=izbaci_cifre1(nizPrvi[i], nizDrugi[j]);

		}
	}
	return 1;
}


int main()
{
	int nizPrvi[100], nizDrugi[10], vel1=0, vel2=0, i, j, provjera;

	for(i=0; i< vel1; i++) {
		scanf ("%d", nizPrvi[i]);
		vel1++;
	}
	for(j=0; j<vel2; j++) {
		scanf("%d", nizDrugi[j]);
		vel2++;
	}

	provjera=izbaci_cifre(nizPrvi, vel1, nizDrugi, vel2);
	for(i=0; i<vel1; i++) {
		printf("%d", nizPrvi[i]);
	}

	return 0;
}
