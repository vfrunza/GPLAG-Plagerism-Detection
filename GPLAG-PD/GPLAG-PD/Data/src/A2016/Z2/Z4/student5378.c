#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int M,N,i,j,teplicova=1,cirkularna=1;
	double MAT[100][100];
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&M,&N);
					if(M<1 || M>100 || N<1 || N>100) printf("Pogresan unos!\n");
	}
	while ((M<1 || M>100) || (N<1 ||  N>100));
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&MAT[i][j]);
		}
	}
if (M==1&&N==1) printf("Matrica je cirkularna");
else if(M==1) printf("Matrica je cirkularna");
else if(N==1)printf("Matrica je Teplicova");
else {
	for (i=1;i<M;i++){
		if(MAT[i][0]!=MAT[i-1][N-1])cirkularna=0;
		for(j=1;j<N;j++){
			if(MAT[i][j]!=MAT[i-1][j-1]) cirkularna=0;
		}
	}
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			if(MAT[i][j]!=MAT[i+1][j+1]) teplicova=0;
		}
	}
	if(cirkularna==1) printf("Matrica je cirkularna");
	else if(teplicova==1)printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
}
	return 0;
}
