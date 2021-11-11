#include <stdio.h>

int main()
{
   int red, kolona, sirina, i, j,n;
  // Unos redova
   do {
      printf("Unesite broj redova: ");
      scanf("%d",&red);
   } while ((red<1) || (red>10));
   // Unos kolona
   do {
      printf("Unesite broj kolona: ");
      scanf("%d",&kolona);
   } while ((kolona<1) || (kolona>10));
   // Unos sirine kolone
   do {
      printf("Unesite sirinu jedne kolone: ");
      scanf("%d",&sirina);
   } while ((sirina<1) || (sirina>10));
   // Prvi red 
   j=0;
   while(j<red)  {

      j++;

    // +--
      i=0;
      while(i<kolona)  {
         printf("+");
         i++;


         n=0;
         while(n<sirina)  {
            printf("-");
            n++;
         }
      }
      // Na kraju +
      printf("+");
      printf("\n");
      // |
      i=0;
      while(i<kolona)  {
         printf("|");
         i++;
     // Razmak izmedju 
         n=0;
         while(n<sirina)  {
            printf(" ");
            n++;
         }
      }
      // Na kraju |
      printf("|");
      printf("\n");
   }
   // Zadnji red 
   i=0;
   while(i<kolona)  {
      printf("+");
      i++;

      n=0;
      while(n<sirina)  {
         printf("-");
         n++;
      }
   }
   printf("+");

   return 0;
}
