#include <stdio.h>

int main() {
	int mat[100][100],m,n,i,j,anja=0;
	
	do{
		printf("Unesite M i N: ");
		scanf("%d%d", &m, &n);
		if(m<=0 || n<=0 || m>100 || n>100){
			printf("Pogresan unos!\n");
		}
	}while(m<=0 || n<=0 || m>100 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(i==j && i==i+1){
				anja++;
			}
		}
	}
	if(anja==m-1){
		printf("Matrica je cirkularna");
	}
	else if(anja==m*n){
		printf("Matrica je Teplicova");
	}
	else{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
