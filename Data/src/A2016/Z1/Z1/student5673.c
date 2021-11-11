#include <stdio.h>
int main()
{
   float x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6, z1, z2, z3, z4, z5, z6;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &x2);
   if (x2 < 0 || x2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &x3);
   if (x3 < 0 || x3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &x4);
   if (x4 < 0 || x4 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &x5);
   if (x5 < 0 || x5 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &x6);
   if (x6 < 0 || x6 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &y2);
   if (y2 < 0 || y2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &y3);
   if (y3 < 0 || y3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &y4);
   if (y4 < 0 || y4 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &y5);
   if (y5 < 0 || y5 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &y6);
   if (y6 < 0 || y6 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &z2);
   if (z2 < 0 || z2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &z3);
   if (z3 < 0 || z3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &z4);
   if (z4 < 0 || z4 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &z5);
   if (z5 < 0 || z5 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &z6);
   if (z6 < 0 || z6 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   x1 = (double)x2 + x3 + x4 + x5 + x6;
   y1 = (double)y2 + y3 + y4 + y5 + y6;
   z1 = (double)z2 + z3 + z4 + z5 + z6;
   if (x1 < 55 && y1 < 55 && z1 < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((x1 > 54 && y1 < 55 && z1 < 55) || (x1 < 55 && y1 > 54 && z1 < 55) || (x1 < 55 && y1 < 55 && z1 > 54))
   {
      printf("Jedan student je polozio.");
   }
   else if ((x1 > 54 && y1 > 54 && z1 < 55) || (x1 < 55 && y1 > 54 && z1 > 54) || (x1 > 54 && y1 < 55 && z1 > 54))
   {
      printf("Dva studenta su polozila.");
   }
   if (x1 > 54 && y1 > 54 && z1 > 54)
   {
      printf("Sva tri studenta su polozila.");
      if (((x1 > 54 && x1 < 65) && (y1 > 54 && y1 < 65) && (z1 > 54 && z1 < 65)) || ((x1 > 64 && x1 < 75) && (y1 > 64 && y1 < 75) && (z1 > 64 && z1 < 75)) || ((x1 > 74 && x1 < 85) && (y1 > 74 && y1 < 85) && (z1 > 74 && z1 < 85)) || ((x1 > 84 && x1 < 92) && (y1 > 84 && y1 < 92) && (z1 > 84 && z1 < 92)) || ((x1 > 91 && x1 < 101) && (y1 > 91 && y1 < 101) && (z1 > 91 && z1 < 101)))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (((x1 > 54 && x1 < 65) && (y1 > 54 && y1 < 65)) || ((x1 > 54 && x1 < 65) && (z1 > 54 && z1 < 65)) || ((y1 > 54 && y1 < 65) && (z1 > 54 && z1 < 65)) || ((x1 > 64 && x1 < 75) && (y1 > 64 && y1 < 75)) || ((x1 > 64 && x1 < 75) && (z1 > 64 && z1 < 75)) || ((y1 > 64 && y1 < 75) && (z1 > 64 && z1 < 75)) || ((x1 > 74 && x1 < 85) && (y1 > 74 && y1 < 85)) || ((x1 > 74 && x1 < 85) && (z1 > 74 && z1 < 85)) || ((y1 > 74 && y1 < 85) && (z1 > 74 && z1 < 85)) || ((x1 > 84 && x1 < 92) && (y1 > 84 && y1 < 92)) || ((z1 > 74 && z1 < 85) && (z1 > 84 && z1 < 92)) || ((y1 > 84 && y1 < 92) && (z1 > 84 && z1 < 92)) || ((x1 > 91 && x1 < 101) && (y1 > 91 && y1 < 101)) || ((x1 > 91 && x1 < 101) && (z1 > 91 && z1 < 101)) || ((y1 > 91 && y1 < 101) && (z1 > 91 && z1 < 101)))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
