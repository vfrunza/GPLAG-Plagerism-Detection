#include <stdio.h>
#include <math.h>
#define EPSILON 0.00000001

int main() {
	
	int m, n, i, j, teplicova=1;
	double matrica[100][100];
	do{
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	if(m<0 || m>100 || n<0 || n>100) 
		printf("Pogresan unos!\n");
	
	}
	while(m<0 || m>100 || n<0 || n>100);
	
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%lf", &matrica[i][j]);
		}
	}
	

				
	
		
			for(i=0; i<m-1; i++){
				for(j=0; j<n-1; j++){
					if(fabs(matrica[i][j]-matrica[i+1][j+1])>EPSILON)
					teplicova=0;
				}
			}
					if(teplicova==1){
					printf("Matrica je Teplicova");
					return 0;
					}
			
		
		if(teplicova==0) printf("Matrica nije ni cirkularna ni Teplicova");
	
	
	return 0;
}
