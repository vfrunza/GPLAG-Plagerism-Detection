#include <stdio.h>
#include <math.h>
#define EPSILON    0.0001
int main()

{
   double par1, par2, pris, zad, zavrs, ocenat, ocenab, ocenam;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &par1);
   if (par1 > 20 || par1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%lf", &par2);
   if (par2 > 20 || par2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   scanf("%lf", &pris);
   if (pris > 10 || pris < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   scanf("%lf", &zad);
   if (zad > 10 || zad < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   scanf("%lf", &zavrs);
   if (zavrs > 40 || zavrs < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   ocenat = par1 + par2 + pris + zad + zavrs;

   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &par1);
   if (par1 > 20 || par1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%lf", &par2);
   if (par2 > 20 || par2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   scanf("%lf", &pris);
   if (pris > 10 || pris < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   scanf("%lf", &zad);
   if (zad > 10 || zad < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   scanf("%lf", &zavrs);
   if (zavrs > 40 || zavrs < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   ocenab = par1 + par2 + pris + zad + zavrs;

   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &par1);
   if (par1 > 20 || par1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
   }
   scanf("%lf", &par2);
   if (par2 > 20 || par2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Prisustvo: ");
   }
   scanf("%lf", &pris);
   if (pris > 10 || pris < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zadace: ");
   }
   scanf("%lf", &zad);
   if (zad > 10 || zad < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("Zavrsni ispit: ");
   }
   scanf("%lf", &zavrs);
   if (zavrs > 40 || zavrs < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   ocenam = par1 + par2 + pris + zad + zavrs;

   if (ocenat < 55)
   {
      ocenat = 5;
   }
   if (ocenat >= 55 && ocenat < 65)
   {
      ocenat = 6;
   }
   if (ocenat >= 65 && ocenat < 75)
   {
      ocenat = 7;
   }
   if (ocenat >= 75 && ocenat < 85)
   {
      ocenat = 8;
   }
   if (ocenat >= 85 && ocenat < 92)
   {
      ocenat = 9;
   }
   if (ocenat >= 92 && ocenat < 100)
   {
      ocenat = 10;
   }


   if (ocenab < 55)
   {
      ocenab = 5;
   }
   if (ocenab >= 55 && ocenab < 65)
   {
      ocenab = 6;
   }
   if (ocenab >= 65 && ocenab < 75)
   {
      ocenab = 7;
   }
   if (ocenab >= 75 && ocenab < 85)
   {
      ocenab = 8;
   }
   if (ocenab >= 85 && ocenab < 92)
   {
      ocenab = 9;
   }
   if (ocenab >= 92 && ocenab < 100)
   {
      ocenab = 10;
   }

   if (ocenam < 55)
   {
      ocenam = 5;
   }
   if (ocenam >= 55 && ocenam < 65)
   {
      ocenam = 6;
   }
   if (ocenam >= 65 && ocenam < 75)
   {
      ocenam = 7;
   }
   if (ocenam >= 75 && ocenam < 85)
   {
      ocenam = 8;
   }
   if (ocenam >= 85 && ocenam < 92)
   {
      ocenam = 9;
   }
   if (ocenam >= 92 && ocenam < 100)
   {
      ocenam = 10;
   }

   if (ocenat >= 6 && ocenab >= 6 && ocenam >= 6)
   {
      printf("Sva tri studenta su polozila.\n");
      {
         if (fabs(ocenat - ocenam) < EPSILON)
         {
            if (fabs(ocenab - ocenat) < EPSILON)
            {
               if (fabs(ocenam - ocenab) < EPSILON)
               {
                  printf("\nSva tri studenta imaju istu ocjenu.");
               }
            }
         }
      }

      if (ocenat == ocenab)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (ocenat == ocenam)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (ocenab == ocenam)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }

      //printf ("\nDva od tri studenta imaju istu ocjenu.");
      if (ocenat != ocenab && ocenat != ocenam)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }

   if ((ocenat >= 6 && ocenab >= 6 && ocenam < 6) || (ocenat >= 6 && ocenab < 6 && ocenam >= 6) || (ocenat < 6 && ocenab >= 6 && ocenam >= 6))
   {
      printf("Dva studenta su polozila.");
   }

   if ((ocenat >= 6 && ocenab < 6 && ocenam < 6) || (ocenat < 6 && ocenab >= 6 && ocenam < 6) || (ocenat < 6 && ocenab < 6 && ocenam >= 6))
   {
      printf("Jedan student je polozio.");
   }

   if (ocenat < 6 && ocenab < 6 && ocenam < 6)
   {
      printf("Nijedan student nije polozio.");
   }

   return(0);
}
