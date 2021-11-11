#include <stdio.h>

int main()
{
   double ppiT, dpiT, prT, zadT, zispT;       /*ppi-prvi parcijalni ispit, dpi-drugi parcijalni ispit, pr-prisustvo, zad-zadace */
   double ppiB, dpiB, prB, zadB, zispB;       /*zisp-zavrsni ispit*/
   double ppiM, dpiM, prM, zadM, zispM;
   double brbodovaTarik, brbodovaBojan, brbodovaMirza;
   int    ocjenaTarik = 0, ocjenaBojan = 0, ocjenaMirza = 0;

   printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
   scanf("%lf", &ppiT);
   if (ppiT > 20 || ppiT < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dpiT);
   if (dpiT > 20 || dpiT < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prT);
   if (prT > 10 || prT < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadT);
   if (zadT < 0 || zadT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zispT);
   if (zispT < 0 || zispT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
   scanf("%lf", &ppiB);
   if (ppiB < 0 || ppiB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dpiB);
   if (dpiB < 0 || dpiB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prB);
   if (prB < 0 || prB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadB);
   if (zadB < 0 || zadB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zispB);
   if (zispB > 40 || zispB < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
   scanf("%lf", &ppiM);
   if (ppiM < 0 || ppiM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dpiM);
   if (dpiM < 0 || dpiM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prM);
   if (prM < 0 || prM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadM);
   if (zadM < 0 || zadM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zispM);
   if (zispM < 0 || zispM > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   brbodovaTarik = ppiT + dpiT + prT + zadT + zispT;
   brbodovaBojan = ppiB + dpiB + prB + zadB + zispB;
   brbodovaMirza = ppiM + dpiM + prM + zadM + zispM;
   if (brbodovaTarik >= 55 && brbodovaTarik < 65)
   {
      ocjenaTarik = 6;
   }
   if (brbodovaTarik >= 65 && brbodovaTarik < 75)
   {
      ocjenaTarik = 7;
   }
   if (brbodovaTarik >= 75 && brbodovaTarik < 85)
   {
      ocjenaTarik = 8;
   }
   if (brbodovaTarik >= 85 && brbodovaTarik < 92)
   {
      ocjenaTarik = 9;
   }
   if (brbodovaTarik >= 92 && brbodovaTarik <= 100)
   {
      ocjenaTarik = 10;
   }
   if (brbodovaBojan >= 55 && brbodovaBojan < 65)
   {
      ocjenaBojan = 6;
   }
   if (brbodovaBojan >= 65 && brbodovaBojan < 75)
   {
      ocjenaBojan = 7;
   }
   if (brbodovaBojan >= 75 && brbodovaBojan < 85)
   {
      ocjenaBojan = 8;
   }
   if (brbodovaBojan >= 85 && brbodovaBojan < 92)
   {
      ocjenaBojan = 9;
   }
   if (brbodovaBojan >= 92 && brbodovaBojan <= 100)
   {
      ocjenaBojan = 10;
   }
   if (brbodovaMirza >= 55 && brbodovaMirza < 65)
   {
      ocjenaMirza = 6;
   }
   if (brbodovaMirza >= 65 && brbodovaMirza < 75)
   {
      ocjenaMirza = 7;
   }
   if (brbodovaMirza >= 75 && brbodovaMirza < 85)
   {
      ocjenaMirza = 8;
   }
   if (brbodovaMirza >= 85 && brbodovaMirza < 92)
   {
      ocjenaMirza = 9;
   }
   if (brbodovaMirza >= 92 && brbodovaMirza <= 100)
   {
      ocjenaMirza = 10;
   }
   if (brbodovaTarik < 55 && brbodovaBojan < 55 && brbodovaMirza < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (brbodovaTarik >= 55 && brbodovaBojan >= 55 && brbodovaMirza >= 55)
   {
      printf("Sva tri studenta su polozila.");
      if (ocjenaMirza == ocjenaBojan && ocjenaBojan == ocjenaTarik)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (ocjenaMirza != ocjenaBojan && ocjenaBojan != ocjenaTarik && ocjenaTarik != ocjenaMirza)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
      else
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
   }
   else if ((brbodovaTarik >= 55 && brbodovaBojan >= 55 && brbodovaMirza < 55) || (brbodovaTarik >= 55 && brbodovaBojan < 55 && brbodovaMirza >= 55) ||
            (brbodovaTarik < 55 && brbodovaBojan >= 55 && brbodovaMirza >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   else
   {
      printf("Jedan student je polozio.");
   }
   return(0);
}
