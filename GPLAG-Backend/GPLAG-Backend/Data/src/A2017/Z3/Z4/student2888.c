#include <stdio.h>
#define memorija 10001
int max(int matrica[100][100],int visina,int sirina )
{
	int i,j,m,n,broj,max=0,poredbenibrojac=0,maxbroj=matrica[0][0];
	int poredenje,temp;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			broj=matrica[i][j];
			for(m=0; m<visina; m++) {
				for(n=0; n<sirina; n++) {
					poredenje=matrica[m][n];
					if(broj==poredenje) {
						poredbenibrojac++;
					}
				}
			}
			if(poredbenibrojac>= max) {
				temp=maxbroj;
				maxbroj=broj;
				if(poredbenibrojac==max && broj>temp)
					maxbroj=temp;
				max=poredbenibrojac;
			}
			poredbenibrojac=0;
		}
	}
	return maxbroj;
}
int izbaci_kolone(int matrica[100][100],int visina,int sirina,int K)
{
	int i,j,m,n,duzina;
	duzina=sirina;
	for(i=0; i<visina; i++)
		for(j=0; j<duzina; j++) {
			if(matrica[i][j]==K) {
				for(m=j; m<sirina; m++)
					for(n=0; n<visina; n++)
						matrica[n][m]=matrica[n][m+1];
				duzina--;
			}
		}
	return duzina;
}
int main()
{

	int visina,sirina,i,j,mat[100][100],k=0,l;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++)
			scanf("%d",&mat[i][j]);
	}
	int ponavljanje;
	ponavljanje=1;
	int vis=visina,sir=sirina,brojac=1;
	do {
		k=0;
		if(sirina>1)
			while(k<vis) {
				for(l=1; l<sirina; l++) {
					if(mat[k][0]==mat[k][l]) {
						brojac++;
					}
				}
				if(brojac==sir) {
					printf("\nNakon 1. prolaza matrica je prazna!");
					return 0;
				} else {
					brojac=1;
					k++;
				}
			}
		int K=max(mat,visina,sirina);
		sirina= izbaci_kolone(mat,visina,sirina,K);
		if(sirina!=0) {
			printf("\nNakon %d. prolaza matrica glasi:\n", ponavljanje);
			for(i=0; i<visina; i++) {
				for(j=0; j<sirina; j++) {
					if(j==0 && mat[i][0]<10)
					printf("    ");
					else if(j==0 && mat[i][0]>=10)
					printf("   ");
					else if(j==0 && mat[i][0]>=100)
					printf("  ");
					if(j==sirina-1)
					printf("%d",mat[i][j]);
					if(j!=sirina-1)
					printf("%-5d",mat[i][j]);
				}
					printf("\n");
				}
			}
			else {
				printf("\nNakon %d. prolaza matrica je prazna!",ponavljanje);
				return 0;
			}
			ponavljanje +=1;
		}
		while(sirina!=0);


		return 0;
	}
