#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define DUZINA 100
#define SIRINA 100
int main() {
	/*printf("Zadaća 2, Zadatak 4");*/
	
	int M,N,i,j,k,l,h=2;
	
	double mat[DUZINA][SIRINA];
	
	printf("Unesite M i N: ");
	
	do{
		scanf("%d %d", &M, &N);
		
		if((M<=0 || M>100) || (N<=0 || N>100)){
			printf("Pogresan unos!\n");
			printf("Unesite M i N: ");
			continue;
		}
	}
	
	while((M<=0 || M>100) || (N<=0 || N>100));
	

	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	
	if(N==1 && M!=1){
		printf("Matrica je Teplicova");
		return 0;
	}
	
	for(k=0; k<M-1; k++)
	{
		for(l=0; l<N-1; l++){
			if(fabs(mat[k][l]-mat[k+1][l+1])>EPSILON) {
				h=0; 
				break;
			}
			if( fabs (mat[k][N-1]-mat[k+1][0])>EPSILON  ) {
				h=1; 
				break;
			}
			
		}
	}
	
	if(h==2) printf("Matrica je cirkularna");
	else if(h==1) printf("Matrica je Teplicova");
	else if(h==0) printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
