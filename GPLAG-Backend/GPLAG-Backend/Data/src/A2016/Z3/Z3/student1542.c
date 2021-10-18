#include <stdio.h>

int main (){
    int M,N,i,j,k,mat[200][200],t,f;
    int isti_redovi=0,iste_kolone=0;
    
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d", &M);
        scanf("%d", &N);
        if(M>=200 || N>=200 || M<1 || N<1) printf("Brojevi nisu u trazenom opsegu.\n");
    }while(M>=200 || N>=200 || M<1 || N<1);
    
    printf("Unesite elemente matrice: ");
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    
    for(i=0; i<M; i++){
        for(j=i+1; j<M; j++){
            for(k=0; k<N; k++){
                if(mat[j][k]!=mat[i][k])
                isti_redovi=1;
            }
        
        if(isti_redovi==0){
            for(t=j; t<M; t++)
            for(f=0; f<N; f++)
            mat[t][f]=mat[t+1][f];
            M--;
            j--;
        }
        isti_redovi=0;
        }
    }
        
        for(i=0; i<N; i++){
            for(j=i+1; j<N; j++){
                for(k=0; k<M; k++){
                    if(mat[k][j]!=mat[k][i])
                    iste_kolone=1;
                }
        
                if(iste_kolone==0){
                    for(t=j; t<N; t++)
                    for(f=0; f<M; f++)
                    mat[f][t]=mat[f][t+1];
                    N--;
                    j--;
                }
                iste_kolone=0;
            }
        }
            
            printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
            for(i=0; i<M; i++){
                for(j=0; j<N; j++){
                    printf("%5d",mat[i][j]);
                }
                printf("\n");
            } 
    return 0;
}