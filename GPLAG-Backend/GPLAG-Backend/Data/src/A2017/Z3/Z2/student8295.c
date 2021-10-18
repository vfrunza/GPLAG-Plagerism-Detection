#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*funkcija koja sve clanove niza zaokruzuje na jednu decimalu*/
void zaokruzi1 (float niz[],int vel)
{
	int i;

	for(i=0; i<vel; i++) {
		niz[i]=round(niz[i]*10.0)/10.0;
	}

}

/*funkcija koja racuna sumu cifara clanova niza*/
int sumaCifara (double x)
{
	int ostatak,cifra,broj;
	float suma=0,dec;
	x=fabs(x);
	dec=x- (int) x;
	dec=(dec+0.05);
	cifra=dec*10;
	broj=(int) x;
	suma=cifra;

	while(broj!=0) {
		ostatak=broj%10;
		suma+=ostatak;
		broj=broj/10;

	}
	return suma;

}

/*funkcija koja preslaze niz*/
void preslozi (float niz[], int vel, int k)
{
	int i,j;
	zaokruzi1(niz,vel); /*poziv funkcije zaokruzi1*/

	j=0;
	for(i=0; i<vel; i++) {
		j=i;
		while(j>0 && sumaCifara(niz[j])>=k && sumaCifara(niz[j-1])<k) {
			float tmp=niz[j];
			niz[j]=niz[j-1];
			niz[j-1]=tmp;
			j--;
		}
	}
}


int main(void)
{

	int i,vel,k;
	float niz[5];
	printf("Unesi velicinu niza: ");
	scanf("%d",&vel);

	printf("Unesi k: ");
	scanf("%d",&k);

	printf("Unesi niz: ");

	for(i=0; i<vel; i++) {
		scanf("%f",&niz[i]);
	}

	/*poziv funkcije preslozi(na pocetku niza se nalaze svi clanovi cija je suma cifara veca ili jednaka k,a zatim oni clanovi cija je suma cifara manja od k)*/
	preslozi(niz,vel,k);

	printf("Niz glasi: ");
	for(i=0; i<vel; i++) {
		printf("%g ",niz[i]);
	}

	return 0;
}
