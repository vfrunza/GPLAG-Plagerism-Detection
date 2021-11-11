#include <stdio.h>
#define EPSILON    0.001
#include <math.h>

int main()
{
   float prvi_parc1, prvi_parc2, prvi_parc3, drugi_parc1, drugi_parc2, drugi_parc3, prisustvo1, prisustvo2, prisustvo3, zadace1, zadace2, zadace3, zavrsni1, zavrsni2, zavrsni3;
   int   pao = 0, polozio = 0, ocjena_6 = 0, ocjena_7 = 0, ocjena_8 = 0, ocjena_9 = 0, ocjena_10 = 0;
   float ukupno1, ukupno2, ukupno3;


   printf("Unesite bodove za Tarika: ");

   printf("\nI parcijalni ispit: ");
   scanf("%f", &prvi_parc1);
   if (prvi_parc1 < 0 || prvi_parc1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &drugi_parc1);
   if (drugi_parc1 < 0 || drugi_parc1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &prisustvo1);
   if (prisustvo1 < 0 || prisustvo1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zadace: ");
   scanf("%f", &zadace1);
   if (zadace1 < 0 || zadace1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni1);
   if (zavrsni1 < 0 || zavrsni1 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }



   printf("Unesite bodove za Bojana: ");

   printf("\nI parcijalni ispit: ");
   scanf("%f", &prvi_parc2);
   if (prvi_parc2 < 0 || prvi_parc2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &drugi_parc2);
   if (drugi_parc2 < 0 || drugi_parc2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &prisustvo2);
   if (prisustvo2 < 0 || prisustvo2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zadace: ");
   scanf("%f", &zadace2);
   if (zadace2 < 0 || zadace2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni2);
   if (zavrsni2 < 0 || zavrsni2 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }



   printf("Unesite bodove za Mirzu: ");

   printf("\nI parcijalni ispit: ");
   scanf("%f", &prvi_parc3);
   if (prvi_parc3 < 0 || prvi_parc3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &drugi_parc3);
   if (drugi_parc3 < 0 || drugi_parc3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &prisustvo3);
   if (prisustvo3 < 0 || prisustvo3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zadace: ");
   scanf("%f", &zadace3);
   if (zadace3 < 0 || zadace3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni3);
   if (zavrsni3 < 0 || zavrsni3 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }


   ukupno1 = prvi_parc1 + drugi_parc1 + prisustvo1 + zadace1 + zavrsni1;
   ukupno2 = prvi_parc2 + drugi_parc2 + prisustvo2 + zadace2 + zavrsni2;
   ukupno3 = prvi_parc3 + drugi_parc3 + prisustvo3 + zadace3 + zavrsni3;


   if (ukupno1 > 0 && ukupno1 < 55)
   {
      pao++;
   }
   if (ukupno2 > 0 && ukupno2 < 55)
   {
      pao++;
   }
   if (ukupno3 > 0 && ukupno3 < 55)
   {
      pao++;
   }


   if ((ukupno1 >= 55 - EPSILON) && ukupno1 < 65)
   {
      polozio++; ocjena_6++;
   }
   if (ukupno2 > 55 && ukupno2 < 65)
   {
      polozio++; ocjena_6++;
   }
   if (ukupno3 > 55 && ukupno3 < 65)
   {
      polozio++; ocjena_6++;
   }

   if (ukupno1 > 65 && ukupno1 < 75)
   {
      polozio++; ocjena_7++;
   }
   if (ukupno2 > 65 && ukupno2 < 75)
   {
      polozio++; ocjena_7++;
   }
   if (ukupno3 > 65 && ukupno3 < 75)
   {
      polozio++; ocjena_7++;
   }

   if (ukupno1 > 75 && ukupno1 < 85)
   {
      polozio++; ocjena_8++;
   }
   if (ukupno2 > 75 && ukupno2 < 85)
   {
      polozio++; ocjena_8++;
   }
   if (ukupno3 > 75 && ukupno3 < 85)
   {
      polozio++; ocjena_8++;
   }


   if (ukupno1 > 85 && ukupno1 < 92)
   {
      polozio++; ocjena_9++;
   }
   if (ukupno2 > 85 && ukupno2 < 92)
   {
      polozio++; ocjena_9++;
   }
   if (ukupno3 > 85 && ukupno3 < 92)
   {
      polozio++; ocjena_9++;
   }


   if (ukupno1 > 92 && ukupno1 < 100)
   {
      polozio++; ocjena_10++;
   }
   if (ukupno2 > 92 && ukupno2 < 100)
   {
      polozio++; ocjena_10++;
   }
   if (ukupno3 > 92 && ukupno3 < 100)
   {
      polozio++; ocjena_10++;
   }


   if (polozio == 0)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (polozio == 1)
   {
      printf("Jedan student je polozio.");
   }
   else if (polozio == 2)
   {
      printf("Dva studenta su polozila.");
   }
   else if (polozio == 3)
   {
      printf("Sva tri studenta su polozila.\n");
   }

   if (polozio == 3)
   {
      if (ocjena_6 == 3 || ocjena_7 == 3 || ocjena_8 == 3 || ocjena_9 == 3 || ocjena_10 == 3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (ocjena_6 == 2 || ocjena_7 == 2 || ocjena_8 == 2 || ocjena_9 == 2 || ocjena_10 == 2)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
