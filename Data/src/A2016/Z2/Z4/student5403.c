#include <stdio.h>

int main() {

  int i,j,teplicova=1,cirkularna=1,M,N;
  double matrica[100][100];

  do{
  	printf("Unesite M i N: ");
  	scanf("%d %d", &M, &N);
  	if(M>100 || N>100 || M<=0 || N<=0)
  	 printf("Pogresan unos!\n");
  }
   while(M>100 || N>100 || M<=0 || N<=0);
   
   printf("Unesite elemente matrice: ");
   
   for(i=0;i<M;i++){
       for(j=0;j<N;j++){
           scanf("%lf", &matrica[i][j]);
       }
   }
  
  for(i=0;i<M-1;i++){
   
     for(j=0;j<N-1;j++){
         if(matrica[i+1][j+1]!=matrica[i][j]){
             teplicova=0;
             cirkularna=0;
             
         }
         
        else if(matrica[i][N-1]!=matrica[i+1][0]){
          cirkularna=0;
          }
     }
  }

   if(N==1 && M!=1)
    printf("Matrica je Teplicova");
   else if(teplicova==0 && cirkularna==0)
    printf("Matrica nije ni cirkularna ni Teplicova");
   else if(cirkularna==0)
    printf("Matrica je Teplicova");
   else
    printf("Matrica je cirkularna");

	return 0;
}
