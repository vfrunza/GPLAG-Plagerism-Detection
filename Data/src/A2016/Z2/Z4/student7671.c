#include <stdio.h>

int main() {
	int M, N, i, j, teplicova=1, cirkularna=1, ukupno=0;
	double mat[100][100]={{0}};
	do {
		printf ("\nUnesite M i N: ");
		scanf ("%d %d", &M, &N);
		if(!(M>0 && M<101 && N>0 && N<101))
		printf("Pogresan unos!");
		ukupno=M-N;
		if(ukupno<0) ukupno=-ukupno;
	} while (M<1 || M>100 || N<1 || N>100);
	printf ("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=0;i<M-1;i++) {
		for(j=0;j<N-1;j++) {
			if(mat[i][j]!=mat[i+1][j+1]) teplicova=0;
			else if (mat[i][N-1]!=mat[i+1][0] || mat[0][ukupno]!=mat[M-1][N-1]) cirkularna=0;
		}
	}
	if(teplicova==0) {
		cirkularna=0;
			for(i=1;i<M;i++) {
				if(mat[i][0]!=mat[0][M-i])
				cirkularna=0;
			}
	}
	if(cirkularna==1) printf("Matrica je cirkularna");
	else if(teplicova==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
