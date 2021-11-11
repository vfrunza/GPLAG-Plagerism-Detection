#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int vel_niza)
{
	int i;
	for(i=0; i<vel_niza; i++)
		niz[i]=(round(niz[i]*10))/10;
}

int suma_cifara(float broj)
{
	int suma=0, temp, pom1;
	broj*=10;
	pom1=broj;
	while(pom1!=0) {
		temp=pom1%10;
		pom1/=10;
		suma+=temp;
	}
	return suma;
}

void preslozi(float niz[], int vel_niza, int k)
{
	int i, j, br_promjene=0;
	float pom;
	zaokruzi1(niz, vel_niza);
	for(i=0; i<vel_niza; i++) {
		if(suma_cifara(fabs(niz[i]))>=k) {
			for(j=i; j>br_promjene; j--) {
				pom=niz[j];
				niz[j]=niz[j-1];
				niz[j-1]=pom;
			}
			br_promjene++;
		}
	}
}

int main()
{
	/*	printf("Zadaća 3, Zadatak 2");*/
	return 0;
}
