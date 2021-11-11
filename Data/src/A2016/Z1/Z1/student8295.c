#include <stdio.h>

int main()
{
   double IP1, IIP1, P1, Z1, ZI1, IP2, IIP2, P2, Z2, ZI2, IP3, IIP3, P3, Z3, ZI3, O1, O2, O3;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IP1);
   if (IP1 > 20 || IP1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &IIP1);
   }
   if (IIP1 < 0 || IIP1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
      scanf("%lf", &P1);
      if (P1 < 0 || P1 > 10)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Zadace: ");
         scanf("%lf", &Z1);
      }
      if (Z1 < 0 || Z1 > 10)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Zavrsni ispit: ");
         scanf("%lf", &ZI1);
      }
      if (ZI1 < 0 || ZI1 > 40)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Unesite bodove za Bojana:\n");
         printf("I parcijalni ispit: ");
         scanf("%lf", &IP2);
      }
      if (IP2 > 20 || IP2 < 0)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("II parcijalni ispit: ");
         scanf("%lf", &IIP2);
      }
      if (IIP2 < 0 || IIP2 > 20)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &P2);
      }
      if (P2 < 0 || P2 > 10)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Zadace: ");
         scanf("%lf", &Z2);
      }
      if (Z2 < 0 || Z2 > 10)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Zavrsni ispit: ");
         scanf("%lf", &ZI2);
      }
      if (ZI2 < 0 || ZI2 > 40)
      {
         printf("Neispravan broj bodova"); return(0);
      }
      else
      {
         printf("Unesite bodove za Mirzu: \n");
         printf("I parcijalni ispit: ");
         scanf("%lf", &IP3);
      }
      if (IP3 > 20 || IP3 < 0)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("II parcijalni ispit: ");
         scanf("%lf", &IIP3);
      }
      if (IIP3 < 0 || IIP3 > 20)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &P3);
      }
      if (P3 < 0 || P3 > 10)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Zadace: ");
         scanf("%lf", &Z3);
      }
      if (Z3 < 0 || Z3 > 10)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Zavrsni ispit: ");
         scanf("%lf", &ZI3);
      }
      if (ZI3 < 0 || ZI3 > 40)
      {
         printf("Neispravan broj bodova");
         return(0);
      }



      if ((IP1 + IIP1 + Z1 + P1 + ZI1) < 55 && (IP2 + IIP2 + Z2 + P2 + ZI2) < 55 && (IP3 + IIP3 + Z3 + P3 + ZI3) < 55)
      {
         printf("Nijedan student nije polozio. \n");
      }
      else if ((IP1 + IIP1 + Z1 + P1 + ZI1) >= 55 && (IP2 + IIP2 + Z2 + P2 + ZI2) >= 55 && (IP3 + IIP3 + Z3 + P3 + ZI3) >= 55)
      {
         printf("Sva tri studenta su polozila.");
      }
      else if (((IP1 + IIP1 + Z1 + P1 + ZI1) < 55 && (IP2 + IIP2 + Z2 + P2 + ZI2) < 55 && (IP3 + IIP3 + Z3 + P3 + ZI3) >= 55) || ((IP1 + IIP1 + Z1 + P1 + ZI1) < 55 && (IP2 + IIP2 + Z2 + P2 + ZI2) >= 55 && (IP3 + IIP3 + Z3 + P3 + ZI3) < 55) || ((IP1 + IIP1 + Z1 + P1 + ZI1) >= 55 && (IP2 + IIP2 + Z2 + P2 + ZI2) < 55 && (IP3 + IIP3 + Z3 + P3 + ZI3) < 55))
      {
         printf("Jedan student je polozio.");
      }
      else if (((IP1 + IIP1 + Z1 + P1 + ZI1) >= 55 && (IP2 + IIP2 + Z2 + P2 + ZI2) >= 55 && (IP3 + IIP3 + Z3 + P3 + ZI3) < 55) || ((IP1 + IIP1 + Z1 + P1 + ZI1) < 55 && (IP2 + IIP2 + Z2 + P2 + ZI2) >= 55 && (IP3 + IIP3 + Z3 + P3 + ZI3) >= 55) || ((IP1 + IIP1 + Z1 + P1 + ZI1) >= 55 && (IP2 + IIP2 + Z2 + P2 + ZI2) < 55 && (IP3 + IIP3 + Z3 + P3 + ZI3) >= 55))
      {
         printf("Dva studenta su polozila.");
      }

      if ((IP1 + IIP1 + Z1 + P1 + ZI1) >= 55 && (IP1 + IIP1 + Z1 + P1 + ZI1) < 65)
      {
         O1 = 6;
      }
      else if ((IP1 + IIP1 + Z1 + P1 + ZI1) >= 65 && (IP1 + IIP1 + Z1 + P1 + ZI1) < 75)
      {
         O1 = 7;
      }
      else if ((IP1 + IIP1 + Z1 + P1 + ZI1) >= 75 && (IP1 + IIP1 + Z1 + P1 + ZI1) < 85)
      {
         O1 = 8;
      }
      else if ((IP1 + IIP1 + Z1 + P1 + ZI1) >= 85 && (IP1 + IIP1 + Z1 + P1 + ZI1) < 92)
      {
         O1 = 9;
      }
      else if ((IP1 + IIP1 + Z1 + P1 + ZI1) >= 92 && (IP1 + IIP1 + Z1 + P1 + ZI1) <= 100)
      {
         O1 = 10;
      }
      if ((IP2 + IIP2 + Z2 + P2 + ZI2) >= 55 && (IP2 + IIP2 + Z2 + P2 + ZI2) < 65)
      {
         O2 = 6;
      }
      else if ((IP2 + IIP2 + Z2 + P2 + ZI2) >= 65 && (IP2 + IIP2 + Z2 + P2 + ZI2) < 75)
      {
         O2 = 7;
      }
      else if ((IP2 + IIP2 + Z2 + P2 + ZI2) >= 75 && (IP2 + IIP2 + Z2 + P2 + ZI2) < 85)
      {
         O2 = 8;
      }
      else if ((IP2 + IIP2 + Z2 + P2 + ZI2) >= 85 && (IP2 + IIP2 + Z2 + P2 + ZI2) < 92)
      {
         O2 = 9;
      }
      else if ((IP2 + IIP2 + Z2 + P2 + ZI2) >= 92 && (IP2 + IIP2 + Z2 + P2 + ZI2) <= 100)
      {
         O2 = 10;
      }
      if ((IP3 + IIP3 + Z3 + P3 + ZI3) >= 55 && (IP3 + IIP3 + Z3 + P3 + ZI3) < 65)
      {
         O3 = 6;
      }
      else if ((IP3 + IIP3 + Z3 + P3 + ZI3) >= 65 && (IP3 + IIP3 + Z3 + P3 + ZI3) < 75)
      {
         O3 = 7;
      }
      else if ((IP3 + IIP3 + Z3 + P3 + ZI3) >= 75 && (IP3 + IIP3 + Z3 + P3 + ZI3) < 85)
      {
         O3 = 8;
      }
      else if ((IP3 + IIP3 + Z3 + P3 + ZI3) >= 85 && (IP3 + IIP3 + Z3 + P3 + ZI3) < 92)
      {
         O3 = 9;
      }
      else if ((IP3 + IIP3 + Z3 + P3 + ZI3) >= 92 && (IP3 + IIP3 + Z3 + P3 + ZI3) <= 100)
      {
         O3 = 10;
      }

      if ((IP1 + IIP1 + Z1 + P1 + ZI1) >= 55 && (IP2 + IIP2 + Z2 + P2 + ZI2) >= 55 && (IP3 + IIP3 + Z3 + P3 + ZI3) >= 55)
      {
         if (O1 == O2 && O2 == O3)
         {
            printf("\nSva tri studenta imaju istu ocjenu.");
         }
         else if (O1 == O2 && O1 != O3 || O1 == O3 && O1 != O2 || O2 == O3 && O1 != O2)
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
}
