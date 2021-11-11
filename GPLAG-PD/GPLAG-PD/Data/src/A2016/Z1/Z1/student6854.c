#include <stdio.h>

int main()
{
   double p1t, p2t, pt, zt, zit, p1b, p2b, pb, zb, zib, p1m, p2m, pm, zm, zim, ut, ub, um, ot, ob, om;

   printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
   scanf("%lf", &p1t);
   if (p1t < 0 || p1t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2t);
   if (p2t < 0 || p2t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pt);
   if (pt < 0 || pt > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zt);
   if (zt < 0 || zt > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zit);
   if (zit < 0 || zit > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ut = p1t + p2t + pt + zt + zit;
   printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
   scanf("%lf", &p1b);
   if (p1b < 0 || p1b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2b);
   if (p2b < 0 || p2b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pb);
   if (pb < 0 || pb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zb);
   if (zb < 0 || zb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zib);
   if (zib < 0 || zib > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ub = p1b + p2b + pb + zb + zib;
   printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
   scanf("%lf", &p1m);
   if (p1m < 0 || p1m > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2m);
   if (p2m < 0 || p2m > 20)
   {
      printf("Neispravan broj bodova: ");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pm);
   if (pm < 0 || pm > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zm);
   if (zm < 0 || zm > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zim);
   if (zim < 0 || zim > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   um = p1m + p2m + pm + zm + zim;

   if (ut < 55)
   {
      ot = 5;
   }
   else if (ut >= 55 && ut < 65)
   {
      ot = 6;
   }
   else if (ut >= 65 && ut < 75)
   {
      ot = 7;
   }
   else if (ut >= 75 && ut < 85)
   {
      ot = 8;
   }
   else if (ut >= 85 && ut < 92)
   {
      ot = 9;
   }
   else if (ut >= 92 && ut <= 100)
   {
      ot = 10;
   }
   if (ub < 55)
   {
      ob = 5;
   }
   else if (ub >= 55 && ub < 65)
   {
      ob = 6;
   }
   else if (ub >= 65 && ub < 75)
   {
      ob = 7;
   }
   else if (ub >= 75 && ub < 85)
   {
      ob = 8;
   }
   else if (ub >= 85 && ub < 92)
   {
      ob = 9;
   }
   else if (ub >= 92 && ub <= 100)
   {
      ob = 10;
   }
   if (um < 55)
   {
      om = 5;
   }
   else if (um >= 55 && um < 65)
   {
      om = 6;
   }
   else if (um >= 65 && um < 75)
   {
      om = 7;
   }
   else if (um >= 75 && um < 85)
   {
      om = 8;
   }
   else if (um >= 85 && um < 92)
   {
      om = 9;
   }
   else if (um >= 92 && um <= 100)
   {
      om = 10;
   }
   if (ut < 55 && ub < 55 && um < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((ut >= 55 && ub < 55 && um < 55) || (ut < 55 && ub >= 55 && um < 55) || (ut < 55 && ub < 55 && um >= 55))
   {
      printf("Jedan student je polozio.");
   }
   else if ((ut < 55 && ub >= 55 && um >= 55) || (ut >= 55 && ub < 55 && um >= 55) || (ut >= 55 && ub >= 55 && um < 55))
   {
      printf("Dva studenta su polozila.");
   }
   else if (ut >= 55 && ub >= 55 && um >= 55)
   {
      printf("Sva tri studenta su polozila.");
      if (ot != ob && ot != om)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
      else if ((ot == 6 && ob == 6 && om == 6) || (ot == 7 && ob == 7 && om == 7) || (ot == 8 && ob == 8 && om == 8) || (ot == 9 && ob == 9 && om == 9) || (ot == 10 && ob == 10 && om == 10))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
   }
   return(0);
}
