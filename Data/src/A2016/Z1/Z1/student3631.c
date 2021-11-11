#include <stdio.h>

int main()
{
   double a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p = 0, q = 0, r = 0;
   int    t, u, v;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &a); if (a < 0 || a > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b); if (b < 0 || b > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c); if (c < 0 || c > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &d); if (d < 0 || d > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e); if (e < 0 || e > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &f); if (f < 0 || f > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &g); if (g < 0 || g > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &h); if (h < 0 || h > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &i); if (i < 0 || i > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &j); if (j < 0 || j > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &k); if (k < 0 || k > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &l); if (l < 0 || l > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &m); if (m < 0 || m > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &n); if (n < 0 || n > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &o); if (o < 0 || o > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   p = a + b + c + d + e;
   q = f + g + h + i + j;
   r = k + l + m + n + o;

   if (p < 55)
   {
      t = 5;
   }
   else if (p >= 55 && p < 65)
   {
      t = 6;
   }
   else if (p >= 65 && p < 75)
   {
      t = 7;
   }
   else if (p >= 75 && p < 85)
   {
      t = 8;
   }
   else if (p >= 85 && p < 92)
   {
      t = 9;
   }
   else if (p >= 92 && p <= 100)
   {
      t = 10;
   }
   if (q < 55)
   {
      u = 5;
   }

   else if (55 <= q && q < 65)
   {
      u = 6;
   }
   else if (65 <= q && q < 75)
   {
      u = 7;
   }
   else if (75 <= q && q < 85)
   {
      u = 8;
   }
   else if (85 <= q && q < 92)
   {
      u = 9;
   }
   else if (92 <= q && q <= 100)
   {
      u = 10;
   }
   if (r < 55)
   {
      v = 5;
   }

   else if (55 <= r && r < 65)
   {
      v = 6;
   }
   else if (65 <= r && r < 75)
   {
      v = 7;
   }
   else if (75 <= r && r < 85)
   {
      v = 8;
   }
   else if (85 <= r && r < 92)
   {
      v = 9;
   }
   else if (92 <= r && r <= 100)
   {
      v = 10;
   }



   if (t < 6 && u < 6 && v < 6)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (t < 6 && u >= 6 && v >= 6)
   {
      printf("Dva studenta su polozila.");
   }
   else if (t >= 6 && u >= 6 && v < 6)
   {
      printf("Dva studenta su polozila.");
   }
   else if (t >= 6 && u < 6 && v >= 6)
   {
      printf("Dva studenta su polozila.");
   }
   else if (t < 6 && u < 6 && v >= 6)
   {
      printf("Jedan student je polozio.");
   }
   else if (t < 6 && u >= 6 && v < 6)
   {
      printf("Jedan student je polozio.");
   }
   else if (t >= 6 && u < 6 && v < 6)
   {
      printf("Jedan student je polozio.");
   }
   else if ((t >= 6 && u >= 6 && v >= 6) && (t != u && u != v && t != v))
   {
      printf("Sva tri studenta su polozila.\nSvaki student ima razlicitu ocjenu.");
   }
   else if ((t >= 6 && u >= 6 && v >= 6) && (t == u && t != v && u != v))
   {
      printf("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu.");
   }
   else if ((t >= 6 && u >= 6 && v >= 6) && (t == v && t != u && v != u))
   {
      printf("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu.");
   }
   else if ((t >= 6 && u >= 6 && v >= 6) && (u == v && u != t && v != t))
   {
      printf("Sva tri studenta su polozila.\nDva od tri studenta imaju istu ocjenu.");
   }
   else if ((t >= 6 && u >= 6 && v >= 6) && (v == u && u == t && v == t))
   {
      printf("Sva tri studenta su polozila.\nSva tri studenta imaju istu ocjenu.");
   }

   return(0);
}
