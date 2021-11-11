#include <stdio.h>
#define SIRINA 100

int main() {
	int i,j,m,n,teplicova=1,cirkularna=1;
	double mat[SIRINA][SIRINA];
	do {
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m<=0 || m>100 || n<=0 || n>100) printf("Pogresan unos!\n"); } while(m<=0 || m>100 || n<=0 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%lf",&mat[i][j]);
		}
	}
	
		for(i=0;i<m-1;i++) {
			for(j=0;j<n-1;j++) {
				if(mat[i][j]!=mat[i+1][j+1] || mat[i][n-1]!=mat[i+1][0]) {
					cirkularna=0;
					break;
				}
			}
			if(cirkularna==0) break;
		}
		if(cirkularna==1) printf("Matrica je cirkularna");
		
		else {
	
	for(i=0;i<m-1;i++) {
		for(j=0;j<n-1;j++) {
			if(mat[i][j]!=mat[i+1][j+1]) {
				teplicova=0;
				break; }
		}
		if(teplicova==0) break;
		
	}
	if(teplicova==1) printf("Matrica je Teplicova");
	
}
	if(teplicova==0 && cirkularna==0) printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
