#include <stdio.h>
#include <stdlib.h>

int main() {
	int A[100][100]={-1}, B[100][100]={-1}, C[100][100]={-1}, nizA[10000]={0}, nizB[10000]={0}, nizC[10000]={0}, 
		brojacAplus[500]={0}, brojacAminus[500]={0}, brojacBplus[500]={0}, brojacBminus[500]={0},
		brojacCplus[500]={0}, brojacCminus[500]={0}, i, j, M, N, vel = 0, svi_jednaki;
	do {
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &M, &N);
	} while (M>100 || N>100);
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d", &A[i][j]);
			nizA[vel]=A[i][j];
			if (nizA[vel]<0) brojacAminus[abs(nizA[vel])]++;
			else brojacAplus[nizA[vel]]++;
			vel++;
		}
	}
	vel = 0;
	printf("Unesite clanove matrice B: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d", &B[i][j]);
			nizB[vel]=B[i][j];
			if (nizB[vel]<0) brojacBminus[abs(nizB[vel])]++;
			else brojacBplus[nizB[vel]]++;
			vel++;
		}
	}
	vel = 0;
	printf("Unesite clanove matrice C: ");
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf ("%d", &C[i][j]);
			nizC[vel]=C[i][j];
			if (nizC[vel]<0) brojacCminus[abs(nizC[vel])]++;
			else brojacCplus[nizC[vel]]++;
			vel++;
		}
	}
	svi_jednaki=1;
	for (i=0; i<vel; i++) {
		if (nizA[i]<0) {
			nizA[i]=nizA[i]*(-1);
			if (brojacAminus[nizA[i]] != brojacBminus[nizA[i]]) {
				svi_jednaki=0;
				break;
			}
			else if (brojacAminus[nizA[i]] != brojacCminus[nizA[i]]) {
				svi_jednaki=0;
				break;
			}
		}
		if (brojacAplus[nizA[i]] != brojacBplus[nizA[i]]) {
			svi_jednaki=0;
			break;
		}
		else if (brojacAplus[nizA[i]] != brojacCplus[nizA[i]]) {
			svi_jednaki=0;
			break;
		}
	}
	if (svi_jednaki) printf ("DA\n");
	else printf ("NE\n");
	return 0;
}
