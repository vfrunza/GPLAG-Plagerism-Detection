#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina){
	int maxbrojac = 0;
	int clan = matrica[0][0];
	int i, j, k, l;
	for(i = 0; i < visina; i++){
		for(j = 0; j<sirina; j++){
			int brojac = 0;
			for(k = 0; k < visina; k++){
				for(l = 0; l<sirina; l++){
					if(matrica[i][j]==matrica[k][l])brojac++;
				}
			}
			if(maxbrojac < brojac){
				maxbrojac = brojac;
				clan = matrica[i][j];
			}
			if(maxbrojac == brojac){
				if(matrica[i][j] < clan)clan = matrica[i][j];
			}
		}
	}
	
	return clan;
}
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n){
	int i, j, k, l;
	int rezultat;
	for(j = sirina-1; j >= 0; j--)
	{
		for(i = 0; i < visina; i++)
		{
			if(matrica[i][j] == n){
				for(l = j; l < sirina-1; l++) {
					for(k = 0; k < visina; k++) {
						matrica[k][l] = matrica[k][l+1];
					}
				}
				
				sirina--;
				break;
			}
		}
	}
	return sirina;
}
int main() {
	int sirina, visina, i, j;
	int matrica[100][100];
	int n, prolaz;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	for(i = 0; i < visina; i++){
		printf("Unesite elemente %d. reda: ", i+1);
		for(j = 0; j < sirina; j++){
			scanf("%d", &matrica[i][j]);
		}
	}


	prolaz = 0;
	while (sirina > 0) {
		n = max(matrica, visina, sirina);
		sirina = izbaci_kolone(matrica, visina, sirina, n);
		prolaz++;
		if(sirina > 0){
		printf("\nNakon %d. prolaza matrica glasi: \n", prolaz);
		for(i = 0; i < visina; i++){
			for(j = 0; j < sirina; j++){
					printf("%5d", matrica[i][j]);
				}
				printf("\n");
			}	
		}
	}
	printf("\nNakon %d. prolaza matrica je prazna!\n", prolaz);


	return 0;
}
