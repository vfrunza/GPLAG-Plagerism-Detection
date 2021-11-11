#include <stdio.h>
#include <math.h>

//Funkcija izbacuju cifru iz broja
int izbaci_cifre_pomocna (int broj, int cifra)
{
	int count=0, l=0;  //l ce biti novi broj
	while (broj!=0) {
		if (fabs(broj%10)!=cifra) {
			l=l+broj%10 * pow(10,count);
			count++;
		}

		broj = broj/10;
	}

	return l;
}

int izbaci_cifre (int nizBr[], int brB, int nizCifre[], int brC)
{
	int i, j, m, n;
	//Provjeravamo da li je niz cifra validan
	for (i=0; i<brC; i++) {
		if (nizCifre[i]>9 || nizCifre[i]<0) return 0;
		for (j=i+1; j<brC; j++) {
			if (nizCifre[i]==nizCifre[j]) return 0;
		}
	}

	//Prolazimo kroz niz i na svaki element pozivamo izbaci_cifre_pomocna funkciju
	for (m=0; m<brB; m++) {
		for (n=0; n<brC; n++)
			nizBr[m] = izbaci_cifre_pomocna (nizBr[m], nizCifre[n]);
	}
	return 1;
}


int main()
{
	int nizBr[1000], nizCifre[10];
	int brB=0, brC=0, i, j,  p;

	//Unosenje nizova
	for (i=0;; i++) {
		scanf("%d", nizBr[i]);
		if(nizBr[i]=='\n') break;
		brB++;
	}

	for (j=0;; j++) {
		scanf("%d", nizCifre[j]);
		if(nizCifre[j]=='\n') break;
		brC++;
	}

	p=izbaci_cifre(nizBr,brB, nizCifre,brC); //Poziv funkcije

	//Printanje niza
	for (i=0; i<brB; i++) {
		printf ("%d", nizBr[i]);
	}
	return 0;
}
