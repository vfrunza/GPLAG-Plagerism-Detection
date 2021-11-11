#include <stdio.h>
#include <math.h>
#define E    0.000001
int main()
{
   double PPIT, DPIT, PT, ZT, ZIT, PPIB, DPIB, PB, ZB, ZIB, PPIM, DPIM, PM, ZM, ZIM, BBT, BBB, BBM, OT, OB, OM;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: "); scanf("%lf", &PPIT);
   if ((PPIT < 0) || (PPIT > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &DPIT);
   if ((DPIT < 0) || (DPIT > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &PT);
   if ((PT < 0) || (PT > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: "); scanf("%lf", &ZT);
   if ((ZT < 0) || (ZT > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &ZIT);
   if ((ZIT > 40) || (ZIT < 0))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: "); scanf("%lf", &PPIB);
   if ((PPIB) < 0 || (PPIB > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &DPIB);
   if ((DPIB < 0) || (DPIB > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &PB);
   if ((PB < 0) || (PB > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: "); scanf("%lf", &ZB);
   if ((ZB < 0) || (ZB > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &ZIB);
   if ((ZIB < 0) || (ZIB > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: "); scanf("%lf", &PPIM);
   if ((PPIM < 0) || (PPIM > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &DPIM);
   if ((DPIM < 0) || (DPIM > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: "); scanf("%lf", &PM);
   if ((PM < 0) || (PM > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: "); scanf("%lf", &ZM);

   if ((ZM < 0) || (ZM > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: "); scanf("%lf", &ZIM);
   if ((ZIM < 0) || (ZIM > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   BBT = PPIT + DPIT + PT + ZT + ZIT;
   BBB = PPIB + DPIB + PB + ZB + ZIB;
   BBM = PPIM + DPIM + PM + ZM + ZIM;

   if (BBT < 55)
   {
      OT = 5;
   }
   if ((BBT >= 55) && (BBT < 65))
   {
      OT = 6;
   }
   if ((BBT >= 65) && (BBT < 75))
   {
      OT = 7;
   }
   if ((BBT >= 75) && (BBT < 85))
   {
      OT = 8;
   }
   if ((BBT >= 85) && (BBT < 92))
   {
      OT = 9;
   }
   if ((BBT >= 92) && (BBT <= 100))
   {
      OT = 10;
   }
   if (BBB < 55)
   {
      OB = 5;
   }
   if ((BBB >= 55) && (BBB < 65))
   {
      OB = 6;
   }
   if ((BBB >= 65) && (BBB < 75))
   {
      OB = 7;
   }
   if ((BBB >= 75) && (BBB < 85))
   {
      OB = 8;
   }
   if ((BBB >= 85) && (BBB < 92))
   {
      OB = 9;
   }
   if ((BBB >= 92) && (BBB <= 100))
   {
      OB = 10;
   }
   if (BBM < 55)
   {
      OM = 5;
   }
   if ((BBM >= 55) && (BBM < 65))
   {
      OM = 6;
   }
   if ((BBM >= 65) && (BBM < 75))
   {
      OM = 7;
   }
   if ((BBM >= 75) && (BBM < 85))
   {
      OM = 8;
   }
   if ((BBM >= 85) && (BBM < 92))
   {
      OM = 9;
   }
   if ((BBM >= 92) && (BBM <= 100))
   {
      OM = 10;
   }
   if ((OM == 5) && (OB == 5) && (OT == 5))
   {
      printf("Nijedan student nije polozio.");
   }
   if (((OT > 5) && (OM <= 5) && (OB <= 5)) || ((OT <= 5) && (OM > 5) && (OB <= 5)) || ((OT <= 5) && (OM <= 5) && (OB > 5)))
   {
      printf("Jedan student je polozio.");
   }
   if (((OT <= 5) && (OB > 5) && (OM > 5)) || ((OT > 5) && (OB > 5) && (OM <= 5)) || ((OT > 5) && (OB <= 5) && (OM > 5)))
   {
      printf("Dva studenta su polozila.");
   }

   if ((OM > 5) && (OT > 5) && (OB > 5))
   {
      printf("Sva tri studenta su polozila.");
      if ((OT == OB) && (OT == OM) && (OM == OB))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((OT != OB) && (OT != OM) && (OB != OM))
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
      else
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
   }

   return(0);
}
