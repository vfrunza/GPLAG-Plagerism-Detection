#include <stdio.h>
#include <math.h>
#define e    0.00001

int main()
{
   float bodovi1 = 0, bodovi2 = 0, bodovi3 = 0, x1;
   int   br = 0;

   printf("Unesite bodove za Tarika:");
   printf("\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &x1);
   if (x1 > 20 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi1 = bodovi1 + x1;
   printf("II parcijalni ispit: ");
   scanf("%f", &x1);
   if (x1 > 20 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi1 = bodovi1 + x1;
   printf("Prisustvo: ");
   scanf("%f", &x1);
   if (x1 > 10 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi1 = bodovi1 + x1;
   printf("Zadace: ");
   scanf("%f", &x1);
   if (x1 > 10 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi1 = bodovi1 + x1;
   printf("Zavrsni ispit: ");
   scanf("%f", &x1);
   if (x1 > 40 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi1 = bodovi1 + x1;


   printf("Unesite bodove za Bojana:");
   printf("\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &x1);
   if (x1 > 20 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi2 = bodovi2 + x1;
   printf("II parcijalni ispit: ");
   scanf("%f", &x1);
   if (x1 > 20 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi2 = bodovi2 + x1;
   printf("Prisustvo: ");
   scanf("%f", &x1);
   if (x1 > 10 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi2 = bodovi2 + x1;
   printf("Zadace: ");
   scanf("%f", &x1);
   if (x1 > 10 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi2 = bodovi2 + x1;
   printf("Zavrsni ispit: ");
   scanf("%f", &x1);
   if (x1 > 40 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi2 = bodovi2 + x1;



   printf("Unesite bodove za Mirzu:");
   printf("\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &x1);
   if (x1 > 20 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi3 = bodovi3 + x1;
   printf("II parcijalni ispit: ");
   scanf("%f", &x1);
   if (x1 > 20 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi3 = bodovi3 + x1;
   printf("Prisustvo: ");
   scanf("%f", &x1);
   if (x1 > 10 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi3 = bodovi3 + x1;
   printf("Zadace: ");
   scanf("%f", &x1);
   if (x1 > 10 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi3 = bodovi3 + x1;
   printf("Zavrsni ispit: ");
   scanf("%f", &x1);
   if (x1 > 40 + e || x1 < -e)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   bodovi3 = bodovi3 + x1;


   if (bodovi1 >= 55 - e)
   {
      br++;
   }
   if (bodovi2 >= 55 - e)
   {
      br++;
   }
   if (bodovi3 >= 55 - e)
   {
      br++;
   }


   if (br == 0)
   {
      printf("Nijedan student nije polozio.");
   }
   else
   {
      if (br == 1)
      {
         printf("Jedan student je polozio.");
      }
      else if (br == 2)
      {
         printf("Dva studenta su polozila.");
      }
      else if (br == 3)
      {
         printf("Sva tri studenta su polozila.\n");
         if (fabs(bodovi3 - bodovi2) < 10 - e && fabs(bodovi2 - bodovi1) < 10 - e && fabs(bodovi3 - bodovi1) < 10 - e)
         {
            printf("Sva tri studenta imaju istu ocjenu.");
         }
         else if (fabs(bodovi3 - bodovi2) > 10 - e && fabs(bodovi2 - bodovi1) > 10 - e && fabs(bodovi3 - bodovi1) > 10 - e)
         {
            printf("Svaki student ima razlicitu ocjenu.");
         }
         else
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }
      }
   }
   return(0);
}
