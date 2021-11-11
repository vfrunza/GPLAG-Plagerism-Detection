#include <stdio.h>
#include <math.h>
#define A 0.000001

int main() {
	int m,n,i,j,tep=0,cirk=0;
	double matrica[100][100]={{0}};
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m>100 || m<1 || n>100 || n<1)
	printf("Pogresan unos!\n");
	} while(m>100 || m<1 || n>100 || n<1);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%lf",&matrica[i][j]);
		}
	}
	
	for(i=0; i<m-1; i++){
		for(j=0; j<n-1; j++){
			if(fabs(matrica[i][j]-matrica[i+1][j+1])<A)
			tep++;
		}
	}
	
	for(i=0; i<m; i++){
			if(fabs(matrica[i][n-1]-matrica[i+1][0])<A)
			cirk++;
		}
	
	if(m==1){
		printf("Matrica je cirkularna");
		return 0;
	}
	if(n==1){
		printf("Matrica je Teplicova");
		return 0;
	}
	
    if(cirk+tep==n*(m-1))
		printf("Matrica je cirkularna");
	else if(tep==(n-1)*(m-1))
		printf("Matrica je Teplicova");
	else
		printf("Matrica nije ni cirkularna ni Teplicova");
		
	return 0;
}
