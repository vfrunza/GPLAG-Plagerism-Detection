#include <stdio.h>

int main()
{
   double t1p, t2p, tpr, tzd, tzi, b1p, b2p, bpr, bzd, bzi, m1p, m2p, mpr, mzd, mzi, tbod, bbod, mbod;
   int    toc, boc, moc, sp, oc6, oc7, oc8, oc9, oc10;

   sp   = 0;
   oc6  = 0;
   oc7  = 0;
   oc8  = 0;
   oc9  = 0;
   oc10 = 0;

   /* Tarik */
   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &t1p);
   if ((t1p < 0) || (t1p > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &t2p);
   if ((t2p < 0) || (t2p > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &tpr);
   if ((tpr < 0) || (tpr > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &tzd);
   if ((tzd < 0) || (tzd > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &tzi);
   if ((tzi < 0) || (tzi > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   tbod = t1p + t2p + tpr + tzd + tzi;

   if (tbod < 55)
   {
      toc = 5;
   }
   else if (tbod < 65)
   {
      toc = 6;
      sp++;
      oc6++;
   }
   else if (tbod < 75)
   {
      toc = 7;
      sp++;
      oc7++;
   }
   else if (tbod < 85)
   {
      toc = 8;
      sp++;
      oc8++;
   }
   else if (tbod < 92)
   {
      toc = 9;
      sp++;
      oc9++;
   }
   else
   {
      toc = 10;
      sp++;
      oc10++;
   }


   /* Bojan */
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &b1p);
   if ((b1p < 0) || (b1p > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b2p);
   if ((b2p < 0) || (b2p > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &bpr);
   if ((bpr < 0) || (bpr > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &bzd);
   if ((bzd < 0) || (bzd > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &bzi);
   if ((bzi < 0) || (bzi > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   bbod = b1p + b2p + bpr + bzd + bzi;

   if (bbod < 55)
   {
      boc = 5;
   }
   else if (bbod < 65)
   {
      boc = 6;
      sp++;
      oc6++;
   }
   else if (bbod < 75)
   {
      boc = 7;
      sp++;
      oc7++;
   }
   else if (bbod < 85)
   {
      boc = 8;
      sp++;
      oc8++;
   }
   else if (bbod < 92)
   {
      boc = 9;
      sp++;
      oc9++;
   }
   else
   {
      boc = 10;
      sp++;
      oc10++;
   }

   /* Mirza */
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &m1p);
   if ((m1p < 0) || (m1p > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &m2p);
   if ((m2p < 0) || (m2p > 20))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &mpr);
   if ((mpr < 0) || (mpr > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &mzd);
   if ((mzd < 0) || (mzd > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &mzi);
   if ((mzi < 0) || (mzi > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   mbod = m1p + m2p + mpr + mzd + mzi;

   if (mbod < 55)
   {
      moc = 5;
   }
   else if (mbod < 65)
   {
      moc = 6;
      sp++;
      oc6++;
   }
   else if (mbod < 75)
   {
      moc = 7;
      sp++;
      oc7++;
   }
   else if (mbod < 85)
   {
      moc = 8;
      sp++;
      oc8++;
   }
   else if (mbod < 92)
   {
      moc = 9;
      sp++;
      oc9++;
   }
   else
   {
      moc = 10;
      sp++;
      oc10++;
   }

   if (sp > 2)
   {
      printf("Sva tri studenta su polozila.\n");
      if ((oc6 < 2) && (oc7 < 2) && (oc8 < 2) && (oc9 < 2) && (oc10 < 2))
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      else if ((oc6 < 3) && (oc7 < 3) && (oc8 < 3) && (oc9 < 3) && (oc10 < 3))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if ((oc6 < 4) && (oc7 < 4) && (oc8 < 4) && (oc9 < 4) && (oc10 < 4))
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
   }
   else if (sp > 1)
   {
      printf("Dva studenta su polozila.");
   }
   else if (sp > 0)
   {
      printf("Jedan student je polozio.");
   }
   else
   {
      printf("Nijedan student nije polozio.");
   }

   return(0);
}
