#include <stdio.h>
#define eps    0.01



int main()
{
   float prvi, drugi, zadaca, prisustvo, zavrsni, zbir1, zbir2, zbir3;
   int   ocjena1, ocjena2, ocjena3;

   printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
   scanf("%f", &prvi);
   if (prvi < 0 || prvi > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &drugi);
   if (drugi < 0 || drugi > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo);
   if (prisustvo < 0 || prisustvo > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadaca);
   if (zadaca < 0 || zadaca > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: "); scanf("%f", &zavrsni);
   if (zavrsni < 0 || zavrsni > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   zbir1 = prvi + drugi + zadaca + prisustvo + zavrsni + eps;
   if (zbir1 < 55)
   {
      ocjena1 = 5;
   }
   if (zbir1 >= 55 && zbir1 < 65)
   {
      ocjena1 = 6;
   }
   if (zbir1 >= 65 && zbir1 < 75)
   {
      ocjena1 = 7;
   }
   if (zbir1 >= 75 && zbir1 < 85)
   {
      ocjena1 = 8;
   }
   if (zbir1 >= 85 && zbir1 < 92)
   {
      ocjena1 = 9;
   }
   if (zbir1 >= 92 && zbir1 <= 100)
   {
      ocjena1 = 10;
   }


   printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
   scanf("%f", &prvi);
   if (prvi < 0 || prvi > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &drugi);
   if (drugi < 0 || drugi > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo);
   if (prisustvo < 0 || prisustvo > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadaca);
   if (zadaca < 0 || zadaca > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: "); scanf("%f", &zavrsni);
   if (zavrsni < 0 || zavrsni > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   zbir2 = prvi + drugi + zadaca + prisustvo + zavrsni + eps;
   if (zbir2 < 55)
   {
      ocjena2 = 5;
   }
   if (zbir2 >= 55 && zbir2 < 65)
   {
      ocjena2 = 6;
   }
   if (zbir2 >= 65 && zbir2 < 75)
   {
      ocjena2 = 7;
   }
   if (zbir2 >= 75 && zbir2 < 85)
   {
      ocjena2 = 8;
   }
   if (zbir2 >= 85 && zbir2 < 92)
   {
      ocjena2 = 9;
   }
   if (zbir2 >= 92 && zbir2 <= 100)
   {
      ocjena2 = 10;
   }

   printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
   scanf("%f", &prvi);
   if (prvi < 0 || prvi > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("II parcijalni ispit: ");
   scanf("%f", &drugi);
   if (drugi < 0 || drugi > 20)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Prisustvo: ");
   scanf("%f", &prisustvo);
   if (prisustvo < 0 || prisustvo > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zadace: ");
   scanf("%f", &zadaca);
   if (zadaca < 0 || zadaca > 10)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   printf("Zavrsni ispit: "); scanf("%f", &zavrsni);
   if (zavrsni < 0 || zavrsni > 40)
   {
      printf("Neispravan broj bodova"); return(0);
   }
   zbir3 = prvi + drugi + zadaca + prisustvo + zavrsni + eps;
   if (zbir3 < 55)
   {
      ocjena2 = 5;
   }
   if (zbir3 >= 55 && zbir3 < 65)
   {
      ocjena3 = 6;
   }
   if (zbir3 >= 65 && zbir3 < 75)
   {
      ocjena3 = 7;
   }
   if (zbir3 >= 75 && zbir3 < 85)
   {
      ocjena3 = 8;
   }
   if (zbir3 >= 85 && zbir3 < 92)
   {
      ocjena3 = 9;
   }
   if (zbir3 >= 92 && zbir3 <= 100)
   {
      ocjena3 = 10;
   }
   if (zbir3 < 55 && zbir2 < 55 && zbir1 < 55)
   {
      printf("Nijedan student nije polozio.");
   }
   if ((zbir1 >= 55 && zbir2 < 55 && zbir3 < 55) || (zbir1 < 55 && zbir2 >= 55 && zbir3 < 55) || (zbir1 < 55 && zbir2 < 55 && zbir3 >= 55))
   {
      printf("Jedan student je polozio.");
   }
   if ((zbir1 > 55 && zbir2 > 55 && zbir3 < 55) || (zbir1 > 55 && zbir2 < 55 && zbir3 > 55) || (zbir1 < 55 && zbir2 > 55 && zbir3 > 55))
   {
      printf("Dva studenta su polozila.");
   }
   if (zbir1 > 55 && zbir2 > 55 && zbir3 > 55)
   {
      printf("Sva tri studenta su polozila.\n");
      if (ocjena1 == ocjena2 && ocjena1 == ocjena3)
      {
         printf("Sva tri studenta imaju istu ocjenu.");
      }
      if ((ocjena1 == ocjena2 && ocjena1 != ocjena3) || (ocjena1 == ocjena3 && ocjena1 != ocjena2) || (ocjena2 == ocjena3 && ocjena2 != ocjena1))
      {
         printf("Dva od tri studenta imaju istu ocjenu.");
      }
      if (ocjena1 != ocjena2 && ocjena1 != ocjena3 && ocjena2 != ocjena3)
      {
         printf("Svaki student ima razlicitu ocjenu.");
      }
   }

   return(0);
}
