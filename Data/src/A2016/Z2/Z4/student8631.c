#include <stdio.h>
#define vel 100
int main() 
{int M, N, i, j, ppt, cikul;
double mat[vel][vel];
do 
{ printf("Unesite M i N: ");
scanf("%d%d", &M, &N); 
if(M<=0 || N<=0||M>vel|| N>vel) printf("Pogresan unos! \n"); }
while (M<=0 || N<=0|| M>vel|| N>vel);
printf("Unesite elemente matrice: ");
      for (i=0; i<M; i++)
    {for (j=0; j<N; j++)
        {scanf("%lf", &mat[i][j]);}}
 ppt=1; 
 for (i=0; i<M-1; i++)
    {for (j=0; j<N-1; j++)
     { if(mat[i][j]!=mat[i+1][j+1]) 
     {ppt=0; }}}
    cikul=1; 
    if(ppt==0) printf("Matrica nije ni cirkularna ni Teplicova"); else {
      for(i=0; i<M-1; i++)
      {if(mat[i+1][0]!= mat[i][N-1])
      cikul=0;   }
  if(cikul==0) printf("Matrica je Teplicova");
   else  printf("Matrica je cirkularna");}
   return 0; }