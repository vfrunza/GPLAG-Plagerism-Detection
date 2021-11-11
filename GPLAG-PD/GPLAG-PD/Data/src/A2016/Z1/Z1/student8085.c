#include <stdio.h>
#define PI1    20 /*Maksimalan broj bodova na prvom parcijalnom ispitu*/
#define PI2    20 /*Maksimalan broj bodova na drugom parcijalnom ispitu*/
#define P      10 /*Maksimalan broj bodova za prisustvo*/
#define Z      10 /*Maksimalan broj bodova za zadace*/
#define ZI     40 /*Maksimalan broj bodova na zavrsnom ispitu*/
int main()
{
   float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, B1, B2, B3;
   int   O1, O2, O3;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &a);
   if (a < 0 || a > PI1)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &b);
   if (b < 0 || b > PI2)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &c);
   if (c < 0 || c > P)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &d);
   if (d < 0 || d > Z)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &e);
   if (e < 0 || e > ZI)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &f);
   if (f < 0 || f > PI1)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &g);
   if (g < 0 || g > PI2)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &h);
   if (h < 0 || h > P)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &i);
   if (i < 0 || i > Z)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &j);
   if (j < 0 || j > ZI)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &k);
   if (k < 0 || k > PI1)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &l);
   if (l < 0 || l > PI2)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &m);
   if (m < 0 || m > P)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &n);
   if (n < 0 || n > Z)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &o);
   if (o < 0 || o > ZI)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }


   B1 = (double)a + b + c + d + e;
   B2 = (double)f + g + h + i + j;
   B3 = (double)k + l + m + n + o;
   if (B1 >= 55 && B1 < 65)
   {
      O1 = 6;
   }
   if (B1 >= 65 && B1 < 75)
   {
      O1 = 7;
   }
   if (B1 >= 75 && B1 < 85)
   {
      O1 = 8;
   }
   if (B1 >= 85 && B1 < 92)
   {
      O1 = 9;
   }
   if (B1 >= 92 && B1 <= 100)
   {
      O1 = 10;
   }
   if (B2 >= 55 && B2 < 65)
   {
      O2 = 6;
   }
   if (B2 >= 65 && B2 < 75)
   {
      O2 = 7;
   }
   if (B2 >= 75 && B2 < 85)
   {
      O2 = 8;
   }
   if (B2 >= 85 && B2 < 92)
   {
      O2 = 9;
   }
   if (B2 >= 92 && B2 <= 100)
   {
      O2 = 10;
   }
   if (B3 >= 55 && B3 < 65)
   {
      O3 = 6;
   }
   if (B3 >= 65 && B3 < 75)
   {
      O3 = 7;
   }
   if (B3 >= 75 && B3 < 85)
   {
      O3 = 8;
   }
   if (B3 >= 85 && B3 < 92)
   {
      O3 = 9;
   }
   if (B3 >= 92 && B3 <= 100)
   {
      O3 = 10;
   }

   if (B1 < 55 && B2 < 55 && B3 < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (B1 < 55 && B2 < 55 && (B3 >= 55 && B3 <= 100))
   {
      printf("Jedan student je polozio.");
   }
   else if (B1 < 55 && B3 < 55 && B2 >= 55 && B2 <= 100)
   {
      printf("Jedan student je polozio.");
   }
   else if (B2 < 55 && B3 < 55 && B1 >= 55 && B3 <= 100)
   {
      printf("Jedan student je polozio.");
   }
   else if (B1 < 55 && (B2 >= 55 && B2 <= 100) && (B3 >= 55 && B3 <= 100))
   {
      printf("Dva studenta su polozila.");
   }
   else if (B2 < 55 && (B1 >= 55 && B1 <= 100) && (B3 >= 55 && B3 <= 100))
   {
      printf("Dva studenta su polozila.");
   }
   else if (B3 < 55 && (B1 >= 55 && B1 <= 100) && (B2 >= 55 && B2 <= 100))
   {
      printf("Dva studenta su polozila.");
      return(0);
   }

   if ((B1 >= 55 && B1 <= 100) && (B2 >= 55 && B2 <= 100) && (B3 >= 55 && B3 <= 100))
   {
      printf("Sva tri studenta su polozila.\n");
      if (O1 == O2 && O1 == O3 && O2 == O3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (O1 == O2 && O1 != O3 && O2 != O3)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (O1 == O3 && O1 != O2 && O3 != O2)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (O2 == O3 && O2 != O1 && O3 != O1)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (O1 != O2 && O1 != O3 && O2 != O3)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
