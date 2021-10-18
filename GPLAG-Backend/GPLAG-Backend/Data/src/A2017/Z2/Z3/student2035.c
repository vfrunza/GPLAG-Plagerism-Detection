#include <stdio.h>
#include <math.h>
#define maxsir 100
#define maxvis 100
#define EPSILON 0.000001
int main() {
      double matA[maxsir][maxvis], matB[maxsir][maxvis];
      int i, j, s1, v1, s2, v2;
      printf("Unesite sirinu i visinu matrice A: ");
      scanf("%d %d", &s1, &v1);
      printf("Unesite clanove matrice A: "); 
      for(i=0;i<v1;i++)
      for(j=0;j<s1;j++) 
      scanf("%lf", &matA[i][j]);
      printf("Unesite sirinu i visinu matrice B: ");
      scanf("%d %d", &s2, &v2);
      printf("Unesite clanove matrice B: ");
      for(i=0;i<v2;i++)
      for(j=0;j<s2;j++)
      scanf("%lf", &matB[i][j]);
      
      if(v1!=s2 || v2!=s1) {printf("NE"); return 0;}
      
      for(i=0; i<v1; i++) {
            for(j=0; j<s1; j++) {
                  if(fabs(matA[i][j]-matB[j][v1-1-i])<EPSILON) continue;
                  else {printf("NE"); return 0;}
            }
      }
      printf("DA");
      
	return 0;
}
