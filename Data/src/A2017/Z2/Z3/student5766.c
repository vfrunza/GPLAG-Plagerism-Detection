#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001

int main()
{
	int visina_A, sirina_A, visina_B, sirina_B, i, j;
	double matA[100][100], matB[100][100];


	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirina_A, &visina_A);

	printf("Unesite clanove matrice A: ");

	for(i=0; i<visina_A; i++) {
		for(j=0; j<sirina_A; j++) {
			scanf("%lf", &matA[i][j]);
		}
	}


	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirina_B, &visina_B);

	printf("Unesite clanove matrice B: ");

	for(i=0; i<visina_B; i++) {
		for(j=0; j<sirina_B; j++) {
			scanf("%lf", &matB[i][j]);
		}
	}

	if(visina_A!=sirina_B || sirina_A != visina_B ){
		printf ("NE");
		return 0;
	}

	for(i=0; i<visina_B; i++){
		for(j=0; j<sirina_B; j++){
			if(fabs(matA[visina_A-1-j][i] - matB[i][j])>EPSILON){
				printf("NE");
				return 0;
			}
		}
	}
	printf("DA");
	return 0;
}
