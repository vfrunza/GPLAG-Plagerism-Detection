#include <stdio.h>
#define PET      55.0
#define SEST     65.0
#define SEDAM    75.0
#define OSAM     85.0
#define DEVET    92.0
#define DESET    100.0

int main()
{
   double PP1, DP1, P1, Z1, ZI1, PP2, DP2, P2, Z2, ZI2, PP3, DP3, P3, Z3, ZI3, ZbirTarik, ZbirBojan, ZbirMirza, OT, OB, OM;


   printf("Unesite bodove za Tarika:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &PP1);
   if (PP1 < 0 || PP1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &DP1);
   if (DP1 < 0 || DP1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &P1);
   if (P1 < 0 || P1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z1);
   if (Z1 < 0 || Z1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI1);
   if (ZI1 < 0 || ZI1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &PP2);
   if (PP2 < 0 || PP2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DP2);
   if (DP2 < 0 || DP2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &P2);
   if (P2 < 0 || P2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z2);
   if (Z2 < 0 || Z2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI2);
   if (ZI2 < 0 || ZI2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &PP3);
   if (PP3 < 0 || PP3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DP3);
   if (DP3 < 0 || DP3 > 20)
   {
      printf("Neisprava broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &P3);
   if (P3 < 0 || P3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z3);
   if (Z3 < 0 || Z3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI3);
   if (ZI3 < 0 || ZI3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ZbirTarik = PP1 + DP1 + P1 + Z1 + ZI1;
   ZbirBojan = PP2 + DP2 + P2 + Z2 + ZI2;
   ZbirMirza = PP3 + DP3 + P3 + Z3 + ZI3;

   OT = ZbirTarik;
   OB = ZbirBojan;
   OM = ZbirMirza;

   if (OT >= PET && OT < SEST)
   {
      OT = 6;
   }
   else
   if (OT >= SEST && OT < SEDAM)
   {
      OT = 7;
   }
   else
   if (OT >= SEDAM && OT < OSAM)
   {
      OT = 8;
   }
   else
   if (OT >= OSAM && OT < DEVET)
   {
      OT = 9;
   }
   else
   if (OT >= DEVET && OT <= DESET)
   {
      OT = 10;
   }

   if (OB >= PET && OB < SEST)
   {
      OB = 6;
   }
   else
   if (OB >= SEST && OB < SEDAM)
   {
      OB = 7;
   }
   else
   if (OB >= SEDAM && OB < OSAM)
   {
      OB = 8;
   }
   else
   if (OB >= OSAM && OB < DEVET)
   {
      OB = 9;
   }
   else
   if (OB >= DEVET && OB <= DESET)
   {
      OB = 10;
   }

   if (OM >= PET && OM < SEST)
   {
      OM = 6;
   }
   else
   if (OM >= SEST && OM < SEDAM)
   {
      OM = 7;
   }
   else
   if (OM >= SEDAM && OM < OSAM)
   {
      OM = 8;
   }
   else
   if (OM >= OSAM && OM < DEVET)
   {
      OM = 9;
   }
   else
   if (OM >= DEVET && OM <= DESET)
   {
      OM = 10;
   }

   if (ZbirTarik < 55 && ZbirBojan < 55 && ZbirMirza < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else
   if ((ZbirTarik < 55 && ZbirBojan < 55 && ZbirMirza >= 55) || (ZbirTarik < 55 && ZbirBojan >= 55 && ZbirMirza < 55) || (ZbirTarik >= 55 && ZbirBojan < 55 && ZbirMirza < 55))
   {
      printf("Jedan student je polozio.");
   }
   else
   if ((ZbirTarik >= 55 && ZbirBojan >= 55 && ZbirMirza < 55) || (ZbirTarik >= 55 && ZbirBojan < 55 && ZbirMirza >= 55) || (ZbirTarik < 55 && ZbirBojan >= 55 && ZbirMirza >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   else
   if (ZbirTarik >= 55 && ZbirBojan >= 55 && ZbirMirza >= 55)
   {
      printf("Sva tri studenta su polozila.");

      if (OT == OM && OT == OB)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else
      if ((OT != OM && OB == OM) || (OT != OB && OT == OM) || (OT != OM && OT == OB))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      if (OT != OB && OT != OM && OM != OB)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
