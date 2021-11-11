/* Zadaca 1, zadatak 1. */

#include <stdio.h>
#include <math.h>
#define eps    0.00001

int main()
{
   float T1P, T2P, TP, TZad, TUsmeni, B1P, B2P, BP, BZad, BUsmeni, M1P, M2P, MP, MZad, MUsmeni, TUkupno, BUkupno, MUkupno;


   /* TARIK UNOS */

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &T1P);
   if (T1P > 20.0 || T1P < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &T2P);
   if (T2P > 20.0 || T2P < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &TP);
   if (TP > 10.0 || TP < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &TZad);
   if (TZad > 10.0 || TZad < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &TUsmeni);
   if (TUsmeni > 40.0 || TUsmeni < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   /* BOJAN UNOS */

   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &B1P);
   if (B1P > 20.0 || B1P < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &B2P);
   if (B2P > 20.0 || B2P < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &BP);
   if (BP > 10.0 || BP < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &BZad);
   if (BZad > 10.0 || BZad < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &BUsmeni);
   if (BUsmeni > 40.0 || BUsmeni < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   /* MIRZA UNOS */

   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &M1P);
   if (M1P > 20.0 || B1P < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &M2P);
   if (M2P > 20.0 || M2P < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &MP);
   if (MP > 10.0 || MP < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &MZad);
   if (MZad > 10.0 || MZad < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &MUsmeni);
   if (MUsmeni > 40.0 || MUsmeni < 0.0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   TUkupno = T1P + T2P + TP + TZad + TUsmeni;
//	printf("\n%f", TUkupno);
   BUkupno = B1P + B2P + BP + BZad + BUsmeni;
   MUkupno = M1P + M2P + MP + MZad + MUsmeni;

   if (fabs((int)TUkupno - TUkupno) > eps)
   {
      //TUkupno = TUkupno * 100;
      //TUkupno = TUkupno + 0.5;
      //TUkupno = TUkupno / 100;

      TUkupno = TUkupno + eps;

      //	printf("\n%f", TUkupno);
   }
   if (fabs((int)BUkupno - BUkupno) > eps)
   {
      BUkupno = BUkupno + eps;
   }
   if (fabs((int)MUkupno - MUkupno) > eps)
   {
      MUkupno = MUkupno + eps;
   }



   if (TUkupno < 55.0 && BUkupno < 55.0 && MUkupno < 55.0)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((TUkupno >= 55.0) && (BUkupno >= 55.0) && (MUkupno >= 55.0))
   {
      printf("Sva tri studenta su polozila.");

      if (((TUkupno >= 55.0 && TUkupno < 65.0) && (BUkupno >= 55.0 && BUkupno < 65.0) && (MUkupno >= 55.0 && MUkupno < 65.0)) ||
          ((TUkupno >= 65.0 && TUkupno < 75.0) && (BUkupno >= 65.0 && BUkupno < 75.0) && (MUkupno >= 65.0 && MUkupno < 75.0)) ||
          ((TUkupno >= 75.0 && TUkupno < 85.0) && (BUkupno >= 75.0 && BUkupno < 85.0) && (MUkupno >= 75.0 && MUkupno < 85.0)) ||
          ((TUkupno >= 85.0 && TUkupno < 92.0) && (BUkupno >= 85.0 && BUkupno < 92.0) && (MUkupno >= 85.0 && MUkupno < 92.0)) ||
          ((TUkupno >= 92.0 && TUkupno <= 100.0) && (BUkupno >= 92.0 && BUkupno <= 100.0) && (MUkupno >= 92.0 && MUkupno <= 100.0)))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (((TUkupno >= 55.0 && TUkupno < 65.0) && ((BUkupno >= 65.0 && BUkupno < 75.0) && ((MUkupno >= 75.0 && MUkupno < 85.0) || (MUkupno >= 85.0 && MUkupno < 92.0) || (MUkupno >= 92.0 && MUkupno <= 100.0)))) ||
               ((TUkupno >= 55.0 && TUkupno < 65.0) && ((BUkupno >= 75.0 && BUkupno < 85.0) && ((MUkupno >= 65.0 && MUkupno < 75.0) || (MUkupno >= 85.0 && MUkupno < 92.0) || (MUkupno >= 92.0 && MUkupno <= 100.0)))) ||
               ((TUkupno >= 55.0 && TUkupno < 65.0) && ((BUkupno >= 85.0 && BUkupno < 92.0) && ((MUkupno >= 65.0 && MUkupno < 75.0) || (MUkupno >= 75.0 && MUkupno < 85.0) || (MUkupno >= 92.0 && MUkupno <= 100.0)))) ||
               ((TUkupno >= 55.0 && TUkupno < 65.0) && ((BUkupno >= 92.0 && BUkupno <= 100.0) && ((MUkupno >= 65.0 && MUkupno < 75.0) || (MUkupno >= 75.0 && MUkupno < 85.0) || (MUkupno >= 85.0 && MUkupno < 92.0)))) ||

               ((TUkupno >= 65.0 && TUkupno < 75.0) && ((BUkupno >= 55.0 && BUkupno < 65.0) && ((MUkupno >= 75.0 && MUkupno < 85.0) || (MUkupno >= 85.0 && MUkupno < 92.0) || (MUkupno >= 92.0 && MUkupno <= 100.0)))) ||
               ((TUkupno >= 65.0 && TUkupno < 75.0) && ((BUkupno >= 75.0 && BUkupno < 85.0) && ((MUkupno >= 55.0 && MUkupno < 65.0) || (MUkupno >= 85.0 && MUkupno < 92.0) || (MUkupno >= 92.0 && MUkupno <= 100.0)))) ||
               ((TUkupno >= 65.0 && TUkupno < 75.0) && ((BUkupno >= 85.0 && BUkupno < 92.0) && ((MUkupno >= 55.0 && MUkupno < 65.0) || (MUkupno >= 75.0 && MUkupno < 85.0) || (MUkupno >= 92.0 && MUkupno <= 100.0)))) ||
               ((TUkupno >= 65.0 && TUkupno < 75.0) && ((BUkupno >= 92.0 && BUkupno <= 100.0) && ((MUkupno >= 55.0 && MUkupno < 65.0) || (MUkupno >= 75.0 && MUkupno < 85.0) || (MUkupno >= 85.0 && MUkupno < 92.0)))) ||

               ((TUkupno >= 75.0 && TUkupno < 85.0) && ((BUkupno >= 65.0 && BUkupno < 75.0) && ((MUkupno >= 55.0 && MUkupno < 65.0) || (MUkupno >= 85.0 && MUkupno < 92.0) || (MUkupno >= 92.0 && MUkupno <= 100.0)))) ||
               ((TUkupno >= 75.0 && TUkupno < 85.0) && ((BUkupno >= 55.0 && BUkupno < 65.0) && ((MUkupno >= 65.0 && MUkupno < 75.0) || (MUkupno >= 85.0 && MUkupno < 92.0) || (MUkupno >= 92.0 && MUkupno <= 100.0)))) ||
               ((TUkupno >= 75.0 && TUkupno < 85.0) && ((BUkupno >= 85.0 && BUkupno < 92.0) && ((MUkupno >= 65.0 && MUkupno < 75.0) || (MUkupno >= 55.0 && MUkupno < 65.0) || (MUkupno >= 92.0 && MUkupno <= 100.0)))) ||
               ((TUkupno >= 75.0 && TUkupno < 85.0) && ((BUkupno >= 92.0 && BUkupno <= 100.0) && ((MUkupno >= 65.0 && MUkupno < 75.0) || (MUkupno >= 55.0 && MUkupno < 65.0) || (MUkupno >= 85.0 && MUkupno < 92.0)))) ||

               ((TUkupno >= 85.0 && TUkupno < 92.0) && ((BUkupno >= 55.0 && BUkupno < 65.0) && ((MUkupno >= 65.0 && MUkupno < 75.0) || (MUkupno >= 75.0 && MUkupno < 85.0) || (MUkupno >= 92.0 && MUkupno <= 100.0)))) ||
               ((TUkupno >= 85.0 && TUkupno < 92.0) && ((BUkupno >= 75.0 && BUkupno < 85.0) && ((MUkupno >= 55.0 && MUkupno < 65.0) || (MUkupno >= 65.0 && MUkupno < 75.0) || (MUkupno >= 92.0 && MUkupno <= 100.0)))) ||
               ((TUkupno >= 85.0 && TUkupno < 92.0) && ((BUkupno >= 65.0 && BUkupno < 75.0) && ((MUkupno >= 55.0 && MUkupno < 65.0) || (MUkupno >= 75.0 && MUkupno < 85.0) || (MUkupno >= 92.0 && MUkupno <= 100.0)))) ||
               ((TUkupno >= 85.0 && TUkupno < 92.0) && ((BUkupno >= 92.0 && BUkupno <= 100.0) && ((MUkupno >= 55.0 && MUkupno < 65.0) || (MUkupno >= 65.0 && MUkupno < 75.0) || (MUkupno >= 75.0 && MUkupno < 85.0)))) ||

               ((TUkupno >= 92.0 && TUkupno <= 100.0) && ((BUkupno >= 65.0 && BUkupno < 75.0) && ((MUkupno >= 55.0 && MUkupno < 65.0) || (MUkupno >= 85.0 && MUkupno < 92.0) || (MUkupno >= 75.0 && MUkupno < 85.0)))) ||
               ((TUkupno >= 92.0 && TUkupno <= 100.0) && ((BUkupno >= 55.0 && BUkupno < 65.0) && ((MUkupno >= 65.0 && MUkupno < 75.0) || (MUkupno >= 75.0 && MUkupno < 85.0) || (MUkupno >= 85.0 && MUkupno < 92.0)))) ||
               ((TUkupno >= 92.0 && TUkupno <= 100.0) && ((BUkupno >= 85.0 && BUkupno < 92.0) && ((MUkupno >= 55.0 && MUkupno < 65.0) || (MUkupno >= 65.0 && MUkupno < 75.0) || (MUkupno >= 75.0 && MUkupno < 85.0)))) ||
               ((TUkupno >= 92.0 && TUkupno <= 100.0) && ((BUkupno >= 75.0 && BUkupno < 85.0) && ((MUkupno >= 55.0 && MUkupno < 65.0) || (MUkupno >= 65.0 && MUkupno < 75.0) || (MUkupno >= 85.0 && MUkupno < 92.0)))))
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
      else
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
   }
   else if (((TUkupno >= 55.0) && (BUkupno < 55.0) && (MUkupno < 55.0)) ||
            ((TUkupno < 55.0) && (BUkupno >= 55.0) && (MUkupno < 55.0)) ||
            ((TUkupno < 55.0) && (BUkupno < 55.0) && (MUkupno >= 55.0)))
   {
      printf("Jedan student je polozio.");
   }
   else
   {
      printf("Dva studenta su polozila.");
   }


   return(0);
}
