#include <stdio.h>
#include <math.h>
#define EPSILON    0.000001

int main()
{
   double pp1 = 0, dp1 = 0, p1 = 0, z1 = 0, isp1 = 0, pp2 = 0, dp2 = 0, p2 = 0, z2 = 0, isp2 = 0, pp3 = 0, dp3 = 0, p3 = 0, z3 = 0, isp3 = 0, bb1 = 0, bb2 = 0, bb3 = 0, ub = 0, oc1 = 0, oc2 = 0, oc3 = 0, oc = 0;

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
   scanf("%lf", &isp1);
   if (isp1 < 0 || isp1 > 40)
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
   scanf("%lf", &isp2);
   if (isp2 < 0 || isp2 > 40)
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
   scanf("%lf", &isp3);
   if (isp3 < 0 || isp3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   bb1 = pp1 + dp1 + p1 + z1 + isp1;
   bb2 = pp2 + dp2 + p2 + z2 + isp2;
   bb3 = pp3 + dp3 + p3 + z3 + isp3;
   ub  = bb1 + bb2 + bb3;

   if (bb1 >= 55 && bb1 < 65)
   {
      oc1 = 6;
   }
   if (bb1 >= 65 && bb1 < 75)
   {
      oc1 = 7;
   }
   if (bb1 >= 75 && bb1 < 85)
   {
      oc1 = 8;
   }
   if (bb1 >= 85 && bb1 < 92)
   {
      oc1 = 9;
   }
   if (bb1 >= 92 && bb1 <= 100)
   {
      oc1 = 10;
   }

   if (bb2 >= 55 && bb2 < 65)
   {
      oc2 = 6;
   }
   if (bb2 >= 65 && bb2 < 75)
   {
      oc2 = 7;
   }
   if (bb2 >= 75 && bb2 < 85)
   {
      oc2 = 8;
   }
   if (bb2 >= 85 && bb2 < 92)
   {
      oc2 = 9;
   }
   if (bb2 >= 92 && bb2 <= 100)
   {
      oc2 = 10;
   }

   if (bb3 >= 55 && bb3 < 65)
   {
      oc3 = 6;
   }
   if (bb3 >= 65 && bb3 < 75)
   {
      oc3 = 7;
   }
   if (bb3 >= 75 && bb3 < 85)
   {
      oc3 = 8;
   }
   if (bb3 >= 85 && bb3 < 92)
   {
      oc3 = 9;
   }
   if (bb3 >= 92 && bb3 <= 100)
   {
      oc3 = 10;
   }

   oc = oc1 + oc2 + oc3;

   if ((oc1 >= 0 && oc1 < 6) && (oc2 >= 0 && oc2 < 6) && (oc3 >= 0 && oc3 < 6))
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if (oc >= 18 && oc <= 30)
   {
      printf("Sva tri studenta su polozila.\n");
      if (fabs(oc1 - oc2) < EPSILON && fabs(oc2 - oc3) < EPSILON)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (!(fabs(oc1 - oc2) < EPSILON) && !(fabs(oc1 - oc3) < EPSILON) && !(fabs(oc2 - oc3) < EPSILON))
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
      else
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
   }
   else if ((oc1 >= 6 && oc1 <= 10 && oc2 >= 6 && oc2 <= 10) || (oc1 >= 6 && oc1 <= 10 && oc3 >= 6 && oc3 <= 10) || (oc2 >= 6 && oc2 <= 10 && oc3 >= 6 && oc3 <= 10))
   {
      printf("Dva studenta su polozila.\n");
   }
   else if ((oc1 >= 6 && oc1 <= 10) || (oc2 >= 6 && oc2 <= 10) || (oc3 >= 6 && oc3 <= 10))
   {
      printf("Jedan student je polozio.\n");
   }
   return(0);
}
