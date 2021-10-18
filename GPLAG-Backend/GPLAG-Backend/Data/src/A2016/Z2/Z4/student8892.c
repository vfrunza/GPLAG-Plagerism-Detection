#include <stdio.h>

int main() {
    
    int m,n, i, j, teplic=1, cirku=0, nitepci;
    double mat[100][100];
    
    do{
    printf ("Unesite M i N: ");
    scanf ("%d %d", &m, &n);
    
    if (m<=0 || n<=0 || m>100 || n>100){
        printf ("Pogresan unos!\n");
        
    }
    }while (m<=0 || n<=0 || m>100 || n>100);
    
    printf ("Unesite elemente matrice: ");
    for (i=0; i<m;i++){
        for (j=0; j<n; j++){
            scanf ("%lf", &mat[i][j]);
        }
    }
    if (m==1){
        cirku=1;
    }
        else {
            for (i=0; i< m-1; i++){
                for (j=0; j<n-1; j++){
                    if (mat[i][j]== mat[i+1][j+1]){
                        teplic=1;
                        nitepci=0;
                    }
                    else {
                        teplic=0;
                        nitepci=1;
                        break;
                    }
                }
            }
            if (teplic==1){
                for (i=0; i<m-1; i++){
                    if (mat[i][n-1]== mat[i+1][0]){
                        cirku=1;
                        nitepci=0;
                    }
                    
                    else{
                        cirku=0;
                        break;
                    }
                }
            }
        }
    if (cirku==1){
        printf ("Matrica je cirkularna");
        
    }
    else if (teplic==1){
        printf ("Matrica je Teplicova");
    }
    else if (nitepci ==1){
        printf ("Matrica nije ni cirkularna ni Teplicova");
    }
    return 0;
}