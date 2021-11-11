#include <stdio.h>
#define VISINA 100
#define SIRINA 100

int main() {
	int i,j,M,N,brojac=0,brojac1=0;
	unsigned int suma=0;
	double mat[VISINA][SIRINA];
	do{
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if(M>100 || M<1 || N>100 || N<1){
	printf("Pogresan unos!\n");
	}

	}while(M>100 || M<1 || N>100 || N<1);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf", &mat[i][j]);
		}
		
	}
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			if(i==0)
			suma+=mat[i][j];
			suma=(int) suma;
		}
	}
	
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			if(i==i) brojac+=mat[i][j];
			else if (brojac!=suma) break;
			
		}
	}
	
	for(i=M-1; i>0; i--){
		for(j=N-1; j>0; j--){
         if(mat[i][j]!=mat[i-1][j-1]) brojac1++;
			}
		}

 if(brojac==M*suma) printf("Matrica je cirkularna");
    else if(brojac1!=0) printf("Matrica nije ni cirkularna ni Teplicova");
    else printf("Matrica je Teplicova");
	return 0;
}
