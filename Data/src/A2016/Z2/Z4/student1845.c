#include <stdio.h>

int main() {
	int M,N,i,j,t=1,c=1;
	double mat[100][100];
	
	do{
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if(M<=0 || M>100 || N<=0 || N>100) {
	printf("Pogresan unos!\n");
	     }
	}while(M<=0 || M>100 || N<=0 || N>100);
		
		printf("Unesite elemente matrice: ");
		for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf", &mat[i][j]);
		    }
		    
		}
		if(N==1) {
			t=1;
			c=0;

		}
        if(M==1) {
        	t=0; c=1;
        }
	for(i=0; i<M-1; i++) {
		for(j=0; j<N-1; j++) {
			
			
			if(mat[i][j]!=mat[i+1][j+1])	t=0;
			if((mat[i][j]!=mat[i+1][j+1]) || (mat[i][N-1]!=mat[i+1][0])) c=0;
			
		}
		
	}

	if(t==1 && c==0) { printf("Matrica je Teplicova");  }
	  else if(t==0 && c==0) { printf("Matrica nije ni cirkularna ni Teplicova"); }
      else if( c==1 && (t==0 || t==1)) { printf("Matrica je cirkularna");
      }
	
	return 0;
}
