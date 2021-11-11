#include <stdio.h>

int ocjena(double prvi, double drugi, double prisustvo, double zadace, double zavrsni)
{
   double total = prvi + drugi + prisustvo + zadace + zavrsni;

   if (total < 55)
   {
      return(5);
   }
   else if (total < 65)
   {
      return(6);
   }
   else if (total < 75)
   {
      return(7);
   }
   else if (total < 85)
   {
      return(8);
   }
   else if (total < 92)
   {
      return(9);
   }
   else
   {
      return(10);
   }
}

int okBodovi(double a, double max)
{
   return(a >= 0 && a <= max);
}

int main()
{
   double prviT, drugiT, prisustvoT, zadaceT, zavrsniT;
   double prviB, drugiB, prisustvoB, zadaceB, zavrsniB;
   double prviM, drugiM, prisustvoM, zadaceM, zavrsniM;

   int ocjenaT, ocjenaB, ocjenaM, palo = 0;

   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");  scanf("%lf", &prviT);
   if (!okBodovi(prviT, 20))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &drugiT);
   if (!okBodovi(drugiT, 20))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Prisustvo: ");                   scanf("%lf", &prisustvoT);
   if (!okBodovi(prisustvoT, 10))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zadace: ");                      scanf("%lf", &zadaceT);
   if (!okBodovi(zadaceT, 10))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zavrsni ispit: ");               scanf("%lf", &zavrsniT);
   if (!okBodovi(zavrsniT, 40))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }

   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");  scanf("%lf", &prviB);
   if (!okBodovi(prviB, 20))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &drugiB);
   if (!okBodovi(drugiB, 20))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Prisustvo: ");                   scanf("%lf", &prisustvoB);
   if (!okBodovi(prisustvoB, 10))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zadace: ");                      scanf("%lf", &zadaceB);
   if (!okBodovi(zadaceB, 10))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zavrsni ispit: ");               scanf("%lf", &zavrsniB);
   if (!okBodovi(zavrsniB, 40))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }

   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");  scanf("%lf", &prviM);
   if (!okBodovi(prviM, 20))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("II parcijalni ispit: "); scanf("%lf", &drugiM);
   if (!okBodovi(drugiM, 20))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Prisustvo: ");                   scanf("%lf", &prisustvoM);
   if (!okBodovi(prisustvoM, 10))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zadace: ");                      scanf("%lf", &zadaceM);
   if (!okBodovi(zadaceM, 10))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }
   printf("Zavrsni ispit: ");               scanf("%lf", &zavrsniM);
   if (!okBodovi(zavrsniM, 40))
   {
      printf("Neispravan broj bodova\n"); return(0);
   }

   ocjenaT = ocjena(prviT, drugiT, prisustvoT, zadaceT, zavrsniT);
   ocjenaB = ocjena(prviB, drugiB, prisustvoB, zadaceB, zavrsniB);
   ocjenaM = ocjena(prviM, drugiM, prisustvoM, zadaceM, zavrsniM);

   if (ocjenaT == 5)
   {
      ++palo;
   }
   if (ocjenaB == 5)
   {
      ++palo;
   }
   if (ocjenaM == 5)
   {
      ++palo;
   }

   if (palo == 0)
   {
      printf("Sva tri studenta su polozila.\n");

      if (ocjenaT == ocjenaB && ocjenaB == ocjenaM)
      {
         printf("Sva tri studenta imaju istu ocjenu.\n");
      }
      else if (ocjenaT == ocjenaB || ocjenaT == ocjenaM || ocjenaM == ocjenaB)
      {
         printf("Dva od tri studenta imaju istu ocjenu.\n");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.\n");
      }
   }
   else if (palo == 1)
   {
      printf("Dva studenta su polozila.\n");
   }
   else if (palo == 2)
   {
      printf("Jedan student je polozio.");
   }
   else if (palo == 3)
   {
      printf("Nijedan student nije polozio.");
   }

   return(0);
}
