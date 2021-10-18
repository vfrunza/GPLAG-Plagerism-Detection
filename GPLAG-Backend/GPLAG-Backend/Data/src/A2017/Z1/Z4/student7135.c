#include <stdio.h>
int main () {
       int i, j, m, r, k, s, x, y;
       do { printf("Unesite broj redova: ");
       scanf("%d", &r);
       } while (r<=0 || r>10);
       do { printf("Unesite broj kolona: ");
       scanf("%d", &k);
       } while (k<=0 || k>10);
       do { printf("Unesite sirinu jedne kolone: ");
       scanf("%d", &s);
       } while (s<=0 || s>10);
       for (m=0; m<r; m++) {
       for (i=0; i<k; i++) {
       printf("+");
       for (j=0; j<s; j++) {
       printf("-");
       }
       }
       printf("+");
       printf("\n");
       for(x=0; x<k+1; x++) {
       printf("|");
       for(y=0; y<s; y++) {
       printf(" ");
       } 
       }
       printf("\n");
       }
       for (i=0; i<k; i++) {
       printf("+");
       for (j=0; j<s; j++) {
       printf("-");
       }
       }
       printf("+");
       return 0; 
}