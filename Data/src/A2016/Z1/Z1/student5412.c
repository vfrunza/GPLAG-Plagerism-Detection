#include <stdio.h>

int main()
{
   double IP, IIP, P, Z, ZI, IP1, IIP1, P1, Z1, ZI1, IP2, IIP2, Z2, P2, ZI2;

   printf("Unesite bodove za Tarika:\n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &IP);
   if (IP < 0 || IP > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &IIP);
   if (IIP < 0 || IIP > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &P);
   if (P < 0 || P > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &Z);
   if (Z < 0 || Z > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI);
   if (ZI < 0 || ZI > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Unesite bodove za Bojana:\n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &IP1);
   if (IP1 < 0 || IP1 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &IIP1);
   if (IIP1 < 0 || IIP1 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &P1);
   if (P1 < 0 || P1 > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &Z1);
   if (Z1 < 0 || Z1 > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI1);
   if (ZI1 < 0 || ZI1 > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Unesite bodove za Mirzu:\n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &IP2);
   if (IP2 < 0 || IP2 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &IIP2);
   if (IIP2 < 0 || IIP2 > 20)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &P2);
   if (P2 < 0 || P2 > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &Z2);
   if (Z2 < 0 || Z2 > 10)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI2);
   if (ZI2 < 0 || ZI2 > 40)
   {
      printf("Neispravan broj bodova\n");
      return(0);
   }

   double zbir, zbir1, zbir2;

   zbir  = IP + IIP + Z + P + ZI;
   zbir1 = IP1 + IIP1 + Z1 + P1 + ZI1;
   zbir2 = IP2 + IIP2 + Z2 + P2 + ZI2;

   if (zbir < 55 && zbir1 < 55 && zbir2 < 55)
   {
      printf("Nijedan student nije polozio.\n");
   }
   else if ((zbir >= 55 || zbir <= 100) || (zbir1 >= 55 || zbir1 <= 100) || (zbir2 >= 55 || zbir2 <= 100))
   {
      printf("Sva tri studenta su polozila.\n");
      if (((zbir >= 55 && zbir < 65) || (zbir >= 65 && zbir < 75) || (zbir >= 75 && zbir < 85) || (zbir >= 85 || zbir < 92) || (zbir >= 92 || zbir <= 100)) ||
          ((zbir1 >= 55 && zbir1 < 65) || (zbir1 >= 65 && zbir1 < 75) || (zbir1 >= 75 && zbir1 < 85) || (zbir1 >= 85 || zbir1 < 92) || (zbir1 >= 92 || zbir1 <= 100)) ||
          ((zbir2 >= 55 && zbir2 < 65) || (zbir2 >= 65 && zbir2 < 75) || (zbir2 >= 75 && zbir2 < 85) || (zbir2 >= 85 || zbir2 < 92) || (zbir2 >= 92 || zbir2 <= 100)))
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (((zbir >= 55 && zbir < 65) || (zbir >= 65 && zbir < 75) || (zbir >= 75 && zbir < 85) || (zbir >= 85 || zbir < 92) || (zbir >= 92 || zbir <= 100)) ||
               ((zbir1 >= 55 && zbir1 < 65) || (zbir1 >= 65 && zbir1 < 75) || (zbir1 >= 75 && zbir1 < 85) || (zbir1 >= 85 || zbir1 < 92) || (zbir1 >= 92 || zbir1 <= 100)) ||
               ((zbir2 >= 55 && zbir2 < 65) || (zbir2 >= 65 && zbir2 < 75) || (zbir2 >= 75 && zbir2 < 85) || (zbir2 >= 85 || zbir2 < 92) || (zbir2 >= 92 || zbir2 <= 100)))
      {
         if (((zbir - zbir1 == 0) || (zbir1 - zbir2 == 0) || (zbir - zbir2 != 0)) || ((zbir - zbir1 != 0) || (zbir1 - zbir2 == 0) || (zbir2 - zbir == 0)) || ((zbir - zbir1 == 0) || (zbir1 - zbir2 != 0) || (zbir2 - zbir == 0)))
         {
            printf("Dva od tri studenta imaju istu ocjenu.");
         }
      }
      else if (((zbir >= 55 && zbir < 65) || (zbir >= 65 && zbir < 75) || (zbir >= 75 && zbir < 85) || (zbir >= 85 || zbir < 92) || (zbir >= 92 || zbir <= 100)) ||
               ((zbir1 >= 55 && zbir1 < 65) || (zbir1 >= 65 && zbir1 < 75) || (zbir1 >= 75 && zbir1 < 85) || (zbir1 >= 85 || zbir1 < 92) || (zbir1 >= 92 || zbir1 <= 100)) ||
               ((zbir2 >= 55 && zbir2 < 65) || (zbir2 >= 65 && zbir2 < 75) || (zbir2 >= 75 && zbir2 < 85) || (zbir2 >= 85 || zbir2 < 92) || (zbir2 >= 92 || zbir2 <= 100)))
      {
         if (((zbir - zbir1 != 0) || (zbir1 - zbir2 != 0) || (zbir - zbir2 != 0)) || ((zbir - zbir1 != 0) || (zbir1 - zbir2 != 0) || (zbir2 - zbir != 0)) || ((zbir - zbir1 != 0) || (zbir1 - zbir2 != 0) || (zbir2 - zbir != 0)))
         {
            printf("Svaki student ima različitu ocjenu.");
         }
      }
   }
   else if (((zbir >= 55 && zbir < 65) || (zbir >= 65 && zbir < 75) || (zbir >= 75 && zbir < 85) || (zbir >= 85 || zbir < 92) || (zbir >= 92 || zbir <= 100)) ||
            ((zbir1 >= 55 && zbir1 < 65) || (zbir1 >= 65 && zbir1 < 75) || (zbir1 >= 75 && zbir1 < 85) || (zbir1 >= 85 || zbir1 < 92) || (zbir1 >= 92 || zbir1 <= 100)) ||
            ((zbir2 >= 55 && zbir2 < 65) || (zbir2 >= 65 && zbir2 < 75) || (zbir2 >= 75 && zbir2 < 85) || (zbir2 >= 85 || zbir2 < 92) || (zbir2 >= 92 || zbir2 <= 100)))
   {
      if (((zbir - zbir1 == 0) || (zbir1 - zbir2 != 0) || (zbir - zbir2 != 0)) || ((zbir - zbir1 != 0) || (zbir1 - zbir2 == 0) || (zbir2 - zbir != 0)) || ((zbir - zbir1 != 0) || (zbir1 - zbir2 != 0) || (zbir2 - zbir == 0)))
      {
         printf("Jedan student je polozio.\n");
      }
   }
   else if (((zbir >= 55 && zbir < 65) || (zbir >= 65 && zbir < 75) || (zbir >= 75 && zbir < 85) || (zbir >= 85 || zbir < 92) || (zbir >= 92 || zbir <= 100)) ||
            ((zbir1 >= 55 && zbir1 < 65) || (zbir1 >= 65 && zbir1 < 75) || (zbir1 >= 75 && zbir1 < 85) || (zbir1 >= 85 || zbir1 < 92) || (zbir1 >= 92 || zbir1 <= 100)) ||
            ((zbir2 >= 55 && zbir2 < 65) || (zbir2 >= 65 && zbir2 < 75) || (zbir2 >= 75 && zbir2 < 85) || (zbir2 >= 85 || zbir2 < 92) || (zbir2 >= 92 || zbir2 <= 100)))
   {
      if (((zbir - zbir1 == 0) || (zbir1 - zbir2 == 0) || (zbir - zbir2 != 0)) || ((zbir - zbir1 != 0) || (zbir1 - zbir2 == 0) || (zbir2 - zbir == 0)) || ((zbir - zbir1 == 0) || (zbir1 - zbir2 != 0) || (zbir2 - zbir == 0)))
      {
         printf("Dva studenta su polozila.\n");
      }
   }
   return(0);
}
