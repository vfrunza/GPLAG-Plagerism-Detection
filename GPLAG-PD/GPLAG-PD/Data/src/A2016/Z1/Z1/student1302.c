#include <stdio.h>

int main()
{
   /*printf("Zadaća 1, Zadatak 1");*/
   double tarikprvi, tarikdrugi, tarikzavrsni, tarikzadace, tarikprisustvo;
   double bojanprvi, bojandrugi, bojanzavrsni, bojanzadace, bojanprisustvo;
   double mirzaprvi, mirzadrugi, mirzazavrsni, mirzazadace, mirzaprisustvo;
   double a, b, c;


   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: "); scanf("%lf", &tarikprvi); if (tarikprvi < 0 || tarikprvi > 20)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &tarikdrugi); if (tarikdrugi < 0 || tarikdrugi > 20)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &tarikprisustvo); if (tarikprisustvo < 0 || tarikprisustvo > 10)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zadace: "); scanf("%lf", &tarikzadace); if (tarikzadace < 0 || tarikzadace > 10)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &tarikzavrsni); if (tarikzavrsni < 0 || tarikzavrsni > 40)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: "); scanf("%lf", &bojanprvi); if (bojanprvi < 0 || bojanprvi > 20)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &bojandrugi); if (bojandrugi < 0 || bojandrugi > 20)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &bojanprisustvo); if (bojanprisustvo < 0 || bojanprisustvo > 10)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zadace: "); scanf("%lf", &bojanzadace); if (bojanzadace < 0 || bojanzadace > 10)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &bojanzavrsni); if (bojanzavrsni < 0 || bojanzavrsni > 40)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: "); scanf("%lf", &mirzaprvi); if (mirzaprvi < 0 || mirzaprvi > 20)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &mirzadrugi); if (mirzadrugi < 0 || mirzadrugi > 20)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Prisustvo: "); scanf("%lf", &mirzaprisustvo); if (mirzaprisustvo < 0 || mirzaprisustvo > 10)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zadace: "); scanf("%lf", &mirzazadace); if (mirzazadace < 0 || mirzazadace > 10)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zavrsni ispit: "); scanf("%lf", &mirzazavrsni); if (mirzazavrsni < 0 || mirzazavrsni > 40)
   {
      printf("Neispravan broj bodova\n"); return(0);
   }



   a = tarikprisustvo + tarikdrugi + tarikzadace + tarikzavrsni + tarikprvi;
   b = bojanprisustvo + bojandrugi + bojanzadace + bojanzavrsni + bojanprvi;
   c = mirzaprisustvo + mirzadrugi + mirzazadace + mirzazavrsni + mirzaprvi;

   if (a < 55 && b < 55 && c < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if ((a < 55 && b < 55 && c >= 55) || (a < 55 && c < 55 && b >= 55) || (b < 55 && c < 55 && a >= 55))
   {
      printf("Jedan student je polozio.\n");
   }
   else if ((a < 55 && b >= 55 && c >= 55) || (b < 55 && c >= 55 && a >= 55) || (c < 55 && a >= 55 && b >= 55))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (a >= 55 && b >= 55 && c >= 55)
   {
      printf("Sva tri studenta su polozila.\n");

      if (a >= 55 && a < 65)
      {
         a = 6;
      }
      else if (a >= 65 && a < 75)
      {
         a = 7;
      }
      else if (a >= 75 && a < 85)
      {
         a = 8;
      }
      else if (a >= 85 && a < 92)
      {
         a = 9;
      }
      else
      {
         a = 10;
      }
      if (b >= 55 && b < 65)
      {
         b = 6;
      }
      else if (b >= 65 && b < 75)
      {
         b = 7;
      }
      else if (b >= 75 && b < 85)
      {
         b = 8;
      }
      else if (b >= 85 && b < 92)
      {
         b = 9;
      }
      else
      {
         b = 10;
      }
      if (c >= 55 && c < 65)
      {
         c = 6;
      }
      else if (c >= 65 && c < 75)
      {
         c = 7;
      }
      else if (c >= 75 && c < 85)
      {
         c = 8;
      }
      else if (c >= 85 && c < 92)
      {
         c = 9;
      }
      else
      {
         c = 10;
      }

      if (a == b && b == c)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      if (a != b && b != c)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
      else
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
   }



   return(0);
}
