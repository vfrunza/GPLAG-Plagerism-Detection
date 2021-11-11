#include <stdio.h>
int main()
{
	int niz[100], velicina=0, i=0, j=0, k=0, niz_naopak[100], temp=0, niz_konacni[1000], brojac=0, pomocni=0, broj=0, niz_brojac[100], br=0;
	printf("Unesite velicinu niza: ");
	scanf("%d", &velicina);
	printf("Unesite clanove niza: ");
	for(i=0; i<velicina; i++) {
		do {
			scanf("%d", &niz[i]);
		} while(niz[i]<0);
		broj=niz[i];
		temp=broj%10;
		broj=broj/10;
		while(broj!=0) {
			temp=temp*10+(broj%10);
			broj=broj/10;
		}
		niz_naopak[i]=temp;
	}
	i=0;
	while(i<velicina) {
		while(niz_naopak[i]!=0) {
			niz_brojac[j]=niz_naopak[i]%10;
			niz_naopak[i]=niz_naopak[i]/10;
			j++;
		}
		i++;
	}
	printf("Finalni niz glasi:\n");
	i=0;
	while(i<j) {
		pomocni=niz_brojac[i];
		brojac=1;
		i++;
		while(pomocni==niz_brojac[i]) {
			brojac++;
			i++;
		}
		niz_konacni[k]=pomocni;
		k++;
		niz_konacni[k]=brojac;
		k++;
		brojac=0;
	}
	for(i=0; i<k; i++) {
		if(i<k-1)
			printf("%d ", niz_konacni[i]);
		else
			printf("%d", niz_konacni[i]);
	}
	return 0;
}
