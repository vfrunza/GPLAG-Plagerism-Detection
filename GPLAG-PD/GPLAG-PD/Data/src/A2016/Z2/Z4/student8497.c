#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int m,n,i,j,teplicova,cirkularna;
	double matrica[100][100];
	const double Eps=1e-10;
	teplicova=1;cirkularna=0;
	
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m>100 || m<=0 || n<=0 || n>100)printf("Pogresan unos!\n");
	}
	while(m>100 || m<=0 || n<=0 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&matrica[i][j]);
		}
	}
	
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(fabs(matrica[i][j])>Eps && fabs(matrica[i+1][j+1])>Eps)
			if( fabs(matrica[i][j]-matrica[i+1][j+1]) >= Eps*(fabs(matrica[i][j])+fabs(matrica[i+1][j+1])) ){teplicova=0;break;}
		}
	}

	if(teplicova==1){
	cirkularna=1;
	for(i=0;i<m-1;i++){
		for(j=0;j<=n-1;j++){
			if(fabs(matrica[i][n-1]-matrica[i+1][0])>=Eps*(fabs(matrica[i][n-1])+fabs(matrica[i+1][0])) ){cirkularna=0;break;}
		}
	}
	}

	if((teplicova==1) && (cirkularna==0))printf("Matrica je Teplicova\n");

	else if((cirkularna==1) && (teplicova==1))printf("Matrica je cirkularna");
	
	else if((teplicova==0) && (cirkularna==0))printf("Matrica nije ni cirkularna ni Teplicova");

	return 0;
}
