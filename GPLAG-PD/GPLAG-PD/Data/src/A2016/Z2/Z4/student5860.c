#include <stdio.h>
 
int main() {

int T=0;
int C=0;
double niz[99][99];
int  x,y; 
int i =0 , j=0;
   
    printf("Unesite M i N: ");
    scanf("%d",&x);
    scanf("%d", &y);
    while(x<=0||x>100||y<=0||y>100)
    {
    printf("Pogresan unos!\n");
     printf("Unesite M i N: ");
    scanf("%d",&x);
    scanf("%d", &y);
    }
   
    printf("Unesite elemente matrice: ");
    for(i=0;i<x;i++)
        for (j=0;j<y;j++)scanf("%lf", &niz[i][j]);
   
    if(y==1&&x==1) printf("Matrica je cirkularna");
    else if(y==1) printf("Matrica je Teplicova");
    
    else {
        for(i=1; i<x; i++) {
           
            if(niz[i][0]!=niz[i-1][y-1]) C=1;
           
            for(j=1; j<y;j++) {
               
                if(niz[i][j]!=niz[i-1][j-1]) C=1;
               
               
            }}
           
        for(i=0; i<x-1; i++) {
           
            for(j=0; j<y-1;j++) { 
               
                if(niz[i][j]!=niz[i+1][j+1]) T=1;
               
               
            }} 
           
     
     	if (T!=0 && C!=0) printf("Matrica nije ni cirkularna ni Teplicova");
        else if(C==0) printf("Matrica je cirkularna");
        else if(T==0) printf("Matrica je Teplicova");
     
    }
   
    return 0;
}
