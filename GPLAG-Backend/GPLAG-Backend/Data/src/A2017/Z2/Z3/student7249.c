#include <stdio.h>

int main()
{
	int A[15][15], B[15][15], sA, vA, sB, vB, i, j;

	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sA, &vA);

	printf("Unesite clanove matrice A: ");
	for(i=0; i<vA; i++) {
		for(j=0; j<sA; j++)
			scanf("%d", &A[i][j]);
	}

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sB, &vB);

	printf("Unesite clanove matrice B: ");
	for(i=0; i<vB; i++) {
		for(j=0; j<sB; j++)
			scanf("%d",&B[i][j]);
	}

	if(sB!=vA || sA!=vB) {
		printf("NE\n");
		return 0;
	}

	for(i=0; i<vA; i++) {

		for(j=0; j<sA; j++) {

			if(B[j][sB-i-1]!=A[i][j]) {
				printf("NE\n");
				return 0;
			}
		}
	}


	printf("DA\n");
	return 0;
}