#include <stdio.h>

int main()
{
   double a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, ut = 0, ub = 0, um = 0;
   int    o1, o2, o3;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &a);
   if (a < 0 || a > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b);
   if (b < 0 || b > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c);
   if (c < 0 || c > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &d);
   if (d < 0 || d > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e);
   if (e < 0 || e > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &f);
   if (f < 0 || f > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &g);
   if (g < 0 || g > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &h);
   if (h < 0 || h > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &i);
   if (i < 0 || i > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &j);
   if (j < 0 || j > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &k);
   if (k < 0 || k > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &l);
   if (l < 0 || l > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &m);
   if (m < 0 || m > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &n);
   if (n < 0 || n > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &o);
   if (o < 0 || o > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   ut = a + b + c + d + e;
   ub = f + g + h + i + j;
   um = k + l + m + n + o;


   if (ut < 55)
   {
      o1 = 5;
   }
   else if (ut >= 55 && ut < 65)
   {
      o1 = 6;
   }
   else if (ut >= 65 && ut < 75)
   {
      o1 = 7;
   }
   else if (ut >= 75 && ut < 85)
   {
      o1 = 8;
   }
   else if (ut >= 85 && ut < 92)
   {
      o1 = 9;
   }
   else if (ut >= 92 && ut <= 100)
   {
      o1 = 10;
   }



   if (ub < 55)
   {
      o2 = 5;
   }
   else if (ub >= 55 && ub < 65)
   {
      o2 = 6;
   }
   else if (ub >= 65 && ub < 75)
   {
      o2 = 7;
   }
   else if (ub >= 75 && ub < 85)
   {
      o2 = 8;
   }
   else if (ub >= 85 && ub < 92)
   {
      o2 = 9;
   }
   else if (ub >= 92 && ub <= 100)
   {
      o2 = 10;
   }



   if (um < 55)
   {
      o3 = 5;
   }
   else if (um >= 55 && um < 65)
   {
      o3 = 6;
   }
   else if (um >= 65 && um < 75)
   {
      o3 = 7;
   }
   else if (um >= 75 && um < 85)
   {
      o3 = 8;
   }
   else if (um >= 85 && um < 92)
   {
      o3 = 9;
   }
   else if (um >= 92 && um <= 100)
   {
      o3 = 10;
   }

   if (o1 == 5 && o2 == 5 && o3 == 5)
   {
      printf("Nijedan student nije polozio."); return(0);
   }
   else if (o1 > 5 && o2 == 5 && o3 == 5)
   {
      printf("Jedan student je polozio."); return(0);
   }
   else if (o1 == 5 && o2 > 5 && o3 == 5)
   {
      printf("Jedan student je polozio."); return(0);
   }
   else if (o1 == 5 && o2 == 5 && o3 > 5)
   {
      printf("Jedan student je polozio."); return(0);
   }
   else if (o1 > 5 && o2 > 5 && o3 == 5)
   {
      printf("Dva studenta su polozila."); return(0);
   }
   else if (o1 > 5 && o2 == 5 && o3 > 5)
   {
      printf("Dva studenta su polozila."); return(0);
   }
   else if (o1 == 5 && o2 > 5 && o3 > 5)
   {
      printf("Dva studenta su polozila."); return(0);
   }
   else if ((o1 > 5 && o2 > 5 && o3 > 5) && (o1 == o2 && o2 == o3))
   {
      printf("Sva tri studenta su polozila. \nSva tri studenta imaju istu ocjenu."); return(0);
   }
   else if ((o1 > 5 && o2 > 5 && o3 > 5) && (o1 == o2 && o1 != o3))
   {
      printf("Sva tri studenta su polozila. \nDva od tri studenta imaju istu ocjenu."); return(0);
   }
   else if ((o1 > 5 && o2 > 5 && o3 > 5) && (o1 == o3 && o1 != o2))
   {
      printf("Sva tri studenta su polozila. \nDva od tri studenta imaju istu ocjenu."); return(0);
   }
   else if ((o1 > 5 && o2 > 5 && o3 > 5) && (o2 == o3 && o2 != o1))
   {
      printf("Sva tri studenta su polozila. \nDva od tri studenta imaju istu ocjenu."); return(0);
   }
   else if ((o1 > 5 && o2 > 5 && o3 > 5) && (o1 != o2 && o2 != o3 && o1 != o3))
   {
      printf("Sva tri studenta su polozila. \nSvaki student ima razlicitu ocjenu."); return(0);
   }

   return(0);
}
