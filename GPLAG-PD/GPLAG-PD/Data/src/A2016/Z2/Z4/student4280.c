#include <stdio.h>

int main() {
    
    int i=0,j=0,M=0,N=0,teplicova,cirkularna;
    double mat[100][100];
    
    do {
    	printf("Unesite M i N: ");
    	scanf("%d %d",&M,&N);
    	if (M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\n");
    	else break;
    } while (1);
    
    
        printf("Unesite elemente matrice: ");
        for (i=0;i<M;i++) {
            for (j=0;j<N;j++) {
            scanf("%lf",&mat[i][j]);
        
        }
    }
    
    teplicova=1;
    for(i=0;i<M-1;i++) {
        for(j=0;j<N-1;j++) {
            if (mat[i][j]!=mat[i+1][j+1])
            teplicova=0;
        }
    }
    
    cirkularna=1;
    for(i=1;i<M;i++) {
        for(j=0;j<N;j++) {
            if( j==0 && mat[i][j]!= mat [i-1][N-1]) 
            cirkularna = 0;
            else if(j!=0 && mat[i][j]!=mat[i-1][j-1]) 
            cirkularna = 0;
        }
    }
        
       if(cirkularna==1) printf("Matrica je cirkularna");
       else if(teplicova==1) printf("Matrica je Teplicova");
       else printf("Matrica nije ni cirkularna ni Teplicova");
       
       return 0;
}