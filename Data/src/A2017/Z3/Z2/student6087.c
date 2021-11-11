#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz, int velicina)
{
	float *p = niz;
	while (p < niz+velicina) {
		*p *= 10;
		*p = round(*p);
		*p++ /= 10;
	}
}

int suma(float clan)
{
	int suma1=0;
	clan = clan * 10;
	while (fabs(clan) > 0) {
		suma1 += (int)clan % 10;
		clan /= 10;
	}
	return fabs(suma1);
}

void preslozi(float *niz, int velicina, int k1)
{
	int i,j;
	int brojac = 0;
	float a;
	zaokruzi1(niz,velicina);
	for (i = 0; i<velicina; i++) {
		if(suma(niz[i]) >= k1) {
			j = i;
			a = niz[i];
			while(j>brojac) {
				niz[j] = niz[j-1];
				j--;
			}
			niz[brojac] = a;
			brojac++;
		}
	}
}

int main()
{
	int i,n,k;
	float niz1[100];

	printf("Unesite velicinu niza: ");
	scanf("%d", &n);

	printf("Unesite elemente niza: ");
	for (i=0; i<n; i++) {
		scanf("%f", &niz1[i]);
	}
	do {
		printf("Unesite k: ");
		scanf("%d", &k);
	} while (k<1);

	/* Provjera sume
	 for(i=0; i<n; i++) {
	printf("%d ", suma(niz1[i]));
	}*/

	preslozi(niz1,n,k);

	return 0;
}
