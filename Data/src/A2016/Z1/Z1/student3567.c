#include <stdio.h>
int main()
{
   double t, bo, m;
   double a, b, c, d, e, f, g, h, i, j, p1, p2, pp, zi, z;

   printf(" Unesite bodove za Tarika: \nI parcijalni ispit:");
   scanf("%lf", &a);
   if (a > 20 || a < 0)
   {
      printf(" Nesipravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%lf", &b);
   if (b > 20 || b < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%lf", &c);
   if (c > 10 || c < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%lf", &d);
   if (d > 10 || d < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%lf", &e);
   if (e > 40 || e < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Unesite bodove za Bojana: \nI parcijalni ispit:");
   scanf("%lf", &f);
   if (f > 20 || f < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%lf", &g);
   if (g > 20 || g < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%lf", &h);
   if (h > 10 || h < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%lf", &i);
   if (i > 10 || i < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%lf", &j);
   if (j > 40 || j < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Unesite bodove za Mirzu: \nI parcijalni ispit:");
   scanf("%lf", &p1);
   if (p1 > 20 || p1 < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%lf", &p2);
   if (p2 > 20 || p2 < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%lf", &pp);
   if (pp > 10 || pp < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%lf", &z);
   if (z > 10 || z < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%lf", &zi);
   if (zi > 40 || zi < 0)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   t  = a + b + c + d + e;
   bo = f + g + h + i + j;
   m  = p1 + p2 + pp + z + zi;
   if (t < 55 && bo < 55 && m < 55)
   {
      printf(" Nijedan student nije polozio.");
   }
   if (t >= 55 && bo >= 55 && m >= 55)
   {
      printf(" Sva tri studenta su polozila.");
   }
   if ((t >= 55 && bo >= 55 && m >= 55) &&
       (((t >= 55 && t < 65) && (bo >= 55 && bo < 65) && (m >= 55 && m < 65)) ||
        ((t >= 65 && t < 75) && (bo >= 65 && bo < 75) && (m >= 65 && m < 65)) ||
        ((t >= 75 && t < 85) && (bo >= 75 && bo < 85) && (m >= 75 && m < 85)) ||
        ((t >= 85 && t < 92) && (bo >= 85 && bo < 92) && (m >= 85 && m < 92)) ||
        ((t >= 92 && t <= 100) && (bo >= 92 && bo <= 100) && (m >= 92 && m <= 100))))
   {
      printf(" Sva tri studenta imaju istu ocjenu.");
   }
   if ((t >= 55 && bo >= 55 && m >= 55) &&
       (((t >= 55 && t < 65) && (bo >= 55 && bo < 65) && (m >= 65 && m <= 100)) ||
        ((t >= 65 && t < 75) && (bo >= 65 && bo < 75) && (m >= 55 && m < 65 || m >= 75 && m <= 100)) ||
        ((t >= 75 && t < 85) && (bo >= 75 && bo < 85) && (m >= 55 && m < 75 || m >= 85 && m <= 100)) ||
        ((t >= 85 && t < 92) && (bo >= 85 && bo < 92) && (m >= 55 && m < 85 || m <= 92 && m <= 100)) ||
        ((t >= 92 && t <= 100) && (bo >= 92 && bo <= 100) && (m >= 55 && m < 92)) ||
        (t >= 55 && t < 65) && (bo >= 65 && bo <= 100) && (m >= 55 && m < 65)) ||
       ((t >= 65 && t < 75) && (bo >= 55 && bo < 65 || bo >= 75 && bo <= 100) && (m >= 65 && m < 75)) ||
       ((t >= 75 && t < 85) && (bo >= 55 && bo < 75 || bo >= 85 && bo <= 100) && (m >= 75 && m < 85)) ||
       ((t >= 85 && t < 92) && (bo >= 55 && bo < 85 || bo >= 92 && bo <= 100) && (m >= 85 && m < 92)) ||
       ((t >= 92 && t <= 100) && (bo >= 55 && bo < 92) && (m >= 92 && m <= 100)))
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   if ((t >= 55 && bo >= 55 && m >= 55) &&
       (((t >= 55 && t < 65) && (bo >= 65 && bo < 75) && (m >= 75 && m <= 85)) ||
        ((t >= 55 && t < 65) && (bo >= 75 && bo < 85) && (m >= 85 && m < 92)) ||
        ((t >= 55 && t < 65) && (bo >= 85 && bo < 92) && (m >= 75 && m < 85)) ||
        ((t >= 55 && t < 65) && (bo >= 75 && bo < 85) && (m >= 65 && m < 75)) ||
        ((t >= 55 && t < 65) && (bo >= 75 && bo <= 85) && (m >= 92 && m <= 100)) ||
        (t >= 55 && t < 65) && (bo >= 92 && bo <= 100) && (m >= 75 && m < 85)) ||
       ((t >= 55 && t < 65) && (bo >= 85 && bo < 92) && (m >= 92 && m < 100)) ||
       ((t >= 55 && t < 65) && (bo >= 92 && bo < 100) && (m >= 85 && m < 92)) ||
       ((t >= 55 && t < 65) && (bo >= 65 && bo < 75) && (m >= 85 && m < 92)) ||
       ((t >= 55 && t < 65) && (bo >= 85 && bo < 92) && (m >= 65 && m < 75)) ||
       ((t >= 55 && t < 65) && (bo >= 65 && bo < 75) && (m >= 92 && m <= 100)) ||
       ((t >= 55 && t < 65) && (bo >= 92 && bo <= 100) && (m >= 65 && m < 75)) ||
       ((t >= 65 && t < 75) && (bo >= 55 && bo < 65) && (m >= 75 && m < 85)) ||
       ((t >= 65 && t < 75) && (bo >= 75 && bo < 85) && (m >= 85 && m < 92)) ||
       ((t >= 65 && t < 75) && (bo >= 85 && bo < 92) && (m >= 75 && m < 85)) ||
       ((t >= 65 && t < 75) && (bo >= 75 && bo < 85) && (m >= 55 && m < 65)) ||
       ((t >= 65 && t < 75) && (bo >= 75 && bo <= 85) && (m >= 92 && m <= 100)) ||
       ((t >= 65 && t < 75) && (bo >= 92 && bo <= 100) && (m >= 75 && m < 85)) ||
       ((t >= 65 && t < 75) && (bo >= 85 && bo < 92) && (m >= 92 && m < 100)) ||
       ((t >= 65 && t < 75) && (bo >= 92 && bo < 100) && (m >= 85 && m < 92)) ||
       ((t >= 65 && t < 75) && (bo >= 55 && bo < 65) && (m >= 85 && m < 92)) ||
       ((t >= 65 && t < 75) && (bo >= 85 && bo < 92) && (m >= 55 && m < 65)) ||
       ((t >= 65 && t < 75) && (bo >= 55 && bo < 65) && (m >= 92 && m <= 100)) ||
       ((t >= 65 && t < 75) && (bo >= 92 && bo <= 100) && (m >= 55 && m < 65)) ||
       ((t >= 75 && t < 85) && (bo >= 55 && bo < 65) && (m >= 85 && m < 92)) ||
       ((t >= 75 && t < 85) && (bo >= 55 && bo < 65) && (m >= 65 && m < 75)) ||
       ((t >= 75 && t < 85) && (bo >= 65 && bo < 75) && (m >= 85 && m < 92)) ||
       ((t >= 75 && t < 85) && (bo >= 85 && bo < 92) && (m >= 65 && m < 75)) ||
       ((t >= 75 && t < 85) && (bo >= 65 && bo < 75) && (m >= 55 && m < 65)) ||
       ((t >= 75 && t < 85) && (bo >= 65 && bo <= 75) && (m >= 92 && m <= 100)) ||
       ((t >= 75 && t < 85) && (bo >= 92 && bo <= 100) && (m >= 65 && m < 75)) ||
       ((t >= 75 && t < 85) && (bo >= 85 && bo < 92) && (m >= 92 && m < 100)) ||
       ((t >= 75 && t < 85) && (bo >= 92 && bo < 100) && (m >= 85 && m < 92)) ||
       ((t >= 75 && t < 85) && (bo >= 55 && bo < 65) && (m >= 85 && m < 92)) ||
       ((t >= 75 && t < 85) && (bo >= 85 && bo < 92) && (m >= 55 && m < 65)) ||
       ((t >= 75 && t < 85) && (bo >= 55 && bo < 65) && (m >= 92 && m <= 100)) ||
       ((t >= 85 && t < 92) && (bo >= 55 && bo < 65) && (m >= 75 && m < 85)) ||
       ((t >= 85 && t < 92) && (bo >= 55 && bo < 65) && (m >= 65 && m < 75)) ||
       ((t >= 85 && t < 92) && (bo >= 65 && bo < 75) && (m >= 75 && m < 85)) ||
       ((t >= 85 && t < 92) && (bo >= 75 && bo < 85) && (m >= 65 && m < 75)) ||
       ((t >= 85 && t < 92) && (bo >= 65 && bo < 75) && (m >= 55 && m < 65)) ||
       ((t >= 85 && t < 92) && (bo >= 65 && bo <= 75) && (m >= 92 && m <= 100)) ||
       ((t >= 85 && t < 92) && (bo >= 92 && bo <= 100) && (m >= 65 && m < 75)) ||
       ((t >= 85 && t < 92) && (bo >= 75 && bo < 85) && (m >= 92 && m <= 100)) ||
       ((t >= 85 && t < 92) && (bo >= 92 && bo < 100) && (m >= 75 && m < 85)) ||
       ((t >= 85 && t < 92) && (bo >= 55 && bo < 65) && (m >= 75 && m < 85)) ||
       ((t >= 85 && t < 92) && (bo >= 75 && bo < 85) && (m >= 55 && m < 65)) ||
       ((t >= 85 && t < 92) && (bo >= 55 && bo < 65) && (m >= 92 && m <= 100)) ||
       ((t >= 92 && t <= 100) && (bo >= 55 && bo < 65) && (m >= 75 && m < 85)) ||
       ((t >= 92 && t <= 100) && (bo >= 55 && bo < 65) && (m >= 65 && m < 75)) ||
       ((t >= 92 && t <= 100) && (bo >= 65 && bo < 75) && (m >= 75 && m < 85)) ||
       ((t >= 92 && t <= 100) && (bo >= 75 && bo < 85) && (m >= 65 && m < 75)) ||
       ((t >= 92 && t <= 100) && (bo >= 65 && bo < 75) && (m >= 55 && m < 65)) ||
       ((t >= 92 && t <= 100) && (bo >= 65 && bo <= 75) && (m >= 85 && m < 92)) ||
       ((t >= 92 && t <= 100) && (bo >= 85 && bo < 92) && (m >= 65 && m < 75)) ||
       ((t >= 92 && t <= 100) && (bo >= 75 && bo < 85) && (m >= 85 && m < 92)) ||
       ((t >= 92 && t <= 100) && (bo >= 85 && bo < 92) && (m >= 75 && m < 85)) ||
       ((t >= 92 && t <= 100) && (bo >= 55 && bo < 65) && (m >= 75 && m < 85)) ||
       ((t >= 92 && t <= 100) && (bo >= 75 && bo < 85) && (m >= 55 && m < 65)) ||
       ((t >= 92 && t <= 100) && (bo >= 55 && bo < 65) && (m >= 85 && m < 92)))
   {
      printf("\nSvaki student ima razlicitu ocjenu.");
   }
   if ((t >= 55 && bo >= 55 && m < 55 && m > 0) || (t < 55 && t > 0 && bo >= 55 && m >= 55) || (t >= 55 && bo < 55 && bo > 0 && m <= 55))
   {
      printf(" Dva studenta su polozila.");
   }
   if ((t >= 55 && bo < 55 && m < 55) || (t < 55 && bo < 55 && m >= 55) || (t < 55 && bo >= 55 && m < 55))
   {
      printf(" Jedan student je polozio.");
   }
   return(0);
}
