#include <stdio.h>

int main() {
	int i,j,m,n,a,b,iste;
	float mat1[50][50],mat2[50][50];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d", &m, &n);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			scanf("%f", &mat1[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d", &a, &b);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<b; i++) {
		for(j=0; j<a; j++) {
			scanf("%f", &mat2[i][j]);
		}
	}
	
	iste=1;
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			if(mat1[i][j]!=mat2[j][n-1-i]) { 
				iste=0;
				break;
			}
		}
	}
	
	if(iste) printf("DA");
	else printf("NE");
	
	return 0;
}
