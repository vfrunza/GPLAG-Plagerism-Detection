#include <stdio.h>
#include <math.h>

int main()
{
   double PP1, PP2, PP3, DP1, DP2, DP3, P1, P2, P3, Z1, Z2, Z3, ZI1, ZI2, ZI3;
   double UK1, UK2, UK3;
   int    O1, O2, O3;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &PP1);
   if (PP1 > 20 || PP1 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DP1);
   if (DP1 > 20 || DP1 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &P1);
   if (P1 > 10 || P1 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z1);
   if (Z1 > 10 || Z1 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI1);
   if (ZI1 > 40 || ZI1 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }

   UK1 = PP1 + DP1 + P1 + Z1 + ZI1;

   if (UK1 < 55)
   {
      O1 = 0;
   }
   else
   {
      if ((PP1 + DP1 + P1 + Z1 + ZI1) >= 55 && (PP1 + DP1 + P1 + Z1 + ZI1) < 65)
      {
         O1 = 6;
      }
      if ((PP1 + DP1 + P1 + Z1 + ZI1) >= 65 && (PP1 + DP1 + P1 + Z1 + ZI1) < 75)
      {
         O1 = 7;
      }
      if ((PP1 + DP1 + P1 + Z1 + ZI1) >= 75 && (PP1 + DP1 + P1 + Z1 + ZI1) < 85)
      {
         O1 = 8;
      }
      if ((PP1 + DP1 + P1 + Z1 + ZI1) >= 85 && (PP1 + DP1 + P1 + Z1 + ZI1) < 95)
      {
         O1 = 9;
      }
      if ((PP1 + DP1 + P1 + Z1 + ZI1) >= 95 && (PP1 + DP1 + P1 + Z1 + ZI1) <= 100)
      {
         O1 = 10;
      }
   }


   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &PP2);
   if (PP2 > 20 || PP2 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DP2);
   if (DP2 > 20 || DP2 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &P2);
   if (P2 > 10 || P2 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z2);
   if (Z2 > 10 || Z2 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI2);
   if (ZI2 > 40 || ZI2 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }

   UK2 = PP2 + DP2 + P2 + Z2 + ZI2;

   if (UK2 < 55)
   {
      O2 = 0;
   }
   else
   {
      if ((PP2 + DP2 + P2 + Z2 + ZI2) >= 55 && (PP2 + DP2 + P2 + Z2 + ZI2) < 65)
      {
         O2 = 6;
      }
      else if ((PP2 + DP2 + P2 + Z2 + ZI2) >= 65 && (PP2 + DP2 + P2 + Z2 + ZI2) < 75)
      {
         O2 = 7;
      }
      else if ((PP2 + DP2 + P2 + Z2 + ZI2) >= 75 && (PP2 + DP2 + P2 + Z2 + ZI2) < 85)
      {
         O2 = 8;
      }
      else if ((PP2 + DP2 + P2 + Z2 + ZI2) >= 85 && (PP2 + DP2 + P2 + Z2 + ZI2) < 95)
      {
         O2 = 9;
      }
      else if ((PP2 + DP2 + P2 + Z2 + ZI2) >= 95 && (PP2 + DP2 + P2 + Z2 + ZI2) <= 100)
      {
         O2 = 10;
      }
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &PP3);
   if (PP3 > 20 || PP3 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DP3);
   if (DP3 > 20 || DP3 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &P3);
   if (P3 > 10 || P3 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z3);
   if (Z3 > 10 || Z3 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI3);
   if (ZI3 > 40 || ZI3 < 0)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }

   UK3 = PP3 + DP3 + P3 + Z3 + ZI3;

   if (UK3 < 55)
   {
      O3 = 0;
   }
   else
   {
      if ((PP3 + DP3 + P3 + Z3 + ZI3) >= 55 && (PP3 + DP3 + P3 + Z3 + ZI3) < 65)
      {
         O3 = 6;
      }
      else if ((PP3 + DP3 + P3 + Z3 + ZI3) >= 65 && (PP3 + DP3 + P3 + Z3 + ZI3) < 75)
      {
         O3 = 7;
      }
      else if ((PP3 + DP3 + P3 + Z3 + ZI3) >= 75 && (PP3 + DP3 + P3 + Z3 + ZI3) < 85)
      {
         O3 = 8;
      }
      else if ((PP3 + DP3 + P3 + Z3 + ZI3) >= 85 && (PP3 + DP3 + P3 + Z3 + ZI3) < 95)
      {
         O3 = 9;
      }
      else if ((PP3 + DP3 + P3 + Z3 + ZI3) >= 95 && (PP3 + DP3 + P3 + Z3 + ZI3) <= 100)
      {
         O3 = 10;
      }
   }

   if (O1 == 0 && O2 == 0 && O3 == 0)
   {
      printf("Nijedan student nije polozio. \n");
   }
   if (O1 != 0 && O2 != 0 && O3 != 0)
   {
      printf("Sva tri studenta su polozila. \n");
   }
   if ((O1 != 0 && O2 == 0 && O3 == 0) || (O1 == 0 && O2 != 0 && O3 == 0) || (O1 == 0 && O2 == 0 && O3 != 0))
   {
      printf("Jedan student je polozio. \n");
   }
   if ((O1 != 0 && O2 != 0 && O3 == 0) || (O1 == 0 && O2 != 0 && O3 != 0) || (O1 != 0 && O2 == 0 && O3 != 0))
   {
      printf("Dva studenta su polozila. \n");
   }

   if (O1 != 0 && O2 != 0 && O3 != 0)
   {
      if (O1 == O2 && O1 == O3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      if ((O1 == O2 && O2 != O3) || (O2 == O3 && O2 != O1) || (O1 == O3 && O1 != O2))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (O1 != O2 && O1 != O3 && O2 != O3)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
