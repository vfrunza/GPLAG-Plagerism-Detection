#include <stdio.h>
#define duz 200

int main() {
    int mat[duz][duz];
    int i=0, j, k, m, n, ok, s; 
    
   do{
        printf("Unesite brojeve M i N: ");
        scanf("%d", &m);
        scanf("%d", &n);
        if(m<1 || m>200 || n<1 || n>200){
            printf("Brojevi nisu u trazenom opsegu.\n");
        }
    } while(m<1 || m>200 || n<1 || n>200);

    
    printf("Unesite elemente matrice: ");
    for(j=0; j<m; j++){
        for(k=0; k<n; k++){
            scanf("%d", &mat[j][k]);
        }
    }
    
    for(j=0; j<m-1; j++){
        for(k=j+1; k<m; k++){
            ok=0;
            for(i=0; i<n; i++){
                if(mat[j][i] != mat[k][i]){
                break;
                }
                else if(mat[j][i] == mat[k][i]){
                    ok++;
                }
            }
            if(ok==n){
                for(s=k; s<m-1; s++){
                    for(i=0; i<n; i++){
                        mat[s][i]=mat[s+1][i];
                    }
                }
                k--;
                m--;
            }
        }
    }
    
    for(j=0; j<n-1; j++){
        for(k=j+1; k<n; k++){
            ok=0;
            for(i=0; i<m; i++){
                if(mat[i][j] != mat[i][k]){
                    break;
                }
                else if(mat[i][j] == mat[i][k]){
                    ok++;
                    }
                }
            if(ok==m){
                for(i=0; i<m; i++){
                    for(s=k; s<n-1; s++ ){
                        mat[i][s]=mat[i][s+1];
                    }
                }
                k--;
                n--;
            }
        }
    }
    
    
    
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(j=0; j<m; j++){
        for(k=0; k<n; k++){
            printf("%5d", mat[j][k]);
        }
        printf("\n");
    }
	
	return 0;
}
