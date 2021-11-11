#include <stdio.h>
#include <math.h>

float zaokruzi1 (float* pok, int velicina) {
	int i;
	
	for (i=0; i<velicina; i++) {
		pok[i]=((round) (pok[i]*10))/10;
	}

	return pok[i];
}

float preslozi (float* pok, int velicina, int k) {

	zaokruzi1(pok,velicina);
	int suma_cifara[100]={0};
	int i,j,zamjena;
	int brojac=0;
	float pomocni_niz[1000];
	
	for (i=0; i<velicina; i++) {
		pok[i]*=10;
		zamjena=pok[i];
		zamjena=fabs (zamjena);
		pok[i]/=10; 
		while (zamjena!=0) {
			suma_cifara[i]+=zamjena%10;
			zamjena=zamjena/10;
			
	}
}
	
	for (i=0; i<velicina; i++) 
		pomocni_niz[i]=pok[i];
	for (i=0; i<velicina; i++) {
		if (suma_cifara[i]>=k) {
			pok[brojac]=pomocni_niz[i];
			brojac++;
		}
	}
		for (i=0; i<velicina; i++) {
			if (suma_cifara[i]<k) {
				pok[brojac]=pomocni_niz[i];
				brojac++;
		}
	}
		
	return pok[i];
}		


int main() {
	float niz[100];
	int vel,i,k;
	printf ("Unesite velicinu niza: ");
	scanf ("%d", &vel);
	printf ("Unesite clanove niza: ");
	for (i=0; i<vel; i++) scanf ("%f", &niz[i]);
	zaokruzi1 (niz,vel);
	printf ("Niz glasi: ");
	for (i=0; i<vel; i++) {
		printf ("%g ", niz[i]);
	}
	printf ("Unesite k: ");
	scanf ("%d", &k);
	preslozi(niz,vel,k);
	printf ("Niz glasi: ");
	for (i=0; i<vel; i++) {
		printf ("%g ", niz[i]);
	}
	
	
	return 0;
}
	
	