#include <stdio.h>
int main()
{
   double prviparc, drugiparc, Prisustvo, Zadace, Zavrsni;
   double Tarik, Bojan, Mirza;
   int    ocjena1 = '0', ocjena2 = '0', ocjena3 = 'c';


   printf("Unesite bodove za Tarika: \n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &prviparc);
   if (prviparc < 0 || prviparc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &drugiparc);
   if (drugiparc < 0 || drugiparc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &Prisustvo);
   if (Prisustvo < 0 || Prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &Zadace);
   if (Zadace < 0 || Zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &Zavrsni);
   if (Zavrsni < 0 || Zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   ocjena1 = prviparc + drugiparc + Prisustvo + Zadace + Zavrsni;
   if (ocjena1 < 55)
   {
      ocjena1 = 5;
   }
   else if (ocjena1 >= 55 && ocjena1 < 65)
   {
      ocjena1 = 6;
   }
   else if (ocjena1 >= 65 && ocjena1 < 75)
   {
      ocjena1 = 7;
   }
   else if (ocjena1 >= 75 && ocjena1 < 85)
   {
      ocjena1 = 8;
   }
   else if (ocjena1 >= 85 && ocjena1 < 92)
   {
      ocjena1 = 9;
   }
   else if (ocjena1 >= 92 && ocjena1 <= 100)
   {
      ocjena1 = 10;
   }

   printf("Unesite bodove za Bojana: \n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &prviparc);
   if (prviparc < 0 || prviparc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &drugiparc);
   if (drugiparc < 0 || drugiparc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &Prisustvo);
   if (Prisustvo < 0 || Prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &Zadace);
   if (Zadace < 0 || Zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &Zavrsni);
   if (Zavrsni < 0 || Zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   ocjena2 = prviparc + drugiparc + Prisustvo + Zadace + Zavrsni;
   if (ocjena2 < 55)
   {
      ocjena2 = 5;
   }
   else if (ocjena2 >= 55 && ocjena2 < 65)
   {
      ocjena2 = 6;
   }
   else if (ocjena2 >= 65 && ocjena2 < 75)
   {
      ocjena2 = 7;
   }
   else if (ocjena2 >= 75 && ocjena2 < 85)
   {
      ocjena2 = 8;
   }
   else if (ocjena2 >= 85 && ocjena2 < 92)
   {
      ocjena2 = 9;
   }
   else if (ocjena2 >= 92 && ocjena2 <= 100)
   {
      ocjena2 = 10;
   }

   printf("Unesite bodove za Mirzu: \n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &prviparc);
   if (prviparc < 0 || prviparc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &drugiparc);
   if (drugiparc < 0 || drugiparc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &Prisustvo);
   if (Prisustvo < 0 || Prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &Zadace);
   if (Zadace < 0 || Zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &Zavrsni);
   if (Zavrsni < 0 || Zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   ocjena3 = prviparc + drugiparc + Prisustvo + Zadace + Zavrsni;
   if (ocjena3 < 55)
   {
      ocjena3 = 5;
   }
   else if (ocjena3 >= 55 && ocjena3 < 65)
   {
      ocjena3 = 6;
   }
   else if (ocjena3 >= 65 && ocjena3 < 75)
   {
      ocjena3 = 7;
   }
   else if (ocjena3 >= 75 && ocjena3 < 85)
   {
      ocjena3 = 8;
   }
   else if (ocjena3 >= 85 && ocjena3 < 92)
   {
      ocjena3 = 9;
   }
   else if (ocjena3 >= 92 && ocjena3 <= 100)
   {
      ocjena3 = 10;
   }

   if (ocjena1 <= 5 && ocjena2 <= 5 && ocjena3 <= 5)
   {
      printf("Nijedan student nije polozio.\n");
      return(0);
   }
   else if (ocjena1 > 5 && ocjena2 > 5 && ocjena3 > 5)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else if ((ocjena1 > 5 && ocjena2 > 5 && ocjena3 <= 5) || (ocjena1 > 5 && ocjena2 <= 5 && ocjena3 > 5) || (ocjena1 <= 5 && ocjena2 > 5 && ocjena3 > 5))
   {
      printf("Dva studenta su polozila.\n");
      return(0);
   }
   else if ((ocjena1 > 5 && ocjena2 <= 5 && ocjena3 <= 5) || (ocjena1 <= 5 && ocjena2 <= 5 && ocjena3 > 5) || (ocjena1 <= 5 && ocjena2 > 5 && ocjena3 <= 5))
   {
      printf("Jedan student je polozio.\n");
      return(0);
   }

   if (ocjena1 == ocjena2 && ocjena2 == ocjena3 && ocjena1 == ocjena3)
   {
      printf("Sva tri studenta imaju istu ocjenu.\n");
      return(0);
   }
   else if ((ocjena1 == ocjena3 && ocjena1 != ocjena2 && ocjena3 != ocjena2) || (ocjena1 == ocjena2 && ocjena1 != ocjena3 && ocjena2 != ocjena3) || (ocjena2 == ocjena3 && ocjena2 != ocjena1 && ocjena3 != ocjena1))
   {
      printf("Dva od tri studenta imaju istu ocjenu.\n");
      return(0);
   }
   else if (ocjena1 != ocjena2 && ocjena3 != ocjena1 && ocjena2 != ocjena3)
   {
      printf("Svaki student ima razlicitu ocjenu.\n");
      return(0);
   }
   return(0);
}
