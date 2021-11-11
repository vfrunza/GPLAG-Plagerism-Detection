#include <stdio.h>
int main () {
double mat[100][100];
int M,N,pret,cirk,i,j;

do {
    printf ("Unesite M i N: ");
    scanf ("%d%d", &M, &N);
    if (M<=0 || M>100 || N<=0 || N>100)
    printf ("Pogresan unos!\n");
}
    while (M<=0 || M>100 || N<=0 || N>100);
    printf ("Unesite elemente matrice: ");
        for (i=0;i<M;i++) 
                for (j=0;j<N;j++)
    scanf ("%lf",&mat[i][j]);
    pret=1;
    for (i=1;i<M;i++) 
        for (j=1;j<N;j++) 
            if (mat[i][j]!=mat[i-1][j-1])
            pret=0;
            
            if (pret==1) {
                cirk=1;
                for (i=1;i<M;i++)
                if (N-i>=0)
                    if (mat[i][0]!=mat[0][N-i])
                    cirk=0;
                   if (cirk==1) 
                    printf("Matrica je cirkularna"); 
                else 
                printf ("Matrica je Teplicova");
               } else {
                    printf ("Matrica nije ni cirkularna ni Teplicova");
            }
        return 0;
}