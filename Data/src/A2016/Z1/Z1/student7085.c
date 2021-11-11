#include <stdio.h>
#include <math.h>
#define e    0.0001
int main()
{
   float PP1, DP1, P1, Z1, ZI1, T, PP2, DP2, P2, Z2, ZI2, B, PP3, DP3, P3, Z3, ZI3, M, T1, B1, M1;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &PP1);
   if (PP1 < 0 || PP1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%f", &DP1);
   if (DP1 < 0 || DP1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   scanf("%f", &P1);
   if (P1 < 0 || P1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   scanf("%f", &Z1);
   if (Z1 < 0 || Z1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   scanf("%f", &ZI1);
   if (ZI1 < 0 || ZI1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   T = PP1 + DP1 + P1 + Z1 + ZI1;



   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &PP2);
   if (PP2 < 0 || PP2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%f", &DP2);
   if (DP2 < 0 || DP2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   scanf("%f", &P2);
   if (P2 < 0 || P2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   scanf("%f", &Z2);
   if (Z2 < 0 || Z2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   scanf("%f", &ZI2);
   if (ZI2 < 0 || ZI2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   B = PP2 + DP2 + P2 + Z2 + ZI2;



   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &PP3);
   if (PP3 < 0 || PP3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%f", &DP3);
   if (DP3 < 0 || DP3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   scanf("%f", &P3);
   if (P3 < 0 || P3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   scanf("%f", &Z3);
   if (Z3 < 0 || Z3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   scanf("%f", &ZI3);
   if (ZI3 < 0 || ZI3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   M = PP3 + DP3 + P3 + Z3 + ZI3;



   if (T < 55.0)
   {
      T1 = 0;
   }
   else
   if ((fabs(T - 55.0) < e || T > 55.0) && T < 65.0)
   {
      T1 = 6;
   }
   else
   if ((fabs(T - 65.0) < e || T > 65.0) && T < 75.0)
   {
      T1 = 7;
   }
   else
   if ((fabs(T - 75.0) < e || T > 75.0) && T < 85.0)
   {
      T1 = 8;
   }
   else
   if (T > 85.0 && T < 92.0)
   {
      T1 = 9;
   }
   else
   if ((fabs(T - 92.0) < e || T > 92.0) && (T < 100.0 || fabs(T - 100.0) < e))
   {
      T1 = 10;
   }

   if (B < 55.0)
   {
      B1 = 0;
   }
   else
   if ((fabs(B - 55.0) < e || B > 55.0) && B < 65.0)
   {
      B1 = 6;
   }
   else
   if ((fabs(B - 65.0) < e || B > 65.0) && B < 75.0)
   {
      B1 = 7;
   }
   else
   if ((fabs(B - 75.0) < e || B > 75.0) && B < 85.0)
   {
      B1 = 8;
   }
   else
   if (B > 85.0 && B < 92.0)
   {
      B1 = 9;
   }
   else
   if ((fabs(B - 92.0) < e || B > 92.0) && (B < 100.0 || fabs(B - 100.0) < e))
   {
      B1 = 10;
   }

   if (M < 55.0)
   {
      M1 = 0;
   }
   else
   if ((fabs(T - 55.0) < e || M > 55.0) && M < 65.0)
   {
      M1 = 6;
   }
   else
   if ((fabs(M - 65.0) < e || M > 65.0) && M < 75.0)
   {
      M1 = 7;
   }
   else
   if ((fabs(M - 75.0) < e || M > 75.0) && M < 85.0)
   {
      M1 = 8;
   }
   else
   if (M > 85.0 && M < 92.0)
   {
      M1 = 9;
   }
   else
   if ((fabs(M - 92.0) < e || M > 92.0) && (M < 100.0 || fabs(M - 100.0) < e))
   {
      M1 = 10;
   }

   if (((fabs(T - 55.0) < e || T > 55.0) && B < 55.0 && M < 55.0) || (T < 55.0 && (fabs(B - 55.0) < e || B > 55.0) && M < 55.0) || (T < 55.0 && B < 55.0 && (fabs(M - 55.0) < e || M > 55.0)))
   {
      printf("Jedan student je polozio.\n");
   }
   else
   if (T < 55.0 && B < 55.0 && M < 55.0)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else
   if (((fabs(T - 55.0) < e || T > 55.0) && (fabs(B - 55.0) < e || B > 55.0) && M < 55.0) || ((fabs(T - 55.0) < e || T > 55.0) && (fabs(M - 55.0) < e || M > 55.0) && B < 55.0) || (T < 55.0 && (fabs(B - 55.0) < e || B > 55.0) && (fabs(M - 55.0) < e || M > 55.0)))
   {
      printf("Dva studenta su polozila.\n");
   }
   else
   if ((fabs(T - 55.0) < e || T > 55.0) && (fabs(B - 55.0) < e || B > 55.0) && (fabs(M - 55.0) < e || M > 55.0))
   {
      printf("Sva tri studenta su polozila.\n");

      if ((fabs(T1 - M1) < e && fabs(T1 - B1) < e && fabs(B1 - M1) < e))
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else
      if ((fabs(T1 - M1) < e && fabs(T1 - B1) > e && fabs(M1 - B1) > e) || (fabs(T1 - B1) < e && fabs(T1 - M1) > e && fabs(B1 - M1) > e) || (fabs(B1 - M1) < e && fabs(B1 - T1) > e && fabs(M1 - T1) > e))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else
      if ((fabs(T1 - B1) > e && fabs(B1 - M1) > e && fabs(M1 - T1) > e))
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }

   return(0);
}
