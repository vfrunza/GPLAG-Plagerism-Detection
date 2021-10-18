#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{

	int najcesci = matrica[0][0];

	int brojPojavljivanja = 0;
	
	int brojPojavljivanjaTrenutnog;

	int i, j, k, l;

	for(i = 0; i < visina; i++) {
		for(j = 0; j < sirina; j++) {
			if(matrica[i][j] == najcesci) {
				brojPojavljivanja++;
			}
		}
	}
	
	for(i = 0; i < visina; i++) {
		for(j = 0; j < sirina; j++) {
			brojPojavljivanjaTrenutnog = 0;
			
			for(k = 0; k < visina; k++) {
				for(l = 0; l < sirina; l++) {
					if(matrica[k][l] == matrica[i][j]) {
						brojPojavljivanjaTrenutnog++;
					}
				}
			}
			if(brojPojavljivanjaTrenutnog > brojPojavljivanja ||
			        (brojPojavljivanjaTrenutnog == brojPojavljivanja && matrica[i][j] < najcesci)) {
				najcesci = matrica[i][j];
				brojPojavljivanja = brojPojavljivanjaTrenutnog;
			}
		}
	}

	return najcesci;

}

int izbaci_kolone(int matrica[100][100],int visina,int sirina, int N)
{

	int i, j, nalaziSe, k;

	for(j = 0; j < sirina; j++) {
		nalaziSe = 0;
		for(i = 0; i < visina; i++) {
			if(matrica[i][j] == N) {
				nalaziSe = 1;
			}
		}
		if(nalaziSe == 1) {
			for(i = 0; i < visina; i++) {
				for(k = j; k < sirina - 1; k++) {
					matrica[i][k] = matrica[i][k+1];
				}
			}
			j--;
			sirina--;
		}
	}

	return sirina;
}

int main()
{

	int visina,sirina;

	int matrica[100][100];

	int i, j;
	
	int brojac = 1;
	
	int najcesci;

	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	for(i =0 ; i < visina ; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j = 0; j < sirina ; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	printf("\n");
	

	do {
		najcesci = max(matrica,visina,sirina);
		sirina = izbaci_kolone(matrica,visina,sirina,najcesci);
		if(sirina != 0) {
			printf("Nakon %d. prolaza matrica glasi:\n", brojac);
			for(i = 0; i < visina ; i++){
				for(j = 0; j < sirina ; j++){
					printf(" %4d", matrica[i][j]);
				}
				printf("\n");
			}
			brojac++;
		} else
			printf("Nakon %d. prolaza matrica je prazna!", brojac);
	} while(sirina > 0);



	return 0;
}
