#include <stdio.h>


float zaokruzi_broj(float br)
{
	/* +- 0.0000005 je zbog toga reprezentacije broja u memorij */
	int n, neg = 1;
	if(br > 0)
		n = br * 100 + 0.000000005;
	else{
		br *= -1;
		neg = -1;
		n = br * 100 - 0.000000005;
	}
		
	if(n % 10 >= 5)
		n += 10;
		
	return (n / 10) / 10. * neg;
}

void zaokruzi1(float* niz, int velicina)
{
	int i = 0;
	for(; i < velicina; ++i)
		niz[i] = zaokruzi_broj(niz[i]);
}

int suma_cifara(float br)
{
	if(br < 0)
		br*=-1;
	int n = br * 10;
	int suma = 0;
	for(; n != 0; n /= 10)
		suma += n % 10;
	return suma;
}


void zamijeni(float* niz, int velicina, int index, int mjesto)
{
	/* pamtim broj prije izbacivanja */
	float br = niz[index];
	
	/* izbacivanje */
	int i = index;
	int j = index + 1;
	for(; j < velicina; ++j, ++i)
		niz[i] = niz[j];
	--velicina;
	
	/* pravljenje prostora za ubacivanje broja */
	i = velicina;
	j = velicina - 1;
	for(; j >= mjesto; --j, --i)
		niz[i] = niz[j];
		
	/* ubacujem broj */	
	niz[mjesto] = br;
}

void preslozi(float* niz, int velicina, int k)
{
	zaokruzi1(niz, velicina);
	int i = 0;
	/* dolazimo do broja cija suma je manja od k */
	for(; i < velicina && suma_cifara(niz[i]) >= k; ++i)
		; /* bez tijela */
		
	/* ako je i doslo do kraja nemamo sta mijenjati */
	if (i == velicina)
		return;
	int prvi_manji = i;
	for(i = i + 1; i < velicina; ++i)
		if(suma_cifara(niz[i]) >= k)
		{
			/* "sortiramo" */
			zamijeni(niz, velicina, i, prvi_manji);
			++prvi_manji;
		}
	
}

int main() {
	printf("Zadaća 3, Zadatak 2");
	return 0;
}
