#include <stdio.h>

int main() {
    int m=0, n=0, i=0, j=0, teplicova=1, cirkularna=1;
    double matrica[100][100]={{0}};
	do{
	    printf("Unesite M i N: ");
	    scanf("%d %d", &m, &n);
	    if(m<=0 || m>100 || n<=0 || n>100)
	        printf("Pogresan unos!\n");
	}while(m<=0 || m>100 || n<=0 || n>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
	    for(j=0; j<n; j++){
	        scanf("%lf", &matrica[i][j]);
	    }
	}
	for(i=0; i<m-1; i++){
	    for(j=0; j<n-1; j++){
	        if(matrica[i][j]!=matrica[i+1][j+1] || matrica[i][n-1]!=matrica[i+1][0]){
	                    cirkularna=0;
	                    i=m;
	                    j=n;
	        }
	    }
	}
	for(i=0; i<m-1; i++){
	    for(j=0; j<n-1; j++){
	        if(matrica[i][j]!=matrica[i+1][j+1]){
	                teplicova=0;
	                i=m;
	                j=n;
	        }
	    }
	}
	if(m>1 && n==1)
	    cirkularna=0;
	if(cirkularna==1) 
	    printf("Matrica je cirkularna");
	else if(teplicova==1) 
	    printf("Matrica je Teplicova");
	else 
	    printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
