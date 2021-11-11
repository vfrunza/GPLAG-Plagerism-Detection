#include <stdio.h>
double PPT, PPB, PPM, DPT, DPB, DPM, PT, PB, PM, ZT, ZB, ZM, zT, zB, zM;
int    T, B, M, pao;
int main()
{
   /*Tarik*/
   printf("\nUnesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &PPT);
   if (PPT < 0 || PPT > 40)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DPT);
   if (DPT < 0 || DPT > 40)
   {
      printf("\nNeispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PT);
   if (PT < 0 || PT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZT);
   if (ZT < 0 || ZT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zT);
   if (zT < 0 || zT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   /*Bojan*/
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &PPB);
   if (PPB < 0 || PPB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DPB);
   if (DPB < 0 || DPB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PB);
   if (PB < 0 || PB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZB);
   if (ZB < 0 || ZB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zB);
   if (zB < 0 || zB > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   /*Mirza*/
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &PPM);
   if (PPM < 0 || PPM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DPM);
   if (DPM < 0 || DPM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PM);
   if (PM < 0 || PM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZM);
   if (ZM < 0 || ZM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zM);
   if (zM < 0 || zM > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   T = PPT + DPT + PT + ZT + zT;
   M = PPM + DPM + PM + ZM + zM;
   B = PPB + DPB + PB + ZB + zB;

   /*do 55 bodova - student pao
    *  [55,65) bodova - ocjena 6
    *  [65,75) bodova - ocjena 7
    *  [75,85) bodova - ocjena 8
    *  [85,92) boda - ocjena 9
    *  [92,100] bodova - ocjena 10*/

   /*Tarik*/
   if (T < 55)
   {
      T = pao;
   }
   else if (T >= 56 && T < 65)
   {
      T = 6;
   }
   else if (T >= 65 && T < 75)
   {
      T = 7;
   }
   else if (T >= 75 && T < 85)
   {
      T = 8;
   }
   else if (T >= 85 && T < 92)
   {
      T = 9;
   }
   else if (T >= 92 && T <= 100)
   {
      T = 10;
   }

   /*do 55 bodova - student pao
    * [55,65) bodova - ocjena 6
    * [65,75) bodova - ocjena 7
    * [75,85) bodova - ocjena 8
    * [85,92) boda - ocjena 9
    * [92,100] bodova - ocjena 10*/

   /*Bojan*/
   if (B < 55)
   {
      B = pao;
   }
   else if (B >= 55 && B < 65)
   {
      B = 6;
   }
   else if (B >= 65 && B < 75)
   {
      B = 7;
   }
   else if (B >= 75 && B < 85)
   {
      B = 8;
   }
   else if (B >= 85 && B < 92)
   {
      B = 9;
   }
   else if (B >= 92 && B <= 100)
   {
      B = 10;
   }
   /*Mirza*/
   if (M < 55)
   {
      M = pao;
   }
   else if (B >= 55 && B < 65)
   {
      M = 6;
   }
   else if (B >= 65 && B < 75)
   {
      M = 7;
   }
   else if (B >= 75 && B < 85)
   {
      M = 8;
   }
   else if (B >= 85 && B < 92)
   {
      M = 9;
   }
   else if (B >= 92 && B <= 100)
   {
      M = 10;
   }
   if (T == pao && M == pao && B == pao)
   {
      printf("Nijedan student nije polozio. ");
   }
   else if ((T != pao && M == pao && B == pao) || (T == pao && M != pao && B == pao) || (T == pao && M == pao && B != pao))
   {
      printf("Jedan student je polozio. ");
   }
   else if ((M != pao && T != pao && B == pao) || (M != pao && B != pao && T == pao) || (M == pao && B != pao && T != pao))
   {
      printf("Dva studenta su polozila. ");
   }
   else if (T != pao && M != pao && B != pao)
   {
      printf("Sva tri studenta su polozila. ");
   }
   if ((T == M && M != B && T != B && T != pao && B != pao && M != pao) || (M == B && B != T && M != T && T != pao && B != pao && M != pao) || (B == T && B != M && T != M && T != pao && B != pao && M != pao))
   {
      printf("\nDva od tri studenta imaju istu ocjenu. ");
   }
   else if (T == M && M == B && B == T && T != pao && B != pao && M != pao)
   {
      printf("\nSva tri studenta imaju istu ocjenu. ");
   }
   else if (T != M && T != B && B != M && T != pao && B != pao && M != pao)
   {
      printf("\nSvaki student ima razlicitu ocjenu. ");
   }

   return(0);
}
