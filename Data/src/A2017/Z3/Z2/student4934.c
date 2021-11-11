#include <stdio.h>
#include <math.h>

void zaokruzi1(float* niz, int velicina_niza)
{
	int i;
	for (i=0; i<velicina_niza; i++) {
		niz[i]=niz[i]*10;
		niz[i]=round(niz[i]);
		niz[i]=niz[i]/10;
	}
}

void preslozi(float* niz, int velicina_niza, int k)
{
	int i, brojac_vecih=0, brojac_manjih=0, suma=0, cifra, temp;
	float  prvi_niz[1000], drugi_niz[1000], konacni_niz[1000];

	zaokruzi1(niz, velicina_niza);

	for (i=0; i<velicina_niza; i++) {
		temp=niz[i]*10;
		suma=0;

		while (temp!=0) {
			cifra=temp%10;
			suma+=fabs(cifra);
			temp/=10;
		}

		if (suma>=k) {
			prvi_niz[brojac_vecih]=niz[i];
			brojac_vecih++;
		} else if (suma<k) {
			drugi_niz[brojac_manjih]=niz[i];
			brojac_manjih++;
		}
	}
	for (i=0; i<brojac_vecih; i++) {
		konacni_niz[i]=prvi_niz[i];
	}
	for (i=brojac_vecih; i<brojac_vecih+brojac_manjih; i++) {
		konacni_niz[i]=drugi_niz[i-brojac_vecih];
	}
	for (i=0; i<brojac_vecih+brojac_manjih; i++) {
		niz[i]=konacni_niz[i];
	}
}

int main()
{
	float niz[100];
	int i, k, velicina_niza=0;
	printf ("Unesite niz: \n");
	for (i=0; i<100; i++) {
		scanf ("%f" , &niz[i]);
	}
	i=velicina_niza;
	printf ("Unesite broj koji cete porediti sa sumom cifara niza: \n");
	scanf ("%d" , &k);
	zaokruzi1(niz, velicina_niza);
	return 0;
}
