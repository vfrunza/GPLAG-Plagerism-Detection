#include <stdio.h>
#include <math.h>

int main()
{
   float prva_parcijala1, druga_parcijala1, prisustvo1, zavrsni1, zadace1, ukupno1;
   float prva_parcijala2, druga_parcijala2, prisustvo2, zavrsni2, zadace2, ukupno2;
   float prva_parcijala3, druga_parcijala3, prisustvo3, zavrsni3, zadace3, ukupno3;
   int   ocjena1 = 5, ocjena2 = 5, ocjena3 = 5;

   printf("Unesite bodove za Tarika:\n");       /*Unos za prvog studenta*/
   printf("I parcijalni ispit: ");
   scanf("%f", &prva_parcijala1);
   if (prva_parcijala1 < 0 || prva_parcijala1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &druga_parcijala1);
   if (druga_parcijala1 < 0 || druga_parcijala1 > 20)
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

   printf("Unesite bodove za Bojana:\n");       /*Unos za drugog studenta*/
   printf("I parcijalni ispit: ");
   scanf("%f", &prva_parcijala2);
   if (prva_parcijala2 < 0 || prva_parcijala2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &druga_parcijala2);
   if (druga_parcijala2 < 0 || druga_parcijala2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo2);
   if (prisustvo2 < 0 || prisustvo2 > 20)
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

   printf("Unesite bodove za Mirzu:\n");      /*Unos za treceg studenta*/
   printf("I parcijalni ispit: ");
   scanf("%f", &prva_parcijala3);
   if (prva_parcijala3 < 0 || prva_parcijala3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &druga_parcijala3);
   if (druga_parcijala3 < 0 || druga_parcijala3 > 20)
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

   ukupno1 = prva_parcijala1 + druga_parcijala1 + prisustvo1 + zadace1 + zavrsni1;
   ukupno1 = ((int)(ukupno1 * 100 + 0.5)) / 100.0;
   ukupno2 = prva_parcijala2 + druga_parcijala2 + prisustvo2 + zadace2 + zavrsni2;
   ukupno2 = ((int)(ukupno2 * 100 + 0.5)) / 100.0;
   ukupno3 = prva_parcijala3 + druga_parcijala3 + prisustvo3 + zadace3 + zavrsni3;
   ukupno3 = ((int)(ukupno3 * 100 + 0.5)) / 100.0;

   if (ukupno1 >= 55 && ukupno2 >= 55 && ukupno3 >= 55)
   {
      printf("Sva tri studenta su polozila.");
   }
   else if ((ukupno1 >= 55 && ukupno2 >= 55 && ukupno3 < 55) || (ukupno1 >= 55 && ukupno3 < 55 && ukupno2 >= 55) || (ukupno1 < 55 && ukupno2 >= 55 && ukupno3 >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   else if ((ukupno1 >= 55 && ukupno2 < 55 && ukupno3 < 55) || (ukupno1 < 55 && ukupno2 >= 55 && ukupno3 < 55) || (ukupno1 < 55 && ukupno2 < 55 && ukupno3 >= 55))
   {
      printf("Jedan student je polozio.");
   }
   else if (ukupno1 < 55 && ukupno2 < 55 && ukupno3 < 55)
   {
      printf("Nijedan student nije polozio.");
   }

   if (ukupno1 >= 55 && ukupno1 < 65)
   {
      ocjena1 = 6;
   }
   else if (ukupno1 >= 65 && ukupno1 < 75)
   {
      ocjena1 = 7;
   }
   else if (ukupno1 >= 75 && ukupno1 < 85)
   {
      ocjena1 = 8;
   }
   else if (ukupno1 >= 85 && ukupno1 < 92)
   {
      ocjena1 = 9;
   }
   else if (ukupno1 >= 92)
   {
      ocjena1 = 10;
   }

   if (ukupno2 >= 55 && ukupno2 < 65)
   {
      ocjena2 = 6;
   }
   else if (ukupno2 >= 65 && ukupno2 < 75)
   {
      ocjena2 = 7;
   }
   else if (ukupno2 >= 75 && ukupno2 < 85)
   {
      ocjena2 = 8;
   }
   else if (ukupno2 >= 85 && ukupno2 < 92)
   {
      ocjena2 = 9;
   }
   else if (ukupno2 >= 92)
   {
      ocjena2 = 10;
   }

   if (ukupno3 >= 55 && ukupno3 < 65)
   {
      ocjena3 = 6;
   }
   else if (ukupno3 >= 65 && ukupno3 < 75)
   {
      ocjena3 = 7;
   }
   else if (ukupno3 >= 75 && ukupno3 < 85)
   {
      ocjena3 = 8;
   }
   else if (ukupno3 >= 85 && ukupno3 < 92)
   {
      ocjena3 = 9;
   }
   else if (ukupno3 >= 92)
   {
      ocjena3 = 10;
   }

   if (ukupno1 >= 55 && ukupno2 >= 55 && ukupno3 >= 55)
   {
      if (ocjena1 == ocjena2 && ocjena1 == ocjena3)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((ocjena1 == ocjena2 && ocjena1 != ocjena3) || (ocjena1 == ocjena3 && ocjena1 != ocjena2) || (ocjena2 == ocjena3 && ocjena2 != ocjena1))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (ocjena1 != ocjena2 && ocjena1 != ocjena3 && ocjena2 != ocjena3)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
