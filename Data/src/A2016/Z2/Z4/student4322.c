#include <stdio.h>
#define A 100

int main() {
	int i, j, m, n, tep=0, cir=0;
	double mat[A][A]={{0},{0}};
	printf("Unesite M i N: ");
	scanf ("%d %d", &m, &n);
	while (m<=0 || m>100 || n<=0 || n>100) {
		printf ("Pogresan unos!\n");
		printf ("Unesite M i N: ");
		scanf ("%d %d", &m, &n);
		}
		printf ("Unesite elemente matrice: ");
		for(i=0; i<m; i++) {
			for(j=0; j<m; j++) {
				scanf("%lf", &mat[i][j]);
			}
		}
			for(i=0; i<m; i++) {
				for(j=0; j<n; j++) {
						if (mat[i][j]==mat[i+1][j+1] && mat[i][n-1]!=mat[i+1][0]) tep=1;
							if (mat[i][j]==mat[i+1][j+1] && mat[i][n-1]==mat[i+1][0]) cir=1;
				} } 
				if(tep==1) printf("Matrica je Teplicova");
	else if(cir==1)printf ("Matrica je cirkularna");
		else  {
			printf("Matrica nije ni cirkularna ni Teplicova"); }
	return 0;
}
