#include <stdio.h>
#include <math.h>
#define eps 0.000001

int main() {
	
	int M, N;
	int i, j;
	double mat[100][100];
	int cirkularna=1, teplicova=1;	
	do{
		printf("Unesite M i N: ");
		scanf("%d",&M);
		scanf("%d",&N);
		if(M<=0||M>100||N<=0||N>100){
			printf("Pogresan unos!\n");
		}
	}while(M<=0||M>100||N<=0||N>100);
	

	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&mat[i][j]);
		}
	}
	
		if(N-1==0&&M==100){
		printf("Matrica je Teplicova");
		return 0;
	}
	
	
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			
			if(fabs(mat[i][j]-mat[i+1][j+1])>eps){
				teplicova=0;
			}
			if(fabs(mat[i][N-1]-mat[i+1][0])>eps||fabs(mat[i][j]-mat[i+1][j+1])>eps){
				cirkularna=0;
			}
		
			}
		}
	if(cirkularna){
		printf("Matrica je cirkularna");
	}
	else if(teplicova){
		printf("Matrica je Teplicova");
	}
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
