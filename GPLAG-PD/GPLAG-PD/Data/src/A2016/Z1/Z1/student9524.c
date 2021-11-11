#include <stdio.h>
#include <math.h>

int main()
{
   double IP, IIP, P, Z, ZI, IP1, IIP1, P1, Z1, ZI1, IIP2, Z2, ZI2, A, B, C, IP2, P2;


   printf("Unesite bodove za Tarika: \n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &IP);
   if (IP < 0 || IP > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: \n");
   scanf("%lf", &IIP);
   if (IIP < 0 || IIP > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: \n");
   scanf("%lf", &P);
   if (P < 0 || P > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadaca: \n");
   scanf("%lf", &Z);
   if (Z < 0 || Z > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: \n");
   scanf("%lf", &ZI);
   if (ZI < 0 || ZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: \n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &IP1);
   if (IP1 < 0 || IP1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIP1);
   if (IIP1 < 0 || IIP1 > 20)
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
   printf("Zadaca: ");
   scanf("lf", &Z1);
   if (Z1 < 0 || Z1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: \n");
   scanf("lf", &ZI1);
   if (ZI1 < 0 || ZI1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: \n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &IP2);
   if (IP2 < 0 || IP2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIP2);
   if (IIP2 < 0 || IIP2 > 20)
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
   printf("Zadaca: ");
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


   A == IP + IIP + P + Z;
   B == IP1 + IIP1 + P1 + Z1;
   C == IP2 + IIP2 + P2 + Z2;



   if (A < 55 && B < 55 && C < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (A < 55 && B < 55 && C >= 55 || A < 55 && B >= 55 && C < 55 || A >= 55 && B < 55 && C < 55)
   {
      printf("Jedan student je polozio .\n");
   }
   else if (A >= 55 && B >= 55 && C < 55 || A < 55 && B >= 55 && C >= 55 || A >= 55 && B < 55 && C >= 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (A >= 55 && B >= 55 && C >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
   }



   if (A >= 55 && A < 65)
   {
      A = 6;
   }
   else if (A >= 65 && A < 75)
   {
      A = 7;
   }
   else if (A >= 75 && A < 85)
   {
      A = 8;
   }
   else if (A >= 85 && A < 92)
   {
      A = 9;
   }
   else if (A >= 92 && A <= 100)
   {
      A = 10;
   }

   if (B >= 55 && B < 65)
   {
      B = 6;
   }
   else if (B >= 65 && B < 75)
   {
      B = 7;
   }
   else if (B >= 75 && B < 85)
   {
      B = 8;
   }
   else if (B >= 85 && B < 92)
   {
      B = 9;
   }
   else if (B >= 92 && A <= 100)
   {
      B = 10;
   }

   if (C >= 55 && C < 65)
   {
      C = 6;
   }
   else if (C >= 65 && C < 75)
   {
      C = 7;
   }
   else if (C >= 75 && C < 85)
   {
      C = 8;
   }
   else if (C >= 85 && C < 92)
   {
      C = 9;
   }
   else if (C >= 92 && C <= 100)
   {
      C = 10;
   }

   if (A == B && B == C)
   {
      printf("Sva tri studenta imaju istu ocjenu.");
   }
   else if (A == B || A == C || B == C)
   {
      printf("Dva od tri studenta imaju istu ocjenu.");
   }
   else
   {
      printf("Svaki student ima razlicitu ocjenu.");
   }
   return(0);
}
