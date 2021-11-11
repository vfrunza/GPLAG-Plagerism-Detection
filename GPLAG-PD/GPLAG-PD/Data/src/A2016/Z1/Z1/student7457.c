#include <stdio.h>
#define pet        55
#define sest       65
#define sedam      75
#define osam       85
#define devet      92
#define deset      100
#define epsilon    0.005
struct prijatelj
{
   float Ipi;                           //max 20
   float IIpi;                          //max 20
   float Prisustvo;                     //max 10
   float Zadace;                        //max 10
   float ZavrsniIspit;                  //max 40
   float UkupnoBodova;                  //svi ispiti zbrojeni
   int   Ocjena;                        //ocjena na predmetu
};
void ocjena(float brojBodova, int *ocjena)
{
   int a = (brojBodova * 100 + 0.005);

   brojBodova = a / 100;
   if (brojBodova < pet)
   {
      *ocjena = 5;
   }
   else if (brojBodova < sest)
   {
      *ocjena = 6;
   }
   else if (brojBodova < sedam)
   {
      *ocjena = 7;
   }
   else if (brojBodova < osam)
   {
      *ocjena = 8;
   }
   else if (ocjena < devet)
   {
      *ocjena = 9;
   }
   else if (ocjena <= deset)
   {
      *ocjena = 10;
   }
}

int main()
{
   //printf("Zadaca 1, Zadatak 1");
   struct prijatelj Tarik, Mirza, Bojan;

   printf("Unesite bodove za Tarika: ");
   //Unosenje bodova za Tareta
   printf("\nI parcijalni ispit: ");
   scanf("%f", &Tarik.Ipi);
   if (Tarik.Ipi < 0 || Tarik.Ipi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &Tarik.IIpi);
   if (Tarik.IIpi < 0 || Tarik.IIpi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Tarik.Prisustvo);
   if (Tarik.Prisustvo < 0 || Tarik.Prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Tarik.Zadace);
   if (Tarik.Zadace < 0 || Tarik.Zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Tarik.ZavrsniIspit);
   if (Tarik.ZavrsniIspit < 0 || Tarik.ZavrsniIspit > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: ");
   //Unosenje bodova za Booju
   printf("\nI parcijalni ispit: ");
   scanf("%f", &Bojan.Ipi);
   if (Bojan.Ipi < 0 || Bojan.Ipi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &Bojan.IIpi);
   if (Bojan.IIpi < 0 || Bojan.IIpi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Bojan.Prisustvo);
   if (Bojan.Prisustvo < 0 || Bojan.Prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Bojan.Zadace);
   if (Bojan.Zadace < 0 || Bojan.Zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Bojan.ZavrsniIspit);
   if (Bojan.ZavrsniIspit < 0 || Bojan.ZavrsniIspit > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu: ");
   //Unosenje bodova za Mizuu
   printf("\nI parcijalni ispit: ");
   scanf("%f", &Mirza.Ipi);
   if (Mirza.Ipi < 0 || Mirza.Ipi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &Mirza.IIpi);
   if (Mirza.IIpi < 0 || Mirza.IIpi > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &Mirza.Prisustvo);
   if (Mirza.Prisustvo < 0 || Mirza.Prisustvo > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%f", &Mirza.Zadace);
   if (Mirza.Zadace < 0 || Mirza.Zadace > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%f", &Mirza.ZavrsniIspit);
   if (Mirza.ZavrsniIspit < 0 || Mirza.ZavrsniIspit > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   //racunanje ukupnih bodova za dodjeljivanje ocjena
   Tarik.UkupnoBodova = Tarik.Ipi + Tarik.IIpi + Tarik.Prisustvo + Tarik.Zadace + Tarik.ZavrsniIspit;
   Bojan.UkupnoBodova = Bojan.Ipi + Bojan.IIpi + Bojan.Prisustvo + Bojan.Zadace + Bojan.ZavrsniIspit;
   Mirza.UkupnoBodova = Mirza.Ipi + Mirza.IIpi + Mirza.Prisustvo + Mirza.Zadace + Mirza.ZavrsniIspit;

   //dodjeljivanje ocjena 5-10
   ocjena(Tarik.UkupnoBodova, &Tarik.Ocjena);
   ocjena(Bojan.UkupnoBodova, &Bojan.Ocjena);
   ocjena(Mirza.UkupnoBodova, &Mirza.Ocjena);

   int brojacProlaznosti = 0;

   if (Tarik.Ocjena > 5)
   {
      brojacProlaznosti++;
   }
   if (Bojan.Ocjena > 5)
   {
      brojacProlaznosti++;
   }
   if (Mirza.Ocjena > 5)
   {
      brojacProlaznosti++;
   }
   if (brojacProlaznosti == 0)
   {
      printf("Nijedan student nije polozio.");
   }
   if (brojacProlaznosti == 1)
   {
      printf("Jedan student je polozio.");
   }
   if (brojacProlaznosti == 2)
   {
      printf("Dva studenta su polozila.");
   }
   if (brojacProlaznosti == 3)
   {
      printf("Sva tri studenta su polozila.\n");
      int brojacOcjena = 0;
      if (Tarik.Ocjena == Bojan.Ocjena)
      {
         brojacOcjena++;
      }
      if (Tarik.Ocjena == Mirza.Ocjena)
      {
         brojacOcjena++;
      }
      if (Bojan.Ocjena == Mirza.Ocjena)
      {
         brojacOcjena++;
      }

      if (brojacOcjena == 0)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      if (brojacOcjena == 1)
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (brojacOcjena == 3)                    //ne moze biti 2 ako je samo 1 ista onda je to 1, a ako je 2 to znaci da je i treca relacija tocna pa ce se povecati na 3
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
   }
   return(0);
}
