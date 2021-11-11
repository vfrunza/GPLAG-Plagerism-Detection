#include <stdio.h>
#include <stdlib.h>
int main()
{
   double P1, P2, P3, Z1, Z2, Z3, PP1, PP2, PP3, DP1, DP2, DP3, ZI1, ZI2, ZI3, BB1, BB2, BB3;
   int    O6 = 0, O7 = 0, O8 = 0, O9 = 0, O10 = 0;

   //tare
   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
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
   //Bojka
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
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
   if (Z2 < 0 || Z2 > 20)
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
   //mirzibad
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
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
      printf("Neispravan broj bodova");
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
   //broj bodova
   BB1 = (P1 + Z1 + PP1 + DP1 + ZI1);
   BB2 = (P2 + Z2 + PP2 + DP2 + ZI2);
   BB3 = (P3 + Z3 + PP3 + DP3 + ZI3);

   if (BB1 < 55 && BB2 < 55 && BB3 < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (BB1 < 55 && BB2 < 55 && BB3 >= 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (BB1 < 55 && BB2 >= 55 && BB3 < 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (BB1 >= 55 && BB2 < 55 && BB3 < 55)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (BB1 < 55 && BB2 >= 55 && BB3 >= 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (BB1 >= 55 && BB2 >= 55 && BB3 < 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (BB1 >= 55 && BB2 < 55 && BB3 >= 55)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (BB1 >= 55 && BB2 >= 55 && BB3 >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
   }
// ocjene iste
   if (BB1 >= 55 && BB1 < 65)
   {
      O6++;
   }
   else if (BB1 >= 65 && BB1 < 75)
   {
      O7++;
   }
   else if (BB1 >= 75 && BB1 < 85)
   {
      O8++;
   }
   else if (BB1 >= 85 && BB1 < 92)
   {
      O9++;
   }
   else if (BB1 >= 92 && BB1 <= 100)
   {
      O10++;
   }
   if (BB2 >= 55 && BB2 < 65)
   {
      O6++;
   }
   else if (BB2 >= 65 && BB2 < 75)
   {
      O7++;
   }
   else if (BB2 >= 75 && BB2 < 85)
   {
      O8++;
   }
   else if (BB2 >= 85 && BB2 < 92)
   {
      O9++;
   }
   else if (BB2 >= 92 && BB2 <= 100)
   {
      O10++;
   }
   if (BB3 >= 55 && BB3 < 65)
   {
      O6++;
   }
   else if (BB3 >= 65 && BB3 < 75)
   {
      O7++;
   }
   else if (BB3 >= 75 && BB3 < 85)
   {
      O8++;
   }
   else if (BB3 >= 85 && BB3 < 92)
   {
      O9++;
   }
   else if (BB3 >= 92 && BB3 <= 100)
   {
      O10++;
   }
   if (BB1 < 55 || BB2 < 55 || BB3 < 55)
   {
      return(0);
   }
   if (O6 == 2 || O7 == 2 || O8 == 2 || O9 == 2 || O10 == 2)
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n"); return(0);
   }
   if (O6 == 3 || O7 == 3 || O8 == 3 || O9 == 3 || O10 == 3)
   {
      printf("Sva tri studenta imaju istu ocjenu.\n"); return(0);
   }
   else
   {
      printf("Svaki student ima razlicitu ocjenu.\n");
   }
   return(0);
}
