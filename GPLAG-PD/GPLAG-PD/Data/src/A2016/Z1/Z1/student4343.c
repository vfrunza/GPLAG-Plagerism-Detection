#include <stdio.h>
#include <math.h>
int main()
{
   float tpp, tdp, tp, tz, tzav, bpp, bdp, bp, bz, bzav, mpp, mdp, mp, mz, mzav;
   float o1, o2, o3;
   int   m, n;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &tpp);
   if (tpp < 0 || tpp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &tdp);
   if (tdp < 0 || tdp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &tp);
   if (tp < 0 || tp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &tz);
   if (tz < 0 || tz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &tzav);
   if (tzav < 0 || tzav > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana:");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &bpp);
   if (bpp < 0 || bpp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &bdp);
   if (bdp < 0 || bdp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &bp);
   if (bp < 0 || bp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &bz);
   if (bz < 0 || bz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &bzav);
   if (bzav < 0 || bzav > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &mpp);
   if (mpp < 0 || mpp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &mdp);
   if (mdp < 0 || mdp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &mp);
   if (mp < 0 || mp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &mz);
   if (mz < 0 || mz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &mzav);
   if (mzav < 0 || mzav > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   o1 = tpp + tdp + tp + tz + tzav;
   o2 = bpp + bdp + bp + bz + bzav;
   o3 = mpp + mdp + mp + mz + mzav;
   m  = 0;    n = 0;
   if (o1 <= 54.999)
   {
      m++;
   }
   if (o2 <= 54.999)
   {
      m++;
   }
   if (o3 <= 54.999)
   {
      m++;
   }
   if (m == 3)
   {
      printf("Nijedan student nije polozio.");
   }
   if (m == 2)
   {
      printf("Jedan student je polozio.");
   }
   if (m == 1)
   {
      printf("Dva studenta su polozila.");
   }

   if (o1 >= 55 && o1 < 65)
   {
      o1 = 6;
   }
   if (o1 >= 65 && o1 < 75)
   {
      o1 = 7;
   }
   if (o1 >= 75 && o1 < 85)
   {
      o1 = 8;
   }
   if (o1 >= 85 && o1 < 92)
   {
      o1 = 9;
   }
   if (o1 >= 92 && o1 <= 100)
   {
      o1 = 10;
   }

   if (o2 >= 55 && o2 < 65)
   {
      o2 = 6;
   }
   if (o2 >= 65 && o2 < 75)
   {
      o2 = 7;
   }
   if (o2 >= 75 && o2 < 85)
   {
      o2 = 8;
   }
   if (o2 >= 85 && o2 < 92)
   {
      o2 = 9;
   }
   if (o2 >= 92 && o2 <= 100)
   {
      o2 = 10;
   }

   if (o3 >= 55 && o3 < 65)
   {
      o3 = 6;
   }
   if (o3 >= 65 && o3 < 75)
   {
      o3 = 7;
   }
   if (o3 >= 75 && o3 < 85)
   {
      o3 = 8;
   }
   if (o3 >= 85 && o3 < 92)
   {
      o3 = 9;
   }
   if (o3 >= 92 && o3 <= 100)
   {
      o3 = 10;
   }

   if (m == 0)
   {
      printf("Sva tri studenta su polozila.");

      if (o1 > o2 || o1 < o2)
      {
         n++;
      }
      if ((o1 > o3 || o1 < o3) && (o2 < o3 || o2 > o3))
      {
         n++;
      }
      if ((o2 < o3 || o2 > o3) && (o1 < o3 || o1 > o3))
      {
         n++;
      }
      if (n == 0)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      if (n == 2)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      if (n == 3)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
