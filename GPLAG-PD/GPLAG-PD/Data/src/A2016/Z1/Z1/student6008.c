#include <stdio.h>

int main()
{
   float tparc1, tparc2, tpr, tzad, tzavr;
   float mparc1, mparc2, mpr, mzad, mzavr;
   float bparc1, bparc2, bpr, bzad, bzavr;
   int   tocjena = 0, bocjena = 0, mocjena = 0;
   float bukupno = 0, tukupno = 0, mukupno = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &tparc1);
   if (tparc1 < 0 || tparc1 > 20)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &tparc2);
   if (tparc2 < 0 || tparc2 > 20)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("Prisustvo: ");
   scanf("%f", &tpr);
   if (tpr < 0 || tpr > 10)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("Zadace: ");
   scanf("%f", &tzad);
   if (tzad < 0 || tzad > 10)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &tzavr);
   if (tzavr < 0 || tzavr > 40)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &bparc1);
   if (bparc1 < 0 || bparc1 > 20)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &bparc2);
   if (bparc2 < 0 || bparc2 > 20)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("Prisustvo: ");
   scanf("%f", &bpr);
   if (bpr < 0 || bpr > 10)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("Zadace: ");
   scanf("%f", &bzad);
   if (bzad < 0 || bzad > 10)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &bzavr);
   if (bzavr < 0 || bzavr > 40)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &mparc1);
   if (mparc1 < 0 || mparc1 > 20)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &mparc2);
   if (mparc2 < 0 || mparc2 > 20)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("Prisustvo: ");
   scanf("%f", &mpr);
   if (mpr < 0 || mpr > 10)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("Zadace: ");
   scanf("%f", &mzad);
   if (mzad < 0 || mzad > 10)
   {
      printf("Neispravan broj bodova");
      return;
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &mzavr);
   if (mzavr < 0 || mzavr > 40)
   {
      printf("Neispravan broj bodova");
      return;
   }



   tukupno = tparc1 + tparc2 + tpr + tzad + tzavr;

   bukupno = bparc1 + bparc2 + bpr + bzad + bzavr;

   mukupno = mparc1 + mparc2 + mpr + mzad + mzavr;


   if (tukupno < 55 && mukupno < 55 && bukupno < 55)
   {
      printf("Nijedan student nije polozio.");
      return;
   }
   else if ((((tukupno == 0 || tukupno < 55) && (mukupno != 0 && mukupno >= 55) && (bukupno != 0 && bukupno >= 55)) || ((bukupno == 0 || bukupno < 55) && (mukupno != 0 && mukupno >= 55) && (tukupno != 0 && tukupno >= 55)) || ((mukupno == 0 || mukupno < 55) && (tukupno != 0 && tukupno >= 55) && (bukupno != 0 && bukupno >= 55))))
   {
      printf("Dva studenta su polozila.");
      return;
   }
   else if ((((tukupno == 0 || tukupno < 55) && (mukupno == 0 || mukupno < 55) && (bukupno != 0 && bukupno >= 55)) || ((bukupno == 0 || bukupno < 55) && (mukupno == 0 || mukupno < 55) && (tukupno != 0 && tukupno >= 55)) || ((mukupno != 0 && mukupno >= 55) && (tukupno == 0 || tukupno < 55) && (bukupno == 0 || bukupno < 55))))
   {
      printf("Jedan student je polozio.");
      return;
   }
   else
   {
      printf("Sva tri studenta su polozila.\n");
   }

   if (tukupno >= 55 && tukupno < 65)
   {
      tocjena = 6;
   }
   else if (tukupno >= 65 && tukupno < 75)
   {
      tocjena = 7;
   }
   else if (tukupno >= 75 && tukupno < 85)
   {
      tocjena = 8;
   }
   else if (tukupno >= 85 && tukupno < 92)
   {
      tocjena = 9;
   }
   else
   {
      tocjena = 10;
   }

   if (bukupno >= 55 && bukupno < 65)
   {
      bocjena = 6;
   }
   else if (bukupno >= 65 && bukupno < 75)
   {
      bocjena = 7;
   }
   else if (bukupno >= 75 && bukupno < 85)
   {
      bocjena = 8;
   }
   else if (bukupno >= 85 && bukupno < 92)
   {
      bocjena = 9;
   }
   else
   {
      bocjena = 10;
   }

   if (mukupno >= 55 && mukupno < 65)
   {
      mocjena = 6;
   }
   else if (mukupno >= 65 && mukupno < 75)
   {
      mocjena = 7;
   }
   else if (mukupno >= 75 && mukupno < 85)
   {
      mocjena = 8;
   }
   else if (mukupno >= 85 && mukupno < 92)
   {
      mocjena = 9;
   }
   else
   {
      mocjena = 10;
   }

   if (tocjena == mocjena && tocjena == bocjena)
   {
      printf("Sva tri studenta imaju istu ocjenu.");
      return;
   }
   else if (tocjena != mocjena && tocjena != bocjena && bocjena != mocjena)
   {
      printf("Svaki student ima razlicitu ocjenu.");
      return;
   }
   else
   {
      printf("Dva od tri studenta imaju istu ocjenu.");
   }

   return(0);
}
