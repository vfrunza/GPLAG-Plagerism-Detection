#include <stdio.h>
#include <math.h>
#define epslilon 0.000001
int main(){
    int m,n,i,j,t=1;
    double a[100][100];
    do{
        printf("Unesite M i N: ");
        scanf("%d %d",&n,&m);
        if (m>100 || m<1 || n<1 || n>100)
        printf("Pogresan unos!\n");
        else
        break;
    }while(1);
    printf("Unesite elemente matrice: ");
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    scanf("%lf",&a[i][j]);
    if(n==1){
    printf("Matrica je cirkularna");
    return 0;
    }
    if(m==1){
    printf("Matrica je Teplicova");
    return 0;
    }
    for(i=1;i<n;i++){
    for(j=1;j<m;j++){
        if(fabs(a[i-1][j-1]-a[i][j])>epslilon)
            t=0;
            }
            
    }
     if(t){
       for(i=0;i<n-1;i++){
            if(fabs(a[i][m-1]-a[i+1][0])>epslilon)
                break;
            else if (i==n-2){
            printf("Matrica je cirkularna");
            return 0;
            }
       } 
            }
    if(t)
    printf("Matrica je Teplicova");
    else
    printf("Matrica nije ni cirkularna ni Teplicova");
    return 0;
}