#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.00001
int main() {
	
	double mat[100][100];
	int i,j,cir=1,tep=1,m,n;
	
	do {
		
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	
	if (m<=0 || m>100 || n<=0 || n>100)
	printf("Pogresan unos!\n");
	
	}while(m<=0 || n<=0 || m>100 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&mat[i][j]);
		}
	}
	for(i=0;i<m-1 ;i++){
		if(tep==0){
		break;}
		for(j=0;j<n-1;j++){
			if(fabs(mat[i][j]-mat[i+1][j+1])>EPSILON){
			tep=0;
			cir=0;
		
			}
		}
	}
	if (tep==1){
		for(i=1;i<m;i++){
		if(cir==0)
		break;
		if (fabs(mat[i][0]-mat[i-1][n-1])>EPSILON)
		cir=0;
	}
	}
	if(cir==1)
	printf("Matrica je cirkularna");
	else if (cir==0 && tep==1)
	printf("Matrica je Teplicova");
	else
	printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
