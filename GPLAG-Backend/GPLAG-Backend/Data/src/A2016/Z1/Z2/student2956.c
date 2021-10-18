#include <stdio.h>
#include <stdlib.h>

int main()
{
   float a1,b1,a2,b2;
   float a,b;

   printf("Unesite a1,b1,a2,b2:");
   scanf("%f,%f,%f,%f",&a1,&b1,&a2,&b2);
   if(a1==a2 && b1==b2) printf("Poklapaju se"); /* prave se poklapaju kada su a1,a2 i b1,b2 jednaki*/
   else if(a1==a2 && b1!=b2) printf("Paralelne su"); /* prave su paralelne kada su im koeficijenti a1 i a2 jednaki */
   /* nadjemo tacke gdje se sijeku prave */
   else {
        a=(b2-b1)/(a1-a2);
        b=(a1*a+b1);
        printf("Prave se sijeku u tacci (%.1f,%.1f)",a,b);
   }
   return 0;
}