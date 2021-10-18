#include <stdio.h>

int main() {
	int mat[100][100],m,n,i,j,brojac=0;
	
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m>100 || n>100 || m<=0 || n<=0){
			printf("Pogresan unos!\n");
		}
	} while(m>100 || n>100 || m<=0 || n<=0);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d",&mat[i][j]);
		}
	}
	
    
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			if(i==j){
				if(i==i+1){
					brojac++;
				}
			}
			
			
		}
	
	}
	if(brojac==m){
		printf("Matrica je Teplicova");
	}
	
	else if(brojac==m-1){
		printf("Matrica je cirkularna");
	}
	else{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
