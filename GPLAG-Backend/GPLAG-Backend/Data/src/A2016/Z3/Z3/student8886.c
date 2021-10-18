#include <stdio.h>

int main () {
    
    int M, N, i, j, mat[200][200], pret=1, k, l;
    printf ("Unesite brojeve M i N: ");
    scanf ("%d %d", &M, &N);
   
/*Osiguravanje da su M i N u zadatom opsegu*/   
    if (M<=0 || M>200 || N<=0 || N>200) {
    do {
        printf ("Brojevi nisu u trazenom opsegu.\nUnesite brojeve M i N: ");
        scanf ("%d %d", &M, &N);
    } while (M<=0 || M>200 || N<=0 || N>200);
   
       }
   
/*Unos elemenata matrice*/   
       printf ("Unesite elemente matrice: ");
       for (i=0; i<M; i++) {
           for (j=0; j<N; j++) {
               scanf ("%d", &mat[i][j]);
           }
       }
       
/*Izbacivanje reda koji se ponavlja*/
    for (i=0; i<M-1; i++) {
        for (k=i+1; k<M; k++) { 
            pret=1;
            for (j=0; j<N; j++)
            if (mat[i][j]!=mat[k][j]) 
            pret=0;
            
            if (pret==1) {
                for (j=k; j<M; j++) 
                   for (l=0; l<N; l++) 
                       mat[j][l]=mat[j+1][l];
                          M--;
                          k--;
            }
                else if (i==N && k==M) 
                M--;      
        } 
    }
    
/*Izbacivanje kolone koja se ponavlja*/
    for (j=0; j<N-1; j++) {
        for (k=j+1; k<N; k++) {
            pret=1;
            for (i=0; i<M; i++) 
            if (mat[i][j]!=mat[i][k]) 
            pret=0;
            
            if (pret==1) {
                for (i=k; i<N-1; i++) 
                   for (l=0; l<M; l++) 
                      mat[l][i]=mat[l][i+1];
                      N--;
                      k--;
            }
            else if (j==M && k==N) 
                N--;
        }
    }
  
/*Ispis modifikovane matrice*/

printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            printf ("%5d", mat[i][j]);
        }
        printf ("\n");
    }
    return 0;
}