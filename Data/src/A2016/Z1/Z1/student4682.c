#include <stdio.h>
#include <math.h>
#define EPSILON    0.0001
int main()
{
   double a1 = 0, b1 = 0, c1 = 0, d1 = 0, e1 = 0, a2 = 0, b2 = 0, c2 = 0, d2 = 0, e2 = 0, a3 = 0, b3 = 0, c3 = 0, d3 = 0, e3 = 0, u1 = 0, u2 = 0, u3 = 0, oc1 = 0, oc2 = 0, oc3 = 0;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &a1);
   if ((a1 < 0) || (a1 > 20))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b1);
   if ((b1 < 0) || (b1 > 20))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c1);
   if ((c1 < 0) || (c1 > 10))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &d1);
   if ((d1 < 0) || (d1 > 10))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e1);
   if ((e1 < 0) || (e1 > 40))
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   {
      printf("Unesite bodove za Bojana: ");
      printf("\nI parcijalni ispit: ");
      scanf("%lf", &a2);
      if ((a2 < 0) || (a2 > 20))
      {
         printf("Neispravan broj bodova\n");
         return(0);
      }
      printf("II parcijalni ispit: ");
      scanf("%lf", &b2);
      if ((b2 < 0) || (b2 > 20))
      {
         printf("Neispravan broj bodova\n");
         return(0);
      }
      printf("Prisustvo: ");
      scanf("%lf", &c2);
      if ((c2 < 0) || (c2 > 10))
      {
         printf("Neispravan broj bodova\n");
         return(0);
      }
      printf("Zadace: ");
      scanf("%lf", &d2);
      if ((d2 < 0) || (d2 > 10))
      {
         printf("Neispravan broj bodova\n");
         return(0);
      }
      printf("Zavrsni ispit: ");
      scanf("%lf", &e2);
      if ((e2 < 0) || (e2 > 40))
      {
         printf("Neispravan broj bodova\n");
         return(0);
      }


      printf("Unesite bodove za Mirzu: ");
      printf("\nI parcijalni ispit: ");
      scanf("%lf", &a3);
      if ((a3 < 0) || (a3 > 20))
      {
         printf("Neispravan broj bodova\n");
         return(0);
      }
      printf("II parcijalni ispit: ");
      scanf("%lf", &b3);
      if ((b3 < 0) || (b3 > 20))
      {
         printf("Neispravan broj bodova\n");
         return(0);
      }
      printf("Prisustvo: ");
      scanf("%lf", &c3);
      if ((c3 < 0) || (c3 > 10))
      {
         printf("Neispravan broj bodova\n");
         return(0);
      }
      printf("Zadace: ");
      scanf("%lf", &d3);
      if ((d3 < 0) || (d3 > 10))
      {
         printf("Neispravan broj bodova\n");
         return(0);
      }
      printf("Zavrsni ispit: ");
      scanf("%lf", &e3);
      if ((e3 < 0) || (e3 > 40))
      {
         printf("Neispravan broj bodova\n");
         return(0);
      }


      u1 = a1 + b1 + c1 + d1 + e1;
      u2 = a2 + b2 + c2 + d2 + e2;
      u3 = a3 + b3 + c3 + d3 + e3;

      if (u1 >= 55 && u1 < 65)
      {
         oc1 = 6;
      }
      if (u1 >= 65 && u1 < 75)
      {
         oc1 = 7;
      }
      if (u1 >= 75 && u1 < 85)
      {
         oc1 = 8;
      }
      if (u1 >= 85 && u1 < 92)
      {
         oc1 = 9;
      }
      if (u1 >= 92 && u1 <= 100)
      {
         oc1 = 10;
      }

      if (u2 >= 55 && u2 < 65)
      {
         oc2 = 6;
      }
      if (u2 >= 65 && u2 < 75)
      {
         oc2 = 7;
      }
      if (u2 >= 75 && u2 < 85)
      {
         oc2 = 8;
      }
      if (u2 >= 85 && u2 < 92)
      {
         oc2 = 9;
      }
      if (u2 >= 92 && u2 <= 100)
      {
         oc2 = 10;
      }

      if (u3 >= 55 && u3 < 65)
      {
         oc3 = 6;
      }
      if (u3 >= 65 && u3 < 75)
      {
         oc3 = 7;
      }
      if (u3 >= 75 && u3 < 85)
      {
         oc3 = 8;
      }
      if (u3 >= 85 && u3 < 92)
      {
         oc3 = 9;
      }
      if (u3 >= 92 && u3 <= 100)
      {
         oc3 = 10;
      }

      if ((oc1 >= 0 && oc1 < 6) && (oc2 >= 0 && oc2 < 6) && (oc3 >= 0 && oc3 < 6))
      {
         printf("Nijedan student nije polozio.");
      }
      else if ((oc1 >= 6 && oc1 < 10) && (oc2 >= 6 && oc2 < 10) && (oc3 >= 6 && oc3 < 10))
      {
         printf("Sva tri studenta su polozila.");
         if (fabs(oc1 - oc2) < EPSILON && fabs(oc2 - oc3) < EPSILON)
         {
            printf("\nSva tri studenta imaju istu ocjenu.");
         }
         else if (fabs(oc1 - oc2) >= EPSILON && fabs(oc2 - oc3) >= EPSILON && fabs(oc1 - oc3) >= EPSILON)
         {
            printf("\nSvaki student ima razlicitu ocjenu.");
         }
         else
         {
            printf("\nDva od tri studenta imaju istu ocjenu.");
         }
      }
      else if ((oc1 >= 6 && oc1 <= 19) && (oc2 >= 6 && oc2 <= 10) || (oc2 >= 6 && oc2 <= 10) && (oc3 >= 6 && oc3 <= 10) || (oc3 >= 6 && oc3 <= 10) && (oc1 >= 6 && oc1 <= 10))
      {
         printf("Dva studenta su polozila.");
      }
      else if ((oc1 >= 6 && oc1 <= 10) || (oc2 >= 6 && oc2 <= 10) || (oc3 >= 6 && oc3 <= 10))
      {
         printf("Jedan student je polozio.");
      }
   }

   return(0);
}
