#include <stdio.h>
#include <math.h>
#define max 100000
/*funkcija za zaokruzivanje brojeva na jednu decimalu*/
void zaokruzi1(float *niz, int velicina)
{
	float* pok=niz;
	while(pok<niz+velicina) {
		if(*pok>=0) {
			*pok *=10;
			*pok=(int)(*pok + 0.5);
			*pok/=10;
			pok++;
		} else {
			*pok *=10;
			*pok=(int)(*pok - 0.5);
			*pok/=10;
			pok++;
		}
	}
}
/*pomocna funkcija za izracunavanje sume cifara nekog broja*/
int suma_cifara(int broj)
{
	int suma=0,cifra;
	if(broj<0) broj=fabs(broj);
	while(broj!=0) {
		cifra=broj%10;
		suma+=cifra;
		broj/=10;
	}
	return suma;
}
/*pomocna funkcija za sortiranje niza*/
void sortiraj(float *niz, int velicina, int k)
{
	int i, br_vecih, br_manjih;
	float pomocni_niz[max];
	float *pok=niz;
	for(i=0; i<velicina; i++) {
		pomocni_niz[i]=niz[i];
	}
	br_vecih=0;
	for(i=0; i<velicina; i++) {
		if(suma_cifara(pomocni_niz[i]*10)>=k) {
			niz[br_vecih]=pomocni_niz[i];
			br_vecih++;
		}
	}
	br_manjih=br_vecih;
	for(i=0; i<velicina; i++) {
		if(suma_cifara(pomocni_niz[i]*10)<k) {
			niz[br_manjih]=pomocni_niz[i];
			br_manjih++;
		}
	}
	niz=pok;
}
/*funkcija preslozi*/
void preslozi(float *niz, int velicina, int k)
{
	zaokruzi1(niz,velicina);
	sortiraj(niz,velicina,k);
}
int main()
{
	float niz[max];
	int i,k, br=0;
	printf("Unesite niz: ");
	for(i=0; i<max; i++) {
		scanf("%f", &niz[i]);
		br++;
		if(niz[i]==-1) break;
	}
	printf("Unesite broj: ");
	scanf("%d", &k);
	zaokruzi1(niz,br);
	printf("Zaokruzeni niz: ");
	for(i=0; i<br-1; i++)
		printf("%g ",niz[i]);
	preslozi(niz,br,k);
	printf("Preslozeni niz: ");
	for(i=0; i<br-1; i++)
		printf("%g ",niz[i]);
	return 0;
}
