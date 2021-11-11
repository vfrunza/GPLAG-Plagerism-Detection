#include <stdio.h>
#include <stdlib.h>

int main()
{
   float a, b, c, d, e;
   float ocjena1 = 0, ocjena2 = 0, ocjena3 = 0;
   int   O1, O2, O3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &a);
   if (a < 0 || a > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &b);
   if (b < 0 || b > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &c);
   if (c < 0 || c > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &d);
   if (d < 0 || d > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &e);
   if (e < 0 || e > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   ocjena1 = (a + b + c + d + e);

   if ((ocjena1 - 55 >= 0) && abs(ocjena1 - 55) < 11 && abs(ocjena1 - 55) > 0)
   {
      O1 = 6;
   }
   else if (abs(ocjena1 - 65) < 11 && abs(ocjena2 - 65) > 0)
   {
      O1 = 7;
   }
   else if (abs(ocjena1 - 75) < 11 && abs(ocjena1 - 75) > 0)
   {
      O1 = 8;
   }
   else if (abs(ocjena1 - 85) < 8 && abs(ocjena1 - 85) > 0)
   {
      O1 = 9;
   }
   else if (abs(ocjena1 - 92) > 0 && abs(ocjena1 - 92) < 8)
   {
      O1 = 10;
   }
   else
   {
      O1 = 5;
   }


   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &a);
   if (a < 0 || a > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &b);
   if (b < 0 || b > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &c);
   if (c < 0 || c > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &d);
   if (d < 0 || d > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &e);
   if (e < 0 || e > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   ocjena2 = (a + b + c + d + e);

   if ((ocjena2 - 55 >= 0) && abs(ocjena2 - 55) < 11 && abs(ocjena2 - 55) > 0)
   {
      O2 = 6;
   }
   else if (abs(ocjena2 - 65) < 11 && abs(ocjena2 - 65) > 0)
   {
      O2 = 7;
   }
   else if (abs(ocjena2 - 75) < 11 && abs(ocjena2 - 75) > 0)
   {
      O2 = 8;
   }
   else if (abs(ocjena2 - 85) < 8 && abs(ocjena2 - 85) > 0)
   {
      O2 = 9;
   }
   else if (abs(ocjena2 - 92) > 0 && abs(ocjena2 - 92) < 8)
   {
      O2 = 10;
   }
   else
   {
      O2 = 5;
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &a);
   if (a < 0 || a > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &b);
   if (b < 0 || b > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &c);
   if (c < 0 || c > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &d);
   if (d < 0 || d > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &e);
   if (e < 0 || e > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   ocjena3 = (a + b + c + d + e);

   if ((ocjena3 - 55 >= 0) && abs(ocjena3 - 55) < 11 && abs(ocjena3 - 55) > 0)
   {
      O3 = 6;
   }
   else if (abs(ocjena3 - 65) < 11 && abs(ocjena3 - 65) > 0)
   {
      O3 = 7;
   }
   else if (abs(ocjena3 - 75) < 11 && abs(ocjena3 - 75) > 0)
   {
      O3 = 8;
   }
   else if (abs(ocjena3 - 85) < 8 && abs(ocjena3 - 85) > 0)
   {
      O3 = 9;
   }
   else if (abs(ocjena3 - 92) > 0 && abs(ocjena3 - 92) < 8)
   {
      O3 = 10;
   }
   else
   {
      O3 = 5;
   }


   if (O1 > 5 && O2 > 5 && O3 > 5)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else if (O1 < 6 && O2 < 6 && O3 < 6)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (O1 > 5 && O2 > 5 && O3 < 6)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (O1 > 5 && O2 < 6 && O3 > 5)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (O1 < 6 && O2 > 5 && O3 > 5)
   {
      printf("Dva studenta su polozila.\n");
   }
   else
   {
      printf("Jedan student je polozio.");
   }

   if (O2 > 5 && O3 > 5 && O1 > 5)
   {
      if (O1 == O2 && O1 == O3 && O2 == O3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (O1 != O2 && O1 != O3 && O2 != O3)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      else
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }



   return(0);
}
