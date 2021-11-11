#include <stdio.h>
#include <math.h>
#define EPS    0.001

int main()
{
   int   ocjenaTarik = 0, ocjenaBojan = 0, ocjenaMirza = 0;
   float tarikPrvaParc = 0, tarikDrugaParc = 0;
   float bojanPrvaParc = 0, bojanDrugaParc = 0;
   float mirzaPrvaParc = 0, mirzaDrugaParc = 0;
   float tarikPrisustvo = 0, bojanPrisustvo = 0, mirzaPrisustvo = 0;
   float tarikZadace = 0, bojanZadace = 0, mirzaZadace = 0;
   float tarikZavrsni = 0, bojanZavrsni = 0, mirzaZavrsni = 0;
   float suma = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: "); scanf("%f", &tarikPrvaParc);
   if (tarikPrvaParc < 0 || tarikPrvaParc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: "); scanf("%f", &tarikDrugaParc);
   if (tarikDrugaParc < 0 || tarikDrugaParc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: "); scanf("%f", &tarikPrisustvo);
   if (tarikPrisustvo < 0 || tarikPrisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: "); scanf("%f", &tarikZadace);
   if (tarikZadace < 0 || tarikZadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: "); scanf("%f", &tarikZavrsni);
   if (tarikZavrsni < 0 || tarikZavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   suma  = tarikPrvaParc * 1000. + tarikDrugaParc * 1000. + tarikPrisustvo * 1000. + tarikZadace * 1000. + tarikZavrsni * 1000.;
   suma /= 1000.;
   if (suma < 55)
   {
      ocjenaTarik = 5;
   }
   else if (suma < 65)
   {
      ocjenaTarik = 6;
   }
   else if (suma < 75)
   {
      ocjenaTarik = 7;
   }
   else if (suma < 85)
   {
      ocjenaTarik = 8;
   }
   else if (suma < 92)
   {
      ocjenaTarik = 9;
   }
   else if (suma <= 100)
   {
      ocjenaTarik = 10;
   }
   else
   {
      printf("Ne valja suma\n");
   }

   /* Bojan */

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: "); scanf("%f", &bojanPrvaParc);
   if (bojanPrvaParc < 0 || bojanPrvaParc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: "); scanf("%f", &bojanDrugaParc);
   if (bojanDrugaParc < 0 || bojanDrugaParc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: "); scanf("%f", &bojanPrisustvo);
   if (bojanPrisustvo < 0 || bojanPrisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: "); scanf("%f", &bojanZadace);
   if (bojanZadace < 0 || bojanZadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: "); scanf("%f", &bojanZavrsni);
   if (bojanZavrsni < 0 || bojanZavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   suma  = bojanPrvaParc * 1000. + bojanDrugaParc * 1000. + bojanPrisustvo * 1000. + bojanZadace * 1000. + bojanZavrsni * 1000.;
   suma /= 1000.;
   if (suma < 55)
   {
      ocjenaBojan = 5;
   }
   else if (suma < 65)
   {
      ocjenaBojan = 6;
   }
   else if (suma < 75)
   {
      ocjenaBojan = 7;
   }
   else if (suma < 85)
   {
      ocjenaBojan = 8;
   }
   else if (suma < 92)
   {
      ocjenaBojan = 9;
   }
   else if (suma <= 100)
   {
      ocjenaBojan = 10;
   }
   else
   {
      printf("Ne valja suma\n");
   }

   /* Mirza */

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: "); scanf("%f", &mirzaPrvaParc);
   if (mirzaPrvaParc < 0 || mirzaPrvaParc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: "); scanf("%f", &mirzaDrugaParc);
   if (mirzaDrugaParc < 0 || mirzaDrugaParc > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: "); scanf("%f", &mirzaPrisustvo);
   if (mirzaPrisustvo < 0 || mirzaPrisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: "); scanf("%f", &mirzaZadace);
   if (mirzaZadace < 0 || mirzaZadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: "); scanf("%f", &mirzaZavrsni);
   if (mirzaZavrsni < 0 || mirzaZavrsni > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   suma  = mirzaPrvaParc * 1000. + mirzaDrugaParc * 1000. + mirzaPrisustvo * 1000. + mirzaZadace * 1000. + mirzaZavrsni * 1000.;
   suma /= 1000.;
   if (suma < 55)
   {
      ocjenaMirza = 5;
   }
   else if (suma < 65)
   {
      ocjenaMirza = 6;
   }
   else if (suma < 75)
   {
      ocjenaMirza = 7;
   }
   else if (suma < 85)
   {
      ocjenaMirza = 8;
   }
   else if (suma < 92)
   {
      ocjenaMirza = 9;
   }
   else if (suma <= 100)
   {
      ocjenaMirza = 10;
   }
   else
   {
      printf("Ne valja suma\n");
   }

   // Ispisivanje poruka

   if (ocjenaTarik > 5 && ocjenaBojan > 5 && ocjenaMirza > 5)
   {
      printf("Sva tri studenta su polozila.\n");
      if (ocjenaTarik == ocjenaBojan && ocjenaTarik == ocjenaMirza)
      {
         printf("Sva tri studenta imaju istu ocjenu");
      }
      else if (ocjenaTarik == ocjenaBojan || ocjenaTarik == ocjenaMirza || ocjenaBojan == ocjenaMirza)
      {
         printf("Dva od tri studenta imaju istu ocjenu");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu");
      }
   }
   else if (ocjenaTarik > 5 && (ocjenaBojan > 5 || ocjenaMirza > 5))
   {
      printf("Dva studenta su polozila");
   }
   else if (ocjenaMirza > 5 && (ocjenaTarik > 5 || ocjenaBojan > 5))
   {
      printf("Dva studenta su polozila");
   }
   else if (ocjenaBojan > 5 && (ocjenaTarik > 5 || ocjenaMirza > 5))
   {
      printf("Dva studenta su polozila");
   }
   else if (ocjenaTarik > 5 || ocjenaBojan > 5 || ocjenaMirza > 5)
   {
      printf("Jedan student je polozio");
   }
   else
   {
      printf("Nijedan student nije polozio");
   }
   printf(".");
   return(0);
}
