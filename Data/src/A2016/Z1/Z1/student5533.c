#include <stdio.h>

int main()
{
   float sumat = 0, sumab = 0, sumam = 0;
   float pparc = 0, dparc = 0, zavrsni = 0, prisustvo = 0, zadace = 0;
   int   ocjenat = 0, ocjenab = 0, ocjenam = 0;

   printf("Unesite bodove za Tarika: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pparc);
   if (pparc < 0 || pparc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dparc);
   if (dparc < 0 || dparc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo);
   if (prisustvo < 0 || prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadace);
   if (zadace < 0 || zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni);
   if (zavrsni < 0 || zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   sumat = pparc + dparc + zavrsni + zadace + prisustvo;
   if (sumat < 55)
   {
      ocjenat = 5;
   }
   if (sumat >= 55 && sumat < 65)
   {
      ocjenat = 6;
   }
   if (sumat >= 65 && sumat < 75)
   {
      ocjenat = 7;
   }
   if (sumat >= 75 && sumat < 85)
   {
      ocjenat = 8;
   }
   if (sumat >= 85 && sumat < 92)
   {
      ocjenat = 9;
   }
   if (sumat >= 92 && sumat <= 100)
   {
      ocjenat = 10;
   }
   printf("Unesite bodove za Bojana: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pparc);
   if (pparc < 0 || pparc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dparc);
   if (dparc < 0 || dparc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo);
   if (prisustvo < 0 || prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadace);
   if (zadace < 0 || zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni);
   if (zavrsni < 0 || zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   sumab = pparc + dparc + zavrsni + zadace + prisustvo;
   if (sumab < 55)
   {
      ocjenab = 5;
   }
   if (sumab >= 55 && sumab < 65)
   {
      ocjenab = 6;
   }
   if (sumab >= 65 && sumab < 75)
   {
      ocjenab = 7;
   }
   if (sumab >= 75 && sumab < 85)
   {
      ocjenab = 8;
   }
   if (sumab >= 85 && sumab < 92)
   {
      ocjenab = 9;
   }
   if (sumab >= 92 && sumab <= 100)
   {
      ocjenab = 10;
   }
   printf("Unesite bodove za Mirzu: \n");
   printf("I parcijalni ispit: ");
   scanf("%f", &pparc);
   if (pparc < 0 || pparc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &dparc);
   if (dparc < 0 || dparc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo);
   if (prisustvo < 0 || prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadace);
   if (zadace < 0 || zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni);
   if (zavrsni < 0 || zavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   sumam = pparc + dparc + zavrsni + zadace + prisustvo;
   if (sumam < 55)
   {
      ocjenam = 5;
   }
   if (sumam >= 55 && sumam < 65)
   {
      ocjenam = 6;
   }
   if (sumam >= 65 && sumam < 75)
   {
      ocjenam = 7;
   }
   if (sumam >= 75 && sumam < 85)
   {
      ocjenam = 8;
   }
   if (ocjenam >= 85 && ocjenam < 92)
   {
      ocjenam = 9;
   }
   if (sumam >= 92 && sumam >= 100)
   {
      ocjenam = 10;
   }
   if (ocjenat == 5 && ocjenab == 5 && ocjenam == 5)
   {
      printf("Nijedan student nije polozio. ");
   }
   if ((ocjenat != 5 && ocjenab == 5 && ocjenam == 5) || (ocjenab != 5 && ocjenat == 5 && ocjenam == 5) || (ocjenam != 5 && ocjenat == 5 && ocjenab == 5))
   {
      printf("Jedan student je polozio.");
   }
   if ((ocjenat != 5 && ocjenab != 5 && ocjenam == 5) || (ocjenat != 5 && ocjenam != 5 && ocjenab == 5) || (ocjenat == 5 && ocjenab != 5 && ocjenam != 5))
   {
      printf("Dva studenta su polozila.");
   }
   if (ocjenat != 5 && ocjenab != 5 && ocjenam != 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if ((ocjenat == ocjenab) && (ocjenat == ocjenam))
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((ocjenat == ocjenab) && (ocjenat != ocjenam) || (ocjenat == ocjenam) && (ocjenat != ocjenab) || (ocjenab == ocjenam) && (ocjenab != ocjenat))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else if (ocjenat != ocjenab && ocjenat != ocjenam && ocjenab != ocjenam)
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }
   return(0);
}
