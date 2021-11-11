#include <stdio.h>

int main() {
    int i, j, M, N, br, br_prim;
    double mat[100][100];
    double suma[100]={0};
    
    do{
    printf("Unesite M i N: ");
    scanf("%d %d", &M, &N);
    if(M>100 || N>100 || M<=0 || N<=0) printf("Pogresan unos!\n");
    }while(M>100 || N>100 || M<=0 || N<=0);
    
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
        suma[i]+=mat[i][j];
        }
    }
    br=1;
    for(i=1; i<M; i++) {
        if(suma[i]!=suma[i-1]) br--;
    }
    br_prim=1;
    for(i=1; i<M; i++) {
        for(j=1; j<N; j++) {
            if(mat[i-1][j-1]!=mat[i][j]) br_prim--;
        }
    }
            if(br==1) {printf("Matrica je cirkularna");}
            else if(br_prim==1) {printf("Matrica je Teplicova");}
            else {printf("Matrica nije ni cirkularna ni Teplicova");}
        
       
    
	
	return 0;
}
