#include <stdio.h>

int main() { 
	int m, n, i, j,  br1=0, br2=0; 
	double mat[100][100];
	printf("Unesite M i N: ");
	do{
		scanf("%d %d", &m, &n); 
		if(m<=0 || m>100 || n<=0 || n>100) {
			printf("Pogresan unos!");  
			printf("\nUnesite M i N: "); 
		}
	} while(m<=0 || m>100 || n<=0 || n>100);   
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=0; i<m-1; i++){
		for(j=0; j<n-1; j++){
			if(mat[i][j]==mat[i+1][j+1]) br1++;
		}
	} 
	for(i=0; i<m-1; i++){ 
		if(mat[i][n-1]==mat[i+1][0] && i<m) br2++;
	}
	if(br1==(m-1)*(n-1) && br2==m-1) printf("Matrica je cirkularna");
	else if(br1==(m-1)*(n-1) && br2!=m-1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
