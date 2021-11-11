#include <stdio.h>
#include <math.h>
int main()
{
   float tp1, tp2, tz, tpr, tzad, bp1, bp2, bz, bpr, bzad, mp1, mp2, mz, mpr, mzad, T, B, M;
   int   t, b, m;

   printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
   scanf("%f", &tp1);
   if (tp1 < 0.00 || tp1 > 20.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &tp2);
   if (tp2 < 0.00 || tp2 > 20.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &tpr);
   if (tpr < 0.00 || tpr > 10.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &tzad);
   if (tzad < 0.00 || tzad > 10.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &tz);
   if (tz < 0.00 || tz > 40.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
   scanf("%f", &bp1);
   if (bp1 < 0.00 || bp1 > 20.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &bp2);
   if (bp2 < 0.00 || bp2 > 20.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &bpr);
   if (bpr < 0.00 || bpr > 10.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &bzad);
   if (bzad < 0.00 || bzad > 10.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &bz);
   if (bz < 0.00 || bz > 40.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
   scanf("%f", &mp1);
   if (mp1 < 0.00 || mp1 > 20.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &mp2);
   if (mp2 < 0.00 || mp2 > 20.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &mpr);
   if (mpr < 0.00 || mpr > 10.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &mzad);
   if (mzad < 0.00 || mzad > 10.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &mz);
   if (mz < 0.00 || mz > 40.00)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   T = tp1 + tp2 + tpr + tz + tzad;
   B = bp1 + bp2 + bpr + bz + bzad;
   M = mp1 + mp2 + mpr + mz + mzad;
   t = (int)T;
   b = (int)B;
   m = (int)M;
   if (t < 55)
   {
      t = 5;
   }
   else if (t >= 55 && t < 65)
   {
      t = 6;
   }
   else if (t >= 65 && t < 75)
   {
      t = 7;
   }
   else if (t >= 75 && t < 85)
   {
      t = 8;
   }
   else if (t >= 85 && t < 92)
   {
      t = 9;
   }
   else if (t >= 92 && t <= 100)
   {
      t = 10;
   }
   if (b < 55)
   {
      b = 5;
   }
   else if (b >= 55 && b < 65)
   {
      b = 6;
   }
   else if (b >= 65 && b < 75)
   {
      b = 7;
   }
   else if (b >= 75 && b < 85)
   {
      b = 8;
   }
   else if (b >= 85 && b < 92)
   {
      b = 9;
   }
   else if (b >= 92 && b <= 100)
   {
      b = 10;
   }
   if (m < 55)
   {
      m = 5;
   }
   else if (m >= 55 && m < 65)
   {
      m = 6;
   }
   else if (m >= 65 && m < 75)
   {
      m = 7;
   }
   else if (m >= 75 && m < 85)
   {
      m = 8;
   }
   else if (m >= 85 && m < 92)
   {
      m = 9;
   }
   else if (m >= 92 && m <= 100)
   {
      m = 10;
   }
   if (t >= 6 && b >= 6 && m >= 6)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else if (t == 5 && b == 5 && m == 5)
   {
      printf("Nijedan student nije polozio.\n");
      return(0);
   }
   else if ((t > 5 && b > 5 && m == 5) || (t > 5 && m > 5 && b == 5) || (m > 5 && b > 5 && t == 5))
   {
      printf("Dva studenta su polozila.\n");
      return(0);
   }
   else if ((t >= 6 && b == 5 && m == 5) || (m >= 6 && b == 5 && t == 5) || (b >= 6 && m == 5 && t == 5))
   {
      printf("Jedan student je polozio.\n");
      return(0);
   }
   if (t == m && m == b)
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
   }
   else if ((t == m && m != b) || (t == b && b != m) || (b == m && m != t))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if (t != m && m != b && t != b)
   {
      printf("Svaki student ima razlicitu ocjenu.\n");
   }
   return(0);
}
