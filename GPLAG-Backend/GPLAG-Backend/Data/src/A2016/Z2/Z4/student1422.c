#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	int i=0,j=0,m=0,n=0,tep=1,cir=1;
	double mat[100][100];
	do{
	printf("Unesite M i N: ");
	scanf("%d %d", &m,&n);
	if(m<1 || n<1 || m>100 || n>100)
	printf("Pogresan unos!\n");
	else
	break;
	}while(1);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&mat[i][j]);
		}
	}
	
	for(i=1;i<m;i++){
		for(j=0;j<n;j++){
			if(j==0){
				if(!(fabs(mat[i][j]-mat[i-1][n-1])<EPSILON))
				cir=0;
			}
				else if (j!=0){ 
				if(!(fabs(mat[i][j]-mat[i-1][j-1])<EPSILON))
			cir=0;
				}
		}
	}
	
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(!(fabs(mat[i][j]-mat[i+1][j+1])<EPSILON))
			tep=0;
		}
	}

	if(cir==1)
	printf("Matrica je cirkularna");
	else if(tep==1)
	printf("Matrica je Teplicova");
	else
	printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
