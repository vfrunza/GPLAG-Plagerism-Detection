#include <stdio.h>

int main()
{
   double pp1, dp1, pris1, z1, zi1, pp2, dp2, pris2, z2, zi2, pp3, dp3, pris3, z3, zi3, bod1, bod2, bod3;
   int    o1, o2, o3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &pp1);
   if (pp1 < 0 || pp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dp1);
   if (dp1 < 0 || dp1 > 20)
   {
      printf("Neispravan broj bodoba");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pris1);
   if (pris1 < 0 || pris1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z1);
   if (z1 < 0 || z1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zi1);
   if (zi1 < 0 || zi1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &pp2);
   if (pp2 < 0 || pp2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dp2);
   if (dp2 < 0 || dp2 > 20)
   {
      printf("Neipravan broj bodva");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pris2);
   if (pris2 < 0 || pris2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z2);
   if (z2 < 0 || z2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zi2);
   if (zi2 < 0 || zi2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &pp3);
   if (pp3 < 0 || pp3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dp3);
   if (dp3 < 0 || dp3 > 20)
   {
      printf("Neispravan broj bodoba");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pris3);
   if (pris3 < 0 || pris3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z3);
   if (z3 < 0 || z3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zi3);
   if (zi3 < 0 || zi3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   bod1 = pp1 + dp1 + pris1 + z1 + zi1;
   bod2 = pp2 + dp2 + pris2 + z2 + zi2;
   bod3 = pp3 + dp3 + pris3 + z3 + zi3;
   bod1 = (int)(bod1);
   bod2 = (int)(bod2);
   bod3 = (int)(bod3);
   if (bod1 >= 55 && bod1 < 65)
   {
      o1 = 6;
   }
   else if (bod1 >= 65 && bod1 < 75)
   {
      o1 = 7;
   }
   else if (bod1 >= 75 && bod1 < 85)
   {
      o1 = 8;
   }
   else if (bod1 >= 85 && bod1 < 92)
   {
      o1 = 9;
   }
   else if (bod1 >= 92 && bod1 <= 100)
   {
      o1 = 10;
   }
   else if (bod1 < 55)
   {
      o1 = 0;
   }
   if (bod2 >= 55 && bod2 < 65)
   {
      o2 = 6;
   }
   else if (bod2 >= 65 && bod2 < 75)
   {
      o2 = 7;
   }
   else if (bod2 >= 75 && bod2 < 85)
   {
      o2 = 8;
   }
   else if (bod2 >= 85 && bod2 < 92)
   {
      o2 = 9;
   }
   else if (bod2 >= 92 && bod2 <= 100)
   {
      o2 = 10;
   }
   else if (bod2 < 55)
   {
      o2 = 0;
   }
   if (bod3 >= 55 && bod3 < 65)
   {
      o3 = 6;
   }
   else if (bod3 >= 65 && bod3 < 75)
   {
      o3 = 7;
   }
   else if (bod3 >= 75 && bod3 < 85)
   {
      o3 = 8;
   }
   else if (bod3 >= 85 && bod3 < 92)
   {
      o3 = 9;
   }
   else if (bod3 >= 92 && bod3 <= 100)
   {
      o3 = 10;
   }
   else if (bod3 < 55)
   {
      o3 = 0;
   }
   if (o1 == 0 && o2 == 0 && o3 == 0)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if ((o1 >= 6 && o2 < 6 && o3 >= 6) || (o1 >= 6 && o2 >= 6 && o3 < 6))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if ((o2 >= 6 && o1 < 6 && o3 >= 6) || (o2 >= 6 && o1 >= 6 && o3 < 6))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if ((o3 >= 6 && o2 >= 6 && o1 < 6) || (o3 >= 6 && o2 < 6 && o1 >= 6))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (o1 >= 6 && o2 < 6 && o3 < 6)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (o2 >= 6 && o1 < 6 && o3 < 6)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (o3 >= 6 && o2 < 6 && o1 < 6)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (o1 >= 6 && o2 >= 6 && o3 >= 6)
   {
      printf("Sva tri studenta su polozila.\n");
      if (o1 == o2 && o1 == o3 && o2 == o3)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (o1 == o2 && o2 != o3)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (o1 == o3 && o3 != o2)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (o2 == o3 && o3 != o1)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (o1 != o2 && o1 != o3 && o3 != o2)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }
   return(0);
}
