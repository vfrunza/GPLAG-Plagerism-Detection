#include <stdio.h>

int main() {
	int m,n,i,j,x,y;
	double A[100][100],B[100][100],C[100][100]={{0}};
	
	/*UNOS DIMENZIJA MATICE A*/
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&m,&n);
	
	/*UNOS ELEMENATA  MATRICE A*/
	
	printf("Unesite clanove matrice A: ");
	for (i=0;i<m;i++) {
		for (j=0;j<n;j++) {
		scanf("%lf",&A[i][j]);
		}
	}
	
	/*UNOS DIMENZIJA MATRICE B*/
	
		printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&x,&y);
	
	/*UNOS ELEMENATA MATRICE B*/
	
	printf("Unesite clanove matrice B: ");
	for (i=0;i<x;i++) {
		for (j=0;j<y;j++) {
		scanf("%lf",&B[i][j]);
		}
	}
	/*UNOS ELEMENATA U MATRICU C*/
	
	
	for(i=0;i<m;i++) {
		for(j=0;j<n;i++) {
			C[j][n-1-i]=A[i][j];
		}
	}
	
	/*POREDJENJE MATRICA B I C*/
	
	for(i=0;i<m;i++) {
		for(i=0;i<n;i++) {
			if (C[i][j] != B[i][j]) {
				printf("NE");
				return 1;
			}
			}
		}
		printf("DA");
	return 0;
}
