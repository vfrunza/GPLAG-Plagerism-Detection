#include <stdio.h>
#include <math.h>

void zaokruzi1(float* niz,int vel)
{
	float *p=niz;
	/*Zaokruzujemo sve brojeve u nizu preko pokazivaca*/
	while(p<niz+vel) {
		*p*=10;
		*p=round(*p);
		*p/=10;
		p++;
	}
}
int suma(float broj)
{
	int sumaBroja=0;
	int brojPomnozen=broj*10;
	/*Sabiramo sve cifre i vracamo tu vrijednost*/
	while(brojPomnozen>0) {
		sumaBroja+=brojPomnozen%10;;
		brojPomnozen/=10;
	}
	return sumaBroja;
}

float preslozi(float niz[], int vel, int k)
{
	float nizVeci[100]= {0},nizManji[100]= {0};
	int i,m,v,sumaCifara;
	zaokruzi1(niz,vel);
	m=0;
	v=0;
	/*Sortiramo dati niz u dva pomocna niza ,nizManji i nizVeci poredivsi ih sa k*/
	for(i=0; i<vel; i++) {
		sumaCifara=suma(fabs(niz[i]));
		if(sumaCifara>=k) {
			nizVeci[v]=niz[i];
			v++;
		} else {
			nizManji[m]=niz[i];
			m++;
		}

	}
	/*Vracamo elemente u prvobitni niz na osnovu novih sortiranih nizova*/
	for (i=0; i<v; i++) {
		niz[i]=nizVeci[i];
	}
	for (i=0; i<m; i++) {
		niz[i+v]=nizManji[i];
	}
}

int main()
{
	int i,duzina,k;
	float niz[100];
	printf("Unesi duzinu niza: ");
	scanf("%d",&duzina);
	printf("Unesi  elemente niza: ");
	for(i=0; i<duzina; i++) {
		scanf("%f ",&niz[i]);
	}
	printf("Unesi k: ");
	scanf("%d ",&k);
	printf("Niz glasi: ");
	preslozi(niz,duzina,k);
	for(i=0; i<duzina; i++) {
		printf("%g ",niz[i]);
		return 0;
	}
}