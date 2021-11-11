#include <stdio.h>
int main()
{
   double PI1T, PI1B, PI1M, PI2T, PI2B, PI2M, ZT, ZM, ZB, PM, PB, PT, ZIT, ZIB, ZIM, UT, UB, UM;
   int    OT, OB, OM;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit:");
   scanf("%lf", &PI1T);
   if ((PI1T < 0) || (PI1T > 20))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit: ");
   scanf("%lf", &PI2T);
   if ((PI2T < 0) || (PI2T > 20))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PT);
   if ((PT < 0) || (PT > 10))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZT);
   if ((ZT < 0) || (ZT > 10))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIT);
   if ((ZIT < 0) || (ZIT > 40))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit:");
   scanf("%lf", &PI1B);
   if ((PI1B < 0) || (PI1B > 20))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit: ");
   scanf("%lf", &PI2B);
   if ((PI2B < 0) || (PI2B > 20))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PB);
   if ((PB < 0) || (PB > 10))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZB);
   if ((ZB < 0) || (ZB > 10))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIB);
   if ((ZIB < 0) || (ZIB > 40))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit:");
   scanf("%lf", &PI1M);
   if ((PI1M < 0) || (PI1M > 20))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit: ");
   scanf("%lf", &PI2M);
   if ((PI2M < 0) || (PI2M > 20))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PM);
   if ((PM < 0) || (PM > 10))
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZM);
   if ((ZM < 0) || (ZM > 10))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIM);
   if ((ZIM < 0) || (ZIM > 40))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   UT = PI1T + PI2T + ZT + PT + ZIT;
   UB = PI1B + PI2B + ZB + PB + ZIB;
   UM = PI1M + PI2M + ZM + PM + ZIM;
   if ((UT >= 0) && (UT < 55))
   {
      OT = 5;
   }
   else if ((UT >= 55) && (UT < 65))
   {
      OT = 6;
   }
   else if ((UT >= 65) && (UT < 75))
   {
      OT = 7;
   }
   else if ((UT >= 75) && (UT < 85))
   {
      OT = 8;
   }
   else if ((UT >= 85) && (UT < 95))
   {
      OT = 9;
   }
   else if ((UT >= 95) && (UT < 100))
   {
      OT = 10;
   }
   if ((UB >= 0) && (UB < 55))
   {
      OB = 5;
   }
   else if ((UB >= 55) && (UB < 65))
   {
      OB = 6;
   }
   else if ((UB >= 65) && (UB < 75))
   {
      OB = 7;
   }
   else if ((UB >= 75) && (UB < 85))
   {
      OB = 8;
   }
   else if ((UB >= 85) && (UB < 95))
   {
      OB = 9;
   }
   else if ((UB >= 95) && (UB < 100))
   {
      OB = 10;
   }
   if ((UM >= 0) && (UM < 55))
   {
      OM = 5;
   }
   else if ((UM >= 55) && (UM < 65))
   {
      OM = 6;
   }
   else if ((UM >= 65) && (UM < 75))
   {
      OM = 7;
   }
   else if ((UM >= 75) && (UM < 85))
   {
      OM = 8;
   }
   else if ((UM >= 85) && (UM < 95))
   {
      OM = 9;
   }
   else if ((UM >= 95) && (UM < 100))
   {
      OM = 10;
   }
   if ((OT == 5) && (OB == 5) && (OM == 5))
   {
      printf("Nijedan student nije polozio.\n");
   }
   if (((OT == 5) && (OB == 5) && (OM != 5)) || ((OT == 5) && (OB != 5) && (OM == 5)) || ((OT != 5) && (OB == 0) && (OM == 5)))
   {
      printf("Jedan student je polozio.\n");
   }
   if (((OT != 5) && (OB != 5) && (OM == 5)) || ((OT != 5) && (OB == 5) && (OM != 5)) || ((OT == 5) && (OB != 5) && (OM != 5)))
   {
      printf("Dva studenta su polozila.\n");
   }
   if ((OT != 5) && (OB != 5) && (OM != 5))
   {
      printf("Sva tri studenta su polozila.\n");
      if ((OT == OB) && (OT == OM) && (OB == OM))
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (((OT == OB) && (OT != OM) && (OB != OM)) || ((OT == OM) && (OT != OB) && (OB != OM)) || ((OM == OB) && (OT != OM) && (OB != OT)))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if ((OT != OB) && (OT != OM) && (OB != OM))
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }
   return(0);
}
