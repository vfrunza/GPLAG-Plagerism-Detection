#include <stdio.h>

int main() {
    int M,N,mat[100][100],i,j;
   
    do{
        printf("Unesite M i N: ");
        scanf("%d %d",&M,&N);
        if( M>100 || N>100 || M<=0 || N<=0)
        
            printf("Pogresan unos!\n");
        
    }while (M>100 || N>100 || M<=0 || N<=0 );
   
        printf("Unesite elemente matrice:");
        for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            
         scanf("%f", &mat[i][j]);
        }}
     int teplicova_mat=1;
        for(i=0;i<M-1;i++){
        for(j=0;j<N-1;j++){
        if( mat[i][j]!=mat[i+1][j+1]){
        teplicova_mat=0;
        }
        
        }
            }
       int cirkularna_mat=1;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if( mat[0][j] != mat[i][(i+j)%N]){
            cirkularna_mat=0;
            }    
        }
        
    }
        if(cirkularna_mat && teplicova_mat){
            printf(" Matrica je cirkularna");
          
        }else if(teplicova_mat){
        printf(" Matrica je Teplicova");
        
        }else{
            printf(" Matrica nije ni cirkularna ni Teplicova");
        }
       
       
       
        return 0;
}
