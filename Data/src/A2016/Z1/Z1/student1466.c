#include <stdio.h>
#include <math.h>
#define EPSILON    0.001
int main()
{
   int bojan_ocjena, tarik_ocjena, mirza_ocjena;

   float prvi_parcijalni_m, prvi_parcijalni_t, prvi_parcijalni_b, drugi_parcijalni_m, drugi_parcijalni_t, drugi_parcijalni_b, prisustvo_m, prisustvo_t, prisustvo_b, zadace_m, zadace_t, zadace_b, zavrsni_b, zavrsni_m, zavrsni_t, bodovi_m, bodovi_b, bodovi_t, a, b, c;


   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &prvi_parcijalni_t);
   if (prvi_parcijalni_t < 0 || prvi_parcijalni_t > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &drugi_parcijalni_t);
   }
   if (drugi_parcijalni_t < 0 || drugi_parcijalni_t > 20)
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
      scanf("%f", &zavrsni_t);
   }
   if (zavrsni_t < 0 || zavrsni_t > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      bodovi_t = prvi_parcijalni_t + drugi_parcijalni_t + prisustvo_t + zadace_t + zavrsni_t;
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &prvi_parcijalni_b);
   if (prvi_parcijalni_b < 0 || prvi_parcijalni_b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &drugi_parcijalni_b);
   }
   if (drugi_parcijalni_b < 0 || drugi_parcijalni_b > 20)
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
      scanf("%f", &zavrsni_b);
   }
   if (zavrsni_b < 0 || zavrsni_b > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      bodovi_b = prvi_parcijalni_b + drugi_parcijalni_b + prisustvo_b + zadace_b + zavrsni_b;
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &prvi_parcijalni_m);
   if (prvi_parcijalni_m < 0 || prvi_parcijalni_m > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &drugi_parcijalni_m);
   }
   if (drugi_parcijalni_m < 0 || drugi_parcijalni_m > 20)
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
      scanf("%f", &zavrsni_m);
      if (zavrsni_m < 0 || zavrsni_m > 40)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         bodovi_m = prvi_parcijalni_m + drugi_parcijalni_m + prisustvo_m + zadace_m + zavrsni_m;


         if (bodovi_t < 55)
         {
            tarik_ocjena = 1;
         }
         else if (bodovi_t >= 55 && bodovi_t < 65)
         {
            tarik_ocjena = 6;
         }
         else if (bodovi_t >= 65 && bodovi_t < 75)
         {
            tarik_ocjena = 7;
         }
         else if (bodovi_t >= 75 && bodovi_t < 85)
         {
            tarik_ocjena = 8;
         }
         else if (bodovi_t >= 85 && bodovi_t < 92)
         {
            tarik_ocjena = 9;
         }
         else
         {
            tarik_ocjena = 10;
         }


         if (bodovi_m < 55)
         {
            mirza_ocjena = 1;
         }
         else if (bodovi_m >= 55 && bodovi_m < 65)
         {
            mirza_ocjena = 6;
         }
         else if (bodovi_m >= 65 && bodovi_m < 75)
         {
            mirza_ocjena = 7;
         }
         else if (bodovi_m >= 75 && bodovi_m < 85)
         {
            mirza_ocjena = 8;
         }
         else if (bodovi_m >= 85 && bodovi_m < 92)
         {
            mirza_ocjena = 9;
         }
         else
         {
            mirza_ocjena = 10;
         }

         if (bodovi_b < 55)
         {
            bojan_ocjena = 1;
         }

         else if (bodovi_b >= 55 && bodovi_b < 65)
         {
            bojan_ocjena = 6;
         }
         else if (bodovi_b >= 65 && bodovi_b < 75)
         {
            bojan_ocjena = 7;
         }
         else if (bodovi_b >= 75 && bodovi_b < 85)
         {
            bojan_ocjena = 8;
         }
         else if (bodovi_b >= 85 && bodovi_b < 92)
         {
            bojan_ocjena = 9;
         }
         else
         {
            bojan_ocjena = 10;
         }
         a = mirza_ocjena * tarik_ocjena * bojan_ocjena;

         if ((bodovi_b < 55) && (bodovi_m < 55) && (bodovi_t < 55))
         {
            printf("Nijedan student nije polozio.");
         }
         if (((bodovi_t < 55) && (bodovi_m < 55) && (bodovi_b > 55)) || ((bodovi_m < 55) && (bodovi_t > 55) && (bodovi_b < 55)) || ((bodovi_m > 55) && (bodovi_t < 55) && (bodovi_b < 55)))
         {
            printf("Jedan student je polozio.");
         }
         if ((bodovi_b >= 55 && (bodovi_t >= 55) && (bodovi_m < 55)) || ((bodovi_b >= 55) && (bodovi_m >= 55) && (bodovi_t < 55)) || ((bodovi_t >= 55) && (bodovi_m >= 55) && (bodovi_b < 55)))
         {
            printf("Dva studenta su polozila.");
         }
         if ((bodovi_b >= 55) && (bodovi_m >= 55) && (bodovi_t >= 55))
         {
            printf("Sva tri studenta su polozila.");
         }

         if ((mirza_ocjena == tarik_ocjena) && (bojan_ocjena == tarik_ocjena) && (mirza_ocjena == bojan_ocjena) && (mirza_ocjena != 1) && (tarik_ocjena != 1) && (bojan_ocjena != 1))
         {
            printf("\nSva tri studenta imaju istu ocjenu.");
         }
         if ((mirza_ocjena != tarik_ocjena) && (mirza_ocjena != bojan_ocjena) && (tarik_ocjena != bojan_ocjena) && (mirza_ocjena != 1) && (tarik_ocjena != 1) && (bojan_ocjena != 1))
         {
            printf("\nSvaki student ima razlicitu ocjenu.");
         }
         if ((mirza_ocjena == tarik_ocjena && mirza_ocjena != bojan_ocjena) || (mirza_ocjena == bojan_ocjena && mirza_ocjena != tarik_ocjena) || (tarik_ocjena == bojan_ocjena && tarik_ocjena != mirza_ocjena) && (mirza_ocjena != 1) && (tarik_ocjena != 1) && (bojan_ocjena != 1))
         {
            printf("\nDva od tri studenta imaju istu ocjenu.");
         }
      }
      return(0);
   }
}
