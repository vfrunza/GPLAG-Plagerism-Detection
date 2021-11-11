#include <stdio.h>

int main()
{
   double TarikIparc = 0, TarikIIparc = 0, TarikZadace = 0, TarikPrisustvo = 0, TarikZavrsni = 0, TarikBodovi = 0, TarikOcjena = 0;

   double BojanIparc = 0, BojanIIparc = 0, BojanZadace = 0, BojanPrisustvo = 0, BojanZavrsni = 0, BojanBodovi = 0, BojanOcjena = 0;

   double MirzaIparc = 0, MirzaIIparc = 0, MirzaZadace = 0, MirzaPrisustvo = 0, MirzaZavrsni = 0, MirzaBodovi = 0, MirzaOcjena = 0;
   int    Brojpolozenih = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &TarikIparc);
   if (TarikIparc < 0 || TarikIparc > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   TarikBodovi += TarikIparc;
   printf("II parcijalni ispit: ");
   scanf("%lf", &TarikIIparc);
   if (TarikIIparc < 0 || TarikIIparc > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   TarikBodovi += TarikIIparc;
   printf("Prisustvo: ");
   scanf("%lf", &TarikPrisustvo);
   if (TarikPrisustvo < 0 || TarikPrisustvo > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   TarikBodovi += TarikPrisustvo;
   printf("Zadace: ");
   scanf("%lf", &TarikZadace);
   if (TarikZadace < 0 || TarikZadace > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   TarikBodovi += TarikZadace;
   printf("Zavrsni ispit: ");
   scanf("%lf", &TarikZavrsni);
   if (TarikZavrsni < 0 || TarikZavrsni > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   TarikBodovi += TarikZavrsni;

   if (TarikBodovi < 55)
   {
      TarikOcjena = 5;
   }
   if (TarikBodovi >= 55 && TarikBodovi < 65)
   {
      TarikOcjena = 6;
   }
   if (TarikBodovi >= 65 && TarikBodovi < 75)
   {
      TarikOcjena = 7;
   }
   if (TarikBodovi >= 75 && TarikBodovi < 85)
   {
      TarikOcjena = 8;
   }
   if (TarikBodovi >= 85 && TarikBodovi < 92)
   {
      TarikOcjena = 9;
   }
   if (TarikBodovi >= 92 && TarikBodovi <= 100)
   {
      TarikOcjena = 10;
   }

   if (TarikOcjena >= 6)
   {
      Brojpolozenih++;
   }
   //BOJAN
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &BojanIparc);
   if (BojanIparc < 0 || BojanIparc > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   BojanBodovi += BojanIparc;
   printf("II parcijalni ispit: ");
   scanf("%lf", &BojanIIparc);
   if (BojanIIparc < 0 || BojanIIparc > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   BojanBodovi += BojanIIparc;
   printf("Prisustvo: ");
   scanf("%lf", &BojanPrisustvo);
   if (BojanPrisustvo < 0 || BojanPrisustvo > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   BojanBodovi += BojanPrisustvo;
   printf("Zadace: ");
   scanf("%lf", &BojanZadace);
   if (BojanZadace < 0 || BojanZadace > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   BojanBodovi += BojanZadace;
   printf("Zavrsni ispit: ");
   scanf("%lf", &BojanZavrsni);
   if (BojanZavrsni < 0 || BojanZavrsni > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   BojanBodovi += BojanZavrsni;

   if (BojanBodovi < 55)
   {
      BojanOcjena = 5;
   }
   if (BojanBodovi >= 55 && BojanBodovi < 65)
   {
      BojanOcjena = 6;
   }
   if (BojanBodovi >= 65 && BojanBodovi < 75)
   {
      BojanOcjena = 7;
   }
   if (BojanBodovi >= 75 && BojanBodovi < 85)
   {
      BojanOcjena = 8;
   }
   if (BojanBodovi >= 85 && BojanBodovi < 92)
   {
      BojanOcjena = 9;
   }
   if (BojanBodovi >= 92 && BojanBodovi <= 100)
   {
      BojanOcjena = 10;
   }

   if (BojanOcjena >= 6)
   {
      Brojpolozenih++;
   }
   // MIRZA
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &MirzaIparc);
   if (MirzaIparc < 0 || MirzaIparc > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   MirzaBodovi += MirzaIparc;
   printf("II parcijalni ispit: ");
   scanf("%lf", &MirzaIIparc);
   if (MirzaIIparc < 0 || MirzaIIparc > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   MirzaBodovi += MirzaIIparc;
   printf("Prisustvo: ");
   scanf("%lf", &MirzaPrisustvo);
   if (MirzaPrisustvo < 0 || MirzaPrisustvo > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   MirzaBodovi += MirzaPrisustvo;
   printf("Zadace: ");
   scanf("%lf", &MirzaZadace);
   if (MirzaZadace < 0 || MirzaZadace > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   MirzaBodovi += MirzaZadace;
   printf("Zavrsni ispit: ");
   scanf("%lf", &MirzaZavrsni);
   if (MirzaZavrsni < 0 || MirzaZavrsni > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   MirzaBodovi += MirzaZavrsni;

   if (MirzaBodovi < 55)
   {
      MirzaOcjena = 5;
   }
   if (MirzaBodovi >= 55 && MirzaBodovi < 65)
   {
      MirzaOcjena = 6;
   }
   if (MirzaBodovi >= 65 && MirzaBodovi < 75)
   {
      MirzaOcjena = 7;
   }
   if (MirzaBodovi >= 75 && MirzaBodovi < 85)
   {
      MirzaOcjena = 8;
   }
   if (MirzaBodovi >= 85 && MirzaBodovi < 92)
   {
      MirzaOcjena = 9;
   }
   if (MirzaBodovi >= 92 && MirzaBodovi <= 100)
   {
      MirzaOcjena = 10;
   }
   if (MirzaOcjena >= 6)
   {
      Brojpolozenih++;
   }

   if (Brojpolozenih == 0)
   {
      printf("Nijedan student nije polozio.");
   }
   if (Brojpolozenih == 1)
   {
      printf("Jedan student je polozio.");
   }
   if (Brojpolozenih == 2)
   {
      printf("Dva studenta su polozila.");
   }
   if (Brojpolozenih == 3)
   {
      printf("Sva tri studenta su polozila.\n");
      if ((TarikOcjena == BojanOcjena && TarikOcjena != MirzaOcjena) || (TarikOcjena == MirzaOcjena && TarikOcjena != BojanOcjena) || (MirzaOcjena == BojanOcjena && BojanOcjena != TarikOcjena))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (TarikOcjena == BojanOcjena && TarikOcjena == MirzaOcjena)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      if (TarikOcjena != BojanOcjena && TarikOcjena != MirzaOcjena)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }



   return(0);
}
