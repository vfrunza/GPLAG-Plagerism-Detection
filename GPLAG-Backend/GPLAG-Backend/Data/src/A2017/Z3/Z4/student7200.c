#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina) {
	int i, j, x=0, brojac=0;
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
		}
	}
	return matrica;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n) {
	int i,j;
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (matrica[j]==n) {
			
			}
			sirina--;
			j--;
		}
	}
	return matrica;	
}

int main() {
	
	int mat[100][100], i, j, vi=0, sr=0, n=0, y=0;
	
	printf ("Unesite sirinu i visinu matrice: ");
	scanf ("%d %d", &sr, &vi);
	
	for (i=0; i<vi; i++) {
		printf ("Unesite clanove %d. reda: ", i+1);
		for (j=0; j<sr; j++) {
			scanf ("%d", &mat[i][j]);
		}
	}
	
	for (i=0; ; i++) {
		printf ("Koji broj treba izbaciti: ");
		scanf ("%d", &n);
	
		y = izbaci_kolone(mat,vi,sr,n);
		printf ("Nakon %d. prolaza matrica glasi: %d", i,y);
	}
	return 0;
}
