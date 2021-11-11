#include <stdio.h>
#include <math.h>

int main()
{
   float PPaT, DPaT, ZT, PrT, ZIT, PPaB, DPaB, ZB, PB, ZIB, PPaM, DPaM, ZM, PM, ZIM;
   float ST, SB, SM;
   int   T, B, M;

   T = 0;
   B = 0;
   M = 0;


   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &PPaT);
   if (PPaT < 0 || PPaT > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &DPaT);
   if (DPaT < 0 || DPaT > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &PrT);
   if (PrT < 0 || PrT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &ZT);
   if (ZT < 0 || ZT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &ZIT);
   if (ZIT < 0 || ZIT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &PPaB);
   if (PPaB < 0 || PPaB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &DPaB);
   if (DPaB < 0 || DPaB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &PB);
   if (PB < 0 || PB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &ZB);
   if (ZB < 0 || ZB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &ZIB);
   if (ZIT < 0 || ZIT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &PPaM);
   if (PPaM < 0 || PPaM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &DPaM);
   if (DPaM < 0 || DPaM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &PM);
   if (PM < 0 || PM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%f", &ZM);
   if (ZM < 0 || ZM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &ZIM);
   if (ZIM < 0 || ZIM > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }


   if (PPaT < 0 || DPaT < 0 || ZT < 0 || PrT < 0 || ZIT < 0 || PPaT > 20 || DPaT > 20 || ZT > 10 || PrT > 10 || ZIT > 40)
   {
      printf("Neispravan broj bodova");
   }
   else if (PPaB < 0 || DPaB < 0 || ZB < 0 || PB < 0 || ZIB < 0 || PPaB > 20 || DPaB > 20 || ZB > 10 || PB > 10 || ZIB > 40)
   {
      printf("Neispravan broj bodova");
   }
   else if (PPaM < 0 || DPaM < 0 || ZM < 0 || PM < 0 || ZIM < 0 || PPaM > 20 || DPaM > 20 || ZM > 10 || PM > 10 || ZIM > 40)
   {
      printf("Neispravan broj bodova");
   }

   else
   {
      ST = PPaT + DPaT + PrT + ZT + ZIT;
      SB = PPaB + DPaB + PB + ZB + ZIB;
      SM = PPaM + DPaM + PM + ZM + ZIM;



      if (ST <= 54.9999)
      {
         T = 5;
      }
      else if (ST >= 55 && ST < 65)
      {
         T = 6;
      }
      else if (ST >= 65 && ST < 75)
      {
         T = 7;
      }
      else if (ST >= 75 && ST < 85)
      {
         T = 8;
      }
      else if (ST >= 85 && ST < 92)
      {
         T = 9;
      }
      else
      {
         T = 10;
      }

      if (SB <= 54.9999)
      {
         B = 5;
      }
      else if (SB >= 55 && SB < 65)
      {
         B = 6;
      }
      else if (SB >= 65 && SB < 75)
      {
         B = 7;
      }
      else if (SB >= 75 && SB < 85)
      {
         B = 8;
      }
      else if (SB >= 85 && SB < 92)
      {
         B = 9;
      }
      else
      {
         B = 10;
      }

      if (SM <= 54.9999)
      {
         M = 5;
      }
      else if (SM >= 55 && SM < 65)
      {
         M = 6;
      }
      else if (SM >= 65 && SM < 75)
      {
         M = 7;
      }
      else if (SM >= 75 && SM < 85)
      {
         M = 8;
      }
      else if (SM >= 85 && SM < 92)
      {
         M = 9;
      }
      else
      {
         M = 10;
      }


      if (T == 5 && B == 5 && M == 5)
      {
         printf("Nijedan student nije polozio.\n");
         return(0);
      }
      else if (T != 5 && B != 5 && M != 5)
      {
         printf("Sva tri studenta su polozila.\n");
      }
      else if ((T == 5 || B == 5 || M == 5) && ((T != 5 && B != 5) || (T != 5 && M != 5) || (B != 5 && M != 5)))
      {
         printf("Dva studenta su polozila.\n");
         return(0);
      }
      else
      {
         printf("Jedan student je polozio.\n ");
         return(0);
      }



      if (T == B && T == M && B == M)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (T != B && T != M && M != B)
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
