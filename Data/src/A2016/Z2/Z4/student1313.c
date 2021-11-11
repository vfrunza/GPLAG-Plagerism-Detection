#include <stdio.h>
#define duzina 100
#include <math.h>
#define epsilon 0.001
int main() {
	int i,j,M,N,Teplicova=0, Cirkularna=0;
	double Mat[duzina][duzina]={{0}};

	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if (M<=0 || M>100 || N<=0 || N>100){
			printf("Pogresan unos! \n");
		} 
		 else break;
		 } while(1);
	
	printf("Unesite elemente matrice: ");
	 for (i=0;i<M;i++){
	 	for (j=0;j<N;j++){
	 		scanf("%lf",&Mat[i][j]);
	 	}
	 }
	 
	 
	 for (i=0;i<M-1;i++){
	 	for (j=0;j<N-1;j++){
	 		if (fabs(Mat[i][j]-Mat[i+1][j+1])<epsilon)
	 		Teplicova=1;
	 		else { Teplicova=0;break;}
	 	}
	 	if(Teplicova==0) break;
	 }
	 
	 for (i=0;i<M-1;i++){
	 	for (j=0;j<N-1;j++){
	 		if (Teplicova==1 && (fabs(Mat[i][N-1]-Mat[i+1][0])<epsilon))
	 		Cirkularna=1;
	 		else {Cirkularna=0; break;}
	 	}
	 	if (Cirkularna==0) break;
	 }
	 
	 if (Cirkularna==1 || M==1) printf("Matrica je cirkularna");
	 
	 else if (Teplicova==1 || N==1) printf("Matrica je Teplicova");
	 else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
