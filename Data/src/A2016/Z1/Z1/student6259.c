#include <stdio.h>
#include <math.h>
#define EPSILON    0.001

int main()
{
   float T1, T2, TP, TZ, TZI, TU, B1, B2, BP, BZ, BZI, BU, M1, M2, MP, MZ, MZI, MU;
   int   OT = 0, OB = 0, OM = 0;

   /*Unosenje bodova za Tarika*/
   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &T1);
   if (T1 < 0 || T1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &T2);
   if (T2 < 0 || T2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &TP);
   if (TP < 0 || TP > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &TZ);
   if (TZ < 0 || TZ > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &TZI);
   if (TZI < 0 || TZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   TU = T1 + T2 + TP + TZ + TZI;


   /*Unosenje bodova za Bojana*/
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &B1);
   if (B1 < 0 || B1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &B2);
   if (B2 < 0 || B2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &BP);
   if (BP < 0 || BP > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &BZ);
   if (BZ < 0 || BZ > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &BZI);
   if (BZI < 0 || BZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   BU = B1 + B2 + BP + BZ + BZI;

   /*Unosenje bodova za Mirzu*/
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &M1);
   if (M1 < 0 || M1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &M2);
   if (M2 < 0 || M1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &MP);
   if (MP < 0 || MP > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &MZ);
   if (MZ < 0 || MZ > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &MZI);
   if (MZI < 0 || (MZI > 40))
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   MU = M1 + M2 + MP + MZ + MZI;

   /* Ocjena za Tarika*/
   if ((TU + EPSILON) <= 55)
   {
      OT = 5;
   }
   else if ((TU + EPSILON) > 55 && (TU + EPSILON) <= 65)
   {
      OT = 6;
   }
   else if ((TU + EPSILON) > 65 && (TU + EPSILON) <= 75)
   {
      OT = 7;
   }
   else if ((TU + EPSILON) > 75 && (TU + EPSILON) <= 85)
   {
      OT = 8;
   }
   else if ((TU + EPSILON) > 85 && (TU + EPSILON) <= 92)
   {
      OT = 9;
   }
   else
   {
      OT = 10;
   }

   /*Ocjena za Mirzu*/
   if ((MU + EPSILON) <= 55)
   {
      OM = 5;
   }
   else if ((MU + EPSILON) > 55 && (MU + EPSILON) <= 65)
   {
      OM = 6;
   }
   else if ((MU + EPSILON) > 65 && (MU + EPSILON) <= 75)
   {
      OM = 7;
   }
   else if ((MU + EPSILON) > 75 && (MU + EPSILON) <= 85)
   {
      OM = 8;
   }
   else if ((MU + EPSILON) > 85 && (MU + EPSILON) <= 92)
   {
      OM = 9;
   }
   else
   {
      OM = 10;
   }

   /*Ocjena za Bojana*/
   if ((BU + EPSILON) <= 55)
   {
      OB = 5;
   }
   else if ((BU + EPSILON) > 55 && (BU + EPSILON) <= 65)
   {
      OB = 6;
   }
   else if ((BU + EPSILON) > 65 && (BU + EPSILON) <= 75)
   {
      OB = 7;
   }
   else if ((BU + EPSILON) > 75 && (BU + EPSILON) <= 85)
   {
      OB = 8;
   }
   else if ((BU + EPSILON) > 85 && (BU + EPSILON) <= 92)
   {
      OB = 9;
   }
   else
   {
      OB = 10;
   }

   /*Koliko je studenata polozilo*/
   if (OT < 6 && OM < 6 && OB < 6)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((OT < 6 && OB < 6 && OM >= 6) || (OT < 6 && OB >= 6 && OM < 6) || (OT >= 6 && OB < 6 && OM < 6))
   {
      printf("Jedan student je polozio.");
   }
   else if ((OT >= 6 && OB >= 6 && OM < 6) || (OT >= 6 && OB < 6 && OM >= 6) || (OT < 6 && OB >= 6 && OM >= 6))
   {
      printf("Dva studenta su polozila.");
   }
   else if (OT >= 6 && OB >= 6 && OM >= 6)
   {
      printf("Sva tri studenta su polozila.\n");
      if (OT == OM && OM == OB)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (OT != OM && OM != OB && OT != OB)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      else
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }


   return(0);
}
