#include <stdio.h>

int main()
{
   float PR, DR, P, ZA, ZAI, UKUPNO, PR1, DR1, P1, ZA1, ZAI1, UKUPNO1, PR2, DR2, P2, ZA2, ZAI2, UKUPNO2;
   int   tarik_ocjena = 5, bojan_ocjena = 5, mirza_ocjena = 5;

   printf(" Unesite bodove za Tarika:\n");
   printf("I parcijalni ispit:");
   scanf("%f", &PR);
   if (PR < 0 || PR > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%f", &DR);
   if (DR < 0 || DR > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%f", &P);
   if (P < 0 || P > 10)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%f", &ZA);
   if (ZA < 0 || ZA > 10)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%f", &ZAI);
   if (ZAI < 0 || ZAI > 40)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }

   UKUPNO = PR + DR + P + ZA + ZAI;
   printf(" Unesite bodove za Bojana:\n");
   printf("I parcijalni ispit:");
   scanf("%f", &PR1);
   if (PR1 < 0 || PR1 > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%f", &DR1);
   if (DR1 < 0 || DR1 > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%f", &P1);
   if (P1 < 0 || P1 > 10)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%f", &ZA1);
   if (ZA1 < 0 || ZA1 > 10)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%f", &ZAI1);
   if (ZAI1 < 0 || ZAI1 > 40)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }

   UKUPNO1 = PR1 + DR1 + P1 + ZA1 + ZAI1;
   printf(" Unesite bodove za Mirzu:\n");
   printf("I parcijalni ispit:");
   scanf("%f", &PR2);
   if (PR2 < 0 || PR2 > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" II parcijalni ispit:");
   scanf("%f", &DR2);
   if (DR2 < 0 || DR2 > 20)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Prisustvo:");
   scanf("%f", &P2);
   if (P2 < 0 || P2 > 10)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zadace:");
   scanf("%f", &ZA2);
   if (ZA2 < 0 || ZA2 > 10)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }
   printf(" Zavrsni ispit:");
   scanf("%f", &ZAI2);
   if (ZAI2 < 0 || ZAI2 > 40)
   {
      printf(" Neispravan broj bodova");
      return(0);
   }

   UKUPNO2 = PR2 + DR2 + P2 + ZA2 + ZAI2;
   if (UKUPNO < 55 && UKUPNO1 < 55 && UKUPNO2 < 55)
   {
      printf(" Nijedan student nije polozio.\n");
   }
   else if ((UKUPNO > 54 && UKUPNO1 < 55 && UKUPNO2 < 55) || (UKUPNO < 55 && UKUPNO1 > 54 && UKUPNO2 < 55) || (UKUPNO2 > 54 && UKUPNO1 < 55 && UKUPNO < 55))
   {
      printf(" Jedan student je polozio.\n");
   }
   else if ((UKUPNO > 54 && UKUPNO1 > 54 && UKUPNO2 < 55) || (UKUPNO < 55 && UKUPNO1 > 54 && UKUPNO2 > 54) || (UKUPNO2 > 54 && UKUPNO1 < 55 && UKUPNO > 54))
   {
      printf(" Dva studenta su polozila.\n");
   }
   else
   {
      printf(" Sva tri studenta su polozila.\n");
      if (UKUPNO < 65)
      {
         tarik_ocjena = 6;
      }
      else if (UKUPNO < 75)
      {
         tarik_ocjena = 7;
      }
      else if (UKUPNO < 85)
      {
         tarik_ocjena = 8;
      }
      else if (UKUPNO < 92)
      {
         tarik_ocjena = 9;
      }
      else
      {
         tarik_ocjena = 10;
      }
      if (UKUPNO1 < 65)
      {
         bojan_ocjena = 6;
      }
      else if (UKUPNO1 < 75)
      {
         bojan_ocjena = 7;
      }
      else if (UKUPNO1 < 85)
      {
         bojan_ocjena = 8;
      }
      else if (UKUPNO1 < 92)
      {
         bojan_ocjena = 9;
      }
      else
      {
         bojan_ocjena = 10;
      }
      if (UKUPNO2 < 65)
      {
         mirza_ocjena = 6;
      }
      else if (UKUPNO2 < 75)
      {
         mirza_ocjena = 7;
      }
      else if (UKUPNO2 < 85)
      {
         mirza_ocjena = 8;
      }
      else if (UKUPNO2 < 92)
      {
         mirza_ocjena = 9;
      }
      else
      {
         mirza_ocjena = 10;
      }
      if (tarik_ocjena != mirza_ocjena && mirza_ocjena != bojan_ocjena && tarik_ocjena != bojan_ocjena)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
      else if ((tarik_ocjena != mirza_ocjena && mirza_ocjena == bojan_ocjena) || (mirza_ocjena != tarik_ocjena && tarik_ocjena == bojan_ocjena) || (bojan_ocjena != tarik_ocjena && tarik_ocjena == mirza_ocjena))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
   }



   return(0);
}
