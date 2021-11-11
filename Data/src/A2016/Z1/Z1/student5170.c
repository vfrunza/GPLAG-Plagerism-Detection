#include <stdio.h>

int main()
{
   double T1, T2, TP, TZ, TZI, B1, B2, BP, BZ, BZI, M1, M2, MP, MZ, MZI, T, B, M;
   int    TO, BO, MO;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
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
   scanf("%lf", &TZI);
   if (TZI < 0 || TZI > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
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
   scanf("%lf", &BZI);
   if (BZI < 0 || BZI > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
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
   scanf("%lf", &MZI);
   if (MZI < 0 || MZI > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   T = T1 + T2 + TP + TZ + TZI;
   B = B1 + B2 + BP + BZ + BZI;
   M = M1 + M2 + MP + MZ + MZI;

   if (T < 55)
   {
      TO = 5;
   }
   else if (T >= 55 && T < 65)
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

   if (B < 55)
   {
      BO = 5;
   }
   else if (B >= 55 && B < 65)
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

   if (M < 55)
   {
      MO = 5;
   }
   else if (M >= 55 && M < 65)
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

   if (TO != 5 && MO != 5 && BO != 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if (TO == MO && MO == BO)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (TO != MO && TO != BO && BO != MO)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      else if (TO == MO && TO != MO || BO == MO && BO != TO || BO == TO && MO != BO)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }
   else if (TO == 5 && MO == 5 && BO == 5)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (TO != 5 && (MO == 5 && BO == 5) || MO != 5 && (TO == 5 && BO == 5) || BO != 5 && (TO == 5 && MO == 5))
   {
      printf("Jedan student je polozio.\n");
   }
   else
   {
      printf("Dva studenta su polozila.\n");
   }

   return(0);
}
