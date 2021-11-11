#include <stdio.h>

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3){
	int brojac[100]={0},i,j,suma=0;	/*Brojac nam sluzi da registrujemo koliko kojih brojeva ima ali bez ponavljanja*/
	
	/*PRVI NIZ*/
	for(i=0;i<vel1;i++){
		for(j=0;j<i;j++){
			if(niz1[i]==niz1[j]) break;	/*Osiguravanje od ponavljanja brojeva niza (isti korak za sve nizove) */
		}
		if(j==i) brojac[niz1[i]]++;
	}
	
	/*DRUGI NIZ*/
	for(i=0;i<vel2;i++){
		for(j=0;j<i;j++){
			if(niz2[i]==niz2[j]) break;
		}
		if(j==i) brojac[niz2[i]]++;
	}
	
	/*TRECI NIZ*/
	for(i=0;i<vel3;i++){
		for(j=0;j<i;j++){
			if(niz3[i]==niz3[j]) break;
		}
		if(j==i) brojac[niz3[i]]++;
	}
	for(i=0;i<100;i++){
		if(brojac[i]==2) suma++;
	}
	return suma;
}

int main() {
	int niz1[100],niz2[100],niz3[100],n1,n2,n3,i;
	printf("Unesite dimenziju prvog niza: ");
	scanf("%d",&n1);
	printf("Unesite elemente prvog niza: ");
	for(i=0;i<n1;i++){
		scanf("%d",&niz1[i]);
	}
	printf("Unesite dimenziju drugog niza: ");
	scanf("%d",&n2);
	printf("Unesite elemente drugog niza: ");
	for(i=0;i<n2;i++){
		scanf("%d",&niz2[i]);
	}
	printf("Unesite dimenziju treceg niza: ");
	scanf("%d",&n3);
	printf("Unesite elemente treceg niza: ");
	for(i=0;i<n3;i++){
		scanf("%d",&niz3[i]);
	}
	printf("Broj elemenata koji se nalaze u 2 od 3 niza je:%3d",dva_od_tri(niz1,n1,niz2,n2,niz3,n3));
	return 0;
}
