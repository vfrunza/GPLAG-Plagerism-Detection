#include <stdio.h>

int main()
{
   double T_parc1, T_parc2, T_pris, T_zadace, T_zavrsni, T_ukupno, B_parc1, B_parc2, B_pris, B_zadace, B_zavrsni, B_ukupno, M_parc1, M_parc2, M_pris, M_zadace, M_zavrsni, M_ukupno;
   int    polozen = 0;
   int    T_ocjena = 1; int B_ocjena = 1; int M_ocjena = 1;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &T_parc1);
   if (T_parc1 < 0 || T_parc1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &T_parc2);
   if (T_parc2 < 0 || T_parc2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &T_pris);
   if (T_pris < 0 || T_pris > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &T_zadace);
   if (T_zadace < 0 || T_zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &T_zavrsni);
   if (T_zavrsni < 0 || T_zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   T_ukupno = T_parc1 + T_parc2 + T_pris + T_zadace + T_zavrsni;
   if (T_ukupno >= 55)
   {
      polozen++;
   }
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &B_parc1);
   if (B_parc1 < 0 || B_parc1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &B_parc2);
   if (B_parc2 < 0 || B_parc2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &B_pris);
   if (B_pris < 0 || B_pris > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &B_zadace);
   if (B_zadace < 0 || B_zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &B_zavrsni);
   if (B_zavrsni < 0 || B_zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   B_ukupno = B_parc1 + B_parc2 + B_pris + B_zadace + B_zavrsni;
   if (B_ukupno >= 55)
   {
      polozen++;
   }
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &M_parc1);
   if (M_parc1 < 0 || M_parc1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &M_parc2);
   if (M_parc2 < 0 || M_parc2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &M_pris);
   if (M_pris < 0 || M_pris > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &M_zadace);
   if (M_zadace < 0 || M_zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &M_zavrsni);
   if (M_zavrsni < 0 || M_zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   M_ukupno = M_parc1 + M_parc2 + M_pris + M_zadace + M_zavrsni;
   if (M_ukupno >= 55)
   {
      polozen++;
   }
   switch (polozen)
   {
   case 1:
      printf("Jedan student je polozio.");
      break;

   case 2:
      printf("Dva studenta su polozila.");
      break;

   case 3:
      printf("Sva tri studenta su polozila.");
      break;

   default:
      printf("Nijedan student nije polozio.");
   }
   if (T_ukupno >= 55 && T_ukupno < 65)
   {
      T_ocjena = 6;
   }
   else if (T_ukupno >= 65 && T_ukupno < 75)
   {
      T_ocjena = 7;
   }
   else if (T_ukupno >= 75 && T_ukupno < 85)
   {
      T_ocjena = 8;
   }
   else if (T_ukupno >= 85 && T_ukupno < 92)
   {
      T_ocjena = 9;
   }
   else
   {
      T_ocjena = 10;
   }
   if (B_ukupno >= 55 && B_ukupno < 65)
   {
      B_ocjena = 6;
   }
   else if (B_ukupno >= 65 && B_ukupno < 75)
   {
      B_ocjena = 7;
   }
   else if (B_ukupno >= 75 && B_ukupno < 85)
   {
      B_ocjena = 8;
   }
   else if (B_ukupno >= 85 && B_ukupno < 92)
   {
      B_ocjena = 9;
   }
   else
   {
      B_ocjena = 10;
   }
   if (M_ukupno >= 55 && M_ukupno < 65)
   {
      M_ocjena = 6;
   }
   else if (M_ukupno >= 65 && M_ukupno < 75)
   {
      M_ocjena = 7;
   }
   else if (M_ukupno >= 75 && M_ukupno < 85)
   {
      M_ocjena = 8;
   }
   else if (M_ukupno >= 85 && M_ukupno < 92)
   {
      M_ocjena = 9;
   }
   else
   {
      M_ocjena = 10;
   }
   if (polozen != 3)
   {
      return(0);
   }
   else
   {
      if (T_ocjena == B_ocjena && B_ocjena == M_ocjena)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (T_ocjena == B_ocjena && B_ocjena != M_ocjena)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
