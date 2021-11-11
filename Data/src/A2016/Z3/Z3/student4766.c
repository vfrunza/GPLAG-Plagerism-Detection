#include <stdio.h>

int main(){
    int M, N;
    int start = 1;
    int i, j,k,l; 
    int mat[200][200];
    int isti;
    
    
    do{
        if(!start)
            printf("Brojevi nisu u trazenom opsegu.\n");
        else if(start)
            start = 0;
    
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
        
    }while(M > 200 || M <= 0 || N > 200 || N <= 0);
    
    printf("Unesite elemente matrice: ");
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    //poredjenje redova
    for(i = 0; i < M; i++){
        //prolazak kroz sve iduce redove da bi se testirala jednakost
        for(j = i + 1; j < M; j++){
            isti = 1;
            for(k = 0; k < N; k++){
                if(mat[j][k] != mat[i][k]){
                    isti = 0;
                    break;
                }
            }
            //pomjeranje redove prema "gore" ukoliko je neki red isti
            if(isti){
                for(k = j; k < M - 1; k++ ){
                    for(l = 0; l < N; l++){
                        mat[k][l] = mat[k+1][l];
                    }
                }
                M--;
                j--;
            }  
        }
        
    }
    
    //isto samo za kolone, poredimo kolone
    for(i = 0; i < N; i++){
        //prolazak kroz sve iduce kolone da bi se testirala jednakost
        for(j = i + 1; j < N; j++){
            isti = 1;
            for(k = 0; k < M; k++){
                if(mat[k][j] != mat[k][i]){
                    isti = 0;
                    break;
                }
            }
            //pomjeranje kolona prema "lijevo" ukoliko je neka kolona ista
            if(isti){
                for(k = j; k < N - 1; k++){
                    for(l = 0; l < M; l++){
                        mat[l][k] = mat[l][k+1];
                    }
                }
                N--;
                j--;
            }  
        }
        
    }
    
    printf("Nakon izbacivanja redova/kolona matrica glasi: ");
    for(i = 0; i < M; i++){
        printf("\n");
        for(j = 0; j < N; j++){
            printf("%5d", mat[i][j]);
        }
    }
    return 0;
}