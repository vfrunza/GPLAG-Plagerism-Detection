#include <stdio.h>

int main()
{
   float firstp1, secondp1, prisustvo1, homework1, final1;
   float firstp2, secondp2, prisustvo2, homework2, final2;
   float firstp3, secondp3, prisustvo3, homework3, final3;

   int ocjena_1, ocjena_2, ocjena_3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &firstp1);
   if (firstp1 > 20 || firstp1 < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &secondp1);
   if (secondp1 > 20 || secondp1 < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo1);
   if (prisustvo1 < 0 || prisustvo1 > 10)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &homework1);
   if (homework1 < 0 || homework1 > 10)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &final1);
   if (final1 < 0 || final1 > 40)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &firstp2);
   if (firstp2 > 20 || firstp2 < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &secondp2);
   if (secondp2 > 20 || secondp2 < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo2);
   if (prisustvo2 < 0 || prisustvo2 > 10)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &homework2);
   if (homework2 < 0 || homework2 > 10)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &final2);
   if (final2 < 0 || final2 > 40)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &firstp3);
   if (firstp3 > 20 || firstp3 < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &secondp3);
   if (secondp3 > 20 || secondp3 < 0)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo3);
   if (prisustvo3 < 0 || prisustvo3 > 10)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &homework3);
   if (homework3 < 0 || homework3 > 10)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &final3);
   if (final3 < 0 || final3 > 40)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }


   ocjena_1 = firstp1 + secondp1 + homework1 + prisustvo1 + final1;
   ocjena_2 = firstp2 + secondp2 + homework2 + prisustvo2 + final2;
   ocjena_3 = firstp3 + secondp3 + homework3 + prisustvo3 + final3;

   /*koliko ih je polozilo*/

   if (ocjena_1 >= 55 && ocjena_1 <= 100 && ocjena_2 < 55 && ocjena_3 < 55)
   {
      printf("Jedan student je polozio.\n");
   }

   else if (ocjena_1 < 55 && ocjena_2 < 55 && ocjena_3 >= 55 && ocjena_3 <= 100)
   {
      printf("Jedan student je polozio.\n");
   }

   else if (ocjena_1 < 55 && ocjena_3 < 55 && ocjena_2 >= 55 && ocjena_2 <= 100)
   {
      printf("Jedan student je polozio.\n");
   }

   if (ocjena_1 < 55)
   {
      if (ocjena_2 >= 55 && ocjena_2 <= 100 && ocjena_3 >= 55 && ocjena_3 <= 100)
      {
         printf("Dva studenta su polozila.\n");
      }
   }

   if (ocjena_2 < 55)
   {
      if (ocjena_1 >= 55 && ocjena_1 <= 100 && ocjena_3 >= 55 && ocjena_3 <= 100)
      {
         printf("Dva studenta su polozila.\n");
      }
   }

   if (ocjena_3 < 55)
   {
      if (ocjena_1 >= 55 && ocjena_1 <= 100 && ocjena_2 >= 55 && ocjena_2 <= 100)
      {
         printf("Dva studenta su polozila.\n");
      }
   }

   else if (ocjena_1 >= 55 && ocjena_1 <= 100 && ocjena_3 >= 55 && ocjena_3 <= 100 && ocjena_2 >= 55 && ocjena_2 <= 100)
   {
      printf("Sva tri studenta su polozila.\n");
   }

   /*koliko je ocjena isto*/

   if (ocjena_1 < 55 && ocjena_2 < 55)
   {
      if (ocjena_3 < 55)
      {
         printf("Nijedan student nije polozio.\n");
      }
   }
   else
   {
      if (ocjena_1 == ocjena_2 && ocjena_3 == ocjena_1)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }

      if (ocjena_3 != ocjena_1)
      {
         if (ocjena_1 == ocjena_2)
         {
            printf("Dva od tri studenta imaju istu ocjenu.\n");
         }
         else if (ocjena_3 == ocjena_2)
         {
            printf("Dva od tri studenta imaju istu ocjenu.\n");
         }
      }
      if (ocjena_1 == ocjena_3 && ocjena_2 != ocjena_3)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }



      else if (ocjena_1 != ocjena_2 && ocjena_3 != ocjena_1 && ocjena_3 != ocjena_2 && ocjena_1 >= 55 && ocjena_2 >= 55 && ocjena_3 >= 55)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }



   /*if (ocjena_3!=ocjena_1)
    * {
    *      if (ocjena_1==ocjena_2) printf("Dva od tri studenta imaju istu ocjenu.\n");
    *      else if (ocjena_3==ocjena_2) printf("Dva od tri studenta imaju istu ocjenu.\n");
    * }
    * if (ocjena_1==ocjena_3 && ocjena_2!=ocjena_3) printf("Dva od tri studenta imaju istu ocjenu.\n");
    *
    * }
    */


   return(0);
}
