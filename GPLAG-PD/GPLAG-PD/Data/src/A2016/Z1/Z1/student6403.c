#include <stdio.h>
#include <math.h>

int main()
{
   float        prvi, drugi, zadaca, prisustvo, zavrsni, ukupno;
   int          ocjena1, ocjena2, ocjena3;
   const double eps = 1e-5;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &prvi);
   if (prvi < 0 || prvi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &drugi);
   if (drugi < 0 || drugi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo);
   if (prisustvo < 0 || prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadaca);
   if (zadaca < 0 || zadaca > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni);
   if (zavrsni < 0 || zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ukupno = prvi + drugi + prisustvo + zadaca + zavrsni;
   ukupno = (int)(ukupno + eps * fabs(ukupno));

   if (ukupno < 55)
   {
      ocjena1 = 5;
   }

   if (ukupno >= 55 && ukupno < 65)
   {
      ocjena1 = 6;
   }

   if (ukupno >= 65 && ukupno < 75)
   {
      ocjena1 = 7;
   }

   if (ukupno >= 75 && ukupno < 85)
   {
      ocjena1 = 8;
   }
   if (ukupno >= 85 && ukupno < 92)
   {
      ocjena1 = 9;
   }
   if (ukupno >= 92 && ukupno <= 100)
   {
      ocjena1 = 10;
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &prvi);
   if (prvi < 0 || prvi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &drugi);
   if (drugi < 0 || drugi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo);
   if (prisustvo < 0 || prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadaca);
   if (zadaca < 0 || zadaca > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni);
   if (zavrsni < 0 || zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   ukupno = prvi + drugi + prisustvo + zadaca + zavrsni;
   ukupno = (int)(ukupno + eps * fabs(ukupno));
   if (ukupno < 55)
   {
      ocjena2 = 5;
   }

   if (ukupno >= 55 && ukupno < 65)
   {
      ocjena2 = 6;
   }

   if (ukupno >= 65 && ukupno < 75)
   {
      ocjena2 = 7;
   }


   if (ukupno >= 75 && ukupno < 85)
   {
      ocjena2 = 8;
   }
   if (ukupno >= 85 && ukupno < 92)
   {
      ocjena2 = 9;
   }
   if (ukupno >= 92 && ukupno <= 100)
   {
      ocjena2 = 10;
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &prvi);
   if (prvi < 0 || prvi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &drugi);
   if (drugi < 0 || drugi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo);
   if (prisustvo < 0 || prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadaca);
   if (zadaca < 0 || zadaca > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni);
   if (zavrsni < 0 || zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   ukupno = prvi + drugi + prisustvo + zadaca + zavrsni;
   ukupno = (int)(ukupno + eps * fabs(ukupno));
   if (ukupno < 55)
   {
      ocjena3 = 5;
   }

   if (ukupno >= 55 && ukupno < 65)
   {
      ocjena3 = 6;
   }

   if (ukupno >= 65 && ukupno < 75)
   {
      ocjena3 = 7;
   }

   if (ukupno >= 75 && ukupno < 85)
   {
      ocjena3 = 8;
   }
   if (ukupno >= 85 && ukupno < 92)
   {
      ocjena3 = 9;
   }
   if (ukupno >= 92 && ukupno <= 100)
   {
      ocjena3 = 10;
   }

   if (ocjena1 == 5 && ocjena2 == 5 && ocjena3 == 5)
   {
      printf("Nijedan student nije polozio.");
      return(0);
   }

   if ((ocjena1 > 5 && ocjena2 == 5 && ocjena3 == 5) || (ocjena1 == 5 && ocjena2 > 5 && ocjena3 == 5) || (ocjena1 == 5 && ocjena2 == 5 && ocjena3 > 5))
   {
      printf("Jedan student je polozio.");
      return(0);
   }

   if ((ocjena1 > 5 && ocjena2 > 5 && ocjena3 == 5) || (ocjena1 > 5 && ocjena2 == 5 && ocjena3 > 5) || (ocjena1 == 5 && ocjena2 > 5 && ocjena3 > 5))
   {
      printf("Dva studenta su polozila.");
      return(0);
   }

   if (ocjena1 > 5 && ocjena2 > 5 && ocjena3 > 5)
   {
      printf("Sva tri studenta su polozila.\n");

      if (ocjena1 == ocjena2 && ocjena2 == ocjena3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }

      if ((ocjena1 == ocjena2 && ocjena2 != ocjena3) || (ocjena1 == ocjena3 && ocjena1 != ocjena2) || (ocjena2 == ocjena3 && ocjena1 != ocjena2))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }

      if (ocjena1 != ocjena2 && ocjena2 != ocjena3)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
