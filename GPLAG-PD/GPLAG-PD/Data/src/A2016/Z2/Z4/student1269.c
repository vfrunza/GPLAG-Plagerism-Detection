#include <stdio.h>
int main() {
	int m,n,i,j;
	double mat[100][100];
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if(m>100 ||m<=0 || n>100 || n<=0) printf("Pogresan unos!\n"); 
		
	   }
		while(m>100 || m<=0 || n>100 || n<=0);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf ("%lf", &mat[i][j]);
		}
	}
	if(n==1 && m>1){
		printf("Matrica je Teplicova");
		return 0;
	}
	for(i=0; i<m-1; i++){
		for(j=0; j<n-1; j++) {
			if (mat[i][j]!= mat[i+1][j+1]) {
				printf ("Matrica nije ni cirkularna ni Teplicova");
				return 0;
			}
		}
	}
	for (i=0; i<m-1; i++) {
		if (mat[i][n-1]!=mat[i+1][0]) {
			printf ("Matrica je Teplicova");
			return 0;
		}
	}
	printf("Matrica je cirkularna");
	return 0;
}

	
	