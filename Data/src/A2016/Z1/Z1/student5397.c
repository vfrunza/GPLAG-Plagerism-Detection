#include <stdio.h>

int main()
{
   int    To, Bo, Mo;
   double p1T, p2T, prT, zadT, zavrT, p1B, p2B, prB, zadB, zavrB, p1M, p2M, prM, zadM, zavrM, Tuk, Buk, Muk;

   printf("Unesite bodove za Tarika:\n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &p1T);
   if (p1T < 0 || p1T > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &p2T);
   if (p2T < 0 || p2T > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &prT);
   if (prT < 0 || prT > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &zadT);
   if (zadT < 0 || zadT > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrT);
   if (zavrT < 0 || zavrT > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }


   printf("Unesite bodove za Bojana:\n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &p1B);
   if (p1B < 0 || p1B > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &p2B);
   if (p2B < 0 || p2B > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &prB);
   if (prB < 0 || prB > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &zadB);
   if (zadB < 0 || zadB > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrB);
   if (zavrB < 0 || zavrB > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }


   printf("Unesite bodove za Mirzu:\n");

   printf("I parcijalni ispit: ");
   scanf("%lf", &p1M);
   if (p1M < 0 || p1M > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &p2M);
   if (p2M < 0 || p2M > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &prM);
   if (prM < 0 || prM > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &zadM);
   if (zadM < 0 || zadM > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrM);
   if (zavrM < 0 || zavrM > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   Tuk = p1T + p2T + prT + zadT + zavrT;
   Buk = p1B + p2B + prB + zadB + zavrB;
   Muk = p1M + p2M + prM + zadM + zavrM;

   if (Tuk < 55)
   {
      To = 5;
   }

   else if (Tuk >= 55 && Tuk < 65)
   {
      To = 6;
   }

   else if (Tuk >= 65 && Tuk < 75)
   {
      To = 7;
   }

   else if (Tuk >= 75 && Tuk < 85)
   {
      To = 8;
   }

   else if (Tuk >= 85 && Tuk < 92)
   {
      To = 9;
   }

   else if (Tuk >= 92 && Tuk <= 100)
   {
      To = 10;
   }



   if (Buk < 55)
   {
      Bo = 5;
   }

   else if (Buk >= 55 && Buk < 65)
   {
      Bo = 6;
   }

   else if (Buk >= 65 && Buk < 75)
   {
      Bo = 7;
   }

   else if (Buk >= 75 && Buk < 85)
   {
      Bo = 8;
   }

   else if (Buk >= 85 && Buk < 92)
   {
      Bo = 9;
   }

   else if (Buk >= 92 && Buk <= 100)
   {
      Bo = 10;
   }



   if (Muk < 55)
   {
      Mo = 5;
   }

   else if (Muk >= 55 && Muk < 65)
   {
      Mo = 6;
   }

   else if (Muk >= 65 && Muk < 75)
   {
      Mo = 7;
   }

   else if (Muk >= 75 && Muk < 85)
   {
      Mo = 8;
   }

   else if (Muk >= 85 && Muk < 92)
   {
      Mo = 9;
   }

   else if (Muk >= 92 && Muk <= 100)
   {
      Mo = 10;
   }

   if (To == 5 && Bo == 5 && Mo == 5)
   {
      printf("Nijedan student nije polozio.\n");
   }

   else if (To > 5 && Bo == 5 && Mo == 5)
   {
      printf("Jedan student je polozio.\n");
   }

   else if (To == 5 && Bo > 5 && Mo == 5)
   {
      printf("Jedan student je polozio.\n");
   }

   else if (To == 5 && Bo == 5 && Mo > 5)
   {
      printf("Jedan student je polozio.\n");
   }

   else if (To > 5 && Bo > 5 && Mo == 5)
   {
      printf("Dva studenta su polozila.\n");
   }

   else if (To > 5 && Bo == 5 && Mo > 5)
   {
      printf("Dva studenta su polozila.\n");
   }

   else if (To == 5 && Bo > 5 && Mo > 5)
   {
      printf("Dva studenta su polozila.\n");
   }

   else if (To > 5 && Bo > 5 && Mo > 5)
   {
      printf("Sva tri studenta su polozila.\n");

      if (To == Bo && Bo == Mo)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }

      else if (To == Bo && Bo != Mo)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }

      else if (To != Bo && Bo == Mo)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }

      else if (To != Bo && Bo != Mo)
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }

   return(0);
}
