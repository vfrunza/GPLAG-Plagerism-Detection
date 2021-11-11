#include <stdio.h>


int main() {
    int m, n, i, j;
    double mat[100][100]={0};
    int teplicova=0, cirkularna=0;
	do {
	   printf("\nUnesite M i N: ");
	   scanf("%d %d", &m, &n);
	   if(m>100 || m<=0 || n>100 || n<=0) printf("Pogresan unos!");
	}while(m>100 || m<=0 || n>100 || n<=0);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
	
	
	for(i=1; i<m; i++)  {
		for(j=1; j<n; j++) {
			if(mat[i][0] != mat[i-1][n-1] || mat[i][j] != mat[i-1][j-1] )
			cirkularna=1;
			
		}
	}
	if(mat[i][j]==mat[100][1]) printf("Matrica je Teplicova\n");
	
	else if(cirkularna==0) printf("Matrica je cirkularna\n");
	
	else {
		
	for(i=1; i<m; i++) {
		for(j=1; j<n; j++) {
			if (mat[i][j] != mat[i-1][j-1] )
			teplicova=1;
		}
	} 
	if(teplicova==0) printf("Matrica je Teplicova\n");
	}

	if(cirkularna==1 && teplicova==1) printf("Matrica nije ni cirkularna ni Teplicova\n");
	return 0;
}
