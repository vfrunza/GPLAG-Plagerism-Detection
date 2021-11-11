#include <stdio.h>
#define brojel 10

int main()
{
	int i, j, A[10][10], B[10][10], redA, kolA, redB, kolB, logicka;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &kolA, &redA);

	printf("Unesite clanove matrice A: ");
	for(i=0; i<redA; i++) {
		for (j=0; j<kolA; j++)
			scanf("%d", &A[i][j]);
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &kolB, &redB);

	printf("Unesite clanove matrice B: ");
	for(i=0; i<redB; i++) {
		for (j=0; j<kolB; j++)
			scanf("%d", &B[i][j]);
	}

	logicka=1;
	if (redA!=kolB || kolA!=redB)
		printf("NE\n");
	else {
		for (i=0; i<redA; i++) {
			for (j=0; j<kolA; j++) {
				if (A[i][j]!=B[j][redA-1-i]) {
					logicka=0;
					j=kolA;
					i=redA;
				}
			}
		}

		if (logicka)
			printf("DA\n");
		else
			printf("NE\n");
	}

	return 0;
}
