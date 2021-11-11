#include <stdio.h>
#define EPSILON    0.01
int main()
{
   double a1, b1, c1, d1, e1, a2, b2, c2, d2, e2, a3, b3, c3, d3, e3;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &a1);
   if (a1 < 0 || a1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b1);
   if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c1);
   if (c1 < 0 || c1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &d1);
   if (d1 < 0 || d1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e1);
   if (e1 < 0 || e1 > 40)
   {
      printf("Nesipravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &a2);
   if (a2 < 0 || a2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b2);
   if (b2 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c2);
   if (c2 < 0 || c2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &d2);
   if (d2 < 0 || d2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e2);
   if (e2 < 0 || e2 > 40)
   {
      printf("Nesipravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &a3);
   if (a3 < 0 || a3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b3);
   if (b3 < 0 || b3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c3);
   if (c3 < 0 || c3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &d3);
   if (d3 < 0 || d3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e3);
   if (e3 < 0 || e3 > 40)
   {
      printf("Nesipravan broj bodova");
      return(0);
   }

   double o1, o2, o3;
   int    t = 0;
   int    b = 0;
   int    m = 0;

   o1 = (a1 + b1 + c1 + d1 + e1);
   o2 = (a2 + b2 + c2 + d2 + e2);
   o3 = (a3 + b3 + c3 + d3 + e3);

   if (o1 < 55)
   {
      t++;
   }
   if (o1 >= 55 && o1 < 65)
   {
      t += 2;
   }
   if (o1 >= 65 && o1 < 75)
   {
      t += 3;
   }
   if (o1 >= 75 && o1 < 85)
   {
      t += 4;
   }
   if (o1 >= 85 && o1 < 92)
   {
      t += 5;
   }
   if (o1 >= 92 && o1 <= 100)
   {
      t += 6;
   }

   if (o2 < 55)
   {
      b++;
   }
   if (o2 >= 55 && o2 < 65)
   {
      b += 2;
   }
   if (o2 >= 65 && o2 < 75)
   {
      b += 3;
   }
   if (o2 >= 75 && o2 < 85)
   {
      b += 4;
   }
   if (o2 >= 85 && o2 < 92)
   {
      b += 5;
   }
   if (o2 >= 92 && o2 <= 100)
   {
      b += 6;
   }

   if (o3 < 55)
   {
      m++;
   }
   if (o3 >= 55 && o3 < 65)
   {
      m += 2;
   }
   if (o3 >= 65 && o3 < 75)
   {
      m += 3;
   }
   if (o3 >= 75 && o3 < 85)
   {
      m += 4;
   }
   if (o3 >= 85 && o3 < 92)
   {
      m += 5;
   }
   if (o3 >= 92 && o3 <= 100)
   {
      m += 6;
   }

   if (t == 1 && b == 1 && m == 1)
   {
      printf("Nijedan student nije polozio.\n");
   }
   if ((t != 1 && b == 1 && m == 1) || (t == 1 && b != 1 && m == 1) || (t == 1 && b == 1 && m != 1))
   {
      printf("Jedan student je polozio.\n");
   }
   if ((t != 1 && b != 1 && m == 1) || (t != 1 && b == 1 && m != 1) || (t == 1 && b != 1 && m != 1))
   {
      printf("Dva studenta su polozila.\n");
   }
   if (t != 1 && b != 1 && m != 1)
   {
      printf("Sva tri studenta su polozila.\n");
      if (t != b && b != m && m != t)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
      if ((t == b && b != m && t != m) || (t != b && b == m && t != m) || (t == m && b != m && t != b))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      if (t == m && t == b && m == b)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
   }

   return(0);
}
