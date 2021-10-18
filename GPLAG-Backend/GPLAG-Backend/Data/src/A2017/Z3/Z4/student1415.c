#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{

	int i, j, i1, j1, brojac=0, br_trenutnog=0;
	int ponovljen = matrica[0][0];

	for(i=0; i < visina; i++) {
		for(j=0; j < sirina; j++) {
			if(matrica[i][j] == ponovljen)
				brojac++;
		}
	}

	for(i = 0; i < visina; i++) {
		for(j = 0; j < sirina; j++) {
			br_trenutnog=0;
			for(i1 = 0; i1 < visina; i1++) {
				for(j1 = 0; j1 < sirina; j1++) {
					if(matrica[i1][j1]==matrica[i][j]) {
						br_trenutnog++;
					}
				}
			}
			if(br_trenutnog > brojac || (br_trenutnog == brojac && matrica[i][j] < ponovljen)) {
				ponovljen= matrica[i][j];
				brojac = br_trenutnog;
			}
		}
	}

	return ponovljen;
}

int izbaci_kolone (int matrica [100][100], int visina, int sirina, int N)
{
	int  sadrzan=0, i, j, k;

	for(j = 0; j < sirina; j++) {
		for(i = 0; i < visina; i++) {
			if (matrica[i][j] == N)
				sadrzan++;
		}

		if(sadrzan != 0) {
			for (i =0 ; i < visina; i++) {
				for(k = j; k < sirina - 1; k++) {
					matrica[i][k]=matrica[i][k+1];
				}
			}
			sirina--;
			j--;
			sadrzan = 0;
		}
	}

	return sirina;
}

int main()
{
	int matrica_probna [100][100], i = 0, j, m, n;
	int ponovljen, brojac = 0;

	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &n, &m);

	do {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j = 0; j < n; j++) {
			scanf("%d", &matrica_probna[i][j]);
		}

		i++;

	} while (i < m);

	printf("\n");

	do {
		ponovljen=max(matrica_probna,m,n);
		n = izbaci_kolone(matrica_probna,m,n,ponovljen);

		if(n > 0) {
			printf("Nakon %d. prolaza matrica glasi:\n", brojac + 1);
			for(i = 0; i < m; i++) {
				for(j = 0; j < n; j++) {
					printf(" %4d", matrica_probna[i][j]);
				}
				printf("\n");
			}
			brojac++;

		} else 
			printf("\nNakon %d. prolaza matrica je prazna!", brojac + 1);
		
	} while (n > 0);

	return 0;
}
