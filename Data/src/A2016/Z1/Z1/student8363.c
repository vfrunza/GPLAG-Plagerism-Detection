#include <stdio.h>

int main()
{
   double uT, uB, uM, p1, p2, pp, z, zi, o1 = 5, o2 = 5, o3 = 5, c = 0, e = 0.001;

   printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
   scanf("%lf", &p1); if (p1 < 0 || p1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2); if (p2 < 0 || p2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pp); if (pp < 0 || pp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z); if (z < 0 || z > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zi); if (zi < 0 || z > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uT = p1 + p2 + pp + z + zi + e;
   printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
   scanf("%lf", &p1); if (p1 < 0 || p1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2); if (p2 < 0 || p2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pp); if (pp < 0 || pp > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z); if (z < 0 || z > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zi); if (zi < 0 || z > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uB = p1 + p2 + pp + z + zi + e;
   printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
   scanf("%lf", &p1); if (p1 < 0 || p1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &p2); if (p2 < 0 || p2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pp); if (pp < 0 || pp > 10)
   {
      printf("Neispravan broj bodova "); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &z); if (z < 0 || z > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zi); if (zi < 0 || zi > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   uM = p1 + p2 + pp + z + zi + e;
   if (uT < 55 && uB < 55 && uM < 55)
   {
      printf("Nijedan student nije polozio."); return(0);
   }
   if (uT >= 55 && uT < 65)
   {
      o1 = 6;
   }
   else if (uT >= 65 && uT < 75)
   {
      o1 = 7;
   }
   else if (uT >= 75 && uT < 85)
   {
      o1 = 8;
   }
   else if (uT >= 85 && uT < 92)
   {
      o1 = 9;
   }
   else if (uT >= 92)
   {
      o1 = 10;
   }
   else
   {
      c++;
   }
   if (uB >= 55 && uB < 65)
   {
      o2 = 6;
   }
   else if (uB >= 65 && uB < 75)
   {
      o2 = 7;
   }
   else if (uB >= 75 && uB < 85)
   {
      o2 = 8;
   }
   else if (uB >= 85 && uB < 92)
   {
      o2 = 9;
   }
   else if (uB >= 92)
   {
      o2 = 10;
   }
   else
   {
      c++;
   }
   if (uM >= 55 && uM < 65)
   {
      o3 = 6;
   }
   else if (uM >= 65 && uM < 75)
   {
      o3 = 7;
   }
   else if (uM >= 75 && uM < 85)
   {
      o3 = 8;
   }
   else if (uM >= 85 && uM < 92)
   {
      o3 = 9;
   }
   else if (uM >= 92)
   {
      o3 = 10;
   }
   else
   {
      c++;
   }
   if (c == 1)
   {
      printf("Dva studenta su polozila.");
   }
   else if (c == 2)
   {
      printf("Jedan student je polozio.");
   }
   else if (c == 0)
   {
      printf("Sva tri studenta su polozila.\n");
      if (o1 == o2)
      {
         c++;
      }
      if (o1 == o3)
      {
         c++;
      }
      if (o2 == o3)
      {
         c++;
      }
      if (o1 == o2 && o2 == o3)
      {
         c = 3;
      }
      if (c >= 2)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (c >= 1)
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
