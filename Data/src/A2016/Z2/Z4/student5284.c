#include <stdio.h>
 
int main() {
    int M,N;
    int da=0,i,j;
    double  mat[100][100];
    do{
        if(da==1) printf("Pogresan unos!\n");
        da=0;
    printf("Unesite M i N: ");
    scanf("%d %d",&M,&N);
    da=1;
    }while(M<1 || M>100 || N<1 || N>100);
   
    printf("Unesite elemente matrice: ");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%lf",&mat[i][j]);
        }
    }
    int cirkularna=1;
 
 
    for(i=0;i<M-1;i++){
        for(j=0;j<N-1;j++){
            if(mat[i][N-1]!=mat[i+1][0]) {
                cirkularna=0; 
                break;
                }
               if(mat[i][j]!=mat[i+1][j+1]) cirkularna=0;
        }
    }
    int teplicova=1;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if(i==M-1 || j==N-1) continue;
             if(mat[i][j]!=mat[i+1][j+1] ) teplicova=0;
        }
    }
     if (teplicova==1 && cirkularna==0) printf("Matrica je Teplicova");
      else if (cirkularna==1) printf("Matrica je cirkularna");
   
    else printf("Matrica nije ni cirkularna ni Teplicova\n");
   
    return 0;
}