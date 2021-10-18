#include <stdio.h>

int main() {
	int i,j;
	int M=0,N=0;
	int teplicova=1,cirkularna=1;
	float mat[100][100];

	while(1){
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M>100 || N>100 || M<=0 || N<=0){ printf("Pogresan unos!\n"); continue;}
		if(M<=100 && M>0 && N<=100 && N>0) break;
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%f",&mat[i][j]);
		}
	}
	for(i=1;i<M-1;i++){
		for(j=1;j<N-1;j++){
			if(mat[i][j]!=mat[i+1][j+1]){
				teplicova=0;
			}
			if(mat[i][N-1]!=mat[i][0]){ cirkularna=0; }
			else teplicova=1;
		}
	}
	if(cirkularna==1 &&( teplicova==1|| teplicova==0)) printf("Matrica je cirkularna\n");
	else if(teplicova==1 && cirkularna==0) printf("Matrica je Teplicova\n");
	else if(teplicova==0 && cirkularna==0) printf("Matrica nije ni cirkularna ni Teplicova\n");
	return 0;
}
