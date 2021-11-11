#include <stdio.h>
#include <math.h>
#define epsilon    0.001
int main()
{
   float tp, tp1, tp2, tz, tu, bp, bp1, bp2, bz, bu, mp, mp1, mp2, mz, mu, sct, scb, scm;
   int   oct, ocb, ocm;
   int   i = 0;


   printf("Unesite bodove za Tarika: ");

   printf("\nI parcijalni ispit: ");
   scanf("%f", &tp1);
   if (tp1 < 0 || tp1 > 20)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }


   printf("II parcijalni ispit: ");
   scanf("%f", &tp2);
   if (tp2 < 0 || tp2 > 20)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }


   printf("Prisustvo: ");
   scanf("%f", &tp);
   if (tp < 0 || tp > 10)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }


   printf("Zadace: ");
   scanf("%f", &tz);
   if (tz < 0 || tz > 10)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }


   printf("Zavrsni ispit: ");
   scanf("%f", &tu);
   if (tu < 0 || tu > 40)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }



   printf("Unesite bodove za Bojana: ");

   printf("\nI parcijalni ispit: ");
   scanf("%f", &bp1);
   if (bp1 < 0 || bp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("II parcijalni ispit: ");
   scanf("%f", &bp2);
   if (bp2 < 0 || bp2 > 20)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }


   printf("Prisustvo: ");
   scanf("%f", &bp);
   if (bp < 0 || bp > 10)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }


   printf("Zadace: ");
   scanf("%f", &bz);
   if (bz < 0 || bz > 10)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }


   printf("Zavrsni ispit: ");
   scanf("%f", &bu);
   if (bu < 0 || bu > 40)
   {
      printf("\nNeispravan broj bodova");
      return(0);;
   }


   printf("Unesite bodove za Mirzu: ");

   printf("\nI parcijalni ispit: ");
   scanf("%f", &mp1);
   if (mp1 < 0 || mp1 > 20)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }


   printf("II parcijalni ispit: ");
   scanf("%f", &mp2);
   if (mp2 < 0 || mp2 > 20)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }


   printf("Prisustvo: ");
   scanf("%f", &mp);
   if (mp < 0 || mp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &mz);
   if (mz < 0 || mz > 10)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &mu);
   if (mu < 0 || mu > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   sct = tp1 + tp2 + tp + tz + tu;
   scb = bp1 + bp2 + bp + bz + bu;
   scm = mp1 + mp2 + mp + mz + mu;


   if (((fabs(sct - 55)) < epsilon || sct > 55) && sct < 65)
   {
      oct = 6;
   }
   else if (((fabs(sct - 65)) < epsilon || sct > 65) && sct < 75)
   {
      oct = 7;
   }
   else if (((fabs(sct - 75)) < epsilon || sct > 75) && sct < 85)
   {
      oct = 8;
   }
   else if (((fabs(sct - 85)) < epsilon || sct > 85) && sct < 92)
   {
      oct = 9;
   }
   else if ((((fabs(sct - 92)) < epsilon || sct > 92) && sct < 100) || fabs(sct - 100) < epsilon)
   {
      oct = 10;
   }
   else
   {
      oct = 5;
   }

   if (((fabs(scb - 55)) < epsilon || scb > 55) && scb < 65)
   {
      ocb = 6;
   }
   else if (((fabs(scb - 65)) < epsilon || scb > 65) && scb < 75)
   {
      ocb = 7;
   }
   else if (((fabs(scb - 75)) < epsilon || scb > 75) && scb < 85)
   {
      ocb = 8;
   }
   else if (((fabs(scb - 85)) < epsilon || scb > 85) && scb < 92)
   {
      ocb = 9;
   }
   else if ((((fabs(scb - 92)) < epsilon || scb > 92) && scb < 100) || fabs(scb - 100) < epsilon)
   {
      ocb = 10;
   }
   else
   {
      ocb = 5;
   }

   if (((fabs(scm - 55)) < epsilon || scm > 55) && scm < 65)
   {
      ocm = 6;
   }
   else if (((fabs(scm - 65)) < epsilon || scm > 65) && scm < 75)
   {
      ocm = 7;
   }
   else if (((fabs(scm - 75)) < epsilon || scm > 75) && scm < 85)
   {
      ocm = 8;
   }
   else if (((fabs(scm - 85)) < epsilon || scm > 85) && scm < 92)
   {
      ocm = 9;
   }
   else if ((((fabs(scm - 92)) < epsilon || scm > 92) && scm < 100) || fabs(scm - 100) < epsilon)
   {
      ocm = 10;
   }
   else
   {
      ocm = 5;
   }



   if (ocb == 5 && oct == 5 && ocm == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((ocb > 5 && oct == 5 && ocm == 5) || (ocb == 5 && oct > 5 && ocm == 5) || (ocb == 5 && oct == 5 && ocm > 5))
   {
      printf("Jedan student je polozio.");
   }
   else if ((oct > 5 && ocb > 5 && ocm == 5) || (oct == 5 && ocb > 5 && ocm > 5) || (oct > 5 && ocb == 5 && ocm > 5))
   {
      printf("Dva studenta su polozila.");
   }
   else if (oct > 5 && ocb > 5 && ocm > 5)
   {
      printf("Sva tri studenta su polozila.");
   }


   if ((oct > 5 && ocb > 5 && ocm > 5) && (fabs(ocm - ocb) < epsilon) && (fabs(ocb - oct) < epsilon))
   {
      printf("\nSva tri studenta imaju istu ocjenu.");
   }

   else if ((oct > 5 && ocb > 5 && ocm > 5) && ((fabs(ocb - ocm) < epsilon) || (fabs(ocb - oct) < epsilon) || (fabs(oct - ocm) < epsilon)))
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }

   else if ((oct > 5 && ocb > 5 && ocm > 5) && ocb != oct && ocb != ocm && oct != ocm)
   {
      printf("\nSvaki student ima razlicitu ocjenu.");
   }



   return(0);
}
