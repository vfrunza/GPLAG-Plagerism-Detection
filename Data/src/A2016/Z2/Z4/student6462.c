#include <stdio.h>
#include <math.h>
#define EPS 0.001

int main() {
	int m, n, i, j, tep=1, cirkularna=1;
	double mat[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if(n<=0 || n>100 || m<=0 || m>100) printf("Pogresan unos!\n");
		else{
			printf("Unesite elemente matrice: ");
			for(i=0; i<m; i++){
				for(j=0; j<n; j++){
					scanf("%lf", &mat[i][j]);
				}
			}
			for(i=0; i<m-1; i++){
				for(j=0; j<n-1; j++){
			if(fabs(mat[i][j]-mat[i+1][j+1])>EPS){
				tep=0;
				break;
			}
			
			}
			}
			
			for(i=0; i<m-1; i++){
				for(j=0; j<n-1; j++){
					if(fabs(mat[i][j]-mat[i+1][j+1])>EPS || fabs(mat[i][n-1]-mat[i+1][0])>EPS){
						 cirkularna=0;
						 break; }
				}
			}
			
		}
	}while((n<=0 || n>100) || (m<=0 || m>100));
	if(n==1 && m!=1){
		tep=1;
		cirkularna=0;
	}
	if(tep==1 && cirkularna==1){
		printf("Matrica je cirkularna");
	}
	else if(tep==1 && cirkularna==0){
		printf("Matrica je Teplicova");
	}
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
