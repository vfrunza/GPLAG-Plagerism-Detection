#include <stdio.h>
#include <math.h>
#define E 0.000000000000001

int main()
{
	double A[100][100],AT[100][100],B[100][100],rotA[100][100];
	int red_A,kol_A,red_B,kol_B;
	int i,j,k,d,equal=1;

	/* A - Matrica za unos
	AT - Transponovana matrica A
	rotA - Matrica A, rotirana za 90 stepeni
	B - Matrica za uporedjivanje sa rotA */

	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&kol_A,&red_A);

	printf("Unesite clanove matrice A: ");

	for(i=0; i<red_A; i++)
		for(j=0; j<kol_A; j++)
			scanf("%lf",&A[i][j]);

	for (i=0; i<red_A; i++)
		for (j=0; j<kol_A; j++)
			AT[j][i] = A[i][j];

	for(i=0; i<kol_A; i++)
		for (k=red_A-1, d = 0; k>= 0; k--, d++)
			rotA[i][d] = AT[i][k];

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&kol_B,&red_B);

	printf("Unesite clanove matrice B: ");
	for(i=0; i<red_B; i++)
		for(j=0; j<kol_B; j++)
			scanf("%lf",&B[i][j]);

	if((red_A*kol_A)!=(red_B*kol_B) || (kol_A!=red_B))
		printf("NE\n");

	else if(kol_A==1 && red_B==1) {
		for(i=0; i<red_A; i++) {
			if(fabs(rotA[0][i]-B[0][i])>E)
				equal=0;
		}
		if(equal==1)
			printf("DA\n");
		else
			printf("NE\n");
	}

	else {
		for(i=0; i<red_B; i++) {
			for(j=0; j<kol_B; j++) {
				if(fabs(rotA[i][j]-B[i][j])>E)
					equal=0;
			}
		}

		if(equal==1)
			printf("DA\n");
		else
			printf("NE\n");
	}

	return 0;
}
