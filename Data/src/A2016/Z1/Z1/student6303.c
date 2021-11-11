#include <stdio.h>

int main()
{
   double IparcijalniIspit_ta, IIparcijalniIspit_ta, Prisustvo_ta, BodoviIzZadace_ta, ZavrsniIspit_ta, T_uk;
   double IparcijalniIspit_bo, IIparcijalniIspit_bo, Prisustvo_bo, BodoviIzZadace_bo, ZavrsniIspit_bo, B_uk;
   double IparcijalniIspit_mi, IIparcijalniIspit_mi, Prisustvo_mi, BodoviIzZadace_mi, ZavrsniIspit_mi, M_uk;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IparcijalniIspit_ta);
   if (IparcijalniIspit_ta < 0 || IparcijalniIspit_ta > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIparcijalniIspit_ta);
   if (IIparcijalniIspit_ta < 0 || IIparcijalniIspit_ta > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Prisustvo_ta);
   if (Prisustvo_ta < 0 || Prisustvo_ta > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &BodoviIzZadace_ta);
   if (BodoviIzZadace_ta < 0 || BodoviIzZadace_ta > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZavrsniIspit_ta);
   if (ZavrsniIspit_ta < 0 || ZavrsniIspit_ta > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IparcijalniIspit_bo);
   if (IparcijalniIspit_bo < 0 || IparcijalniIspit_bo > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIparcijalniIspit_bo);
   if (IIparcijalniIspit_bo < 0 || IIparcijalniIspit_bo > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Prisustvo_bo);
   if (Prisustvo_bo < 0 || Prisustvo_bo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &BodoviIzZadace_bo);
   if (BodoviIzZadace_bo < 0 || BodoviIzZadace_bo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZavrsniIspit_bo);
   if (ZavrsniIspit_bo < 0 || ZavrsniIspit_bo > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IparcijalniIspit_mi);
   if (IparcijalniIspit_mi < 0 || IparcijalniIspit_mi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIparcijalniIspit_mi);
   if (IIparcijalniIspit_mi < 0 || IIparcijalniIspit_mi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Prisustvo_mi);
   if (Prisustvo_mi < 0 || Prisustvo_mi > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &BodoviIzZadace_mi);
   if (BodoviIzZadace_mi < 0 || BodoviIzZadace_mi > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZavrsniIspit_mi);
   if (ZavrsniIspit_mi < 0 || ZavrsniIspit_mi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   T_uk = IparcijalniIspit_ta + IIparcijalniIspit_ta + Prisustvo_ta + BodoviIzZadace_ta + ZavrsniIspit_ta;
   B_uk = IparcijalniIspit_bo + IIparcijalniIspit_bo + Prisustvo_bo + BodoviIzZadace_bo + ZavrsniIspit_bo;
   M_uk = IparcijalniIspit_mi + IIparcijalniIspit_mi + Prisustvo_mi + BodoviIzZadace_mi + ZavrsniIspit_mi;

   if (T_uk < 55 && B_uk < 55 && M_uk < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (T_uk >= 55 && B_uk < 55 && M_uk < 55)
   {
      printf("Jedan student je polozio.");
   }
   else if (T_uk < 55 && B_uk >= 55 && M_uk < 55)
   {
      printf("Jedan student je polozio.");
   }
   else if (T_uk < 55 && B_uk < 55 && M_uk >= 55)
   {
      printf("Jedan student je polozio.");
   }
   else if (T_uk >= 55 && B_uk >= 55 && M_uk < 55)
   {
      printf("Dva studenta su polozila.");
   }
   else if (T_uk >= 55 && B_uk < 55 && M_uk >= 55)
   {
      printf("Dva studenta su polozila.");
   }
   else if (T_uk < 55 && B_uk >= 55 && M_uk >= 55)
   {
      printf("Dva studenta su polozila.");
   }
   else if (T_uk >= 55 && B_uk >= 55 && M_uk >= 55)
   {
      printf("Sva tri studenta su polozila.\n");

      if (T_uk >= 55 && T_uk < 65 && B_uk >= 55 && B_uk < 65 && M_uk >= 55 && M_uk < 65)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 65 && T_uk < 75 && B_uk >= 65 && B_uk < 75 && M_uk >= 65 && M_uk < 75)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 75 && T_uk < 85 && B_uk >= 75 && B_uk < 85 && M_uk >= 75 && M_uk < 85)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 85 && T_uk < 92 && B_uk >= 85 && B_uk < 92 && M_uk >= 85 && M_uk < 92)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 92 && T_uk <= 100 && B_uk >= 92 && B_uk <= 100 && M_uk >= 92 && M_uk <= 100)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 55 && T_uk < 65 && B_uk >= 55 && B_uk < 65 && M_uk >= 65 && M_uk <= 100)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 65 && T_uk < 75 && B_uk >= 65 && B_uk < 75 && M_uk >= 55 && M_uk < 65 && M_uk >= 75 && M_uk <= 100)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 75 && T_uk < 85 && B_uk >= 75 && B_uk < 85 && M_uk >= 55 && M_uk < 75 && M_uk >= 85 && M_uk <= 100)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 85 && T_uk < 92 && B_uk >= 85 && B_uk < 92 && M_uk >= 55 && M_uk < 85 && M_uk >= 92 && M_uk <= 100)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 92 && T_uk <= 100 && B_uk >= 92 && B_uk <= 100 && M_uk >= 55 && M_uk < 92)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 55 && T_uk < 65 && B_uk > 65 && B_uk <= 100 && M_uk >= 55 && M_uk < 65)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 65 && T_uk < 75 && B_uk >= 55 && B_uk < 65 && B_uk >= 75 && B_uk <= 100 && M_uk >= 65 && M_uk < 75)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 75 && T_uk < 85 && B_uk >= 55 && B_uk < 75 && B_uk >= 85 && B_uk <= 100 && M_uk >= 75 && M_uk < 85)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 85 && T_uk < 92 && B_uk >= 55 && B_uk < 85 && B_uk >= 92 && B_uk <= 100 && M_uk >= 85 && M_uk < 92)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 92 && T_uk <= 100 && B_uk >= 55 && B_uk < 92 && M_uk >= 92 && M_uk <= 100)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk > 65 && T_uk <= 100 && B_uk >= 55 && B_uk < 65 && M_uk >= 55 && M_uk < 65)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 55 && T_uk < 65 && T_uk >= 75 && T_uk <= 100 && B_uk >= 65 && B_uk < 75 && M_uk >= 65 && M_uk < 75)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 55 && T_uk < 75 && T_uk >= 85 && T_uk <= 100 && B_uk >= 75 && B_uk < 85 && M_uk >= 75 && M_uk < 85)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 55 && T_uk < 85 && T_uk >= 92 && T_uk <= 100 && B_uk >= 85 && B_uk < 92 && M_uk >= 85 && M_uk < 92)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (T_uk >= 55 && T_uk < 92 && B_uk >= 92 && B_uk <= 100 && M_uk >= 92 && M_uk <= 100)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
