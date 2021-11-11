#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void zaokruzi1(float niz[],int velicina)
{
	int i=0;
	float *p=niz;

	for(i=0; i<velicina; i++) {
		*p*=10;
		*p=round(*p);
		*p/=10;
		p++;
	}
}

int suma(float broj)
{
	int sabiraj=0;
	broj*=10;

	while(fabs(broj)>0) {
		sabiraj=sabiraj+(int)broj%10;
		broj/=10;
	}
	return fabs(sabiraj);
}

void preslozi(float niz[],int velicina,int k)
{
	float noviNiz1[100],noviNiz2[100],noviNiz3[100];
	int z=0,j=0,brojac1=0,i,brojac2=0,rez;

	zaokruzi1(niz,velicina);

	for(i=0; i<velicina; i++) {
		rez=suma(niz[i]);
		if( rez>=k)  {
			noviNiz1[j]=niz[i];
			j++;
			brojac1++;
		}
	}

	for(i=0; i<velicina; i++) {
		rez=suma(niz[i]);
		if(rez<k) {
			noviNiz2[z]=niz[i];
			z++;
			brojac2++;
		}
	}

	for(i=0; i<brojac1; i++)
		noviNiz3[i]=noviNiz1[i];
	for(i=0; i<brojac2; i++)
		noviNiz3[i+brojac1]=noviNiz2[i];
	for(i=0; i<velicina; i++)
		niz[i]=noviNiz3[i];
}

int main()
{
	int i=0,velicina,k;
	float niz[100];
	printf("Unesite velicinu niza: ");
	scanf("%d",&velicina);
	printf("Unesite clanove niza: ");
	for(i=0; i<velicina; i++)
		scanf("%f",&niz[i]);
	printf("\nUnesite k: ");
	scanf("%d",&k);
	preslozi(niz,velicina,k);
	printf("Niz glasi: ");
	for(i=0; velicina; i++)
		printf("%g",niz[i]);
	return 0;
}