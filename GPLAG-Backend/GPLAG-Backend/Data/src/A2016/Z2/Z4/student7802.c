#include <stdio.h>
#define VISINA 100
#define SIRINA 100
int main () {
    int t=1,c=1,m=1,n=1,i=0,j=0;
    double mat[VISINA][SIRINA]= {{0}};
    printf ("Unesite M i N: ");
    do{
        scanf("%d %d", &m, &n);
        if (m<=0 || n<=0 || m>100 || n>100){printf("Pogresan unos!\n");printf("Unesite M i N: ");}
    }while(m<=0 || n<=0 || m>100 || n>100);
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
        scanf("%lf", &mat[i][j]);
        }
    }
    for(i=0;i<m-1;i++){
        for(j=0;j<n-1;j++){
           if(mat[i+1][j+1]!=mat[i][j] || mat[1+i][0]!=mat[i][n-1]) c=0;

        }
    }t=1;
    for(i=0;i<m-1;i++){
        for(j=0;j<n-1;j++){
           if(mat[i][j]!=mat[i+1][j+1]) t=0;
        }
    }
    
    
    
    if(n==1 && m!=1){printf("Matrica je Teplicova");}
    else if(c==1){printf("Matrica je cirkularna");}
    else if(t==1 && c==0){printf("Matrica je Teplicova");}
    else if(t==0 && c==0){printf("Matrica nije ni cirkularna ni Teplicova");}
    return 0;
}