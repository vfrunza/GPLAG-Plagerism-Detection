#include <stdio.h>

void zaokruzi1 (float niz[], int velicina)
{

	int i;

	for (i=0; i<velicina; i++) {

		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i] /= 10;
	}

}

void preslozi (float niz[], int velicina2, int k)
{

}