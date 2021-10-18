#include <stdio.h>
#include <math.h>

/* Funkcija koja zaokruzuje sve clanove niza na 1 decimalu: */
void zaokruzi1(float niz[], int vel) {
	int i;
	for (i=0; i<vel; i++) {
		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i]/=10;
	}
	return;
}
void preslozi(float niz[], int vel, int k) {
	int i, suma_cifara, temp, j=0, l=0, p;
	float temp2;
	
	zaokruzi1(niz, vel);
	
	for (i=0; i<vel; i++) {
		/* Svaki clan niza postavljamo na promjenjivu kako ne bismo mijenjali njihovu vrijednost. */
		/* Mnozimo sa 10 da bismo radili sa cjelobrojnim vrijednosima: */
		temp=fabs(niz[i]*10);
		suma_cifara=0;
		do {
			suma_cifara+=temp%10;
			temp/=10.;
		} while(temp>0);
		
		temp2=niz[i];
		
		/* Clanove cija je suma cifara veca od ili jednaka datom broju k stavljamo na pocetak niza: */
		if (suma_cifara>=k) {
			temp2=niz[i];
			/* Ostale clanove pomjeramo za jedno mjesto uz ocuvanje redoslijeda: */
			for (p=i; p>l; p--) {
				niz[p]=niz[p-1];
			}
			niz[l]=temp2;
			l++;
			j++;
		}
		else {
			niz[j]=niz[i];
			j++;
		}
	}
	return;
}
int main() {
	printf("Zadaća 3, Zadatak 2");
	return 0;
}
