#include <stdio.h>
int main() {
    double matrica[100][100]={0};
    int teplicova=1, cirkularna=1, i, j, m ,n;
    do {
        printf("Unesite M i N: ");
        scanf("%d %d", &m, &n);
        if (m>100 || m<=0 || n>100 || n<=0) printf("Pogresan unos!\n");
    }
    while(m>100 || m<=0 || n>100 || n<=0);
    
    printf("Unesite elemente matrice: "); 
    
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%lf", &matrica[i][j]);
        }
    }
    
    for(i=1; i<m; i++) {
        for(j=1; j<n; j++) {
            
            if(matrica[i][j]!=matrica[i-1][j-1]) {
                teplicova=0;
                cirkularna=0;
                j=n;
                i=m;
            }
               }
    }
    
    for(i=1; i<m-1; i++) {
        for(j=1; j<n; j++) {
            if(matrica[i][0]!=matrica[i-1][n-1]) {
                cirkularna=0;
                j=n;
                i=m-1;
            }
        }
    }



    if(teplicova && cirkularna) printf("Matrica je cirkularna");
    else if(teplicova) printf("Matrica je Teplicova");
    else printf("Matrica nije ni cirkularna ni Teplicova");
    
    
    return 0;
    
    
    
    
    
}