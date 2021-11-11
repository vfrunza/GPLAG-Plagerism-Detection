#include <stdio.h>
#include <math.h>

#define sizeM 100
#define err 0.000001

int main() {
	/* initial */
	double A[sizeM][sizeM], B[sizeM][sizeM];
	double N[sizeM][sizeM]; /* validity array */
	int i, j, validity = 1;
	int AH=0, AW=0, BH=0, BW=0;
	
	/* input */
	printf("Unesite sirinu i visinu matrice A: "); scanf("%d %d", &AW, &AH);
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < AH; i++) 
		for(j = 0; j < AW; j++) {
			scanf("%lf", &A[i][j]);
			N[j][AH-i-1] = A[i][j];
		}
	
	printf("Unesite sirinu i visinu matrice B: "); scanf("%d %d", &BW, &BH);
	printf("Unesite clanove matrice B: ");
	/* test here to avoid additional loops */
	if(AW != BH || AH != BW)
		validity = 0;
	
	for(i = 0; i < BH; i++) 
		for(j = 0; j < BW; j++) {
			scanf("%lf", &B[i][j]);
			if(validity)
				if(i < AW && j < AH && fabs(B[i][j] - N[i][j]) > err)
					validity = 0;
		}
	
	if(validity)
		printf("DA\n");
	else
		printf("NE\n");
	
	return 0;
}