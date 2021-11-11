#include <stdio.h>
#include <math.h>
#define EPSILON    0.0001
int main()
{
   double t1, t2, tp, tz, tzi, b1, b2, bp, bz, bzi, m1, m2, mp, mz, mzi, ts, bs, ms, x, y, z;
   int    k;

   k = 0;
   /* Tarik */
   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: "); scanf("%lf", &t1); if (t1 < 0 || t1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &t2); if (t2 < 0 || t2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &tp); if (tp < 0 || tp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: "); scanf("%lf", &tz); if (tz < 0 || tz > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &tzi); if (tzi < 0 || tzi > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ts = t1 + t2 + tz + tzi + tp;
   if (ts < 55)
   {
      x = 5;
   }
   if (t1 + t2 + tz + tzi + tp >= 55 && ts < 65)
   {
      x = 6; k = 1;
   }
   if (ts >= 65 && ts < 75)
   {
      x = 7; k = 1;
   }
   if (ts >= 75 && ts < 85)
   {
      x = 8; k = 1;
   }
   if (ts >= 85 && ts < 92)
   {
      x = 9; k = 1;
   }
   if (ts >= 92)
   {
      x = 10; k = 1;
   }
   /* Bojan */
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: "); scanf("%lf", &b1); if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &b2); if (b2 < 0 || b2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &bp); if (bp < 0 || bp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: "); scanf("%lf", &bz); if (bz < 0 || bz > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &bzi); if (bzi < 0 || bzi > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   bs = b1 + b2 + bz + bzi + bp;
   if (bs < 55)
   {
      y = 5;
   }
   if (bs >= 55 && bs < 65)
   {
      y = 6; k = k + 1;
   }
   if (bs >= 65 && bs < 75)
   {
      y = 7; k = k + 1;
   }
   if (bs >= 75 && bs < 85)
   {
      y = 8; k = k + 1;
   }
   if (bs >= 85 && bs < 92)
   {
      y = 9; k = k + 1;
   }
   if (bs >= 92)
   {
      y = 10; k = k + 1;
   }
   /* Mirza */
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: "); scanf("%lf", &m1); if (m1 < 0 || m1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &m2); if (m2 < 0 || m2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &mp); if (mp < 0 || mp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: "); scanf("%lf", &mz); if (mz < 0 || mz > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &mzi); if (mzi < 0 || mzi > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ms = m1 + m2 + mz + mzi + mp;
   if (ms < 55)
   {
      z = 5;
   }
   if (ms >= 55 && ms < 65)
   {
      z = 6; k = k + 1;
   }
   if (ms >= 65 && ms < 75)
   {
      z = 7; k = k + 1;
   }
   if (ms >= 75 && ms < 85)
   {
      z = 8; k = k + 1;
   }
   if (ms >= 85 && ms < 92)
   {
      z = 9; k = k + 1;
   }
   if (ms >= 92)
   {
      z = 10; k = k + 1;
   }
   switch (k)
   {
   case 0:
      printf("Nijedan student nije polozio.");
      return(0);

      break;

   case 1:
      printf("Jedan student je polozio.\n");
      break;

   case 2:
      printf("Dva studenta su polozila.\n");
      break;

   case 3:
      printf("Sva tri studenta su polozila.\n");
      break;
   }
   if ((fabs(k - 3)) > EPSILON)
   {
      return(0);
   }
   if (fabs(x - y) < EPSILON && fabs(y - z) < EPSILON)
   {
      printf("Sva tri studenta imaju istu ocjenu."); return(0);
   }
   if (fabs(x - y) < EPSILON || fabs(x - z) < EPSILON || fabs(y - z) < EPSILON)
   {
      printf("Dva od tri studenta imaju istu ocjenu.");
   }
   if (fabs(x - y) > EPSILON && fabs(x - z) > EPSILON && fabs(y - z) > EPSILON)
   {
      printf("Svaki student ima razlicitu ocjenu.");
   }



   return(0);
}
