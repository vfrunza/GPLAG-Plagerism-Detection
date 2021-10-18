#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 0.000001

int main() {
	
	int M, N, i=0, j=0, teplicova=1, cirkularna=1;
	double mat[100][100];
	
	do {
		printf("Unesite M i N: ");
		scanf("%d%d", &M, &N); 
		if(M<=0 || M>100 || N<=0 || N>100)
		printf("Pogresan unos!\n");
	}

	while(M<=0 || M>100 || N<=0 || N>100);
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf", &mat[i][j]);
			}
	}
	

	for(i=0; i<M-1; i++) {
		for(j=0; j<N-1; j++){
			if((fabs(mat[i][j]-mat[i+1][j+1])<=EPS) && (fabs(mat[i][N-1]-mat[i+1][0])<=EPS) || (fabs(mat[M-1][j]-mat[0][N-1])<=EPS)  ) 
			cirkularna=1; 
			else cirkularna=0;
			if(cirkularna==0) { break; }
			}
			
			
		}
		
	
	
		if((M==1 && N==1) || (M==1 && N!=1))  { 
		
			printf("Matrica je cirkularna");
		return 0; }
	
	
	for(i=0; i<M-1; i++) {
		for(j=0; j<N-1; j++) {
			if(fabs(mat[i][j]-mat[i+1][j+1])>EPS || (mat[M-2][N-2]!=mat[M-1][N-1]))  
			teplicova=0;
			else teplicova=1;
			
		if(teplicova==0)	break;
			}
		}
	
	
	 if(cirkularna==1 && teplicova == 0) printf("Matrica je cirkularna");
	
	 else if((cirkularna==1 && teplicova==1) || (teplicova==1 && cirkularna==0)) printf("Matrica je Teplicova");
	
	 else if( ( M==N &&  mat[0][0]!=mat[M-1][N-1] ) || (teplicova==0 && cirkularna==0) ) printf("Matrica nije ni cirkularna ni Teplicova");
	

	
	
	return 0;
}
