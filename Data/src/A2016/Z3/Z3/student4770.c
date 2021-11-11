#include <stdio.h>
// Najprije treba omogućiti korisniku da unese matricu proizvoljnih dimenzija MxN.
// Korisnik najprije unosi prirodne brojeve M i N koji su manji ili jednaki 200.
//Petljom do-while treba osigurati da su brojevi u traženom opsegu. Nakon toga, unose se elementi matrice.
//Nakon unosa, program treba izbaciti iz matrice sve redove koji se ponavljaju (svi elementi redova su jednaki) tako da u matrici ostane 
//samo prvi odozgo takav red. Nakon toga treba izbaciti i sve kolone koje se ponavljaju, tako da u matrici ostane samo prva slijeva takva kolona.
//Konačno treba ispisati tako promijenjenu matricu.

int main() {
	int M, N, i, j, mat[200][200], temp, k=0, z, y, l;
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &M,&N);
		if (M > 200 || M < 1 || N > 200 || N <1) printf ("Brojevi nisu u trazenom opsegu.\n");
		
	}while (M > 200 || M < 1 || N > 200 || N < 1);
	printf ("Unesite elemente matrice: ");
	for (i = 0; i < M; ++i) {
		for (j = 0;j < N; ++j) {
			scanf ("%d", &mat[i][j]);
		}
	}
	//Izbacivanje redova koji se ponavljaju iz matrice :)
	for (i = 0; i < M; ++i) {
		for (j = i+1; j < M; ++j) {
			k = 0;
			for (l = 0; l < N; ++l) {
				if (mat[i][l] == mat[j][l]) k++;
				if (k == N) {
					for (y = j+1; y < M; ++y) {
						for (z = 0; z < N; ++z) {
							temp = mat[y-1][z];
							mat[y-1][z] = mat[y][z];
							mat[y][z] = temp;
						}
					}
					M--;
					j--;
				}
				
				
			}
			
		}
	}
	//Izbacivanje kolona koje se ponavljaju iz matrice
	for (i = 0; i < N; ++i) {
		for (j = i+1; j < N; ++j) {
			k = 0;
			for (l = 0; l < M; ++l) {
				if (mat[l][i] == mat[l][j]) k++;
				if (k == M) {
					for (y = j+1; y < N; ++y) {
						for (z = 0; z < M; ++z) {
							temp = mat[z][y-1];
							mat[z][y-1] = mat[z][y];
							mat[z][y] = temp;
						}
					}
					N--;
					j--;
				}
			}
		}	
	}
	printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (i = 0; i < M; i++) {
		for ( j = 0; j < N; j++) {
			printf ("%5d", mat[i][j]);
		}
		printf ("\n");
	}
		return 0;
}
