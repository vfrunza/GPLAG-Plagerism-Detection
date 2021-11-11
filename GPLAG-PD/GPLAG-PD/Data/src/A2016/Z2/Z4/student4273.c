#include <stdio.h>
#include <math.h>

int main() {
	int m,n,i,j,teplicova,cirkularna;
	double mat[100][100];
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m<1 || m>100 || n<1 || n>100) printf("Pogresan unos!\n");
	}while(m<1 || m>100 || n<1 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&mat[i][j]);
			
		}
	}
cirkularna=1;
	for(i=0;i<=m-2;i++){
		for(j=0;j<=n-2;j++){
			if(!((fabs(mat[i][j]-mat[i+1][j+1])<0.0000000000001) && (fabs(mat[i][n-1]-mat[i+1][0])<0.000000000001))) {
			cirkularna=0;
	break;
			}
			}
	}

		teplicova=1;
	for(i=0;i<=m-2;i++){
		for(j=0;j<=n-2;j++){
			if(!(fabs(mat[i][j]-mat[i+1][j+1])<0.000000001)){
			teplicova=0;
			break;
			}
		}
	}

	

	if(m==1 && n==1) printf("Matrica je cirkularna");
	else if(n==1) printf("Matrica je Teplicova");
	else if(cirkularna) printf("Matrica je cirkularna");
	else if(teplicova) printf("Matrica je Teplicova"); 
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
