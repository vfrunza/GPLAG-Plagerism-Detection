#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina) {
	int i, j, k, l, brojac, pomocna[100][100] = {{0}}, MaxClan = matrica[0][0], MaxBrojac = 0;
	
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			
			brojac = 0;
			for (k=0; k<visina; k++) {
				for (l=0; l<sirina; l++) {
					if (matrica[i][j] == matrica[k][l]) {
						brojac++;
					}
				}
			}
			
			pomocna[i][j] = brojac;
		}
	}
	
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if ((MaxBrojac < pomocna[i][j]) || (MaxBrojac == pomocna[i][j] && MaxClan > matrica[i][j]))
			{
				MaxBrojac = pomocna[i][j];
				MaxClan = matrica[i][j];
			}
		}
	}
	
	return MaxClan;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n){
	int i, j, k, l;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(matrica[i][j]==n) {
				for (k=0; k<visina; k++) {
					for (l=j; l<sirina-1; l++) {
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
	

int main() {
	int matrica[100][100], i, j, n, visina, sirina, maks, brojac = 1;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	
	for(i=0;i<visina;i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0;j<sirina;j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	
	printf ("\n");
	
	while(sirina != 0) {
		maks = max(matrica, visina, sirina);
		sirina = izbaci_kolone(matrica, visina, sirina, maks);
		if (sirina == 0) {
			printf ("Nakon %d. prolaza matrica je prazna!", brojac);
			break;
		}
		printf ("Nakon %d. prolaza matrica glasi:\n", brojac);
		for (i=0; i<visina; i++) {
			for (j=0; j<sirina; j++) {
				printf ("%5d", matrica[i][j]);
			}
			printf ("\n");
		}
		
		
		printf ("\n");
		brojac++;
	}
	return 0;
}
