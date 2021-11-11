#include <stdio.h>

int main()
{
   double prva_parcijalaT = 0, druga_parcijalaT = 0, prisustvoT = 0, zadacaT = 0, zavrsni_ispitT = 0, prva_parcijalaB = 0, druga_parcijalaB = 0, prisustvoB = 0, zadacaB = 0, zavrsni_ispitB = 0, prva_parcijalaM = 0, druga_parcijalaM = 0, prisustvoM = 0, zadacaM = 0, zavrsni_ispitM = 0, bodovi_Bojan = 0, bodovi_Tarik = 0, bodovi_Mirza = 0;
   int    ocjena_T = 0, ocjena_B = 0, ocjena_M = 0;

   printf("Unesite bodove za Tarika: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &prva_parcijalaT);
   if (prva_parcijalaT < 0 || prva_parcijalaT > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &druga_parcijalaT);
   if (druga_parcijalaT < 0 || druga_parcijalaT > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvoT);
   if (prisustvoT < 0 || prisustvoT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadacaT);
   if (zadacaT < 0 || zadacaT > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni_ispitT);
   if (zavrsni_ispitT < 0 || zavrsni_ispitT > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Bojana: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &prva_parcijalaB);
   if (prva_parcijalaB < 0 || prva_parcijalaB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &druga_parcijalaB);
   if (druga_parcijalaB < 0 || druga_parcijalaB > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvoB);
   if (prisustvoB < 0 || prisustvoB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadacaB);
   if (zadacaB < 0 || zadacaB > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni_ispitB);
   if (zavrsni_ispitB < 0 || zavrsni_ispitB > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   printf("Unesite bodove za Mirzu: ");
   printf("\nI parcijalni ispit: ");
   scanf("%lf", &prva_parcijalaM);
   if (prva_parcijalaM < 0 || prva_parcijalaM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%lf", &druga_parcijalaM);
   if (druga_parcijalaM < 0 || druga_parcijalaM > 20)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Prisustvo: ");
   scanf("%lf", &prisustvoM);
   if (prisustvoM < 0 || prisustvoM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zadace: ");
   scanf("%lf", &zadacaM);
   if (zadacaM < 0 || zadacaM > 10)
   {
      printf("Neispravan broj bodova");
      return(0);
   }
   printf("Zavrsni ispit: ");
   scanf("%lf", &zavrsni_ispitM);
   if (zavrsni_ispitM < 0 || zavrsni_ispitM > 40)
   {
      printf("Neispravan broj bodova");
      return(0);
   }

   bodovi_Tarik = prva_parcijalaT + druga_parcijalaT + prisustvoT + zadacaT + zavrsni_ispitT;
   bodovi_Bojan = prva_parcijalaB + druga_parcijalaB + prisustvoB + zadacaB + zavrsni_ispitB;
   bodovi_Mirza = prva_parcijalaM + druga_parcijalaM + prisustvoM + zadacaM + zavrsni_ispitM;

   if (bodovi_Tarik < 55 && bodovi_Mirza < 55 && bodovi_Bojan < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   else if ((bodovi_Bojan < 55 && bodovi_Mirza < 55 && bodovi_Tarik >= 55) || (bodovi_Bojan < 55 && bodovi_Mirza >= 55 && bodovi_Tarik < 55) || (bodovi_Bojan >= 55 && bodovi_Mirza < 55 && bodovi_Tarik < 55))
   {
      printf("Jedan student je polozio.");
   }
   else if ((bodovi_Bojan >= 55 && bodovi_Mirza < 55 && bodovi_Tarik >= 55) || (bodovi_Bojan < 55 && bodovi_Mirza >= 55 && bodovi_Tarik >= 55) || (bodovi_Bojan >= 55 && bodovi_Mirza >= 55 && bodovi_Tarik < 55))
   {
      printf("Dva studenta su polozila.");
   }
   else
   {
      printf("Sva tri studenta su polozila.");
   }

   if (bodovi_Tarik >= 55 && bodovi_Tarik < 65)
   {
      ocjena_T = 6;
   }
   else if (bodovi_Tarik >= 65 && bodovi_Tarik < 75)
   {
      ocjena_T = 7;
   }
   else if (bodovi_Tarik >= 75 && bodovi_Tarik < 85)
   {
      ocjena_T = 8;
   }
   else if (bodovi_Tarik >= 85 && bodovi_Tarik < 92)
   {
      ocjena_T = 9;
   }
   else if (bodovi_Tarik >= 92 && bodovi_Tarik <= 100)
   {
      ocjena_T = 10;
   }

   if (bodovi_Mirza >= 55 && bodovi_Mirza < 65)
   {
      ocjena_M = 6;
   }
   else if (bodovi_Mirza >= 65 && bodovi_Mirza < 75)
   {
      ocjena_M = 7;
   }
   else if (bodovi_Mirza >= 75 && bodovi_Mirza < 85)
   {
      ocjena_M = 8;
   }
   else if (bodovi_Mirza >= 85 && bodovi_Mirza < 92)
   {
      ocjena_M = 9;
   }
   else if (bodovi_Mirza >= 92 && bodovi_Mirza <= 100)
   {
      ocjena_M = 10;
   }

   if (bodovi_Bojan >= 55 && bodovi_Bojan < 65)
   {
      ocjena_B = 6;
   }
   else if (bodovi_Bojan >= 65 && bodovi_Bojan < 75)
   {
      ocjena_B = 7;
   }
   else if (bodovi_Bojan >= 75 && bodovi_Bojan < 85)
   {
      ocjena_B = 8;
   }
   else if (bodovi_Bojan >= 85 && bodovi_Bojan < 92)
   {
      ocjena_B = 9;
   }
   else if (bodovi_Bojan >= 92 && bodovi_Bojan <= 100)
   {
      ocjena_B = 10;
   }


   if (bodovi_Tarik >= 55 && bodovi_Mirza >= 55 && bodovi_Bojan >= 55)
   {
      if (ocjena_T == ocjena_M && ocjena_M == ocjena_B)
      {
         printf("\nSva tri studenta imaju istu ocjenu.");
      }
      else if (ocjena_T == ocjena_M || ocjena_T == ocjena_B || ocjena_M == ocjena_B)
      {
         printf("\nDva od tri studenta imaju istu ocjenu.");
      }
      else
      {
         printf("\nSvaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
