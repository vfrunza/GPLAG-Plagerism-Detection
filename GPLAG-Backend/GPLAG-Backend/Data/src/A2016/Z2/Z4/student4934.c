#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define e 0.0000000000000001
#define w 100
int main () {
    double n[w][w];
    int x=0,y=0,N,M,a,b;
    do {
        printf ("Unesite M i N: ");
        scanf ("%d %d",&M,&N);
        if( ( (M>w) || (M<=0)) || ((N<=0) || (N>w) ) ) {
            printf ("Pogresan unos!\n");
        }
    }
    while (((M>w) || (M<=0)) || ((N<=0) || (N>w)));
    printf ("Unesite elemente matrice: ");
    a=1;
    b=1;
    for (x=0;x<M;x++) {
        for (y=0;y<N;y++) {
            scanf ("%lf",&n[x][y]);
        }
    }
    for (x=0;x<M-1;x++) {
        for (y=0;y<N-1;y++){
            if ((fabs(n[x][y]-n[x+1][y+1])>e))
            a=0;
        }
    }
    for (x=0;x<M-1;x++) {
        for (y=0;y<N-1;y++) {
            if ((fabs (n[x][y]-n[x+1][y+1])>e) || (fabs (n[x][N-1]-n[x+1][0])>e))
            b=0;
        }
    }
    if (((M==w)&&(N==1)) || ((a==1) && (b==0))) {
        printf ("Matrica je Teplicova");
    }
    else if (b==1) {
        printf ("Matrica je cirkularna");
    }
    else {
        printf ("Matrica nije ni cirkularna ni Teplicova");
    }
    return 0;
}
