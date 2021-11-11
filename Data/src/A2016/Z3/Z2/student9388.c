#include <stdio.h>
#include <stdlib.h>

int SumaCifara (int broj) {
	int cifre [10]={0}, j=0, suma=0, brojac=0;
	while (broj!=0) {
		cifre[j]=broj%10;
		broj=broj/10;
		j++;
		brojac++;
	}
	for (j=0; j<brojac; j++) {
		suma=suma+cifre[j];
	}
	return abs(suma);
}

void ubaci (int *niz, int size) {
	int n[100]; /*Kreiramo novi niz*/
	int i=0;
	
	for (i=0; i<size; i++) {
		n[i]=niz[i]; /*Napunimo novi niz elementima starog niza.*/
	}

	for (i=0; i<size; i++) {
		niz[2*i]=n[i];
		niz[2*i+1]=SumaCifara(n[i]); /*Upisivanje novih elemenata u stari niz.*/
	}
	niz[2*size]='\0';
}

int izbaci (int *niz, int size) {
	int f[100], i=0, brojac=0, j=0, k=0;
	f[0]=1;
	f[1]=1;
	
	for (i=2; i<100; i++) {
		f[i]=f[i-1]+f[i-2]; /*Napunili smo Fibonaccijev niz.*/
	}
	int n[100]; /*Kreiramo novi niz.*/
	
	for (i=0; i<size; i++) {
		n[i]=niz[i]; /*Napunimo novi niz elementima starog niza.*/
	}

	for (i=0; i<size; i++) {
		for (j=0; j<100; j++) {
			if (f[j]==n[i]) {
				k=1;
				break;
			}
			else k=0; 
		}
		if (k==0) {
			niz[brojac]=n[i];
			brojac++;
		}
	}
	return brojac;
}

int main() {
	/*printf("Zadaća 3, Zadatak 2");*/
	int niz[100];
	int i=0, k=0;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++) {
		scanf ("%d", &niz[i]);
	}
	
	ubaci(niz,10);

	k=izbaci(niz,20);
	
	printf ("Modificirani niz glasi: ");
	
	for (i=0; i<k; i++) {
		if (i==(k-1)) printf ("%d. ", niz[i]);
		else printf ("%d, ", niz[i]);
	}
	
	return 0;
}
