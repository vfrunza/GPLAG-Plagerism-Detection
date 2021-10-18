#include <stdio.h>

int main() {
   
   double matrica[100][100];
   int M,N;
   unos:
   printf("Unesite M i N: ");
   scanf("%d %d",&M,&N);
   if(M>100 || N>100 || M<=0 ||N<=0){
   	printf("Pogresan unos!\n");
   	goto unos;
   	}
   	int i,j;
   	printf("Unesite elemente matrice: ");
   	for(i=0;i<M;i++){
   		for(j=0;j<N;j++){
   			scanf("%lf",&matrica[i][j]);
   		}
   	}
   	int t=0, c=0;
   	for(i=0;i<M-1;i++){
   		for(j=0;j<N-1;j++){
   			if(matrica[i][j]!=matrica[i+1][j+1])
   			t=1;
   		}
   		}
   		for(i=0;i<M;i++){
   		for(j=0;j<N;j++){
   			if(i-1<0)continue;
   			if(matrica[i-1][N-1]!=matrica[i][0])
   			c=1;
   			
   		}
   		
   	}
if(c==0 && t==0)printf("Matrica je cirkularna");
else if(c==1 && t==0)printf("Matrica je Teplicova");
else printf("Matrica nije ni cirkularna ni Teplicova");



	return 0;
}
