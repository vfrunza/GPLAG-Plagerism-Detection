#include <stdio.h>

int main() {
	int teplicova,cirkularna,i,j,m,n;
	double mat[100][100];
	printf("Unesite M i N: ");
	scanf("%d%d", &m,&n);
    while(m>100 || m<=0 || n>100 || n<=0){
    	printf("Pogresan unos!\n");
    	printf("Unesite M i N: ");
	    scanf("%d%d", &m,&n);
    }
    
	printf("Unesite elemente matrice: ");
	teplicova=1;
	for (i=0;i<m;i++){
		for(j=0;j<n;j++){
	    scanf("%lf", &mat[i][j]);
	}
	}
	if (n==1 && m!=1){ printf("Matrica je Teplicova"); return 0;}
	for (i=1;i<m;i++){
		for(j=1;j<n;j++){
	    if(mat[i][j]!=mat[i-1][j-1]) teplicova=0;
		
	}
	}
	if (teplicova==1) {
		cirkularna=1;
		for (i=1;i<m;i++)
			if(n-i>0)
		    if(mat[i][0]!=mat[0][n-i]){ cirkularna=0;}
		    if(cirkularna==1)
		    printf("Matrica je cirkularna");
		    else printf("Matrica je Teplicova");
		    
		
		
	} 	
	else printf("Matrica nije ni cirkularna ni Teplicova");

	return 0;
}
