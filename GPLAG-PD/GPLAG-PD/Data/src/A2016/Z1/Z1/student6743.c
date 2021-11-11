#include <stdio.h>

int main()
{
   float bodovi1I, bodovi1II, prisustvo1, zadace1, zavrsni1, bodovi2I, bodovi2II,
         prisustvo2, zadace2, zavrsni2, bodovi3I, bodovi3II, prisustvo3, zadace3,
         zavrsni3, ukupno1, ukupno2, ukupno3;

   int Tarik = 0, Bojan = 0, Mirza = 0;

   printf("Unesite bodove za Tarika: ");

   printf("\nI parcijalni ispit: ");
   scanf("%f", &bodovi1I);
   if (bodovi1I < 0 || bodovi1I > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &bodovi1II);
   if (bodovi1II < 0 || bodovi1II > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &prisustvo1);
   if (prisustvo1 < 0 || prisustvo1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zadace: ");
   scanf("%f", &zadace1);
   if (zadace1 < 0 || zadace1 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni1);
   if (zavrsni1 < 0 || zavrsni1 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Bojana: ");

   printf("\nI parcijalni ispit: ");
   scanf("%f", &bodovi2I);
   if (bodovi2I < 0 || bodovi2I > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &bodovi2II);
   if (bodovi2II < 0 || bodovi2II > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &prisustvo2);
   if (prisustvo2 < 0 || prisustvo2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zadace: ");
   scanf("%f", &zadace2);
   if (zadace2 < 0 || zadace2 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni2);
   if (zavrsni2 < 0 || zavrsni2 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Unesite bodove za Mirzu: ");

   printf("\nI parcijalni ispit: ");
   scanf("%f", &bodovi3I);
   if (bodovi3I < 0 || bodovi3I > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("II parcijalni ispit: ");
   scanf("%f", &bodovi3II);
   if (bodovi3II < 0 || bodovi3II > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Prisustvo: ");
   scanf("%f", &prisustvo3);
   if (prisustvo3 < 0 || prisustvo3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zadace: ");
   scanf("%f", &zadace3);
   if (zadace3 < 0 || zadace3 > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }

   printf("Zavrsni ispit: ");
   scanf("%f", &zavrsni3);
   if (zavrsni3 < 0 || zavrsni3 > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }


   ukupno1 = (double)bodovi1I + bodovi1II + prisustvo1 + zadace1 + zavrsni1;
   ukupno2 = (double)bodovi2I + bodovi2II + prisustvo2 + zadace2 + zavrsni2;
   ukupno3 = (double)bodovi3I + bodovi3II + prisustvo3 + zadace3 + zavrsni3;

   if (ukupno1 < 55)
   {
      Tarik = 5;
   }
   if (ukupno2 < 55)
   {
      Bojan = 5;
   }
   if (ukupno3 < 55)
   {
      Mirza = 5;
   }

   if (ukupno1 >= 55 && ukupno1 < 65)
   {
      Tarik = 6;
   }
   if (ukupno2 >= 55 && ukupno2 < 65)
   {
      Bojan = 6;
   }
   if (ukupno3 >= 55 && ukupno3 < 65)
   {
      Mirza = 6;
   }

   if (ukupno1 >= 65 && ukupno1 < 75)
   {
      Tarik = 7;
   }
   if (ukupno2 >= 65 && ukupno2 < 75)
   {
      Bojan = 7;
   }
   if (ukupno3 >= 65 && ukupno3 < 75)
   {
      Mirza = 7;
   }

   if (ukupno1 >= 75 && ukupno1 < 85)
   {
      Tarik = 8;
   }
   if (ukupno2 >= 75 && ukupno2 < 85)
   {
      Bojan = 8;
   }
   if (ukupno3 >= 75 && ukupno3 < 85)
   {
      Mirza = 8;
   }

   if (ukupno1 >= 85 && ukupno1 < 92)
   {
      Tarik = 9;
   }
   if (ukupno2 >= 85 && ukupno2 < 92)
   {
      Bojan = 9;
   }
   if (ukupno3 >= 85 && ukupno3 < 92)
   {
      Mirza = 9;
   }

   if (ukupno1 >= 92 && ukupno1 <= 100)
   {
      Tarik = 10;
   }
   if (ukupno2 >= 92 && ukupno2 <= 100)
   {
      Bojan = 10;
   }
   if (ukupno3 >= 92 && ukupno3 <= 100)
   {
      Mirza = 10;
   }

   if (Tarik == 5 && Bojan == 5 && Mirza == 5)
   {
      printf("Nijedan student nije polozio.");
   }

   if ((Tarik > 5 && Bojan == 5 && Mirza == 5) || (Tarik == 5 && Bojan > 5 && Mirza == 5) ||
       (Tarik == 5 && Bojan == 5 && Mirza > 5))
   {
      printf("Jedan student je polozio.");
   }

   if ((Tarik > 5 && Bojan > 5 && Mirza == 5) || (Tarik > 5 && Bojan == 5 && Mirza > 5) ||
       (Tarik == 5 && Bojan > 5 && Mirza > 5))
   {
      printf("Dva studenta su polozila.");
   }

   if ((Tarik > 5) && (Bojan > 5) && (Mirza > 5))
   {
      printf("Sva tri studenta su polozila.");


      if ((Tarik == Bojan && Bojan == Mirza) && Tarik != 5 && Bojan != 5 && Mirza != 5)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }

      if ((Tarik == Bojan && Bojan != Mirza) || (Tarik == Mirza && Mirza != Bojan) ||
          (Bojan == Mirza && Mirza != Tarik))
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }

      if ((Tarik != Bojan) && (Bojan != Mirza) && (Mirza != Tarik))
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }


   return(0);
}
