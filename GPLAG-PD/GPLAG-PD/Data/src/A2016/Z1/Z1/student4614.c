#include <stdio.h>
#include <math.h>
#define min    55


int main()
{
   double I1, I2, I3, II1, II2, II3, p1, p2, p3, dz1, dz2, dz3, z1, z2, z3;
   double UB1, UB2, UB3;
   int    ocjena1 = 0, ocjena2 = 0, ocjena3 = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &I1);
   if (I1 > 20 || I1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &II1);
   if (II1 > 20 || II1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p1);
   if (p1 > 10 || p1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &dz1);
   if (dz1 > 10 || dz1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &z1);
   if (z1 > 40 || z1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   UB1 = I1 + II1 + p1 + dz1 + z1;
   if (UB1 >= min && UB1 < 65)
   {
      ocjena1 = 6;
   }
   else if (UB1 >= 65 && UB1 < 75)
   {
      ocjena1 = 7;
   }
   else if (UB1 >= 75 && UB1 < 85)
   {
      ocjena1 = 8;
   }
   else if (UB1 >= 85 && UB1 < 92)
   {
      ocjena1 = 9;
   }
   else if (UB1 >= 92)
   {
      ocjena1 = 10;
   }


   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &I2);
   if (I2 > 20 || I2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &II2);
   if (II1 > 20 || II1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p2);
   if (p2 > 10 || p2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &dz2);
   if (dz1 > 10 || dz1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &z2);
   if (z2 > 40 || z2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   UB2 = I2 + II2 + p2 + dz2 + z2;
   if (UB2 >= min && UB2 < 65)
   {
      ocjena2 = 6;
   }
   else if (UB2 >= 65 && UB2 < 75)
   {
      ocjena2 = 7;
   }
   else if (UB2 >= 75 && UB2 < 85)
   {
      ocjena2 = 8;
   }
   else if (UB2 >= 85 && UB2 < 92)
   {
      ocjena2 = 9;
   }
   else if (UB2 >= 92)
   {
      ocjena2 = 10;
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &I3);
   if (I3 > 20 || I3 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &II3);
   if (II3 > 20 || II3 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &p3);
   if (p3 > 10 || p3 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &dz3);
   if (dz3 > 10 || dz3 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &z3);
   if (z3 > 40 || z3 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   UB3 = I3 + II3 + p3 + dz3 + z3;
   if (UB3 >= min && UB3 < 65)
   {
      ocjena3 = 6;
   }
   else if (UB3 >= 65 && UB3 < 75)
   {
      ocjena3 = 7;
   }
   else if (UB3 >= 75 && UB3 < 85)
   {
      ocjena3 = 8;
   }
   else if (UB3 >= 85 && UB3 < 92)
   {
      ocjena3 = 9;
   }
   else if (UB3 >= 92)
   {
      ocjena3 = 10;
   }

   if (UB1 < min && UB2 < min && UB3 < min)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((UB1 >= min && UB2 < min && UB3 < min) || (UB2 >= min && UB1 < min && UB3 < min) || (UB3 >= min && UB1 < min && UB2 < min))
   {
      printf("Jedan student je polozio.");
   }
   else if ((UB1 >= min && UB2 >= min && UB3 < min) || (UB1 >= min && UB3 >= min && UB2 < min) || (UB2 >= min && UB3 >= min && UB1 < min))
   {
      printf("Dva studenta su polozila.");
   }
   if (UB1 >= min && UB2 >= min && UB3 >= min)
   {
      printf("Sva tri studenta su polozila.\n");
      if (ocjena1 == ocjena2 && ocjena1 == ocjena3 && ocjena2 == ocjena3)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (ocjena1 != ocjena2 && ocjena1 != ocjena3 && ocjena2 != ocjena3)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
      else if (((ocjena1 == ocjena2) && (ocjena1 != ocjena3 || ocjena2 != ocjena3)) || ((ocjena1 == ocjena3) && (ocjena1 != ocjena2 || ocjena3 != ocjena2)) || ((ocjena2 == ocjena3) && (ocjena2 != ocjena1 || ocjena3 != ocjena1)))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }



   return(0);
}
