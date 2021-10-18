#include <stdio.h>

int max (int matrica[100][100], int visina, int sirina)
{

	int brojac[10000]={0}, i, j, max[100]={0}, clan;
	
	
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			brojac[matrica[i][j]] ++;
		}
	}

	max = brojac [matrica[0][0]];

	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(max == brojac [matrica[i][j]] && matrica[i][j] < clan) {
				max[i][j] = brojac[matrica][i][j];
				clan = matrica[i][j];
			}
			if(brojac [matrica[i][j]] > max) {
				max[i][j] = brojac[matrica[i][j]];
				clan = matrica[i][j];
			}

			return clan;
		}


		int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N) {

			for(i=0; i<visina; i++) {
				N = matrica[i][sirina - 1]
			}

			sirina --;

			for(i=0; i<visina; i++) {
				for(j=0; j<sirina; j++) {
					printf("%d ", matrica[i][j]);
				}
			}

		}

		int main() {
			int i, j, sirina, visina, matrica[100][100], N;

			printf("Unesite sirinu i visinu matrice: ");
			scanf("%d", &sirina);
			scanf("%d", &visina);

			for(i=0; i<visina; i++) {
				printf("Unesite elemente %i. reda", i+1);
				for(j=0; j<sirina; j++) {
					scanf("%d", matrica[i][j]);
				}
			}




			for(i=0; i<visina; i++) {
				printf("Nakon %i. prolaza matrica glasi: \n");
				N = max(matrica);
				izbaci_kolone(matrica, visina, sirina, N));
			}

			return 0;
		}
