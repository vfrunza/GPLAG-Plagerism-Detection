#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz, int velicina_niza)
{
	int i;

	for(i = 0; i < velicina_niza; i++) {
		niz[i] = (round(niz[i] * 10)) / 10;
	}
}

int suma_cifri(float br)							
{
	int suma = 0;
	int temp = (br * 10);

	if (temp < 0) temp = -temp;							

	while(temp != 0) {
		suma += (temp % 10);
		temp /= 10;
	}
	return suma;
}

void preslozi (float niz[200], int velicina_niza, int k)
{
	float* clan, novi_niz[200], *trenutni;
	
	zaokruzi1(niz, velicina_niza);
	
	clan = niz;
	trenutni = novi_niz;

	for(; clan < niz + velicina_niza; clan++) {
		if(suma_cifri(*clan) >= k) {
			*trenutni = *clan;
			trenutni++;
		}
	}
	clan = niz;

	for(; clan < niz + velicina_niza; clan++) {

		if(suma_cifri(*clan) < k) {
			*trenutni = *clan;
			trenutni++;
		}
	}
	
	clan = niz;
	trenutni = novi_niz;

	for(; clan < niz + velicina_niza; clan++) {
		*clan = *trenutni;
		trenutni++;
	}
}

int main()
{
	float niz[100];
	int i, vel;
	
	printf("Unesite velicinu niza: ");
	scanf("%d",&vel);
	
	printf("Unesite clanove niza: ");
	for(i = 0; i < vel; i++) {
		scanf("%f",&niz[i]);
	}

	preslozi(niz,vel,4);
	
	for(i = 0; i < vel; i++) {
		printf("%g ",niz[i]);
	}
	
	return 0;
}
