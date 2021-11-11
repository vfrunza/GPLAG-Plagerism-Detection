#include <stdio.h>

int main() {
	int mat1[100][100], mat[100][100], sirina_A, visina_A, sirina_B, visina_B, i=0, j=0, ispitivac_uslova;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirina_A, &visina_A);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visina_A; i++) {
		for(j=0; j<sirina_A; j++) 
		{   scanf("%d", &mat[i][j]); } }
		
		
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirina_B, &visina_B);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visina_B; i++) {
		for(j=0; j<sirina_B; j++) 
	{   scanf("%d", &mat1[i][j]); } }
	
	/*provjeravamo dimenzije matrica*/
	if(sirina_A!=visina_B || sirina_B!=visina_A) {
	printf("NE\n");
	return 0; }
	

	if(sirina_A==visina_B && sirina_B==visina_A) {
		for(i=0; i<sirina_A; i++) {
			if(mat[0][i]==mat1[i][visina_B-1]) ispitivac_uslova=1; 
			else { ispitivac_uslova=0, printf("NE\n"); return 0; }
			if(mat[i][visina_A-1]==mat1[sirina_B-1][visina_B-i-1]) ispitivac_uslova=1; 
			else { ispitivac_uslova=0; printf("NE\n"); return 0; }
			if(mat[sirina_A-1][visina_A-i-1]==mat1[sirina_B-i-1][0]) ispitivac_uslova=1; 
			else { ispitivac_uslova=0; printf("NE\n"); return 0; }
			if(mat[sirina_A-i-1][0]==mat1[0][i]) ispitivac_uslova=1; 
			else { ispitivac_uslova=0; printf("NE\n"); return 0; }
			if(ispitivac_uslova==1) { printf("DA\n"); return 0; }
		} 
	}
	if(sirina_A!=sirina_B && visina_A!=visina_B) {
		for(i=0; j<visina_B; j++) {
			for(i=0; i<visina_A; i++) {
				if(mat[j][i]==mat1[i][sirina_B-j-1]) ispitivac_uslova=1;
				else { ispitivac_uslova=0; printf("NE\n"); return 0; }
				if(ispitivac_uslova==1) { printf("DA\n"); return 0; }
			}
		}
	}
	return 0;
	}

