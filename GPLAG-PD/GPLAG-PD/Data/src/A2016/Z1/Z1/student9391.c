#include <stdio.h>
#include <math.h>
#define MAX        100
#define MIN        55
#define MIN_OCJ    5
int main()
{
   float p1T, p2T, PRIS_T, ZAD_T, ZAV_T;
   float p1B, p2B, PRIS_B, ZAD_B, ZAV_B;
   float p1M, p2M, PRIS_M, ZAD_M, ZAV_M;
   int   SES = 0, SED = 0, OSM = 0, DEV = 0, DES = 0;
   int   OCJT, OCJB, OCJM;
   float KON1, KON2, KON3;
   float EPS = 1e-5;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &p1T);
   if (p1T < 0 || p1T > 20)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &p2T);
   if (p2T < 0 || p2T > 20)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }
   printf("Prisustvo: ");
   scanf("%f", &PRIS_T);
   if (PRIS_T < 0 || PRIS_T > 10)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }
   printf("Zadace: ");
   scanf("%f", &ZAD_T);
   if (ZAD_T < 0 || ZAD_T > 10)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZAV_T);
   if (ZAV_T < 0 || ZAV_T > 40)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &p1B);
   if (p1B < 0 || p1B > 20)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &p2B);
   if (p2B < 0 || p2B > 20)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }
   printf("Prisustvo: ");
   scanf("%f", &PRIS_B);
   if (PRIS_B < 0 || PRIS_B > 10)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }
   printf("Zadace: ");
   scanf("%f", &ZAD_B);
   if (ZAD_B < 0 || ZAD_B > 10)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &ZAV_B);
   if (ZAV_B < 0 || ZAV_B > 40)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%f", &p1M);
   if (p1M < 0 || p1M > 20)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &p2M);
   if (p2M < 0 || p2M > 20)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }
   printf("Prisustvo: ");
   scanf("%f", &PRIS_M);
   if (PRIS_M < 0 || PRIS_M > 10)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }
   printf("Zadace: ");
   scanf("%f", &ZAD_M);
   if (ZAD_M < 0 || ZAD_M > 10)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZAV_M);
   if (ZAV_M < 0 || ZAV_M > 40)
   {
      printf("Neispravan broj bodova"); goto kraj;
   }

   KON1 = p1T + p2T + PRIS_T + ZAD_T + ZAV_T;
   KON2 = p1B + p2B + PRIS_B + ZAD_B + ZAV_B;
   KON3 = p1M + p2M + PRIS_M + ZAD_M + ZAV_M;
   if (KON1 < MIN - EPS)
   {
      OCJT = MIN_OCJ;
   }
   else if (KON1 >= MIN - EPS && KON1 < 65)
   {
      OCJT = 6; SES++;
   }
   else if (KON1 >= 65 && KON1 < 75)
   {
      OCJT = 7; SED++;
   }
   else if (KON1 >= 75 && KON1 < 85)
   {
      OCJT = 8; OSM++;
   }
   else if (KON1 >= 85 && KON1 < 92)
   {
      OCJT = 9; DEV++;
   }
   else if (KON1 >= 92 && KON1 <= MAX)
   {
      OCJT = 10; DES++;
   }

   if (KON2 < MIN - EPS)
   {
      OCJB = MIN_OCJ;
   }
   else if (KON2 >= MIN - EPS && KON2 < 65)
   {
      OCJB = 6; SES++;
   }
   else if (KON2 >= 65 && KON2 < 75)
   {
      OCJB = 7; SED++;
   }
   else if (KON2 >= 75 && KON2 < 85)
   {
      OCJB = 8; OSM++;
   }
   else if (KON2 >= 85 && KON2 < 92)
   {
      OCJB = 9; DEV++;
   }
   else if (KON2 >= 92 && KON2 <= MAX)
   {
      OCJB = 10; DES++;
   }

   if (KON3 < MIN - EPS)
   {
      OCJM = MIN_OCJ;
   }
   else if (KON3 >= MIN - EPS && KON3 < 65)
   {
      OCJM = 6; SES++;
   }
   else if (KON3 >= 65 && KON3 < 75)
   {
      OCJM = 7; SED++;
   }
   else if (KON3 >= 75 && KON3 < 85)
   {
      OCJM = 8; OSM++;
   }
   else if (KON3 >= 85 && KON3 < 92)
   {
      OCJM = 9; DEV++;
   }
   else if (KON3 >= 92 && KON3 <= MAX)
   {
      OCJM = 10; DES++;
   }

   if (OCJT == MIN_OCJ && OCJB == MIN_OCJ && OCJM == MIN_OCJ)
   {
      printf("Nijedan student nije polozio.\n");
      goto kraj;
   }
   else if (OCJT != MIN_OCJ && OCJB != MIN_OCJ && OCJM != MIN_OCJ)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else if ((OCJT != MIN_OCJ && OCJB == MIN_OCJ && OCJM == MIN_OCJ) ||
            (OCJT == MIN_OCJ && OCJB != MIN_OCJ && OCJM == MIN_OCJ) ||
            (OCJT == MIN_OCJ && OCJB == MIN_OCJ && OCJM != MIN_OCJ))
   {
      printf("Jedan student je polozio.\n");
   }
   else
   {
      printf("Dva studenta su polozila.\n");
   }

   if (OCJT != MIN_OCJ && OCJB != MIN_OCJ && OCJM != MIN_OCJ)
   {
      if (DEV == 2 || DES == 2 || OSM == 2 || SED == 2 || SES == 2)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else if (DEV == 3 || DES == 3 || OSM == 3 || SED == 3 || SES == 3)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }
kraj:
   /*printf("Zadaća 1, Zadatak 1");*/
   return(0);
}
