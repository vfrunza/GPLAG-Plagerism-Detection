#include <stdio.h>
#include <math.h>

int main()
{
   float       i1, i2, i3, ii1, ii2, ii3, pr1, pr2, pr3, d1, d2, d3, z1, z2, z3, s1, s2, s3;
   const float eps = 1e-2;
   int         ocjena1, ocjena2, ocjena3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &i1);
   if (i1 < 0 || i1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &ii1);
   if (ii1 < 0 || ii1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pr1);
   if (pr1 < 0 || pr1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &d1);
   if (d1 < 0 || d1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &z1);
   if (z1 < 0 || z1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &i2);
   if (i2 < 0 || i2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &ii2);
   if (ii2 < 0 || ii2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pr2);
   if (pr2 < 0 || pr2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &d2);
   if (d2 < 0 || d2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &z2);
   if (z2 < 0 || z2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }



   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &i3);
   if (i3 < 0 || i3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &ii3);
   if (ii3 < 0 || ii3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &pr3);
   if (pr3 < 0 || pr3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &d3);
   if (d3 < 0 || d3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &z3);
   if (z3 < 0 || z3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   s1 = i1 + ii1 + pr1 + d1 + z1;
   s2 = i2 + ii2 + pr2 + d2 + z2;
   s3 = i3 + ii3 + pr3 + d3 + z3;



   if ((fabs(s1 - 55) < eps || s1 > 55) && s1 < 65)
   {
      ocjena1 = 6;
   }

   if ((fabs(s1 - 65) < eps || s1 > 65) && s1 < 75)
   {
      ocjena1 = 7;
   }

   if ((fabs(s1 - 75) < eps || s1 > 75) && s1 < 85)
   {
      ocjena1 = 8;
   }

   if ((fabs(s1 - 85) < eps || s1 > 85) && s1 < 92)
   {
      ocjena1 = 9;
   }

   if ((fabs(s1 - 92) < eps || s1 > 95) && (fabs(s1 - 100) < eps || s1 < 100))
   {
      ocjena1 = 10;
   }

   if ((fabs(s2 - 55) < eps || s2 > 55) && s2 < 65)
   {
      ocjena2 = 6;
   }

   if ((fabs(s2 - 65) < eps || s2 > 65) && s2 < 75)
   {
      ocjena2 = 7;
   }

   if ((fabs(s2 - 75) < eps || s2 > 75) && s2 < 85)
   {
      ocjena2 = 8;
   }

   if ((fabs(s2 - 85) < eps || s2 > 85) && s2 < 92)
   {
      ocjena2 = 9;
   }

   if ((fabs(s2 - 92) < eps || s2 > 95) && (fabs(s2 - 100) < eps || s2 < 100))
   {
      ocjena2 = 10;
   }

   if ((fabs(s3 - 55) < eps || s3 > 55) && s3 < 65)
   {
      ocjena3 = 6;
   }

   if ((fabs(s3 - 65) < eps || s3 > 65) && s3 < 75)
   {
      ocjena3 = 7;
   }

   if ((fabs(s3 - 75) < eps || s3 > 75) && s3 < 85)
   {
      ocjena3 = 8;
   }

   if ((fabs(s3 - 85) < eps || s3 > 85) && s3 < 92)
   {
      ocjena3 = 9;
   }

   if ((fabs(s3 - 92) < eps || s3 > 95) && (fabs(s3 - 100) < eps || s3 < 100))
   {
      ocjena3 = 10;
   }


   if (((fabs(s1 - 55) < eps || s1 > 55) && s2 < 55 && s3 < 55) || (s1 < 55 && (fabs(s2 - 55) < eps || s2 > 55) && s3 < 55) || (s1 < 55 && s2 < 55 && (fabs(s3 - 55) < eps || s3 > 55)))
   {
      printf("Jedan student je polozio.\n");
   }

   else if (((fabs(s1 - 55) < eps || s1 > 55) && (fabs(s2 - 55) < eps || s2 > 55) && s3 < 55) || ((fabs(s1 - 55) < eps || s1 > 55) && s2 < 55 && (fabs(s3 - 55) < eps || s3 > 55)) || (s1 < 55 && (fabs(s2 - 55) < eps || s2 > 55) && (fabs(s3 - 55) < eps || s3 > 55)))
   {
      printf("Dva studenta su polozila.");
   }


   else if (s1 < 55 && s2 < 55 && s3 < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }


   if ((fabs(s1 - 55) < eps || s1 > 55) && (fabs(s2 - 55) < eps || s2 > 55) && (fabs(s3 - 55) < eps || s3 > 55))
   {
      printf("Sva tri studenta su polozila.\n");
      if (ocjena1 == ocjena2 && ocjena1 == ocjena3 && ocjena2 == ocjena3)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      if (ocjena1 != ocjena2 && ocjena1 != ocjena3 && ocjena2 != ocjena3)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
      if ((ocjena1 == ocjena2 && ocjena1 != ocjena3 && ocjena2 != ocjena3) || (ocjena1 == ocjena3 && ocjena1 != ocjena2 && ocjena2 != ocjena3) || (ocjena2 == ocjena3 && ocjena2 != ocjena1 && ocjena1 != ocjena3))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
   }

   return(0);
}
