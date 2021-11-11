#include <stdio.h>

int main() {
	int M,N;
	int i,j;
	float A[100][100];
	int cirkularna=1;
	int teplicova=1;
	
	printf("Unesite M i N: ");
	scanf("%d %d",&M,&N);
	
	
	while((M<=0 || M>100) || (N<=0 || N>100)){
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
	}
	printf("Unesite elemente matrice: ");
	
	
		for(i=0;i<M;i++){
			for(j=0;j<N;j++){
				scanf("%f",&A[i][j]);}
		}
				for(i=0;i<M-1;i++){
				   for(j=0;j<N-1;j++){
			if(A[i][j]!=A[i+1][j+1])
			teplicova=0;
		       if(A[i][N-1]!=A[i+1][0])
		       cirkularna=0;
		        
			}
		}
	
		
		if(cirkularna==1 && teplicova==1){
			printf("Matrica je cirkularna ");
		}
	   else if(cirkularna==0 && teplicova==1){
	    	printf("Matrica je Teplicova");
	    }
	  
	    else{
	    	printf("Matrica nije ni cirkularna ni Teplicova");
	    }




	return 0;
}
