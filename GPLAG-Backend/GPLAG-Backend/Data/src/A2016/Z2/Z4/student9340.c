#include <stdio.h>
#define broj 100
int main() {
    int matrica[broj][broj]={{0,0}},i,j,M,N;
    int teplicova=1,cirkularna=1;
    do {
        printf("Unesite M i N: ");
        scanf("%d %d",&M,&N);
        if(M<=0 || M>100 || N<=0 || N>100){
            printf("Pogresan unos!\n");
        }
    }while(M<=0 || M>100 || N<=0 || N>100);

            printf("Unesite elemente matrice: ");
            for(i=0;i<M;i++){
                for(j=0;j<N;j++){
                    scanf("%d",&matrica[i][j]);
                }
            }
            
            for(i=0;i<M;i++){
                for(j=0;j<N;j++){
                    if(matrica[i][j]!=matrica[i+1][j+1]){
                    teplicova=0;
                }
                else {
                    if(matrica[i][N-1]!=matrica[i+1][0] && matrica[i][j]!=matrica[i+1][j+1] && j<N-1){
                        cirkularna=0;
                        i=M;
                        j=N;
                    }
                }
            }
        }
    
if(cirkularna==1 && teplicova==0){
    printf("Matrica je cirkularna");
    return 0;
}
else {
 if(cirkularna==0 && teplicova==1){
printf("Matrica je Teplicova");
return 0;
}
}

        if(cirkularna==1 && teplicova==1){
            printf("Matrica je cirkularna");
         return 0;
        }
        else {
             if(cirkularna==0 && teplicova==0){
                 printf("Matrica nije ni Teplicova ni cirkularna");
             }
        }
    
    return 0;
}