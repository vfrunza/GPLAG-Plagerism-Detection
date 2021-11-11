#include <stdio.h>

int main()
{
   double tp1, tp2, tzd, tz, tp, bp1, bp2, bzd, bz, bp, mp1, mp2, mzd, mz, mp, o1, o2, o3;
   int    brojac = 0;
   int    oc1, oc2, oc3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &tp1);
   if (tp1 < 0 || tp1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &tp2);
   if (tp2 < 0 || tp2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &tp);
   if (tp < 0 || tp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &tzd);
   if (tzd < 0 || tzd > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &tz);
   if (tz < 0 || tz > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   o1 = tp1 + tp2 + tzd + tp + tz;
   if (o1 >= 55)
   {
      brojac++;
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &bp1);
   if (bp1 < 0 || bp1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &bp2);
   if (bp2 < 0 || bp2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &bp);
   if (bp < 0 || bp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &bzd);
   if (bzd < 0 || bzd > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bz);
   if (bz < 0 || bz > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   o2 = bp1 + bp2 + bzd + bp + bz;
   if (o2 >= 55)
   {
      brojac++;
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &mp1);
   if (mp1 < 0 || mp1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &mp2);
   if (mp2 < 0 || mp2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &mp);
   if (mp < 0 || mp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &mzd);
   if (mzd < 0 || mzd > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &mz);
   if (mz < 0 || mz > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   o3 = mp1 + mp2 + mzd + mp + mz;
   if (o3 >= 55)
   {
      brojac++;
   }

   if (brojac == 3)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   if (brojac == 2)
   {
      printf("Dva studenta su polozila.\n");
   }
   if (brojac == 1)
   {
      printf("Jedan student je polozio.\n");
   }
   if (brojac == 0)
   {
      printf("Nijedan student nije polozio.\n");
   }

   if (o1 <= 55)
   {
      oc1 = 0;
   }
   if (o1 > 55 && o1 < 65)
   {
      oc1 = 6;
   }
   if (o1 >= 65 && o1 < 75)
   {
      oc1 = 7;
   }
   if (o1 >= 75 && o1 < 85)
   {
      oc1 = 8;
   }
   if (o1 >= 85 && o1 < 92)
   {
      oc1 = 9;
   }
   if (o1 >= 92 && o1 <= 100)
   {
      oc1 = 10;
   }

   if (o2 <= 55)
   {
      oc2 = 0;
   }
   if (o2 > 55 && o2 < 65)
   {
      oc2 = 6;
   }
   if (o2 >= 65 && o2 < 75)
   {
      oc2 = 7;
   }
   if (o2 >= 75 && o2 < 85)
   {
      oc2 = 8;
   }
   if (o2 >= 85 && o2 < 92)
   {
      oc2 = 9;
   }
   if (o2 >= 92 && o2 <= 100)
   {
      oc2 = 10;
   }

   if (o3 <= 55)
   {
      oc3 = 0;
   }
   if (o3 > 55 && o3 < 65)
   {
      oc3 = 6;
   }
   if (o3 >= 65 && o3 < 75)
   {
      oc3 = 7;
   }
   if (o3 >= 75 && o3 < 85)
   {
      oc3 = 8;
   }
   if (o3 >= 85 && o3 < 92)
   {
      oc3 = 9;
   }
   if (o3 >= 92 && o3 <= 100)
   {
      oc3 = 10;
   }

   if (oc1 == 0 && oc2 == 0 && oc3 == 0)
   {
      return(0);
   }
   if ((oc1 >= 6 && oc2 < 6 && oc3 < 6) || (oc2 >= 6 && oc1 < 6 && oc3 < 6) || (oc3 >= 6 && oc2 < 6 && oc1 < 6))
   {
      return(0);
   }
   if (brojac == 3)
   {
      if (oc1 == oc2 && oc2 == oc3 && oc1 == oc3)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      if ((oc1 == oc2 && oc1 != oc3) || (oc2 == oc3 && oc1 != oc2) || (oc3 == oc1 && oc3 != oc2))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (oc1 != oc2 && oc2 != oc3)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
      return(0);
   }
   return(0);
}
