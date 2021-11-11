#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define visina 100
#define sirina 100
#define eps 0.000001

int main() {
	int i=0,M=0,N=0,j=0;
	double ubi[visina][sirina];
	int tp=1,ck=1;

	do{
		printf("Unesite M i N: ");
		scanf("%d%d",&M,&N);
		if(M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\n");
	}while(M<=0 || M>100 || N<=0 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&ubi[i][j]);
		}
	}
	ck=1;
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
	 		if(fabs(ubi[i][j] - ubi[i+1][j+1])>eps || fabs(ubi[i][N-1] - ubi[i+1][0])>eps){
	 			ck=0;
	 			break;
	 		}
	 	}
	 	if(ck==0)
	 		break;
	 }
	 if(N==1 && M != 1)
	 	ck=0;
	 if(ck){
	 	printf("Matrica je cirkularna");
	 	return 0;
	 } 

	
	tp=1;
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
		if(fabs(ubi[i][j] - ubi[i+1][j+1])>eps)
			tp=0;
		}
	}
	 if(tp){
	 printf("Matrica je Teplicova"); 
	 return 0;
	 }
	
	  printf("Matrica nije ni cirkularna ni Teplicova");
	 
		
	return 0;

	
		
	}
		