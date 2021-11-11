#include <stdio.h>

int main() {
int M, N, i, j, k, l, br_ponavljanja_A, br_ponavljanja_B, br_ponavljanja_C, clan;
int A[100][100], B[100][100], C[100][100];

do {
	printf ("Unesite brojeve M i N: ");
	scanf ("%d %d", &M, &N);
} while (M < 0 || M > 100 || N < 0 || N > 100);

/* Unos matrica */

printf ("Unesite clanove matrice A: ");
for (i=0 ; i<M ; i++)
	for (j=0 ; j<N ; j++)
		scanf ("%d", &A[i][j]);
	
printf ("Unesite clanove matrice B: ");
for (i=0 ; i<M ; i++)
	for (j=0 ; j<N ; j++)
		scanf ("%d", &B[i][j]);
		
printf ("Unesite clanove matrice C: ");
for (i=0 ; i<M ; i++)
	for (j=0 ; j<N ; j++)
		scanf ("%d", &C[i][j]);
		
/* Ideja da se uzima jedan po jedan clan matrice A, prebroji se broj njegovih ponavljanja */
/* Zatim, isto uradimo u matricama B i C */

/* Ovom dvostrukom petlljom prolazimo kroz sve clanove matrice A */
for (i=0 ; i<M ; i++) {
	for (j=0 ; j<N ; j++) {
		/* Uzimamo clana matrice A */
		clan = A[i][j];
		
		/* Potrebno je svaki put kada uzmemo novog clana restartovati sve brojace ponavljanja na 0 */
		
		br_ponavljanja_A = br_ponavljanja_B = br_ponavljanja_C = 0;
		
		/* Naredna petlja se moze iskoristiti za prebrojavanje ponavljanja u svakoj matrici,
		tj. mozemo kroz svaku matricu prolaziti istom petljom, jer su sve matrice istih dimenzija */
		
		for (k=0 ; k<M ; k++) {
			for (l=0 ; l<N ; l++) {
				
				/* Znaci uzeli smo jedan clan u matrici A i prebrojimo koliko se puta ponavlje u peostale dvije matrice */
				
				if (clan == A[k][l]) br_ponavljanja_A++;
				if (clan == B[k][l]) br_ponavljanja_B++;
				if (clan == C[k][l]) br_ponavljanja_C++;		
			}
		}
		
		if (br_ponavljanja_A != br_ponavljanja_B || br_ponavljanja_A != br_ponavljanja_C) {
			printf ("NE");
			return 0;
		}
		
		
	}
}

	printf ("DA");
	return 0;
}
