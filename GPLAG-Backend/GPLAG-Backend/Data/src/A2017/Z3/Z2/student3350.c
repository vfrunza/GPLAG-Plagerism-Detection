#include <stdio.h>
#include <stdlib.h>
void zaokruzi1(float niz[],int duzina)
{
	int i;
	for(i=0; i<duzina; i++) {
		if(niz[i]>=0) {
			niz[i]=niz[i]*10;
			niz[i]=(int)(niz[i]+0.5);
			niz[i]/=10;
		}
		if(niz[i]<0) {
			niz[i]=niz[i]*(-10);
			niz[i]=(int)(niz[i]+0.5);
			niz[i]=niz[i]/(-10);
		}
	}
}
int suma_cifara(float broj)
{
	int suma=0,cifra,novi=0;
	broj*=10;
	novi=(int)broj;
	while(novi!=0) {
		cifra=novi%10;
		suma+=cifra;
		novi/=10;
	}
	return suma;
}
void preslozi(float niz[],int duzina,int k)
{

	int i,j=0,s=0,n=0,suma=0;
	float bbc[100],manji[100],veci[100];
	zaokruzi1(niz,duzina);
	for(i=0; i<duzina; i++) {
		bbc[i]=niz[i];
	}
	for(i=0; i<duzina; i++) {
		suma=suma_cifara(niz[i]);
		if(suma<0) suma=abs(suma);
		if(suma>=k) {
			veci[j]=bbc[i];
			j++;
		} else {
			manji[s]=bbc[i];
			s++;
		}
	}

	for(i=0; i<j; i++) {
		niz[i]=veci[i];
	}
	k=0;
	for(i=j; i<duzina; i++) {
		niz[i]=manji[n];
		n++;
	}
}
int main()
{
	int i,duzina=0,k=14;
	float niz[100];
	printf("Unesite velicinu niza: ");
	scanf("%d",&duzina);
	printf("Unesite niz: ");
	for(i=0; i<duzina; i++) {
		scanf("%f",&niz[i]);
	}
	preslozi(niz,duzina,k);
	printf("NIz glasi: ");
	for(i=0; i<duzina; i++)
		printf("%.1f ",niz[i]);
}