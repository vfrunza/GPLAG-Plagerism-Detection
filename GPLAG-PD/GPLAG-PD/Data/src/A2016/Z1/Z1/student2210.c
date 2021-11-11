#include <stdio.h>
#define E    0.0001

int main()
{
   float PP1_T, PP2_T, ZAD_T, ZAV_T, PRI_T, Zbir_T, PP1_B, PP2_B, ZAD_B, ZAV_B, PRI_B, Zbir_B, PP1_M, PP2_M, ZAD_M, ZAV_M, PRI_M, Zbir_M, Ocjena_T, Ocjena_B, Ocjena_M;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit:");
   scanf("%f", &PP1_T);
   if ((PP1_T < 0 || PP1_T > 20))
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%f", &PP2_T);
   if ((PP2_T >= 0 && PP2_T <= 20))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%f", &PRI_T);
   if ((PRI_T >= 0 && PRI_T <= 10))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%f", &ZAD_T);
   if ((ZAD_T >= 0 && ZAD_T <= 10))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%f", &ZAV_T);
   if ((ZAV_T >= 0 && ZAV_T <= 40))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit:");
   scanf("%f", &PP1_B);
   if ((PP1_B >= 0 && PP1_B <= 20))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%f", &PP2_B);
   if ((PP2_B >= 0 && PP2_B <= 20))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%f", &PRI_B);
   if ((PRI_B >= 0 && PRI_B <= 10))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%f", &ZAD_B);
   if ((ZAD_B >= 0 && ZAD_B <= 10))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%f", &ZAV_B);
   if ((ZAV_B >= 0 && ZAV_B <= 40))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit:");
   scanf("%f", &PP1_M);
   if ((PP1_M >= 0 && PP1_M <= 20))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%f", &PP2_M);
   if ((PP2_M >= 0 && PP2_M <= 20))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%f", &PRI_M);
   if ((PRI_M >= 0 && PRI_M <= 10))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%f", &ZAD_M);
   if ((ZAD_M >= 0 && ZAD_M <= 10))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%f", &ZAV_M);
   if ((ZAV_M >= 0 && ZAV_M <= 40))
   {
      ;
   }
   else
   {
      printf(" Neispravan broj bodova");
      return(0);
   }

   Zbir_T = (PP1_T + PP2_T + ZAD_T + PRI_T + ZAV_T + E);

   if (Zbir_T >= 0.00 && Zbir_T < 55.00)
   {
   }
   if (Zbir_T >= 55.00 && Zbir_T < 65.00)
   {
      Ocjena_T = 6;
   }
   if (Zbir_T >= 65.00 && Zbir_T < 75.00)
   {
      Ocjena_T = 7;
   }
   if (Zbir_T >= 75.00 && Zbir_T < 85.00)
   {
      Ocjena_T = 8;
   }
   if (Zbir_T >= 85.00 && Zbir_T < 92.00)
   {
      Ocjena_T = 9;
   }
   if (Zbir_T >= 92.00 && Zbir_T <= 100.00)
   {
      Ocjena_T = 10;
   }


   Zbir_B = (PP1_B + PP2_B + ZAD_B + PRI_B + ZAV_B);

   if (Zbir_B >= 0.00 && Zbir_B < 55.00)
   {
   }
   if (Zbir_B >= 55.00 && Zbir_B < 65.00)
   {
      Ocjena_B = 6;
   }
   if (Zbir_B >= 65.00 && Zbir_B < 75.00)
   {
      Ocjena_B = 7;
   }
   if (Zbir_B >= 75.00 && Zbir_B < 85.00)
   {
      Ocjena_B = 8;
   }
   if (Zbir_B >= 85.00 && Zbir_B < 92.00)
   {
      Ocjena_B = 9;
   }
   if (Zbir_B >= 92.00 && Zbir_B < 100.00)
   {
      Ocjena_B = 10;
   }

   Zbir_M = (PP1_M + PP2_M + ZAD_M + PRI_M + ZAV_M);

   if (Zbir_M >= 0.00 && Zbir_M < 55.00)
   {
   }
   if (Zbir_M >= 55.00 && Zbir_M < 65.00)
   {
      Ocjena_M = 6;
   }
   if (Zbir_M >= 65.00 && Zbir_M < 75.00)
   {
      Ocjena_M = 7;
   }
   if (Zbir_M >= 75.00 && Zbir_M < 85.00)
   {
      Ocjena_M = 8;
   }
   if (Zbir_M >= 85.00 && Zbir_M < 92.00)
   {
      ;
      Ocjena_M = 9;
   }
   if (Zbir_M >= 92.00 && Zbir_M < 100.00)
   {
      Ocjena_M = 10;
   }
   if ((Zbir_T < 55.00) && (Zbir_B < 55.00) && (Zbir_M < 55.00))
   {
      printf(" Nijedan student nije polozio. \n");
   }

   if ((Zbir_T < 55.00) && (Zbir_B < 55.00) && (Zbir_M >= 55.00))
   {
      printf(" Jedan student je polozio. ");
   }
   if ((Zbir_T < 55.00) && (Zbir_B >= 55.00) && (Zbir_M < 55.00))
   {
      printf(" Jedan student je polozio.");
   }
   if ((Zbir_T >= 55.00) && (Zbir_B < 55.00) && (Zbir_M < 55.00))
   {
      printf(" Jedan student je polozio.");
   }
   if ((Zbir_T < 55.00) && (Zbir_B >= 55.00) && (Zbir_M >= 55.00))
   {
      printf(" Dva studenta su polozila.");
   }

   if ((Zbir_T >= 55.00) && (Zbir_B < 55.00) && (Zbir_M >= 55.00))
   {
      printf(" Dva studenta su polozila.");
   }
   if ((Zbir_T >= 55.00) && (Zbir_B >= 55.00) && (Zbir_M < 55.00))
   {
      printf(" Dva studenta su polozila.");
   }
   if ((Zbir_T >= 55.00) && (Zbir_B >= 55.00) && (Zbir_M >= 55.00))
   {
      printf(" Sva tri studenta su polozila. \n");

      if ((Ocjena_T == Ocjena_B) && (Ocjena_B == Ocjena_M))
      {
         printf("Sva tri studenta imaju istu ocjenu. \n");
      }
      if ((Ocjena_T != Ocjena_B) && (Ocjena_B != Ocjena_M) && (Ocjena_M != Ocjena_T))
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      if ((Ocjena_T != Ocjena_B && Ocjena_T != Ocjena_M && Ocjena_B == Ocjena_M) || (Ocjena_B != Ocjena_T && Ocjena_B != Ocjena_M && Ocjena_T == Ocjena_M) || (Ocjena_M != Ocjena_T && Ocjena_M != Ocjena_B && Ocjena_T == Ocjena_B))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }

   return(0);
}
