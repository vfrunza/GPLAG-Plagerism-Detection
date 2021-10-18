#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void zaokruzi1(float *niz, int vel)
{
	float *p = niz;
	while (p < niz+vel) {
		*p = round(*p*10);
		*(p++) /= 10;
	}
}

int suma(float x,int l)
{
	int suma=0;
	int cifra,broj;
	x=x*10;
	broj=abs((int)x);
	while(broj!=0) {
		cifra=broj%10;
		suma+=cifra;
		broj/=10;
	}
	if(suma>=l)
		return 1;
	else
		return 0;
}

void zamjena(float *x, float *y)
{
	float temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void preslozi(float *niz,int vel,int l)
{
	float *q=niz;
	float *p=niz;

	zaokruzi1(niz,vel);

	while(q<niz+vel) {

		if(suma(*q,l)) {
			while(q>p) {
				zamjena(q,q-1);  /* Zamjenjuje unazad elemente, jedan po jedan, pocevsi od elementa koji ispunjava uslov ka pocetku niza */
				q--;
			}
			p++;
		}
		q++;
	}
}

int main()
{
	/* Test */
	int i,n,k;
	float niz[100];

	printf("Unesite velicinu niza: \n");
	scanf("%d",&n);

	printf("Unesite elemente niza: \n");
	for(i=0; i<n; i++)
		scanf("%f",niz+i);

	printf("Unesite k (za sumu): \n");
	scanf("%d",&k);

	preslozi(niz,n,k);

	printf("Niz glasi: \n");
	for(i=0; i<n; i++)
		printf("%g ",niz[i]);

	return 0;
}
