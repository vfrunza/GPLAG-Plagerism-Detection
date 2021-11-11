#include <stdio.h>

const int eps = 1e-10;

int ocjena(float a, float b, float c, float d, float e)
{
   int bod = (int)(a * 1000000) + (int)(b * 1000000) + (int)(c * 1000000) + (int)(d * 1000000) + (int)(e * 1000000);

   if (bod < 55000000)
   {
      return(0);
   }
   if (bod < 65000000)
   {
      return(6);
   }
   if (bod < 75000000)
   {
      return(7);
   }
   if (bod < 85000000)
   {
      return(8);
   }
   if (bod < 92000000)
   {
      return(9);
   }
   return(10);
}

int main()
{
   float par1, par2, zad, pris, usm;
   float tpar1, tpar2, tzad, tpris, tusm;
   float bpar1, bpar2, bzad, bpris, busm;
   float mpar1, mpar2, mzad, mpris, musm;
   int   m, b, t, a = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &par1);
   if (par1 < 0 || par1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &par2);
   if (par2 < 0 || par2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pris);
   if (pris < 0 || pris > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zad);
   if (zad < 0 || zad > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &usm);
   if (usm < 0 || usm > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   tpar1 = par1;
   tpar2 = par2;
   tzad  = zad;
   tpris = pris;
   tusm  = usm;
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &par1);
   if (par1 < 0 || par1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &par2);
   if (par2 < 0 || par2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pris);
   if (pris < 0 || pris > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zad);
   if (zad < 0 || zad > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &usm);
   if (usm < 0 || usm > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   bpar1 = par1;
   bpar2 = par2;
   bzad  = zad;
   bpris = pris;
   busm  = usm;
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &par1);
   if (par1 < 0 || par1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &par2);
   if (par2 < 0 || par2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pris);
   if (pris < 0 || pris > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zad);
   if (zad < 0 || zad > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &usm);
   if (usm < 0 || usm > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   mpar1 = par1;
   mpar2 = par2;
   mzad  = zad;
   mpris = pris;
   musm  = usm;
   b     = ocjena(bpar1, bpar2, bzad, bpris, busm);
   t     = ocjena(tpar1, tpar2, tzad, tpris, tusm);
   m     = ocjena(mpar1, mpar2, mzad, mpris, musm);
   if (m > 5)
   {
      a++;
   }
   if (b > 5)
   {
      a++;
   }
   if (t > 5)
   {
      a++;
   }
   if (a == 0)
   {
      printf("Nijedan student nije polozio.");
   }
   else
   if (a == 1)
   {
      printf("Jedan student je polozio.");
   }
   else
   if (a == 2)
   {
      printf("Dva studenta su polozila.");
   }
   else
   {
      printf("Sva tri studenta su polozila.\n");
      if (b == m && m == t)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else
      if (b == m || m == t || t == b)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
