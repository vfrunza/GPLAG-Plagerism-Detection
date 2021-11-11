#include <stdio.h>

int main () {
	int sirinaA, visinaA, sirinaB, visinaB, i, j, k, l, jednake;
	float A[100][100], B[100][100];

	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &sirinaA, &visinaA);
	printf ("Unesite clanove matrice A: ");
	
	for (i=0; i<visinaA; i++) {
		for (j=0; j<sirinaA; j++) {
			scanf ("%f", &A[i][j]);
		}
	}
	
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &sirinaB, &visinaB);
	printf ("Unesite clanove matrice B: ");
	
	for (i=0; i<visinaB; i++) {
		for (j=0; j<sirinaB; j++) {
			scanf ("%f", &B[i][j]);
		}
	}
	
	jednake=1;
	
	 if (visinaA*sirinaA == visinaB*sirinaB ) {
		for (i=0; i<visinaA; i++) {
		jednake=1;
			for (j=0; j<sirinaA; j++) {
				if (A[i][j]!=B[j][visinaA-1-i]) 
				jednake=0;
				} 
			break;
		}}
	 else  jednake=0; 
	 
	
	if(jednake) printf ("DA");
	else  printf ("NE");
	
	return 0; 
}