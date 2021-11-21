#include <stdio.h>

int main()
{
    for (int i = 0; i < 50; i++)
    {
        printf("hello");
    }
   double MP1, MP2, MP, MZ, MZI, BP1, BP2, BP, BZ, BZI, TP1, TP2, TP, TZ, TZI, MBB, TBB, BBB, MO, TO, BO;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &TP1);
   if (TP1 < 0 || TP1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &TP2);
   if (TP2 < 0 || TP2 > 20)
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
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &BP1);
   if (BP1 < 0 || BP1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &BP2);
   if (BP2 < 0 || BP2 > 20)
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
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &MP1);
   if (MP1 < 0 || MP1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &MP2);
   if (MP2 < 0 || MP2 > 20)
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
   TBB = TP1 + TP2 + TZ + TP + TZI;
   MBB = MP1 + MP2 + MP + MZ + MZI;
   BBB = BP1 + BP2 + BP + BZ + BZI;
   if (TBB < 55)
   {
      TO = 5;
   }
   else if (TBB >= 55 && TBB < 65)
   {
      TO = 6;
   }
   else if (TBB >= 65 && TBB < 75)
   {
      TO = 7;
   }
   else if (TBB >= 75 && TBB < 85)
   {
      TO = 8;
   }
   else if (TBB >= 85 && TBB < 92)
   {
      TO = 9;
   }
   else
   {
      TO = 10;
   }
   if (MBB < 55)
   {
      MO = 5;
   }
   else if (MBB >= 55 && MBB < 65)
   {
      MO = 6;
   }
   else if (MBB >= 65 && MBB < 75)
   {
      MO = 7;
   }
   else if (MBB >= 75 && MBB < 85)
   {
      MO = 8;
   }
   else if (MBB >= 85 && MBB < 92)
   {
      MO = 9;
   }
   else
   {
      MO = 10;
   }
   if (BBB < 55)
   {
      BO = 5;
   }
   else if (BBB >= 55 && BBB < 65)
   {
      BO = 6;
   }
   else if (BBB >= 65 && BBB < 75)
   {
      BO = 7;
   }
   else if (BBB >= 75 && BBB < 85)
   {
      BO = 8;
   }
   else if (BBB >= 85 && BBB < 92)
   {
      BO = 9;
   }
   else
   {
      BO = 10;
   }
   if (MO < 6 && BO < 6 && TO < 6)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (MO >= 6 && BO >= 6 && TO >= 6)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else if ((MO < 6 && BO < 6 && TO >= 6) || (MO < 6 && BO >= 6 && TO < 6) || (MO >= 6 && BO < 6 && TO < 6))
   {
      printf("Jedan student je polozio.\n");
   }
   else
   {
      printf("Dva studenta su polozila.\n");
   }
   if (MO >= 6 && BO >= 6 && TO >= 6)
   {
      if (MO == BO && BO == TO)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (MO != BO && BO != TO && MO != TO)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      else
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }
   return(0);
}