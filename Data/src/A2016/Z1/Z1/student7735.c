#include <stdio.h>
int main()
{
   double TPP, TDP, TP, TZ, TZA, BPP, BDP, BP, BZ, BZA, MPP, MDP, MP, MZ, MZA, TUK, MUK, BUK, TO, MO, BO;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &TPP);
   if (TPP < 0 || TPP > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &TDP);
   if (TDP < 0 || TDP > 20)
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
   if (TZ < 0 || TZ > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &TZA);
   if (TZA < 0 || TZA > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &BPP);
   if (BPP < 0 || BPP > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &BDP);
   if (BDP < 0 || BDP > 20)
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
   scanf("%lf", &BZA);
   if (BZA < 0 || BZA > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &MPP);
   if (MPP < 0 || MPP > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &MDP);
   if (MDP < 0 || MDP > 20)
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
   scanf("%lf", &MZA);
   if (MZA < 0 || MZA > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   TUK = TPP + TDP + TZ + TP + TZA;
   MUK = MPP + MDP + MZ + MP + MZA;
   BUK = BPP + BDP + BZ + BP + BZA;

   if (TUK < 55)
   {
      TO = 5;
   }
   if (TUK >= 55 && TUK < 65)
   {
      TO = 6;
   }
   if (TUK >= 65 && TUK < 75)
   {
      TO = 7;
   }
   if (TUK >= 75 && TUK < 85)
   {
      TO = 8;
   }
   if (TUK >= 85 && TUK < 92)
   {
      TO = 9;
   }
   if (TUK >= 92 && TUK < 100)
   {
      TO = 10;
   }
   if (TUK < 55)
   {
      TO = 5;
   }
   if (MUK >= 55 && MUK < 65)
   {
      MO = 6;
   }
   if (MUK >= 65 && MUK < 75)
   {
      MO = 7;
   }
   if (MUK >= 75 && MUK < 85)
   {
      MO = 8;
   }
   if (MUK >= 85 && MUK < 92)
   {
      MO = 9;
   }
   if (MUK >= 92 && MUK < 100)
   {
      MO = 10;
   }

   if (BUK < 55)
   {
      BO = 5;
   }

   if (BUK >= 55 && BUK < 65)
   {
      BO = 6;
   }
   if (BUK >= 65 && BUK < 75)
   {
      BO = 7;
   }
   if (BUK >= 75 && BUK < 85)
   {
      BO = 8;
   }
   if (BUK >= 85 && BUK < 92)
   {
      BO = 9;
   }
   if (BUK >= 92 && BUK < 100)
   {
      BO = 10;
   }
   if ((MUK < 55) && (BUK < 55) && (TUK < 55))
   {
      printf("Nijedan student nije polozio.\n");
      return(0);
   }
   else if ((MUK < 55) && (BUK >= 55) && (TUK < 55))
   {
      printf("Jedan student je polozio.\n");
      return(0);
   }
   else if ((MUK >= 55) && (BUK < 55) && (TUK < 55))
   {
      printf("Jedan student je polozio.\n");
      return(0);
   }
   else if ((MUK < 55) && (BUK < 55) && (TUK >= 55))
   {
      printf("Jedan student je polozio.\n");
      return(0);
   }
   else if ((MUK >= 55) && (BUK >= 55) && (TUK < 55))
   {
      printf("Dva studenta su polozila.\n");
      return(0);
   }
   else if ((MUK >= 55) && (BUK < 55) && (TUK >= 55))
   {
      printf("Dva studenta su polozila.\n");
      return(0);
   }
   else if ((MUK < 55) && (BUK >= 55) && (TUK >= 55))
   {
      printf("Dva studenta su polozila.\n");
      return(0);
   }
   else if ((TUK >= 55) && (MUK >= 55) && (BUK >= 55))
   {
      printf("Sva tri studenta su polozila.\n");
   }

   if ((MO == BO) && (MO == TO))
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
   }

   else if ((MO == BO) && (MO != TO))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }

   else if ((MO == TO) && (MO != BO))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }
   else if ((TO == BO) && (TO != MO))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
   }

   else if ((TO != BO && MO != BO && MO != TO))
   {
      printf("Svaki student ima razlicitu ocjenu.\n");
      return(0);
   }



   return(0);
}
