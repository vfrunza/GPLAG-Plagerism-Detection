#include <stdio.h>
#include <math.h>
#define eps 0.00001
int main() {
	int m,n,i,j,teplicova=1,cirkularna=1;
	double mat[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d%d",&m,&n);
		if(m<=0 || m>100 || n<=0 || n>100) printf("Pogresan unos!\n");
	}while(m<=0 || m>100 || n<=0 || n>100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&mat[i][j]);
		}
	}
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
		if(fabs(!(mat[i][j]-mat[i+1][j+1]))<eps) teplicova=0;	
		}
	}
	if(teplicova) {
		for(i=0;i<m-1;i++){
			for(j=0;j<n;j++){
				if(fabs(!(mat[i][n-1]-mat[i+1][0]))<eps) cirkularna=0;
		}
	}
	if(cirkularna) printf("Matrica je cirkularna");
	else printf("Matrica je Teplicova");
	}
	else printf ("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
