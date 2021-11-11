#include <stdio.h>
#include <math.h>
#define E    0.00001
int main()
{
   float I1, II1, prisustvo1, zad1, zi1, I2, II2, prisustvo2, zad2, zi2, I3, II3, prisustvo3, zad3, zi3, bod1, bod2, bod3, o1, o2, o3;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &I1);
   if (I1 > 20 || I1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &II1);
   if (II1 > 20 || II1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo1);
   if (prisustvo1 > 10 || prisustvo1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zad1);
   if (zad1 > 10 || zad1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zi1);
   if (zi1 > 40 || zi1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &I2);
   if (I2 > 20 || I2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &II2);
   if (II2 > 20 || II2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo2);
   if (prisustvo2 > 10 || prisustvo2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zad2);
   if (zad2 > 10 || zad2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zi2);
   if (zi2 > 40 || zi2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%f", &I3);
   if (I3 > 20 || I3 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &II3);
   if (II3 > 20 || II3 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo3);
   if (prisustvo3 > 10 || prisustvo3 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zad3);
   if (zad3 > 10 || zad3 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zi3);
   if (zi3 > 40 || zi3 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   bod1 = I1 + II1 + prisustvo1 + zad1 + zi1;
   bod2 = I2 + II2 + prisustvo2 + zad2 + zi2;
   bod3 = I3 + II3 + prisustvo3 + zad3 + zi3;
   if (bod1 < 54.99)
   {
      o1 = 0;
   }
   if (bod1 >= 54.99 && bod1 < 65)
   {
      o1 = 6;
   }
   if (bod1 >= 65 && bod1 < 75)
   {
      o1 = 7;
   }
   if (bod1 >= 75 && bod1 < 85)
   {
      o1 = 8;
   }
   if (bod1 >= 85 && bod1 < 92)
   {
      o1 = 9;
   }
   if (bod1 >= 92 && bod1 < 100)
   {
      o1 = 10;
   }
   if (bod2 < 55)
   {
      o2 = 0;
   }
   if (bod2 >= 55 && bod2 < 65)
   {
      o2 = 6;
   }
   if (bod2 >= 65 && bod2 < 75)
   {
      o2 = 7;
   }
   if (bod2 >= 75 && bod2 < 85)
   {
      o2 = 8;
   }
   if (bod2 >= 85 && bod2 < 92)
   {
      o2 = 9;
   }
   if (bod2 >= 92 && bod2 < 100)
   {
      o2 = 10;
   }
   if (bod3 < 55)
   {
      o3 = 0;
   }
   if (bod3 >= 55 && bod3 < 65)
   {
      o3 = 6;
   }
   if (bod3 >= 65 && bod3 < 75)
   {
      o3 = 7;
   }
   if (bod3 >= 75 && bod3 < 85)
   {
      o3 = 8;
   }
   if (bod3 >= 85 && bod3 < 92)
   {
      o3 = 9;
   }
   if (bod3 >= 92 && bod3 < 100)
   {
      o3 = 10;
   }
   if ((fabs(o1 - 0) < E) && (fabs(o2 - 0) < E) && (fabs(o3 - 0) < E))
   {
      printf("Nijedan student nije polozio.");
   }
   if (
      (o1 > 0 && (fabs(o2 - 0) < E) && (fabs(o3 - 0) < E)) || ((fabs(o1 - 0) < E) && o2 > 0 && (fabs(o3 - 0) < E)) || ((fabs(o1 - 0) < E) && (fabs(o2 - 0) < E) && o3 > 0))
   {
      printf("Jedan student je polozio.");
   }
   if ((o1 > 0 && o2 > 0 && (fabs(o3 - 0) < E)) || ((fabs(o1 - 0) < E) && o2 > 0 && o3 > 0) || (o1 > 0 && (fabs(o2 - 0) < E) && o3 > 0))
   {
      printf("Dva studenta su polozila.");
   }
   if (o1 > 0 && o2 > 0 && o3 > 0)
   {
      printf("Sva tri studenta su polozila.");
      if ((fabs(o1 - o2) < E) && (fabs(o1 - o3) < E) && (fabs(o2 - o3) < E))
      {
         printf("\nSva tri studenta imaju istu ocjenu. ");
      }
      if (((fabs(o1 - o2) > E) && (fabs(o1 - o3) > E) && (fabs(o2 - o3) < E)) || ((fabs(o1 - o2) < E) && (fabs(o1 - o3) > E) && (fabs(o2 - o3) > E)) || ((fabs(o1 - o2) > E) && (fabs(o1 - o3) < E) && (fabs(o2 - o3) > E)))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      if ((fabs(o1 - o2) > E) && (fabs(o1 - o3) > E) && (fabs(o2 - o3) > E))
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
