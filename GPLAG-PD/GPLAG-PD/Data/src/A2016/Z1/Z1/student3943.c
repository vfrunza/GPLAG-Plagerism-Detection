#include <stdio.h>

int main()
{
   double a, b, c, d, e, f, g, h, i, j, k, l, m, n, o;


   printf("Unesite bodove za Tarika:\n");
   scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
   printf("I parcijalni ispit: ");
   if (a < 0 || a > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   if (b < 0 || b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   if (c < 0 || c > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   if (d < 0 || d > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   if (e < 0 || e > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   double A;

   A = a + b + c + d + e;


   printf("Unesite bodove za Bojana:\n");
   scanf("%lf %lf %lf %lf %lf", &f, &g, &h, &i, &j);
   printf("I parcijalni ispit: ");
   if (f < 0 || f > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   if (g < 0 || g > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   if (h < 0 || h > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   if (i < 0 || i > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   if (j < 0 || j > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   double B;

   B = f + g + h + i + j;



   printf("Unesite bodove za Mirzu:\n");
   scanf("%lf %lf %lf %lf %lf", &k, &l, &m, &n, &o);
   printf("I parcijalni ispit: ");
   if (k < 0 || k > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   if (l < 0 || l > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   if (m < 0 || m > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   if (n < 0 || n > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   if (o < 0 || o > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   double C;

   C = k + l + m + n + o;


   if (A < 55 && B < 55 && C < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else
   if ((A >= 55 && A <= 100 && B < 55 && C < 55) || (B >= 55 && B <= 100 && C < 55 && A < 55) || (C >= 55 && C <= 100 && A < 55 && B < 55))
   {
      printf("Jedan student je polozio.");
   }
   else
   if ((A >= 55 && A <= 100 && B >= 55 && B <= 100 && C < 55) || (B >= 55 && B <= 100 && C >= 55 && C <= 100 && A < 55) || (C >= 55 && C <= 100 && A >= 55 && A <= 100 && B < 55))
   {
      printf("Dva studenta su polozila.");
   }
   else
   {
      printf("Sva tri studenta su polozila.\n");

      if ((A < 65 && B < 65 && C < 65) || (A >= 65 && A < 75 && B >= 65 && B < 75 && C >= 65 && C < 75) || (A >= 75 && A < 85 && B >= 75 && B < 85 && C >= 75 && C < 85) || (A >= 85 && A < 92 && B >= 85 && B < 92 && C >= 85 && C < 92) || (A >= 92 && A <= 100 && B >= 92 && B <= 100 && C >= 92 && C <= 100))
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else
      if ((A < 65 && B < 65 && C >= 65 && C <= 100) || (C < 65 && B < 65 && A >= 65 && A <= 100) || (A < 65 && C < 65 && B >= 65 && B <= 100) || (A >= 65 && A < 75 && B >= 65 && B < 75 && (C < 65 || (C >= 75 && C <= 100))) || (B >= 65 && B < 75 && C >= 65 && C < 75 && (A < 65 || (A >= 75 && A <= 100))) || (A >= 65 && A < 75 && C >= 65 && C < 75 && (B < 65 || (B >= 75 && B <= 100))) || (A >= 75 && A < 85 && B >= 75 && B < 85 && (C < 75 || (C >= 85 && C <= 100))) || (B >= 75 && B < 85 && C >= 75 && C < 85 && (A < 75 || (A >= 85 && A <= 100))) || (A >= 75 && A < 85 && C >= 75 && C < 85 && (B < 75 || (B >= 85 && B <= 100))) || (A >= 85 && A < 92 && B >= 85 && B < 92 && (C < 85 || (C >= 92 && C <= 100))) || (B >= 85 && B < 92 && C >= 85 && C < 92 && (A < 85 || (A >= 92 && A <= 100))) || (A >= 85 && A < 92 && C >= 85 && C < 92 && (B < 85 || (B >= 92 && B <= 100))) || (A >= 92 && A <= 100 && B >= 92 && B < 100 && C < 92) || (B >= 92 && B <= 100 && C >= 92 && C <= 100 && A < 92) || (A >= 92 && A <= 100 && C >= 92 && C <= 100 && B < 92))
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
