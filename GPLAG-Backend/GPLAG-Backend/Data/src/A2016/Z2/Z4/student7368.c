#include <stdio.h>

int main() {
	int i=0,j=0,m=0,n=0,k=0;
	double mat[101][101]={{0}};
	int teplicova=1, cirkularna=1;
	do {
		printf ("Unesite M i N: ");
		scanf ("%d %d",&m, &n);
		if (m<=0 || n<=0 || n>100 || m>100) {
			printf ("Pogresan unos!\n");
		}
	}
	while (m<=0 || n<=0 || m>100 || n>100);
	
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++){
		for (j=0; j<n; j++) {
			scanf ("%lf", &mat[i][j]);
		}
	}
	if (m==1 && n==1) {
		printf ("Matrica je cirkularna");
		return 0;
	}
	else if (m==1) {
		printf("Matrica je cirkularna");
		return 0;
	}
	else if (n==1) {
		printf ("Matrica je Teplicova");
		return 0;
	}
	
else {
	for (i=1; i<=m-1; i++) {
		
		for (j=1; j<n; j++) {
			
            if (mat[i][j]!=mat[i-1][j-1]){
            	teplicova=0; 
            	cirkularna=0;
            	break;
            }
            else {
            	for (k=0; k<m-1; k++) {
            if (mat[k][n-1]!=mat[k+1][0]) {
            	cirkularna=0;
            	break;}
           
            else {
            	teplicova=0;
            break;}
            }}
	}}
}

				
	if (teplicova==1) {
		printf ("Matrica je Teplicova");
	}
	else if (cirkularna==1) {
		printf ("Matrica je cirkularna");
	}
	else if (teplicova==0 || cirkularna==0) {
		printf ("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
