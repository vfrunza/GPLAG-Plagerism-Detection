#include <stdio.h>
#define BROJ_EL 100
int main() {
double matrica[101][101];
int i,j,m,n;
int TM = 1;
int CM = 1;
greska:printf("Unesite M i N: ");
scanf("%d %d",&m,&n);
if(m < 1 || n < 1 || m > 100 || n > 100){
    printf("Pogresan unos!\n");
    goto greska;
    }
printf("Unesite elemente matrice: ");
for (i =0;i < m ; i ++) {
    for (j =0;j < n ; j ++) {
        scanf ("%lf", &matrica[i][j]);
    }
 }
 for(i = 0;i < (m-1);i++){
     for(j = 0;j < (n-1);j++){
      if(matrica[i][j] != matrica[i+1][j+1]){
          TM = 0;
          i = j = 1000;
      }
      }
     }
     for(i = 0;i < (m-1);i++){
         if(matrica[i][n-1]!=matrica[i+1][0]){
             CM = 0;
             break;
         }
     }
     
    if(TM == 1 && CM == 1)
    printf("Matrica je cirkularna");
    else if(TM == 1)
    printf("Matrica je Teplicova");
    else printf("Matrica nije ni cirkularna ni Teplicova");
return 0;
}
