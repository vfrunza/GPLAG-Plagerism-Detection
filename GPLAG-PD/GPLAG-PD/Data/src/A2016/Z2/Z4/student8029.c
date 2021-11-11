#include <stdio.h>


int main() {
    double mat[100][100];
    int M=0,N=0;
    int i, j, k, p=0;
   do {
			printf("Unesite M i N: ");
			scanf("%d %d", &M , &N);
			if(M >100 || M<=0 || N>100|| N<=0 ) printf("Pogresan unos!\n");
	} while (M >100 || M<=0 || N>100|| N<=0 );
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<M; i++)
	{
	    for(j=0; j<N;j++)
	    scanf("%lf",&mat[i][j]);
	}
	
	for(i=0; i<M; i++)
	{
	    for(j=0; j<N;j++)
	    { 
	        for(k=0; k<N; k++)
	            if (mat[0][k]!=mat[i][j] && i+k==j){ printf("Matrica nije ni cirkularna ni Teplicova"); return 0;}
	        
	        for(k=0; k<M; k++)
	            if (mat[k][0]!=mat[i][j] && i-k==j){ printf("Matrica nije ni cirkularna ni Teplicova"); return 0;}  
	       if(M>1) 
	       {
	        for(k=0; k<M-1; k++)
	            if (mat[k][N-1]!=mat[k+1][0]){p=1;}
	       }
	       else if (M==1){printf("Matrica je cirkularna"); return 0;}
	    }
	       
	    
	}  
	
	if(p!=1) printf("Matrica je cirkularna");
	else printf("Matrica je Teplicova");
	
	return 0;
}
