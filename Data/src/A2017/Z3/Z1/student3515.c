#include <stdio.h>
#include <stdlib.h>
int dva_od_tri(int *pok1,int velicina_1,int *pok2,int velicina_2,int*pok3,int velicina_3)
{
	int brojac=0,i,j,k=0,l,m,logicka=0;
	int *niz;
	niz=(int*)malloc((velicina_1+velicina_2+velicina_3+100)*sizeof(int));
	/* Unos clanova prvog niza, prethodno provjerava da li se taj clan ponavlja u prvom nizu,clanovi pocetnih nizova nalaze se na parnim mjestima, njihvi brojaci na neparnim */
	for (i = 0; i < velicina_1; i++) {
		niz[k]=*pok1++;
		niz[k+1]=0;
		if(k==0) {
			k+=2;
			continue;
		}
		logicka=0;
		for (j = 0; j <k ; j=j+2) {
			if(niz[k]==niz[j])
				logicka++;
		}
		if(logicka==0)
			k+=2;
	}
	/*L mjesto pocetka drugog niza,unos clanova drugog niza i provjera da li se broj ponavlja*/
	l=k;
	for (i = 0; i < velicina_2; i++) {
		niz[k]=*pok2++;
		niz[k+1]=0;
		if(k==l) {
			k+=2;
			continue;
		}
		logicka=0;
		for (j = l; j < k; j=j+2) {
			if(niz[j]==niz[k])
				logicka++;
		}
		if(logicka==0)
			k+=2;
	}
	m=k;
	/*L mjesto pocetka drugog niza,unos clanova drugog niza i provjera da li se broj ponavlja*/
	for (i = 0; i < velicina_3; i++) {
		niz[k]=*(pok3++);
		niz[k+1]=0;
		if(k==m) {
			k+=2;
			continue;
		}
		logicka=0;
		for (j = m; j < k; j=j+2) {
			if(niz[k]==niz[j])
				logicka++;
		}
		if(logicka==0)
			k+=2;
	}
	/*Prebrojavanje elemenata, ako se broj 2 puta nalazi se u  2 od 3 pocetna niza*/
	for (i = 0; i < k; i=i+2) {
		for (j = 0; j < k; j=j+2) {
			if(niz[i]==niz[j])
				niz[i+1]++;
		}
	}
	for (i = 1; i < k; i=i+2) {
		if(niz[i]==2)
			brojac++;
	}
	/*svaki broj se ponavlja 2 puta pa je 2 puta racunat*/
	brojac/=2;
	free(niz);

	return brojac;
}




int main()
{
	printf("Zadaća 3, Zadatak 1");
	return 0;
}
