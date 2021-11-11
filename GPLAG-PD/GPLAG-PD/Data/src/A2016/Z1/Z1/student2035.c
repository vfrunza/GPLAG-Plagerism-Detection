#include <stdio.h>
#include <math.h>
int main()
{
   double uBT, uBB, uBM, p1T, p1B, p1M, p2T, p2B, p2M, pT, pB, pM, zT, zB, zM, ZT, ZB, ZM;


   /*UNOS BODOVA ZA TARIKA*/

   printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
   scanf("%lf", &p1T);
   if (p1T < 0 || p1T > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &p2T);
   if (p2T < 0 || p2T > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &pT);
   if (pT < 0 || pT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &zT);
   if (zT < 0 || zT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &ZT);
   if (ZT < 0 || ZT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   uBT = p1T + p2T + pT + zT + ZT; // Ukupan broj Tarikovih bodova



   /*UNOS BODOVA ZA BOJANA*/

   printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
   scanf("%lf", &p1B);
   if (p1B < 0 || p1B > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &p2B);
   if (p2B < 0 || p2B > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &pB);
   if (pB < 0 || pB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &zB);
   if (zB < 0 || zB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Zavrsni ispit: ");
   scanf("%lf", &ZB);
   if (ZB < 0 || ZB > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   uBB = p1B + p2B + pB + zB + ZB; // Ukupan broj Bojanovih bodova



   /*UNOS BODOVA ZA MIRZU*/

   printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
   scanf("%lf", &p1M);
   if (p1M < 0 || p1M > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &p2M);
   if (p2M < 0 || p2M > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pM);
   if (pM < 0 || pM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &zM);
   if (zM < 0 || zM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &ZM);
   if (ZM < 0 || ZM > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   uBM = p1M + p2M + pM + zM + ZM; // Ukupan  broj Mirzinih bodova


   /*kraj unosa*/

   if (uBT < 55 && uBB < 55 && uBM < 55)
   {
      printf("Nijedan student nije polozio.");
   }

   else if ((uBT >= 55 && uBB < 55 && uBM < 55) || (uBT < 55 && uBB >= 55 && uBM < 55) || (uBT < 55 && uBB < 55 && uBM >= 55))
   {
      printf("Jedan student je polozio.");
   }

   else if ((uBT >= 55 && uBB >= 55 && uBM < 55) || (uBT >= 55 && uBB < 55 && uBM >= 55) || (uBT < 55 && uBB >= 55 && uBM >= 55))
   {
      printf("Dva studenta su polozila.");
   }

   else
   {
      printf("Sva tri studenta su polozila.");

      if ((uBT < 65 && uBB < 65 && uBM < 65) || (uBT >= 65 && uBT < 75 && uBB >= 65 && uBB < 75 && uBM >= 65 && uBM < 75) || (uBT >= 75 && uBT < 85 && uBB >= 75 && uBB < 85 && uBM >= 75 && uBM < 85) || (uBT >= 85 && uBT < 92 && uBB >= 85 && uBB < 92 && uBM >= 85 && uBM < 92))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }

      else if ((uBT >= 65 && uBB < 65 && uBM < 65) || (uBT < 65 && uBB >= 65 && uBM < 65) || (uBT < 65 && uBB < 65 && uBM >= 65) || (!(uBT >= 65 && uBT < 75) && uBB >= 65 && uBB < 75 && uBM >= 65 && uBM < 75) || (uBT >= 65 && uBT < 75 && !(uBB >= 65 && uBB < 75) && uBM >= 65 && uBM < 75) || (uBT >= 65 && uBT < 75 && uBB >= 65 && uBB < 75 && !(uBM >= 65 && uBM < 75)) || (!(uBT >= 75 && uBT < 85) && uBB >= 75 && uBB < 85 && uBM >= 75 && uBM < 85) || (uBT >= 75 && uBT < 85 && !(uBB >= 75 && uBB < 85) && uBM >= 75 && uBM < 85) || (uBT >= 75 && uBT < 85 && uBB >= 75 && uBB < 85 && !(uBM >= 75 & uBM < 85)) || (!(uBT >= 85 && uBT < 92) && uBB >= 85 && uBB < 92 && uBM >= 85 && uBM < 92) || (uBT >= 85 && uBT < 92 && !(uBB >= 85 && uBB < 92) && uBM >= 85 && uBM < 92) || (uBT >= 85 && uBT < 92 && uBB >= 85 && uBB < 92 && !(uBM >= 85 && uBM < 92)) || (uBT < 92 && uBB >= 92 && uBM >= 92) || (uBT >= 92 && uBB < 92 && uBM >= 92) || (uBT >= 92 && uBB >= 92 && uBM < 92))

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
