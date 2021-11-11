#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Eps 0.000001
int main() {
	int m,n,i,j,t=0,c=0;
	double matrix[100][100];
	printf("Unesite M i N: ");
	do{
		scanf("%d %d",&m,&n);
		if(m<1 || m>100 || n<1 || n>100) printf("Pogresan unos!\nUnesite M i N: ");
		else if(m>0 || m<=100 || n>0 || n<=100) break;
	}while(1);
	printf("Unesite elemente matrice: ");
	if(m==1){
		printf("Matrica je cirkularna");
		return 0;
	}
	if(n==1){
		printf("Matrica je Teplicova");
		return 0;
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&matrix[i][j]);
		}
	}
	for(i=1;i<m;i++){
		if(fabs(matrix[i][0]-matrix[i-1][j-1])>Eps) c=1;
		for(j=1;j<n;j++){
				if(fabs(matrix[i][j]-matrix[i-1][j-1])>Eps) c=1;
		
		}
	}
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
		if(fabs(matrix[i][j]-matrix[i+1][j+1])>Eps) t=0;
		else t=1;
		
		if(m>1 && n>1 && n-m<=1 && fabs(matrix[m-2][0]-matrix[0][n-2])>Eps) t=0;
		}
	}
	
	if(c==0){
		printf("Matrica je cirkularna");
	}
	else if(t==1){
		printf("Matrica je Teplicova");
	}
	else{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	
	return 0;
}
