#include <stdio.h>

int main()
{
   double tarik1, tarik2, tarik_p, tarik_z, tarik_zi;
   double bojan1, bojan2, bojan_p, bojan_z, bojan_zi;
   double mirza1, mirza2, mirza_p, mirza_z, mirza_zi;
   double bodovi_t, bodovi_b, bodovi_m;
   int    ocjena_t, ocjena_b, ocjena_m;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &tarik1);
   if (tarik1 > 20 || tarik1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &tarik2);
   if (tarik2 > 20 || tarik2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &tarik_p);
   if (tarik_p > 10 || tarik_p < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &tarik_z);
   if (tarik_z > 10 || tarik_z < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &tarik_zi);
   if (tarik_zi > 40 || tarik_zi < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &bojan1);
   if (bojan1 > 20 || bojan1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &bojan2);
   if (bojan2 > 20 || bojan2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &bojan_p);
   if (bojan_p > 10 || bojan_p < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &bojan_z);
   if (bojan_z > 10 || bojan_z < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bojan_zi);
   if (bojan_zi > 40 || bojan_zi < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &mirza1);
   if (mirza1 > 20 || mirza1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &mirza2);
   if (mirza2 > 20 || mirza2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &mirza_p);
   if (mirza_p > 10 || mirza_p < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &mirza_z);
   if (mirza_z > 10 || mirza_z < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &mirza_zi);
   if (mirza_zi > 40 || mirza_zi < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   bodovi_t = tarik1 + tarik2 + tarik_p + tarik_z + tarik_zi;
   bodovi_b = bojan1 + bojan2 + bojan_p + bojan_z + bojan_zi;
   bodovi_m = mirza1 + mirza2 + mirza_p + mirza_z + mirza_zi;
   if (bodovi_t < 55)
   {
      ocjena_t = 5;
   }
   else if (bodovi_t >= 55 && bodovi_t < 65)
   {
      ocjena_t = 6;
   }
   else if (bodovi_t >= 65 && bodovi_t < 75)
   {
      ocjena_t = 7;
   }
   else if (bodovi_t >= 75 && bodovi_t < 85)
   {
      ocjena_t = 8;
   }
   else if (bodovi_t >= 85 && bodovi_t < 92)
   {
      ocjena_t = 9;
   }
   else if (bodovi_t >= 92 && bodovi_t <= 100)
   {
      ocjena_t = 10;
   }

   if (bodovi_b < 55)
   {
      ocjena_b = 5;
   }
   else if (bodovi_b >= 55 && bodovi_b < 65)
   {
      ocjena_b = 6;
   }
   else if (bodovi_b >= 65 && bodovi_b < 75)
   {
      ocjena_b = 7;
   }
   else if (bodovi_b >= 75 && bodovi_b < 85)
   {
      ocjena_b = 8;
   }
   else if (bodovi_b >= 85 && bodovi_b < 92)
   {
      ocjena_b = 9;
   }
   else if (bodovi_b >= 92 && bodovi_b <= 100)
   {
      ocjena_b = 10;
   }

   if (bodovi_m < 55)
   {
      ocjena_m = 5;
   }
   else if (bodovi_m >= 55 && bodovi_m < 65)
   {
      ocjena_m = 6;
   }
   else if (bodovi_m >= 65 && bodovi_m < 75)
   {
      ocjena_m = 7;
   }
   else if (bodovi_m >= 75 && bodovi_m < 85)
   {
      ocjena_m = 8;
   }
   else if (bodovi_m >= 85 && bodovi_m < 92)
   {
      ocjena_m = 9;
   }
   else if (bodovi_m >= 92 && bodovi_m <= 100)
   {
      ocjena_m = 10;
   }

   if (ocjena_t <= 5 && ocjena_b <= 5 && ocjena_m <= 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((ocjena_t < 6 && ocjena_b < 6 && ocjena_m >= 6) || (ocjena_t < 6 && ocjena_b >= 6 && ocjena_m < 6) || (ocjena_t >= 6 && ocjena_b < 6 && ocjena_m < 6))
   {
      printf("Jedan student je polozio.");
   }
   else if ((ocjena_t >= 5 && ocjena_b >= 5 && ocjena_m <= 5) || (ocjena_t >= 5 && ocjena_b <= 5 && ocjena_m >= 5) || (ocjena_t <= 5 && ocjena_b >= 5 && ocjena_m >= 5))
   {
      printf("Dva studenta su polozila.");
   }
   else if (ocjena_t != 5 && ocjena_b != 5 && ocjena_m != 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if (ocjena_t == ocjena_b && ocjena_b == ocjena_m)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((ocjena_t == ocjena_b && ocjena_b != ocjena_m) || (ocjena_t == ocjena_m && ocjena_b != ocjena_m) || (ocjena_b == ocjena_m && ocjena_t != ocjena_m))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (ocjena_t != ocjena_b && ocjena_b != ocjena_m && ocjena_t != ocjena_m)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
