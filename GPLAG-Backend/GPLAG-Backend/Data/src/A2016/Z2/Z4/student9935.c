#include <stdio.h>
#include <stdlib.h>
#define epsilon 0.0000001
int main() {
	int M,N,i,j,teplicova,cirkularna;
	double mat[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M>100 || M<=0 || N>100 || N<=0)
			printf("Pogresan unos!\n");
		else
			break;
	}while(M>100 || M<=0 || N>100 || N<=0);
		printf("Unesite elemente matrice: ");
			for(i=0;i<M;i++){
				for(j=0;j<N;j++){
					scanf("%lf",&mat[i][j]);
				}
			}
			if(N==1 && M>1){
				printf("Matrica je Teplicova");
			}
			else{
				teplicova=1;
				cirkularna=1;
				for(i=0;i<M-1;i++){
					for(j=0;j<N-1;j++){
						if(abs(mat[i][j]-epsilon)!=abs(mat[i+1][j+1]-epsilon)){
							teplicova=0;
							cirkularna=0;
						}
						else if(abs(mat[i][N-1]-epsilon)!=abs(mat[i+1][N-N]-epsilon)){
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
				else{
					printf("Matrica nije ni cirkularna ni Teplicova");
				}
			}
	
	return 0;
}