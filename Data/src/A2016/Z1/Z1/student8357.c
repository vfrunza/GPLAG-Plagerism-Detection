#include <stdio.h>
#include <math.h>

int main()
{
   float pi1, pi2, pri, zad, zi, ubb, r;

   int oc1, oc2, oc3;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pi1);
   if (pi1 >= 0 && pi1 <= 20)
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &pi2);
      if (pi2 >= 0 && pi2 <= 20)
      {
         printf("Prisustvo: ");
         scanf("%f", &pri);
         if (pri >= 0 && pri <= 10)
         {
            printf("Zadace: ");
            scanf("%f", &zad);
            if (zad >= 0 && zad <= 10)
            {
               printf("Zavrsni ispit: ");
               scanf("%f", &zi);
               if (zi >= 0 && zi <= 40)
               {
                  ubb = pi1 + pi2 + pri + zad + zi;
                  ubb = (int)(ubb * 1000 + 0.5) / 1000;
                  if (ubb < 55)
                  {
                     oc1 = 5;
                  }
                  else if (ubb >= 55 && ubb < 65)
                  {
                     oc1 = 6;
                  }
                  else if (ubb >= 65 && ubb < 75)
                  {
                     oc1 = 7;
                  }
                  else if (ubb >= 75 && ubb < 85)
                  {
                     oc1 = 8;
                  }
                  else if (ubb >= 85 && ubb < 92)
                  {
                     oc1 = 9;
                  }
                  else if (ubb >= 92 && ubb <= 100)
                  {
                     oc1 = 10;
                  }
               }
               else
               {
                  printf("Neispravan broj bodova"); return(0);
               }
            }
            else
            {
               printf("Neispravan broj bodova"); return(0);
            }
         }
         else
         {
            printf("Neispravan broj bodova"); return(0);
         }
      }
      else
      {
         printf("Neispravan broj bodova"); return(0);
      }
   }
   else
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pi1);
   if (pi1 >= 0 && pi1 <= 20)
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &pi2);
      if (pi2 >= 0 && pi2 <= 20)
      {
         printf("Prisustvo: ");
         scanf("%f", &pri);
         if (pri >= 0 && pri <= 10)
         {
            printf("Zadace: ");
            scanf("%f", &zad);
            if (zad >= 0 && zad <= 10)
            {
               printf("Zavrsni ispit: ");
               scanf("%f", &zi);
               if (zi >= 0 && zi <= 40)
               {
                  ubb = pi1 + pi2 + pri + zad + zi;
                  ubb = (int)(ubb * 1000 + 0.5) / 1000;
                  if (ubb < 55)
                  {
                     oc2 = 5;
                  }
                  else if (ubb >= 55 && ubb < 65)
                  {
                     oc2 = 6;
                  }
                  else if (ubb >= 65 && ubb < 75)
                  {
                     oc2 = 7;
                  }
                  else if (ubb >= 75 && ubb < 85)
                  {
                     oc2 = 8;
                  }
                  else if (ubb >= 85 && ubb < 92)
                  {
                     oc2 = 9;
                  }
                  else if (ubb >= 92 && ubb <= 100)
                  {
                     oc2 = 10;
                  }
               }
               else
               {
                  printf("Neispravan broj bodova"); return(0);
               }
            }
            else
            {
               printf("Neispravan broj bodova"); return(0);
            }
         }
         else
         {
            printf("Neispravan broj bodova"); return(0);
         }
      }
      else
      {
         printf("Neispravan broj bodova"); return(0);
      }
   }
   else
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pi1);
   if (pi1 >= 0 && pi1 <= 20)
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &pi2);
      if (pi2 >= 0 && pi2 <= 20)
      {
         printf("Prisustvo: ");
         scanf("%f", &pri);
         if (pri >= 0 && pri <= 10)
         {
            printf("Zadace: ");
            scanf("%f", &zad);
            if (zad >= 0 && zad <= 10)
            {
               printf("Zavrsni ispit: ");
               scanf("%f", &zi);
               if (zi >= 0 && zi <= 40)
               {
                  ubb = pi1 + pi2 + pri + zad + zi;
                  ubb = (int)(ubb * 1000 + 0.5) / 1000;
                  if (ubb < 55)
                  {
                     oc3 = 5;
                  }
                  else if (ubb >= 55 && ubb < 65)
                  {
                     oc3 = 6;
                  }
                  else if (ubb >= 65 && ubb < 75)
                  {
                     oc3 = 7;
                  }
                  else if (ubb >= 75 && ubb < 85)
                  {
                     oc3 = 8;
                  }
                  else if (ubb >= 85 && ubb < 92)
                  {
                     oc3 = 9;
                  }
                  else if (ubb >= 92 && ubb <= 100)
                  {
                     oc3 = 10;
                  }
               }
               else
               {
                  printf("Neispravan broj bodova"); return(0);
               }
            }
            else
            {
               printf("Neispravan broj bodova"); return(0);
            }
         }
         else
         {
            printf("Neispravan broj bodova"); return(0);
         }
      }
      else
      {
         printf("Neispravan broj bodova"); return(0);
      }
   }
   else
   {
      printf("Neispravan broj bodova"); return(0);
   }

   if (oc1 > 5 && oc2 > 5 && oc3 > 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if (oc1 != oc2 && oc2 != oc3 && oc1 != oc3)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      if (oc1 == oc2 && oc2 == oc3)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      if (oc1 == oc2)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (oc2 == oc3)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (oc1 == oc3)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }
   if (oc1 > 5 && oc2 > 5 && oc3 < 6)
   {
      printf("Dva studenta su polozila.");
   }
   if (oc1 > 5 && oc2 > 6 && oc3 < 5)
   {
      printf("Dva studenta su polozila.");
   }
   if (oc1 > 6 && oc2 > 5 && oc3 < 5)
   {
      printf("Dva studenta su polozila.");
   }
   if (oc1 < 6 && oc2 < 6 && oc3 > 5)
   {
      printf("Jedan student je polozio.");
   }
   if (oc1 < 6 && oc2 > 5 && oc3 < 6)
   {
      printf("Jedan student je polozio.");
   }
   if (oc1 > 5 && oc2 < 6 && oc3 < 6)
   {
      printf("Jedan student je polozio.");
   }
   if (oc1 < 6 && oc2 < 6 && oc3 < 6)
   {
      printf("Nijedan student nije polozio.");
   }


   return(0);
}
