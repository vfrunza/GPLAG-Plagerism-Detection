#include <stdio.h>

int main() {
	int M, N, mat[100][100]={0}, i, j, teplicova=1, cirkularna=1;
	
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	while(M<=0 || M>100 || N<=0 || N>100) {
		printf("Pogresan unos!\nUnesite M i N: ");
		scanf("%d %d", &M, &N);
	}
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(i=1; i<M; i++) {
		if(mat[i][0] != mat[i-1][N-1]) {
			cirkularna = 0;
			break;
		} 
		for(j=1; j<N; j++) {
			if (mat[i][j] != mat[i-1][j-1]) {
				cirkularna = 0; 
				break;
			}
		}
	}
	
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
			if(mat[i][j] != mat[i+1][j+1]) {
				teplicova = 0; 
				break;
			}
		}
	}
	
	if(cirkularna==1) printf("Matrica je cirkularna");
	else if(teplicova==1 && cirkularna==0) printf("Matrica je Teplicova");
	else if(cirkularna==0 && teplicova==0) printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
