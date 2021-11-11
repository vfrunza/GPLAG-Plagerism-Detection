#include <stdio.h>

int main()
{
   double p1t, p1b, p1m, p2t, p2b, p2m, prt, prb, prm, zadt, zadb, zadm, zit, zib, zim, ut, ub, um;
   int    np, o6, o7, o8, o9, o10;

   printf("\n Unesite bodove za Tarika:");
   printf("\n I parcijalni ispit: ");
   scanf("%f", &p1t);
   if (p1t < 0 || p1t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("\n II parcijalni ispit: ");
   scanf("%f", &p2t);
   if (p2t < 0 || p2t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("\n Prisustvo: ");
   scanf("%f", &prt);
   if (prt < 0 || prt > 10)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   printf("\n Zadaće: ");
   scanf("%f", &zadt);
   if (zadt < 0.00 || zadt > 10.00)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   printf("\n Završni ispit: ");
   scanf("%f", &zit);
   if (zit < 0 || zit > 40)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   printf("\n Unesite bodove za Bojana:");
   printf("\n I parcijalni ispit: ");
   scanf("%f", &p1b);
   if (p1b < 0 || p1b > 20)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   printf("\n II parcijalni ispit: ");
   scanf("%f", &p2b);
   if (p2b < 0 || p2b > 20)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   printf("\n Prisustvo: ");
   scanf("%f", &prb);
   if (prb < 0 || prb > 10)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   printf("\n Zadaće: ");
   scanf("%f", &zadb);
   if (zadb < 0 || zadb > 10)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   printf("\n Završni ispit: ");
   scanf("%f", &zib);
   if (zib < 0 || zib > 40)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   printf("\n Unesite bodove za Mirzu:");
   printf("\n I parcijalni ispit: ");
   scanf("%f", &p1m);
   if (p1m < 0 || p1m > 20)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   printf("\n II parcijalni ispit: ");
   scanf("%f", &p2m);
   if (p2m < 0 || p2m > 20)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   printf("\n Prisustvo: ");
   scanf("%f", &prm);
   if (prm < 0 || prm > 10)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   printf("\n Zadaće: ");
   scanf("%f", &zadm);
   if (zadm < 0 || zadm > 10)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   printf("\n Završni ispit: ");
   scanf("%f", &zim);
   if (zim < 0 || zim > 40)
   {
      printf("\n Neispravan broj bodova");
      return(0);
   }
   ut = p1t + p2t + prt + zadt + zit;
   ub = p1b + p2b + prb + zadb + zib;
   um = p1m + p2m + prm + zadm + zim;
   if (um < 55)
   {
      np = np++;
   }
   if (um >= 55 && um < 65)
   {
      o6 = o6++;
   }
   if (um >= 65 && um < 75)
   {
      o7 = o7++;
   }
   if (um >= 75 && um < 85)
   {
      o8 = o8++;
   }
   if (um >= 85 && um < 92)
   {
      o9 = o9++;
   }
   if (um >= 92 && um < 100)
   {
      o10 = o10++;
   }
   if (np == 0)
   {
      printf("\n Sva tri studenta su položila.");
   }
   if (np == 1)
   {
      printf("\n Dva studenta su položila.");
   }
   if (np == 2)
   {
      printf("\n Jedan student je položio.");
   }
   if (np == 3)
   {
      printf("\n Nijedan student nije položio.");
   }
   if (o6 == 3)
   {
      ||
      (o7 == 3) || (o8 == 3) || (o9 == 3) || (o10 == 3)
      {
         printf("\n Sva tri studenta imaju istu ocjenu.");
      }
   }
   if (o6 == 2)
   {
      ||
      (o7 == 2) || (o8 == 2) || (o9 == 2) || (o10 == 2)
      {
         printf("\n Dva od tri studenta imaju istu ocjenu.");
      }
   }
   if (o6 == 1)
   {
      ||
      (o7 == 1) || (o8 == 1) || (o9 == 1) || (o10 == 1)
      {
         printf("\n Sva tri studenta imaju različitu ocjenu.");
      }
   }
   return(0);
}
