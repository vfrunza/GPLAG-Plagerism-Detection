#include <stdio.h>

/* 1. Tri prijatelja - Tarik, Bojan i Mirza - odlučili su da uporede svoj uspjeh na predmetu Osnove računarstva.
 * Njima je potreban program koji omogućuje unos bodova po kategorijama: I parcijalni ispit (max. 20 bodova),
 * II parcijalni ispit (max. 20 bodova), Prisustvo (max. 10 bodova), Zadaće  (max. 10 bodova) i Završni ispit (max. 40 bodova).
 * Broj bodova može imati i decimalni dio. U slučaju da se unese negativan broj bodova ili veći od dozvoljenog,
 * program treba ispisati poruku "Neispravan broj bodova" (bez navodnika) i prekinuti rad programa.
 *
 * Ako su svi bodovi uneseni ispravno, nakon unosa treba odrediti ocjene za svakog studenta po važećoj skali:
 * do 55 bodova - student pao
 * [55,65) bodova - ocjena 6
 * [65,75) bodova - ocjena 7
 * [75,85) bodova - ocjena 8
 * [85,92) boda - ocjena 9
 * [92,100] bodova - ocjena 10
 *
 * Potrebno je ispisati jednu od sljedećih poruka ovisno o situaciji:
 * Nijedan student nije položio.
 * Jedan student je položio.
 * Dva studenta su položila.
 * Sva tri studenta su položila.
 * Te ako su sva tri studenta položila, u sljedećem redu ispisati jednu od poruka:
 * Sva tri studenta imaju istu ocjenu.
 * Dva od tri studenta imaju istu ocjenu.
 * Svaki student ima različitu ocjenu.
 * Primjer ulaza i izlaza:
 *      Unesite bodove za Tarika:
 *      I parcijalni ispit: 18
 *      II parcijalni ispit: 15
 *      Prisustvo: 9
 *      Zadace: 5
 *      Zavrsni ispit: 30
 *      Unesite bodove za Bojana:
 *      I parcijalni ispit: 12
 *      ...
 *      Sva tri studenta su polozila.
 *      Svaki student ima razlicitu ocjenu.
 *
 */
int main()
{
   double pp1, dp1, pris1, zadace1, zISPIT1;
   double pp2, dp2, pris2, zadace2, zISPIT2;
   double pp3, dp3, pris3, zadace3, zISPIT3;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &pp1); if (pp1 < 0 || pp1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dp1); if (dp1 < 0 || dp1 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pris1); if (pris1 < 0 || pris1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadace1); if (zadace1 < 0 || zadace1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zISPIT1); if (zISPIT1 < 0 || zISPIT1 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &pp2); if (pp2 < 0 || pp2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dp2); if (dp2 < 0 || dp2 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pris2); if (pris2 < 0 || pris2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadace2); if (zadace2 < 0 || zadace2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zISPIT2); if (zISPIT2 < 0 || zISPIT2 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &pp3); if (pp3 < 0 || pp3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &dp3); if (dp3 < 0 || dp3 > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &pris3); if (pris3 < 0 || pris3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadace3); if (zadace3 < 0 || zadace3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zISPIT3); if (zISPIT3 < 0 || zISPIT3 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }



   /*
    * if(pris1<0 || pris1>10 || pris2<0 || pris2>10 || pris3<0 || pris3>10) { printf("Neispravan broj bodova"); return 0; }
    * else if(zadace1<0 || zadace1>10 || zadace2<0 || zadace2>10 || zadace3<0 || zadace3>10) { printf("Neispravan broj bodova"); return 0; }
    * else if(pp1<0 || pp1>20 || pp2<0 || pp2>20 || pp3<0 || pp3>20) { printf("Neispravan broj bodova"); return 0; }
    * else if(dp1<0 || dp1>20 || dp2<0 || dp2>20 || dp3<0 || dp3>20) { printf("Neispravan broj bodova"); return 0; }
    * else if(zISPIT1<0 || zISPIT1>40 || zISPIT2<0 || zISPIT2>40 || zISPIT3<0 || zISPIT3>40) { printf("Neispravan broj bodova"); return 0; }
    *     else { } */
   int brojac1 = 0, brojac2 = 0, brojac3 = 0, brojac4 = 0, brojac5 = 0;

   int poloz = 0;

   double suma1, suma2, suma3;

   suma1 = pp1 + dp1 + pris1 + zadace1 + zISPIT1;
   suma2 = pp2 + dp2 + pris2 + zadace2 + zISPIT2;
   suma3 = pp3 + dp3 + pris3 + zadace3 + zISPIT3;

   // printf("%g %g %g\n", suma1, suma2, suma3);

   if (suma1 >= 55 && suma1 < 65)
   {
      brojac1++; poloz++;
   }
   else if (suma1 >= 65 && suma1 < 75)
   {
      brojac2++; poloz++;
   }
   else if (suma1 >= 75 && suma1 < 85)
   {
      brojac3++; poloz++;
   }
   else if (suma1 >= 85 && suma1 < 92)
   {
      brojac4++; poloz++;
   }
   else if (suma1 >= 92 && suma1 <= 100)
   {
      brojac5++; poloz++;
   }

   if (suma2 >= 55 && suma2 < 65)
   {
      brojac1++;  poloz++;
   }
   else if (suma2 >= 65 && suma2 < 75)
   {
      brojac2++; poloz++;
   }
   else if (suma2 >= 75 && suma2 < 85)
   {
      brojac3++; poloz++;
   }
   else if (suma2 >= 85 && suma2 < 92)
   {
      brojac4++; poloz++;
   }
   else if (suma2 >= 92 && suma2 <= 100)
   {
      brojac5++; poloz++;
   }

   if (suma3 >= 55 && suma3 < 65)
   {
      brojac1++; poloz++;
   }
   else if (suma3 >= 65 && suma3 < 75)
   {
      brojac2++; poloz++;
   }
   else if (suma3 >= 75 && suma3 < 85)
   {
      brojac3++; poloz++;
   }
   else if (suma3 >= 85 && suma3 < 92)
   {
      brojac4++; poloz++;
   }
   else if (suma3 >= 92 && suma3 <= 100)
   {
      brojac5++; poloz++;
   }


   if (poloz == 1)
   {
      printf("Jedan student je polozio.\n");
   }
   else if (poloz == 2)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (poloz == 3)
   {
      printf("Sva tri studenta su polozila.\n");
   }
   else
   {
      printf("Nijedan student nije polozio.\n");
   }

   if (suma1 >= 55 && suma2 >= 55 && suma3 >= 55)
   {
      if (brojac1 == 3 || brojac2 == 3 || brojac3 == 3 || brojac4 == 3 || brojac5 == 3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if (brojac1 == 2 || brojac2 == 2 || brojac3 == 2 || brojac4 == 2 || brojac5 == 2)
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
