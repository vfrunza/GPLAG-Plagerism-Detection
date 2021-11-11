#include <stdio.h>
#include <math.h>

int main()
{
   float prviparc, drugiparc, pr, z, zavr, prviparc2, drugiparc2, pr2, z2, zavr2, prviparc3, drugiparc3, pr3, z3, zavr3;

   printf("Unesite bodove za Tarika:\n");

   printf("I parcijalni ispit:");
   scanf("%float", &prviparc);
   if (prviparc > 20 || prviparc < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%f", &drugiparc);
   if (drugiparc > 20 || drugiparc < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%f", &pr);
   if (pr > 10 || pr < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%f", &z);
   if (z > 10 || z < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%f", &zavr);
   if (zavr > 40 || zavr < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }

   printf(" Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit:");
   scanf("%f", &prviparc2);
   if (prviparc2 > 20 || prviparc2 < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%f", &drugiparc2);
   if (drugiparc2 > 20 || drugiparc2 < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%f", &pr2);
   if (pr2 > 10 || pr2 < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%f", &z2);
   if (z2 > 10 || z2 < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%f", &zavr2);
   if (zavr2 > 40 || zavr2 < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }

   printf(" Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit:");
   scanf("%f", &prviparc3);
   if (prviparc3 > 20 || prviparc3 < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%f", &drugiparc3);
   if (drugiparc3 > 20 || drugiparc3 < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%f", &pr3);
   if (pr3 > 10 || pr3 < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%f", &z3);
   if (z3 > 10 || z3 < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%f", &zavr3);
   if (zavr3 > 40 || zavr3 < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }


   float a = prviparc + drugiparc + pr + z + zavr;
   float b = prviparc2 + drugiparc2 + pr2 + z2 + zavr2;
   float c = prviparc3 + drugiparc3 + pr3 + z3 + zavr3;

   if (a < 55 && b < 55 && c < 55)
   {
      printf(" Nijedan student nije polozio.");
   }

   else if (a >= 55 && b < 55 && c < 55)
   {
      printf(" Jedan student je polozio.\n");
   }
   else if (a < 55 && b >= 55 && c < 55)
   {
      printf(" Jedan student je polozio.\n");
   }
   else if (a < 55 && b < 55 && c >= 55)
   {
      printf(" Jedan student je polozio.\n");
   }
   else if (a < 55 && b >= 55 && c >= 55)
   {
      printf(" Dva studenta su polozila.\n");
   }
   else if (a >= 55 && b >= 55 && c < 55)
   {
      printf(" Dva studenta su polozila.\n");
   }
   else if (a >= 55 && b <= 55 && c >= 55)
   {
      printf(" Dva studenta su polozila.\n");
   }
   else if (a >= 55 && b >= 55 && c >= 55)
   {
      printf(" Sva tri studenta su polozila.\n");
   }
   if (a >= 55 && b >= 55 && c >= 55)
   {
      if (a > 55 && a < 65 && b > 55 && b < 65 && c > 55 && c < 65)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (a > 65 && a < 75 && b > 65 && b < 75 && c > 65 && c < 75)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (a > 75 && a < 85 && b > 75 && b < 85 && c > 75 && c < 85)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (a > 85 && a < 92 && b > 85 && b < 92 && c > 85 && c < 92)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (a > 92 && a < 100 && b > 92 && b < 100 && c > 92 && c < 100)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }


      else if (a > 55 && a < 65 && b > 55 && b < 65 && c != a)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (a > 55 && a < 65 && c > 55 && c < 65 && b != a)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (c > 55 && c < 65 && b > 55 && b < 65 && a != c)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }

      else if (a > 65 && a < 75 && b > 65 && b < 75 && c != a)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (a > 65 && a < 75 && c > 65 && c < 75 && b != a)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (c > 65 && c < 75 && b > 65 && b < 75 && a != c)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }

      else if (a > 75 && a < 85 && b > 75 && b < 85 && c != a)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (a > 75 && a < 85 && c > 75 && c < 85 && b != a)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (c > 75 && c < 85 && b > 75 && b < 85 && a != c)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }

      else if (a > 85 && a < 92 && b > 85 && b < 92 && c != a)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (a > 85 && a < 92 && c > 85 && c < 92 && b != a)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (c > 85 && c < 92 && b > 85 && b < 92 && a != c)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }

      else if (a > 92 && a < 100 && b > 92 && b < 100 && c != a)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (a > 92 && a < 100 && c > 92 && c < 100 && b != a)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (c > 92 && c < 100 && b > 92 && b < 100 && a != c)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }


      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
