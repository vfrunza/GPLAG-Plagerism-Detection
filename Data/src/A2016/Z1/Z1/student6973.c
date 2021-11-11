#include <stdio.h>

int main()
{
   float t1 = 0, t2 = 0, tp = 0, tz = 0, tu = 0, tZ = 0, b1 = 0, b2 = 0, bz = 0, bp = 0, bu = 0, bZ = 0, m1 = 0, m2 = 0, mp = 0, mz = 0, mu = 0, mZ = 0;
   int   to = 0, bo = 0, mo = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &t1);
   if (t1 < 0 || t1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &t2);
   if (t2 > 20 || t2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &tp);
   if (tp > 10 || tp < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &tz);
   if (tz > 10 || tz < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &tZ);
   if (tZ > 40 || tZ < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana:\n");;
   printf("I parcijalni ispit: ");
   scanf("%f", &b1);
   if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &b2);
   if (b2 > 20 || b2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &bp);
   if (bp > 10 || bp < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &bz);
   if (bz > 10 || bz < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &bZ);
   if (bZ > 40 || bZ < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu:\n");;
   printf("I parcijalni ispit: ");
   scanf("%f", &m1);
   if (m1 < 0 || m1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &m2);
   if (m2 > 20 || m2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &mp);
   if (mp > 10 || mp < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &mz);
   if (mz > 10 || mz < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &mZ);
   if (mZ > 40 || mZ < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   tu = t1 + t2 + tp + tz + tZ;
   tu = ((tu * 100) + 0.5) / 100;
   bu = b1 + b2 + bp + bz + bZ;
   bu = ((bu * 100) + 0.5) / 100;
   mu = m1 + m2 + mp + mz + mZ;
   mu = ((mu * 100) + 0.5) / 100;
   if (tu < 55)
   {
      to = 5;
   }
   else if (tu >= 55 && tu < 65)
   {
      to = 6;
   }
   else if (tu >= 65 && tu < 75)
   {
      to = 7;
   }
   else if (tu >= 75 && tu < 85)
   {
      to = 8;
   }
   else if (tu >= 85 && tu < 92)
   {
      to = 9;
   }
   else
   {
      to = 10;
   }
   //printf("%f , %d\n", tu, to);
   if (bu < 55)
   {
      bo = 5;
   }
   else if (bu >= 55 && bu < 65)
   {
      bo = 6;
   }
   else if (bu >= 65 && bu < 75)
   {
      bo = 7;
   }
   else if (bu >= 75 && bu < 85)
   {
      bo = 8;
   }
   else if (bu >= 85 && bu < 92)
   {
      bo = 9;
   }
   else
   {
      bo = 10;
   }
   //printf("%f , %d\n", bu, bo);
   if (mu < 55)
   {
      mo = 5;
   }
   else if (mu >= 55 && mu < 65)
   {
      mo = 6;
   }
   else if (mu >= 65 && mu < 75)
   {
      mo = 7;
   }
   else if (mu >= 75 && mu < 85)
   {
      mo = 8;
   }
   else if (mu >= 85 && mu < 92)
   {
      mo = 9;
   }
   else
   {
      mo = 10;
   }
   //printf("%f , %d\n", mu, mo);
   if (to == 5 && bo == 5 && mo == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((to > 5 && bo == 5 && mo == 5) || (bo > 5 && to == 5 && mo == 5) || (mo > 5 && bo == 5 && to == 5))
   {
      printf("Jedan student je polozio.");
   }
   else if ((to > 5 && bo > 5 && mo == 5) || (to > 5 && mo > 5 && bo == 5) || (mo > 5 && bo > 5 && to == 5))
   {
      printf("Dva studenta su polozila.");
   }
   else if (to > 5 && bo > 5 && mo > 5)
   {
      printf("Sva tri studenta su polozila.\n");
      //if(to > 5) printf("aaa");
      if (to == bo && bo == mo)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((to == bo && mo != to) || (to == mo && bo != to) || (mo == bo && to != mo))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (to != bo && bo != mo && to != mo)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
