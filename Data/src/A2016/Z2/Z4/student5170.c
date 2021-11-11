#include <stdio.h>

int main() {
	int M,N,i,j,tepl=0,cirk=1;
	double mat[100][100];
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if (M<=0 || N<=0 || M>100 || N>100) printf("Pogresan unos!\n");
	} while (M<=0 || N<=0 || M>100 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
		for(i=0; i<M-1; i++) {
		for(j=0; j<N-1; j++) {
			if(mat[i+1][j+1]!=mat[i][j] || mat[i+1][0]!=mat[i][N-1]) cirk=0;
			if(mat[i][j]==mat[i+1][j+1])
			tepl=1; 
			if(mat[i][j]!=mat[i+1][j+1]) {tepl=0; break;}
		}}
		if (M==1 && N==1) printf("Matrica je cirkularna");
		else if (N==1) printf("Matrica je Teplicova");
		else if(cirk==1) printf("Matrica je cirkularna");
			else if(tepl==1 && cirk==0) {printf("Matrica je Teplicova");}
			else if(tepl==0 && cirk==0) printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
