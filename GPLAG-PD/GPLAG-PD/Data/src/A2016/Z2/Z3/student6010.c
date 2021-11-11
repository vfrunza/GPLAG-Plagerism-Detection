#include <stdio.h>
#define A 20

int main() {
 int i, j, n, x, y, m[A][A]={0};
 printf("Unesite broj tacaka: ");
 scanf("%d", &n);
 while(n<1 || n>10) {printf("Pogresan unos\n");
 printf("Unesite broj tacaka: ");
 scanf("%d", &n);
}
for(i=1; i<=n; i++) {
 printf("Unesite %d. tacku: ", i);
 scanf("%d %d", &x, &y);
 while(x<0 || x>19 || y<0 || y>19) {printf("Pogresan unos\n");
  printf("Unesite %d. tacku: ", i);
 scanf("%d %d", &x, &y); }
 m[x][y]=1;
 
}
for(i=0; i<=19; i++) {
 for(j=0; j<=19; j++) {
  if(m[j][i]==1) printf("*");
  else printf(" ");
 }
 printf("\n");
}
return 0;
}