#include <stdio.h>

int main()
{
   double pi1t, pi2t, pt, zt, zit;
   double pi1b, pi2b, pb, zb, zib;
   double pi1m, pi2m, pm, zm, zim;
   double st, sm, sb;
   int    t, m, b;
   int    tbm = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &pi1t);
   if (pi1t < 0 || pi1t > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &pi2t);
   if (pi2t < 0 || pi2t > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pt);
   if (pt < 0 || pt > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zt);
   if (zt < 0 || zt > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zit);
   if (zit < 0 || zit > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &pi1b);
   if (pi1b < 0 || pi1b > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &pi2b);
   if (pi2b < 0 || pi2b > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pb);
   if (pb < 0 || pb > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zb);
   if (zb < 0 || zb > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zib);
   if (zib < 0 || zib > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &pi1m);
   if (pi1m < 0 || pi1m > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &pi2m);
   if (pi2m < 0 || pi2m > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pm);
   if (pm < 0 || pm > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zm);
   if (zm < 0 || zm > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zim);
   if (zim < 0 || zim > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }


   st = pi1t + pi2t + pt + zt + zit;
   sm = pi1m + pi2m + pm + zm + zim;
   sb = pi1b + pi2b + pb + zb + zib;


   if (st <= 55)
   {
      t = 0;
   }
   if (st >= 55 && st < 65)
   {
      t = 6;
   }
   if (st >= 65 && st < 75)
   {
      t = 7;
   }
   if (st >= 75 && st < 85)
   {
      t = 8;
   }
   if (st >= 85 && st < 92)
   {
      t = 9;
   }
   if (st >= 92 && st <= 100)
   {
      t = 10;
   }

   if (sb < 55)
   {
      b = 0;
   }
   if (sb >= 55 && sb < 65)
   {
      b = 6;
   }
   if (sb >= 65 && sb < 75)
   {
      b = 7;
   }
   if (sb >= 75 && sb < 85)
   {
      b = 8;
   }
   if (sb >= 85 && sb < 92)
   {
      b = 9;
   }
   if (sb >= 92 && sb <= 100)
   {
      b = 10;
   }

   if (sm < 55)
   {
      m = 0;
   }
   if (sm >= 55 && sm < 65)
   {
      m = 6;
   }
   if (sm >= 65 && sm < 75)
   {
      m = 7;
   }
   if (sm >= 75 && sm < 85)
   {
      m = 8;
   }
   if (sm >= 85 && sm < 92)
   {
      m = 9;
   }
   if (sm >= 92 && sm <= 100)
   {
      m = 10;
   }

   if (t == 0 && m == 0 && b == 0)
   {
      printf("Nijedan student nije polozio.\n");
   }
   if ((t != 0 && m == 0 && b == 0) || (t == 0 && m != 0 && b == 0) || (t == 0 && m == 0 && b != 0))
   {
      printf("Jedan student je polozio.\n");
   }

   if ((t != 0 && m != 0 && b == 0) || (t == 0 && m != 0 && b != 0) || (t != 0 && m == 0 && b != 0))
   {
      printf("Dva studenta su polozila.\n");
   }

   if (t != 0 && m != 0 && b != 0)
   {
      printf("Sva tri studenta su polozila.\n"); tbm = 1;
   }

   if (tbm == 1)
   {
      if (t == m && t == b && m == b)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      if ((t == m && t != b && m != b) || (t != m && t != b && m == b) || (t != m && t == b && m != b))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }

      if (t != m && t != b && m != b)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }
   return(0);
}
