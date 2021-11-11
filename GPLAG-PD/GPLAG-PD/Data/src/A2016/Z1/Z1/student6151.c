#include <stdio.h>

int main()
{
   double a, b, c, d, e, f, g, h, i, j, k, l, m, n, o;
   int    x, y, z, ocjena1, ocjena2, ocjena3;


   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &a);
   if (a < 0 || a > 20)
   {
      printf("Neispravan broj bodova"); return(1);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &b);
   if (b < 0 || b > 20)
   {
      printf("Neispravan broj bodova"); return(1);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c);
   if (c < 0 || c > 10)
   {
      printf("Neispravan broj bodova"); return(1);
   }
   printf("Zadace: ");
   scanf("%lf", &d);
   if (d < 0 || d > 10)
   {
      printf("Neispravan broj bodova"); return(1);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e);
   if (e < 0 || e > 40)
   {
      printf("Neispravan broj bodova"); return(1);
   }


   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &f);
   if (f < 0 || f > 20)
   {
      printf("Neispravan broj bodova"); return(1);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &g);
   if (g < 0 || g > 20)
   {
      printf("Neispravan broj bodova"); return(1);
   }
   printf("Prisustvo: ");
   scanf("%lf", &h);
   if (h < 0 || h > 10)
   {
      printf("Neispravan broj bodova"); return(1);
   }
   printf("Zadace: ");
   scanf("%lf", &i);
   if (i < 0 || i > 10)
   {
      printf("Neispravan broj bodova"); return(1);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &j);
   if (j < 0 || j > 40)
   {
      printf("Neispravan broj bodova"); return(1);
   }


   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &k);
   if (k < 0 || k > 20)
   {
      printf("Neispravan broj bodova"); return(1);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &l);
   if (l < 0 || l > 20)
   {
      printf("Neispravan broj bodova"); return(1);
   }
   printf("Prisustvo: ");
   scanf("%lf", &m);
   if (m < 0 || m > 10)
   {
      printf("Neispravan broj bodova"); return(1);
   }
   printf("Zadace: ");
   scanf("%lf", &n);
   if (n < 0 || n > 10)
   {
      printf("Neispravan broj bodova"); return(1);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &o);
   if (o < 0 || o > 40)
   {
      printf("Neispravan broj bodova"); return(1);
   }


   z = a + b + c + d + e;

   x = f + g + h + j + i;

   y = k + l + m + n + o;


   if (x >= 55 && z >= 55 && y >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
   }

   else if ((z >= 55 && x >= 55 && y < 55) || (z >= 55 && y >= 55 && x < 55) || (x >= 55 && y >= 55 && z < 55))
   {
      printf("Dva studenta su polozila.\n");
   }

   else if ((z >= 55 && x < 55 && y < 55) || (z < 55 && y >= 55 && x < 55) || (x >= 55 && y < 55 && z < 55))
   {
      printf("Jedan student je polozio.\n");
   }

   else
   {
      printf("Nijedan student nije polozio.\n");
   }

   if (z >= 55 && z < 65)
   {
      ocjena1 = 6;
   }

   if (z >= 65 && z < 75)
   {
      ocjena1 = 7;
   }

   if (z >= 75 && z < 85)
   {
      ocjena1 = 8;
   }

   if (z >= 85 && z < 92)
   {
      ocjena1 = 9;
   }

   if (z >= 92 && z < 100)
   {
      ocjena1 = 10;
   }



   if (x >= 55 && x < 65)
   {
      ocjena2 = 6;
   }

   if (x >= 65 && x < 75)
   {
      ocjena2 = 7;
   }

   if (x >= 75 && x < 85)
   {
      ocjena2 = 8;
   }

   if (x >= 85 && x < 92)
   {
      ocjena2 = 9;
   }

   if (x >= 92 && x < 100)
   {
      ocjena2 = 10;
   }


   if (y >= 55 && y < 65)
   {
      ocjena3 = 6;
   }

   if (y >= 65 && y < 75)
   {
      ocjena3 = 7;
   }

   if (y >= 75 && y < 85)
   {
      ocjena3 = 8;
   }

   if (y >= 85 && y < 92)
   {
      ocjena3 = 9;
   }

   if (y >= 92 && y < 100)
   {
      ocjena3 = 10;
   }

   if (x >= 55 && z >= 55 && y >= 55)
   {
      if (ocjena1 == ocjena2 && ocjena2 == ocjena3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }

      else if ((ocjena1 == ocjena2 && ocjena1 != ocjena3) || (ocjena2 == ocjena3 && ocjena1 != ocjena3) || (ocjena1 == ocjena3 && ocjena2 != ocjena3))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }

      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
