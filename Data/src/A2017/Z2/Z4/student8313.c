#include <stdio.h>

int main() {
    int i, j, m, n, a[100][100], b[100][100], c[100][100], br[1000]={0}, isti;
    double t;

  
    m = 0;
    n = 0;
    isti = 1;
    
    
   
    /*Unos dimenzije matrice*/
    do {
      printf("Unesite brojeve M i N: ");
      scanf("%d %d", &m, &n);  
    } while (m>100 || n>100 || m<0 || n<0);
    
    
    
    /*Unos clanova matrica*/
    
    printf("Unesite clanove matrice A: ");
    for(i=0; i<m; i++) {
      for(j=0; j<n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    
    printf("Unesite clanove matrice B: ");
    for(i=0; i<m; i++) {
      for(j=0; j<n; j++) {
        scanf("%d", &b[i][j]);
      }
    }
    
    printf("Unesite clanove matrice C: ");
    for(i=0; i<m; i++) {
      for(j=0; j<n; j++) {
        scanf("%d", &c[i][j]);
      }
    }
    
    
    
  /*Brojimo koliko se puta element javlja u svakoj od matrica*/
  
  for(i=0; i<m; i++) {
    for(j=0; j<n; j++) {
      br[a[i][j]] ++;
    }
  }

  for(i=0; i<m; i++) {
    for(j=0; j<n; j++) {
      br[b[i][j]] ++;
    }
  }

  for(i=0; i<m; i++) {
    for(j=0; j<n; j++) {
      br[c[i][j]] ++;
    }
  }


 /*Zbir svih ponovljenih brojeva iz matrice A treba da bude djeljiv sa 3*/
 for(i=0; i<m; i++) {
   for(j=0; j<n; j++) {
     t = br[a[i][j]] % 3;
     if(t > 0) isti = 0;
    }
  }
 
 if(isti == 1) {
   printf("DA");
 } else {
   printf ("NE");
 }
    
 
  return 0;

}

