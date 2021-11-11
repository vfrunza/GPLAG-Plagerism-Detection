#include <stdio.h>
#include <math.h>
#define EPS 0.0001


int main() {
	
	int sirina_A=0, visina_A=0, sirina_B=0, visina_B=0, i, j;
	double A[100][100], B[100][100];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirina_A, &visina_A);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visina_A; i++) {
		for(j=0; j<sirina_A; j++) {
			scanf("%lf", &A[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirina_B, &visina_B);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visina_B; i++) {
		for(j=0; j<sirina_B; j++) {
			scanf("%lf", &B[i][j]);
		}
	}
	
	if(sirina_A!=visina_B || visina_A!=sirina_B) {
		printf("NE\n");
		return 0;
	}
		
	for(i=0; i<visina_A; i++) {
		for(j=0; j<sirina_A; j++) {
				if(fabs(A[i][j]-B[j][visina_A-i-1])>EPS) {
					printf("NE\n");
					return 0;
				}
		}
	}
	
	printf("DA\n");
	return 0;
}
