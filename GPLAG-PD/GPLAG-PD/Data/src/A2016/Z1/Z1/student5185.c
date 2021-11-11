#include <stdio.h>
#define Max1              10
#define Max2              20
#define Max3              40
#define Min               0
#define donjaGranica6     55
#define donjaGranica7     65
#define donjaGranica8     75
#define donjaGranica9     85
#define donjaGranica10    92

/*uradi testiranje za svaki scenario!!!*/

int main()
{
   /*Deklaracija varijabli*/
   double prvaParcijalaBodoviT, drugaParcijalaBodoviT, prisustvoBodoviT, zadaceBodoviT, zavrsniIspitBodoviT, sumaBodovaT; /*varijable za Tarika*/
   double prvaParcijalaBodoviB, drugaParcijalaBodoviB, prisustvoBodoviB, zadaceBodoviB, zavrsniIspitBodoviB, sumaBodovaB; /*varijable za Bojana*/
   double prvaParcijalaBodoviM, drugaParcijalaBodoviM, prisustvoBodoviM, zadaceBodoviM, zavrsniIspitBodoviM, sumaBodovaM; /*varijable za Mirzu*/
   double brojac = 0;                                                                                                     /*Brojac koji mjeri koliko je studenata polozilo*/
   int    ocjenaT, ocjenaB, ocjenaM;

   /*Unos podataka - Tarik*/
   printf("Unesite bodove za Tarika:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &prvaParcijalaBodoviT);

   if (prvaParcijalaBodoviT > Max2 || prvaParcijalaBodoviT < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &drugaParcijalaBodoviT);

   if (drugaParcijalaBodoviT > Max2 || drugaParcijalaBodoviT < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &prisustvoBodoviT);

   if (prisustvoBodoviT > Max1 || prisustvoBodoviT < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &zadaceBodoviT);

   if (zadaceBodoviT > Max1 || zadaceBodoviT < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsniIspitBodoviT);

   if (zavrsniIspitBodoviT > Max3 || zavrsniIspitBodoviT < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   /*Unos podataka - Bojan*/
   printf("Unesite bodove za Bojana:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &prvaParcijalaBodoviB);

   if (prvaParcijalaBodoviB > Max2 || prvaParcijalaBodoviB < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &drugaParcijalaBodoviB);

   if (drugaParcijalaBodoviB > Max2 || drugaParcijalaBodoviB < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &prisustvoBodoviB);

   if (prisustvoBodoviB > Max1 || prisustvoBodoviB < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &zadaceBodoviB);

   if (zadaceBodoviB > Max1 || zadaceBodoviB < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsniIspitBodoviB);

   if (zavrsniIspitBodoviB > Max3 || zavrsniIspitBodoviB < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   /*Unos podataka - Mirza*/
   printf("Unesite bodove za Mirzu:");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &prvaParcijalaBodoviM);

   if (prvaParcijalaBodoviM > Max2 || prvaParcijalaBodoviM < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%lf", &drugaParcijalaBodoviM);

   if (drugaParcijalaBodoviM > Max2 || drugaParcijalaBodoviM < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Prisustvo: ");
   scanf("%lf", &prisustvoBodoviM);

   if (prisustvoBodoviM > Max1 || prisustvoBodoviM < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zadace: ");
   scanf("%lf", &zadaceBodoviM);

   if (zadaceBodoviM > Max1 || zadaceBodoviM < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsniIspitBodoviM);

   if (zavrsniIspitBodoviM > Max3 || zavrsniIspitBodoviM < Min)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   else
   {
      sumaBodovaT = prvaParcijalaBodoviT + drugaParcijalaBodoviT + prisustvoBodoviT + zadaceBodoviT + zavrsniIspitBodoviT;
      sumaBodovaB = prvaParcijalaBodoviB + drugaParcijalaBodoviB + prisustvoBodoviB + zadaceBodoviB + zavrsniIspitBodoviB;
      sumaBodovaM = prvaParcijalaBodoviM + drugaParcijalaBodoviM + prisustvoBodoviM + zadaceBodoviM + zavrsniIspitBodoviM;

      if (sumaBodovaT >= donjaGranica6)
      {
         brojac++;
      }

      if (sumaBodovaB >= donjaGranica6)
      {
         brojac++;
      }

      if (sumaBodovaM >= donjaGranica6)
      {
         brojac++;
      }

      if (brojac == 0)
      {
         printf("Nijedan student nije polozio.");
      }
      else if (brojac == 1)
      {
         printf("Jedan student je polozio.");
      }
      else if (brojac == 2)
      {
         printf("Dva studenta su polozila.");
      }
      else
      {
         printf("Sva tri studenta su polozila.");

         /*Test da se odredi Tarikovu ocjenu*/
         if (sumaBodovaT >= donjaGranica6 && sumaBodovaT < donjaGranica7)
         {
            ocjenaT = 6;
         }
         else if (sumaBodovaT >= donjaGranica7 && sumaBodovaT < donjaGranica8)
         {
            ocjenaT = 7;
         }
         else if (sumaBodovaT >= donjaGranica8 && sumaBodovaT < donjaGranica9)
         {
            ocjenaT = 8;
         }
         else if (sumaBodovaT >= donjaGranica9 && sumaBodovaT < donjaGranica10)
         {
            ocjenaT = 9;
         }
         else
         {
            ocjenaT = 10;
         }

         /*Test da se odredi Tarikovu ocjenu*/
         if (sumaBodovaT >= donjaGranica6 && sumaBodovaT < donjaGranica7)
         {
            ocjenaT = 6;
         }
         else if (sumaBodovaT >= donjaGranica7 && sumaBodovaT < donjaGranica8)
         {
            ocjenaT = 7;
         }
         else if (sumaBodovaT >= donjaGranica8 && sumaBodovaT < donjaGranica9)
         {
            ocjenaT = 8;
         }
         else if (sumaBodovaT >= donjaGranica9 && sumaBodovaT < donjaGranica10)
         {
            ocjenaT = 9;
         }
         else
         {
            ocjenaT = 10;
         }

         /*Test da se odredi Bojanovu ocjenu*/
         if (sumaBodovaB >= donjaGranica6 && sumaBodovaB < donjaGranica7)
         {
            ocjenaB = 6;
         }
         else if (sumaBodovaB >= donjaGranica7 && sumaBodovaB < donjaGranica8)
         {
            ocjenaB = 7;
         }
         else if (sumaBodovaB >= donjaGranica8 && sumaBodovaB < donjaGranica9)
         {
            ocjenaB = 8;
         }
         else if (sumaBodovaB >= donjaGranica9 && sumaBodovaB < donjaGranica10)
         {
            ocjenaB = 9;
         }
         else
         {
            ocjenaB = 10;
         }


         /*Test da se odredi Mirzinu ocjenu*/
         if (sumaBodovaM >= donjaGranica6 && sumaBodovaM < donjaGranica7)
         {
            ocjenaM = 6;
         }
         else if (sumaBodovaM >= donjaGranica7 && sumaBodovaM < donjaGranica8)
         {
            ocjenaM = 7;
         }
         else if (sumaBodovaM >= donjaGranica8 && sumaBodovaM < donjaGranica9)
         {
            ocjenaM = 8;
         }
         else if (sumaBodovaM >= donjaGranica9 && sumaBodovaM < donjaGranica10)
         {
            ocjenaM = 9;
         }
         else
         {
            ocjenaM = 10;
         }

         /*Provjera ako su iste ocjene*/
         if (ocjenaT == ocjenaB && ocjenaB == ocjenaM)
         {
            printf("\nSva tri studenta imaju istu ocjenu.");
         }
         else if (ocjenaT != ocjenaB && ocjenaB != ocjenaM && ocjenaT != ocjenaM)
         {
            printf("\nSvaki student ima razlicitu ocjenu.");
         }
         else
         {
            printf("\nDva od tri studenta imaju istu ocjenu.");
         }
      }
   }


   return(0);
}
