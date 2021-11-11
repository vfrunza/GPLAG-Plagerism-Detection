#include <stdio.h>
#include <math.h>

int main()
{
   double ukupno, prvi_parcijalni, drugi_parcijalni, zavrsni, prisustvo, zadace;
   double ukupno1, prvi_parcijalni1, drugi_parcijalni1, zavrsni1, zadace1, prisustvo1;
   double ukupno2, prvi_parcijalni2, drugi_parcijalni2, zavrsni2, zadace2, prisustvo2;
   int    ocjena1 = 5, ocjena2 = 5, ocjena3 = 5, brojac = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &prvi_parcijalni);
   if (prvi_parcijalni < 0 || prvi_parcijalni > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &drugi_parcijalni);
   if (drugi_parcijalni < 0 || drugi_parcijalni > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &prisustvo);
   if (prisustvo < 0 || prisustvo > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &zadace);
   if (zadace < 0 || zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni);
   if (zavrsni < 0 || zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &prvi_parcijalni1);
   if (prvi_parcijalni1 < 0 || prvi_parcijalni1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &drugi_parcijalni1);
   if (drugi_parcijalni1 < 0 || drugi_parcijalni1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &prisustvo1);
   if (prisustvo1 < 0 || prisustvo1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &zadace1);
   if (zadace1 < 0 || zadace1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni1);
   if (zavrsni1 < 0 || zavrsni1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &prvi_parcijalni2);
   if (prvi_parcijalni2 < 0 || prvi_parcijalni2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &drugi_parcijalni2);
   if (drugi_parcijalni2 < 0 || drugi_parcijalni2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &prisustvo2);
   if (prisustvo2 < 0 || prisustvo2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &zadace2);
   if (zadace2 < 0 || zadace2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni2);
   if (zavrsni2 < 0 || zavrsni2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   ukupno  = prvi_parcijalni + drugi_parcijalni + zadace + zavrsni + prisustvo;
   ukupno1 = prvi_parcijalni1 + drugi_parcijalni1 + zadace1 + zavrsni1 + prisustvo1;
   ukupno2 = prvi_parcijalni2 + drugi_parcijalni2 + zadace2 + zavrsni2 + prisustvo2;
   if (ukupno >= 55)
   {
      brojac++;
   }
   if (ukupno1 >= 55)
   {
      brojac++;
   }
   if (ukupno2 >= 55)
   {
      brojac++;
   }

   if (brojac == 0)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (brojac == 1)
   {
      printf("Jedan student je polozio.");
   }
   else if (brojac == 2)
   {
      printf("Dva studenta su polozila.");
   }
   else if (brojac == 3)
   {
      printf("Sva tri studenta su polozila.");
   }
   else
   {
      printf("Greska!");
   }

   if (ukupno < 55)
   {
      ocjena1 = 5;
   }
   else if (ukupno >= 55 && ukupno < 65)
   {
      ocjena1 = 6;
   }
   else if (ukupno >= 65 && ukupno < 75)
   {
      ocjena1 = 7;
   }
   else if (ukupno >= 75 && ukupno < 85)
   {
      ocjena1 = 8;
   }
   else if (ukupno >= 85 && ukupno < 92)
   {
      ocjena1 = 9;
   }
   else if (ukupno >= 92 && ukupno <= 100)
   {
      ocjena1 = 10;
   }
   else
   {
      printf("Greska!");
   }

   if (ukupno1 < 55)
   {
      ocjena2 = 5;
   }
   else if (ukupno1 >= 55 && ukupno1 < 65)
   {
      ocjena2 = 6;
   }
   else if (ukupno1 >= 65 && ukupno1 < 75)
   {
      ocjena2 = 7;
   }
   else if (ukupno1 >= 75 && ukupno1 < 85)
   {
      ocjena2 = 8;
   }
   else if (ukupno1 >= 85 && ukupno1 < 92)
   {
      ocjena2 = 9;
   }
   else if (ukupno1 >= 92 && ukupno1 <= 100)
   {
      ocjena2 = 10;
   }
   else
   {
      printf("Greska!");
   }

   if (ukupno2 < 55)
   {
      ocjena3 = 5;
   }
   else if (ukupno2 >= 55 && ukupno2 < 65)
   {
      ocjena3 = 6;
   }
   else if (ukupno2 >= 65 && ukupno2 < 75)
   {
      ocjena3 = 7;
   }
   else if (ukupno2 >= 75 && ukupno2 < 85)
   {
      ocjena3 = 8;
   }
   else if (ukupno2 >= 85 && ukupno2 < 92)
   {
      ocjena3 = 9;
   }
   else if (ukupno2 >= 92 && ukupno2 <= 100)
   {
      ocjena3 = 10;
   }
   else
   {
      printf("Greska!");
   }

   if (brojac == 3)
   {
      if (ocjena1 == ocjena2 && ocjena1 == ocjena3 && ocjena2 == ocjena3)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (ocjena1 == ocjena2 || ocjena1 == ocjena3 || ocjena2 == ocjena3)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
