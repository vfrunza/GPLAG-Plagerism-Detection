#include <stdio.h>

int main()
{
   float a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3, z1, z2, z3, y1, y2, y3;
   int   o1, o2, o3;

   /* TARIK */
   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &a1);
   if (a1 < 0 || a1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%f", &b1);
   if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   scanf("%f", &c1);
   if (c1 < 0 || c1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   scanf("%f", &z1);
   if (z1 < 0 || z1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   scanf("%f", &d1);
   if (d1 < 0 || d1 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      /* BOJAN */
      printf("Unesite bodove za Bojana:");
   }
   printf("\nI parcijalni ispit: ");
   scanf("%f", &a2);
   if (a2 < 0 || a2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%f", &b2);
   if (b2 < 0 || b2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   scanf("%f", &c2);
   if (c2 < 0 || c2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   scanf("%f", &z2);
   if (z2 < 0 || z2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   scanf("%f", &d2);
   if (d2 < 0 || d2 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      /* MIRZA */
      printf("Unesite bodove za Mirzu:");
   }
   printf("\nI parcijalni ispit: ");
   scanf("%f", &a3);
   if (a3 < 0 || a3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%f", &b3);
   if (b3 < 0 || b3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   scanf("%f", &c3);
   if (c3 < 0 || c3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   scanf("%f", &z3);
   if (z3 < 0 || z3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   scanf("%f", &d3);
   if (d3 < 0 || d3 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      y1 = a1 + b1 + c1 + d1 + z1;
   }
   y2 = a2 + b2 + c2 + d2 + z2;
   y3 = a3 + b3 + c3 + d3 + z3;

   if (y1 < 55)
   {
      o1 = 5;
   }
   else if (y1 >= 55 && y1 < 65)
   {
      o1 = 6;
   }
   else if (y1 >= 65 && y1 < 75)
   {
      o1 = 7;
   }
   else if (y1 >= 75 && y1 < 85)
   {
      o1 = 8;
   }
   else if (y1 >= 85 && y1 < 92)
   {
      o1 = 9;
   }
   else if (y1 >= 92 && y1 <= 100)
   {
      o1 = 10;
   }

   if (y2 < 55)
   {
      o2 = 5;
   }
   else if (y2 >= 55 && y2 < 65)
   {
      o2 = 6;
   }
   else if (y2 >= 65 && y2 < 75)
   {
      o2 = 7;
   }
   else if (y2 >= 75 && y2 < 85)
   {
      o2 = 8;
   }
   else if (y2 >= 85 && y2 < 92)
   {
      o2 = 9;
   }
   else if (y2 >= 92 && y2 <= 100)
   {
      o2 = 10;
   }

   if (y3 < 55)
   {
      o3 = 5;
   }
   else if (y3 >= 55 && y3 < 65)
   {
      o3 = 6;
   }
   else if (y3 >= 65 && y3 < 75)
   {
      o3 = 7;
   }
   else if (y3 >= 75 && y3 < 85)
   {
      o3 = 8;
   }
   else if (y3 >= 85 && y3 < 92)
   {
      o3 = 9;
   }
   else if (y3 >= 92 && y3 <= 100)
   {
      o3 = 10;
   }

   if (y1 < 55 && y2 < 55 && y3 < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   if ((y1 >= 55 && y2 < 55 && y3 < 55) || (y1 < 55 && y2 >= 55 && y3 < 55) || (y1 < 55 && y2 < 55 && y3 >= 55))
   {
      printf("Jedan student je polozio.");
   }
   if ((y1 >= 55 && y2 >= 55 && y3 < 55) || (y1 < 55 && y2 >= 55 && y3 >= 55) || (y1 >= 55 && y2 < 55 && y3 >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   if (y1 >= 55 && y2 >= 55 && y3 >= 55)
   {
      printf("Sva tri studenta su polozila.");
   }
   if (o1 != 5 && o2 != 5 && o3 != 5)
   {
      if (o1 == o2 && o2 == o3)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      if ((o1 == o2 && o2 != o3) || (o1 == o3 && o1 != o2) || (o2 == o3 && o2 != o1))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      if (o1 != o2 && o1 != o3)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   else
   {
      return(0);
   }
}
