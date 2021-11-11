#include <stdio.h>
#include <math.h>
int main () {
    
    int M, N, i, j, razlika, cirkularna=1;
    double matrica[100][100]= {{0}};
    
        do { 
        printf("Unesite M i N: ");
        scanf ("%d %d", &M, &N);
        if (M<1 || N<1 || M>100 || N>100)
        printf ("Pogresan unos!\n");
       else break;
    } while (M>1 || N>1 || M<100 || N<100);
    
    
    printf ("Unesite elemente matrice: ");
    for (i=0; i<M; i++)
        for (j=0; j<N; j++)
            scanf ("%lf",&matrica[i][j]);
            
    if (M==1) {
        printf ("Matrica je cirkularna");
        return 0;
    } 
    else if (N==1) {
        printf ("Matrica je Teplicova");
        return 0;
    }
    razlika=fabs(M-N);
    for (i=0; i<M-1; i++)
        if (matrica[i][N-1]!=matrica[i+1][0] || matrica[0][razlika]!=matrica[M-1][N-1]) 
            cirkularna=0;
        
    if (cirkularna==1) {
        printf ("Matrica je cirkularna");
        return 0;
    } else {
        int teplicova=1;
        for(i=0; i<M-1; i++) {
            for(j=0; j<N-1; j++) {
                if(matrica[i][j]!=matrica[i+1][j+1])
                    teplicova=0;
            }
        }
        if (teplicova) printf ("Matrica je Teplicova");
        else goto KRAJ;
        return 0;
    }
        KRAJ: printf ("Matrica nije ni cirkularna ni Teplicova");
        return 0;
    }
