#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PARC1      20
#define PARC2      20
#define PRIS       10
#define ZAD        10
#define ZAVRSNI    40

int main()
{
   float        T1, T2, Tpr, Tzad, Tzav, B1, B2, Bpr, Bzad, Bzav, M1, M2, Mpr, Mzad, Mzav;
   float        sumaT = 0, sumaB = 0, sumaM = 0;
   int          ocjena1, ocjena2, ocjena3;
   double const EpSiLoN = 1e-5;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &T1);
   if (T1 < 0 || T1 > PARC1)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &T2);
   if (T2 < 0 || T2 > PARC2)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Tpr);
   if (Tpr < 0 || Tpr > PRIS)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Tzad);
   if (Tzad < 0 || Tzad > ZAD)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Tzav);
   if (Tzav < 0 || Tzav > ZAVRSNI)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   sumaT = T1 + T2 + Tpr + Tzad + Tzav;

   if (sumaT < 55)
   {
      ocjena1 = 5;
   }
   else if (sumaT > 55 - EpSiLoN && sumaT < 65 - EpSiLoN)
   {
      ocjena1 = 6;
   }
   else if (sumaT > 65 - EpSiLoN && sumaT < 75 - EpSiLoN)
   {
      ocjena1 = 7;
   }
   else if (sumaT > 75 - EpSiLoN && sumaT < 85 - EpSiLoN)
   {
      ocjena1 = 8;
   }
   else if (sumaT > 85 - EpSiLoN && sumaT < 92 - EpSiLoN)
   {
      ocjena1 = 9;
   }
   else
   {
      ocjena1 = 10;
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &B1);
   if (B1 < 0 || B1 > PARC1)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &B2);
   if (B2 < 0 || B2 > PARC2)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Bpr);
   if (Bpr < 0 || Bpr > PRIS)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Bzad);
   if (Bzad < 0 || Bzad > ZAD)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Bzav);
   if (Bzav < 0 || Bzav > ZAVRSNI)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   sumaB = B1 + B2 + Bpr + Bzad + Bzav;

   if (sumaB < 55)
   {
      ocjena2 = 5;
   }
   else if (sumaB > 55 - EpSiLoN && sumaB < 65 - EpSiLoN)
   {
      ocjena2 = 6;
   }
   else if (sumaB > 65 - EpSiLoN && sumaB < 75 - EpSiLoN)
   {
      ocjena2 = 7;
   }
   else if (sumaB > 75 - EpSiLoN && sumaB < 85 - EpSiLoN)
   {
      ocjena2 = 8;
   }
   else if (sumaB > 85 - EpSiLoN && sumaB < 92 - EpSiLoN)
   {
      ocjena2 = 9;
   }
   else
   {
      ocjena2 = 10;
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &M1);
   if (M1 < 0 || M1 > PARC1)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &M2);
   if (M2 < 0 || M2 > PARC2)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Mpr);
   if (Mpr < 0 || Mpr > PRIS)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Mzad);
   if (Mzad < 0 || Mzad > ZAD)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Mzav);
   if (Mzav < 0 || Mzav > ZAVRSNI)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   sumaM = M1 + M2 + Mpr + Mzad + Mzav;

   if (sumaM < 55)
   {
      ocjena3 = 5;
   }
   else if (sumaM > 55 - EpSiLoN && sumaM < 65 - EpSiLoN)
   {
      ocjena3 = 6;
   }
   else if (sumaM > 65 - EpSiLoN && sumaM < 75 - EpSiLoN)
   {
      ocjena3 = 7;
   }
   else if (sumaM > 75 - EpSiLoN && sumaM < 85 - EpSiLoN)
   {
      ocjena3 = 8;
   }
   else if (sumaM > 85 - EpSiLoN && sumaM < 92 - EpSiLoN)
   {
      ocjena3 = 9;
   }
   else
   {
      ocjena3 = 10;
   }

   if (sumaT > 55 - EpSiLoN && sumaB > 55 - EpSiLoN && sumaM > 55 - EpSiLoN)
   {
      printf("Sva tri studenta su polozila.\n");
      if (ocjena1 == ocjena2 && ocjena2 == ocjena3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (ocjena1 != ocjena2 && ocjena2 != ocjena3 && ocjena1 != ocjena3)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      else
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }
   else if (sumaT < 55 - EpSiLoN && sumaB < 55 - EpSiLoN && sumaM < 55 - EpSiLoN)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((sumaT > 55 - EpSiLoN && sumaB < 55 - EpSiLoN && sumaM < 55 - EpSiLoN) || (sumaT < 55 - EpSiLoN && sumaB > 55 - EpSiLoN && sumaM < 55 - EpSiLoN) || (sumaT < 55 - EpSiLoN && sumaB < 55 - EpSiLoN && sumaM > 55 - EpSiLoN))
   {
      printf("Jedan student je polozio.");
   }
   else
   {
      printf("Dva studenta su polozila.");
   }

   return(0);
}
