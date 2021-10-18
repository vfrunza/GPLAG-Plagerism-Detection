#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int i=0, j=0, brojac=0, max_brojac=0, max_broj, pomocni_niz[10000];
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			pomocni_niz[j+i*sirina]=matrica[i][j];
		}
	}
	max_broj=pomocni_niz[0];
	for(i=0; i<sirina+sirina*(visina-1); i++) {
		brojac=0;
		for(j=i; j<sirina+sirina*(visina-1); j++) {
			if(pomocni_niz[i]==pomocni_niz[j]) brojac++;
		}
		if(brojac>max_brojac) {
			max_brojac=brojac;
			max_broj=pomocni_niz[i];
		} else if(brojac==max_brojac && pomocni_niz[i]<max_broj) {
			max_broj=pomocni_niz[i];
		}
	}
	return max_broj;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n)
{
	int i=0, j=0, flag=0, k=0, lokacija=0;
	/* Pregled po kolonama */
	for(i=0; i<sirina; i++) {
		for(j=0; j<visina; j++) {
			if(matrica[j][i]==n) {
				lokacija=i;
				flag=1;
				break;
			}
		}
		if(flag==1) {
			for(j=0; j<visina; j++) {
				for(k=lokacija; k<sirina-1; k++) {
					matrica[j][k]=matrica[j][k+1];
				}
			}
			sirina--;
			i--;
		}
		flag=0;
	}
	return sirina;
}

int main()
{
	int matrix[100][100], sir=0, vis=0, i=0, j=0, brojac=1;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sir, &vis);
	for(i=0; i<vis; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sir; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	do {
		sir=izbaci_kolone(matrix, vis, sir, max(matrix, vis, sir));
		if(sir==0) break;
		printf("\nNakon %d. prolaza matrica glasi:\n", brojac);
		for(i=0; i<vis; i++) {
			for(j=0; j<sir; j++) {
				printf("%5d", matrix[i][j]);
			}
			printf("\n");
		}
		brojac++;
	} while(sir>0);
	printf("\nNakon %d. prolaza matrica je prazna!", brojac);
	return 0;
}
