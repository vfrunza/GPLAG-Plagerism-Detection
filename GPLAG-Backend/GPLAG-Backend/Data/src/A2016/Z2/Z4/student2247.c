#include <stdio.h>
#define max 100
int main() {
	double mat[max][max]={{0},{0}};
	int m, n, i, j, matTep=0, matCirc=0;
	ponovo:
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	if((m<0 || m>100)||(n<0 || n>100)) {
		printf("Pogresan unos!\n"); goto ponovo;
	}
	else {printf("Unesite elemente matrice: ");}
		for(i=0; i<m; i++) {
			for(j=0; j<n; j++) {
				scanf("%lf", &mat[i][j]);
			}
		}
	if(m==1) {printf("Matrica je cirkularna"); return 0;}
	for(i=0; i<m-1; i++) {
		for(j=0; j<n-1; j++) {
			if(mat[i][j]==mat[i+1][j+1]) matTep=1;
		}
	}
	if(matTep==1) {
	for(i=1; i<m; i++) {
			if(mat[i][n-1]==mat[i+1][0]) matCirc=1;
		}
	}

	if(matCirc==1) printf("Matrica je cirkularna");
	else if(matTep==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
