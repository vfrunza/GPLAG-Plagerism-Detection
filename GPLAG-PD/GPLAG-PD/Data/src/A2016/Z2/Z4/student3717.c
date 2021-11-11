#include <stdio.h>

int main() {
int M,N,i,j,niz[100][100]={{0}},t=1,c=1;
printf("Unesite M i N: ");
scanf("%d %d",&M,&N);
	do{
		if(M<=0 || M>100 || N<=0 || N>100){
			printf("Pogresan unos!\n");
			printf("Unesite M i N: ");
			scanf("%d %d",&M,&N);
		}
	}while(M<0 || M>100 || N<0 || N>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d",&niz[i][j]);
		}
	}
	
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
				if(niz[i][j]!=niz[i+1][j+1]){
					t=0;
					break;
				}
			}
			if(t==0){
				break;
			}
	}
	
	for (i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
				if(niz[i][N-1]!=niz[i+1][0]){
					c=0;
					break;
				}
		}
		if(c==0){
			break;
		}
	}
	
			if(t==1 && c==0 || N==1 && M!=1){
	        	printf("Matrica je Teplicova");
				}else if(t==1 && c==1 || M==1){
					printf("Matrica je cirkularna");
				}else{
					printf("Matrica nije ni cirkularna ni Teplicova");
				}
	
	return 0;
}
