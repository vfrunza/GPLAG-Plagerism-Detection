#include <stdio.h>
#include <stdlib.h>

int main()
{
   double pp, dp, p, z, zi, pp1, dp1, p1, z1, zi1, pp2, dp2, p2, z2, zi2, s1, s2, s3;
   int    zo1, zo2, zo3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &pp);
   if (pp < 0 || pp > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dp);
   if (dp < 0 || dp > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p);
   if (p < 0 || p > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z);
   if (z < 0 || z > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zi);
   if (zi < 0 || zi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana:\n");
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
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p1);
   if (p1 < 0 || p1 > 10)
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
   printf("Unesite bodove za Mirzu:\n");
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
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p2);
   if (p2 < 0 || p2 > 10)
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
   s1 = pp + dp + p + z + zi;
   s2 = pp1 + dp1 + p1 + z1 + zi1;
   s3 = pp2 + dp2 + p2 + z2 + zi2;
   if (s1 < 55 && s2 < 55 && s3 < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   if ((s1 >= 55 && s2 < 55 && s3 < 55) || (s1 < 55 && s2 >= 55 && s3 < 55) || (s1 < 55 && s2 < 55 && s3 >= 55))
   {
      printf("Jedan student je polozio.\n");
   }
   if ((s1 >= 55 && s2 >= 55 && s3 < 55) || (s1 >= 55 && s2 < 55 && s3 >= 55) || (s1 < 55 && s2 >= 55 && s3 >= 55))
   {
      printf("Dva studenta su polozila.\n");
   }
   if (s1 >= 55 && s3 >= 55 && s3 >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   if (s1 > 55 && s2 > 55 && s3 > 55)
   {
      zo1 = (s1 + 5) / 10;
      zo2 = (s2 + 5) / 10;
      zo3 = (s3 + 5) / 10;
      if ((zo1 == zo2 && zo1 == zo3 && zo2 == zo3) || (zo1 <= 5 && zo2 <= 5 && zo3 <= 5))
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      if ((zo1 == zo2 && zo1 != zo3 && zo2 != zo3) || (zo1 == zo3 && zo1 != zo2 && zo2 != zo3) || (zo2 == zo3 && zo2 != zo1 && zo3 != zo1))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (zo1 != zo2 && zo1 != zo3 && zo2 != zo3)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
