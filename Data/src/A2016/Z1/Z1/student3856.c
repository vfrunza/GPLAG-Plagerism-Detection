#include <stdio.h>

int main()
{
   double TP1, TP2, TPR, TZA, TZ, TUK, BP1, BP2, BPR, BZA, BZ, BUK, MP1, MP2, MPR, MZA, MZ, MUK;

   int OT, OB, OM, student = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &TP1);
   if ((TP1 < 0) || (TP1 > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &TP2);
   if ((TP2 < 0) || (TP2 > 20))
   {
      printf("Neispravan broj bododa");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &TPR);
   if ((TPR < 0) || (TPR > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &TZA);
   if ((TZA < 0) || (TZA > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &TZ);
   if ((TZ < 0) || (TZ > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &BP1);
   if ((BP1 < 0) || (BP2 > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &BP2);
   if (BP2 < 0 || BP2 > 20)
   {
      printf("Neispravan broj bododa ");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &BPR);
   if ((BPR < 0) || (BPR > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &BZA);
   if (BZA < 0 || BZA > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &BZ);
   if ((BZ < 0) || (BZ > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &MP1);
   if ((MP1 < 0) || (MP2 > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &MP2);
   if ((BP2 < 0) || (BP2 > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &MPR);
   if ((MPR < 0) || (MPR > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &MZA);
   if ((MZA < 0) || (MZA > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &MZ);
   if ((MZ < 0) || (MZ > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   TUK = TP1 + TP2 + TPR + TZA + TZ;
   if (TUK < 55)
   {
      OT = 5;
   }
   if (TUK >= 55 && TUK > 65)
   {
      OT = 6;
   }
   if (TUK >= 65 && TUK < 75)
   {
      OT = 7;
   }
   if (TUK >= 75 && TUK < 85)
   {
      OT = 8;
   }
   if (TUK >= 85 && TUK < 92)
   {
      OT = 9;
   }
   if (TUK >= 92 && TUK <= 100)
   {
      OT = 10;
   }
   BUK = BP1 + BP2 + BPR + BZA + BZ;
   if (BUK < 55)
   {
      OB = 5;
   }
   if (BUK >= 55 && BUK > 65)
   {
      OB = 6;
   }
   if (BUK >= 65 && BUK < 75)
   {
      OB = 7;
   }
   if (BUK >= 75 && BUK < 85)
   {
      OT = 8;
   }
   if (BUK >= 85 && BUK < 92)
   {
      OB = 9;
   }
   if (BUK >= 92 && BUK <= 100)
   {
      OB = 10;
   }
   MUK = MP1 + MP2 + MPR + MZA + MZ;
   if (MUK < 55)
   {
      OM = 5;
   }
   if (MUK >= 55 && MUK > 65)
   {
      OM = 6;
   }
   if (BUK >= 65 && MUK < 75)
   {
      OM = 7;
   }
   if (MUK >= 75 && MUK < 85)
   {
      OT = 8;
   }
   if (MUK >= 85 && MUK < 92)
   {
      OM = 9;
   }
   if (MUK >= 92 && MUK <= 100)
   {
      OM = 10;
   }

   if (OT == 5 && OB == 5 && OM == 5)
   {
      printf("Nijedan student nije polozio. \n");
   }
   if (OT > 5)
   {
      ++student;
   }
   if (OB > 5)
   {
      ++student;
   }
   if (OM > 5)
   {
      ++student;
   }
   if (student == 1)
   {
      printf("Jedan student je polozio. \n");
   }
   if (student == 2)
   {
      printf("Dva studenta su polozila. \n");
   }
   if (student == 3)
   {
      printf("Sva tri studenta su polozila. \n");
      if (OT == OB && OB == OM)
      {
         printf("Sva tri studenta imaju istu ocjenu. \n");
      }
      else if ((OT == OB && OB != OM) || (OT != OB && OB == OM) || (OT == OM && OM != OB))
      {
         printf("Dva od tri studenta imaju istu ocjenu. \n");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu. \n");
      }
   }
   return(0);
}
