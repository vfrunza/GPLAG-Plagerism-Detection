#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.0001

int main() {
    
    int m, n, i, j, brojac=0, cik=0, tep=0;
    double matrica[100][100], niz[100], el;
    
    do {
        printf("Unesite M i N: ");
        scanf("%d %d", &m, &n);
        if(m>100 || m<=0 || n>100 || n<=0) printf("Pogresan unos!\n");
        
    } while(m>100 || m<=0 || n>100 || n<=0);

    
    printf("Unesite elemente matrice: ");
    
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%lf", &el);
            matrica[i][j]=el;
            if(i==0) niz[j]=el;
            if(j==0 && i!=0) { niz[n+brojac]=el; brojac++; }
            
        }
    }
    
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
        
         if(i-j<=0 || j==n-1) {
             
             if(matrica[i][j]>=0) {
             if((matrica[i][j]-niz[abs(i-j)])<EPSILON) tep=1; 
             else { tep=0; goto ispis; }
             } 
             
             else if(matrica[i][j]<0) {
             if((matrica[i][j]-niz[abs(i-j)])>EPSILON) tep=1; 
             else { tep=0; goto ispis; }
             } 
             
             
             
         }
         
         else {
             if(fabs(matrica[i][j]-niz[i-j+n-1])<EPSILON) tep=1;
             else { tep=0; goto ispis; }
         }
            
        }
    }
    
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            
            if(m==1 && n>0) { cik=1; goto ispis; }
            if(n==1 && m>0) {  cik=0; goto ispis; }
            if(j==n-1 && i!=m-1) { if(fabs(matrica[i][j]-matrica[1+i][0])<EPSILON) cik=1; else { cik=0; goto ispis; }}
            if(i==j && i!=0) { if((matrica[i][j-1]-n)<EPSILON) cik=1;  else { cik=0; goto ispis; } }
         
    
    }
    
    }

    ispis:
    if(cik==1 && tep==1) printf("Matrica je cirkularna");
    else if(tep==1) printf("Matrica je Teplicova");
    else printf("Matrica nije ni cirkularna ni Teplicova");
    return 0;
    
}
