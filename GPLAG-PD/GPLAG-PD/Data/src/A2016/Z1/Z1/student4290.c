#include <stdio.h>
int ocjene(float a)
{
   if (a < 55)
   {
      return(5);
   }
   else if (a > 54 && a < 65)
   {
      return(6);
   }
   else if (a > 64 && a < 75)
   {
      return(7);
   }
   else if (a > 74 && a < 85)
   {
      return(8);
   }
   else if (a > 84 && a < 95)
   {
      return(9);
   }
   else if (a > 94)
   {
      return(10);
   }
}

int main()
{
   float t1p, t2p, tpri, tzad, tu, b1p, b2p, bpri, bzad, bu, m1p, m2p, mpri, mzad, mu, tzbir, bzbir, mzbir;
   int   bo, mo, to;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &t1p);
   if ((t1p < 0) || (t1p > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &t2p);
   if ((t2p < 0) || (t2p > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &tpri);
   if ((tpri < 0) || (tpri > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &tzad);
   if ((tzad < 0) || (tzad > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &tu);
   if ((tu < 0) || (tu > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   tzbir = t1p + t2p + tpri + tzad + tu;
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &b1p);
   if ((b1p < 0) || (b1p > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &b2p);
   if ((b2p < 0) || (b2p > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &bpri);
   if ((bpri < 0) || (bpri > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &bzad);
   if ((bzad < 0) || (bzad > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &bu);
   if ((bu < 0) || (bu > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   bzbir = b1p + b2p + bpri + bzad + bu;
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &m1p);
   if ((m1p < 0) || (m1p > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &m2p);
   if ((m2p < 0) || (m2p > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &mpri);
   if ((mpri < 0) || (mpri > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &mzad);
   if ((mzad < 0) || (mzad > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &mu);
   if ((mu < 0) || (mu > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   mzbir = m1p + m2p + mpri + mzad + mu;
   mo    = ocjene(mzbir);
   bo    = (ocjene(bzbir));
   to    = ocjene(tzbir);
   if ((mo == 5) && (to == 5) && (bo == 5))
   {
      printf("Nijedan student nije polozio.");
   }

   else if ((mo > 5 && bo == 5 && to == 5) || (mo == 5 && bo > 5 && to == 5) || (mo == 5 && bo == 5 && to > 5))
   {
      printf("Jedan student je polozio.");
   }
   else if ((to > 5 && mo > 5 && bo == 5) || (to > 5 && bo > 5 && mo == 5) || (to == 5 && mo > 5 && to > 5))
   {
      printf("Dva studenta su polozila.");
   }
   else if (to > 5 && mo > 5 && bo > 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if ((to == mo) && to == bo)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if ((to == bo && to != mo) || (to == mo && to != bo) || (bo == mo && bo != to))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (bo != mo != to)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
