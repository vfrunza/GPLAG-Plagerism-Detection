#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int n,m,i,j,teplicova=1,cirkularna=1;
	double mat[100][100]={0};
	
	do{
	
	   printf("Unesite M i N: ");
	   scanf("%d", &m);
       scanf("%d", &n);
	   if((m > 100) || (m<=0) || (n > 100) || (n<=0)) printf("Pogresan unos!\n");
	
	   }while((m > 100) || (m<=0) || (n > 100) || (n<=0));
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%lf", &mat[i][j]);
	    	}
		}
    
   if((n==1) && (m==1)) { printf("Matrica je cirkularna"); return 0; }
   else {
    for(i=0; i<m-1; i++) {
    		if((mat[0][abs(m-n)]!=mat[m-1][n-1]) || (mat[i][n-1]!=mat[i+1][0])) cirkularna=0;
    		for(j=0; j<n-1; j++) {
    		if(mat[i][j]!=mat[i+1][j+1]) teplicova=0;
    		}
    }
   }
    
    if(cirkularna) printf("Matrica je cirkularna");
    else if(teplicova) printf("Matrica je Teplicova");
    else printf("Matrica nije ni cirkularna ni Teplicova");
	
	
	return 0;
}
