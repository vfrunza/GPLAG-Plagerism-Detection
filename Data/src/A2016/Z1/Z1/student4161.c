#include <stdio.h>
#include <math.h>
#define eps    0.0001
int main()
{
   float pom1, pom2, pom3, sum1, sum2, sum3;

   sum1 = 0; sum2 = 0; sum3 = 0;
   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pom1);
   if (pom1 < -eps || pom1 > 20 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum1 += pom1;
   printf("II parcijalni ispit: ");
   scanf("%f", &pom1);
   if (pom1 < -eps || pom1 > 20 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum1 += pom1;
   printf("Prisustvo: ");
   scanf("%f", &pom1);
   if (pom1 < -eps || pom1 > 10 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum1 += pom1;
   printf("Zadace: ");
   scanf("%f", &pom1);
   if (pom1 < -eps || pom1 > 10 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum1 += pom1;
   printf("Zavrsni ispit: ");
   scanf("%f", &pom1);
   if (pom1 < -eps || pom1 > 40 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum1 += pom1;
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pom2);
   if (pom2 < -eps || pom2 > 20 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum2 += pom2;
   printf("II parcijalni ispit: ");
   scanf("%f", &pom2);
   if (pom2 < -eps || pom2 > 20 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum2 += pom2;
   printf("Prisustvo: ");
   scanf("%f", &pom2);
   if (pom2 < -eps || pom2 > 10 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum2 += pom2;
   printf("Zadace: ");
   scanf("%f", &pom2);
   if (pom2 < -eps || pom2 > 10 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum2 += pom2;
   printf("Zavrsni ispit: ");
   scanf("%f", &pom2);
   if (pom2 < -eps || pom2 > 40 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum2 += pom2;
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pom3);
   if (pom3 < -eps || pom3 > 20 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum3 += pom3;
   printf("II parcijalni ispit: ");
   scanf("%f", &pom3);
   if (pom3 < -eps || pom3 > 20 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum3 += pom3;
   printf("Prisustvo: ");
   scanf("%f", &pom3);
   if (pom3 < -eps || pom3 > 10 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum3 += pom3;
   printf("Zadace: ");
   scanf("%f", &pom3);
   if (pom3 < -eps || pom3 > 10 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum3 += pom3;
   printf("Zavrsni ispit: ");
   scanf("%f", &pom3);
   if (pom3 < -eps || pom3 > 40 + eps)
   {
      printf("Neispravan broj bodova");
      return(1);
   }
   sum3 += pom3;
   /*printf("SUma jedan %g suma dva %g suma tri %g",sum1,sum2,sum3);*/
   if (sum1 - 55 < -eps && sum2 - 55 < -eps && sum3 - 55 < -eps)
   {
      printf("Nijedan student nije polozio.");
   }
   else
   {
      if ((sum1 - 54 > eps && sum2 - 54 < eps && sum3 - 54 < eps) || (sum1 - 54 < eps && sum2 - 54 > eps && sum3 - 54 < eps) || (sum1 - 54 < eps && sum2 - 54 < eps && sum3 - 55 > eps))
      {
         printf("Jedan student je polozio.");
      }
      else if ((sum1 - 55 >= eps && sum2 - 55 >= eps && sum3 - 55 <= eps) || (sum1 - 55 >= eps && sum2 - 55 <= eps && sum3 - 55 >= eps) || (sum1 - 55 <= eps && (sum2 - 55) >= eps && (sum3 - 55) >= eps))
      {
         printf("Dva studenta su polozila.");
      }
      else
      {
         printf("Sva tri studenta su polozila.");
         if ((sum1 < 85 && sum2 < 85 && sum3 < 85 && fabs(sum1 - sum2) < 10 && fabs(sum3 - sum2) < 10 && fabs(sum1 - sum3) < 10) || (sum1 > 85 && sum2 > 85 && sum3 > 85 && sum1 < 92 && sum2 < 92 && sum3 < 92) || (sum1 > 92 && sum2 > 92 && sum3 > 92))
         {
            printf("\nSva tri studenta imaju istu ocjenu.");
         }
         else if ((sum1 < 85 && sum2 < 85 && fabs(sum1 - sum2) < 10) || (sum1 > 85 && sum2 > 85 && sum1 < 92 && sum2 < 92) || (sum1 > 92 && sum2 > 92) ||
                  (sum3 < 85 && sum2 < 85 && fabs(sum3 - sum2) < 10) || (sum3 > 85 && sum2 > 85 && sum3 < 92 && sum2 < 92) || (sum3 > 92 && sum2 > 92) ||
                  (sum1 < 85 && sum3 < 85 && fabs(sum1 - sum3) < 10) || (sum1 > 85 && sum3 > 85 && sum1 < 92 && sum3 < 92) || (sum1 > 92 && sum3 > 92))
         {
            printf("\nDva od tri studenta imaju istu ocjenu.");
         }
         else
         {
            printf("\nSvaki student ima razlicitu ocjenu.");
         }
      }
   }
   return(0);
}
