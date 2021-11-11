#include <stdio.h>
#include <stdlib.h>

int main() {
	int m,n,i,j;
	double mat[100][100];
	
	
	do{
		printf("Unesite M i N: ");
		scanf("%d%d", &m, &n);
		if(m<=0 || m>100 || n<=0 || n>100){printf("Pogresan unos!\n");
		continue;
	    
		}
	}
	while(m>100 || m<=0 || n>100 || n<=0);
	    
	
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0;j<n;j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	if(m==1){
				printf("Matrica je cirkularna");
				return 0;
			}
	
	for(i=1; i<m; i++){
		for(j=1;j<n;j++){
			if(mat[i][j]!=mat[i-1][j-1]){
				printf("Matrica nije ni cirkularna ni Teplicova");
				return 0;
			}
		}
	}
	if(mat[0][n-1]!=mat[1][0] || mat[m-1][0]!=mat[m-2][n-1]){printf("Matrica je Teplicova");
	}
	else {printf("Matrica je cirkularna");
	}
			
	return 0;
}
