#include <stdio.h>
#include <math.h>
#define EPSILON    0.000001

int main()
{
   double TP1, TP2, TP, TZ, TZI, BP1, BP2, BP, BZ, BZI, MP1, MP2, MP, MZ, MZI, TUB, BUB, MUB, TO, BO, MO;

   printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
   scanf("%lf", &TP1);
   if (TP1 > 20 || TP1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &TP2);
   if (TP2 > 20 || TP2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &TP);
   if (TP > 10 || TP < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &TZ);
   if (TZ > 10 || TZ < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &TZI);
   if (TZI > 40 || TZI < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
   scanf("%lf", &BP1);
   if (BP1 > 20 || BP1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &BP2);
   if (BP2 > 20 || BP2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &BP);
   if (BP > 10 || BP < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &BZ);
   if (BZ > 10 || BZ < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &BZI);
   if (BZI > 40 || BZI < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
   scanf("%lf", &MP1);
   if (MP1 > 20 || MP1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &MP2);
   if (MP2 > 20 || MP2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &MP);
   if (MP > 10 || MP < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &MZ);
   if (MZ > 10 || MZ < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &MZI);
   if (MZI > 40 || MZI < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   TUB = TP1 + TP2 + TP + TZ + TZI;
   BUB = BP1 + BP2 + BP + BZ + BZI;
   MUB = MP1 + MP2 + MP + MZ + MZI;

   if (55 - TUB >= EPSILON)
   {
      TO = 5.00;
   }
   else
   if (TUB >= 55.00 && TUB < 65.00)
   {
      TO = 6.00;
   }
   else
   if (TUB >= 65.00 && TUB < 75.00)
   {
      TO = 7.00;
   }
   else
   if (TUB >= 75.00 && TUB < 85.00)
   {
      TO = 8.00;
   }
   else
   if (TUB >= 85.00 && TUB < 92.00)
   {
      TO = 9.00;
   }
   else
   if (TUB >= 92.00 && BUB <= 100.00)
   {
      TO = 10.00;
   }
   if (55 - BUB >= EPSILON)
   {
      BO = 5.00;
   }
   else
   if (BUB >= 55.00 && BUB < 65.00)
   {
      BO = 6.00;
   }
   else
   if (BUB >= 65.0 && BUB < 75.0)
   {
      BO = 7.0;
   }
   else
   if (BUB >= 75.0 && BUB < 85.0)
   {
      BO = 8.0;
   }
   else
   if (BUB >= 85.0 && BUB < 92.0)
   {
      BO = 9.0;
   }
   else
   if (BUB >= 92.0 && BUB <= 100.0)
   {
      BO = 10.0;
   }
   if (55 - MUB >= EPSILON)
   {
      MO = 5.0;
   }
   else
   if (MUB >= 55.0 && MUB < 65.0)
   {
      MO = 6.0;
   }
   else
   if (MUB >= 65.0 && MUB < 75.0)
   {
      MO = 7.0;
   }
   else
   if (MUB >= 75.0 && MUB < 85.0)
   {
      MO = 8.0;
   }
   else
   if (MUB >= 85.0 && MUB < 92.0)
   {
      MO = 9.0;
   }
   else
   if (MUB >= 92.0 && MUB <= 100.0)
   {
      MO = 10.0;
   }


   if (TO == 5.00 && BO == 5.00 && MO == 5.00)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else
   if (TO == 5.00 && BO == 5.00 && MO != 5.00)
   {
      printf("Jedan student je polozio.\n");
   }
   else
   if (MO == 5.00 && BO == 5.00 && TO != 5.00)
   {
      printf("Jedan student je polozio.\n");
   }
   else
   if (TO == 5.00 && MO == 5.00 && BO != 5.00)
   {
      printf("Jedan student je polozio.\n");
   }
   else
   if (TO == 5.00 && BO != 5.00 && MO != 5.00)
   {
      printf("Dva studenta su polozila.\n");
   }
   else
   if (BO == 5.00 && TO != 5.00 && MO != 5.00)
   {
      printf("Dva studenta su polozila.\n");
   }
   else
   if (MO == 5.00 && TO != 5.00 && BO != 5.00)
   {
      printf("Dva studenta su polozila.\n");
   }
   else
   if (TO != 5.0 && BO != 5.0 && MO != 5.0)
   {
      printf("Sva tri studenta su polozila.\n");
      if (fabs(BO - TO) < EPSILON && fabs(BO - MO) < EPSILON && fabs(TO - MO) < EPSILON)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else
      if (fabs(BO - TO) < EPSILON && !(fabs(BO - MO) < EPSILON) && !(fabs(TO - MO) < EPSILON) || fabs(BO - MO) < EPSILON && !(fabs(TO - MO) < EPSILON) && !(fabs(BO - TO) < EPSILON) || fabs(TO - MO) < EPSILON && !(fabs(BO - MO) < EPSILON) && !(fabs(BO - TO) < EPSILON))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      if (!(fabs(BO - TO) < EPSILON) && !(fabs(BO - MO) < EPSILON) && !(fabs(TO - MO) < EPSILON))
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }


   return(0);
}
