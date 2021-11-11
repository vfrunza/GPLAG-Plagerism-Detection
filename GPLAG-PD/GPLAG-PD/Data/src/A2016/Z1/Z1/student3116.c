#include <stdio.h>

int main()
{
   double T1, T2, Tp, Tz, Ti, B1, B2, Bp, Bz, Bi, M1, M2, Mp, Mz, Mi, Tu, Bu, Mu;
   int    o6 = 0, o7 = 0, o8 = 0, o9 = 0, o10 = 0, BrojPalih = 0;

   /* ------- TARIK ------- */

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &T1);
   if (T1 < 0 || T1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &T2);
   if (T2 < 0 || T2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &Tp);
   if (Tp < 0 || Tp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &Tz);
   if (Tz < 0 || Tz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &Ti);
   if (Ti < 0 || Ti > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   /* ------- BOJAN ------- */

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &B1);
   if (B1 < 0 || B1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &B2);
   if (B2 < 0 || B2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &Bp);
   if (Bp < 0 || Bp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &Bz);
   if (Bz < 0 || Bz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &Bi);
   if (Bi < 0 || Bi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   /* ------- MIRZA ------- */

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &M1);
   if (M1 < 0 || M1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &M2);
   if (M2 < 0 || M2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &Mp);
   if (Mp < 0 || Mp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &Mz);
   if (Mz < 0 || Mz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &Mi);
   if (Mi < 0 || Mi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   Tu = T1 + T2 + Tp + Tz + Ti;
   Bu = B1 + B2 + Bp + Bz + Bi;
   Mu = M1 + M2 + Mp + Mz + Mi;

   if (Tu < 55)
   {
      BrojPalih++;
   }
   else if (Tu < 65)
   {
      o6++;
   }
   else if (Tu < 75)
   {
      o7++;
   }
   else if (Tu < 85)
   {
      o8++;
   }
   else if (Tu < 92)
   {
      o9++;
   }
   else
   {
      o10++;
   }

   if (Bu < 55)
   {
      BrojPalih++;
   }
   else if (Bu < 65)
   {
      o6++;
   }
   else if (Bu < 75)
   {
      o7++;
   }
   else if (Bu < 85)
   {
      o8++;
   }
   else if (Bu < 92)
   {
      o9++;
   }
   else
   {
      o10++;
   }

   if (Mu < 55)
   {
      BrojPalih++;
   }
   else if (Mu < 65)
   {
      o6++;
   }
   else if (Mu < 75)
   {
      o7++;
   }
   else if (Mu < 85)
   {
      o8++;
   }
   else if (Mu < 92)
   {
      o9++;
   }
   else
   {
      o10++;
   }

   if (BrojPalih == 3)
   {
      printf("Nijedan student nije polozio."); return(0);
   }
   else if (BrojPalih == 2)
   {
      printf("Jedan student je polozio."); return(0);
   }
   else if (BrojPalih == 1)
   {
      printf("Dva studenta su polozila."); return(0);
   }
   else if (BrojPalih == 0)
   {
      printf("Sva tri studenta su polozila.");
   }


   if (o6 == 3 || o7 == 3 || o8 == 3 || o9 == 3 || o10 == 3)
   {
      printf("\nSva tri studenta imaju istu ocjenu.");
   }
   else if (o6 == 2 || o7 == 2 || o8 == 2 || o9 == 2 || o10 == 2)
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else
   {
      printf("\nSvaki student ima razlicitu ocjenu.");
   }

   return(0);
}
