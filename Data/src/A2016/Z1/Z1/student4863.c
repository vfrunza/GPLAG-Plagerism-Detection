#include <stdio.h>
#include <math.h>

int main()
{
   double t1, t2, tp, tz, tzi, b1, b2, bp, bz, bzi, m1, m2, mp, mz, mzi;
   double st = 0;
   double sb = 0;
   double sm = 0;
   int    to = 0, bo = 0, mo = 0, brojac = 0, obrojac = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &t1);
   if (t1 < 0 || t1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &t2);
   if (t2 < 0 || t2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &tp);
   if (tp < 0 || tp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &tz);
   if (tz < 0 || tz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &tzi);
   if (tzi < 0 || tzi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &b1);
   if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b2);
   if (b2 < 0 || b2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &bp);
   if (bp < 0 || bp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &bz);
   if (bz < 0 || bz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bzi);
   if (bzi < 0 || bzi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &m1);
   if (m1 < 0 || m1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &m2);
   if (m2 < 0 || m2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &mp);
   if (mp < 0 || mp > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &mz);
   if (mz < 0 || mz > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &mzi);
   if (mzi < 0 || mzi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   else
   {
      st = t1 + t2 + tp + tz + tzi;
      sb = b1 + b2 + bp + bz + bzi;
      sm = m1 + m2 + mp + mz + mzi;


      if (st >= 55 && st < 65)
      {
         to = 6;
      }
      if (st >= 65 && st < 75)
      {
         to = 7;
      }
      if (st >= 75 && st < 85)
      {
         to = 8;
      }
      if (st >= 85 && st < 92)
      {
         to = 9;
      }
      if (st >= 92 && st <= 100)
      {
         to = 10;
      }

      if (sb >= 55 && sb < 65)
      {
         bo = 6;
      }
      if (sb >= 65 && sb < 75)
      {
         bo = 7;
      }
      if (sb >= 75 && sb < 85)
      {
         bo = 8;
      }
      if (sb >= 85 && sb < 92)
      {
         bo = 9;
      }
      if (sb >= 92 && sb <= 100)
      {
         bo = 10;
      }

      if (sm >= 55 && sm < 65)
      {
         mo = 6;
      }
      if (sm >= 65 && sm < 75)
      {
         mo = 7;
      }
      if (sm >= 75 && sm < 85)
      {
         mo = 8;
      }
      if (sm >= 85 && sm < 92)
      {
         mo = 9;
      }
      if (sm >= 92 && sm <= 100)
      {
         mo = 10;
      }

      if (st < 55 && sb < 55 && sm < 55)
      {
         printf("Nijedan student nije polozio.");
      }

      else
      {
         if (st >= 55)
         {
            brojac++;
         }
         if (sb >= 55)
         {
            brojac++;
         }
         if (sm >= 55)
         {
            brojac++;
         }

         if (brojac == 1)
         {
            printf("Jedan student je polozio.");
         }
         else if (brojac == 2)
         {
            printf("Dva studenta su polozila.");
         }
         else if (brojac == 3)
         {
            printf("Sva tri studenta su polozila.\n");
            if (to == bo)
            {
               obrojac++;
            }
            if (to == mo)
            {
               obrojac++;
            }
            if (bo == mo)
            {
               obrojac++;
            }

            if (obrojac == 3)
            {
               printf("Sva tri studenta imaju istu ocjenu.");
            }
            else if (obrojac == 1)
            {
               printf("Dva od tri studenta imaju istu ocjenu.");
            }
            else if (obrojac == 0)
            {
               printf("Svaki student ima razlicitu ocjenu.");
            }
         }
      }
   }

   return(0);
}
