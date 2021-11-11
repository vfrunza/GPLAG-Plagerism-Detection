#include <stdio.h>

int main()
{

	int i,j,sirA, sirB, visA, visB;
	int A[100][100], B[100][100], C[100][100];
	int jednake=1;

	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirA,&visA);
	printf("Unesite clanove matrice A: ");
	for (i=0; i<visA; i++) {
		for(j=0; j<sirA; j++) {
			scanf ("%d", &A[i][j]);
		}
	}

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirB,&visB);
	printf("Unesite clanove matrice B: ");
	for (i=0; i<visB; i++) {
		for(j=0; j<sirB; j++) {
			scanf ("%d", &B[i][j]);
		}
	}

	if(visA!=sirB || sirA!=visB) {
		jednake=0;
		printf("NE");
		return 1;
	}
	for(i=0; i<sirA; i++) {
		for (j=0; j<visA; j++) {
			C[i][j]=A[visA-j-1][i];
		}
	}

	for(i=0; i<sirA; i++) {
		for (j=0; j<visA; j++) {
			if(C[i][j]!=B[i][j]) {
				jednake=0;
				break;
			}
		}
		if(!jednake)
			break;
	}

	if(jednake)
		printf("DA");

	else printf ("NE");

	return 0;
}
