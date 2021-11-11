#include <stdio.h>
#include <math.h>

int main()
{
   double P1T, P2T, PrT, DzT, ZiT, OT = 0, P1B, P2B, PrB, DzB, ZiB, OB = 0, P1M, P2M, PrM, DzM, ZiM, OM = 0;
   int    ot = 0, om = 0, ob = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &P1T);
   if (P1T < 0 || P1T > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &P2T);
   if (P2T < 0 || P2T > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PrT);
   if (PrT < 0 || PrT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &DzT);
   if (DzT < 0 || DzT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZiT);
   if (ZiT < 0 || ZiT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   OT = fabs(P1T + P2T + PrT + DzT + ZiT);


   if (OT < 54.999)
   {
      ot = 5;
   }
   else if (OT >= 54.999 && OT < 64.999)
   {
      ot = 6;
   }
   else if (OT >= 64.999 && OT < 74.999)
   {
      ot = 7;
   }
   else if (OT >= 74.999 && OT < 84.999)
   {
      ot = 8;
   }
   else if (OT >= 84.999 && OT < 91.999)
   {
      ot = 9;
   }
   else if (OT >= 91.999 && OT <= 100)
   {
      ot = 10;
   }



   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &P1B);
   if (P1B < 0 || P1B > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &P2B);
   if (P2B < 0 || P2B > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PrB);
   if (PrB < 0 || PrB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &DzB);
   if (DzB < 0 || DzB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZiB);
   if (ZiB < 0 || ZiB > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   OB = fabs(P1B + P2B + PrB + DzB + ZiB);

   if (OB < 55)
   {
      ob = 5;
   }
   else if (OB >= 54.999 && OB < 64.999)
   {
      ob = 6;
   }
   else if (OB >= 64.999 && OB < 74.999)
   {
      ob = 7;
   }
   else if (OB >= 74.999 && OB < 84.999)
   {
      ob = 8;
   }
   else if (OB >= 84.999 && OB < 91.999)
   {
      ob = 9;
   }
   else if (OB >= 91.999 && OB <= 100)
   {
      ob = 10;
   }



   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &P1M);
   if (P1M < 0 || P1M > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &P2M);
   if (P2M < 0 || P2M > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PrM);
   if (PrM < 0 || PrM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &DzM);
   if (DzM < 0 || DzM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZiM);
   if (ZiM < 0 || ZiM > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   OM = fabs(P1M + P2M + PrM + DzM + ZiM);


   if (OM < 55)
   {
      om = 5;
   }
   else if (OM >= 54.999 && OM < 64.999)
   {
      om = 6;
   }
   else if (OM >= 64.999 && OM < 74.999)
   {
      om = 7;
   }
   else if (OM >= 74.999 && OM < 84.999)
   {
      om = 8;
   }
   else if (OM >= 84.999 && OM < 94.999)
   {
      om = 9;
   }
   else if (OM >= 91.999 && OM <= 100)
   {
      om = 10;
   }

   if (OT >= 54.999 && OB >= 54.999 && OM >= 54.999)
   {
      printf("Sva tri studenta su polozila.\n");
      if (ot == ob && ob == om && ot == om)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (ot != ob && ob != om && ot != om)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
      else if ((ot != ob && ob == om) || (ot == ob && ob != om) || (ot == ob && ot != om))
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
   }
   else if (OT < 54.999 && OB < 54.999 && OM < 54.999)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if ((OT >= 55 && OB < 54.999 && OM < 54.999) || (OT < 54.999 && OB >= 55 && OM < 54.999) || (OT < 54.999 && OB < 54.999 && OM >= 55))
   {
      printf("Jedan student je polozio.\n");
   }
   else
   {
      printf("Dva studenta su polozila.\n");
   }
   return(0);
}
