#include <stdio.h>
#include <math.h>
#define epsilon 0.0000000001
int main() {
	int M,N,i,j;
	double mat[100][100];
	int teplicova=1, cirkularna=1;
	
	do {
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
		if(M>0 && M<=100 && N>0 && N<=100)
		break;
		else 
		printf("Pogresan unos!\n");
	}
	
	while(M>100 || M<100 || N>100 || N<100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		
		for(j=0; j<N; j++) {
			scanf("%lf", &mat[i][j]);
		}
		
	}
	for(i=0; i<M-1; i++) {
		if(fabs (mat[i][N-1]-mat[i+1][0])>epsilon) {
			cirkularna=0;
		}
		for(j=0; j<N-1; j++){
			if(fabs(mat[i][j]-mat[i+1][j+1])>epsilon){
				teplicova=0;
				cirkularna=0;
			}
			if(fabs(mat[i][N-1]-mat[i+1][0])>epsilon) {
				
				cirkularna=0;
		
			}
		}
		
	}
	if(cirkularna==1) {
		printf("Matrica je cirkularna");
		return 0;
	}
	if(teplicova==1 && cirkularna==0) {
		printf("Matrica je Teplicova");
		return 0;
	}
	else 
	printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
