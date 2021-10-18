#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int duzina)
{
	int i;

	for(i = 0; i < duzina; i++) {
		niz[i]=(round(niz[i]*10))/10;
	}

}

void preslozi(float niz[], int duzina, int k)
{
	int i,suma_cifara[1000]= {0},broj,j,cifra,brojac=0,t=0,p=0;
	float niz_veci[1000],niz_manji[1000];

	zaokruzi1(niz,duzina);

	for(i = 0; i < duzina; i++) {
		broj=niz[i]*10;
		for(j = 0; broj!=0 ; j++) {
			cifra=fabs(broj%10);
			broj/=10;
			suma_cifara[i]+=cifra;
		}
	}


	for(i = 0; i < duzina; i++) {
		if(suma_cifara[i]>=k) {
			niz_veci[t]=niz[i];
			brojac++;
			t++;
		} else {
			niz_manji[p]=niz[i];
			p++;
		}

	}
	for(i = 0; i < brojac; i++) {
		niz[i]=niz_veci[i];
	}
	p=0;
	for(i = brojac; i < duzina; i++) {
		niz[i]=niz_manji[p];
		p++;
	}
}
int main()
{
	int i,duzina,k;
	float niz[100];
	printf("Unesite duzinu niza: ");
	scanf("%d",&duzina);
	printf("Unesite clanove niza: \n");
	for(i = 0; i < duzina; i++) {
		printf("%d. clan niza: ",i+1);
		scanf("%f",&niz[i]);
	}
	printf("Unesite k: ");
	scanf("%d",&k);

	preslozi(niz,duzina,k);

	printf("Niz nakon preslaganja: \n");
	for(i = 0; i < duzina; i++) {
		if(i!=duzina-1)
			printf("%g, ",niz[i]);
		else
			printf("%g",niz[i]);
	}
	return 0;
}
