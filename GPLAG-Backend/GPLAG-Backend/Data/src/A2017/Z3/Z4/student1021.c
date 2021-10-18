#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int i,j,a=0;
	int brojac=0,pom,pon,maksi,maksip;
	int niz1[10000],niz2[10000],niz3[10000];
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			niz1[brojac]=matrica[i][j];
			brojac++;
		}
	}
	for(i=0; i<brojac-1; i++) {
		for(j=0; j<brojac-i-1; j++) {
			if(niz1[j]>=niz1[j+1]) {
				pom=niz1[j];
				niz1[j]=niz1[j+1];
				niz1[j+1]=pom;
			}
		}
	}
	pon=1;
	for(i=0; i<brojac-1; i++) {
		if(niz1[i]==niz1[i+1])
			pon++;
		if(niz1[i]==niz1[i+1] && i==brojac-2) {
			niz2[a]=niz1[i];
			niz3[a]=pon;
			a++;
		}
		if(niz1[i]!=niz1[i+1] && i==brojac-2) {
			niz2[a]=niz1[i];
			niz3[a]=pon;
			a++;
			niz2[a]=niz1[i+1];
			niz3[a]=1;
			a++;
		}
		if(i!=brojac-2 && niz1[i]!=niz1[i+1]) {
			niz2[a]=niz1[i];
			niz3[a]=pon;
			a++;
			pon=1;
		}
	}
	maksi=niz2[0];
	maksip=niz3[0];
	for(i=0; i<a-1; i++) {
		if(niz3[i+1]>maksip || (niz3[i+1]==maksip && niz2[i+1]<=maksi)) {
			maksi=niz2[i+1];
			maksip=niz3[i+1];
		}
	}
	return maksi;
}
void izbaci(int matrica[100][100], int visina, int sirina,int kolona)
{
	int matrica1[100][101];
	int i,j;
	for(i=0; i<visina; i++)
		for(j=0; j<sirina+1; j++) {
			if(j<sirina)
				matrica1[i][j]=matrica[i][j];
			else
				matrica1[i][j]=0;
		}
	for(i=0; i<visina; i++) {
		for(j=kolona; j<sirina; j++) {
			matrica[i][j]=matrica1[i][j+1];
		}
	}
}
int izbaci_kolone(int matrica[100][100], int visina, int sirina,int N)
{
	int i,j;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==N) {
				if(sirina==1) return 0;
				else
					izbaci(matrica,visina,sirina,j);
				sirina--;
				j--;
			}
		}
	}
	return sirina;
}
int main()
{
	int i,v,s,e,j,k,brojac;
	int matrica[100][100];
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&s,&v);
	for(i=0; i<v; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<s; j++) {
			scanf("%d",&e);
			matrica[i][j]=e;
		}
	}
	brojac=1;
	k=s;
	for(;;) {
		k=izbaci_kolone(matrica,v,k,max(matrica,v,k));
		if(k!=0) {
			printf("\nNakon %d. prolaza matrica glasi: \n",brojac);
			for(i=0; i<v; i++) {
				for(j=0; j<k; j++) {
					printf("%5d",matrica[i][j]);
				}
				printf("\n");
			}
		}
		if(k==0) {
			printf("\nNakon %d. prolaza matrica je prazna!",brojac);
			break;
		}
		brojac++;
	}
	return 0;
}
