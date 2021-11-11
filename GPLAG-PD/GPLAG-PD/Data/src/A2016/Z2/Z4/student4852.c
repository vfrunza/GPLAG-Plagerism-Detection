#include <stdio.h>
#include <math.h>
int main() {
    int M,N,i,j,tm=1,cm=1;
    double mat[100][100];
    do{
        printf("Unesite M i N: ");
        scanf("%d %d",&M,&N);
        if(M>100||M<=0||N>100||N<=0)
        printf("Pogresan unos!\n");}
        while(M>100||M<=0||N>100||N<=0);
        printf("Unesite elemente matrice: ");
        for(i=0;i<M;i++){
            for(j=0;j<N;j++){
                scanf("%lf", &mat[i][j]);
            }
        }
        
        for(i=0;i<M-1;i++){
            for(j=0;j<N-1;j++){
               if(mat[i][j]!=mat[i+1][j+1])
               tm=0;
            }}
             for(i=0;i<M-1;i++){
               if(mat[i][N-1]!=mat[i+1][0])
               cm=0;}
               
            
            if(tm==1&&cm==1)
            printf("Matrica je cirkularna");
            else if(tm==1)
            printf("Matrica je Teplicova");
            else 
            printf("Matrica nije ni cirkularna ni Teplicova");
        
        
        
        

	return 0;
}
