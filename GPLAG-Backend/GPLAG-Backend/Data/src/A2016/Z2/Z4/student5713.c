#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
int  M, N, i, j, teplicova=0, cirkularna=0, kraj=0, k, l;
double niz[100][100];
int main() {
	do{
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if(M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\n");
	}while (M<=0 || M>100 || N<=0 || N>100);
	
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
	
		for(j=0; j<N; j++){
			scanf("%lf", &niz[i][j]);
		}
	}
	
	if(M==1) {printf("Matrica je cirkularna"); return 0;}
	if(N==1) {printf("Matrica je Teplicova"); return 0;}
	
	/*ispitivanje da li je cirkularna*/
		
					if(fabs(niz[0][N-1]-niz[1][0])<epsilon){
						
						for(k=0; k<M-1; k++){
							for(l=0; l<N-1; l++){
								if(fabs(niz[k][N-1]- niz[k+1][0])<epsilon){
								if(fabs(niz[k][l]-niz[k+1][l+1])<epsilon) cirkularna=1;
								
								else {cirkularna=0; break; kraj=1;}
									
								}
								else {cirkularna=0; kraj=1;}
							} if(kraj==1) break;
						}
					}
					else cirkularna=0;
		
	
		if(cirkularna==1) {printf("Matrica je cirkularna"); return 0;}
		/*ako je cirkularna onda je i teplicova*/
	
	/*ispitivanje da li je matrica teplikova*/
	for(i=1; i<M; i++){
		for(j=1; j<N; j++){
				if(fabs(niz[i-1][j-1]-niz[i][j])<epsilon) teplicova=1;
							else {teplicova=0; break;}
				
			}if(teplicova==0)break;
	}
	
	if(teplicova==1 && cirkularna !=1) printf("Matrica je Teplicova");
	if(teplicova !=1 && cirkularna !=1 ) printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
