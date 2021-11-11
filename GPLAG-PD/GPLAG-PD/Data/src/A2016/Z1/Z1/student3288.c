#include <stdio.h>

int main()
{
   double p1, p2, P, Z, ZI, UB, p11, p21, P1, Z1, ZI1, UB1, p12, p22, P2, Z2, ZI2, UB2;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &p1);
   if (p1 < 0 || p1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2);
   if (p2 < 0 || p2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &P);
   if (P < 0 || P > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z);
   if (Z < 0 || Z > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI);
   if (ZI < 0 || ZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &p11);
   if (p11 < 0 || p11 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p21);
   if (p21 < 0 || p21 > 20)
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
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &p12);
   if (p12 < 0 || p12 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p22);
   if (p22 < 0 || p22 > 20)
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
   UB  = p1 + p2 + P + Z + ZI;
   UB1 = p11 + p21 + P1 + Z1 + ZI1;
   UB2 = p12 + p22 + P2 + Z2 + ZI2;
   if (UB < 55 && UB1 < 55 && UB2 < 55)
   {
      printf("Nijedan student nije polozio. ");
      return(0);
   }
   else if ((UB >= 55 && UB1 < 55 && UB2 < 55) || (UB < 55 && UB1 >= 55 && UB2 < 55) || (UB < 55 && UB1 < 55 && UB2 >= 55))
   {
      printf("Jedan student je polozio. ");
      return(0);
   }
   else if ((UB >= 55 && UB1 >= 55 && UB2 < 55) || (UB >= 55 && UB1 < 55 && UB2 >= 55) || (UB < 55 && UB1 >= 55 && UB2 >= 55))
   {
      printf("Dva studenta su polozila. ");
      return(0);
   }
   else if (UB >= 55 && UB1 >= 55 && UB2 >= 55)
   {
      printf("Sva tri studenta su polozila. ");
   }
   if (((UB >= 55 && UB <= 65) && (UB1 >= 55) && (UB1 <= 65) && UB2 > 65) || ((UB >= 65 && UB < 75) && (UB1 >= 65) && (UB1 < 75) && (UB2 > 75 || UB2 < 65)) || ((UB >= 75 && UB < 85) && (UB1 >= 75) && (UB1 < 85) && (UB2 >= 85 || UB2 < 75)) || ((UB >= 85 && UB < 92) && (UB1 >= 85) && (UB1 < 92) && (UB2 >= 92 || UB2 < 85)) || ((UB >= 92 && UB <= 100) && (UB1 >= 92) && (UB1 <= 100) && (UB2 < 92)))
   {
      printf("\nDva od tri studenta imaju istu ocjenu. ");
   }
   else if (UB == UB1 && UB1 == UB2)
   {
      printf("\nSva tri studenta imaju istu ocjenu. ");
   }
   else if (UB != UB1 && UB != UB2 && UB1 != UB2)
   {
      printf("\nSvaki student ima razlicitu ocjenu. ");
   }
   return(0);
}
