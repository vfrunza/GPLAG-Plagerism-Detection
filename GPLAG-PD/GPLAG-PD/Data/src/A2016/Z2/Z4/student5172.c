#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001
#define BROJ_REDOVA 100
#define BROJ_KOLONA 100

int main() {
    
    int M,N,i,j;
    
    do{
        printf("Unesite M i N: ");
        scanf("%d %d",&M,&N);
        if(M<=0 || M>100 || N<=0 || N>100)
        printf("Pogresan unos!\n");
    }
    while(M<=0 || M>100 || N<=0 || N>100);
    
    double A[BROJ_REDOVA][BROJ_KOLONA];
    
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%lf",&A[i][j]);
        }
    }
    
    if(N==1)
    {
        if(M==1){
        printf("Matrica je cirkularna");
        return 0;
    }
       else{
           printf("Matrica je Teplicova");
           return 0;
       }
    }
    
    for(i=1; i<M; i++){
        for(j=1; j<N; j++){
                if(fabs(A[i][j]-A[i-1][j-1])>EPSILON){
                        printf("Matrica nije ni cirkularna ni Teplicova");
                        return 0;
                }
            }
        }
    
    for(i=0; i<M-1; i++){
       
                if(fabs(A[i][N-1]-A[i+1][0])>EPSILON){
                    printf("Matrica je Teplicova");
                    return 0;
                }
    }    
    printf("Matrica je cirkularna");
    
    
    return 0;
}