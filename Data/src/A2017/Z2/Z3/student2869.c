#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	int i, j, sirA=0, sirB=0, visA=0, visB=0, jednake=1;
	float A[100][100], B[100][100];
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d%d", &sirA,&visA);
	printf ("Unesite clanove matrice A: ");
	for (i=0;i<visA;i++) {
		for (j=0;j<sirA;j++){
			scanf ("%f", &A[i][j]);
		}
	}
	
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d%d", &sirB,&visB);
	printf ("Unesite clanove matrice B: ");
	for (i=0;i<visB;i++) {
		for (j=0;j<visA;j++){
			scanf ("%f", &B[i][j]);
		}
	}
	
	if (sirB!=visA || sirA!=visB) {
		printf ("NE\n");
	}
	else if (sirB==visA || sirA==visB) {
		for (i=0; i<visA; i++) {
			for (j=0; j<sirA; j++) {
				if (fabs(A[i][j]-B[j][visA-i-1])>EPSILON)
				jednake=0;
			}
		}
	if (jednake==1) {
		printf ("DA\n"); 
	}
	else {
		printf ("NE\n");
	}
	}
	return 0;
}
