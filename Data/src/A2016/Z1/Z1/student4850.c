#include <stdio.h>
#define e    0.001

int main()
{
   float P1T, P2T, ZIT, ZT, PRT, BT, P1B, P2B, ZIB, ZB, PRB, BB, P1M, P2M, ZIM, ZM, PRM, BM;
   int   OT, OB, OM;

   printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
   scanf("%f", &P1T);
   if (P1T > 20 || P1T < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &P2T);
   if (P2T > 20 || P2T < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &PRT);
   if (PRT > 10 || PRT < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &ZT);
   if (ZT > 10 || ZT < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZIT);
   if (ZIT > 40 || ZIT < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
   scanf("%f", &P1B);
   if (P1B > 20 || P1B < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &P2B);
   if (P2B > 20 || P2B < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &PRB);
   if (PRB > 10 || PRB < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &ZB);
   if (ZB > 10 || ZB < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZIB);
   if (ZIB > 40 || ZIB < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
   scanf("%f", &P1M);
   if (P1M > 20 || P1M < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &P2M);
   if (P2M > 20 || P2M < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &PRM);
   if (PRM > 10 || PRM < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &ZM);
   if (ZM > 10 || ZM < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZIM);
   if (ZIM > 40 || ZIM < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   BT = P1T + P2T + ZIT + ZT + PRT;
   BB = P1B + P2B + ZIB + ZB + PRB;
   BM = P1M + P2M + ZIM + ZM + PRM;

   if (BT < 55)
   {
      OT = 5;
   }
   else if (BT < 65)
   {
      OT = 6;
   }
   else if (BT < 75)
   {
      OT = 7;
   }
   else if (BT < 85)
   {
      OT = 8;
   }
   else if (BT < 92)
   {
      OT = 9;
   }
   else
   {
      OT = 10;
   }

   if (BB < 55)
   {
      OB = 5;
   }
   else if (BB < 65)
   {
      OB = 6;
   }
   else if (BB < 75)
   {
      OB = 7;
   }
   else if (BB < 85)
   {
      OB = 8;
   }
   else if (BB < 92)
   {
      OB = 9;
   }
   else
   {
      OB = 10;
   }

   if (BM < 55)
   {
      OM = 5;
   }
   else if (BM < 65)
   {
      OM = 6;
   }
   else if (BM < 75)
   {
      OM = 7;
   }
   else if (BM < 85)
   {
      OM = 8;
   }
   else if (BM < 92)
   {
      OM = 9;
   }
   else
   {
      OM = 10;
   }

   if (OT == 5 && OB == 5 && OM == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (OT != 5 && OB != 5 && OM != 5)
   {
      printf("Sva tri studenta su polozila. ");
   }
   else if ((OT == 5 && OB == 5 && OM != 5) || (OT == 5 && OB != 5 && OM == 5) || (OT != 5 && OB == 5 && OM == 5))
   {
      printf("Jedan student je polozio.");
   }
   else
   {
      printf("Dva studenta su polozila.");
   }

   if (OT != 5 && OB != 5 && OM != 5 && OT == OB && OB == OM)
   {
      printf("\nSva tri studenta imaju istu ocjenu.");
   }
   else if (OT != 5 && OB != 5 && OM != 5 && OT != OB && OB != OM && OM != OT)
   {
      printf("\nSvaki student ima razlicitu ocjenu.");
   }
   else if (OT == 5 || OB == 5 || OM == 5)
   {
   }
   else
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   return(0);
}
