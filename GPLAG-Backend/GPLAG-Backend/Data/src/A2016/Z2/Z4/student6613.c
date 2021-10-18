#include<stdio.h>
#define v 100
#define s 100
int main(){
    int m,n,i,j,t=1,c=0;
    double mat[v][s]={0};
    for(i=0;i<1;i++){
        printf("Unesite M i N: ");
        scanf("%d %d",&m,&n);
        if(m<=0 || m>100 || n<=0 || n>100){
            printf("Pogresan unos!\n");
            i--;
        }
    }
   
    printf("Unesite elemente matrice: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&mat[i][j]);
        }
    }
    if(m==1) printf("Matrica je cirkularna");
    else{
    for(i=0;i<m-1;i++){
        for(j=0;j<n-1;j++){
    if(mat[i][j]==mat[i+1][j+1]) t=1;
            else { t=0;
            break;
        }}}
        
        if(t==1){
            for(i=0;i<m-1;i++){
           if(mat[i][n-1]==mat[i+1][0]) c=1;
           else {c=0;
           break;}
          
        }
    
    }
  
    if(c==1) printf("Matrica je cirkularna");
    else if(t==1) printf("Matrica je Teplicova");
    else printf("Matrica nije ni cirkularna ni Teplicova");}
    return 0;
}
