#include <stdio.h>

int main() {
	int M=5, N=7, i, j, k=1, t=1, mat[100][100]={{0}};
	
	do{
		if(M<1 || N<1 || M>100 || N>100) printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
	}
	while(M<1 || N<1 || M>100 || N>100);
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	for(i=0;i<M-1;i++){
		for(i=0;i<N-1;i++){
			if(mat[i][N-1]!=mat[i+1][0] || mat[i][j]!=mat[i+1][j+1]){
				k=0;
				i=M;
				j=N;
				
			}
		}
	}
	
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(mat[i][j]!=mat[i+1][j+1]){
				t=0;
				i=M;
				j=N;
			}
			
			
		}
	}
if(M>1 && N==1) k=0;

	if(k) printf("Matrica je cirkularna");
	else if(t) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
