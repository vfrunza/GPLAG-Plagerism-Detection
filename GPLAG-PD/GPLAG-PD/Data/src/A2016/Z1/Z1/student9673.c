#include <stdio.h>
#include <math.h>

int main()
{
   double tp1, tp2, tp, tzi, tza, tu, mp1, mp2, mp, mzi, mza, mu, bp1, bp2, bp, bzi, bza, bu;
   int    tocj, mocj, bocj;

/* TARIK BODOVI */
   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &tp1);
   if (tp1 < 0 || tp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &tp2);
      if (tp2 < 0 || tp2 > 20)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &tp);
         if (tp < 0 || tp > 10)
         {
            printf("Neispravan broj bodova");
            return(0);
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &tza);
            if (tza < 0 || tza > 10)
            {
               printf("Neispravan broj bodova");
               return(0);
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &tzi);
               if (tzi < 0 || tzi > 40)
               {
                  printf("Neispravan broj bodova");
                  return(0);
               }
               else
               {
                  tu = tp1 + tp2 + tp + tzi + tza;
                  if (tu < 55)
                  {
                     tocj = 5;
                  }
                  else if (tu >= 55 && tu < 65)
                  {
                     tocj = 6;
                  }
                  else if (tu >= 65 && tu < 75)
                  {
                     tocj = 7;
                  }
                  else if (tu >= 75 && tu < 85)
                  {
                     tocj = 8;
                  }
                  else if (tu >= 85 && tu < 92)
                  {
                     tocj = 9;
                  }
                  else if (tu >= 92 && tu <= 100)
                  {
                     tocj = 10;
                  }
               }
            }
         }
      }
   }

/*  BODOVI BOJAN */
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &bp1);
   if (bp1 < 0 || bp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &bp2);
      if (bp2 < 0 || bp2 > 20)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &bp);
         if (bp < 0 || bp > 10)
         {
            printf("Neispravan broj bodova");
            return(0);
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &bza);
            if (bza < 0 || bza > 10)
            {
               printf("Neispravan broj bodova");
               return(0);
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &bzi);
               if (bzi < 0 || bzi > 40)
               {
                  printf("Neispravan broj bodova");
                  return(0);
               }
               else
               {
                  bu = bp1 + bp2 + bp + bzi + bza;
                  if (bu < 55)
                  {
                     bocj = 5;
                  }
                  else if (bu >= 55 && bu < 65)
                  {
                     bocj = 6;
                  }
                  else if (bu >= 65 && bu < 75)
                  {
                     bocj = 7;
                  }
                  else if (bu >= 75 && bu < 85)
                  {
                     bocj = 8;
                  }
                  else if (bu >= 85 && bu < 92)
                  {
                     bocj = 9;
                  }
                  else if (bu >= 92 && bu <= 100)
                  {
                     bocj = 10;
                  }
               }
            }
         }
      }
   }
/*  BODOVI MIRZA */
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &mp1);
   if (mp1 < 0 || mp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   else
   {
      printf("II parcijalni ispit: ");
      scanf("%lf", &mp2);
      if (mp2 < 0 || mp2 > 20)
      {
         printf("Neispravan broj bodova");
         return(0);
      }
      else
      {
         printf("Prisustvo: ");
         scanf("%lf", &mp);
         if (mp < 0 || mp > 10)
         {
            printf("Neispravan broj bodova");
            return(0);
         }
         else
         {
            printf("Zadace: ");
            scanf("%lf", &mza);
            if (mza < 0 || mza > 10)
            {
               printf("Neispravan broj bodova");
               return(0);
            }
            else
            {
               printf("Zavrsni ispit: ");
               scanf("%lf", &mzi);
               if (mzi < 0 || mzi > 40)
               {
                  printf("Neispravan broj bodova");
                  return(0);
               }
               else
               {
                  mu = mp1 + mp2 + mp + mzi + mza;
                  if (mu < 55)
                  {
                     mocj = 5;
                  }
                  else if (mu >= 55 && mu < 65)
                  {
                     mocj = 6;
                  }
                  else if (mu >= 65 && mu < 75)
                  {
                     mocj = 7;
                  }
                  else if (mu >= 75 && mu < 85)
                  {
                     mocj = 8;
                  }
                  else if (mu >= 85 && mu < 92)
                  {
                     mocj = 9;
                  }
                  else if (mu >= 92 && mu <= 100)
                  {
                     mocj = 10;
                  }
               }
            }
         }
      }
   }
/* OCJENE */
   if (bocj > 5 && mocj > 5 && tocj > 5)
   {
      printf("Sva tri studenta su polozila.");
/* DA LI SU ISTE OCJENE */
      if (bocj == mocj && mocj == tocj)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((bocj == mocj && bocj != tocj) || (bocj == tocj && mocj != bocj) || (mocj == tocj && mocj != bocj))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (bocj != mocj && bocj != tocj)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   else if ((tocj > 5 && bocj > 5 && mocj <= 5) || (tocj > 5 && mocj > 5 && bocj <= 5) || (tocj <= 5 && mocj > 5 && bocj > 5))
   {
      printf("Dva studenta su polozila.");
   }
   else if ((tocj > 5 && (bocj <= 5 && mocj <= 5)) || (bocj > 5 && (tocj <= 5 && mocj <= 5)) || (mocj > 5 && (bocj <= 5 && tocj <= 5)))
   {
      printf("Jedan student je polozio.");
   }
   else if (tocj <= 5 && bocj <= 5 && mocj <= 5)
   {
      printf("Nijedan student nije polozio.");
   }
}
