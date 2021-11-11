#include <stdio.h>
#include <math.h>
int main()

/* Tarik - IP1,IIP1,PRIS,Z,ZI */
/* Bojan - IP2,IIP2,PRIS2,Z2,ZI2 */
/* Mirza - IP3,IIP3,PRIS3,Z3,ZI3 */
{
   const double Eps = 1e-10;
   double       IP1, IIP1, PRIS, Z, ZI;
   double       IP2, IIP2, PRIS2, Z2, ZI2;
   double       IP3, IIP3, PRIS3, Z3, ZI3;
   double       XT, XB, XM;
   double       TARIK, BOJAN, MIRZA;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IP1);
/*TARIK TARIK TARIK TARIK*/
   if (20 < IP1 || IP1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIP1);
   if (20 < IIP1 || IIP1 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PRIS);
   if (10 < PRIS || PRIS < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z);
   if (10 < Z || Z < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI);
   if (40 < ZI || ZI < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   /*BOJAN BOJAN BOJAN BOJAN*/

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IP2);
   if (20 < IP2 || IP2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIP2);
   if (20 < IIP2 || IIP2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PRIS2);
   if (10 < PRIS2 || PRIS2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z2);
   if (10 < Z2 || Z2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI2);
   if (40 < ZI2 || ZI2 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   /*MIRZA MIRZA MIRZA MIRZA MIRZA*/

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IP3);
   if (20 < IP3 || IP3 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIP3);
   if (20 < IIP3 && IIP3 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PRIS3);
   if (10 < PRIS3 || PRIS3 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z3);
   if (10 < Z3 || Z3 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI3);
   if (40 < ZI3 || ZI3 < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   {
      XM = IP3 + IIP3 + PRIS3 + Z3 + ZI3;
      XT = IP1 + IIP1 + PRIS + Z + ZI;
      XB = IP2 + IIP2 + PRIS2 + Z2 + ZI2;
      if (XT < 55)
      {
         TARIK = 5;
      }
      if (55 <= XT && XT < 65)
      {
         TARIK = 6;
      }
      if (65 <= XT && XT < 75)
      {
         TARIK = 7;
      }
      if (75 <= XT && XT < 85)
      {
         TARIK = 8;
      }
      if (85 <= XT && XT < 92)
      {
         TARIK = 9;
      }
      if (92 <= XT && XT <= 100)
      {
         TARIK = 10;
      }
      if (XB < 55)
      {
         BOJAN = 5;
      }
      if (55 <= XB && XB < 65)
      {
         BOJAN = 6;
      }
      if (65 <= XB && XB < 75)
      {
         BOJAN = 7;
      }
      if (75 <= XB && XB < 85)
      {
         BOJAN = 8;
      }
      if (85 <= XB && XB < 92)
      {
         BOJAN = 9;
      }
      if (92 <= XB && XB <= 100)
      {
         BOJAN = 10;
      }
      if (XM < 55)
      {
         MIRZA = 5;
      }
      if (55 <= XM && XM < 65)
      {
         MIRZA = 6;
      }
      if (65 <= XM && XM < 75)
      {
         MIRZA = 7;
      }
      if (65 <= XM && XM < 85)
      {
         MIRZA = 8;
      }
      if (85 <= XM && XM < 92)
      {
         MIRZA = 9;
      }
      if (92 <= XM && XM <= 100)
      {
         MIRZA = 10;
      }
   }
   if (fabs(TARIK - 5) <= Eps * (fabs(TARIK) + fabs(5)) && (fabs(5 - BOJAN) <= Eps * (fabs(BOJAN) + fabs(5)) && (fabs(5 - MIRZA) <= Eps * (fabs(MIRZA) + fabs(5)))))
   {
      printf("Nijedan student nije polozio.");
   }
   else
   {
      if (fabs(TARIK - 5) > Eps * (fabs(TARIK) + fabs(5)) && (fabs(5 - BOJAN) <= Eps * (fabs(BOJAN) + fabs(5)) && (fabs(5 - MIRZA) <= Eps * (fabs(MIRZA) + fabs(5)))))
      {
         printf("Jedan student je polozio.");
      }
      if (fabs(TARIK - 5) <= Eps * (fabs(TARIK) + fabs(5)) && (fabs(5 - BOJAN) > Eps * (fabs(BOJAN) + fabs(5)) && (fabs(5 - MIRZA) <= Eps * (fabs(MIRZA) + fabs(5)))))
      {
         printf("Jedan student je polozio.");
      }
      if (fabs(TARIK - 5) <= Eps * (fabs(TARIK) + fabs(5)) && (fabs(5 - BOJAN) <= Eps * (fabs(BOJAN) + fabs(5)) && (fabs(5 - MIRZA) > Eps * (fabs(MIRZA) + fabs(5)))))
      {
         printf("Jedan student je polozio.");
      }
      if (fabs(TARIK - 5) > Eps * (fabs(TARIK) + fabs(5)) && (fabs(5 - BOJAN) <= Eps * (fabs(BOJAN) + fabs(5)) && (fabs(5 - MIRZA) > Eps * (fabs(MIRZA) + fabs(5)))))
      {
         printf("Dva studenta su polozila.");
      }
      if (fabs(TARIK - 5) > Eps * (fabs(TARIK) + fabs(5)) && (fabs(5 - BOJAN) > Eps * (fabs(BOJAN) + fabs(5)) && (fabs(5 - MIRZA) <= Eps * (fabs(MIRZA) + fabs(5)))))
      {
         printf("Dva studenta su polozila.");
      }
      if (fabs(TARIK - 5) <= Eps * (fabs(TARIK) + fabs(5)) && (fabs(5 - BOJAN) > Eps * (fabs(BOJAN) + fabs(5)) && (fabs(5 - MIRZA) > Eps * (fabs(MIRZA) + fabs(5)))))
      {
         printf("Dva studenta su polozila.");
      }
   }
   if (fabs(TARIK - 5) > Eps * (fabs(TARIK) + fabs(5)) && (fabs(5 - BOJAN) > Eps * (fabs(BOJAN) + fabs(5)) && (fabs(5 - MIRZA) > Eps * (fabs(MIRZA) + fabs(5)))))
   {
      printf("Sva tri studenta su polozila.\n");
      if (fabs(TARIK - BOJAN) <= Eps * (fabs(TARIK) + fabs(BOJAN)) && (fabs(TARIK - MIRZA) <= Eps * (fabs(MIRZA) + fabs(TARIK))))
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      if (fabs(TARIK - BOJAN) <= Eps * (fabs(TARIK) + fabs(BOJAN)) && (fabs(TARIK - MIRZA) > Eps * (fabs(MIRZA) + fabs(TARIK))))
      {
         printf("Dva od tri studenta imaju istu ocjenu. \n");
      }
      if (fabs(TARIK - MIRZA) <= Eps * (fabs(TARIK) + fabs(MIRZA)) && (fabs(BOJAN - MIRZA) > Eps * (fabs(MIRZA) + fabs(BOJAN))))
      {
         printf("Dva od tri studenta imaju istu ocjenu. \n");
      }
      if (fabs(BOJAN - MIRZA) <= Eps * (fabs(BOJAN) + fabs(MIRZA)) && (fabs(TARIK - BOJAN) > Eps * (fabs(BOJAN) + fabs(MIRZA))))
      {
         printf("Dva od tri studenta imaju istu ocjenu. \n");
      }
      if ((fabs(BOJAN - MIRZA) > Eps * (fabs(BOJAN) + fabs(MIRZA))) && (fabs(TARIK - MIRZA) > Eps * (fabs(TARIK) + fabs(MIRZA))) && (fabs(BOJAN - TARIK) > Eps * (fabs(BOJAN) + fabs(TARIK))))
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }
   return(0);
}
