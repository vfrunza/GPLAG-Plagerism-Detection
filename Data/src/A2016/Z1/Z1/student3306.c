#include <stdio.h>
#include <math.h>
#define EPSILON    0.001
int main()
{
   /*printf("Zadaća 1, Zadatak 1");*/
   int    oc, oc1, oc2;
   double a, b, c, d, e, a1, b1, c1, d1, e1, a2, b2, c2, d2, e2, S, S1, S2;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &a);
   if (a > 20 || a < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b);
   if (b > 20 || b < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c);
   if (c > 10 || c < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &d);
   if (d > 10 || d < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e);
   if (e > 40 || e < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &a1);
   if (a1 > 20 || a1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b1);
   if (b1 > 20 || b1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c1);
   if (c1 > 10 || c1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &d1);
   if (d1 > 10 || d1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e1);
   if (e1 > 40 || e1 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &a2);
   if (a2 > 20 || a2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b2);
   if (b2 > 20 || b2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c2);
   if (c2 > 10 || c2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &d2);
   if (d2 > 10 || d2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e2);
   if (e2 > 40 || e2 < 0)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   S = a + b + c + d + e;

   S1 = a1 + b1 + c1 + d1 + e1;
   S2 = a2 + b2 + c2 + d2 + e2;
   if (S < 55.0)
   {
      oc = 5;
   }
   else if ((S >= 55.0 && S < 65.0) || fabs(55 - S) <= EPSILON)
   {
      oc = 6;
   }
   else if ((S >= 65 && S < 75) || fabs(65 - S) <= EPSILON)
   {
      oc = 7;
   }
   else if ((S >= 75 && S < 85) || fabs(75 - S) <= EPSILON)
   {
      oc = 8;
   }
   else if ((S >= 85 && S < 92) || fabs(85 - S) <= EPSILON)
   {
      oc = 9;
   }
   else if ((S >= 92 && S <= 100) || fabs(92 - S) <= EPSILON)
   {
      oc = 10;
   }

   if (S1 < 55)
   {
      oc1 = 5;
   }
   else if (S1 >= 55 && S1 < 65)
   {
      oc1 = 6;
   }
   else if (S1 >= 65 && S1 < 75)
   {
      oc1 = 7;
   }
   else if (S1 >= 75 && S1 < 85)
   {
      oc1 = 8;
   }
   else if (S1 >= 85 && S1 < 92)
   {
      oc1 = 9;
   }
   else if (S1 >= 92 && S1 <= 100)
   {
      oc1 = 10;
   }

   if (S2 < 55)
   {
      oc2 = 5;
   }
   else if (S2 >= 55 && S2 < 65)
   {
      oc2 = 6;
   }
   else if (S2 >= 65 && S2 < 75)
   {
      oc2 = 7;
   }
   else if (S2 >= 75 && S2 < 85)
   {
      oc2 = 8;
   }
   else if (S2 >= 85 && S2 < 92)
   {
      oc2 = 9;
   }
   else if (S2 >= 92 && S2 <= 100)
   {
      oc2 = 10;
   }

   if (oc == 5 && oc1 == 5 && oc2 == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((oc > 5 && oc1 == 5 && oc2 == 5) || (oc == 5 && oc1 > 5 && oc2 == 5) || (oc == 5 && oc1 == 5 && oc2 > 5))
   {
      printf("Jedan student je polozio.");
   }
   else if ((oc > 5 && oc1 > 5 && oc2 == 5) || (oc > 5 && oc1 == 5 && oc2 > 5) || (oc == 5 && oc1 > 5 && oc2 > 5))
   {
      printf("Dva studenta su polozila.");
   }
   else if (oc > 5 && oc1 > 5 && oc2 > 5)
   {
      printf("Sva tri studenta su polozila.");
      if (oc == oc1 && oc1 == oc2 && oc == oc2)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((oc == oc1 && oc1 != oc2 && oc != oc2) || (oc == oc2 && oc != oc1 && oc2 != oc1) || (oc1 == oc2 && oc1 != oc && oc2 != oc))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
