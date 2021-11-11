#include <stdio.h>

int main()
{
   double tarik_prvi, tarik_drugi, tarik_zadaca, tarik_prisustvo, tarik_zavrsni, tarik_suma;
   double bojan_prvi, bojan_drugi, bojan_zadaca, bojan_prisustvo, bojan_zavrsni, bojan_suma;
   double mirza_prvi, mirza_drugi, mirza_zadaca, mirza_prisustvo, mirza_zavrsni, mirza_suma;
   int    brojac5 = 0, brojac6 = 0, brojac7 = 0, brojac8 = 0, brojac9 = 0, brojac10 = 0;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &tarik_prvi);
   if (tarik_prvi < 0 || tarik_prvi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &tarik_drugi);
   if (tarik_drugi < 0 || tarik_drugi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &tarik_prisustvo);
   if (tarik_prisustvo < 0 || tarik_prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &tarik_zadaca);
   if (tarik_zadaca < 0 || tarik_zadaca > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &tarik_zavrsni);
   if (tarik_zavrsni < 0 || tarik_zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &bojan_prvi);
   if (bojan_prvi < 0 || bojan_prvi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &bojan_drugi);
   if (bojan_drugi < 0 || bojan_drugi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &bojan_prisustvo);
   if (bojan_prisustvo < 0 || bojan_prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &bojan_zadaca);
   if (bojan_zadaca < 0 || bojan_zadaca > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bojan_zavrsni);
   if (bojan_zavrsni < 0 || bojan_zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &mirza_prvi);
   if (mirza_prvi < 0 || mirza_prvi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &mirza_drugi);
   if (mirza_drugi < 0 || mirza_drugi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &mirza_prisustvo);
   if (mirza_prisustvo < 0 || mirza_prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &mirza_zadaca);
   if (mirza_zadaca < 0 || mirza_zadaca > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &mirza_zavrsni);
   if (mirza_zavrsni < 0 || mirza_zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   tarik_suma = tarik_prvi + tarik_drugi + tarik_zadaca + tarik_prisustvo + tarik_zavrsni;
   bojan_suma = bojan_prvi + bojan_drugi + bojan_zadaca + bojan_prisustvo + bojan_zavrsni;
   mirza_suma = mirza_prvi + mirza_drugi + mirza_zadaca + mirza_prisustvo + mirza_zavrsni;


   if (tarik_suma < 55)
   {
      brojac5++;
   }
   if (bojan_suma < 55)
   {
      brojac5++;
   }
   if (mirza_suma < 55)
   {
      brojac5++;
   }

   if (tarik_suma >= 55 && tarik_suma < 65)
   {
      brojac6++;
   }
   if (bojan_suma >= 55 && bojan_suma < 65)
   {
      brojac6++;
   }
   if (mirza_suma >= 55 && mirza_suma < 65)
   {
      brojac6++;
   }

   if (tarik_suma >= 65 && tarik_suma < 75)
   {
      brojac7++;
   }
   if (bojan_suma >= 65 && bojan_suma < 75)
   {
      brojac7++;
   }
   if (mirza_suma >= 65 && mirza_suma < 75)
   {
      brojac7++;
   }

   if (tarik_suma >= 75 && tarik_suma < 85)
   {
      brojac8++;
   }
   if (bojan_suma >= 75 && bojan_suma < 85)
   {
      brojac8++;
   }
   if (mirza_suma >= 75 && mirza_suma < 85)
   {
      brojac8++;
   }

   if (tarik_suma >= 85 && tarik_suma < 95)
   {
      brojac9++;
   }
   if (bojan_suma >= 85 && bojan_suma < 95)
   {
      brojac9++;
   }
   if (mirza_suma >= 85 && mirza_suma < 95)
   {
      brojac9++;
   }

   if (tarik_suma >= 95 && tarik_suma <= 100)
   {
      brojac10++;
   }
   if (bojan_suma >= 95 && bojan_suma <= 100)
   {
      brojac10++;
   }
   if (mirza_suma >= 95 && mirza_suma <= 100)
   {
      brojac10++;
   }

   if (brojac5 == 3)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (brojac5 == 2)
   {
      printf("Jedan student je polozio.");
   }
   else if (brojac5 == 1)
   {
      printf("Dva studenta su polozila.");
   }
   else if (brojac5 == 0)
   {
      printf("Sva tri studenta su polozila.");
   }

   if (brojac5 == 0)
   {
      if (brojac6 == 3 || brojac7 == 3 || brojac8 == 3 || brojac9 == 3 || brojac10 == 3)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (brojac6 == 2 || brojac7 == 2 || brojac8 == 2 || brojac9 == 2 || brojac10 == 2)
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
