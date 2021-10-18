#include <stdio.h>

int main() {
	int i, j, a1, a2, b1, b2, lp=1, dm1=0, dm2=0;
	float matA[100][100], matB[100][100];
	printf("\nUnesite sirinu i visinu matrice A: ");
	scanf("%d %d", &a1, &a2);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<a1; i++) {
		for(j=0; j<a2; j++) {
			scanf("%f", &matA[i][j]);			
		}
	}

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &b1, &b2);
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<b1; i++) {
		for(j=0; j<b2; j++) {
			scanf("%f", &matB[i][j]);			
		}
	}

	for(i=b1-1; i>=0; i--) {
		for(j=0; j<b2; j++) {
			if(matA[i][j]!=matB[dm1][dm2]) {
				lp=0;
				break;
			}
			if(dm1<b2-1) dm1++;
		}
		if(dm2<b1-1) dm2++;
		dm1=0;
	}
	if(lp==0) printf("NE");
	else printf("DA");
	return 0;
}
