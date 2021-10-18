#include <stdio.h>

int broj_javljanja_u_matrici(int matrica[100][100],int visina,int sirina,int broj)
{
	int brojac=0,i,j;
	for ( i = 0; i < visina; i++) {
		for ( j = 0; j < sirina; j++) {
			if(matrica[i][j]==broj) {
				brojac++;
			}
		}
	}

	return brojac;
}

int max(int matrica[100][100],int visina, int sirina)
{

	int najveci_broj_javljanja=broj_javljanja_u_matrici(matrica,visina,sirina,matrica[0][0]);
	int broj_max=matrica[0][0];/*broj koji se najvise puta javlja u matrici*/
	int i,j;
	int broj_javljanja;

	for ( i = 0; i < visina; i++) {
		for ( j = 0; j < sirina; j++) {
			broj_javljanja = broj_javljanja_u_matrici(matrica,visina,sirina,matrica[i][j]);
			if(broj_javljanja>najveci_broj_javljanja ||
			        (broj_javljanja==najveci_broj_javljanja&&matrica[i][j]<broj_max)) {
				najveci_broj_javljanja = broj_javljanja;
				broj_max = matrica[i][j];
			}

		}
	}

	return broj_max;
}

int izbaci_kolonu(int matrica[100][100],int visina, int sirina, int nta_kolona)
{
	int i, j;

	for ( i = 0; i < visina; i++) {

		for (j = nta_kolona; j < sirina-1; j++) {
			matrica[i][j]=matrica[i][j+1];
		}
	}
	sirina--;

	return sirina;
}

int izbaci_kolone(int matrica[100][100],int visina, int sirina,int N)
{
	int i,j;
	for (j = 0; j < sirina; j++) {
		for ( i = 0; i < visina; i++) {
			if(matrica[i][j]==N) {
				sirina = izbaci_kolonu(matrica,visina,sirina,j);
				j--;
				break;
			}
		}
	}
	return sirina;
}



void ispisi_matricu(int matrica[100][100],int visina,int sirina)
{
	int i,j;

	for ( i = 0; i < visina; i++) {
		for ( j = 0; j < sirina; j++) {
			printf("%5d",matrica[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int matrica[100][100],i,j,visina,sirina,N,brojac_prolaza;


	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina, &visina);

	for ( i = 0; i < visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);

		for (j = 0; j < sirina; j++) {
			scanf("%d",&matrica[i][j]);
		}
	}

	brojac_prolaza=0;

	while(sirina!=0) {
		N = max(matrica,visina,sirina);
		sirina = izbaci_kolone(matrica,visina,sirina,N);
		brojac_prolaza++;

		printf("\nNakon %d. prolaza matrica ",brojac_prolaza);
		if(sirina==0) {
			printf("je prazna!");
		} else {
			printf("glasi:\n");
		}
		ispisi_matricu(matrica,visina,sirina);

	}
	return 0;
}
