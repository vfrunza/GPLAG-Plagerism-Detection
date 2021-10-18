#include <stdio.h>

int main() {
	
	int m, n, i, j;
	float mat[100][100];
	int teplicova=1;
	int cirkularna=1;
	
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
	if(m<1 || m>100 || n<1 || n>100){
		printf("Pogresan unos!\n");
	}
		}while(m<1 || m>100 || n<1 || n>100);
		
		printf("Unesite elemente matrice: ");
		
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				scanf("%f",&mat[i][j]);
			}
		}
		
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(j>=i){
					if(mat[i][j]!=mat[0][j-i]){
						teplicova=0;
				}
					
				}
				else if(j<i){
					if(mat[i][j]!=mat[i-j][0]){
						teplicova=0;
					}
				}
			
		  }
			
		}
			if(teplicova==0) {
				cirkularna=0;
			}if(teplicova==1){
				for(i=1;i<m;i++){
					for(j=0;j<n;j++){
						if(mat[i][0]!=mat[i-1][n-1]){
							cirkularna=0;
						}
					}
				}
			}
			if(cirkularna){
				printf("Matrica je cirkularna");
			}else if(teplicova){
				printf("Matrica je Teplicova");
			}else {
				printf("Matrica nije ni cirkularna ni Teplicova");
			}
	
		return 0;
}
