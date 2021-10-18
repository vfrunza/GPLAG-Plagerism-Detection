#include <stdio.h>
#include <math.h>
#define DUZINA 200

void zaokruzi1(float niz[], int broj)
{
	int i=0;
	for (i=0; i<broj; i++)
		niz[i]=roundf(niz[i]*10)/10;
}

int suma_cifara(float c)
{
	int suma=0, cifra=0;
	int pom=c*10;
	if(pom<0) pom=-pom;
	while(pom!=0) {
		cifra=pom%10;
		suma+=cifra;
		pom/=10;
	}
	return suma;
}

void preslozi(float niz[], int velicina, int k)
{
	int i, velicina1=0, velicina2=0;
	float niz1[DUZINA]= {0}, niz2[DUZINA]= {0};
	zaokruzi1(niz,velicina);
	for (i=0; i < velicina; i++) {
		if (suma_cifara(niz[i])>k) {
			niz1[i]=niz[i];
			velicina1++;
		} else {
			niz2[i]=niz[i];
			velicina2++;
		}
	}
	for (i=0; i<velicina1; i++)
		niz[i]=niz1[i];
	for (i=velicina1; i<velicina; i++)
		niz[i]=niz2[i];

}


/*float preslozi(float niz[], int vel, int k) {

	int i, suma=0, cifra, j, clan, n=0;
	float *pok;
	float niz1[100];

	zaokruzi(niz,vel);

	for(i=0;i<vel;i++) {
		niz1[i]=niz[i];
	}

	for(i=0;i<vel;i++) {
		clan=niz[i];
		niz[i]*=10;
		while(niz[i]!=0) {
		cifra=(int)niz[i]%10;
		suma+=cifra;
		niz[i]/=10; }

		if(suma>=k) {
			for(j=0;j<vel;j++) {
				niz[j]=clan;
				n++;
				}
			}
		}

		for(i=0;i<vel;i++) {
		clan=niz1[i];
		niz1[i]*=10;
		while(niz1[i]!=0) {
		cifra=(int)niz1[i]%10;
		suma+=cifra;
		niz1[i]/=10; }

		if(suma<k) {
			for(j=n;j<vel;j++) {
				niz[j]=clan;
				}
			}
		}
		*pok=niz[0];
		return pok;

}*/
int main()
{
	float niz[DUZINA];
	int i, vel, k;

	printf("Unesi velicinu: ");
	scanf("%d", &vel);
	printf("Niz: ");
	for(i=0; i<vel; i++) {
		scanf("%f", &niz[i]);
	}
	printf("k: ");
	scanf("%d", &k);
	preslozi(niz,vel,k);
	for(i=0; i<vel; i++) {
		printf("%f ", niz[i]);
	}
	/*printf("Zadaća 3, Zadatak 2");*/
	return 0;
}

/*
float preslozi(float niz[], int vel, int k) {

	int i, suma=0, cifra, j, clan, n=0;
	float *pok;
	float niz1[100];

	zaokruzi(niz,vel);

	for(i=0;i<vel;i++) {
		niz1[i]=niz[i];
	}

	for(i=0;i<vel;i++) {
		clan=niz[i];
		niz[i]*=10;
		while(niz[i]!=0) {
		cifra=(int)niz[i]%10;
		suma+=cifra;
		niz[i]/=10; }

		if(suma>=k) {
			for(j=0;j<vel;j++) {
				niz[j]=clan;
				n++;
				}
			}
		}

		for(i=0;i<vel;i++) {
		clan=niz1[i];
		niz1[i]*=10;
		while(niz1[i]!=0) {
		cifra=(int)niz1[i]%10;
		suma+=cifra;
		niz1[i]/=10; }

		if(suma<k) {
			for(j=n;j<vel;j++) {
				niz[j]=clan;
				}
			}
		}
		*pok=niz[0];
		return *pok;

}*/