#include <stdio.h>

int main()
{
   int    tarik, bojan, mirza;
   double I1, I2, P, Z, ZI, O;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &I1);
   if (I1 < 0 || I1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &I2);
   if (I2 < 0 || I2 > 20)
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

   O = I1 + I2 + P + Z + ZI;

   if (O < 55)
   {
      tarik = 5;
   }
   else if (O >= 55 && O < 65)
   {
      tarik = 6;
   }
   else if (O >= 65 && O < 75)
   {
      tarik = 7;
   }
   else if (O >= 75 && O < 85)
   {
      tarik = 8;
   }
   else if (O >= 85 && O < 92)
   {
      tarik = 9;
   }
   else if (O >= 92 && O <= 100)
   {
      tarik = 10;
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &I1);
   if (I1 < 0 || I1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &I2);
   if (I2 < 0 || I2 > 20)
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

   O = I1 + I2 + P + Z + ZI;

   if (O < 55)
   {
      bojan = 5;
   }
   else if (O >= 55 && O < 65)
   {
      bojan = 6;
   }
   else if (O >= 65 && O < 75)
   {
      bojan = 7;
   }
   else if (O >= 75 && O < 85)
   {
      bojan = 8;
   }
   else if (O >= 85 && O < 92)
   {
      bojan = 9;
   }
   else if (O >= 92 && O <= 100)
   {
      bojan = 10;
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &I1);
   if (I1 < 0 || I1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &I2);
   if (I2 < 0 || I2 > 20)
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

   O = I1 + I2 + P + Z + ZI;

   if (O < 55)
   {
      mirza = 5;
   }
   else if (O >= 55 && O < 65)
   {
      mirza = 6;
   }
   else if (O >= 65 && O < 75)
   {
      mirza = 7;
   }
   else if (O >= 75 && O < 85)
   {
      mirza = 8;
   }
   else if (O >= 85 && O < 92)
   {
      mirza = 9;
   }
   else if (O >= 92 && O <= 100)
   {
      mirza = 10;
   }

   if (tarik == 5 && bojan == 5 && mirza == 5)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((tarik == 5 && bojan == 5 && mirza != 5) || (tarik == 5 && bojan != 5 && mirza == 5) || (tarik != 5 && bojan == 5 && mirza == 5))
   {
      printf("Jedan student je polozio.");
   }
   else if ((tarik == 5 && bojan != 5 && mirza != 5) || (tarik != 5 && bojan == 5 && mirza != 5) || (tarik != 5 && bojan != 5 && mirza == 5))
   {
      printf("Dva studenta su polozila.");
   }
   else if (tarik != 5 && bojan != 5 && mirza != 5)
   {
      printf("Sva tri studenta su polozila.");
      if (mirza == tarik && tarik == bojan && mirza == bojan)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (tarik == bojan || tarik == mirza || mirza == bojan)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else if (mirza != tarik && mirza != bojan && bojan != tarik)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
