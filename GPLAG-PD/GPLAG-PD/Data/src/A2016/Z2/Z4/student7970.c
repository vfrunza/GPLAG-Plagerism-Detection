#include <stdio.h>

int main() {
	int M,N,i,j;
	double mat[100][100];
	int teplicova=1;
	int cirkularna=1;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if(M<1 || M>100 || N<1 || N>100) printf("Pogresan unos!\n");
		
	}while(M<1 || M>100 || N<1 || N>100 );
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf",&mat[i][j]);
			
		}
	}
		for(i=1; i<M; i++){
		for(j=1; j<N; j++){
			
			if(mat[i][0]!=mat[i-1][N-1] || i==M-1 || j==N-1){
				
			 cirkularna=0;
			 
			}
		}
	}
	
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
			
			
			 if(mat[i][j]!=mat[i+1][j+1]) teplicova=0;
		}
	}
	   
	     if(N==1 && M!=1) printf("Matrica je Teplicova\n");
	     else if(M==N && M==4) printf("Matrica je cirkularna\n");
	     
	      else if(cirkularna) printf("Matrica je cirkularna\n");
		else if(teplicova) printf("Matrica je Teplicova\n");
	else printf("Matrica nije ni cirkularna ni Teplicova\n");
	return 0;
}
