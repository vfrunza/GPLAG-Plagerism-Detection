#include "stdio.h"
int main(void)
{

  int brredova=0,brkolona=0,sirina=0,i,j,k;

  do {
    printf("Unesite broj redova: ");
    scanf("%d",&brredova);
  } while (brredova<=0|| brredova>10);

  do {
    printf("Unesite broj kolona: ");
    scanf("%d",&brkolona);
  } while (brkolona<=0 || brkolona>10);

  do {
    printf("Unesite sirinu jedne kolone: ");
    scanf("%d",&sirina);
  } while(sirina<=0|| sirina>10);


  for (i=0; i<brredova*2+1; i++) 
  {
    for(j=1; j<=brkolona; j++)
    {
      if (i%2==0) printf("+");
      else printf("|");

      for(k=1; k<=sirina; k++) 
      {
        if (i%2==0) printf("-");
        else printf(" ");
      }
    }

   if (i%2==0) printf("+\n");
   else printf("|\n");
  }
  return 0;
}