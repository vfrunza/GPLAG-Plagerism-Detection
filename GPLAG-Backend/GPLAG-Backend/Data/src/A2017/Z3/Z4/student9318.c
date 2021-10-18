#include <stdio.h>
#include <math.h>

int max(int  matrica[100][100], int visina, int sirina)
{
	int i, j, k = 0, brojacIstih = 0, maxBrojac=0, najmanjiMax=matrica[0][0];
	int matNiz[1000]= {0}, nizElemenata[1000]= {0}, nizBrojaca[100]= {0};
	/*Datu matricu pretvorimo u niz*/
	for (i = 0; i < visina; i++) {
		for (j = 0; j < sirina; j++) {
			matNiz[k] = matrica[i][j];
			k++;
		}
	}
	for (i = 0; i < k; i++) {
		brojacIstih = 0;
		/*Brojimo koliko istih elemenata imamo u matrici(nizu)*/
		for (j = 0; j < k; j++) {
			if (matNiz[i] == matNiz[j]) {
				brojacIstih++;
			}
		}
		nizElemenata[i] = matNiz[i];
		nizBrojaca[i] = brojacIstih;
	}
	for(i=0; i<k; i++) {
		/*Odredjujemo koji je najmanji maksimum*/
		if(nizBrojaca[i]>maxBrojac) {
			maxBrojac=nizBrojaca[i];
			najmanjiMax=nizElemenata[i];
		}
		if(nizBrojaca[i]==maxBrojac) {
			if(najmanjiMax>nizElemenata[i]) {
				najmanjiMax=nizElemenata[i];
			}
		}
	}
	return najmanjiMax;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N)
{
	int i, j, k, l;
	for( i=0; i<visina ; i++) {
		for( j=0; j<sirina; j++) {
			if(matrica[i][j]==N)
				break;
		}
		if(j!=sirina) {
			/*Kada pronadjemo kolonu koju treba izbaciti pomjeramo ostale kolone za kolonu manje*/
			for(k=0; k<visina; k++) {
				for(l=j; l<sirina-1; l++) {
					matrica[k][l]=matrica[k][l+1];
				}
			}
			sirina--;
			j=0;
			i=0;
		}
	}
	return sirina;
}

int main()
{
	int i, j,k=0, sirina, visina, matrica[100][100];
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", & sirina, & visina);
	for (i = 0; i < visina; i++) {
		printf("Unesite elemente %d. reda: ", i + 1);
		for (j = 0; j < sirina; j++) {
			scanf("%d ", & matrica[i][j]);
		}
	}
	printf("\n");

	if((sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina)))==0) {
		printf("Nakon 1. prolaza matrica je prazna!");
	} else {
		while(sirina>=1) {
			k++;
			printf("Nakon %d. prolaza matrica glasi: \n",k);
			for(i=0; i<visina; i++) {
				for(j=0; j<sirina; j++) {
					printf("%5d",matrica[i][j]);
				}
				printf("\n");
			}
			sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));
			printf("\n");
		}

		printf("Nakon %d. prolaza matrica je prazna!",k+1);
	}
	return 0;
}