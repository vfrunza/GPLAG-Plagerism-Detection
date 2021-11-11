#include <stdio.h>
int main()
{
   double IP1T, IP2T, ZT, PT, ZIT, IP1B, IP2B, ZB, ZIB, PB, IP1M, IP2M, ZM, PM, ZIM;
   int    oc1 = 0, oc2 = 0, oc3 = 0;


   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IP1T);
   if (IP1T < 0 || IP1T > 20)
   {
      printf("Nesipravan broj bodova. \n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IP2T);
   if (IP2T < 0 || IP2T > 20)
   {
      printf("Nesipravan broj bodova. \n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PT);
   if (PT < 0 || PT > 10)
   {
      printf("Neispravan broj bodova. \n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZT);
   if (ZT < 0 || ZT > 10)
   {
      printf("Neispravan broj bodova. \n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIT);
   if (ZIT < 0 || ZIT > 40)
   {
      printf("Neispravan broj bodova. \n");
      return(0);
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IP1B);
   if (IP1B < 0 || IP1B > 20)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IP2B);
   if (IP2B < 0 || IP2B > 20)
   {
      printf("Neispravan broj bodova. \n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PB);
   if (PB < 0 || PB > 10)
   {
      printf("Neispravan broj bodova. \n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZB);
   if (ZB < 0 || ZB > 10)
   {
      printf("Neispravan broj bodova. \n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIB);
   if (ZIB < 0 || ZIB > 40)
   {
      printf("Neispravan broj bodova. \n");
      return(0);
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &IP1M);
   if (IP1M < 0 || IP1M > 20)
   {
      printf("Nesipravan broj bodova. \n");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IP2M);
   if (IP2M < 0 || IP2M > 20)
   {
      printf("Nesipravan broj bodova. \n");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &PM);
   if (PM < 0 || PM > 10)
   {
      printf("Neispravan broj bodova \n");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &ZM);
   if (ZM < 0 || ZM > 10)
   {
      printf("Neispravan broj bodova. \n");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &ZIM);
   if (ZIM < 0 || ZIM > 40)
   {
      printf("Neispravan broj bodova. \n");
      return(0);
   }

   oc1 = IP1T + IP2T + PT + ZT + ZIT;
   oc2 = IP1B + IP2B + PB + ZB + ZIB;
   oc3 = IP1M + IP2M + PM + ZM + ZIM;


   if (oc1 < 55)
   {
      oc1 = 5;
   }
   else if (oc1 >= 55 && oc1 < 65)
   {
      oc1 = 6;
   }
   else if (oc1 >= 65 && oc1 < 75)
   {
      oc1 = 7;
   }
   else if (oc1 >= 75 && oc1 < 85)
   {
      oc1 = 8;
   }
   else if (oc1 >= 85 && oc1 < 92)
   {
      oc1 = 9;
   }
   else if (oc1 >= 92 && oc1 <= 100)
   {
      oc1 = 10;
   }

   if (oc2 < 55)
   {
      oc2 = 5;
   }
   if (oc2 >= 55 && oc2 < 65)
   {
      oc2 = 6;
   }
   else if (oc2 >= 65 && oc2 < 75)
   {
      oc2 = 7;
   }
   else if (oc2 >= 75 && oc2 < 85)
   {
      oc2 = 8;
   }
   else if (oc2 >= 85 && oc2 < 92)
   {
      oc2 = 9;
   }
   else if (oc2 >= 92 && oc2 <= 100)
   {
      oc2 = 10;
   }

   if (oc3 < 55)
   {
      oc3 = 5;
   }
   if (oc3 >= 55 && oc3 < 65)
   {
      oc3 = 6;
   }
   else if (oc3 >= 65 && oc3 < 75)
   {
      oc3 = 7;
   }
   else if (oc3 >= 75 && oc3 < 85)
   {
      oc3 = 8;
   }
   else if (oc3 >= 85 && oc3 < 92)
   {
      oc3 = 9;
   }
   else if (oc3 >= 92 && oc3 <= 100)
   {
      oc3 = 10;
   }

   if (oc1 == 5 && oc2 == 5 && oc3 == 5)
   {
      printf("Nijedan student nije polozio.");
      return(0);
   }


   if ((oc1 > 5 && oc2 == 5 && oc3 == 5) || (oc1 == 5 && oc2 > 5 && oc3 == 5) || (oc1 == 5 && oc2 == 5 && oc3 > 5))
   {
      printf("Jedan student je polozio.");
      return(0);
   }


   if (oc1 > 5 && oc2 > 5 && oc3 > 5)
   {
      printf("Sva tri studenta su polozila.\n");

      if ((oc1 == oc2) && (oc2 == oc3) && (oc1 == oc3))
      {
         printf("Sva tri studenta imaju istu ocjenu.");
         return(0);
      }

      else if ((oc1 != oc2) && (oc2 != oc3) && (oc1 != oc3))
      {
         printf("Svaki student ima razlicitu ocjenu.");
         return(0);
      }
   }



   if (oc1 > 5 && oc2 > 5 && oc3 == 5)
   {
      printf("Dva studenta su polozila. \n");
      return(0);
   }
   if (oc1 > 5 && oc2 == 5 && oc3 > 5)
   {
      printf("Dva studenta su polozila. \n");
      return(0);
   }
   if (oc1 == 5 && oc2 > 5 && oc3 > 5)
   {
      printf("Dva studenta su polozila. \n");
      return(0);
   }

   if (oc1 == oc2 && oc1 != oc3 && oc2 != oc3)
   {
      printf("Dva od tri studenta imaju istu ocjenu. \n");
      return(0);
   }
   if (oc2 == oc3 && oc2 != oc1 && oc3 != oc1)
   {
      printf("Dva od tri studenta ima istu ocjenu. \n");
      return(0);
   }
   if (oc1 == oc3 && oc1 != oc2 && oc2 != oc3)
   {
      printf("Dva od tri studenta imaju istu ocjenu. \n");
      return(0);
   }

   return(0);
}
