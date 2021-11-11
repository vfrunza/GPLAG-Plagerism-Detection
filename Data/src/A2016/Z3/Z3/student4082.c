#include <stdio.h>
#define M 200 N 200

int main(){
    int a=1;
    int mat[200][200];
    int i,j,k,m,n,l;
    do{
    printf("Unesite brojeve M i N: ");
    scanf("%d %d", &m, &n);
    if(m<1 || m>200 || n>200 || n<1){
    printf("Brojevi nisu u trazenom opsegu.\n");
    continue;
    }
    break;
    }while(1);
    printf("Unesite elemente matrice: ");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    // posamaraj redove
    for(i=0; i<m; i++){
        for(j=i+1; j<m; j++){
            a=1;
            if(mat[i][0] == mat[j][0]){
                for(k=0; k<n; k++){
                    if(mat[i][k] != mat[j][k]){
                        a=0;
                        break;
                    }
                }
                if(a == 1){
                    for(l=j+1; l<m; l++){
                        for(k=0; k<n; k++){
                            mat[l-1][k]=mat[l][k];
                        }
                    }
                    m--;
                    j--;
                }
                
            }
        }
    }
    // kraj samaranja redova
    // posamaraj kolone
    for(j=0; j<n; j++){
        for(i=j+1; i<n; i++){
            a=1;
            if(mat[0][j] == mat[0][i]){
                for(k=0; k<m; k++){
                    if(mat[k][j] != mat[k][i]){
                        a=0;
                        break;
                    }
                }
                if(a == 1){
                    for(l=i+1; l<n; l++){
                        for(k=0; k<m; k++){
                            mat[k][l-1]=mat[k][l];
                        }
                    }
                    n--;
                    i--;
                }
                
            }
        }
    }
    // kraj samaranja kolona
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}