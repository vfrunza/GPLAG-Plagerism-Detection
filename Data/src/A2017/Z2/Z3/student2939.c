#include <stdio.h>

int main() {
	int matA[100][100], matB[100][100], pom_mat[100][100];
	int i, j, sirina_A, sirina_B, visina_A, visina_B, iste=0;
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirina_A,&visina_A);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visina_A; i++){
		for(j=0; j<sirina_A; j++){
			scanf("%d", &matA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirina_B,&visina_B);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visina_B; i++){
		for(j=0; j<sirina_B; j++){
			scanf("%d", &matB[i][j]);
		}
	}
	
	if(sirina_A!=visina_B || visina_A!=sirina_B){
		printf("NE"); return 0;
	} else {
	for(i=0; i<visina_A; i++){
		for(j=0; j<sirina_A; j++){
			
			pom_mat[j][visina_A-1-i]=matA[i][j];
			
		}
	}
	
	for(i=0; i<sirina_A; i++){
		for(j=0; j<visina_A; j++){
        if((pom_mat[i][j]-matB[i][j])==0){
        	iste++;
        }
		}
	} 
	
	
	if(iste==sirina_A*visina_A){ printf("DA"); }
	else printf("NE");
	}
	return 0;
}
