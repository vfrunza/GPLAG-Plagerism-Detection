#include <stdio.h>
#include <math.h>
#define MAX 100
#define e 0.001

int main(){
	double mat[MAX][MAX];
	int i,j,Teplicova=0,Cirkularna=1,M,N,t=1, s=0;
	
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if((M>MAX || M<=0) || (N>MAX || N<=0))
		printf("Pogresan unos!\n");
	}
	
	while((M>MAX || M<=0) || (N>MAX || N<=0));
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf", &mat[i][j]);
		}
			}	
		for(i=1; i<M; i++){
			for(j=1; j<N; j++){
				if(fabs(mat[i][j]-mat[i-t][j-t])>e || fabs(mat[i][s]-mat[s][N-i]>e))
				Cirkularna=0;
				if(fabs(mat[i][j]-mat[i-t][j-t]<e))
				Teplicova=1;
				if(fabs(mat[i][j]-mat[i-t][j-t])>e){
					Teplicova=0;
					break;}
				}
				
			}
			
			if(M==1 && N==1)
				printf("Matrica je cirkularna");
			else if (N==1)
				printf("Matrica je Teplicova");
			else if (Teplicova==0 && Cirkularna==0)
				printf("Matrica nije ni cirkularna ni Teplicova\n");
			else if (Cirkularna==1)
				printf("Matrica je cirkularna\n");
			else if(Cirkularna==0 && Teplicova==1)
				printf("Matrica je Teplicova\n");
			
return 0;
}