#include <stdio.h>

int max(int matrica[100][100],int visina,int sirina);
int izbaci_kolone(int (*mat)[100],int vis,int sir,int n);

int max(int matrica[100][100],int visina,int sirina)
{
	int i,j,k,q;
	int cmax=0,rmax;
	int br[100][100]= {{0}};
	/*kreiranje histograma po ponavljanju istih vrijednosti u matrici*/
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			for(k=0; k<visina; k++) {
				for(q=0; q<sirina; q++)
					if(matrica[i][j]==matrica[k][q])
						br[i][j]++;
			}
		}
	}
	/*pronalazak najvece vrijednosti u histogramu i odgovarajuceg elementa iz matrice*/
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(br[i][j]>cmax) {
				cmax=br[i][j];
				rmax=matrica[i][j];
			}
		}
	}
	/*zamjena za najmanju vrijednost koja se najvise ponavlja u matrici*/
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(br[i][j]==cmax)
				if(matrica[i][j]<rmax)
					rmax=matrica[i][j];
		}
	}
	return rmax;
}

int izbaci_kolone(int (*mat)[100],int vis,int sir,int n)
{
	int i,j,k,z;
	for(i=0; i<vis; i++) {
		for(j=0; j<sir; j++) {
			if((*mat)[j]==n) {
				mat-=i;    /*vracanje na pocetni pokazivac*/
				/*izbacivanje kolone u kojoj je pronadjen n*/
				for(k=0; k<vis; k++) {
					for(z=j; z<sir-1; z++) {
						(*mat)[z]=(*mat)[z+1];
					}
					mat++;
				}
				mat-=k;   /*vracanje na pocetni pokazivac*/
				mat+=i;   /*vracanje na zadnju poziciju u pretrazi*/
				sir--;
				j--;
			}
		}
		mat++;
	}
	return sir;
}

int main()
{
	int sirina,visina,i,j,k;
	int matrica[100][100];
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d",&matrica[i][j]);
		}
	}
	k=0;
	do {
		sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));
		k++;
		if(sirina>0) {
			printf("\nNakon %d. prolaza matrica glasi: \n",k);
			for(i=0; i<visina; i++) {
				for(j=0; j<sirina; j++) {
					printf("%5d",matrica[i][j]);
				}
				printf("\n");
			}
		}
	} while(sirina>0);
	printf("\nNakon %d. prolaza matrica je prazna!\n",k);
	return 0;
}
