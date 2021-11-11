#include <stdio.h>

int main()
{
   double pi1, di1, p1, z1, zi1, pi2, p2, di2, zi2, z2, p3, pi3, di3, zi3, z3, a1, b1, c1, d1, o1, o2, o3;

   printf("Unesite bodove za Tarika:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &pi1);
   if (pi1 < 0 || pi1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &di1); if (di1 > 20 || di1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p1);
   if (p1 < 0 || p1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z1);
   if (z1 < 0 || z1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zi1);
   if (zi1 > 40 || zi1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Bojana:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &pi2);
   if (pi2 < 0 || pi2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &di2); if (di2 > 20 || di2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p2);
   if (p2 < 0 || p2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z2);
   if (z2 < 0 || z2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zi2);
   if (zi2 > 40 || zi2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Mirzu:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &pi3);
   if (pi3 < 0 || pi3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &di3); if (di3 > 20 || di3 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p3);
   if (p3 < 0 || p3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z3);
   if (z3 < 0 || z3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zi3);
   if (zi3 > 40 || zi3 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   a1 = p1 + pi1 + zi1 + z1 + di1;
   b1 = p2 + pi2 + zi2 + z2 + di2;
   c1 = p3 + pi3 + di3 + z3 + zi3;
   if (a1 < 55)
   {
      o1 = 5;
   }
   if (a1 >= 55 && a1 < 65)
   {
      o1 = 6;
   }
   if (a1 >= 65 && a1 < 75)
   {
      o1 = 7;
   }
   if (a1 >= 75 && a1 < 85)
   {
      o1 = 8;
   }
   if (a1 >= 85 && a1 < 92)
   {
      o1 = 9;
   }
   if (a1 >= 92 && a1 <= 100)
   {
      o1 = 10;
   }
   if (b1 < 55)
   {
      o2 = 5;
   }
   if (b1 >= 55 && b1 < 65)
   {
      o2 = 6;
   }
   if (b1 >= 65 && b1 < 75)
   {
      o2 = 7;
   }
   if (b1 >= 75 && b1 < 85)
   {
      o2 = 8;
   }
   if (b1 >= 85 && b1 < 92)
   {
      o2 = 9;
   }
   if (b1 >= 92 && b1 <= 100)
   {
      o2 = 10;
   }
   if (c1 < 55)
   {
      o3 = 5;
   }
   if (c1 >= 55 && c1 < 65)
   {
      o3 = 6;
   }
   if (c1 >= 65 && c1 < 75)
   {
      o3 = 7;
   }
   if (c1 >= 75 && c1 < 85)
   {
      o3 = 8;
   }
   if (c1 >= 85 && c1 < 92)
   {
      o3 = 9;
   }
   if (c1 >= 92 && c1 <= 100)
   {
      o3 = 10;
   }
   if (o1 == 5 && o2 == 5 && o3 == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   if (o1 == 5 && o2 != 5 && o3 != 5)
   {
      printf("Dva studenta su polozila.");
   }
   if (o2 == 5 && o1 != 5 && o3 != 5)
   {
      printf("Dva studenta su polozila.");
   }
   if (o3 == 5 && o1 != 5 && o2 != 5)
   {
      printf("Dva studenta su polozila.");
   }
   if (o1 != 5 && o2 != 5 && o3 != 5)
   {
      printf("Sva tri studenta su polozila.");
   }
   if (o1 != 5 && o2 == 5 && o3 == 5)
   {
      printf("Jedan student je polozio.");
   }
   if (o1 == 5 && o2 != 5 && o3 == 5)
   {
      printf("Jedan student je polozio.");
   }
   if (o1 == 5 && o2 == 5 && o3 != 5)
   {
      printf("Jedan student je polozio.");
   }
   if (o1 == o2 && o2 == o3 && o1 != 5 && o2 != 5 && o3 != 5)
   {
      printf("\nSva tri studenta imaju istu ocjenu.");
   }
   if (o1 == o2 && o2 != o3 && o1 != 5 && o2 != 5)
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   if (o1 != o2 && o2 == o3 && o2 != 5 && o3 != 5)
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   if (o1 == o3 && o2 != o3 && o1 != 5 && o3 != 5)
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   if (o1 != o3 && o1 != o2 && o2 != o3 && o1 != 5 && o2 != 5 && o3 != 5)
   {
      printf("\nSvaki student ima razlicitu ocjenu.");
   }



   return(0);
}
