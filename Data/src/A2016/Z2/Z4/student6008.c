#include <stdio.h>

int main() {
	int m, n, i, j, cirkularna=1, teplicova=1;
	double mat[100][100];
	
	
	do{
		printf("Unesite M i N: ");
		scanf("%d%d", &m, &n);
		if((m<1 || m>100) ||(n<1 || n>100))
			printf("Pogresan unos!\n");
			
	}while(m<1 || m>100 || n<1 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=0; i<m-1; i++){
		for(j=0; j<n-1; j++){
			if(mat[i][n-1]!=mat[i+1][0]) {
				cirkularna=0;
				break;
			}
		}
	}
	
	
	for(i=0; i<m-1; i++){
		for(j=0; j<n-1; j++){
			if(mat[i][j]!=mat[i+1][j+1]){
				teplicova=0;
				break;
			}
		}
	}
	if (n == 1 && m != 1) {
		cirkularna = 0;
		teplicova = 1;
	}
	
	if(teplicova==1) {
		if (cirkularna == 1) {
			printf("Matrica je cirkularna");
		} else {
			printf("Matrica je Teplicova");
		}
	} else { 
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	
	return 0;
}
