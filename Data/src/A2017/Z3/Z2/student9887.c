#include <stdio.h>
#include <math.h>

/* funkcija zaokruzuje broj na jednu decimalu */
void zaokruzi1(float* niz, int vel)
{
	float *p;
	p=niz;
	while(p<niz+vel) {
		*p=round(*p*10)/10;
		p++;
	}
}

void preslozi(float* niz, int vel, int k)
{
	int cifra, suma_cifara=0, pom, i, j, ind_za_ubacivanje=0;
	float temp;
	zaokruzi1(niz,vel);
	for(i=0; i<vel; i++) {
		pom=fabs(niz[i]*10);
		/* trazimo sumu cifara nekog broja iz niza */
		while(pom!=0) {
			cifra=pom%10;
			suma_cifara+=cifra;
			pom=pom/10;
		}
		/* preslazemo clanove niza na osnovu uslova u if-naredbi */
		if(suma_cifara>=k) {
			temp=niz[i];
			for(j=i; j>ind_za_ubacivanje; j--) {
				niz[j]=niz[j-1];
			}
			niz[ind_za_ubacivanje++]=temp;
		}
		suma_cifara=0;
	}
}

int main()
{

	return 0;
}
