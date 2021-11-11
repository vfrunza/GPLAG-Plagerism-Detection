#include <stdio.h>

int main() {
	int m,n, i, j, teplicova=1, cirkularna=1;
	do{
		printf("Unesite M i N: ");
		scanf("%d%d", &m, &n);
		if(m>0&&m<=100&&n>0&&n<=100)
			break;
		printf("Pogresan unos!\n");
	}while(1);
	
	double mat[100][100];
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf", &mat[i][j]);
		}
		
	}
	for(i=0;i<(m-1);i++){
		for(j=0;j<(n-1);j++){
			if(mat[i][j]!=mat[i+1][j+1]){
				teplicova=0;
				break;
			}
		}
		if(teplicova==0)
			break;
	}
	for(i=0;i<(m-1);i++){
		for(j=0;j<n;j++){
			if(j==(n-1)){
				if(mat[i][j]!=mat[i+1][0]){
					cirkularna=0;
					break;
				}
			}
				
			
		}
		if(cirkularna==0)
			break;
	}
	
	
	if(teplicova){
		if(cirkularna){
			printf("Matrica je cirkularna");
			return 0;	
		}
		else{
			printf("Matrica je Teplicova");
			return 0;
		}
	}
	printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
