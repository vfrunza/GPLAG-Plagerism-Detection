#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{

	int brojac[100][100]= {{0}};
	int i,j,k,l;
	int max,min;

	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {

			for(k=0; k<visina; k++) {
				for(l=0; l<sirina; l++) {

					if(matrica[i][j]==matrica[k][l]) {
						brojac[i][j]++;						/* Za svaki clan matrice brojimo koliko se puta ponavlja...*/
					}
				}
			}
		}
	}

	max=brojac[0][0];

	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(brojac[i][j]>max) {
				max=brojac[i][j];						   /*...Nalazimo najveci broj ponavljanja clana matrice...*/
			}
		}
	}


	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(brojac[i][j]==max) {
				min=matrica[i][j];
				for(k=0; k<visina; k++) {
					for(l=0; l<sirina; l++) {
						if(matrica[k][l]<min && brojac[k][l]==max) {
							min=matrica[k][l];								/*...Nalazimo najmanji clan matrice koji se ponavlja najvise puta*/
						}
					}
				}
			}
		}
	}


	return min;


}


int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{

	int i,j,k,l;


	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==N) {
				for(k=0; k<visina; k++) {
					for(l=j; l<sirina-1; l++) {
						matrica[k][l]=matrica[k][l+1];       /* Kada smo pronasli trazeni clan matrice, "prepisujemo" susjedne kolone jedne na drugu pocevsi od kolone
																u kojoj se nalazi trazeni clan...*/
					}
				}
				sirina--;									/*...Smanjili smo sirinu matrice*/
				j--;										/*...Provjeravamo da li je i u susjednoj koloni trazeni clan...*/
				i=0;										/*...Pocinjemo od vrha kolone...*/
			}
		}
	}

	return sirina;

}


int main()
{

	int sirina, visina;
	int clan;
	int i=0,j,k;
	int matrica[100][100];
	int nova_sirina;
	int brojac=0;
	int wanted;

	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);

	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d", &clan);
			matrica[i][j]=clan;
		}
	}

	nova_sirina=sirina;

	while(nova_sirina!=0) {

		wanted=max(matrica,visina,nova_sirina);
		nova_sirina=izbaci_kolone(matrica,visina,nova_sirina,wanted);

		if(nova_sirina==0) {
			printf("\nNakon %d. prolaza matrica je prazna!", brojac+1);
			break;
		}

		printf("\nNakon %d. prolaza matrica glasi:\n", brojac+1);
		for(j=0; j<visina; j++) {
			for(k=0; k<nova_sirina; k++) {
				printf("%5d", matrica[j][k]);
			}
			printf("\n");
		}
		brojac++;
	}

	return 0;
}




