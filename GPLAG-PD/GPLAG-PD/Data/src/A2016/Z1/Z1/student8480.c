#include <stdio.h>
#define Iparcijalni     20.0
#define IIparcijalni    20.0
#define Prisustvo       10.0
#define Zadace          10.0
#define Zavrsniispit    40.0

int main()
{
   double a, b, c, d, e, f, g, h, zi, T = 0, B = 0, M = 0, ZI, TarikovaOcjena = 0, BojanovaOcjena = 0, MirzinaOcjena = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &a); if (a > Iparcijalni || a < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;
   printf("II parcijalni ispit: ");
   scanf("%lf", &b); if (b > IIparcijalni || b < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;
   printf("Prisustvo: ");
   scanf("%lf", &c); if (c < 0 || c > Prisustvo)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;
   printf("Zadace: ");
   scanf("%lf", &d); if (d < 0 || d > Zadace)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;
   printf("Zavrsni ispit: ");
   scanf("%lf", &zi); if (zi < 0 || zi > Zavrsniispit)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;



   T = a + b + c + d + zi;

   if (T < 55)
   {
      TarikovaOcjena = 5;
   }
   else if (T >= 55 && T < 65)
   {
      TarikovaOcjena = 6;
   }
   else if (T >= 65 && T < 75)
   {
      TarikovaOcjena = 7;
   }
   else if (T >= 75 && T < 85)
   {
      TarikovaOcjena = 8;
   }
   else if (T >= 85 && T < 92)
   {
      TarikovaOcjena = 9;
   }
   else if (T >= 92 && T <= 100)
   {
      TarikovaOcjena = 10;
   }


   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &e); if (e < 0 || e > Iparcijalni)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;
   printf("II parcijalni ispit: ");
   scanf("%lf", &f); if (f < 0 || f > IIparcijalni)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;
   printf("Prisustvo: ");
   scanf("%lf", &g); if (g < 0 || g > Prisustvo)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;
   printf("Zadace: ");
   scanf("%lf", &h); if (h < 0 || h > Zadace)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI); if (ZI < 0 || ZI > Zavrsniispit)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;

   B = e + f + g + h + ZI;

   if (B < 55)
   {
      BojanovaOcjena = 5;
   }
   else if (B >= 55 && B < 65)
   {
      BojanovaOcjena = 6;
   }
   else if (B >= 65 && B < 75)
   {
      BojanovaOcjena = 7;
   }
   else if (B >= 75 && B < 85)
   {
      BojanovaOcjena = 8;
   }
   else if (B >= 85 && B < 92)
   {
      BojanovaOcjena = 9;
   }
   else if (B >= 92 && b <= 100)
   {
      BojanovaOcjena = 10;
   }


   double i, j, k, l, iz;

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &i); if (i < 0 || i > Iparcijalni)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;
   printf("II parcijalni ispit: ");
   scanf("%lf", &j); if (j < 0 || j > IIparcijalni)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;
   printf("Prisustvo: ");
   scanf("%lf", &k); if (k < 0 || k > Prisustvo)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;
   printf("Zadace: ");
   scanf("%lf", &l); if (l < 0 || l > Zadace)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;
   printf("Zavrsni ispit: ");
   scanf("%lf", &iz); if (iz < 0 || iz > Zavrsniispit)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   ;



   M = i + j + k + l + iz;

   if (M < 55)
   {
      MirzinaOcjena = 5;
   }
   else if (M >= 55 && M < 65)
   {
      MirzinaOcjena = 6;
   }
   else if (M >= 65 && M < 75)
   {
      MirzinaOcjena = 7;
   }
   else if (M >= 75 && M < 85)
   {
      MirzinaOcjena = 8;
   }
   else if (M >= 85 && M < 92)
   {
      MirzinaOcjena = 9;
   }
   else if (M >= 92 && M <= 100)
   {
      MirzinaOcjena = 10;
   }

   if (M >= 55 && B >= 55 && T >= 55)
   {
      printf("Sva tri studenta su polozila.\n");

      if (TarikovaOcjena == MirzinaOcjena && MirzinaOcjena == BojanovaOcjena)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (TarikovaOcjena == MirzinaOcjena && MirzinaOcjena != BojanovaOcjena || TarikovaOcjena == BojanovaOcjena && BojanovaOcjena != MirzinaOcjena || BojanovaOcjena == MirzinaOcjena && MirzinaOcjena != TarikovaOcjena)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (TarikovaOcjena != MirzinaOcjena && MirzinaOcjena != BojanovaOcjena && TarikovaOcjena != BojanovaOcjena)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }

   else if (T >= 55 && B >= 55 && M < 55)
   {
      printf("Dva studenta su polozila.");
   }
   else if (T >= 55 && B < 55 && M >= 55)
   {
      printf("Dva studenta su polozila.");
   }
   else if (T >= 55 && B < 55 && M < 55)
   {
      printf("Jedan student je polozio.");
   }
   else if (T < 55 && B >= 55 && M >= 55)
   {
      printf("Dva studenta su polozila.");
   }
   else if (T < 55 && B >= 55 && M < 55)
   {
      printf("Jedan student je polozio.");
   }
   else if (T < 55 && B < 55 && M >= 55)
   {
      printf("Jedan student je polozio.");
   }
   else if (T < 55 && B < 55 && M < 55)
   {
      printf("Nijedan student nije polozio.");
   }

   return(0);
}
