#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int i, j, brojac_visina=0, brojac_sirina=0, br_glavni=1, max_br=0,  privr_broj, max_broj;
	privr_broj=matrica[0][0];
	max_broj=matrica[0][0];

	for (i = brojac_visina; i < visina; i++) {
		j=brojac_sirina;
		if (i!=brojac_visina)
			j=0;
		for (; j < sirina; j++) {
			if ((i==brojac_visina)&&(j==brojac_sirina)) {
				privr_broj=matrica[i][j];
				continue;
			}

			if (matrica[i][j]==privr_broj)
				br_glavni++;
		}
		if (i==visina-1) {
			if (br_glavni>max_br) {
				max_br=br_glavni;
				max_broj=privr_broj;
			} else if (br_glavni==max_br) {
				if (privr_broj<max_broj)
					max_broj=privr_broj;
			}
			brojac_sirina++;
			i=brojac_visina-1;
			if (brojac_sirina==sirina) {
				brojac_visina++;
				i=brojac_visina-1;
				brojac_sirina=0;
			}
			br_glavni=1;
		}
	}
	return max_broj;
}



int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int i, j, k, g;

	for (i = 0; i < visina; i++) {
		for (j = 0; j < sirina; j++) {
			if (matrica[i][j]==N) {
				for (k = 0; k < visina; k++) {
					for (g = j; g < sirina-1; g++) {
						matrica[k][g]=matrica[k][g+1];
					}
				}
				sirina--;
				j--;
			}
		}
	}

	return sirina;
}



int main()
{
	int i, j, k, sirina=100, visina=100, matrica[100][100], maksi;

	do {
		printf("Unesite sirinu i visinu matrice: ");
		scanf("%d %d", &sirina, &visina);
	} while ((sirina<=0) || (visina<=0));


	for (i = 0; i < visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for (j = 0; j < sirina; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}

	for (k = 1; ; k++) {
		maksi=max(matrica,visina,sirina);
		sirina=izbaci_kolone(matrica,visina,sirina,maksi);
		if (sirina>0) {
			printf("\nNakon %d. prolaza matrica glasi:\n", k);
			for (i = 0; i < visina; i++) {
				for (j = 0; j < sirina; j++) {
					printf("%5d", matrica[i][j]);
				}
				printf("\n");
			}
		} else {
			printf("\nNakon %d. prolaza matrica je prazna!", k);
			break;
		}
	}

	return 0;
}
