#include <stdio.h>

int main() {
	int i,j,M,N, mat[100][100], teplicova=1; 
	int cirkularna=0;
	do {
		printf("\nUnesite M i N: ");
		scanf("%d %d", &M,&N);
		if(M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\nUnesite M i N: ");
	} while(M<0 || M>100 || N<0 || N>100); 
	printf("Unesite elemente matrice: "); 
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	for(i=0; i<M-1; i++) {
	for(j=0; j<N; j++) {
		if(mat[i][j]!=mat[i+1][j+1]) {
		teplicova=0; }
	 
	} }
	if(M==1 && N==1) 
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			if(mat[N-i][j]==mat[i][j]) cirkularna=1;
		}
	}
	if(teplicova=0) printf("Matrica je Teplicova");
	else if(cirkularna=1) printf("Matrica je cirkularna");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}