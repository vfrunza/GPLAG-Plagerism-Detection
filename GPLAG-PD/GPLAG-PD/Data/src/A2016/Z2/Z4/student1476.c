#include <stdio.h>
int main(){
	int i,j,M,N,cirkularna,teplicova;
	double mat[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d",&M);
		scanf("%d", &N);
	if(M<=0 || M>100 || N<=0 || N>100)
	printf("Pogresan unos!\n");
	} while(M<=0 || M>100 || N<=0 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++){
	  for(j=0;j<N;j++){
	  scanf("%lf", &mat[i][j]);
	 	}
	 }
	 teplicova=1;
	for(i=1;i<M;i++){
	  for(j=1;j<N;j++){
	  if(mat[i][j]!=mat[i-1][j-1]) teplicova=0;
      }
      	for(i=1;i<M;i++){
      	for(j=1;j<N;j++)
	  if (mat[i][0]!=mat[0][N-1]) 
	  cirkularna=0;
      }
      }
      if(teplicova==0) printf("Matrica je Teplicova.");
      else if (cirkularna==0 && teplicova==1) printf("Matrica je cirkularna");
      else printf("Matrica nije ni cirkularna ni teplicova");
	
      return 0;
}