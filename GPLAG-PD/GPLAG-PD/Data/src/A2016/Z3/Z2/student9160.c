#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#define duzina 10
void ubaci(int *niz,int velicina)
{
	int broj,broj2=0,cifra,i,j;
	for(j=velicina-1; j>=0; j--)niz[2*j]=niz[j];
	for(i=0; i<2*velicina; i+=2) 
	{
		broj=abs(niz[i]);
		if(broj<10)broj2=broj;
		else {
			do {
				cifra=broj%10;
				broj2+=cifra;
				broj/=10;
			} while(broj!=0);
		}
		niz[i+1]=broj2;
		broj2=0;
	}
}
int izbaci(int *niz, int velicina)
{
	int j,prvi=0,drugi=1,treci,i;
	for(i=0; i<velicina; i++) {
		prvi=0;
		drugi=1;
		for(j=1; j<10000; j++) {
			if(j==1)treci=1;
			else {
				treci=prvi+drugi;
				prvi=drugi;
				drugi=treci;
			}
			if(niz[i]==treci) {
				int k;
				for(k=i; k<velicina-1; k++)niz[k]=niz[k+1];
				velicina--;
				i--;
				break;
			}
		}
	}
	return velicina;
}

int main()
{
	int niz[2*duzina],i,pozivanje;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<duzina; i++)scanf("%d",&niz[i]);
	ubaci(niz,duzina);
	pozivanje=izbaci(niz,2*duzina);
	printf("Modificirani niz glasi: ");
	for(i=0; i<pozivanje; i++)
		if(i==pozivanje-1)printf("%d.",niz[i]);
		else printf("%d, ",niz[i]);
	return 0;
}
