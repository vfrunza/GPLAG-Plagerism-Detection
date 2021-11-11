#include <stdio.h>
#include <math.h>
#define EP    0.00001

int main()
{
   float pp, dp, p, z, zi, pp1, dp1, p1, z1, zi1, pp2, dp2, p2, z2, zi2, s = 0, s1 = 0, s2 = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pp);
   if (pp < 0 || pp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s += pp;
   printf("II parcijalni ispit: ");
   scanf("%f", &dp);
   if (dp < 0 || dp > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s += dp;
   printf("Prisustvo: ");
   scanf("%f", &p);
   if (p < 0 || p > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s += p;
   printf("Zadace: ");
   scanf("%f", &z);
   if (z < 0 || z > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s += z;
   printf("Zavrsni ispit: ");
   scanf("%f", &zi);
   if (zi < 0 || zi > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s += zi;
   if (s + EP < 55)
   {
      s = 5;
   }
   else if (s >= 55 && s < 65)
   {
      s = 6;
   }
   else if (s >= 65 && s < 75)
   {
      s = 7;
   }
   else if (s >= 75 && s < 85)
   {
      s = 8;
   }
   else if (s >= 85 && s < 92)
   {
      s = 9;
   }
   else if (s >= 92 && s <= 100)
   {
      s = 10;
   }
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pp1);
   if (pp1 < 0 || pp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s1 += pp1;
   printf("II parcijalni ispit: ");
   scanf("%f", &dp1);
   if (dp1 < 0 || dp1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s1 += dp1;
   printf("Prisustvo: ");
   scanf("%f", &p1);
   if (p1 < 0 || p1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s1 += p1;
   printf("Zadace: ");
   scanf("%f", &z1);
   if (z1 < 0 || z1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s1 += z1;
   printf("Zavrsni ispit: ");
   scanf("%f", &zi1);
   if (zi1 < 0 || zi1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s1 += zi1;
   if (s1 + EP < 55)
   {
      s1 = 5;
   }
   else if (s1 >= 55 && s1 < 65)
   {
      s1 = 6;
   }
   else if (s1 >= 65 && s1 < 75)
   {
      s1 = 7;
   }
   else if (s1 >= 75 && s1 < 85)
   {
      s1 = 8;
   }
   else if (s1 >= 85 && s1 < 92)
   {
      s1 = 9;
   }
   else if (s1 >= 92 && s1 <= 100)
   {
      s1 = 10;
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pp2);
   if (pp2 < 0 || pp2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s2 += pp2;
   printf("II parcijalni ispit: ");
   scanf("%f", &dp2);
   if (dp2 < 0 || dp2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s2 += dp2;
   printf("Prisustvo: ");
   scanf("%f", &p2);
   if (p2 < 0 || p2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s2 += p2;
   printf("Zadace: ");
   scanf("%f", &z2);
   if (z2 < 0 || z2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s2 += z2;
   printf("Zavrsni ispit: ");
   scanf("%f", &zi2);
   if (zi2 < 0 || zi2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   s2 += zi2;
   if (s2 + EP < 55)
   {
      s2 = 5;
   }
   else if (s2 >= 55 && s2 < 65)
   {
      s2 = 6;
   }
   else if (s2 >= 65 && s2 < 75)
   {
      s2 = 7;
   }
   else if (s2 >= 75 && s2 < 85)
   {
      s2 = 8;
   }
   else if (s2 >= 85 && s2 < 92)
   {
      s2 = 9;
   }
   else if (s2 >= 92 && s2 <= 100)
   {
      s2 = 10;
   }
   if (s == 5 && s1 == 5 && s2 == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   if ((s > 5 && (s1 == 5 && s2 == 5)) || (s1 > 5 && (s == 5 && s2 == 5)) || (s2 > 5 && (s == 5 && s1 == 5)))
   {
      printf("Jedan student je polozio.");
   }
   if ((s == 5 && (s1 > 5 && s2 > 5)) || (s1 == 5 && (s > 5 && s2 > 5)) || (s2 == 5 && (s > 5 && s1 > 5)))
   {
      printf("Dva studenta su polozila.");
   }
   if (s > 5 && s1 > 5 && s2 > 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if (s == s1 && s == s2)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (s == s1 || s == s2 || s1 == s2)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   /*printf("Zadaća 1, Zadatak 1");*/
   return(0);
}
