#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 0.00001
int main() {
int i, j, M, N, cirkularna=1, teplicova=1;
double mat[100][100];

do{
	printf("Unesite M i N: ");
	scanf("%d %d",&M, &N);
	if((M>100 || M<=0) || (N>100 || N<=0))
	printf("Pogresan unos!\n");
}while(M>100 || M<=0 || N>100 || N<=0);

printf("Unesite elemente matrice: ");

for(i=0; i<M; i++){
	for(j=0; j<N; j++){
		scanf("%lf ", &mat[i][j]);
	}
}

for(i=0; i<M-1; i++){
	for(j=0; j<N-1; j++){
		if(fabs(mat[i][j]-mat[i+1][j+1])>EPS)
	    teplicova=0;
	}
}

for(i=0; i<M-1; i++){
	
		if(fabs(mat[i][N-1]-mat[i+1][0])>EPS)
		cirkularna=0;
        
	}
	
if(cirkularna==1 && teplicova==1)
	printf("Matrica je cirkularna");
else if(teplicova==1 && cirkularna==0)
	printf("Matrica je Teplicova");
else 
    printf("Matrica nije ni cirkularna ni Teplicova");

	return 0;
}
