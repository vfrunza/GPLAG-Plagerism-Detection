#include <stdio.h>

int main() {
	
	int M, N, tepl_mat=0, cirk_mat=0;
	int i,j;
	do{
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if(M<=0 || N<=0 || M>100 || N>100) printf("Pogresan unos!\n");
	} while(M<=0 || N<=0 || M>100 || N>100);
	
	double mat[100][100];
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
		scanf("%lf",&mat[i][j]);
		}
	}
	
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
			if(mat[i][j]!=mat[i+1][j+1]) tepl_mat=1;
		}
	}
	if(tepl_mat==0)
	{
		for(i=1;i<M;i++)
		if(mat[i][0]!=mat[i-1][N-1])cirk_mat=1;
		if(cirk_mat==0)printf("Matrica je cirkularna");
		else printf("Matrica je Teplicova");
	}
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
	}
	
