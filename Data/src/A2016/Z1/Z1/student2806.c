#include <stdio.h>

int main()
{
   double PP, DP, P, Z, ZI, a = 0, PPb, DPb, Pb, Zb, ZIb, b = 0, PPm, DPm, Pm, Zm, ZIm, c = 0;
   int    ocjenaT = 0, ocjenaB = 0, ocjenaM = 0;

   /*TARIK*/
   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &PP);
   if (PP < 0 || PP > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DP);
   if (DP < 0 || DP > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &P);
   if (P < 0 || P > 10)
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
   a = PP + DP + P + Z + ZI;
   if (a < 55)
   {
      ocjenaT = 5;
   }
   else if (a >= 55 && a < 65)
   {
      ocjenaT = 6;
   }
   else if (a >= 65 && a < 75)
   {
      ocjenaT = 7;
   }
   else if (a >= 75 && a < 85)
   {
      ocjenaT = 8;
   }
   else if (a >= 85 && a < 92)
   {
      ocjenaT = 9;
   }
   else
   {
      ocjenaT = 10;
   }

   /*BOJAN*/
   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &PPb);
   if (PPb < 0 || PPb > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DPb);
   if (DPb < 0 || DPb > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Pb);
   if (Pb < 0 || Pb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Zb);
   if (Zb < 0 || Zb > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIb);
   if (ZIb < 0 || ZIb > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   b = PPb + DPb + Pb + Zb + ZIb;
   if (b < 55)
   {
      ocjenaB = 5;
   }
   else if (b >= 55 && b < 65)
   {
      ocjenaB = 6;
   }
   else if (b >= 65 && b < 75)
   {
      ocjenaB = 7;
   }
   else if (b >= 75 && b < 85)
   {
      ocjenaB = 8;
   }
   else if (b >= 85 && b < 92)
   {
      ocjenaB = 9;
   }
   else
   {
      ocjenaB = 10;
   }

   /*MIRZA*/
   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &PPm);
   if (PPm < 0 || PPm > 20)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DPm);
   if (DPm < 0 || DPm > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &Pm);
   if (Pm < 0 || Pm > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &Zm);
   if (Zm < 0 || Zm > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIm);
   if (ZIm < 0 || ZIm > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   c = PPm + DPm + Pm + Zm + ZIm;

   if (c < 55)
   {
      ocjenaM = 5;
   }
   else if (c >= 55 && c < 65)
   {
      ocjenaM = 6;
   }
   else if (c >= 65 && c < 75)
   {
      ocjenaM = 7;
   }
   else if (c >= 75 && c < 85)
   {
      ocjenaM = 8;
   }
   else if (c >= 85 && c < 92)
   {
      ocjenaM = 9;
   }
   else
   {
      ocjenaM = 10;
   }

   if (a >= 55 && b >= 55 && c >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
      if (ocjenaT == ocjenaB && ocjenaB == ocjenaM && ocjenaT == ocjenaM)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (ocjenaT != ocjenaB && ocjenaB != ocjenaM && ocjenaT != ocjenaM)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
      else
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
   }
   else if (a < 55 && b < 55 && c < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if ((a >= 55 && b < 55 && c < 55) || (a < 55 && b >= 55 && c < 55) || (a < 55 && b < 55 && c >= 55))
   {
      printf("Jedan student je polozio.\n ");
   }
   else
   {
      printf("Dva studenta su polozila.\n ");
   }
   return(0);
}
