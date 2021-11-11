#include <stdio.h>

int main()
{
   double T1, B1, M1, T2, B2, M2, TP, TZ, BP, BZ, MP, MZ, TZI, MZI, BZI;
   double MU, TU, BU;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
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
   scanf("%lf", &TP);
   if (TP < 0 || TP > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &TZ);
   if (TZ < 0 || TZ > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &TZI);
   if (TZI < 0 || TZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   TU = T1 + T2 + TP + TZ + TZI;

   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &B1);
   if (B1 < 0 || B1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &B2);
   if (B1 < 0 || B2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &BP);
   if (BP < 0 || BP > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &BZ);
   if (BZ < 0 || BZ > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &BZI);
   if (BZI < 0 || BZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   BU = B1 + B2 + BP + BZ + BZI;

   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
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
   scanf("%lf", &MP);
   if (MP < 0 || MP > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &MZ);
   if (MZ < 0 || MZ > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &MZI);
   if (MZI < 0 || MZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   MU = M1 + M2 + MP + MZ + MZI;

   if (TU < 55 && MU < 55 && BU < 55)
   {
      printf("Nijedan student nije polozio.");
   }

   else if (TU < 55 && MU < 55 && BU >= 55)
   {
      printf("Jedan student je polozio.");
   }

   else if (TU < 55 && MU >= 55 && BU < 55)
   {
      printf("Jedan student je polozio.");
   }

   else if (TU >= 55 && MU < 55 && BU < 55)
   {
      printf("Jedan student je polozio.");
   }

   else if (TU < 55 && MU >= 55 && BU >= 55)
   {
      printf("Dva studenta su polozila.");
   }

   else if (TU >= 55 && MU >= 55 && BU < 55)
   {
      printf("Dva studenta su polozila.");
   }

   else if (TU >= 55 && MU < 55 && BU >= 55)
   {
      printf("Dva studenta su polozila.");
   }


   else if (TU >= 55 && MU >= 55 && BU >= 55)
   {
      printf("Sva tri studenta su polozila.");

      if (TU >= 55 && TU < 65 && BU >= 55 && BU < 65 && MU > 65)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 65 && TU < 75 && BU >= 65 && BU < 75 && MU >= 55 && MU < 65)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 65 && TU < 75 && BU >= 65 && BU < 75 && MU >= 75 && MU <= 100)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 75 && TU < 85 && BU >= 75 && BU < 85 && MU >= 55 && MU < 75)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 75 && TU < 85 && BU >= 75 && BU < 85 && MU >= 85 && MU <= 100)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 85 && TU < 92 && BU >= 85 && BU < 92 && MU >= 55 && MU < 85)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 85 && TU < 92 && BU >= 85 && BU < 92 && MU >= 92 && MU < 100)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 92 && TU <= 100 && BU >= 92 && BU <= 100 && MU >= 55 && MU < 92)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }

      else if (TU >= 55 && TU < 65 && MU >= 55 && MU < 65 && TU > 65)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 65 && TU < 75 && MU >= 65 && MU < 75 && TU >= 55 && TU < 65)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 65 && TU < 75 && MU >= 65 && MU < 75 && TU >= 75 && TU <= 100)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 75 && TU < 85 && MU >= 75 && MU < 85 && TU >= 55 && TU < 75)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 75 && TU < 85 && MU >= 75 && MU < 85 && TU >= 85 && TU <= 100)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 85 && TU < 92 && MU >= 85 && MU < 92 && TU >= 55 && TU < 85)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 85 && TU < 92 && MU >= 85 && MU < 92 && TU >= 92 && TU < 100)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (TU >= 92 && TU <= 100 && MU >= 92 && MU <= 100 && TU >= 55 && TU < 92)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }

      else if (MU >= 55 && MU < 65 && BU >= 55 && BU < 65 && TU > 65)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (MU >= 65 && MU < 75 && BU >= 65 && BU < 75 && TU >= 55 && TU < 65)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (MU >= 65 && MU < 75 && BU >= 65 && BU < 75 && TU >= 75 && TU <= 100)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (MU >= 75 && MU < 85 && BU >= 75 && BU < 85 && TU >= 55 && TU < 75)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (MU >= 75 && MU < 85 && BU >= 75 && BU < 85 && TU >= 85 && TU <= 100)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (MU >= 85 && MU < 92 && BU >= 85 && BU < 92 && TU >= 55 && TU < 85)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (MU >= 85 && MU < 92 && BU >= 85 && BU < 92 && TU >= 92 && TU < 100)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (MU >= 92 && MU <= 100 && BU >= 92 && BU <= 100 && TU >= 55 && TU < 92)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }

      else if (MU >= 55 && MU < 65 && BU >= 55 && BU < 65 && TU >= 55 && TU < 65)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (MU >= 65 && MU < 75 && BU >= 65 && BU < 75 && TU >= 65 && TU < 75)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (MU >= 75 && MU < 85 && BU >= 75 && BU < 85 && TU >= 75 && TU < 85)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (MU >= 85 && MU < 92 && BU >= 85 && BU < 92 && TU >= 85 && TU < 92)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (MU >= 92 && MU <= 100 && BU >= 92 && BU <= 100 && TU >= 92 && TU <= 100)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }

      else
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
