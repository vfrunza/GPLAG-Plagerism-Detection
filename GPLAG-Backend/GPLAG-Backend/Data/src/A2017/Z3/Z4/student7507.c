#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int i,j,max_ponavljanje, maxpon_el, ponavljanje, pomocni_niz[10000];


	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			pomocni_niz[i*sirina+j]=matrica[i][j];
		}
	}
	max_ponavljanje=0;
	maxpon_el=pomocni_niz[0];
	for(i=0; i<(visina*sirina); i++) {
		ponavljanje=1;
		for(j=i+1; j<(visina*sirina); j++) {
			if(pomocni_niz[i]==pomocni_niz[j]) ponavljanje++;
		}
		if(ponavljanje>max_ponavljanje) {
			max_ponavljanje=ponavljanje;
			maxpon_el=pomocni_niz[i];
		}
		if(ponavljanje==max_ponavljanje && pomocni_niz[i]<maxpon_el) {
			maxpon_el=pomocni_niz[i];
		}
	}

	return maxpon_el;
}

int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N)
{
	int i, j, k, l;

	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==N) {
				for(k=0; k<visina; k++) {
					for(l=j; l<sirina-1; l++) {
						matrica[k][l]=matrica[k][l+1];
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
	int matrica[100][100];
	int maxpon_el, i, j, k, visina, sirina, nova_sirina;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);

	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	nova_sirina=sirina;
	for(k=0; k<sirina; k++) {
		maxpon_el=max(matrica,visina,nova_sirina);
		nova_sirina=izbaci_kolone(matrica, visina, nova_sirina, maxpon_el);
		if(nova_sirina==0) {
			printf("\nNakon %d. prolaza matrica je prazna!", k+1);
			break;
		} else {
			printf("\nNakon %d. prolaza matrica glasi: \n", k+1);
			for(i=0; i<visina; i++) {
				for(j=0; j<nova_sirina; j++) {
					printf("%5d", matrica[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}

	}

	return 0;
}
