#include <stdio.h>
int main()
{
   int T, B, M;

   double T1, T2, TF, TZ, TP;
   double B1, B2, BF, BZ, BP;
   double M1, M2, MF, MZ, MP;

   double OT, OB, OM;

   printf("Unesite bodove za Tarika:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &T1);
   if (T1 < 0 || T1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &T2);
   if (T2 < 0 || T2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &TP);
   if (TP < 0 || TP > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &TZ);
   if (TZ < 0 || TZ > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &TF);
   if (TF < 0 || TF > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   OT = (T1 + T2 + TP + TZ + TF);

   printf("Unesite bodove za Bojana:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &B1);
   if (B1 < 0 || B1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &B2);
   if (B2 < 0 || B2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &BP);
   if (BP < 0 || BP > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &BZ);
   if (BZ < 0 || BZ > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &BF);
   if (BF < 0 || BF > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   OB = B1 + B2 + BP + BZ + BF;

   printf("Unesite bodove za Mirzu:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &M1);
   if (M1 < 0 || M1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &M2);
   if (M2 < 0 || M2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &MP);
   if (MP < 0 || MP > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &MZ);
   if (MZ < 0 || MZ > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &MF);
   if (MF < 0 || MF > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   OM = (M1 + M2 + MP + MZ + MF);


   /* Tarikova ocjena */
   if (OT < 55)
   {
      T = 5;
   }
   else if (OT >= 55 && OT < 65)
   {
      T = 6;
   }
   else if (OT >= 65 && OT < 75)
   {
      T = 7;
   }
   else if (OT >= 75 && OT < 85)
   {
      T = 8;
   }
   else if (OT >= 85 && OT < 92)
   {
      T = 9;
   }
   else
   {
      T = 10;
   }

   /* Bojanova ocjena */
   if (OB < 55)
   {
      B = 5;
   }
   else if (OB >= 55 && OB < 65)
   {
      B = 6;
   }
   else if (OB >= 65 && OB < 75)
   {
      B = 7;
   }
   else if (OB >= 75 && OB < 85)
   {
      B = 8;
   }
   else if (OB >= 85 && OB < 92)
   {
      B = 9;
   }
   else
   {
      B = 10;
   }

   /* Mirzina ocjena */
   if (OM < 55)
   {
      M = 5;
   }
   else if (OM >= 55 && OM < 65)
   {
      M = 6;
   }
   else if (OM >= 65 && OM < 75)
   {
      M = 7;
   }
   else if (OM >= 75 && OM < 85)
   {
      M = 8;
   }
   else if (OM >= 85 && OM < 92)
   {
      M = 9;
   }
   else
   {
      M = 10;
   }

   if (T >= 6 && B >= 6 && M >= 6)
   {
      printf("Sva tri studenta su polozila.");
      if (T == B && B == M)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (T != B && B != M && M != T)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
      else
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
   }
   else if ((T >= 6 && B >= 6 && M < 6) || (T >= 6 && B >= 6 && M < 6) || (T < 6 && B >= 6 && M >= 6))
   {
      printf("Dva studenta su polozila.");
   }
   else if (T < 6 && B < 6 && M < 6)
   {
      printf("Nijedan student nije polozio.");
   }
   else
   {
      printf("Jedan student je polozio.");
   }
   return(0);
}
