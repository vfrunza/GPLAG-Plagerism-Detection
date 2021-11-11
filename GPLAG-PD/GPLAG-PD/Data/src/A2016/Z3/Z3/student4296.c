#include <stdio.h>
#include <math.h>
#define epsilon 0.0000000001
#define DUZINA 200
int main(){
    int i,j,duzina,k,l,g,ista,M,N;
    double mat[DUZINA][DUZINA]={{0}};
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d",&M,&N);
        if(M<1 || N<1 || M>200 || N>200)
            printf("Brojevi nisu u trazenom opsegu.\n");
    }while(M<1 || N<1 || M>200 || N>200);
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
            scanf("%lf",&mat[i][j]);
    /*Izbacivanje istih redova*/
    duzina=M; 
    for(i=0; i<M-1; i++){
        for(j=1; j<duzina; j++){
            if(fabs(mat[i][0]-mat[i+j][0])<epsilon){
                ista=1;
                for(k=0; k<N; k++)
                    if(fabs(mat[i][k]-mat[i+j][k])>epsilon)
                        ista=0;
                if(ista==1){
                    if((i+j)==(M-1))
                        M--;
                    else{
                        for(l=(i+j); l<M-1; l++)
                            for(g=0; g<N; g++)
                                mat[l][g]=mat[l+1][g];
                        M--;
                    }
                }
            }
        }   
        duzina--;
    }
    /*Izbacivanje istih kolona*/
    duzina=N;
    for(i=0; i<N-1; i++){
        for(j=1; j<duzina; j++){
            if(fabs(mat[0][i]-mat[0][i+j])<epsilon){
                ista=1;
                for(k=0; k<M; k++)
                    if(fabs(mat[k][i]-mat[k][i+j])>epsilon)
                        ista=0;
                if(ista==1){
                    if((i+j)==(N-1)){
                        N--;
                        i--;
                    }
                    else{
                        for(l=(i+j); l<N-1; l++)
                            for(g=0; g<M; g++)
                                mat[g][l]=mat[g][l+1];
                        j--;
                        N--;
                    }
                }
            }
        }   
        duzina--;
    }
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0; i<M; i++){
        for(j=0; j<N;j++)
            printf("% 5g",mat[i][j]);
        printf("\n");
    }
    return 0;
}