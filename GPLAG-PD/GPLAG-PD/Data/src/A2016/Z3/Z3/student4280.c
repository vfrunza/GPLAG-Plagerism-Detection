#include <stdio.h>

int main() {
    int M,N,i,j,k,mat[50][50],flag[50][50];

do {
        printf ("Unesite brojeve M i N: ");
        scanf("%d %d", &M, &N);
        if (M>200 || N>200 || M<0 || N<0)
            printf ("Brojevi nisu u trazenom opsegu.\n");
    } while (M>200 || N>200 || M<0 || N<0);
   
printf("Unesite elemente matrice: ");


for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    for(i=0;i<=M;i++) {
        for(j=0;j<=N;j++) {
            flag[i][j]=1;
        }
    }
    
    flag[0][N]=1;
    for (i=0;i<M;i++) {
        for (j=i+1;j<M;j++) {
            if (flag[j][N]!=0) {
                flag[j][N]=0;
                for (k=0;k<N;k++) {
                    if(mat[i][k]!=mat[j][k] ) {
                        flag[j][N]=1;
                        break;
                    }
                }
            }
       }
    }

    flag[M][0]=1;
    for (i=0;i<N;i++) {
        for (j=i+1;j<N;j++) {
            if (flag[M][j]!=0) {
                flag[M][j]=0;
                for (k=0;k<M;k++) {
                    if(mat[k][i]!=mat[k][j] ) {
                        flag [M][j]=1;
                        break;
                    }
                }
            }
       }
   }
   
 printf("Nakon izbacivanja redova/kolona matrica glasi: ");
            printf("\n");
    for (i=0;i<M;i++) {
        if (flag[i][N]==1) {
            for (j=0;j<N;j++) {
                if (flag[M][j]==1) printf("%5d",mat[i][j]);
            }
            printf("\n");
        }
    }
return 0; 
}