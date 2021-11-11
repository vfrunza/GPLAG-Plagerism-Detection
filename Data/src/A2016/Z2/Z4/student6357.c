#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
int main() {
	int n,m,i=0,j=0,cirkularna=0,teplicova=0;
	double niz[100][100];
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m<1 || m>100 || n<1 || n>100){
		do{printf("Pogresan unos!");
		printf("\nUnesite M i N: ");
		scanf("%d %d",&m,&n);
	}while(m<1 || m>100 || n<1 || n>100);
	}printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&niz[i][j]);
		}}for(i=0;i<=m-2;i++){
			for(j=0;j<=n-2;j++){
					if(fabs(niz[i][j]-niz[i+1][j+1])<EPSILON){teplicova=1;
						if(fabs(niz[i][n-1]-niz[i+1][0])<EPSILON && fabs(niz[i][n-1]-0)>=EPSILON && niz[i][n-1]<10){
							cirkularna=1;teplicova=0;
					}else cirkularna=0;teplicova=1;
					}else{teplicova=0;cirkularna=0;
			}}}
			if(cirkularna==1   || (n==1 && m==1) || m==1) printf("Matrica je cirkularna");
			else if(teplicova==1 && cirkularna==0|| n==1) printf("Matrica je Teplicova");
			else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
