#include <stdio.h>

int main() {
	int r, k, sirina, i, j, p, l, m;

  /* unos redova kolona i sirina kolone  */

  do
  {
   	printf("Unesite broj redova: ");
    scanf("%d", &r);   
  }
  while(r<=0 || r>10);
  
  do
  {
    printf("Unesite broj kolona: ");
	scanf("%d", &k);
  }
  while(k<=0 || k>10);
  
  do
  {
    printf("Unesite sirinu jedne kolone: ");
  	scanf("%d", &sirina);
  }
  while(sirina<=0 || sirina>10);
  
  /* ispis slike */
  
  for(i=0; i<r; i++) {
  printf("+");
  for(j=0; j<k; j++) {
  for(m=0; m<sirina; m++) {
  printf("-");
  }
  printf("+");
  }
  printf("\n");


  printf("|");
  for(l=0; l<k; l++) {
  for(p=0; p<sirina; p++) {
  printf(" ");
  }
  printf("|");
  }
  printf("\n");
  }

  printf("+");
  for(j=0; j<k; j++) 
  {
  for(m=0; m<sirina; m++) 
  {
  printf("-");
  }
  printf("+");
  }
  
  
 	return 0;
}