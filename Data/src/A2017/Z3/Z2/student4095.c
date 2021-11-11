#include <stdio.h>
#include <math.h>


void zaokruzi1 (float niz[100], int brojClanova)
{
	int i;
	for(i = 0; i < brojClanova; i++) {
		niz[i] = roundf(niz[i] * 10) / 10;
	}
}


int zbirCifara(float x)
{
	int zbirCifara = 0;
	int cijeliBroj = 10*x;
	if(cijeliBroj < 0) {
		cijeliBroj = -cijeliBroj;
	}
	while(cijeliBroj != 0) {
		zbirCifara += cijeliBroj % 10;
		cijeliBroj /= 10;
	}
	return zbirCifara;
}


void preslozi(float niz[100], int brojClanova, int k)
{

	zaokruzi1(niz,brojClanova);

	float *trenutni = niz;

	float noviNiz[100];

	float *trenutniNovi = noviNiz;

	while(trenutni < niz + brojClanova) {
		if(zbirCifara(*trenutni) >= k) {
			*trenutniNovi = *trenutni;
			trenutniNovi++;
		}
		trenutni++;
	}

	trenutni = niz;

	while(trenutni < niz + brojClanova) {
		if(zbirCifara(*trenutni) < k) {
			*trenutniNovi = *trenutni;
			trenutniNovi++;
		}
		trenutni++;
	}

	trenutni = niz;

	trenutniNovi = noviNiz;

	while(trenutni < niz + brojClanova) {
		*trenutni = *trenutniNovi;
		trenutniNovi++;
		trenutni++;
	}
}

int main()
{
	int brojClanova, i, k;
	float niz[100];
	
	printf("Unesite broj clanova niza: ");
	scanf("%d", &brojClanova);
	printf("Unesite niz: ");
	for(i = 0; i < brojClanova; i++) {
		scanf("%f", &niz[i]);
	}
	scanf("%d", &k);

	preslozi(niz,brojClanova,k);

	return 0;
}
