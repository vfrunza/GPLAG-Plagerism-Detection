#include <stdio.h>
#define A 100

int main() {
	int i, j, m, n, teplicova_mat=0, cirkularna_mat=0;
	double mat[A][A]={{0},{0}};
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
		while(m<=0 || m>100 || n<=0 || n>100){printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);} 
		printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=0; i<m-1; i++) {
		for(j=0; j<n-1; j++) {
			 if(mat[i][j]!=mat[i+1][j+1]) teplicova_mat=1;
		}
	}
	if(teplicova_mat==0) {
		for(i=1; i<m; i++) {
			if(mat[i][0]!=mat[i-1][n-1]) cirkularna_mat=1; 
			}
			if(cirkularna_mat==0) printf("Matrica je cirkularna");
			else printf("Matrica je Teplicova");
		
	}	else {printf("Matrica nije ni cirkularna ni Teplicova");}
	return 0;
}