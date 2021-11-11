#include <stdio.h>

int main() {
	int a, b, i, j, c, d;
	double A[100][100], B[100][100];
	
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &a, &b);
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<b; i++) {
		for (j=0; j<a; j++) {
			scanf ("%lf", &A[i][j]);
		}
	}
	
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &c, &d);
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<d; i++) {
		for (j=0; j<c; j++) {
			scanf ("%lf", &B[i][j]);
		}
	}
	
	if (a!=c || b!=d) {
		printf ("NE");
		return 0;
	}
	
	for (i=0; i<b; i++) {
		for (j=0; j<b; j++) {
			if (A[0][j] == B[j][b-1]) printf ("DA"); &//PREGLUPO RJESENJE
		}
	}
	
	return 0;
}
