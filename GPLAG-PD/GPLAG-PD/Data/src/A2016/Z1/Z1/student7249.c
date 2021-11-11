#include <stdio.h>

int main()
{
   double T1P, T2P, TP, TZ, TZI, B1P, B2P, BP, BZ, BZI, M1P, M2P, MP, MZ, MZI, TB, BB, MB;

   printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
   scanf("%lf", &T1P);
   if (T1P < 0 || T1P > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &T2P);
   if (T2P < 0 || T2P > 20)
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
   printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
   scanf("%lf", &B1P);
   if (B1P < 0 || B1P > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &B2P);
   if (B2P < 0 || B2P > 20)
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
   printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
   scanf("%lf", &M1P);
   if (M1P < 0 || M1P > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &M2P);
   if (M2P < 0 || M2P > 20)
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
   TB = T1P + T2P + TP + TZ + TZI;
   BB = B1P + B2P + BP + BZ + BZI;
   MB = M1P + M2P + MP + MZ + MZI;
   if (TB >= 55 && BB >= 55 && MB >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else if (TB >= 55 && BB >= 55 && MB < 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (TB >= 55 && BB < 55 && MB >= 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (TB < 55 && BB >= 55 && MB >= 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (TB >= 55 && BB < 55 && MB < 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (TB < 55 && BB >= 55 && MB < 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (TB < 55 && BB < 55 && MB >= 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (TB < 55 && BB < 55 && MB < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   if (TB < 55)
   {
      return(0);
   }
   if (BB < 55)
   {
      return(0);
   }
   if (MB < 55)
   {
      return(0);
   }
   if (TB >= 55 && TB < 65)
   {
      TB = 6;
   }
   else if (TB >= 65 && TB < 75)
   {
      TB = 7;
   }
   else if (TB >= 75 && TB < 85)
   {
      TB = 8;
   }
   else if (TB >= 85 && TB < 92)
   {
      TB = 9;
   }
   else if (TB >= 92 && TB <= 100)
   {
      TB = 10;
   }
   if (BB >= 55 && BB < 65)
   {
      BB = 6;
   }
   else if (BB >= 65 && BB < 75)
   {
      BB = 7;
   }
   else if (BB >= 75 && BB < 85)
   {
      BB = 8;
   }
   else if (BB >= 85 && BB < 92)
   {
      BB = 9;
   }
   else if (BB >= 92 && BB <= 100)
   {
      BB = 10;
   }
   if (MB >= 55 && MB < 65)
   {
      MB = 6;
   }
   else if (MB >= 65 && MB < 75)
   {
      MB = 7;
   }
   else if (MB >= 75 && MB < 85)
   {
      MB = 8;
   }
   else if (MB >= 85 && MB < 92)
   {
      MB = 9;
   }
   else if (MB >= 92 && MB <= 100)
   {
      MB = 10;
   }
   if (TB == BB && BB == MB)
   {
      printf("Sva tri studenta imaju istu ocjenu.");
   }
   else if (TB == BB && BB != MB)
   {
      printf("Dva od tri studenta imaju istu ocjenu.");
   }
   else if (TB == MB && MB != BB)
   {
      printf("Dva od tri studenta imaju istu ocjenu.");
   }
   else if (MB == BB && TB != MB)
   {
      printf("Dva od tri studenta imaju istu ocjenu.");
   }
   if (TB != BB && BB != MB && TB != MB)
   {
      printf("Svaki student ima razlicitu ocjenu.");
   }
   return(0);
}
