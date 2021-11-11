#include <stdio.h>

int main()
{
   double Iparc1, IIparc1, prisustvo1, zadace1, zavrsni1, Iparc2, IIparc2, prisustvo2, zadace2, zavrsni2, Iparc3, IIparc3, prisustvo3, zadace3, zavrsni3, bodoviT, bodoviB, bodoviM;
   int    paoT = 0, paoB = 0, paoM = 0, ocjenaT1 = 0, ocjenaT2 = 0, ocjenaT3 = 0, ocjenaT4 = 0, ocjenaT5 = 0, ocjenaB1 = 0, ocjenaB2 = 0, ocjenaB3 = 0, ocjenaB4 = 0, ocjenaB5 = 0, ocjenaM1 = 0, ocjenaM2 = 0, ocjenaM3 = 0, ocjenaM4 = 0, ocjenaM5 = 0;

   /*Tarik*/
   printf("Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &Iparc1);
   if (Iparc1 < 0 || Iparc1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIparc1);
   if (IIparc1 < 0 || IIparc1 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvo1);
   if (prisustvo1 < 0 || prisustvo1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadace1);
   if (zadace1 < 0 || zadace1 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni1);
   if (zavrsni1 < 0 || zavrsni1 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   /*Bojan*/
   printf("Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &Iparc2);
   if (Iparc2 < 0 || Iparc2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIparc2);
   if (IIparc2 < 0 || IIparc2 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvo2);
   if (prisustvo2 < 0 || prisustvo2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadace2);
   if (zadace2 < 0 || zadace2 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni2);
   if (zavrsni2 < 0 || zavrsni2 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   /*Mirza*/
   printf("Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit: ");
   scanf("%lf", &Iparc3);
   if (Iparc3 < 0 || Iparc3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &IIparc3);
   if (IIparc3 < 0 || IIparc3 > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvo3);
   if (prisustvo3 < 0 || prisustvo3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadace3);
   if (zadace3 < 0 || zadace3 > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni3);
   if (zavrsni3 < 0 || zavrsni3 > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   bodoviT = Iparc1 + IIparc1 + prisustvo1 + zadace1 + zavrsni1;
   bodoviB = Iparc2 + IIparc2 + prisustvo2 + zadace2 + zavrsni2;
   bodoviM = Iparc3 + IIparc3 + prisustvo3 + zadace3 + zavrsni3;

   if (bodoviT < 55)
   {
      paoT++;
   }
   else if (bodoviT >= 55 && bodoviT < 65)
   {
      ocjenaT1++;
   }
   else if (bodoviT >= 65 && bodoviT < 75)
   {
      ocjenaT2++;
   }
   else if (bodoviT >= 75 && bodoviT < 85)
   {
      ocjenaT3++;
   }
   else if (bodoviT >= 85 && bodoviT < 92)
   {
      ocjenaT4++;
   }
   else if (bodoviT >= 92 && bodoviT <= 100)
   {
      ocjenaT5++;
   }

   if (bodoviB < 55)
   {
      paoB++;
   }
   else if (bodoviB >= 55 && bodoviB < 65)
   {
      ocjenaB1++;
   }
   else if (bodoviB >= 65 && bodoviB < 75)
   {
      ocjenaB2++;
   }
   else if (bodoviB >= 75 && bodoviB < 85)
   {
      ocjenaB3++;
   }
   else if (bodoviB >= 85 && bodoviB < 92)
   {
      ocjenaB4++;
   }
   else if (bodoviB >= 92 && bodoviB <= 100)
   {
      ocjenaB5++;
   }

   if (bodoviM < 55)
   {
      paoM++;
   }
   else if (bodoviM >= 55 && bodoviM < 65)
   {
      ocjenaM1++;
   }
   else if (bodoviM >= 65 && bodoviM < 75)
   {
      ocjenaM2++;
   }
   else if (bodoviM >= 75 && bodoviM < 85)
   {
      ocjenaM3++;
   }
   else if (bodoviM >= 85 && bodoviM < 92)
   {
      ocjenaM4++;
   }
   else if (bodoviM >= 92 && bodoviM <= 100)
   {
      ocjenaM5++;
   }

   if (paoT == 1 && paoB == 1 && paoM == 1)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((paoT == 1 && paoB == 1) || (paoB == 1 && paoM == 1) || (paoT == 1 && paoM == 1))
   {
      printf("Jedan student je polozio.");
   }
   else if (paoM == 0 && paoB == 0 && paoM == 0)
   {
      printf("Sva tri studenta su polozila.\n");

      if ((ocjenaT1 == 1 && ocjenaB1 == 1 && ocjenaM1 == 1) || (ocjenaT2 == 1 && ocjenaB2 == 1 && ocjenaM2 == 1) || (ocjenaT3 == 1 && ocjenaB3 == 1 && ocjenaM3 == 1) || (ocjenaT4 == 1 && ocjenaB4 == 1 && ocjenaM4 == 1) || (ocjenaT5 == 1 && ocjenaB5 == 1 && ocjenaM5 == 1))
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      else if ((ocjenaT1 == 1 && ocjenaB1 == 1) || (ocjenaB1 == 1 && ocjenaM1 == 1) || (ocjenaT1 == 1 && ocjenaM1 == 1) || (ocjenaT2 == 1 && ocjenaB2 == 1) || (ocjenaB2 == 1 && ocjenaM2 == 1) || (ocjenaT2 == 1 && ocjenaM2 == 1) || (ocjenaT3 == 1 && ocjenaB3 == 1) || (ocjenaB3 == 1 && ocjenaM3 == 1) || (ocjenaT3 == 1 && ocjenaM3 == 1) || (ocjenaT4 == 1 && ocjenaM4 == 1) || (ocjenaM4 == 1 && ocjenaB4 == 1) || (ocjenaT4 == 11 && ocjenaB4 == 1) || (ocjenaT5 == 1 && ocjenaM5 == 1) || (ocjenaM5 == 1 && ocjenaB5 == 1) || (ocjenaT5 == 1 && ocjenaB5 == 1))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }
   else
   {
      printf("Dva studenta su polozila.");
   }

   return(0);
}
