#include <stdio.h>
#define m 100
#define n 100

int main() {
    int i, j,teplicova, cirkularna;
    double mat[m][n];
    
    
    printf("Unesite M i N: ");
    scanf("%d %d",&i,&j);
    
    if((i<0||i>100) || (j<0 || j>100)){printf("Pogresan unos!");}
    
    printf("Unesite elemente matrice: ");
    
    teplicova=0;
    for(i=0;i<n;i++){
        
        for(j=0;j<n;j++){
            
            if(i==j || (i>j && i+n==j) || (i<j && i==j+1)){
                teplicova=1;
            }
        }
    }
    if(teplicova) printf("Matrica je Teplicova "); return 0;
    
    
    cirkularna=0;
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            //if((i<0||i>100) && (j<0 || j>100)){printf("Pogresan unos!");}
            if(i==j || (i>j && i+n==j) || (i<j && i==j+1) || (mat[i][n-1]==mat[i+1][0])){
                cirkularna=1;
            }
        }
    }
    if(cirkularna) printf("Matrica je cirkulatna");
    
    if(i<0||i>100 || j<0 || j>100){printf("Matrica nije ni cirkularna ni Teplicova.");}
    
    
    
	return 0;
}
