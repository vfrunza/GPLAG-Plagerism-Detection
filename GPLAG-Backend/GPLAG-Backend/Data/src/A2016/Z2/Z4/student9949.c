#include <stdio.h>
#include <math.h>
#define e 0.001
#define MAX 100
int main() {
	int M,N,i,j,C=1,T=0,k=1,k1=0;
	double mat[100][100];
	do
	  { printf("Unesite M i N: ");
	    scanf("%d %d",&M,&N);
	    if(M>100 || N>100 || M<=0 || N<=0){
	    printf("Pogresan unos!\n");}
	  } while (M>100 || N>100 || M<=0 || N<=0);
	  
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
	   for(j=0; j<N; j++){
	   scanf("%lf", &mat[i][j]);
	}   }
	
	for(i=1; i<M; i++){
		for(j=1; j<N; j++){
         if(fabs(mat[i][j]-mat[i-k][j-k])>e || fabs(mat[i][k1]-mat[k1][N-i])>e)
         C=0;
         if(fabs(mat[i][j]-mat[i-k][j-k])<e)
	     T=1;
	     if(fabs(mat[i][j]-mat[i-k][j-k])>e) {
	     T=0; break; } 
	   }}

    if(M==1 && N==1){
    printf("Matrica je cirkularna");
    } else
    if(N==1){
   	printf("Matrica je Teplicova");
    } else
	if(T==0 && C==0){
	    printf("Matrica nije ni cirkularna ni Teplicova\n");
	} else
	if(C==1){
	    printf("Matrica je cirkularna\n");
	} else
	if(T==1 && C==0){
		printf("Matrica je Teplicova\n");
	}
    return 0;
}
	