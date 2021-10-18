#include <stdio.h>
#include <math.h>

int main()
{
	int	redA, kolonaA, redB, kolonaB, i, j;
	double tmp[100][100], matA[100][100], matB[100][100];

	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &redA, &kolonaA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<kolonaA; i++)
		for(j=0; j<redA; j++)
			scanf("%lf",&matA[i][j]);


	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&redB, &kolonaB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<kolonaB; i++)
		for(j=0; j<redB; j++)
			scanf("%lf", &matB[i][j]);



	for(i=0; i<redA; i++) {
		for(j=kolonaA-1; j>=0; j--) {
			tmp[i][kolonaA-1-j]=matA[j][i];

		}
	}



	if((kolonaA!=redB)||(kolonaB!=redA)) {
		printf("NE");
		return 1;
	}

	for(i=0; i<kolonaB; i++) {
		for(j=0; j<redB; j++) {
			if(fabs(matB[i][j]-tmp[i][j]>=0.0001)) {
				printf("NE");
				return 1;
			}
		}
	}
	printf("DA");




	return 0;
}
