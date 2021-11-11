#include <stdio.h>

int main()
{
   int   To, Bo, Mo;
   float T, B, M;
   float I1, II1, P1, Z1, ZI1;
   float I2, II2, P2, Z2, ZI2;
   float I3, II3, P3, Z3, ZI3;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &I1);
   if (I1 < 0 || I1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%f", &II1);
   if (II1 < 0 || II1 > 20)
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
   else
   {
      printf("Unesite bodove za Bojana: \n");
   }
   printf("I parcijalni ispit: ");
   scanf("%f", &I2);
   if (I2 < 0 || I2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%f", &II2);
   if (II2 < 0 || II2 > 20)
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
   else
   {
      printf("Unesite bodove za Mirzu: \n");
   }
   printf("I parcijalni ispit: ");
   scanf("%f", &I3);
   if (I3 < 0 || I3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%f", &II3);
   if (II3 < 0 || II3 > 20)
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
   else
   {
      T = I1 + II2 + P1 + Z1 + ZI1;
   }
   B = I2 + II2 + P2 + Z2 + ZI2;
   M = I3 + II3 + P3 + Z3 + ZI3;

   if (T < 55)
   {
      To = 5;
   }
   else if (T >= 55 && T < 65)
   {
      To = 6;
   }
   else if (T >= 65 && T < 75)
   {
      To = 7;
   }
   else if (T >= 75 && T < 85)
   {
      To = 8;
   }
   else if (T >= 85 && T < 92)
   {
      To = 9;
   }
   else
   {
      To = 10;
   }

   if (B < 55)
   {
      Bo = 5;
   }
   else if (B >= 55 && B < 65)
   {
      Bo = 6;
   }
   else if (B >= 65 && B < 75)
   {
      Bo = 7;
   }
   else if (B >= 75 && B < 85)
   {
      Bo = 8;
   }
   else if (B >= 85 && B < 92)
   {
      Bo = 9;
   }
   else
   {
      Bo = 10;
   }

   if (M < 55)
   {
      Mo = 5;
   }
   else if (M >= 55 && M < 65)
   {
      Mo = 6;
   }
   else if (M >= 65 && M < 75)
   {
      Mo = 7;
   }
   else if (M >= 75 && M < 85)
   {
      Mo = 8;
   }
   else if (M >= 85 && M < 92)
   {
      Mo = 9;
   }
   else
   {
      Mo = 10;
   }

   if (T < 55 && B < 55 && M < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else
   if (T >= 55 && B < 55 && M < 55)
   {
      printf("Jedan student je polozio.");
   }
   else
   if (T < 55 && B >= 55 && M < 55)
   {
      printf("Jedan student je polozio.");
   }
   else
   if (T < 55 && B < 55 && M >= 55)
   {
      printf("Jedan student je polozio.");
   }
   else
   if (T >= 55 && B >= 55 && M < 55)
   {
      printf("Dva studenta su polozila.");
   }
   else
   if (T < 55 && B >= 55 && M >= 55)
   {
      printf("Dva studenta su polozila.");
   }
   else
   if (T > 55 && B < 55 && M >= 55)
   {
      printf("Dva studenta su polozila.");
   }
   else
   if (T >= 55 && B >= 55 && M >= 55)
   {
      printf("Sva tri studenta su polozila.");
   }
   return(0);
}
