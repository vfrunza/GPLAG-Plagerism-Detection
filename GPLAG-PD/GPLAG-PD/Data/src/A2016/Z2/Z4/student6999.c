#include <stdio.h>
 int main(){
    int M,N,tep=1,cir=1,i,j;
    double mat[100][100],suma[100]={0};
  
    do{
        printf("Unesite M i N: "); 
        scanf("%d %d",&M,&N);
         if(M>100||M<1||N>100||N<1) printf("Pogresan unos!\n");
    }while(M>100||M<1||N>100||N<1);
  
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%lf", &mat[i][j]);
        }
    }
  
    for(i=0; i<M-1; i++){
        for(j=0; j<N-1; j++){
            if(mat[i][j]!=mat[i+1][j+1]) {tep=0;}
        }
    }
 
    if(tep==1){
        for(i=0; i<M; i++){
            for(j=0; j<N; j++){
                suma[i]+=mat[i][j];
            }
        }
        for(i=0; i<M-1; i++){
            if(suma[i]!=suma[i+1]) {cir=0;}
        }
    }else{
        cir=0;
    }

    if(tep==1 && cir==0){
        printf("Matrica je Teplicova");
    }else if(cir==1){
        printf("Matrica je cirkularna");
    }else if(tep==0 && cir==0){
        printf("Matrica nije ni cirkularna ni Teplicova");
    }
	return 0;
}