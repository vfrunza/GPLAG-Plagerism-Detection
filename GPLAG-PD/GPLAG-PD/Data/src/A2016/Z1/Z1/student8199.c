#include <stdio.h>

int main()
{
   double tP1, tP2, tPR, tZA, tZ, tUK, tOC, bP1, bP2, bPR, bZA, bZ, bUK, bOC, mP1, mP2, mPR, mZA, mZ, mUK, mOC;

   // Tarikovi bodovi

   printf("Unesite bodove za Tarika: \n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &tP1);
   if (tP1 < 0 || tP1 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &tP2);
   if (tP2 < 0 || tP2 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &tPR);
   if (tPR < 0 || tPR > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &tZA);
   if (tZA < 0 || tZA > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &tZ);
   if (tZ < 0 || tZ > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   tUK = tP1 + tP2 + tPR + tZA + tZ;

   if (tUK < 55)
   {
      tOC = 5;
   }
   if (tUK >= 55 && tUK < 65)
   {
      tOC = 6;
   }
   if (tUK >= 65 && tUK < 75)
   {
      tOC = 7;
   }
   if (tUK >= 75 && tUK < 85)
   {
      tOC = 8;
   }
   if (tUK >= 85 && tUK < 92)
   {
      tOC = 9;
   }
   if (tUK >= 92 && tUK <= 100)
   {
      tOC = 10;
   }

   // Bojanovi bodovi

   printf("Unesite bodove za Bojana: \n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &bP1);
   if (bP1 < 0 || bP1 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &bP2);
   if (bP2 < 0 || bP2 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &bPR);
   if (bPR < 0 || bPR > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &bZA);
   if (bZA < 0 || bZA > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bZ);
   if (bZ < 0 || bZ > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   bUK = bP1 + bP2 + bPR + bZA + bZ;

   if (bUK < 55)
   {
      bOC = 5;
   }
   else if (bUK >= 55 && bUK < 65)
   {
      bOC = 6;
   }
   else if (bUK >= 65 && bUK < 75)
   {
      bOC = 7;
   }
   else if (bUK >= 75 && bUK < 85)
   {
      bOC = 8;
   }
   else if (bUK >= 85 && bUK < 92)
   {
      bOC = 9;
   }
   else if (bUK >= 92 && bUK <= 100)
   {
      bOC = 10;
   }

   //Mirzini bodovi

   printf("Unesite bodove za Mirzu: \n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &mP1);
   if (mP1 < 0 || mP1 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &mP2);
   if (mP2 < 0 || mP2 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &mPR);
   if (mPR < 0 || mPR > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &mZA);
   if (mZA < 0 || mZA > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &mZ);
   if (mZ < 0 || mZ > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   mUK = mP1 + mP2 + mPR + mZA + mZ;

   if (mUK < 55)
   {
      mOC = 5;
   }
   if (mUK >= 55 && mUK < 65)
   {
      mOC = 6;
   }
   if (mUK >= 65 && mUK < 75)
   {
      mOC = 7;
   }
   if (mUK >= 75 && mUK < 85)
   {
      mOC = 8;
   }
   if (mUK >= 85 && mUK < 92)
   {
      mOC = 9;
   }
   if (mUK >= 92 && mUK <= 100)
   {
      mOC = 10;
   }

   //Prolaznost

   int student = 0;

   if (tOC == 5 && bOC == 5 && mOC == 5)
   {
      printf("Nijedan student nije polozio.\n");
   }

   if (tOC > 5)
   {
      student++;
   }
   if (bOC > 5)
   {
      student++;
   }
   if (mOC > 5)
   {
      student++;
   }

   if (student == 1)
   {
      printf("Jedan student je polozio.\n");
   }

   if (student == 2)
   {
      printf("Dva studenta su polozila.\n");
   }

   if (student == 3)
   {
      printf("Sva tri studenta su polozila.\n");

      if (tOC == bOC && bOC == mOC)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (tOC == bOC || tOC == mOC || mOC == bOC)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }

   return(0);
}
