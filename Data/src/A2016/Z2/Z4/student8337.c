#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 101
#define N 101
#define EPSILON 0.0001


int main() {
	int i, j, m, n, teplicova=1, cirkularna=1;
	double mat[M][N];
	do{
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	if( m<1 || m>100 || n<1 || n>100 ) printf("Pogresan unos!\n");
	}while(m<1 || m>100 || n<1 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	
	for(i=1; i<m; i++){
		for(j=1; j<n; j++){
			
			if(fabs(mat[i][j] - mat[i-1][j-1]) > EPSILON){
				teplicova = 0;
				break;
			}
			
		}
		if(teplicova==0) break;
	}
	
	if(teplicova){
		
		if(n==1&& m>1){
			cirkularna=0;
		}
		
		for(i=1; i<m; i++){
			for(j=0; j<n; j++){
				
				if(j==0){
					if(fabs(mat[i][j]-mat[j][n-i]) > EPSILON){
						cirkularna = 0;
						break;
					}
				}
			}
			if(cirkularna==0) break;
		}
		
		if(cirkularna){
			printf("Matrica je cirkularna");
		}else {
			printf("Matrica je Teplicova");
		}
		
	}else{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
