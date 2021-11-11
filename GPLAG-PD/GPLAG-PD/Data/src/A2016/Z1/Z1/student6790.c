#include <stdio.h>

int main()
{
   float tp1, tp2, tp, tz, tzi, mp1, mp2, mp, mz, mzi, bp1, bp2, bp, bz, bzi, tuk, buk, muk;
   int   o1, o2, o3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &tp1);
   if (tp1 < 0 || tp1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &tp2);
   if (tp2 < 0 || tp2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &tp);
   if (tp < 0 || tp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &tz);
   if (tz < 0 || tz > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &tzi);
   if (tzi < 0 || tzi > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }


   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &bp1);
   if (bp1 < 0 || bp1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &bp2);
   if (bp2 < 0 || bp2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &bp);
   if (bp < 0 || bp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &bz);
   if (bz < 0 || bz > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &bzi);
   if (bzi < 0 || bzi > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }


   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &mp1);
   if (mp1 < 0 || mp1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &mp2);
   if (mp2 < 0 || mp2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &mp);
   if (mp < 0 || mp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &mz);
   if (mz < 0 || mz > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &mzi);
   if (mzi < 0 || mzi > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }


   tuk = tp1 + tp2 + tp + tz + tzi;
   buk = bp1 + bp2 + bp + bz + bzi;
   muk = mp1 + mp2 + mp + mz + mzi;

   if (tuk < 55)
   {
      o1 = 5;
   }
   else if (tuk >= 55 && tuk < 65)
   {
      o1 = 6;
   }
   else if (tuk >= 65 && tuk < 75)
   {
      o1 = 7;
   }
   else if (tuk >= 75 && tuk < 85)
   {
      o1 = 8;
   }
   else if (tuk >= 85 && tuk < 92)
   {
      o1 = 9;
   }
   else
   {
      o1 = 10;
   }

   if (buk < 55)
   {
      o2 = 5;
   }
   else if (buk >= 55 && buk < 65)
   {
      o2 = 6;
   }
   else if (buk >= 65 && buk < 75)
   {
      o2 = 7;
   }
   else if (buk >= 75 && buk < 85)
   {
      o2 = 8;
   }
   else if (buk >= 85 && buk < 92)
   {
      o2 = 9;
   }
   else
   {
      o2 = 10;
   }

   if (muk < 55)
   {
      o3 = 5;
   }
   else if (muk >= 55 && muk < 65)
   {
      o3 = 6;
   }
   else if (muk >= 65 && muk < 75)
   {
      o3 = 7;
   }
   else if (muk >= 75 && muk < 85)
   {
      o3 = 8;
   }
   else if (muk >= 85 && muk < 92)
   {
      o3 = 9;
   }
   else
   {
      o3 = 10;
   }

   if (o1 > 5 && o2 > 5 && o3 > 5)
   {
      printf("Sva tri studenta su polozila.");
   }
   else if (o1 == 5 && o2 == 5 && o3 == 5)
   {
      printf("Nijedan student nije polozio.");
      return(0);
   }
   else if (o1 == 6)
   {
      if (o2 == 5 && o3 == 5)
      {
         printf("Jedan student je polozio.");
      }
      else
      {
         printf("Dva studenta su polozila.");
      }
      return(0);
   }
   else if (o2 == 6)
   {
      if (o1 == 5 && o3 == 5)
      {
         printf("Jedan student je polozio.");
      }
      else
      {
         printf("Dva studenta su polozila.");
      }
      return(0);
   }
   else
   {
      if (o2 == 5 && o1 == 5)
      {
         printf("Jedan student je polozio.");
      }
      else
      {
         printf("Dva studenta su polozila.");
      }
      return(0);
   }



   if (((o1 == o2) && o1 != o3) || ((o1 == o3) && o1 != o2) || ((o2 == o3) && o2 != o1))
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
      return(0);
   }
   if (o1 != o2 && o1 != o3 && o2 != o3)
   {
      printf("\nSvaki student ima razlicitu ocjenu.");
      return(0);
   }
   else
   {
      printf("\nSva tri studenta imaju istu ocjenu.");
   }
   return(0);
}
