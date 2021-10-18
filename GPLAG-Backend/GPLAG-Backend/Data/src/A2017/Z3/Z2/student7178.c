#include <stdio.h>
#include <math.h>

/*Funkcija "suma" vraca zbir cifara nekog realnog broja.*/
int suma(float broj)
{
	int a, i=0, zbir=0;
	broj=fabs(broj*10);
	while(broj!= 0) {
		a=(int)broj%10;
		broj=(int)broj/10;
		zbir+=a;
		i++;
	}
	return zbir;
}
/*Funkcija "zaokruzi1" prima niz realnih brojeva i sve clanove zaokruzuje na jednu decimalu. */
void zaokruzi1(float *niz, int vel)
{
	float *p=niz;
	while (p<niz+vel) {
		*p=round(*p*10)/10;
		p++;
	}
}

/*Funkcija "preslozi" sortira clanove niza tako da se prvo nalaze oni borjevi cija je suma cifara veca od zadanog broja k.*/
void preslozi(float *niz, int vel, int k)
{
	int i;
	float  *q;
	float niz_pom[100];

	zaokruzi1 (niz,vel);

	q=niz_pom;
	/*U pomocni niz smijestamo prvo sve clanove naseg niza cija je suma cifara veca od zadanog broja*/
	for(i=0; i<vel; i++) {
		if(suma(*(niz+i))>=k) {
			*q=*(niz+i);
			q++;
		}
	}
	/*Sada u pomocni niz smijestamo one clanove niza cija je suma cifara manja od zadanog broja*/
	for(i=0; i<vel; i++) {
		if(suma(*(niz+i))<k) {
			*q=*(niz+i);
			q++;
		}
	}
	/*Clanove pomocnog niza redom smijestamo u nas prvobitni niz*/
	for(i=0; i<vel; i++) {
		*(niz+i)=*(niz_pom+i);
	}

}

int main()
{
	int i, vel, k;
	float niz[100];
	scanf("%d\n",&vel);
	scanf("%d\n", &k);
	for(i=0; i<vel; i++) {
		scanf("%f ", &niz[i]);
	}

	preslozi(niz,vel,k);

	printf("Niz glasi: ");
	for(i=0; i<vel; i++) {
		printf("%g ", niz[i]);
	}
	return 0;
}
