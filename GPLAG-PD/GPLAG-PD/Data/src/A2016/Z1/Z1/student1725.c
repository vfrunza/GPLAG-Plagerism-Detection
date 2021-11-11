#include <stdio.h>

int main()
{
   float t1p, t2p, tp, tz, tzp, b1p, b2p, bp, bz, bzp, m1p, m2p, mp, mz, mzp, M, B, T, TO = 0, BO = 0, MO = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &t1p);
   if (t1p < 0 || t1p > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &t2p);
   if (t2p < 0 || t2p > 20)
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
   scanf("%f", &tzp);
   if (tzp < 0 || tzp > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &b1p);
   if (b1p < 0 || b1p > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &b2p);
   if (b2p < 0 || b2p > 20)
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
   scanf("%f", &bzp);
   if (bzp < 0 || bzp > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &m1p);
   if (m1p < 0 || m1p > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &m2p);
   if (m2p < 0 || m2p > 20)
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
   scanf("%f", &mzp);
   if (mzp < 0 || mzp > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   T = t1p + t2p + tp + tz + tzp;
   B = b1p + b2p + bp + bz + bzp;
   M = m1p + m2p + mp + mz + mzp;



   if (T >= 55 && B >= 55 && M >= 55)
   {
      printf("Sva tri studenta su polozila.\n");

      if (T >= 55 && T < 65)
      {
         TO = 6;
      }
      else if (T >= 65 && T < 75)
      {
         TO = 7;
      }
      else if (T >= 75 && T < 85)
      {
         TO = 8;
      }
      else if (T >= 85 && T < 92)
      {
         TO = 9;
      }
      else
      {
         TO = 10;
      }

      if (B >= 55 && B < 65)
      {
         BO = 6;
      }
      else if (B >= 65 && B < 75)
      {
         BO = 7;
      }
      else if (B >= 75 && B < 85)
      {
         BO = 8;
      }
      else if (B >= 85 && B < 92)
      {
         BO = 9;
      }
      else
      {
         BO = 10;
      }

      if (M >= 55 && M < 65)
      {
         MO = 6;
      }
      else if (M >= 65 && M < 75)
      {
         MO = 7;
      }
      else if (M >= 75 && M < 85)
      {
         MO = 8;
      }
      else if (M >= 85 && M < 92)
      {
         MO = 9;
      }
      else
      {
         MO = 10;
      }


      if (TO == BO && TO == MO)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((TO == BO && TO != MO) || (TO == MO && TO != BO) || (BO == MO && BO != TO))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   else if (T >= 55 && B >= 55 && M < 55)
   {
      printf("Dva studenta su polozila.");
   }
   else if (T >= 55 && B < 55 && M >= 55)
   {
      printf("Dva studenta su polozila.");
   }
   else if (T < 55 && B >= 55 && M >= 55)
   {
      printf("Dva studenta su polozila.");
   }
   else if (T >= 54.9 && B < 55 && M < 55)
   {
      printf("Jedan student je polozio.");
   }
   else if (T < 55 && B >= 55 && M < 55)
   {
      printf("Jedan student je polozio.");
   }
   else if (T < 55 && B < 55 && M >= 55)
   {
      printf("Jedan student je polozio.");
   }
   else if (T < 55 && B < 55 && M < 55)
   {
      printf("Nijedan student nije polozio.");
   }


   return(0);
}
