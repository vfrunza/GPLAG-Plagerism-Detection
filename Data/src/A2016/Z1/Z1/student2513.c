#include <stdio.h>
#include <math.h>
int main()
{
   double t1, t2, t3, t4, t5, b1, b2, b3, b4, b5, m1, m2, m3, m4, m5, tu, bu, mu, ocjena1, ocjena2, ocjena3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &t1);
   if (t1 < 0 || t1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &t2);
   if (t2 < 0 || t2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &t3);
   if (t3 < 0 || t3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &t4);
   if (t4 < 0 || t4 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &t5);
   if (t5 < 0 || t5 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   tu = t1 + t2 + t3 + t4 + t5;

   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &b1);
   if (b1 < 0 || b1 > 20)
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
   scanf("%lf", &b3);
   if (b3 < 0 || b3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &b4);
   if (b4 < 0 || b4 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &b5);
   if (b5 < 0 || b5 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   bu = b1 + b2 + b3 + b4 + b5;

   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &m1);
   if (m1 < 0 || m1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &m2);
   if (m2 < 0 || m2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &m3);
   if (m3 < 0 || m3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &m4);
   if (m4 < 0 || m4 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &m5);
   if (m5 < 0 || m5 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   mu = m1 + m2 + m3 + m4 + m5;

   if (tu < 55 && bu < 55 && mu < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   if (tu >= 55 && bu >= 55 && mu >= 55)
   {
      printf("Sva tri studenta su polozila.");
   }
   if (tu >= 55 && bu >= 55 && mu < 55)
   {
      printf("Dva studenta su polozila.");
   }
   if (tu >= 55 && mu >= 55 && bu < 55)
   {
      printf("Dva studenta su polozila.");
   }
   if (bu >= 55 && mu >= 55 && tu < 55)
   {
      printf("Dva studenta su polozila.");
   }
   if ((tu >= 55 && mu < 55 && bu < 55) || (bu >= 55 && tu < 55 && mu < 55) || (mu >= 55 && tu < 55 && bu < 55))
   {
      printf("Jedan student je polozio.");
   }

   if (tu >= 55 && tu < 65)
   {
      ocjena1 = 6;
   }
   if (tu >= 65 && tu < 75)
   {
      ocjena1 = 7;
   }
   if (tu >= 75 && tu < 85)
   {
      ocjena1 = 8;
   }
   if (tu >= 85 && tu < 92)
   {
      ocjena1 = 9;
   }
   if (tu >= 92 && tu <= 100)
   {
      ocjena1 = 10;
   }

   if (bu >= 55 && bu < 65)
   {
      ocjena2 = 6;
   }
   if (bu >= 65 && bu < 75)
   {
      ocjena2 = 7;
   }
   if (bu >= 75 && bu < 85)
   {
      ocjena2 = 8;
   }
   if (bu >= 85 && bu < 92)
   {
      ocjena2 = 9;
   }
   if (bu >= 92 && bu <= 100)
   {
      ocjena2 = 10;
   }

   if (mu >= 55 && mu < 65)
   {
      ocjena3 = 6;
   }
   if (mu >= 65 && mu < 75)
   {
      ocjena3 = 7;
   }
   if (mu >= 75 && mu < 85)
   {
      ocjena3 = 8;
   }
   if (mu >= 85 && mu < 92)
   {
      ocjena3 = 9;
   }
   if (mu >= 92 && mu <= 100)
   {
      ocjena3 = 10;
   }


   if (tu >= 55 && bu >= 55 && mu >= 55)
   {
      if (ocjena1 != ocjena2 && ocjena2 != ocjena3 && ocjena1 != ocjena3)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }

      if (ocjena1 == ocjena2 && ocjena2 == ocjena3)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }

      if ((ocjena1 == ocjena2 && ocjena2 != ocjena3) || (ocjena1 == ocjena3 && ocjena3 != ocjena2) || (ocjena2 == ocjena3 && ocjena2 != ocjena1))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
   }



   return(0);
}
