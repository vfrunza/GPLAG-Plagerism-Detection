#include <stdio.h>
#define E    0.001

int main()
{
   float Ia, IIa, Pa, Za, ZAa, suma;
   float Ib, IIb, Pb, Zb, ZAb, sumb;
   float Ic, IIc, Pc, Zc, ZAc, sumc;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Ia);
   if (Ia > 20 || Ia < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIa);
   if (IIa > 20 || IIa < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Pa);
   if (Pa > 10 || Pa < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Za);
   if (Za > 10 || Za < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZAa);
   if (ZAa > 40 || ZAa < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Ib);
   if (Ib > 20 || Ib < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIb);
   if (IIb > 20 || IIb < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Pb);
   if (Pb > 10 || Pb < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Zb);
   if (Zb > 10 || Zb < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZAb);
   if (ZAb > 40 || ZAb < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &Ic);
   if (Ic > 20 || Ic < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &IIc);
   if (IIc > 20 || IIc < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Pc);
   if (Pc > 10 || Pc < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Zc);
   if (Zc > 10 || Zc < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &ZAc);
   if (ZAc > 40 || ZAc < 0)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   suma = Ia + IIa + ZAa + Za + Pa + E;
   sumb = Ib + IIb + ZAb + Zb + Pb + E;
   sumc = Ic + IIc + ZAc + Zc + Pc + E;
   if (suma >= 55)
   {
      if (sumb >= 55)
      {
         if (sumc >= 55)
         {
            printf("Sva tri studenta su polozila.\n");
         }
         else
         {
            printf("Dva studenta su polozila."); return(0);
         }
      }
      else
      {
         if (sumc >= 55)
         {
            printf("Dva studenta su polozila."); return(0);
         }
         else
         {
            printf("Jedan student je polozio."); return(0);
         }
      }
   }
   else
   {
      if (sumb >= 55)
      {
         if (sumc >= 55)
         {
            printf("Dva studenta su polozila."); return(0);
         }
         else
         {
            printf("Jedan student je polozio."); return(0);
         }
      }
      else
      {
         if (sumc >= 55)
         {
            printf("Jedan student je polozio."); return(0);
         }
         else
         {
            printf("Nijedan student nije polozio."); return(0);
         }
      }
   }
   if (suma >= 55 && suma < 65)
   {
      suma = 6;
   }
   else if (suma >= 65 && suma < 75)
   {
      suma = 7;
   }
   else if (suma >= 75 && suma < 85)
   {
      suma = 8;
   }
   else if (suma >= 85 && suma < 90)
   {
      suma = 9;
   }
   else
   {
      suma = 10;
   }
   if (sumb >= 55 && sumb < 65)
   {
      sumb = 6;
   }
   else if (sumb >= 65 && sumb < 75)
   {
      sumb = 7;
   }
   else if (sumb >= 75 && sumb < 85)
   {
      sumb = 8;
   }
   else if (sumb >= 85 && sumb < 90)
   {
      sumb = 9;
   }
   else
   {
      sumb = 10;
   }
   if (sumc >= 55 && sumc < 65)
   {
      sumc = 6;
   }
   else if (sumc >= 65 && sumc < 75)
   {
      sumc = 7;
   }
   else if (sumc >= 75 && sumc < 85)
   {
      sumc = 8;
   }
   else if (sumc >= 85 && sumc < 90)
   {
      sumc = 9;
   }
   else
   {
      sumc = 10;
   }
   if (suma == sumb)
   {
      if (sumc == suma)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
   }
   else
   {
      if (suma == sumc)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (sumb == sumc)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
