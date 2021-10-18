#include <stdio.h>

int main() {
	int m,n,i,j,teplicova,cirkularna;
	double mat[100][100];
//	printf("Zadaća 2, Zadatak 4");
	do{
	g:	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m>100 || m<=0 || n>100 || n<=0) {
		printf("Pogresan unos!\n");
		 goto g;
	}
	}
	while(m>100 || m<0 || n>100 || n<0);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%lf",&mat[i][j]);
		}
	}
	
	cirkularna=1;
	teplicova=1;
	for(i=0;i<m-1;i++) {
		for(j=0;j<n-1; j++) {
		if( mat[i][j]!=mat[i+1][j+1] || mat[i][n-1]!=mat[i+1][0] ) {
		cirkularna=0;
			}
		if( mat[i][j]!=mat[i+1][j+1]) {
		teplicova=0;
			}
		}
	}
	if(n==1 && m!=1) printf("Matrica je Teplicova");
	 else if(cirkularna==1) printf("Matrica je cirkularna");
	else if(teplicova==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
