#include <stdio.h>

int izbaci_iz_niza(int* niz, int velicina, int val)
{
	int i = 0;
	for(; i < velicina; ++i)
		if(niz[i] == val)
		{
			int j = i + 1;
			for(; j < velicina; ++j)
				niz[j - 1] = niz[j];
			--velicina;
			--i;
		}
	return velicina;
}


int niz_u_broj(int* niz, int velicina)
{
	int d = 1, br = 0, i = 0;
	for(; i < velicina; ++i)
	{
		br += niz[i] * d;
		d*=10;
	}
	return br;
}

void broj_u_niz(int* niz, int velicina, int broj)
{
	if(broj < 0)
		broj *= -1;
	int i = 0;
	for(; i < velicina && broj != 0; ++i, broj /= 10)
		niz[i] = broj % 10;
		
}


int broj_cifara(int broj)
{
	if(broj < 0)
		broj *= -1;
	int brojac = 0;
	for(;broj != 0; broj /= 10)
		++brojac;
	return brojac;
}

int provjera_cifara(int* niz, int velicina)
{
	int i = 0;
	for(; i < velicina; ++i)
	{
		if(niz[i] < 0 || niz[i] > 9)
			return 0;
		int j = i + 1;
		for(; j < velicina; ++j)
			if(niz[i] == niz[j])
				return 0;
	}
	return 1;
}

int izbaci_cifre(int* niz, int velicina, int* cifre, int velicina_c)
{
	if(provjera_cifara(cifre, velicina_c) == 0)
		return 0;
	int i = 0;
	for(; i < velicina; ++i)
	{
		int broj_niz[20];
		int broj_c = broj_cifara(niz[i]);
		broj_u_niz(broj_niz, broj_c, niz[i]);
		int j = 0;
		for(; j < velicina_c; ++j)
			broj_c = izbaci_iz_niza(broj_niz, broj_c, cifre[j]);
		if(broj_c == 0)
		{
			niz[i] = 0;
			continue;
		}
		int neg = 1;
		if(niz[i] < 0)
			neg = -1;
		niz[i] = niz_u_broj(broj_niz, broj_c) * neg;	
	}
	return 1;
}

int main() {
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
