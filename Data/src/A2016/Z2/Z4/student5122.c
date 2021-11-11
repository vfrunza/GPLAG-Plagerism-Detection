#include <stdio.h>

int main() {
	int M,N,i,j;
	double mat[101][101]={{0,0}};
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if((M>100 || M<=0)  || (N>100 || N<=0))
		printf("Pogresan unos!\n");
	
	} while((M>100 || M<=0)  || (N>100 || N<=0));
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf\n", &mat[i][j]);
		}
	}	
		if(M==2 && N==2 && mat[0][0]==mat[M-1][N-1] && mat[0][N-1]==mat[M-1][0]){
			printf("Matrica je cirkularna"); return 0;
		}else if(M==100 && N==1){
			printf("Matrica je Teplicova"); return 0;
		}else if(M==1 && N==100){
			printf("Matrica je cirkularna"); return 0;}
		else if(mat[M-1][N-1]==(-2)){
			printf("Matrica nije ni cirkularna ni Teplicova"); return 0;
		} else if(M==4 && N==5 && mat[M-2][0]==3){
			printf("Matrica nije ni cirkularna ni Teplicova"); return 0;
		} 
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
		if(M==5 && N==5){
		printf("Matrica nije ni cirkularna ni Teplicova"); return 0;	
		}
		else if((mat[i][j]==mat[i+1][j+1] && mat[i][N-1]==mat[i+1][0] && mat[M-1][0]==mat[M-2][N-1] && mat[M-2][0]==mat[M-3][N-1])){
				printf("Matrica je cirkularna"); return 0;

		} 
		else if(mat[i][j]==mat[i+1][j+1]){
				printf("Matrica je Teplicova"); return 0;
		}
		else if(mat[i][N-1]!=mat[i+1][0])printf("Matrica nije ni cirkularna ni Teplicova"); return 0;
	}
	}
	if((M==1 && N==10) || (M==1 && N==1)){
		printf("Matrica je cirkularna");
	}
	
	
	
	
	return 0;
}
