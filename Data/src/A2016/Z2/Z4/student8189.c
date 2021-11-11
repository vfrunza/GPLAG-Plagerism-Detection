#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
#define A 100
#define B 100
int main() {
    int M,N,i,j,a,b;
    int pret=2;
    double mat[A][B];
    
     do
   {   
       
       printf("Unesite M i N: ");
        scanf("%d %d",&M,&N);
        if(M<=0 || M>100 || N<=0 || N>100) 
        printf("Pogresan unos!\n");
    
}
    while((M<=0 || M>100) ||( N<=0 || N>100));
    printf("Unesite elemente matrice: ");
    for(i=0;i<M;i++)
        { for(j=0;j<N;j++)
                {  scanf("%lf",&mat[i][j]); } 
        }
        
        if(N==1 && M!=1) {  printf("Matrica je Teplicova"); return 0; }
         
    
    for(a=0;a<M-1;a++)
    { for(b=0;b<N-1;b++)
        {
         if(fabs(mat[a][b]-mat[a+1][b+1])>EPSILON)
       { pret=0; break; }
    
         if(fabs (mat[a][N-1]-mat[a+1][0]) >EPSILON)
        { pret=1; break; 
        }
        
        }
    } 
        if(pret==2)  printf("Matrica je cirkularna "); 
        else if(pret==1)  printf("Matrica je Teplicova "); 
       else  if(pret==0)  printf("Matrica nije ni cirkularna ni Teplicova "); 
	return 0;
}
