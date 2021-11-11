#include <stdio.h>
#include<stdlib.h>
#define M 100
#define E 0.0000000000000001

int main() {
	double mat[M][M];
	int m, n, i, j, teplicova=0, cirkularna=0, sum;
	do{
		printf ("Unesite M i N: ");
		scanf ("%d %d", &m, &n);
		if (m<=0 || m>100 || n<=0 ||n>100){
			printf ("Pogresan unos!\n");
			
		}
		
		
	} while (m<=0 || m>100 || n<=0 || n>100);
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			scanf ("%lf",&mat[i][j]);
		}
	}
	for (i=0; i<m-1; i++){
		for(j=0; j<n-1; j++){
			if (mat[i][j]!=mat[i+1][j+1])
				teplicova=1;
			
			}
	}
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
				if (i-1<0) continue;
				if(mat[i-1][n-1]!=mat[i][0])
				cirkularna=1;
		}
	}
	
	sum=teplicova+cirkularna;
	switch (sum) {
		case 2:
			printf ("Matrica nije ni cirkularna ni Teplicova");
			break;
		case 1:
			printf ("Matrica je Teplicova");
			break;
		case 0:
			printf ("Matrica je cirkularna");
	}
	return 0;
}
