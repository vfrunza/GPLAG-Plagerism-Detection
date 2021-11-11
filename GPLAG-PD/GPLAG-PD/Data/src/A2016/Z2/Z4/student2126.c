#include <stdio.h>
#include <math.h>
#define epsilon 0.000001
int main() {
	
	double mat[100][100]={{0}}; 
	int i, j, m, n,t1=1;
	printf("Unesite M i N: ");
	scanf("%d%d", &m, &n);
	if ((m>100 || m<=0) || (n>100 || n<=0)){
		do {
			printf("Pogresan unos!");
			printf("\nUnesite M i N: ");
			scanf("%d%d", &m, &n);
		} while ((m>100 || m<=0) || (n>100 || n<=0));
	}
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++ ){ 
		for(j=0; j<n; j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	if(n==1 && m!=1) {
		printf("Matrica je Teplicova");
		return 0;
	}

	for (i=0; i<m-1; i++){
		for (j=0; j<n-1; j++){
		
			if (fabs(mat[i][j]-mat[i+1][j+1])>epsilon){ printf ("Matrica nije ni cirkularna ni Teplicova"); return 0;}
			
		}
	}
	
	for(i=0; i<m-1; i++){
		for(j=0; j<n-1; j++){
			if (fabs(mat[i][n-1]-mat[i+1][0])>epsilon) { t1=0;}
		}
	}
	
	if(t1)printf("Matrica je cirkularna"); 
	else printf("Matrica je Teplicova"); 
	
	return 0;
	
}