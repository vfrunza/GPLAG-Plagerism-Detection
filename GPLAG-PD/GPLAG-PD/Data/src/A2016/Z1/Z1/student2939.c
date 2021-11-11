#include <stdio.h>
int main()
{
   double T1, T2, T3, T4, T5, B1, B2, B3, B4, B5, M1, M2, M3, M4, M5, BB1, BB2, BB3;
   int    O1 = 0, O2 = 0, O3 = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &T1);
   if (T1 < 0 || T1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &T2);
   if (T2 < 0 || T2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &T3);
   if (T3 < 0 || T3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &T4);
   if (T4 < 0 || T4 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &T5);
   if (T5 < 0 || T5 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &B1);
   if (B1 < 0 || B1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &B2);
   if (B2 < 0 || B2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &B3);
   if (B3 < 0 || B3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &B4);
   if (B4 < 0 || B4 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &B5);
   if (B5 < 0 || B5 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &M1);
   if (M1 < 0 || M1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &M2);
   if (M2 < 0 || M2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &M3);
   if (M3 < 0 || M3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &M4);
   if (M4 < 0 || M4 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &M5);
   if (M5 < 0 || M5 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   BB1 = T1 + T2 + T3 + T4 + T5;
   BB2 = B1 + B2 + B3 + B4 + B5;
   BB3 = M1 + M2 + M3 + M4 + M5;

   { if (BB1 >= 55 && BB1 < 65)
     {
        O1 = 6;
     }
     if (BB1 >= 65 && BB1 < 75)
     {
        O1 = 7;
     }
     if (BB1 >= 75 && BB1 < 85)
     {
        O1 = 8;
     }
     if (BB1 >= 85 && BB1 < 92)
     {
        O1 = 9;
     }
     if (BB1 >= 92 && BB1 < 100)
     {
        O1 = 10;
     }
   }

   { if (BB2 >= 55 && BB2 < 65)
     {
        O2 = 6;
     }
     if (BB2 >= 65 && BB2 < 75)
     {
        O1 = 7;
     }
     if (BB2 >= 75 && BB2 < 85)
     {
        O2 = 8;
     }
     if (BB2 >= 85 && BB2 < 92)
     {
        O2 = 9;
     }
     if (BB2 >= 92 && BB2 < 100)
     {
        O2 = 10;
     }
   }

   { if (BB3 >= 55 && BB3 < 65)
     {
        O3 = 6;
     }
     if (BB3 >= 65 && BB3 < 75)
     {
        O3 = 7;
     }
     if (BB3 >= 75 && BB3 < 85)
     {
        O3 = 8;
     }
     if (BB3 >= 85 && BB3 < 92)
     {
        O3 = 9;
     }
     if (BB3 >= 92 && BB3 < 100)
     {
        O3 = 10;
     }
   }

   if ((BB1 >= 55 && BB2 < 55 && BB3 < 55) || (BB1 < 55 && BB2 >= 55 && BB3 < 55) || (BB1 < 55 && BB2 < 55 && BB3 >= 55))
   {
      printf("Jedan student je polozio.\n");
   }
   else if (BB1 < 55 && BB2 < 55 && BB3 < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else
   if ((BB1 < 55 && BB2 >= 55 && BB3 >= 55) || (BB1 >= 55 && BB2 < 55 && BB3 >= 55) || (BB1 >= 55 && BB2 >= 55 && BB3 < 55))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (BB1 >= 55 && BB2 >= 55 && BB3 >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
      if (O1 == O2 && O1 == O3 && O2 == O3)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (O1 != O2 && O2 != O3 && O1 != O3)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
      else if ((O1 == O2 && O1 != O3) || (O1 == O3 && O1 != O2) || (O2 == O3 && O1 != O2))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
   }
   return(0);
}
