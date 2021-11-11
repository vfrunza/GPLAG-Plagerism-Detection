#include <stdio.h>

int main()
{
   double pp1, dp1, z1, p1, zi1, pp2, dp2, z2, p2, zi2, pp3, dp3, z3, p3, zi3, s1, s2, s3;
   double o1, o2, o3, b;

   printf("Unesite bodove za Tarika: \n");
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
      printf("Neispravan broj bodova");
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
   printf("Unesite bodove za Bojana: \n");
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
      printf("Neispravan broj bodova");
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

   printf("Unesite bodove za Mirzu: \n");
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
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p3);
   if (p3 < 0 || p3 > 10)
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

   s1 = pp1 + dp1 + z1 + p1 + zi1;
   s2 = pp2 + dp2 + z2 + p2 + zi2;
   s3 = pp3 + dp3 + z3 + p3 + zi3;

   b = 0;

   if (s1 < 55)
   {
      b = b + 1;
   }
   if (s2 < 55)
   {
      b = b + 1;
   }
   if (s3 < 55)
   {
      b = b + 1;
   }

   if (b == 0)
   {
      printf("Sva tri studenta su polozila.");
   }
   if (b == 1)
   {
      printf("Dva studenta su polozila.");
   }

   if (b == 2)
   {
      printf("Jedan student je polozio.");
   }

   if (b == 3)
   {
      printf("Nijedan student nije polozio.");
   }


   if (b == 0)
   {
      if (s1 > 55 && s1 < 65)
      {
         o1 = 6;
      }
      else if (s1 >= 65 && s1 < 75)
      {
         o1 = 7;
      }
      else if (s1 >= 75 && s1 < 85)
      {
         o1 = 8;
      }
      else if (s1 >= 85 && s1 < 92)
      {
         o1 = 9;
      }
      else if (s1 >= 92 && s1 <= 100)
      {
         o1 = 10;
      }
      if (s2 > 55 && s2 < 65)
      {
         o2 = 6;
      }
      else if (s2 >= 65 && s2 < 75)
      {
         o2 = 7;
      }
      else if (s2 >= 75 && s2 < 85)
      {
         o2 = 8;
      }
      else if (s2 >= 85 && s2 < 92)
      {
         o2 = 9;
      }
      else if (s2 >= 92 && s2 <= 100)
      {
         o2 = 10;
      }
      if (s3 > 55 && s3 < 65)
      {
         o3 = 6;
      }
      else if (s3 >= 65 && s3 < 75)
      {
         o3 = 7;
      }
      else if (s3 >= 75 && s3 < 85)
      {
         o3 = 8;
      }
      else if (s3 >= 85 && s3 < 92)
      {
         o3 = 9;
      }
      else if (s3 >= 92 && s3 <= 100)
      {
         o3 = 10;
      }

      if (o1 == o2 && o2 == o3)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (o1 != o2 && o2 == o3)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (o1 == o2 && o2 != o3)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (o1 == o3 && o3 != o2)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (o1 != o2 && o2 != o3 && o3 != o1)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
