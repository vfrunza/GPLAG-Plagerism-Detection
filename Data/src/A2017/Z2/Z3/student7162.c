#include <stdio.h>

int main () {
	int i, j, A_sirina, A_visina, B_sirina, B_visina, rotirana;
	float A[100][100], B[100][100];
	
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &A_sirina, &A_visina);
	
	printf ("Unesite clanove matrice A: ");
	for (i=0;i<A_visina;i++) {
		for (j=0;j<A_sirina;j++) {
			scanf ("%f", &A[i][j]);
		}
	}
	
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &B_sirina, &B_visina);
	
	printf ("Unesite clanove matrice B: ");
	for (i=0;i<B_visina;i++) {
		for (j=0;j<B_sirina;j++) {
			scanf ("%f", &B[i][j]);
		}
	}
	
	rotirana = 1;
	for (i=0;i<A_visina;i++) {
		for (j=0;j<A_sirina;j++) {
			if (B[i][j] != A[A_sirina-1-j][i]) {
				rotirana = 0;
				break;
			}
		}
	}
	
	if (rotirana) printf ("DA");
	else printf ("NE");
	printf ("\n");
	return 0;
}