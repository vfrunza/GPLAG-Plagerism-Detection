#include <stdio.h>
#include <math.h>
#define tacnost 0.0001

int main() {
	
	int i, j, m, n, teplicova=1, cirkularna=1, obicna=0;
	double matrica[100][100];
	
	
	ponovo1:
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	if(m<1 || m>100 || n<1 || n>100){
		printf("Pogresan unos!\n");
		goto ponovo1;
	}
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf", &matrica[i][j]);
		}
	}
	
	for(i=0;i<m;i++){
		if(i==m-1)continue;
		for(j=0;j<n;j++){
			if(j==n-1)continue;
			if(fabs(matrica[i][j]-matrica[i+1][j+1])<tacnost && ((i+1)<m && (j+1)<n)){ continue;} else {obicna=1; teplicova=0; cirkularna=0, i=m; break;}
		}
	}
	
	for(i=0;i<m;i++){
		if(i==m-1){break;}
		if(fabs(matrica[i][n-1]-matrica[i+1][0])<tacnost){ continue;} else {cirkularna=0; i=m; break;}
	}
    if(cirkularna==1) teplicova=0;
    
    if(obicna==1) printf("Matrica nije ni cirkularna ni Teplicova");
    if(teplicova==1) {printf("Matrica je Teplicova"); return 0;}
    if(cirkularna==1) printf("Matrica je cirkularna");
    
	return 0;
}
