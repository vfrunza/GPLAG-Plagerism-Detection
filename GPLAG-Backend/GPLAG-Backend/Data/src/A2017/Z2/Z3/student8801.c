#include <stdio.h>

int main() {
	
	int matA[100][100], matB[100][100];
	int mA, nA, mB, nB, i, j, temp, rezultat;
	
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &mA, &nA);
	
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<mA; i++)
	for (j=0; j<nA; j++)
	scanf ("%d", &matA[i][j]);
	
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &mB, &nB);
	
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<mB; i++)
	for (j=0; j<nB; j++)
	scanf ("%d", &matB[i][j]);
	
	/* Rotiranje matrice A */
	/* 1. Transponovanje */
	
	for (i=0; i<mA; i++)
	for (j=i; j<nA; j++) {
	temp=matA[i][j];
	matA[i][j]=matA[j][i];
	matA[j][i]=temp; }


	/* 2. Zamjena kolona */
	for (i=0; i<nA; i++)
	for (j=0; j<nA/2; j++) {
	temp=matA[i][j];
	matA[i][j]=matA[i][nA-1-j];
	matA[i][nA-1-j]=temp;
	}
	
	rezultat=0;
	for (i=0; i<mA; i++)
	for (j=0; j<nA; j++) {
		if (matA[i][j]!=matB[i][j]) {
		rezultat=1;
		break; }
	}
	
	if (rezultat==0) printf ("DA");
	else printf ("NE");

	return 0;
} 