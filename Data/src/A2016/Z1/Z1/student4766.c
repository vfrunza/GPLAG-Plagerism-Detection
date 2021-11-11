#include <stdio.h>
#include <math.h>

int main()
{
   double tparc1, tparc2, tzad, tusmeni, tpris;
   double bparc1, bparc2, bzad, busmeni, bpris;
   double mparc1, mparc2, mzad, musmeni, mpris;
   double tarikBod, mirzaBod, bojanBod;
   int    tOcjena, mOcjena, bOcjena, numPass;

   numPass = 0;
   //tarik
   printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
   scanf("%lf", &tparc1);
   if (tparc1 < 0 || tparc1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &tparc2);
   if (tparc2 < 0 || tparc2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &tpris);
   if (tpris > 10 || tpris < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &tzad);
   if (tzad < 0 || tzad > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &tusmeni);
   if (tusmeni < 0 || tusmeni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   //bojan
   printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
   scanf("%lf", &bparc1);
   if (bparc1 > 20 || bparc1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &bparc2);
   if (bparc2 > 20 || bparc2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &bpris);
   if (bpris > 10 || bpris < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &bzad);
   if (bzad < 0 || bzad > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &busmeni);
   if (busmeni < 0 || busmeni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   //mirza
   printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
   scanf("%lf", &mparc1);
   if (mparc1 < 0 || mparc1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &mparc2);
   if (mparc2 < 0 || mparc2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &mpris);
   if (mpris < 0 || mpris > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &mzad);
   if (mzad < 0 || mzad > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &musmeni);
   if (musmeni < 0 || musmeni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   //END
   tarikBod = tparc1 + tparc2 + tpris + tzad + tusmeni;
   bojanBod = bparc1 + bparc2 + bpris + bzad + busmeni;
   mirzaBod = mparc1 + mparc2 + mpris + mzad + musmeni;

   if (tarikBod >= 92)
   {
      tOcjena = 10;
   }
   else if (tarikBod >= 85)
   {
      tOcjena = 9;
   }
   else if (tarikBod >= 75)
   {
      tOcjena = 8;
   }
   else if (tarikBod >= 65)
   {
      tOcjena = 7;
   }
   else if (tarikBod >= 54.9999)
   {
      tOcjena = 6;
   }
   else
   {
      tOcjena = 0;
   }
   if (tOcjena > 0)
   {
      numPass++;
   }

   if (bojanBod >= 92)
   {
      bOcjena = 10;
   }
   else if (bojanBod >= 85)
   {
      bOcjena = 9;
   }
   else if (bojanBod >= 75)
   {
      bOcjena = 8;
   }
   else if (bojanBod >= 65)
   {
      bOcjena = 7;
   }
   else if (bojanBod >= 55)
   {
      bOcjena = 6;
   }
   else
   {
      bOcjena = 0;
   }
   if (bOcjena > 0)
   {
      numPass++;
   }

   if (mirzaBod >= 92)
   {
      mOcjena = 10;
   }
   else if (mirzaBod >= 85)
   {
      mOcjena = 9;
   }
   else if (mirzaBod >= 75)
   {
      mOcjena = 8;
   }
   else if (mirzaBod >= 65)
   {
      mOcjena = 7;
   }
   else if (mirzaBod >= 55)
   {
      mOcjena = 6;
   }
   else
   {
      mOcjena = 0;
   }
   if (mOcjena > 0)
   {
      numPass++;
   }

   //END
   switch (numPass)
   {
   case 0: printf("Nijedan student nije polozio.");
      break;

   case 1: printf("Jedan student je polozio.");
      break;

   case 2: printf("Dva studenta su polozila.");
      break;

   case 3: printf("Sva tri studenta su polozila.");
      break;

   default: printf("O no!");
   }
   if (numPass == 3)
   {
      if (tOcjena == mOcjena && tOcjena == bOcjena)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (tOcjena == mOcjena || tOcjena == bOcjena || mOcjena == bOcjena)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }


   return(0);
}
