#include <stdio.h>

int main() {
	int m,n,i,j;
	int brt=0,brc=0;
	double mat[100][100]={{0}};
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &m,&n);
		if(m>100 || n>100 || n<=0 || m<=0) printf("Pogresan unos!\n");
		
	}while(m>100 || n>100 || m<=0 || n<=0);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf", &mat[i][j]);
		}
	}
		
	
	
	for(i=1;i<m;i++){
		if(mat[i-1][n-1]==mat[i][0])	brc++;
	}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			
			if(mat[i-1][j-1]==mat[i][j]) brc++;
			if(mat[i-1][j-1]==mat[i][j]) brt++;
		
		}
	}
	
	if(brc==(m-1)*n) printf("Matrica je cirkularna");
	else if(brt==(m-1)*(n-1)) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
