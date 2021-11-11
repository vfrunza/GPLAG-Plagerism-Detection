#include <stdio.h>
 
int main() {
   
    int m,n, tep=1,  cit=1, i, j;
   
    double mat[100][100];
   
    printf("Unesite M i N: ");
    scanf("%d %d", &m, &n);
   
    while(m>100||n>100||n<1||m<1)
    {
    printf("Pogresan unos!\nUnesite M i N: ");
    scanf("%d %d", &m, &n);
    }
   
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++){for (j=0;j<n;j++){scanf("%lf", &mat[i][j]);}} //unosis elemente
   
    if(n==1&&m==1) printf("Matrica je cirkularna");
    else if(m==1) printf("Matrica je cirkularna"); //provjeravas granicne slucajeve
    else if(n==1) printf("Matrica je Teplicova");
    else {
        for(i=1; i<m; i++) {
           
            if(mat[i][0]!=mat[i-1][n-1]) cit=0;
           
            for(j=1; j<n;j++) { //provjeravas je li cirkularna, poredis svaka dva susjedna reda
               
                if(mat[i][j]!=mat[i-1][j-1]) cit=0;
               
               
            }}
           
        for(i=0; i<m-1; i++) {
           
            for(j=0; j<n-1;j++) { //provjeravas je li Teplicova, poredis svaki elemenat sa prvim susjednim na dijagonali
               
                if(mat[i][j]!=mat[i+1][j+1]) tep=0;
               
               
            }} 
           
       
           
        if(cit==1) printf("Matrica je cirkularna");
        else if(tep==1) printf("Matrica je Teplicova");
        else printf("Matrica nije ni cirkularna ni Teplicova");
       
       
       
       
 
    }
   
 
 
    return 0;
}