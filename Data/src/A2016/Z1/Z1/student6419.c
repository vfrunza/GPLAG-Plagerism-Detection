#include <stdio.h>
#define E    0.00001
int main()
{
   float tp1, tp2, tpr, tz, tzi, bp1, bp2, bpr, bz, bzi, mp1, mp2, mpr, mz, mzi;
   float tu, bu, mu;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &tp1);
   if (tp1 < 0 || tp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &tp2);
   if (tp2 < 0 || tp2 > 20)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Prisustvo: ");
   scanf("%f", &tpr);
   if (tpr < 0 || tpr > 10)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Zadace: ");
   scanf("%f", &tz);
   if (tz < 0 || tz > 10)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &tzi);
   if (tzi < 0 || tzi > 40)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &bp1);
   if (bp1 < 0 || bp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &bp2);
   if (bp2 < 0 || bp2 > 20)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Prisustvo: ");
   scanf("%f", &bpr);
   if (bpr < 0 || bpr > 10)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Zadace: ");
   scanf("%f", &bz);
   if (bz < 0 || bz > 10)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &bzi);
   if (bzi < 0 || bzi > 40)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &mp1);
   if (mp1 < 0 || mp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &mp2);
   if (mp2 < 0 || mp2 > 20)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Prisustvo: ");
   scanf("%f", &mpr);
   if (mpr < 0 || mpr > 10)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Zadace: ");
   scanf("%f", &mz);
   if (mz < 0 || mz > 10)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &mzi);
   if (mzi < 0 || mzi > 40)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   tu = tp1 + tp2 + tpr + tz + tzi + E;
   bu = bp1 + bp2 + bpr + bz + bzi + E;
   mu = mp1 + mp2 + mpr + mz + mzi + E;
   if (tu >= 55 && bu >= 55 && mu >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
      if (tu >= 55 && tu < 65 && mu >= 55 && mu < 65 && bu >= 55 && bu < 65 || tu >= 65 && tu < 75 && bu >= 65 && bu < 75 && mu >= 65 && mu < 75 || tu >= 75 && tu < 85 && bu >= 75 && bu < 85 && mu >= 75 && mu < 85 || tu >= 85 && tu < 92 && bu >= 85 && bu < 92 && mu >= 85 && mu < 92 || tu >= 92 && tu <= 100 && bu >= 92 && bu <= 100 && mu >= 92 && mu <= 100)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (tu >= 55 && tu < 65 && bu >= 55 && bu < 65 || tu >= 65 && tu < 75 && bu >= 65 && bu < 75 || tu >= 75 && tu < 85 && bu >= 75 && bu < 85 || tu >= 85 && tu < 92 && bu >= 85 && bu < 92 || tu >= 92 && tu <= 100 && bu >= 92 && bu <= 100)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   else if (tu >= 55 && bu < 55 && mu < 55 || tu < 55 && bu >= 55 && mu < 55 || tu < 55 && bu < 55 && mu >= 55)
   {
      printf("Jedan student je polozio.");
   }
   else if (tu >= 55 && bu >= 55 && mu < 55 || tu >= 55 && bu < 55 && mu >= 55 || tu < 55 && bu >= 55 && mu >= 55)
   {
      printf("Dva studenta su polozila.");
   }
   else if (tu < 55 && bu < 55 && mu < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   return(0);
}
