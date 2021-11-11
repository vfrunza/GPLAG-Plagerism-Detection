#include <stdio.h>
#include <math.h>

#define eps 0.0001
#define size 100

int main() {
	
	int mA, nA, mB, nB;
	double A[size][size], B[size][size];
	int i, j;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &nA, &mA);
	
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < mA; i++){
		for(j = 0; j < nA; j++){
			scanf("%lf", &A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &nB, &mB);
	
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < mB; i++){
		for(j = 0; j < nB; j++){
			scanf("%lf", &B[i][j]);
		}
	}
	
	
	if(fabs(mA - nB) > eps || fabs(nA - mB) > eps){
		printf("NE\n");
		return 0;
	}
	
	int jednake = 1;
	
	for(i = 0; i < mB; i++){
		for(j = 0; j < nB; j++){
		
			if(fabs(B[i][j] - A[mA - 1 - j][i]) > eps){
				jednake = 0;
			}
		
		}
	}
	
	if(jednake){
		printf("DA\n");
	}else{
		printf("NE\n");
	}
	
	return 0;
}
