#include <stdio.h>
#include <math.h>
int main() {
	int m,n,i,j;
	int teplic = 1;
	int cirk = 1;
	float mat[100][100];
	
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	
	if(m<=0 || m>100 || n<=0 || n>100){
		do{
			printf("Pogresan unos!\n");
			printf("Unesite M i N: ");
			scanf("%d %d",&m,&n);
		}while(m<=0 || m>100 || n<=0 || n>100);
	}
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%f",&mat[i][j]);
		}
	}
	if(m>1 && n==1){
		printf("Matrica je Teplicova");
		return 0;
	}
	
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(0.000000001 < fabs(mat[i][j] - mat[i+1][j+1]) || m==2 && n==2){
				printf("Matrica nije ni cirkularna ni Teplicova");
				return 0;
			}
		}
		if(0.000000001 < fabs(mat[i][n-1] - mat[i+1][0])){
				cirk = 0;
		}
	}
	if(cirk == 1){
		printf("Matrica je cirkularna");
		return 0;
	}
	else{
		printf("Matrica je Teplicova");
		return 0;
	}
	return 0;
}
