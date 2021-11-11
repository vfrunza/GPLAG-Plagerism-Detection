#include <stdio.h>

int main() {
    int m, n, A[100][100], B[100][100], C[100][100], i, j, A1[1000], B1[1000], C1[1000], x;
    
    do {
        printf ("Unesite brojeve M i N: ");
        scanf ("%d %d", &m, &n);
    } while (m<0 || n<0 || m>100 || n>100);
    
    
    printf ("Unesite clanove matrice A: ");
    for (i=0; i<=m-1; i++){
        for (j=0; j<=n-1; j++){
            scanf ("%d", &A[i][j]);
            
            A1[n*i+j] = A[i][j];
            
        }
    }
    
    
    printf ("Unesite clanove matrice B: ");
    for (i=0; i<=m-1; i++){
        for (j=0; j<=n-1; j++){
            scanf ("%d", &B[i][j]);
            
            B1[n*i+j] = B[i][j];
            
        }
    }
    
    
    printf ("Unesite clanove matrice C: ");
    for (i=0; i<=m-1; i++){
        for (j=0; j<=n-1; j++){
            scanf ("%d", &C[i][j]);
            
           C1[n*i+j] = C[i][j];
           
        }
    }
    
    
    for (i=0; i<=m*n-1-1; i++){
        for (j=i+1; j<=m*n-1; j++){
            
            if (A1[i] > A1[j]){
                x = A1[i];
                A1[i] = A1[j];
                A1[j] = x;
            }
            
            if (B1[i] > B1[j]){
                x = B1[i];
                B1[i] = B1[j];
                B1[j] = x;
            }
            
            if (C1[i] > C1[j]){
                x = C1[i];
                C1[i] = C1[j];
                C1[j] = x;
            }
            
        }
    }
    
    
    for (i=0; i<=m*n-1; i++){
        if (A1[i] != B1[i]  ||  A1[i] != C1[i]){
            printf ("NE\n");
            
            return 1;
        }
    }
    
    printf ("DA");
    
    
	return 0;
}
