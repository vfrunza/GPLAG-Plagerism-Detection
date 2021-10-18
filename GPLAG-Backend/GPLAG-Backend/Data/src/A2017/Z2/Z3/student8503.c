#include <stdio.h>

int main() {
	int i,j,mat[m][n],mat[p][q],m,n,p,q;
	
	printf("Unesite sirinu i visinu matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++) {
			printf("Unesite cvlanove matrice A: ");
			scanf("%d",&mat[i][j]);
			
		}
		printf("\n");
	}
	
		printf("Unesite sirinu i visinu matrice B: ");
	for(i=0;i<p;i++){
		for(j=0;j<q;j++) {
			printf("Unesite cvlanove matrice B: ");
			scanf("%d",&mat[i][j]);
			
		} printf("\n");
		
	}
	return 0;
}
