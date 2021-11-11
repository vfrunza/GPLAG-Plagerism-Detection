#include <stdio.h>

int main()
{

	//varijable
	double matA[100][100]= {0}, matB[100][100]= {0};
	int i, j, r1, r2, k1, k2, temp;

	//unos dimenzija

	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &r1, &k1);

	//unos matrica
	printf("Unesite clanove matrice A: ");

	for (i = 0; i < r1; i++) {
		for (j = 0; j < k1; j++) scanf("%lf", &matA[i][j]);
	}

	//unos dimenzija

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &r2, &k2);

	//unos matrica
	printf("Unesite clanove matrice B: ");

	for (i = 0; i < r2; i++) {
		for (j = 0; j < k2; j++) scanf("%lf", &matB[i][j]);
	}

if (k1==r1) {

	//Rotiranje 90 stepeni

	for (i = 0; i < r1; i++) {

		for (j = i; j < k1-1-i; j++) {

			temp=matA[i][j];

			matA[i][j]=matA[k1-1-j][i];

			matA[k1-1-j][i]=matA[k1-1-i][r1-1-j];

			matA[k1-1-i][r1-1-j]=matA[j][r1-1-i];

			matA[j][r1-1-i]=temp;
		}
	}
}
/*else{
	
	temp=r1;
	r1=k1;
	k1=temp;
	matA[r1-1][k1-1]
	for (i = 0; i < r1; i++) {
	
		for (j = i; j < k1-2-i; j++) {

			temp=matA[i][j];

			matA[i][j]=matA[k1-1-j][i];

			matA[k1-1-j][i]=matA[k1-1-i][r1-1-j];

			matA[k1-1-i][r1-1-j]=matA[j][r1-1-i];

			matA[j][r1-1-i]=temp;
}
}
for (i = 0; i < r1; i++) {
		for (j = 0; j < k1; j++) {
			printf("%g", matA[i][j]);
				
		}
		printf("\n");
	}
}*/
	//Ispis

	for (i = 0; i < r1; i++) {
		for (j = 0; j < k1; j++) {
			if (matA[i][j]!=matB[i][j]) {
				printf("NE");
				return 0;
			}
		}
	}
	printf("DA");
	return 0;
}
