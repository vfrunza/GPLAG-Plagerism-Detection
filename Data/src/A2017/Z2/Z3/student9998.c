#include <stdio.h>

int main() {
	int sirinaA, visinaA, sirinaB, visinaB, A[100][100], B[100][100], i, j, rezultat=1;
	
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &sirinaA, &visinaA);
	
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<visinaA; i++) {
		for (j=0; j<sirinaA; j++) {
			scanf ("%d", &A[i][j]);
		}
	}
	
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &sirinaB, &visinaB);
	
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<visinaB; i++) {
		for (j=0; j<sirinaB; j++) {
			scanf ("%d", &B[i][j]);
		}
	}
	
	if (sirinaA!=visinaB) rezultat=0;
	else if (visinaA!=sirinaB) rezultat=0;
	else {
		for (i=0; i<sirinaA; i++) {
			for (j=0; j<visinaA; j++) {
				if (A[visinaA-j-1][i]!=B[i][j]) {
					rezultat=0;
					break;
				}
			}
		}
	}
		
	if (rezultat==0) printf ("NE");
	else printf ("DA");

	
	return 0;
}
