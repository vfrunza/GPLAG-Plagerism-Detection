#include <stdio.h>
#define brEl 100

int broj_pon(int mat[brEl][brEl], int visina, int sirina, int broj) {// f-ja za odredjivanje broja ponavljanja nekog broja
	int i, j, br_pon = 0;
	for(i = 0; i < visina; i++)
		for(j = 0; j < sirina; j++)
			if(mat[i][j] == broj) br_pon++;
	return br_pon;
}

int max(int mat[brEl][brEl], int visina, int sirina) {
	int max_br_pon = 0, cifra = mat[0][0], i , j, br_pon;
	for (i = 0; i < visina; i++)
		for(j = 0; j < sirina; j++) {
			br_pon = broj_pon(mat, visina, sirina, mat[i][j]);
			if(br_pon > max_br_pon) {
				max_br_pon = br_pon;
				cifra = mat[i][j];
			}
			else if(br_pon == max_br_pon && mat[i][j] < cifra) cifra = mat[i][j];
		}
	return cifra;
}

int izbaci_kolone(int mat[brEl][brEl], int visina, int sirina, int N) {
	int i, j, k, l;
	for (i = 0; i < visina; i++)
		for (j = 0; j < sirina; j++)
			if(mat[i][j] == N) {
				for (k = 0; k < visina; k++)
					for (l = j+1; l < sirina; l++)
						mat[k][l-1] = mat[k][l];
				sirina--;
				j--;
			}
	return sirina;
}

int main() {
	int mat[brEl][brEl], visina, sirina, i, j, br_prolaza = 1;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sirina, &visina);
	for (i = 0; i < visina; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for (j = 0; j < sirina; j++)
			scanf("%d", &mat[i][j]);
	}
	do {
		sirina = izbaci_kolone(mat, visina, sirina, max(mat, visina, sirina));
		if(!sirina) break;
		printf("\nNakon %d. prolaza matrica glasi:\n", br_prolaza++);
		for (i = 0; i < visina; i++) {
			for(j = 0; j < sirina; j++)
				printf("%5d", mat[i][j]);
			printf("\n");
		}
	}while(sirina);
	printf("\nNakon %d. prolaza matrica je prazna!", br_prolaza);
	return 0;
}
