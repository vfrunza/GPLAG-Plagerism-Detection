#include <stdio.h>
#include <math.h>
#define EPSILON    0.01

int main()
{
   float prvi_parcijalni_ispit_t, drugi_parcijalni_ispit_t, prisustvo_t, zadace_t, zavrsni_ispit_t, ukupan_broj_bodova_t,
         prvi_parcijalni_ispit_b, drugi_parcijalni_ispit_b, prisustvo_b, zadace_b, zavrsni_ispit_b, ukupan_broj_bodova_b,
         prvi_parcijalni_ispit_m, drugi_parcijalni_ispit_m, prisustvo_m, zadace_m, zavrsni_ispit_m, ukupan_broj_bodova_m;

   printf("\nUnesite bodove za Tarika:");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &prvi_parcijalni_ispit_t);
   if (prvi_parcijalni_ispit_t < 0 || prvi_parcijalni_ispit_t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &drugi_parcijalni_ispit_t);
   }
   if (drugi_parcijalni_ispit_t < 0 || drugi_parcijalni_ispit_t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
      scanf("%f", &prisustvo_t);
   }
   if (prisustvo_t < 0 || prisustvo_t > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zadace: ");
      scanf("%f", &zadace_t);
   }
   if (zadace_t < 0 || zadace_t > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
      scanf("%f", &zavrsni_ispit_t);
   }
   if (zavrsni_ispit_t < 0 || zavrsni_ispit_t > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Unesite bodove za Bojana:");
      printf("\nI parcijalni ispit: ");
      scanf("%f", &prvi_parcijalni_ispit_b);
   }
   if (prvi_parcijalni_ispit_b < 0 || prvi_parcijalni_ispit_b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &drugi_parcijalni_ispit_b);
   }
   if (drugi_parcijalni_ispit_b < 0 || drugi_parcijalni_ispit_b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
      scanf("%f", &prisustvo_b);
   }
   if (prisustvo_b < 0 || prisustvo_b > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zadace: ");
      scanf("%f", &zadace_b);
   }
   if (zadace_b < 0 || zadace_b > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
      scanf("%f", &zavrsni_ispit_b);
   }
   if (zavrsni_ispit_b < 0 || zavrsni_ispit_b > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Unesite bodove za Mirzu:");
      printf("\nI parcijalni ispit: ");
      scanf("%f", &prvi_parcijalni_ispit_m);
   }
   if (prvi_parcijalni_ispit_m < 0 || prvi_parcijalni_ispit_m > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &drugi_parcijalni_ispit_m);
   }
   if (drugi_parcijalni_ispit_m < 0 || drugi_parcijalni_ispit_m > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
      scanf("%f", &prisustvo_m);
   }
   if (prisustvo_m < 0 || prisustvo_m > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zadace: ");
      scanf("%f", &zadace_m);
   }
   if (zadace_m < 0 || zadace_m > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
      scanf("%f", &zavrsni_ispit_m);
   }
   if (zavrsni_ispit_m < 0 || zavrsni_ispit_m > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      ukupan_broj_bodova_t = prvi_parcijalni_ispit_t + drugi_parcijalni_ispit_t + prisustvo_t + zadace_t + zavrsni_ispit_t;
      ukupan_broj_bodova_b = prvi_parcijalni_ispit_b + drugi_parcijalni_ispit_b + prisustvo_b + zadace_b + zavrsni_ispit_b;
      ukupan_broj_bodova_m = prvi_parcijalni_ispit_m + drugi_parcijalni_ispit_m + prisustvo_m + zadace_m + zavrsni_ispit_m;

      if (ukupan_broj_bodova_t < 55 && ukupan_broj_bodova_b < 55 && ukupan_broj_bodova_m < 55)
      {
         printf("Nijedan student nije polozio.");
      }
      else if (fabs(55 - ukupan_broj_bodova_t) < EPSILON && ukupan_broj_bodova_t > 55 && ukupan_broj_bodova_b < 55 && ukupan_broj_bodova_m < 55 ||
               ukupan_broj_bodova_b >= 55 && ukupan_broj_bodova_t < 55 && ukupan_broj_bodova_m < 55 ||
               ukupan_broj_bodova_m >= 55 && ukupan_broj_bodova_t < 55 && ukupan_broj_bodova_b < 55)
      {
         printf("Jedan student je polozio.");
      }
      else if (ukupan_broj_bodova_t >= 55 && ukupan_broj_bodova_b >= 55 && ukupan_broj_bodova_m < 55 ||
               ukupan_broj_bodova_t >= 55 && ukupan_broj_bodova_m >= 55 && ukupan_broj_bodova_b < 55 ||
               ukupan_broj_bodova_b >= 55 && ukupan_broj_bodova_m >= 55 && ukupan_broj_bodova_t < 55)
      {
         printf("Dva studenta su polozila.");
      }

      else if (ukupan_broj_bodova_t >= 55 && ukupan_broj_bodova_b >= 55 && ukupan_broj_bodova_m >= 55)
      {
         printf("Sva tri studenta su polozila.");
         if (ukupan_broj_bodova_t >= 55 && ukupan_broj_bodova_t < 65 && ukupan_broj_bodova_b >= 55 && ukupan_broj_bodova_b < 65 && ukupan_broj_bodova_m >= 55 && ukupan_broj_bodova_m < 65 ||
             ukupan_broj_bodova_t >= 65 && ukupan_broj_bodova_t < 75 && ukupan_broj_bodova_b >= 65 && ukupan_broj_bodova_b < 75 && ukupan_broj_bodova_m >= 65 && ukupan_broj_bodova_m < 75 ||
             ukupan_broj_bodova_t >= 75 && ukupan_broj_bodova_t < 85 && ukupan_broj_bodova_b >= 75 && ukupan_broj_bodova_b < 85 && ukupan_broj_bodova_m >= 75 && ukupan_broj_bodova_m < 85 ||
             ukupan_broj_bodova_t >= 85 && ukupan_broj_bodova_t < 92 && ukupan_broj_bodova_b >= 85 && ukupan_broj_bodova_b < 92 && ukupan_broj_bodova_m >= 85 && ukupan_broj_bodova_m < 92 ||
             ukupan_broj_bodova_t >= 92 && ukupan_broj_bodova_t <= 100 && ukupan_broj_bodova_b >= 92 && ukupan_broj_bodova_b <= 100 && ukupan_broj_bodova_m >= 92 && ukupan_broj_bodova_m <= 100)
         {
            printf("\nSva tri studenta imaju istu ocjenu.");
         }
         else if (ukupan_broj_bodova_t >= 55 && ukupan_broj_bodova_t < 65 && ukupan_broj_bodova_b >= 55 && ukupan_broj_bodova_b < 65 && ukupan_broj_bodova_m >= 65 ||
                  ukupan_broj_bodova_t >= 55 && ukupan_broj_bodova_t < 65 && ukupan_broj_bodova_m >= 55 && ukupan_broj_bodova_m < 65 && ukupan_broj_bodova_b >= 65 ||
                  ukupan_broj_bodova_b >= 55 && ukupan_broj_bodova_b < 65 && ukupan_broj_bodova_m >= 55 && ukupan_broj_bodova_m < 65 && ukupan_broj_bodova_t >= 65 ||

                  ukupan_broj_bodova_t >= 65 && ukupan_broj_bodova_t < 75 && ukupan_broj_bodova_b >= 65 && ukupan_broj_bodova_b < 75 && (ukupan_broj_bodova_m < 65 || ukupan_broj_bodova_m >= 75) ||
                  ukupan_broj_bodova_t >= 65 && ukupan_broj_bodova_t < 75 && ukupan_broj_bodova_m >= 65 && ukupan_broj_bodova_m < 75 && (ukupan_broj_bodova_b < 65 || ukupan_broj_bodova_b >= 75) ||
                  ukupan_broj_bodova_b >= 65 && ukupan_broj_bodova_b < 75 && ukupan_broj_bodova_m >= 65 && ukupan_broj_bodova_m < 75 && (ukupan_broj_bodova_t < 65 || ukupan_broj_bodova_t >= 75) ||


                  ukupan_broj_bodova_t >= 75 && ukupan_broj_bodova_t < 85 && ukupan_broj_bodova_b >= 75 && ukupan_broj_bodova_b < 85 && (ukupan_broj_bodova_m < 75 || ukupan_broj_bodova_m >= 85) ||
                  ukupan_broj_bodova_t >= 75 && ukupan_broj_bodova_t < 85 && ukupan_broj_bodova_m >= 75 && ukupan_broj_bodova_m < 85 && (ukupan_broj_bodova_b < 75 || ukupan_broj_bodova_b >= 85) ||
                  ukupan_broj_bodova_b >= 75 && ukupan_broj_bodova_b < 85 && ukupan_broj_bodova_m >= 75 && ukupan_broj_bodova_m < 85 && (ukupan_broj_bodova_t < 75 || ukupan_broj_bodova_t >= 85) ||


                  ukupan_broj_bodova_t >= 85 && ukupan_broj_bodova_t < 92 && ukupan_broj_bodova_b >= 85 && ukupan_broj_bodova_b < 92 && (ukupan_broj_bodova_m < 85 || ukupan_broj_bodova_m >= 92) ||
                  ukupan_broj_bodova_t >= 85 && ukupan_broj_bodova_t < 92 && ukupan_broj_bodova_m >= 85 && ukupan_broj_bodova_m < 92 && (ukupan_broj_bodova_b < 85 || ukupan_broj_bodova_b >= 92) ||
                  ukupan_broj_bodova_b >= 85 && ukupan_broj_bodova_b < 92 && ukupan_broj_bodova_m >= 85 && ukupan_broj_bodova_m < 92 && (ukupan_broj_bodova_t < 85 || ukupan_broj_bodova_t >= 92) ||


                  ukupan_broj_bodova_t >= 92 && ukupan_broj_bodova_t <= 100 && ukupan_broj_bodova_b >= 92 && ukupan_broj_bodova_b <= 100 && ukupan_broj_bodova_m < 92 ||
                  ukupan_broj_bodova_t >= 92 && ukupan_broj_bodova_t <= 100 && ukupan_broj_bodova_m >= 92 && ukupan_broj_bodova_m <= 100 && ukupan_broj_bodova_b < 92 ||
                  ukupan_broj_bodova_b >= 92 && ukupan_broj_bodova_b <= 100 && ukupan_broj_bodova_m >= 92 && ukupan_broj_bodova_m <= 100 && ukupan_broj_bodova_t < 92)
         {
            printf("\nDva od tri studenta imaju istu ocjenu.");
         }
         else
         {
            printf("\nSvaki student ima razlicitu ocjenu.");
         }
      }
   }
   return(0);
}
