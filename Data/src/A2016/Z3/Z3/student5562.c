#include <stdio.h>


int main(){
    
    int mat[300][300];
    int M, N, i, j, k, l , m;
    
    /*Unos dimenzija*/
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
        
        if (M < 1 || M > 200 || N < 1 || N > 200)
            printf("Brojevi nisu u trazenom opsegu.\n");
        
    } while (M < 1 || M > 200 || N < 1 || N > 200);
    
    /*Unos elemenata*/
    printf("Unesite elemente matrice: ");
    
    for (i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            scanf("%d", &mat[i][j]);
    
    /*REDOVI*/
    for (i = 0; i < M - 1; i++){ /*Prelistaj redove*/
        
        for (j = i + 1; j < M; j++){ /*Prelistaj redove ispred trenutnog reda*/
            
            if (mat[i][0] == mat[j][0]){
                
                for (k = 0; k < N; k++){ /*Prelistaj clanove redova koje poredimo*/
                    
                    if (mat[i][k] != mat[j][k])
                        break;
                        
                    if (k == N - 1){
                        
                        for (l = j; l < M - 1; l++){
                            
                            for (m = 0; m < N; m++){
                                
                                mat[l][m] = mat[l + 1][m];
                                
                            }
                            
                        }
                       M--;
                       j--; 
                    }
                
                }
                
            }
            
        }
        
    }
    
    
    /*KOLONE*/
    for (i = 0; i < N - 1; i++){ /*Prelistaj kolone*/
        
        for (j = i + 1; j < N; j++){ /*Prelistaj kolone ispred trenutne kolone*/
            
            if (mat[0][i] == mat[0][j]){
                
                for (k = 0; k < M; k++){ /*Prelistaj clanove kolona koje poredimo*/
                    
                    if (mat[k][i] != mat[k][j])
                        break;
                        
                    if (k == M - 1){
                        
                        for (l = j; l < N - 1; l++){
                            
                            for (m = 0; m < M; m++){
                                
                                mat[m][l] = mat[m][l + 1];
                                
                            }
                            
                        }
                        N--;
                        j--;
                    }
                
                }
                
            }
            
        }
        
    }
    
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    
    for (i = 0; i < M; i++){
        for(j = 0; j < N; j++)
            printf("%5d", mat[i][j]);
        printf("\n");
    }
    return 0;
}