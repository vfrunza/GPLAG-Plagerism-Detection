#include <stdio.h>
#include <math.h>
#define E    0.00000000001

int main()
{
   double ti, tii, tp, tz, tzi, bi, bii, bp, bz, bzi, mi, mii, mp, mz, mzi, to, mo, bo;
   int    polozio = 3, sest = 0, sedam = 0, osam = 0, devet = 0, deset = 0;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &ti);
   if (ti > 20 || ti < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%lf", &tii);
   if (tii > 20 || tii < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &tp);
   if (tp > 10 || tp < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &tz);
   if (tz > 10 || tz < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &tzi);
   if (tzi > 40 || tzi < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   to = ti + tii + tp + tz + tzi;
   if (to < 55)
   {
      polozio--;
   }
   else if ((to >= 5 && to < 65))
   {
      sest++;
   }
   else if (to >= 65 && to < 75)
   {
      sedam++;
   }
   else if (to >= 75 && to < 85)
   {
      osam++;
   }
   else if (to >= 85 && to < 92)
   {
      devet++;
   }
   else if (to >= 92 && to < 100)
   {
      deset++;
   }

   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &bi);
   if (bi > 20 || bi < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &bii);
   if (bii > 20 || bii < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &bp);
   if (bp > 10 || bp < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &bz);
   if (bz > 10 || bz < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bzi);
   if (bzi > 40 || bzi < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   bo = bi + bii + bp + bz + bzi;
   if (bo < 55)
   {
      polozio--;
   }
   else if (bo >= 55 && bo < 65)
   {
      sest++;
   }
   else if (bo >= 65 && bo < 75)
   {
      sedam++;
   }
   else if (bo >= 75 && bo < 85)
   {
      osam++;
   }
   else if (bo >= 85 && bo < 92)
   {
      devet++;
   }
   else if (bo >= 92 && bo < 100)
   {
      deset++;
   }
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &mi);
   if (mi > 20 || mi < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &mii);
   if (mii > 20 || mii < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &mp);
   if (mp > 10 || mp < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &mz);
   if (mz > 10 || mz < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &mzi);
   if (mzi > 40 || mzi < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   mo = mi + mii + mp + mz + mzi;
   if (mo < 55)
   {
      polozio--;
   }
   else if (mo >= 55 && mo < 65)
   {
      sest++;
   }
   else if (mo >= 65 && mo < 75)
   {
      sedam++;
   }
   else if (mo >= 75 && mo < 85)
   {
      osam++;
   }
   else if (mo >= 85 && mo < 92)
   {
      devet++;
   }
   else if (mo >= 92 && mo < 100)
   {
      deset++;
   }

   switch (polozio)
   {
   case 0:
      printf("Nijedan student nije polozio.");
      return(0);

   case 1:
      printf("Jedan student je polozio.");
      break;

   case 2:
      printf("Dva studenta su polozila.");
      break;

   case 3:
      printf("Sva tri studenta su polozila.");
   }
   ;
   if (polozio == 3)
   {
      if (sest <= 1 && sedam <= 1 && osam <= 1 && devet <= 1 && deset <= 1)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
      else if (sest == 2 || sedam == 2 || osam == 2 || devet == 2 || deset == 2)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (sest == 3 || sedam == 3 || osam == 3 || devet == 3 || deset == 3)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
   }
   ;
   return(0);
}
