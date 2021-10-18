#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void zaokruzi1(float niz[], int vel)
{
	float *p=niz;
	while(p<niz+vel) {
		*p*=10;
		*p=round(*p);
		*p++/=10;
	}
}

void preslozi (float niz[], int vel, int k)
{
	int c,suma=0,i;
	int pom,p;
	float m;
	float niz1[1000];
	int brojac=0,l=0;
	zaokruzi1(niz,vel);
	for(i=0; i<vel; i++) {
		suma=0;
		m=((fabs(niz[i]-(int)niz[i])+0.02)*10);
		suma+=m;
		pom=niz[i];
		if(pom<0)
			pom*=-1;
		while(pom!=0) {
			c=(pom%10);
			pom=pom/10;
			suma+=c;
		}
		if(suma>=k) {
			niz[brojac]=niz[i];
			brojac++;
		} else {
			niz1[l]=niz[i];
			l++;
		}
	}
	p=0;
	for(i=brojac; i<vel; i++) {
		niz[i]=niz1[p];
		p++;
	}
}

int main()
{
	int i,k,niz[100],vel;
	printf("Unesite prirodan broj k: ");
	scanf("%d",&k);

	printf("Unesite velicinu niza: ");
	scanf("%d",&vel);

	printf("Unesite clanove niza: ");
	for(i=0; i<vel; i++) {
		scanf("%d", &niz[i]);
	}
	printf("Niz nakon preslaganja: ");
	return 0;
}
