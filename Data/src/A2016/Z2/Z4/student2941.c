#include <stdio.h>
#define duzina 100
#define razlika 0.0001

int main() {
	
	int m,n,i,j,br=0,brojac=0;
	double mat[duzina][duzina];
	
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	if(m>100 || n>100 || m<=0 || n<=0) {
	do {
		printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
	
	}while(m>100 || n>100 || m<=0 || n<=0);
	}
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%lf",&mat[i][j]);
		}
	}
	
	if(m==1) { printf("Matrica je cirkularna"); return 0; }
	if(n==1) { printf("Matrica je Teplicova"); return 0; }
	
	for(i=0;i<m-1;i++) {
				
		if(mat[i][n-1]==mat[i+1][0]) br++;
	}
	
	
	
	for(i=0;i<m-1;i++) {
		for(j=0;j<n-1;j++) {
			if(mat[i][j]==mat[i+1][j+1]) brojac++;
		}
	}
	

	if(br==m-1 && brojac==(m-1)*(n-1)) printf("Matrica je cirkularna");
	else if(brojac==(m-1)*(n-1)) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	
	return 0;
}
