#include <stdio.h>
#include <math.h>
#define RED 100
#define KOL 100

int main() {
    int  m,n, greska=0, i, j, c=1, t=1;
    double matrica[RED][KOL];

    do{
        if(greska != 0) printf ("Pogresan unos!\n");
        printf("Unesite M i N: ");
        scanf("%d %d", &m, &n);

        greska++;

    }
    while (m<=0 || m>100 || n<=0 || n>100);

    printf("Unesite elemente matrice: ");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
        scanf("%lf", &matrica[j][i]);
        }
    }

    for(i=0; i<m-1; i++){
        for(j=0; j<n-1; j++){
        if(matrica[j+1][i+1] != matrica [j][i]){
         t=0;
         break;
        }
        }
    } 


    for(i=0; i<m-1; i++){
        for(j=0; j<n-1; j++){
     if(matrica[n-1][i] != matrica [0][i+1] || matrica[j+1][i+1]!=matrica[j][i]){
         c=0;
         break;
        }
        }
    } 
if(n==1&&m==1)printf("Matrica je cirkularna");
else if(m==1) printf("Matrica je cirkularna");
else if(n==1) printf("Matrica je Teplicova");
 else   if (c==1) printf("Matrica je cirkularna");
    else if (t==1) printf("Matrica je Teplicova");
    else printf ("Matrica nije ni cirkularna ni Teplicova");


    return 0;
} 
