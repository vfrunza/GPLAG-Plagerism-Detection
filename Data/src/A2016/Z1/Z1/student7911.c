#include <stdio.h>
int main()
{
   double t, b, m, t1, b1, m1, t2, b2, m2, tp, bp, mp, tzd, bzd, mzd, tzv, bzv, mzv;//t-Tarik,B-Bojan,m-Mirza
   int    ot, ob, om;

   printf("Unesite bodove za Tarika: \n");
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
   scanf("%lf", &tzd);
   if (tzd < 0 || tzd > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &tzv);
   if (tzv < 0 || tzv > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   t = t1 + t2 + tp + tzd + tzv;
   printf("Unesite bodove za Bojana: \n");
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
   scanf("%lf", &bzd);
   if (bzd < 0 || bzd > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bzv);
   if (bzv < 0 || bzv > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   b = b1 + b2 + bp + bzd + bzv;
   printf("Unesite bodove za Mirzu: \n");
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
   scanf("%lf", &mzd);
   if (mzd < 0 || mzd > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &mzv);
   if (mzv < 0 || mzv > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   m = m1 + m2 + mp + mzd + mzv;
/*Odredjivanje ocjene*/
   if (t < 55)
   {
      ot = 5;
   }
   else if (t >= 55 && t < 65)
   {
      ot = 6;
   }
   else if (t >= 65 && t < 75)
   {
      ot = 7;
   }
   else if (t >= 75 && t < 85)
   {
      ot = 8;
   }
   else if (t >= 85 && t < 92)
   {
      ot = 9;
   }
   else if (t >= 92 && t < 100)
   {
      ot = 10;
   }
   if (b < 55)
   {
      ob = 5;
   }
   else if (b >= 55 && b < 65)
   {
      ob = 6;
   }
   else if (b >= 65 && b < 75)
   {
      ob = 7;
   }
   else if (b >= 75 && b < 85)
   {
      ob = 8;
   }
   else if (b >= 85 && b < 92)
   {
      ob = 9;
   }
   else if (b >= 92 && b < 100)
   {
      ob = 10;
   }
   if (m < 55)
   {
      om = 5;
   }
   else if (m >= 55 && m < 65)
   {
      om = 6;
   }
   else if (m >= 65 && m < 75)
   {
      om = 7;
   }
   else if (m >= 75 && m < 85)
   {
      om = 8;
   }
   else if (m >= 85 && m < 92)
   {
      om = 9;
   }
   else if (m >= 92 && m < 100)
   {
      om = 10;
   }
   if (ot == 5 && om == 5 && ob == 5)
   {
      printf("Nijedan student nije polozio.");
      return(0);
   }
   else if (ot >= 6 && ob < 6 && om < 6)
   {
      printf("Jedan student je polozio.");
      return(0);
   }
   else if (ot < 6 && ob >= 6 && om < 6)
   {
      printf("Jedan student je polozio.");
      return(0);
   }
   else if (ot < 6 && ob < 6 && om >= 6)
   {
      printf("Jedan student je polozio.");
      return(0);
   }
   else if (ot >= 6 && ob >= 6 && om < 6)
   {
      printf("Dva studenta su polozila.");
      return(0);
   }
   else if (ot < 6 && ob >= 6 && om >= 6)
   {
      printf("Dva studenta su polozila.");
      return(0);
   }
   else if (ot >= 6 && ob < 6 && om >= 6)
   {
      printf("Dva studenta su polozila.");
      return(0);
   }
   else if (ot >= 6 && ob >= 6 && om >= 6)
   {
      printf("Sva tri studenta su polozila.\n");
      if (ot == ob && ob == om)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (ot != ob && ob != om)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      else if (ot == ob && ob != om)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (ot != ob && ob == om)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (ot == om && om != ob)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      return(0);
   }
   return(0);
}
