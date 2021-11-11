#include <stdio.h>
#define MAX_SIZE 100
int main() {
	int m, n,i,j,start=1;
	int x=0;
	int circularna =1;
	int treplica =1;
	double matrix[MAX_SIZE][MAX_SIZE];
	//UNOS DIMENZIJA
	do{
	if(start!=1)
	printf("Pogresan unos!\n");
	start=0;
	
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	}while(m<1||m>100||n<0||n>100);
	//unos matrice
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<m;i++){
		for(j=0; j<n; j++){
			scanf("%lf",&matrix[i][j]);
		}
	}
	//test je li cirkularna
	for(i=0; i<m-1;i++){
		for(j=0;j<n;j++){
			if(j!=n-1){
			if(matrix[i][j]!=matrix[i+1][j+1])
			circularna =0;
			
			}
			else{
				if(matrix[i][j]!=matrix[i+1][0])
				circularna =0;
				
			}
		
		}
		
	}
	//test je li teplica
	for(i=0; i<m-1;i++){
		for(j=0; j<n-1;j++){
			if(matrix[i][j] != matrix[i+1][j+1])
			treplica =0;
		}
	}
	
	if(circularna)
	printf("Matrica je cirkularna");
	else if(treplica)
	printf("Matrica je Teplicova");
	else
	printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
