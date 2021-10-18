#include <stdio.h>

int main()
{
	int prvi_red,prva_kolona,drugi_red,druga_kolona,i,j,mrmot=0;
	float PRVI,DRUGI,A[100][100], B[100][100], C[100][100], TRECA_MATRICA;

	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d%d", &prva_kolona, &prvi_red);

	printf ("Unesite clanove matrice A: ");

	for (i=0; i<prvi_red; i++) {
		for (j=0; j<prva_kolona; j++) {
			scanf ("%f", &PRVI);
			A[i][j]=PRVI;
		}
	}
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d%d", &druga_kolona, &drugi_red);

	printf ("Unesite clanove matrice B: ");

	for (i=0; i<drugi_red; i++) {
		for (j=0; j<druga_kolona; j++) {
			scanf ("%f", &DRUGI);
			B[i][j]=DRUGI;
		}
	}
	/*SMJENA*/
	for (i=0; i<drugi_red; i++) {
		for (j=0; j<druga_kolona; j++) {
			C[i][j]=A[j][i];
		}
	}
	/*SMJENA*/

	for (i=0; i<prva_kolona; i++) {
		for (j=0; j<prvi_red/2; j++) {
			TRECA_MATRICA=C[i][j];
			C[i][j]=C[i][prvi_red-j-1];
			C[i][prvi_red-j-1]=TRECA_MATRICA;
		}
	}
	if (prva_kolona!=drugi_red || prvi_red!=druga_kolona) {
		printf ("NE");
		return 0;
	} else {
		for(i=0; i<prva_kolona; i++) {
			for (j=0; j<prvi_red; j++) {
				if (C[i][j]==B[i][j]) mrmot++;
			}
		}
	}

	if (mrmot == prvi_red * prva_kolona) printf ("DA");
	else printf ("NE");
	return 0;
}
