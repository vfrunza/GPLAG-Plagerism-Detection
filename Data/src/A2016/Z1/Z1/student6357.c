#include <stdio.h>
int main()
{
   double p1, p2, p3, d1, d2, d3, u1, u2, u3, pr1, pr2, pr3, z1, z2, z3, sum1 = 0, sum2 = 0, sum3 = 0;
   int    ocjena1 = 0, ocjena2 = 0, ocjena3 = 0, pao = 0;

   printf("Unesite bodove za Tarika:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &p1);
   if (p1 < 0 || p1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &d1);
   if (d1 < 0 || d1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pr1);
   if (pr1 < 0 || pr1 > 10)
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
   scanf("%lf", &u1);
   if (u1 < 0 || u1 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Bojana:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &p2);
   if (p2 < 0 || p2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &d2);
   if (d2 < 0 || d2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pr2);
   if (pr2 < 0 || pr2 > 10)
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
   scanf("%lf", &u2);
   if (u2 < 0 || u2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &p3);
   if (p3 < 0 || p3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &d3);
   if (d3 < 0 || d3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pr3);
   if (pr3 < 0 || pr3 > 10)
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
   scanf("%lf", &u3);
   if (u3 < 0 || u3 > 40)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }
   sum1 = p1 + d1 + pr1 + z1 + u1;
   sum2 = p2 + d2 + pr2 + z2 + u2;
   sum3 = p3 + d3 + pr3 + z3 + u3;
   if (sum1 < 55)
   {
      pao++;
   }
   else if (sum1 >= 55 && sum1 < 65)
   {
      ocjena1 = 6;
   }
   else if (sum1 >= 65 && sum1 < 75)
   {
      ocjena1 = 7;
   }
   else if (sum1 >= 75 && sum1 < 85)
   {
      ocjena1 = 8;
   }
   else if (sum1 >= 85 && sum1 < 92)
   {
      ocjena1 = 9;
   }
   else
   {
      ocjena1 = 10;
   }
   if (sum2 < 55)
   {
      pao++;
   }
   else if (sum2 >= 55 && sum2 < 65)
   {
      ocjena2 = 6;
   }
   else if (sum2 >= 65 && sum2 < 75)
   {
      ocjena2 = 7;
   }
   else if (sum2 >= 75 && sum2 < 85)
   {
      ocjena2 = 8;
   }
   else if (sum2 >= 85 && sum2 < 92)
   {
      ocjena2 = 9;
   }
   else
   {
      ocjena2 = 10;
   }
   if (sum3 < 55)
   {
      pao++;
   }
   else if (sum3 >= 55 && sum3 < 65)
   {
      ocjena3 = 6;
   }
   else if (sum3 >= 65 && sum3 < 75)
   {
      ocjena3 = 7;
   }
   else if (sum3 >= 75 && sum3 < 85)
   {
      ocjena3 = 8;
   }
   else if (sum3 >= 85 && sum3 < 92)
   {
      ocjena3 = 9;
   }
   else
   {
      ocjena3 = 10;
   }
   if (pao == 3)
   {
      printf("Nijedan student nije polozio.");
   }
   else if (pao == 2)
   {
      printf("Jedan student je polozio.");
   }
   else if (pao == 1)
   {
      printf("Dva studenta su polozila.");
   }
   else if (pao == 0)
   {
      printf("Sva tri studenta su polozila.");
      if (ocjena1 == ocjena2 && ocjena1 == ocjena3)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (ocjena1 != ocjena2 && ocjena1 != ocjena3 && ocjena2 != ocjena3)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
      else
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
   }
   return(0);
}
