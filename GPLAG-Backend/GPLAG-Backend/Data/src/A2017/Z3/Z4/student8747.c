#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int matrica[100][100],int visina,int sirina)
{
	int i,j,l,k,Ponavljanje=0,PocetniClan=0,Max=1000000,MaxPonavljanje=0;
	Ponavljanje=0;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			PocetniClan=matrica[i][j];
			for(l=0; l<visina; l++) {
				for(k=0; k<sirina; k++) {
					if(PocetniClan==matrica[l][k]) {
						Ponavljanje++;
					}
				}
			}
			if(Ponavljanje>MaxPonavljanje) {
				Max=matrica[i][j];
				MaxPonavljanje=Ponavljanje;
			}
			if(Ponavljanje==MaxPonavljanje && matrica[i][j]<Max) {
				Max=matrica[i][j];
				MaxPonavljanje=Ponavljanje;
			}
			Ponavljanje=0;
		}
	}
	return Max;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int i,j,k,l,Brojac=0;
	for(i=0; i<sirina; i++) {
		for(j=0; j<visina; j++) {
			if (matrica[j][i]==N) {
				for(k=i; k<sirina; k++) {
					for(l=0; l<visina; l++) {
						matrica[l][k]=matrica[l][k+1];
					}
				}
				sirina--;
			}
		}
	}
	for(i=0; i<1; i++) {
		for(j=0; j<visina; j++) {
			if(matrica[j][i]==N) {
				return 0;
			}
		}
	}
	return sirina;
}

int main()
{

	int matrica[100][100]= {0},i,j,visina,sirina,NovaVisina,N,k,l,Prolaz=1;
	do {
		printf("Unesite sirinu i visinu matrice: ");
		scanf("%d",&sirina);
		scanf("%d",&visina);
	} while(sirina<=0 && visina<=0);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d",&matrica[i][j]);
		}
	}
	for(i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			N=max(matrica,visina,sirina);
			sirina=izbaci_kolone(matrica,visina,sirina,N);
			if (sirina>0) {
				printf("\nNakon %d. prolaza matrica glasi:\n",Prolaz);
				Prolaz++;
			}
			if(sirina>0) {
				for(l=0; l<visina; l++) {
					for(k=0; k<sirina; k++) {
						printf("%5.d",matrica[l][k]);
					}
					printf("\n");
				}
			} else {
				printf("\nNakon %d. prolaza matrica je prazna!\n",Prolaz);
			}
		}
	}
	return 0;
}
