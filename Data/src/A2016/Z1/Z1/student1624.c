#include <stdio.h>
#define EPSILON    0.01
int main()
{
   double ppit, dpit, prt, dzt, zit, ppib, dpib, prb, dzb, zib, ppim, dpim, prm, dzm, zim, ot, ob, om, bt, bb, bm;

   printf("Unesite bodove za Tarika:");
   printf("\nI parcijalni ispit:");
   scanf("%lf", &ppit);
   if (ppit < 0 || ppit > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%lf", &dpit);
   if (dpit < 0 || dpit > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%lf", &prt);
   if (prt < 0 || prt > 10)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%lf", &dzt);
   if (dzt < 0 || dzt > 10)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%lf", &zit);
   if (zit < 0 || zit > 40)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }


   bt = ppit + dpit + prt + dzt + zit;
   if (bt < 55)
   {
      ot = 5;
   }
   else if (bt >= 55 && bt < 65)
   {
      ot = 6;
   }
   else if (bt >= 65 && bt < 75)
   {
      ot = 7;
   }
   else if (bt >= 75 && bt < 85)
   {
      ot = 8;
   }
   else if (bt >= 85 && bt < 92)
   {
      ot = 9;
   }
   else if (bt >= 92 && bt <= 100)
   {
      ot = 10;
   }

   printf(" Unesite bodove za Bojana:");
   printf("\nI parcijalni ispit:");
   scanf("%lf", &ppib);
   if (ppib < 0 || ppib > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%lf", &dpib);
   if (dpib < 0 || dpib > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%lf", &prb);
   if (prb < 0 || prb > 10)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%lf", &dzb);
   if (dzb < 0 || dzb > 10)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%lf", &zib);
   if (zib < 0 || zib > 40)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }


   bb = ppib + dpib + prb + dzb + zib;
   if (bb < 55)
   {
      ob = 5;
   }
   else if (bb >= 55 && bb < 65)
   {
      ob = 6;
   }
   else if (bb >= 65 && bb < 75)
   {
      ob = 7;
   }
   else if (bb >= 75 && bb < 85)
   {
      ob = 8;
   }
   else if (bb >= 85 && bb < 92)
   {
      ob = 9;
   }
   else if (bb >= 92 && bb <= 100)
   {
      ob = 10;
   }

   printf(" Unesite bodove za Mirzu:");
   printf("\nI parcijalni ispit:");
   scanf("%lf", &ppim);
   if (ppim < 0 || ppim > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%lf", &dpim);
   if (dpim < 0 || dpim > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%lf", &prm);
   if (prm < 0 || prm > 10)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%lf", &dzm);
   if (dzm < 0 || dzm > 10)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%lf", &zim);
   if (zim < 0 || zim > 40)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }

   bm = ppim + dpim + prm + dzm + zim;
   if (bm < 55)
   {
      om = 5;
   }
   else if (bm >= 55 && bm < 65)
   {
      om = 6;
   }
   else if (bm >= 65 && bm < 75)
   {
      om = 7;
   }
   else if (bm >= 75 && bm < 85)
   {
      om = 8;
   }
   else if (bm >= 85 && bm < 92)
   {
      om = 9;
   }
   else if (bm >= 92 && bm <= 100)
   {
      om = 10;
   }

   if (bt >= 55 && bb >= 55 && bm >= 55)
   {
      printf(" Sva tri studenta su polozila.");
      if (ot == ob && ob == om)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (ot != ob && ot != om && ob != om)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
      else
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
   }
   else if (bt < 55 && bb < 55 && bm < 55)
   {
      printf(" Nijedan student nije polozio.");
   }
   else if ((bt >= 55 && bb >= 55 && bm < 55) || (bt >= 55 && bb < 55 && bm >= 55) || (bt < 55 && bb >= 55 && bm >= 55))
   {
      printf(" Dva studenta su polozila.");
   }
   else
   {
      printf(" Jedan student je polozio.");
   }
   return(0);
}
