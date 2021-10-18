#include <stdio.h>
#include <math.h>
int main() {
   int p, l, a, b;
   double mat[100][100];
   
   do{ 
       printf("Unesite M i N: ");
       scanf ("%d %d", &l, &p);
       if ( l <= 0 || l > 100 || p <= 0 || p > 100) {
           printf("Pogresan unos!\n");
       }
   } while ( l <= 0 || l > 100 || p <= 0 || p > 100);
   
   printf("Unesite elemente matrice: ");
   for (a = 0; a < l; a++){
       for (b = 0; b < p; b++){
           scanf("%lf", &mat[a][b]);
       }
   }
   
   for (a = 0; a < l -1; a++) { 
       for (b = 0; b < p - 1; b++){
           if (mat[a][b] != mat[a+1][b+1]){
               printf("Matrica nije ni cirkularna ni Teplicova");
               return 0;
           }
       }
   }
   for (a = 0; a < l - 1; a++){ 
       if (mat[a][p-1] != mat[a+1][0]){
           printf ("Matrica je Teplicova");
           return 0;
       }
   }
   printf("Matrica je cirkularna");
   return 0;
}