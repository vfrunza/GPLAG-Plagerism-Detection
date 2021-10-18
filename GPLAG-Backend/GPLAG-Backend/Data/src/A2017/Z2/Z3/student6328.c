#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, visinaA=0, sirinaA=0, visinaB=0, sirinaB=0, iste=1;
	float matA[100][100], matB[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d", &sirinaA, &visinaA);
	printf("Unesite clanove matrice A: ");
	for (i=0; i<visinaA; i++) {
		for (j=0; j<sirinaA; j++) {
			scanf("%f", &matA[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d", &sirinaB, &visinaB);
	printf("Unesite clanove matrice B: ");
	for (i=0; i<visinaB; i++) {
		for (j=0; j<sirinaB; j++) {
			scanf("%f", &matB[i][j]);
		}
	}
	if (visinaA!=sirinaB || sirinaA!=visinaB)
		printf("NE\n");
	else {
		for (i=0; i<visinaA; i++) {
			for (j=0; j<sirinaA; j++) {
				if (fabs(matA[i][j]-matB[j][visinaA-i-1])>0.001) (iste=0);
			}
		}
		if (iste==1) printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}