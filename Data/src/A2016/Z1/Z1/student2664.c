#include <stdio.h>

int main()
{
   double PP1, DP1, P1, ZAD1, ZI1;
   double PP2, DP2, P2, ZAD2, ZI2;
   double PP3, DP3, P3, ZAD3, ZI3;
   double BR1, BR2, BR3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &PP1);
   if (PP1 < 0 || PP1 > 20)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DP1);
   if (DP1 < 0 || DP1 > 20)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &P1);
   if (P1 < 0 || P1 > 10)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZAD1);
   if (ZAD1 < 0 || ZAD1 > 10)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI1);
   if (ZI1 < 0 || ZI1 > 40)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &PP2);
   if (PP2 < 0 || PP2 > 20)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DP2);
   if (DP2 < 0 || DP2 > 20)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &P2);
   if (P2 < 0 || P2 > 10)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZAD2);
   if (ZAD2 < 0 || ZAD2 > 10)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI2);
   if (ZI2 < 0 || ZI2 > 40)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }


   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &PP3);
   if (PP3 < 0 || PP3 > 20)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &DP3);
   if (PP3 < 0 || PP3 > 20)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &P3);
   if (P3 < 0 || P3 > 10)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZAD3);
   if (ZAD3 < 0 || ZAD3 > 10)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZI3);
   if (ZI3 < 0 || ZI3 > 40)
   {
      printf("Neispravan broj bodova ");
      return(0);
   }


   BR1 = PP1 + DP1 + P1 + ZAD1 + ZI1;
   BR2 = PP2 + DP2 + P2 + ZAD2 + ZI2;
   BR3 = PP3 + DP3 + P3 + ZAD3 + ZI3;

   if (BR1 < 55 && BR2 < 55 && BR3 < 55)
   {
      printf("Nijedan student nije polozio. ");
   }
   else if (BR1 >= 55 && BR2 >= 55 && BR3 >= 55)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else if ((BR1 >= 55 && BR2 < 55 && BR3 < 55) || (BR1 < 55 && BR2 >= 55 && BR3 < 55) || (BR1 < 55 && BR2 < 55 && BR3 >= 55))
   {
      printf("Jedan student je polozio. ");
   }
   else
   {
      printf("Dva studenta su polozila.");
   }

   if (BR1 >= 55 && BR2 >= 55 && BR3 >= 55)
   {
      if ((BR1 >= 55 && BR1 < 65 && BR2 >= 55 && BR2 < 65 && BR3 >= 55 && BR3 < 65) || (BR1 >= 65 && BR1 < 75 && BR2 >= 65 && BR2 < 75 && BR3 >= 65 && BR3 < 75) ||
          (BR1 >= 75 && BR1 < 85 && BR2 >= 75 && BR2 < 85 && BR3 >= 75 && BR3 < 85) || (BR1 >= 85 && BR1 < 92 && BR2 >= 85 && BR2 < 92 && BR3 >= 85 && BR3 > 92) ||
          (BR1 >= 92 && BR1 <= 100 && BR2 >= 92 && BR2 <= 100 && BR3 >= 92 && BR3 <= 100))
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (
         (BR1 >= 55 && BR1 < 65 && BR2 >= 55 && BR2 < 65 && BR3 >= 65 && BR3 < 75) ||
         (BR1 >= 55 && BR1 < 65 && BR2 >= 55 && BR2 < 65 && BR3 >= 75 && BR3 < 85) ||
         (BR1 >= 55 && BR1 < 65 && BR2 >= 55 && BR2 < 65 && BR3 >= 85 && BR3 < 92) ||
         (BR1 >= 55 && BR1 < 65 && BR2 >= 55 && BR2 < 65 && BR3 <= 92 && BR3 <= 100) ||

         (BR1 >= 65 && BR1 < 75 && BR2 >= 65 && BR2 < 75 && BR3 >= 55 && BR3 < 65) ||
         (BR1 >= 65 && BR1 < 75 && BR2 >= 65 && BR2 < 75 && BR3 >= 75 && BR3 < 85) ||
         (BR1 >= 65 && BR1 < 75 && BR2 >= 65 && BR2 < 75 && BR3 >= 85 && BR3 < 92) ||
         (BR1 >= 65 && BR1 < 75 && BR2 >= 65 && BR2 < 75 && BR3 <= 92 && BR3 <= 100) ||

         (BR1 >= 75 && BR1 < 85 && BR2 >= 75 && BR2 < 85 && BR3 >= 55 && BR3 < 65) ||
         (BR1 >= 75 && BR1 < 85 && BR2 >= 75 && BR2 < 85 && BR3 >= 65 && BR3 < 75) ||
         (BR1 >= 75 && BR1 < 85 && BR2 >= 75 && BR2 < 85 && BR3 >= 85 && BR3 < 92) ||
         (BR1 >= 75 && BR1 < 85 && BR2 >= 75 && BR2 < 85 && BR3 <= 92 && BR3 <= 100) ||

         (BR1 >= 85 && BR1 < 92 && BR2 >= 85 && BR2 < 92 && BR3 >= 55 && BR3 < 65) ||
         (BR1 >= 85 && BR1 < 92 && BR2 >= 85 && BR2 < 92 && BR3 >= 65 && BR3 < 75) ||
         (BR1 >= 85 && BR1 < 92 && BR2 >= 85 && BR2 < 92 && BR3 >= 75 && BR3 < 85) ||
         (BR1 >= 85 && BR1 < 92 && BR2 >= 85 && BR2 < 92 && BR3 <= 92 && BR3 <= 100) ||

         /*11(BR1>=92 && BR1<=100 && BR2>=92 && BR2<=100 && BR3>=55 && BR3<55) ||
          * /*12*/(BR1 >= 92 && BR1 <= 100 && BR2 >= 92 && BR2 <= 100 && BR3 >= 65 && BR3 < 75) ||
         /*13*/ (BR1 >= 92 && BR1 <= 100 && BR2 >= 92 && BR2 <= 100 && BR3 >= 75 && BR3 < 85) ||
         /*14*/ (BR1 >= 92 && BR1 <= 100 && BR2 >= 92 && BR2 <= 100 && BR3 >= 85 && BR3 < 92) ||


         /*11*/ (BR1 >= 55 && BR1 < 65 && BR2 >= 65 && BR2 < 75 && BR3 >= 55 && BR3 < 65) ||
         /*12*/ (BR1 >= 55 && BR1 < 65 && BR2 >= 75 && BR2 < 85 && BR3 >= 55 && BR3 < 65) ||
         /*13*/ (BR1 >= 55 && BR1 < 65 && BR2 >= 85 && BR2 < 92 && BR3 >= 55 && BR3 < 65) ||
         /*14*/ (BR1 >= 55 && BR1 < 65 && BR2 >= 92 && BR2 < 100 && BR3 >= 55 && BR3 <= 65) ||

         /*21*/ (BR1 >= 65 && BR1 < 75 && BR2 >= 55 && BR2 < 65 && BR3 >= 65 && BR3 < 75) ||
         /*22*/ (BR1 >= 65 && BR1 < 75 && BR2 >= 75 && BR2 < 85 && BR3 >= 65 && BR3 < 75) ||
         /*23*/ (BR1 >= 65 && BR1 < 75 && BR2 >= 85 && BR2 < 92 && BR3 >= 65 && BR3 < 75) ||
         /*24*/ (BR1 >= 65 && BR1 < 75 && BR2 >= 92 && BR2 <= 100 && BR3 >= 65 && BR3 < 75) ||

         /*11*/ (BR1 >= 75 && BR1 < 85 && BR2 >= 55 && BR2 < 65 && BR3 >= 75 && BR3 < 85) ||
         (BR1 >= 75 && BR1 < 85 && BR2 >= 65 && BR2 < 75 && BR3 >= 75 && BR3 < 85) ||
         (BR1 >= 75 && BR1 < 85 && BR2 >= 85 && BR2 < 92 && BR3 >= 75 && BR3 < 85) ||
         (BR1 >= 75 && BR1 < 85 && BR2 >= 92 && BR2 <= 100 && BR3 >= 75 && BR3 < 85) ||

         (BR1 >= 85 && BR1 < 92 && BR2 >= 55 && BR2 < 65 && BR3 >= 85 && BR3 < 92) ||
         (BR1 >= 85 && BR1 < 92 && BR2 >= 65 && BR2 < 75 && BR3 >= 85 && BR3 < 92) ||
         (BR1 >= 85 && BR1 < 92 && BR2 >= 75 && BR2 < 85 && BR3 >= 85 && BR3 < 92) ||
         (BR1 >= 85 && BR1 < 92 && BR2 >= 92 && BR2 <= 100 && BR3 >= 85 && BR3 < 92) ||

         (BR1 >= 92 && BR1 <= 100 && BR2 >= 55 && BR2 < 65 && BR3 >= 92 && BR3 <= 100) ||
         (BR1 >= 92 && BR1 <= 100 && BR2 >= 65 && BR2 < 75 && BR3 >= 92 && BR3 <= 100) ||
         (BR1 >= 92 && BR1 <= 100 && BR2 >= 75 && BR2 < 85 && BR3 >= 92 && BR3 <= 100) ||
         (BR1 >= 92 && BR1 <= 100 && BR2 >= 85 && BR2 < 92 && BR3 >= 92 && BR3 <= 100) ||


         (BR1 >= 65 && BR1 < 75 && BR2 >= 55 && BR2 < 65 && BR3 >= 55 && BR3 < 65) ||
         (BR1 >= 75 && BR1 < 85 && BR2 >= 55 && BR2 < 65 && BR3 >= 55 && BR3 < 65) ||
         (BR1 >= 85 && BR1 < 92 && BR2 >= 55 && BR2 < 65 && BR3 >= 55 && BR3 < 65) ||
         (BR1 >= 92 && BR1 <= 100 && BR2 >= 55 && BR2 < 65 && BR3 >= 55 && BR3 < 65) ||

         (BR1 >= 55 && BR1 < 65 && BR2 >= 65 && BR2 < 75 && BR3 >= 65 && BR3 < 75) ||
         (BR1 >= 75 && BR1 < 85 && BR2 >= 65 && BR2 < 75 && BR3 >= 65 && BR3 < 75) ||
         (BR1 >= 85 && BR1 < 92 && BR2 >= 65 && BR2 < 75 && BR3 >= 65 && BR3 < 75) ||
         (BR1 >= 92 && BR1 <= 100 && BR2 >= 65 && BR2 < 75 && BR3 >= 65 && BR3 < 75) ||

         (BR1 >= 55 && BR1 < 65 && BR2 >= 75 && BR2 < 85 && BR3 >= 75 && BR3 < 85) ||
         (BR1 >= 65 && BR1 < 75 && BR2 >= 75 && BR2 < 85 && BR3 >= 75 && BR3 < 85) ||
         (BR1 >= 85 && BR1 < 92 && BR2 >= 75 && BR2 < 85 && BR3 >= 75 && BR3 < 85) ||
         (BR1 >= 92 && BR1 <= 100 && BR2 >= 75 && BR2 < 85 && BR3 >= 75 && BR3 < 85) ||

         (BR1 >= 55 && BR1 < 65 && BR2 >= 85 && BR2 < 92 && BR3 >= 85 && BR3 < 92) ||
         (BR1 >= 65 && BR1 < 75 && BR2 >= 85 && BR2 < 92 && BR3 >= 85 && BR3 < 92) ||
         (BR1 >= 75 && BR1 < 85 && BR2 >= 85 && BR2 < 92 && BR3 >= 85 && BR3 < 92) ||
         (BR1 >= 92 && BR1 <= 100 && BR2 >= 85 && BR2 < 92 && BR3 >= 85 && BR3 < 92) ||

         (BR1 >= 55 && BR1 <= 65 && BR2 >= 92 && BR2 <= 100 && BR3 >= 92 && BR3 <= 100) ||
         (BR1 >= 65 && BR1 <= 75 && BR2 >= 92 && BR2 <= 100 && BR3 >= 92 && BR3 <= 100) ||
         (BR1 >= 75 && BR1 <= 85 && BR2 >= 92 && BR2 <= 100 && BR3 >= 92 && BR3 <= 100) ||
         (BR1 >= 85 && BR1 <= 92 && BR2 >= 92 && BR2 <= 100 && BR3 >= 92 && BR3 <= 100))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }



   return(0);
}
