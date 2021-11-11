#include <stdio.h>

int main()
{
   printf("Zadaća 1, Zadatak 1");
   float p1t, p2t, prt, zdt, zit, p1b, p2b, prb, zdb, zib, p1m, p2m, prm, zdm, zim, ukt, ukb, ukm, ocjenat, ocjenab, ocjenam;

   printf("\nUnesite broj bodova za Tarika:");
   printf("\nPrvi parcijalni ispit:");
   scanf("%f", &p1t);
   printf("\nDrugi parcijalni ispit:");
   scanf("%f", &p2t);
   printf("\nPrisustvo:");
   scanf("%f", &prt);
   printf("\nZadaca:");
   scanf("%f", &zdt);
   printf("\nZavrsni ispit:");
   scanf("%f", &zit);
   ukt = p1t + p2t + prt + zdt + zit;
   if (ukt < 55)
   {
      ocjenat = 55;
      printf("Student pao.");
   }
   else
   if (ukt >= 55 && ukt < 65)
   {
      ocjenat = 6;
      printf("Ocjena 6");
   }
   else
   if (ukt >= 65 && ukt < 75)
   {
      ocjenat = 7;
      printf("Ocjena 7");
   }
   else
   if (ukt >= 75 && ukt < 85)
   {
      ocjenat = 8;
      printf("Ocjena 8");
   }
   else
   if (ukt >= 85 && ukt < 92)
   {
      ocjenat = 9,
      printf("Ocjena 9");
   }
   else
   if (ukt >= 92 && ukt <= 100)
   {
      ocjenat = 10;
      printf("Ocjena 10");
   }
   else
   {
      printf("Neispravan broj bodova.");
      return(0);
   }
   printf("\nUnesite broj bodova za Bojana:");
   printf("\nPrvi parcijalni ispit:");
   scanf("%f", &p1b);
   printf("\nDrugi parcijalni ispit:");
   scanf("%f", &p2b);
   printf("\nPrisustvo:");
   scanf("%f", &prb);
   printf("\nZadaca:");
   scanf("%f", &zdb);
   printf("\nZavrsni ispit:");
   scanf("%f", &zib);
   ukb = p1b + p2b + prb + zdb + zib;
   if (ukb < 55)
   {
      ocjenab = 55;
      printf("Student pao.");
   }
   else
   if (ukb >= 55 && ukb < 65)
   {
      ocjenab = 6;
      printf("Ocjena 6");
   }
   else
   if (ukb >= 65 && ukb < 75)
   {
      ocjenab = 7;
      printf("Ocjena 7");
   }
   else
   if (ukb >= 75 && ukb < 85)
   {
      ocjenab = 8;
      printf("Ocjena 8");
   }
   else
   if (ukb >= 85 && ukb < 92)
   {
      ocjenab = 9,
      printf("Ocjena 9");
   }
   else
   if (ukb >= 92 && ukb <= 100)
   {
      ocjenab = 10;
      printf("Ocjena 10");
   }
   else
   {
      printf("Neispravan broj bodova.");
      return(0);
   }
   printf("\nUnesite broj bodova za Mirzu:");
   printf("\nPrvi parcijalni ispit:");
   scanf("%f", &p1m);
   printf("\nDrugi parcijalni ispit:");
   scanf("%f", &p2m);
   printf("\nPrisustvo:");
   scanf("%f", &prm);
   printf("\nZadaca:");
   scanf("%f", &zdm);
   printf("\nZavrsni ispit:");
   scanf("%f", &zim);
   ukm = p1m + p2m + prm + zdm + zim;
   if (ukm < 55)
   {
      ocjenam = 55;
      printf("Student pao.");
   }
   else
   if (ukm >= 55 && ukm < 65)
   {
      ocjenam = 6;
      printf("Ocjena 6");
   }
   else
   if (ukm >= 65 && ukm < 75)
   {
      ocjenam = 7;
      printf("Ocjena 7");
   }
   else
   if (ukm >= 75 && ukm < 85)
   {
      ocjenam = 8;
      printf("Ocjena 8");
   }
   else
   if (ukm >= 85 && ukm < 92)
   {
      ocjenam = 9,
      printf("Ocjena 9");
   }
   else
   if (ukm >= 92 && ukm <= 100)
   {
      ocjenam = 10;
      printf("Ocjena 10");
   }
   else
   {
      printf("Neispravan broj bodova.");
      return(0);
   }
   if (ukt < 55 && ukb < 55 && ukm < 55)
   {
      printf("\nNijedan student nije polozio.");
   }
   if ((ukt > 55 && ukb < 55 && ukm < 55) || (ukt < 55 && ukb > 55 && ukm < 55) || (ukt < 55 && ukb < 55 && ukm > 55))
   {
      printf("\nJedan student je polozio.");
   }
   if ((ukt > 55 && ukb > 55 && ukm < 55) || (ukt > 55 && ukb < 55 && ukm > 55) || (ukt < 55 && ukb > 55 && ukm > 55))
   {
      printf("\nDva studenta su polozila.");
   }
   if (ukt > 55 && ukb > 55 && ukm > 55)
   {
      printf("\nSva tri studenta su polozila.");
   }
   if (ocjenat == ocjenab)
   {
      if (ocjenat == ocjenam)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
   }
   else
   if (ocjenat == ocjenam)
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else
   if (ocjenab == ocjenam)
   {
      printf("\nDva od tri studenta imaju istu ocjenu.");
   }
   else
   {
      printf("\nSva tri studenta imaju razlicitu ocjenu.");
   }

   return(0);
}
