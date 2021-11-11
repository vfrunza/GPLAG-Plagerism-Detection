#include <stdio.h>
int main()
{
   double T1, T2, T3, T4, T5, B1, B2, B3, B4, B5, M1, M2, M3, M4, M5, X1, X2, X3;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: "); scanf("%lf", &T1);
   if ((T1 < 0) || (T1 > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &T2);
   if ((T2 < 0) || (T2 > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");  scanf("%lf", &T3);
   if ((T3 < 0) || (T3 > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");     scanf("%lf", &T4);
   if ((T4 < 0) || (T4 > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");      scanf("%lf", &T5);
   if ((T5 < 0 || T5 > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: "); scanf("%lf", &B1);
   if ((B1 < 0) || (B1 > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");        scanf("%lf", &B2);
   if ((B2 < 0) || (B2 > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");  scanf("%lf", &B3);
   if ((B3 < 0) || (B3 > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");     scanf("%lf", &B4);
   if ((B4 < 0) || (B4 > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");      scanf("%lf", &B5);
   if ((B5 < 0) || (B5 > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: "); scanf("%lf", &M1);
   if ((M1 < 0) || (M1 > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");        scanf("%lf", &M2);
   if ((M2 < 0) || (M2 > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");  scanf("%lf", &M3);
   if ((M3 < 0) || (M3 > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");     scanf("%lf", &M4);
   if ((M4 < 0) || (M4 > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");      scanf("%lf", &M5);
   if ((M5 < 0 || M5 > 40))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   X1 = T1 + T2 + T3 + T4 + T5;
   X2 = B1 + B2 + B3 + B4 + B5;
   X3 = M1 + M2 + M3 + M4 + M5;
   if (X1 < 55 && X2 < 55 && X3 < 55)
   {
      printf("Nijedan student nije polozio.");
      return(0);
   }
   if ((X1 - 55 >= 0 && X2 - 55 < 0 && X3 - 55 < 0) || (X1 - 55 < 0 && X2 - 55 >= 0 && X3 - 55 < 0) || (X1 - 55 < 0 && X2 - 55 < 0 && X3 - 55 >= 0))
   {
      printf("Jedan student je polozio.\n");
      return(0);
   }
   if ((X1 - 55 >= 0 && X2 - 55 >= 0 && X3 - 55 < 0) || (X1 - 55 < 0 && X2 - 55 >= 0 && X3 - 55 >= 0) || (X1 - 55 >= 0 && X2 - 55 < 0 && X3 - 55 >= 0))
   {
      printf("Dva studenta su polozila.\n");
      return(0);
   }
   if ((X1 >= 55) && (X2 >= 55) && (X3 >= 55))
   {
      printf("Sva tri studenta su polozila.\n");
      if ((X1 == X2) && (X2 == X3) && (X1 == X3))
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if ((X1 != X2) && (X2 != X3) && (X3 != X1))
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
      else
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
   }
   return(0);
}
