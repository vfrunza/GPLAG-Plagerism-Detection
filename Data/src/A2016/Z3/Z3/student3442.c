#include <stdio.h>

int provjeri(int* A, int* B, int vel) {
    int i, prov=0;
    
    for(i=0; i<vel; i++) {
        if(A[i]!=B[i]) {
            prov = 1;
        }
    }
    
    if(prov==0) {
        return 1;
    }
    else return 0;
}

int main() {
    
    int i, j, k, l, p, q, t, m, n, provjera_elemenata=0;
    int A[300][300] = {0}, red_A[200] = {0}, red_B[200] = {0}, kolona_A[200] = {0}, kolona_B[200] = {0};
    
    do {
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &m, &n);
        
        if(m<=0 || m>200 || n<=0 || n>200) {
            printf("Brojevi nisu u trazenom opsegu.\n");
            continue;
        }
        else break;
    }while(1);
    
    printf("Unesite elemente matrice: ");
    
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            if(A[0][0]==A[i][j]) {
                provjera_elemenata++;
            }
        }
    }
    
    if(provjera_elemenata == m*n){
        printf("Nakon izbacivanja redova/kolona matrica glasi:");
        return 0;
    }
   
    for(i=0; i<m; i++) { 
        for(j=0; j<n; j++) {
            red_A[j] = A[i][j];
        }
        for(t=0; t<m; t++) {
            for(j=i+1; j<m; j++) {
                for(k=0; k<n; k++) {
                    red_B[k] = A[j][k];
                }
            
                if(provjeri(red_A,red_B,m)) {
                    for(l=0; l<m; l++) {
                        if(l==j) {
                            for(p=j; p<m; p++) {
                                for(q=0; q<n; q++) {
                                    A[p][q] = A[p+1][q];
                                }
                            }
                            m--;
                        }
                    }
                    t--;
                }
            }
        }
    } 
    
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            kolona_A[j] = A[j][i];
        }
        for(t=0; t<n; t++) {
            for(j=i+1; j<n; j++) {
                for(k=0; k<m; k++) {
                    kolona_B[k] = A[k][j];
                }
        
                if(provjeri(kolona_A,kolona_B,n)) {
                    for(l=0; l<n; l++) {
                        if(l==j) {
                            for(p=0; p<m; p++) {
                                for(q=j; q<n; q++) {
                                    A[p][q] = A[p][q+1];
                                }
                            }
                            n--;
                        }
                    }
                    t--;
                }
            }
        }
    }     
   
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}