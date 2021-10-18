#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max( int matrica[100][100], int visina, int sirina)
{
	int i,j,k,l,brojac=0,max_brojac=0,max_cifra;
	max_cifra=matrica[0][0];
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			brojac=0;
			for(k=0; k<visina; k++) {
				for(l=0; l<sirina; l++)
					if(matrica[i][j]==matrica[k][l]) {
						brojac++;


					}

			}
			if(brojac>max_brojac) {
				max_brojac=brojac;
				max_cifra=matrica[i][j];
			} else if(brojac==max_brojac) {
				if(max_cifra>matrica[i][j])
					max_cifra=matrica[i][j];
			}
		}
	}

	return max_cifra;
}
int izbaci_kolone( int matrica[100][100], int visina, int sirina, int N)
{
	int i,j,k=0,l,broj_kolona=0,izbaci_kol[100],brojac=0,kolona=0;
	
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==N) {
				izbaci_kol[k]=j;
				brojac++;

				k++;

			}

		}

	}

	i=0;
	for(k=0; k<brojac; k++) {
		for(j=0; j<sirina; j++) {
			izbaci_kol[k]=kolona;
			if(j==kolona) {
				for(l=j; l<sirina-1; l++) {
					matrica[i][l]=matrica[i][l+1];

				}
				i++;


				sirina--;
			}


		}

	}
	broj_kolona=sirina;
	return broj_kolona;
}


int main()
{
	int matrica[100][100],i,j,sirina=0,visina=0;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d",&matrica[i][j]);
		}
	}


	return 0;
}
