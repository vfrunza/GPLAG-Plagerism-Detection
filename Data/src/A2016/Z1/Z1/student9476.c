#include <stdio.h>
#define EPS    0.0001
int main()
{
   float prviparc1, prviparc2, prviparc3, drugiparc1, drugiparc2, drugiparc3;
   float prisustvo1, prisustvo2, prisustvo3, zadace1, zadace2, zadace3, zavrsni1, zavrsni2, zavrsni3;
   int   ocjena1, ocjena2, ocjena3;
   float zbir1, zbir2, zbir3;

   /* UNOS BODOVA*/
   /*TARIK*/
   printf("Unesite bodove za Tarika:\n");

   printf("I parcijalni ispit: ");
   scanf("%f", &prviparc1);
   if (prviparc1 < 0 || prviparc1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &drugiparc1);
   if (drugiparc1 < 0 || drugiparc1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo1);
   if (prisustvo1 < 0 || prisustvo1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadace1);
   if (zadace1 < 0 || zadace1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni1);
   if (zavrsni1 < 0 || zavrsni1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   /* BOJAN*/

   printf("Unesite bodove za Bojana:\n");

   printf("I parcijalni ispit: ");
   scanf("%f", &prviparc2);
   if (prviparc2 < 0 || prviparc2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &drugiparc2);
   if (drugiparc2 < 0 || drugiparc2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo2);
   if (prisustvo2 < 0 || prisustvo2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadace2);
   if (zadace2 < 0 || zadace2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni2);
   if (zavrsni2 < 0 || zavrsni2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   /* MIRZA */
   printf("Unesite bodove za Mirzu:\n");

   printf("I parcijalni ispit: ");
   scanf("%f", &prviparc3);
   if (prviparc3 < 0 || prviparc3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &drugiparc3);
   if (drugiparc3 < 0 || drugiparc3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo3);
   if (prisustvo3 < 0 || prisustvo3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadace3);
   if (zadace3 < 0 || zadace3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni3);
   if (zavrsni3 < 0 || zavrsni3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   zbir1 = prviparc1 + drugiparc1 + prisustvo1 + zadace1 + zavrsni1 + EPS;
   zbir2 = prviparc2 + drugiparc2 + prisustvo2 + zadace2 + zavrsni2 + EPS;
   zbir3 = prviparc3 + drugiparc3 + prisustvo3 + zadace3 + zavrsni3 + EPS;

   if (zbir1 >= 0 && zbir1 < 55)
   {
      ocjena1 = 5;
   }
   if (zbir1 >= 55 && zbir1 < 65)
   {
      ocjena1 = 6;
   }
   if (zbir1 >= 65 && zbir1 < 75)
   {
      ocjena1 = 7;
   }
   if (zbir1 >= 75 && zbir1 < 85)
   {
      ocjena1 = 8;
   }
   if (zbir1 >= 85 && zbir1 < 92)
   {
      ocjena1 = 9;
   }
   if (zbir1 >= 92 && zbir1 <= 100)
   {
      ocjena1 = 10;
   }

   if (zbir2 >= 0 && zbir2 < 55)
   {
      ocjena2 = 5;
   }
   if (zbir2 >= 55 && zbir2 < 65)
   {
      ocjena2 = 6;
   }
   if (zbir2 >= 65 && zbir2 < 75)
   {
      ocjena2 = 7;
   }
   if (zbir2 >= 75 && zbir2 < 85)
   {
      ocjena2 = 8;
   }
   if (zbir2 >= 85 && zbir2 < 92)
   {
      ocjena2 = 9;
   }
   if (zbir2 >= 92 && zbir2 <= 100)
   {
      ocjena2 = 10;
   }

   if (zbir3 >= 0 && zbir3 < 55)
   {
      ocjena3 = 5;
   }
   if (zbir3 >= 55 && zbir3 < 65)
   {
      ocjena3 = 6;
   }
   if (zbir3 >= 65 && zbir3 < 75)
   {
      ocjena3 = 7;
   }
   if (zbir3 >= 75 && zbir3 < 85)
   {
      ocjena3 = 8;
   }
   if (zbir3 >= 85 && zbir3 < 92)
   {
      ocjena3 = 9;
   }
   if (zbir3 >= 92 && zbir3 <= 100)
   {
      ocjena3 = 10;
   }

   if (ocjena1 == 5 && ocjena2 == 5 && ocjena3 == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((ocjena1 == 5 && ocjena2 == 5 && ocjena3 > 5) || (ocjena1 == 5 && ocjena2 > 5 && ocjena3 == 5) || (ocjena1 > 5 && ocjena2 == 5 && ocjena3 == 5))
   {
      printf("Jedan student je polozio.");
   }
   else if ((ocjena1 == 5 && ocjena2 > 5 && ocjena3 > 5) || (ocjena1 > 5 && ocjena2 == 5 && ocjena3 > 5) || (ocjena1 > 5 && ocjena2 > 5 && ocjena3 == 5))
   {
      printf("Dva studenta su polozila.");
   }
   else if (ocjena1 > 5 && ocjena2 > 5 && ocjena3 > 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if (ocjena1 == ocjena2 && ocjena1 == ocjena3)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
         return(0);
      }
      if ((ocjena1 == ocjena2 && ocjena1 != ocjena3) || (ocjena1 == ocjena3 && ocjena1 != ocjena2) || (ocjena2 == ocjena3 && ocjena2 != ocjena1))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
         return(0);
      }
      if (ocjena1 != ocjena2 && ocjena2 != ocjena3 && ocjena1 != ocjena3)
      {
         printf("Svaki student ima razlicitu ocjenu.");
         return(0);
      }
   }

   return(0);
}
