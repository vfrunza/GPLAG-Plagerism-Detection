#include <stdio.h>
#include <math.h>
#define max 100
#define e 0.00001

int main() {
    int i,j, m, n, Z=0, Y=0;
    double x[max][max];
    lesgo:
    printf("Unesite M i N: ");
    scanf("%d %d", &m, &n);
    if(m>100 || m<=0 || n>100 || n<=0){
        printf("Pogresan unos!\n");
        goto lesgo;
    } 
    printf("Unesite elemente matrice: ");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%lf", &x[i][j]);
        }
    }
    for(i=0; i<m; i++){
        if(i==m-1)
                break;
        for(j=0; j<n; j++){
            if(j==n-1)
                continue;
            if(fabs((x[i][j])-(x[i+1][j+1]))<e){
                Z=1;
            } else {
                Z=0;
                printf("Matrica nije ni cirkularna ni Teplicova");
                return 0;
            }
        }
    }
    
    for(i=0; i<m; i++){
        if(i==m-1) break;
            
        for(j=0; j<n; j++){
            
            if(fabs(x[i][n-1]-x[i+1][0])<e){
                Y=1; Z=0;
            } else {
                Y=0;
                printf("Matrica je Teplicova");
                return 0;
            }
        }
    }
    printf("Matrica je cirkularna"); 
    return 0;
}
