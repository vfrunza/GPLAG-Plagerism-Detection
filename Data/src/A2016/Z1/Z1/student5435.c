#include <stdio.h>
#define epsilon    0.001

int main()
{
   float T1, T2, TP, TZ, TF, B1, B2, BP, BZ, BF, M1, M2, MP, MZ, MF;
   float TU, BU, MU;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &T1);
   if (T1 > 20 || T1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &T2);
   if (T2 > 20 || T2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &TP);
   if (TP > 10 || TP < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &TZ);
   if (TZ > 10 || TZ < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &TF);
   if (TF > 40 || TF < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &B1);
   if (B1 > 20 || B1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &B2);
   if (B2 > 20 || B2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &BP);
   if (BP > 10 || BP < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &BZ);
   if (BZ > 10 || BZ < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &BF);
   if (BF > 40 || BF < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &M1);
   if (M1 > 20 || M1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &M2);
   if (M2 > 20 || M2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &MP);
   if (MP > 10 || MP < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &MZ);
   if (MZ > 10 || MZ < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &MF);
   if (MF > 40 || MF < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   TU = T1 + T2 + TP + TZ + TF;
   BU = B1 + B2 + BP + BZ + BF;
   MU = M1 + M2 + MP + MZ + MF;
   int t, b, m;

   if (TU < 55)
   {
      t = 0;
   }
   if (TU >= 55 - epsilon && TU < 65)
   {
      t = 6;
   }
   if (TU >= 65 && TU < 75)
   {
      t = 7;
   }
   if (TU >= 75 && TU < 85)
   {
      t = 8;
   }
   if (TU >= 85 && TU < 92)
   {
      t = 9;
   }
   if (TU >= 92 && TU < 100)
   {
      t = 10;
   }

   if (BU < 55)
   {
      b = 0;
   }
   if (BU >= 55 && BU < 65)
   {
      b = 6;
   }
   if (BU >= 65 && BU < 75)
   {
      b = 7;
   }
   if (BU >= 75 && BU < 85)
   {
      b = 8;
   }
   if (BU >= 85 && BU < 92)
   {
      b = 9;
   }
   if (BU >= 92 && BU < 100)
   {
      b = 10;
   }

   if (MU < 55)
   {
      m = 0;
   }
   if (MU >= 55 && MU < 65)
   {
      m = 6;
   }
   if (MU >= 65 && MU < 75)
   {
      m = 7;
   }
   if (MU >= 75 && MU < 85)
   {
      m = 8;
   }
   if (MU >= 85 && MU < 92)
   {
      m = 9;
   }
   if (MU >= 92 && MU < 100)
   {
      m = 10;
   }

   if (t == 0 && b == 0 && m == 0)
   {
      printf("Nijedan student nije polozio.");
   }
   if (t == 0 && b == 0 && m != 0)
   {
      printf("Jedan student je polozio.");
   }
   if (t == 0 && b != 0 && m == 0)
   {
      printf("Jedan student je polozio.");
   }
   if (t != 0 && b == 0 && m == 0)
   {
      printf("Jedan student je polozio.");
   }
   if (t == 0 && b != 0 && m != 0)
   {
      printf("Dva studenta su polozila.");
   }
   if (t != 0 && b == 0 && m != 0)
   {
      printf("Dva studenta su polozila.");
   }
   if (t != 0 && b != 0 && m == 0)
   {
      printf("Dva studenta su polozila.");
   }

   if (t != 0 && b != 0 && m != 0)
   {
      printf("Sva tri studenta su polozila.\n");
      if (t == b && t == m)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      if (t != b && b != m && m != t)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      if (t != b && b == m)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (t == b && b != m)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (t == m && m != b)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }

   return(0);
}
