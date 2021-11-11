#include <stdio.h>
#include <math.h>

int main()
{
   float par1, par2, pris, zad, zav, uk;
   int   to, bo, mo;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &par1);
   if (par1 >= 0 && par1 <= 20)
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &par2);
      if (par2 >= 0 && par2 <= 20)
      {
         printf("Prisustvo: ");
         scanf("%f", &pris);
         if (pris >= 0 && pris <= 10)
         {
            printf("Zadace: ");
            scanf("%f", &zad);
            if (zad >= 0 && zad <= 10)
            {
               printf("Zavrsni ispit: ");
               scanf("%f", &zav);
               if (zav >= 0 && zav <= 40)
               {
                  uk = par1 + par2 + pris + zad + zav;
                  uk = (int)(uk * 1000 + 0.5) / 1000;

                  if (uk < 55)
                  {
                     to = 5;
                  }
                  else if (uk >= 55 && uk < 65)
                  {
                     to = 6;
                  }
                  else if (uk >= 65 && uk < 75)
                  {
                     to = 7;
                  }
                  else if (uk >= 75 && uk < 85)
                  {
                     to = 8;
                  }
                  else if (uk >= 85 && uk < 92)
                  {
                     to = 9;
                  }
                  else if (uk >= 92 && uk <= 100)
                  {
                     to = 10;
                  }
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


   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &par1);
   if (par1 >= 0 && par1 <= 20)
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &par2);
      if (par2 >= 0 && par2 <= 20)
      {
         printf("Prisustvo: ");
         scanf("%f", &pris);
         if (pris >= 0 && pris <= 10)
         {
            printf("Zadace: ");
            scanf("%f", &zad);
            if (zad >= 0 && zad <= 10)
            {
               printf("Zavrsni ispit: ");
               scanf("%f", &zav);
               if (zav >= 0 && zav <= 40)
               {
                  uk = par1 + par2 + pris + zad + zav;
                  uk = (int)(uk * 1000 + 0.5) / 1000;

                  if (uk < 55)
                  {
                     bo = 5;
                  }
                  else if (uk >= 55 && uk < 65)
                  {
                     bo = 6;
                  }
                  else if (uk >= 65 && uk < 75)
                  {
                     bo = 7;
                  }
                  else if (uk >= 75 && uk < 85)
                  {
                     bo = 8;
                  }
                  else if (uk >= 85 && uk < 92)
                  {
                     bo = 9;
                  }
                  else if (uk >= 92 && uk <= 100)
                  {
                     bo = 10;
                  }
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


   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &par1);
   if (par1 >= 0 && par1 <= 20)
   {
      printf("II parcijalni ispit: ");
      scanf("%f", &par2);
      if (par2 >= 0 && par2 <= 20)
      {
         printf("Prisustvo: ");
         scanf("%f", &pris);
         if (pris >= 0 && pris <= 10)
         {
            printf("Zadace: ");
            scanf("%f", &zad);
            if (zad >= 0 && zad <= 10)
            {
               printf("Zavrsni ispit: ");
               scanf("%f", &zav);
               if (zav >= 0 && zav <= 40)
               {
                  uk = par1 + par2 + pris + zad + zav;
                  uk = (int)(uk * 1000 + 0.5) / 1000;

                  if (uk < 55)
                  {
                     mo = 5;
                  }
                  else if (uk >= 55 && uk < 65)
                  {
                     mo = 6;
                  }
                  else if (uk >= 65 && uk < 75)
                  {
                     mo = 7;
                  }
                  else if (uk >= 75 && uk < 85)
                  {
                     mo = 8;
                  }
                  else if (uk >= 85 && uk < 92)
                  {
                     mo = 9;
                  }
                  else if (uk >= 92 && uk <= 100)
                  {
                     mo = 10;
                  }
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


   if (mo > 5 && bo > 5 && to > 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if (mo != bo && bo != to && to != mo)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      if (mo == bo && bo == to)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      if (mo == bo)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (bo == to)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (mo == to)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }
   if (mo > 5 && bo > 5 && to < 6)
   {
      printf("Dva studenta su polozila.");
   }
   if (mo > 5 && to > 5 && bo < 6)
   {
      printf("Dva studenta su polozila.");
   }
   if (to > 5 && bo > 5 && mo < 6)
   {
      printf("Dva studenta su polozila.");
   }
   if (to > 5 && bo < 6 && mo < 6)
   {
      printf("Jedan student je polozio.");
   }
   if (bo > 5 && to < 6 && mo < 6)
   {
      printf("Jedan student je polozio.");
   }
   if (mo > 5 && to < 6 && bo < 6)
   {
      printf("Jedan student je polozio.");
   }
   if (mo < 6 && to < 6 && bo < 6)
   {
      printf("Nijedan student nije polozio.");
   }
   return(0);
}
