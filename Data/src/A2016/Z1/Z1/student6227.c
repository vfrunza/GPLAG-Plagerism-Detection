#include <stdio.h>

int main()
{
   double a, b, c, d, e, f, a1, b1, c1, d1, e1, f1, a2, b2, c2, d2, e2, f2;
   int    ocjena1 = 0, ocjena2 = 0, ocjena3 = 0;

   printf("Unesite bodove za Tarika:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &a);
   if (a < 0 || a > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b);
   if (b < 0 || b > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c);
   if (c < 0 || c > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &d);
   if (d < 0 || d > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e);
   if (e < 0 || e > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }


   printf("Unesite bodove za Bojana:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &a1);
   if (a1 < 0 || a1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b1);
   if (b1 < 0 || b1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c1);
   if (c1 < 0 || c1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &d1);
   if (d1 < 0 || d1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e1);
   if (e1 < 0 || e1 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &a2);
   if (a2 < 0 || a2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &b2);
   if (b2 < 0 || b2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &c2);
   if (c2 < 0 || c2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &d2);
   if (d2 < 0 || d2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &e2);
   if (e2 < 0 || e2 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   f = a + b + c + d + e;
   if (f >= 55 && f < 65)
   {
      ocjena1 = 6;
   }
   else if (f >= 65 && f < 75)
   {
      ocjena1 = 7;
   }
   else if (f >= 75 && f < 85)
   {
      ocjena1 = 8;
   }
   else if (f >= 85 && f < 92)
   {
      ocjena1 = 9;
   }
   else if (f >= 92 && f <= 100)
   {
      ocjena1 = 10;
   }

   f1 = a1 + b1 + c1 + d1 + e1;
   if (f1 >= 55 && f1 < 65)
   {
      ocjena2 = 6;
   }
   else if (f1 >= 65 && f1 < 75)
   {
      ocjena2 = 7;
   }
   else if (f1 >= 75 && f1 < 85)
   {
      ocjena2 = 8;
   }
   else if (f1 >= 85 && f1 < 92)
   {
      ocjena2 = 9;
   }
   else if (f1 >= 92 && f1 <= 100)
   {
      ocjena2 = 10;
   }

   f2 = a2 + b2 + c2 + d2 + e2;
   if (f2 >= 55 && f2 < 65)
   {
      ocjena3 = 6;
   }
   else if (f2 >= 65 && f2 < 75)
   {
      ocjena3 = 7;
   }
   else if (f2 >= 75 && f2 < 85)
   {
      ocjena3 = 8;
   }
   else if (f2 >= 85 && f2 < 92)
   {
      ocjena3 = 9;
   }
   else if (f2 >= 92 && f2 <= 100)
   {
      ocjena3 = 10;
   }


   if (f < 55 && f1 < 55 && f2 < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((f >= 55 && f1 < 55 && f2 < 55) || (f < 55 && f1 >= 55 && f2 < 55) || (f < 55 && f1 < 55 && f2 >= 55))
   {
      printf("Jedan student je polozio.");
   }
   else if ((f >= 55 && f1 >= 55 && f2 < 55) || (f >= 55 && f1 < 55 && f2 >= 55) || (f < 55 && f1 >= 55 && f2 >= 55))
   {
      printf("Dva studenta su polozila.");
   }
   else if (f >= 55 && f1 >= 55 && f2 >= 55)
   {
      printf("Sva tri studenta su polozila.");

      if (ocjena1 == ocjena2 && ocjena1 == ocjena3)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if ((ocjena1 == ocjena2 && ocjena1 != ocjena3) || (ocjena1 == ocjena3 && ocjena1 != ocjena2) || (ocjena2 == ocjena3 && ocjena2 != ocjena1))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (ocjena1 != ocjena2 && ocjena1 != ocjena3 && ocjena2 != ocjena3)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
