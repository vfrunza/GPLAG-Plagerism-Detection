#include <stdio.h>

int jednakiSu(int niz1[], int* niz2, int vel){
    int i;
    for(i = 0; i<vel; i++){
        if(niz1[i] != niz2[i])
            return 0;
    }
    return 1;
}

void zamijeniRedove(int niz1[], int niz2[], int vel){
    int i;
    for(i = 0; i<vel; i++){
        int temp = niz1[i];
        niz1[i] = niz2[i];
        niz2[i] = temp;
    }
}

int main ()
{
    int i = 0, j, m = 1, n = 1, k;
    int niz[200][200];
    
    do{
        if(i == 1)
            printf("Brojevi nisu u trazenom opsegu.\n");
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &m, &n);
        i = 1;
    }while(m <= 0 || m > 200 || n <= 0 || n > 200);
    printf("Unesite elemente matrice: ");
    for(i = 0; i<m; i++)
        for(j = 0; j<n; j++)
            scanf("%d", &niz[i][j]);
    
    for(i = 0; i<m; i++){
        for(j = i + 1; j<m; j++){
            if(jednakiSu(niz[i], niz[j], n) == 1){
                for(k = j + 1; k<m; k++){
                    zamijeniRedove(niz[k-1], niz[k], n);
                }
                m--;
                j--;
            }
        }    
    }
    
    for(i = 0; i<n; i++){
        for(j = i + 1; j < n; j++){
            int niz1[200], niz2[200];
            for(k = 0; k < m; k++){
                niz1[k] = niz[k][i];
                niz2[k] = niz[k][j];
            }
            if(jednakiSu(niz1, niz2, m) == 1){
                int h = j + 1;
                for(h; h < n; h++){
                    for(k = 0; k < m; k++){
                        int temp = niz[k][h - 1];
                        niz[k][h - 1] = niz[k][h];
                        niz[k][h] = temp;
                    }
                }
                n--; 
                j--;
            }
        }
    }
    
    printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
    for(i = 0; i<m-1; i++){
        for(j = 0; j<n; j++){
            printf("%5d", niz[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i<n; i++)
        printf("%5d", niz[m-1][i]);
        
    return 0;
}
