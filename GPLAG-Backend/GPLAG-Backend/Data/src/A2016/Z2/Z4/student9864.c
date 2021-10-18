#include <stdio.h>
#include <math.h>
int poredi( double x, double y){
	const double Eps=0.0000000001;
	return fabs(x-y)<=Eps*(fabs(x)+fabs(y));
}

int main() {
	int m,n,i=0,j=0,teplicova=1,cirkularna=1;
	double mat[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if(m>100 || n>100 || m<1 || n<1) printf("Pogresan unos!\n");
	}while(m>100 || n>100|| m<1 ||n<1);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1; j++){
			if(!poredi(mat[i][j],mat[i+1][j+1])) teplicova=0;
		}
	}
	for(i=0; i<m-1; i++){
		for(j=0;j<n;j++){
			if(j!=n-1){
				if(!poredi(mat[i][j],mat[i+1][j+1])) cirkularna=0;
			}
			else
				if(!poredi(mat[i][j],mat[i+1][0])) cirkularna=0;
		}
	}
	if(cirkularna) printf("Matrica je cirkularna");
	else if(teplicova) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
