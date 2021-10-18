#include <stdio.h>

int main() {
	
	float A[100][100];
	float B[100][100];
	int i, j, SA, VA, SB, VB;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &SA, &VA);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<SA; i++){
		
		for(j=0; j<VA; j++){
			
			scanf("%f ", A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &SB, &VB);
	
	printf("Unesite clanove matrice B: ");
	for(i=0; i<SB; i++){
		
		for(j=0; j<VB; j++){
			
			scanf("%f ", B[i][j]);
			
		}
	}
	
	
	
	return 0;
}
