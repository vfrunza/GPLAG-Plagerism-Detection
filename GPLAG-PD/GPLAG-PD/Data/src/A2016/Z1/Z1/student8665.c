#include <stdio.h>
#include <math.h>
#define EPSILON    0.0001

int main()
{
   double P = 0, D = 0, R = 0, Z = 0, ZI = 0, MP = 0, BP = 0, BD = 0, BR = 0, BZ = 0, BZI = 0, MD = 0, MR = 0, MZ = 0, MZI = 0, T = 0, B = 0, M = 0;
   int    OT = 0, OM = 0, OB = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &P);

   if (P < 0 || P > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &D);
   if (D < 0 || D > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &R);
   if (R < 0 || R > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Z);
   if (Z < 0 || Z > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI);
   if (ZI < 0 || ZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &BP);
   if (BP < 0 || BP > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &BD);
   if (BD < 0 || BD > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &BR);
   if (BR < 0 || BR > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &BZ);
   if (BZ < 0 || BZ > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &BZI);
   if (BZI < 0 || BZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &MP);
   if (MP < 0 || MP > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &MD);
   if (MD < 0 || MD > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &MR);
   if (MR < 0 || MR > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &MZ);
   if (MZ < 0 || MZ > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &MZI);
   if (MZI < 0 || MZI > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   T = P + D + R + Z + ZI;
   B = BP + BD + BR + BZ + BZI;
   M = MP + MD + MR + MZ + MZI;

   if (T < 55)
   {
      OT = 5;
   }
   else if ((fabs(T - 55) < EPSILON || T > 55) && T < 65)
   {
      OT = 6;
   }
   else if ((fabs(T - 65) < EPSILON || T > 65) && T < 75)
   {
      OT = 7;
   }
   else if ((fabs(T - 75) < EPSILON || T > 75) && T < 85)
   {
      OT = 8;
   }
   else if ((fabs(T - 85) < EPSILON || T > 85) && T < 92)
   {
      OT = 9;
   }
   else if ((fabs(T - 92) < EPSILON || T > 92) && T <= 100)
   {
      OT = 10;
   }

   if (B < 55)
   {
      OB = 5;
   }
   else if ((fabs(B - 55) < EPSILON || B > 55) && B < 65)
   {
      OB = 6;
   }
   else if ((fabs(B - 65) < EPSILON || B > 65) && B < 75)
   {
      OB = 7;
   }
   else if ((fabs(B - 75) < EPSILON || B > 75) && B < 85)
   {
      OB = 8;
   }
   else if ((fabs(B - 85) < EPSILON || B > 85) && B < 92)
   {
      OB = 9;
   }
   else if ((fabs(B - 92) < EPSILON || B > 92) && B <= 100)
   {
      OB = 10;
   }
   if (M < 55)
   {
      OM = 5;
   }
   else if ((fabs(M - 55) < EPSILON || M > 55) && M < 65)
   {
      OM = 6;
   }
   else if ((fabs(M - 65) < EPSILON || M > 65) && M < 75)
   {
      OM = 7;
   }
   else if ((fabs(M - 75) < EPSILON || M > 75) && M < 85)
   {
      OM = 8;
   }
   else if ((fabs(M - 85) < EPSILON || M > 85) && M < 92)
   {
      OM = 9;
   }
   else if ((fabs(M - 92) < EPSILON || M > 92) && M <= 100)
   {
      OM = 10;
   }

   if (OT == 5 && OB == 5 && OM == 5)
   {
      printf("Nijedan student nije polozio.\n");
   }
   if (OT >= 6 && OT <= 10 && OB == 5 && OM == 5)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (OT == 5 && OB >= 6 && OB <= 10 && OM == 5)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (OT == 5 && OB == 5 && OM >= 6 && OM <= 10)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (OT >= 6 && OT <= 10 && OB >= 6 && OB <= 10 && OM == 5)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (OT >= 6 && OT <= 10 && OB == 5 && OM >= 6 && OM <= 10)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (OT == 5 && OB >= 6 && OB <= 10 && OM >= 6 && OM <= 10)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (OT >= 6 && OT <= 10 && OB >= 6 && OB <= 10 && OM >= 6 && OM <= 10)
   {
      printf("Sva tri studenta su polozila.\n");
      if (OT == OB && OB == OM)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (OT == OB && OB != OM)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (OT != OB && OB == OM)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (OT == OM && OM != OB)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (OT != OB && OB != OM && OT != OM)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }


   return(0);
}
